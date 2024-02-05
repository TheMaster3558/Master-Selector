#pragma once
#include <functional>
#include <string>


namespace ms {

class Auton {
public:
    /**
     * @brief Construct a new Auton
     *
     * @param name The name of the auton
     * @param callback The callback associated with the auton (the function that will be called when auton is selected)
     */
    Auton(std::string name, const std::function<void()> &callback);

    /** @brief The name of the auton */
    std::string name;

    /** @brief The callback associated with the auton */
    std::function<void()> callback;
};

} // namespace ms