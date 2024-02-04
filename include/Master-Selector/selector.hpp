#pragma once

#include <functional>
#include <map>
#include <utility>
#include "pros/apix.h"


namespace selector {

class Auton {
public:
    std::string name;
    std::function<void()> callback;

    Auton(std::string name, const std::function<void()>& callback);
};


class Category {
public:
    std::string name;
    std::vector <Auton> autons;

    Category(std::string name, const std::vector<Auton>& autons);
};


void set_autons(const std::vector<Category> &categories);
void call_selected_auton();
void initialize(int autons_per_row = 3);

}  // namespace autonSelector
