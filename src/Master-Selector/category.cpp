#include "Master-Selector/category.hpp"


ms::Category::Category(std::string name, const std::vector <Auton>& autons)
    : name(name), autons(autons) {}