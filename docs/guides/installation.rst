1 - Getting Started
===================

This tutorial will teach you how to install Master-Selector and start using it!


Development Environment
-----------------------
Master-Selector is a template with `PROS <https://pros.cs.purdue.edu>`_.
You can use PROS in any development environment but it is most commonly used with
`Visual Studio Code <https://code.visualstudio.com/>`_
(Although, *Master-Selector* was coded in `CLion <https://www.jetbrains.com/clion/>`_ ).

For more instructions on how to use PROS, visit their `getting started page <https://pros.cs.purdue.edu/v5/getting-started/index.html>`_.


Master-Selector Installation
------------------------------
Visit our `GitHub <https://github.com/themaster3558/master-selector>`_ and navigate to the
releases page. Then download the latest release, it should look like ``Master-Selector@x.x.x.zip``.
Once you have downloaded that, move it to your project folder.

Next, open up your PROS terminal. You must run the following commands.

.. code:: sh

    pros c fetch Master-Selector@x.x.x.zip
    pros c apply Master-Selector@x.x.x

Of course, replace the x's with your installed Master-Selector version.

Lastly, add this to your ``include/main.h`` file and you are ready to use Master-Selector!

.. code:: cpp

    #include "Master-Selector/api.hpp"


**Next Guide:** :doc:`usage`
