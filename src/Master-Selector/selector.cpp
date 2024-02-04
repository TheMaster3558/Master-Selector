#include "Master-Selector/selector.hpp"


selector::Auton::Auton(std::string name, const std::function<void()>& callback) : name(name), callback(callback) {}
selector::Category::Category(std::string name, const std::vector <Auton>& autons) : name(name), autons(autons) {}


std::vector<selector::Category> auton_categories = {};
selector::Auton* selected_auton = nullptr;

void selector::set_autons(const std::vector<selector::Category> &categories) {
    auton_categories = categories;
    selected_auton = &auton_categories[0].autons[0];
}


void selector::call_selected_auton() {
    selected_auton->callback();
}


lv_obj_t* tabview = nullptr;
// Map the page number to the button matrix
std::vector<lv_obj_t*> btnms = {};
// Map the button matrix to the category so the category can be retrieved during the callback
std::map<lv_obj_t*, selector::Category*> btnm_to_category;


lv_res_t button_action(lv_obj_t *btnm, const char *txt) {
    for (selector::Auton& auton : btnm_to_category[btnm]->autons) {
        if (strcmp(auton.name.c_str(), txt) == 0) {
            selected_auton = &auton;
            break;
        }
    }

    return LV_RES_OK;
}


// reset the auton to the first auton on the page when tab is changed
void handle_tab_change() {
    int previous_tab = lv_tabview_get_tab_act(tabview);
    while (true) {
        int current_tab = lv_tabview_get_tab_act(tabview);

        if (current_tab != previous_tab) {
            selected_auton = &auton_categories[current_tab].autons[0];

            lv_obj_t* btnm = btnms[previous_tab];
            lv_btnm_set_toggle(btnm, true, 0);
        }

        previous_tab = current_tab;
        pros::delay(20);
    }
}


void selector::initialize(int autons_per_row) {
    btnm_to_category = {};

    lv_theme_t* theme = lv_theme_alien_init(360, NULL);
    lv_theme_set_current(theme);

    tabview = lv_tabview_create(lv_scr_act(), NULL);

    for (selector::Category& category : auton_categories) {
        lv_obj_t* category_tab = lv_tabview_add_tab(tabview, category.name.c_str());
        lv_obj_t* category_btnm = lv_btnm_create(category_tab, NULL);

        size_t num_autons = category.autons.size();
        size_t auton_buttons_size = num_autons + num_autons / autons_per_row + 1;
        const char** auton_buttons = new const char*[auton_buttons_size];

        size_t i;
        int autonIndex = 0;
        for (i = 0; i < auton_buttons_size - 1; i++) {
            // i != 0 so there's no empty row at the start
            if (i != 0 && i % autons_per_row == 0) {
                auton_buttons[i] = "\n";
            }
            else {
                auton_buttons[i] = category.autons[autonIndex++].name.c_str();
            }
        }

        auton_buttons[auton_buttons_size - 1] = "";  // empty string at end

        lv_btnm_set_map(category_btnm, auton_buttons);
        lv_btnm_set_action(category_btnm, *button_action);
        lv_btnm_set_toggle(category_btnm, true, 0);
        lv_obj_set_size(category_btnm, 450, 50);
        lv_obj_set_pos(category_btnm, 0, 100);
        lv_obj_align(category_btnm, NULL, LV_ALIGN_CENTER, 0, 0);

        btnms.push_back(category_btnm);
        btnm_to_category.emplace(category_btnm, &category);
    }

    pros::Task handle_tab_change_task(handle_tab_change);
}
