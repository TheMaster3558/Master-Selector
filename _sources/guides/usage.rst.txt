2 - Using Master-Selector
=========================

Now that you've installed Master-Selector, you need to learn how to use it.
Luckily, it's pretty simple!

Our Classes
-----------
These classes define how Master-Selector works, if you understand these, development will be easy.

Auton
~~~~~
An auton has a name and a callback. The callback is the function that will be called when
the auton is selected.

Category
~~~~~~~~
A category is a group of `Auton`'s. Each category has a name and contains different autons.
We use categories to group autons together, for example, grouping all near side autons together.


Using The Classes
-----------------
It's pretty simple. You first need to define a few autons somewhere in my code. We'll use
these as an example. Remember that your autons may look very different than someone else's,
it all depends on the other libraries that you use (We recommend `LemLib <https://lemlib.github.io/LemLib/index.html>`_).

.. code:: cpp

    // Near side and gets the auton win point
    void near_side_awp() {
        // ...
    }

    // Near side for elimination rounds
    void near_side_elims() {
        // ...
    }

    // Skills
    void skills() {
        // ...
    }


Once you have defined that, we'll navigate to the `initialize()` function in `src/main.cpp`.
We'll define two categories: *Near Side* and *Skills*. We will add `near_side_awp` and `near_side_elims`
to *Near-Side* and `skills` to *Skills*.

We will use the `set_autons` function with `Category` and `Auton` classes to do this.
Remember that all classes and functions of Master-Selector are held within the `ms` namespace!

.. code:: cpp

    void initialize() {
        // Do extra initializing here

        ms::set_autons({  // Vector of categories
            ms::Category("Near-Side", {
                ms::Auton("Auton Win Point", near_side_awp),
                ms::Auton("Eliminations", near_side_elims)
            }),
            ms::Category("Skills", {
                ms::Auton("Skills", skills)
            })
        });
        ms::initialize(); // Initialize the screen
    }

Next add `call_selected_auton()` to your `autonomous()` function.

.. code:: cpp

    void autonomous() {
        ms::call_selected_auton();
    }


From here, you're all good to go! If you want to view more detail about the classes
and functions, visit :ref:`this<Master-Selector API Reference>` section of our documentation.

Good luck coding!
