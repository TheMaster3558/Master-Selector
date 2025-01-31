# Master-Selector

| ![Master-Selector](docs/_static/branding/MasterSelector%20(640%20x%20320%20px).png) |
|:--:|
| *Logo created by [@LyubomirT](https://github.com/LyubomirT)* |

Welcome to Master-Selector!
Master-Selector is a simple yet capable PROS template that handles your autonomous routine selector

**IMPORTANT: This template only works on PROS 3, consider using robodash if you are using PROS 4**

The creation of this library was inspired by this [autonomous selector](https://github.com/kunwarsahni01/Vex-Autonomous-Selector).
This library aims to be an up-to-date and more flexible version of our inspiration.

## Documentation
Check out our documentation [here](https://themaster3558.github.io/Master-Selector)

## License
MIT, see the LICENSE file for more

## Features
- Easy to setup
- Categories to group your autons
- Interactive GUI on brain

## Installation
1. Download the latest release of `Master-Selector` and add the zip file to your project root.
2. Run `pros c fetch Master-Selector@x.x.x.zip` in your terminal
3. Run `pros c apply Master-Selector@x.x.x.zip` in your terminal
4. Add `#include Master-Selector/api.hpp` to the top of your `main.h`

## Code Example

```c++
#include "main.h"


void near_side_awp() {
    // ...
}


void near_side_elims() {
    // ...
}


void skills() {
    // ...
}


void initialize() {
    ms::set_autons({
        ms::Category("Near Side", {
            ms::Auton("Near Side AWP", near_side_awp),
            ms::Auton("Near Side Eliminations", near_side_elims)
        }),
        ms::Category("Skills", {
            ms::Auton("skills", skills)
        })
    });
    ms::initialize();
}


void autonomous() {
    ms::call_selected_auton();
}
```

