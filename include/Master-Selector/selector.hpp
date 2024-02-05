#pragma once

#include <map>
#include <utility>
#include "pros/apix.h"
#include "auton.hpp"
#include "category.hpp"


namespace ms {

/**
 * @brief Set the autons that will be displayed on the brain
 *
 * @param categories A vector of @ref Category that will be displayed
 */
void set_autons(const std::vector<Category> &categories);

/**
 * @brief Call the callback of the currently selected @ref Auton
 */
void call_selected_auton();

/**
 * @brief Initialize the autonomous selector
 *
 * @param autons_per_row The number of autons that can be displayed on each row, defaults to 3
 */
void initialize(int autons_per_row = 3);

}  // namespace ms
