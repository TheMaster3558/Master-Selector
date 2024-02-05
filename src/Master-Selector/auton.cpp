#include "auton.hpp"

ms::Auton::Auton(std::string name, const std::function<void()>& callback)
    : name(name), callback(callback) {}
