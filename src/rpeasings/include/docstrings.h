#ifndef DOCSTRING_H
#define DOCSTRING_H

#define MODULE_DOCSTRING \
    "Robert Penner's Easing Functions\n" \
    "\n" \
    "SYNOPSIS\n" \
    "\n" \
    "	rpeasings.EASING_FUNCTION(t: float) -> float\n" \
    "\n" \
    "    returns t (between 0 and 1) eased by the chosen function.\n" \
    "\n" \
    "\n" \
    "DESCRIPTION\n" \
    "\n" \
    "There are a plethora of versions available of these, many of which provide an\n" \
    "object oriented interface, while most of the original easing functions could\n" \
    "be simple inline expressions.\n" \
    "\n" \
    "This library takes the purely functional approach.  No class instantiation,\n" \
    "just a function call.\n" \
    "\n" \
    "See https://easings.net for a good visualisation of these to chose the right\n" \
    "one.\n" \
    "\n" \
    "Alternatively, if you have pygame-ce installed, you can launch the\n" \
    "`rpeasings-catalog.py` script in the `catalog` folder.  This will not work on\n" \
    "the outdated \"official\" pygame release.\n" \
    "\n" \
    "## Module contents\n" \
    "\n" \
    "With the exception of `null`, `in_expx` and `out_expx`, this is a pure python\n" \
    "port of \"Penner's Easing Functions\", based on the js code from\n" \
    "https://easings.net where you can also see a catalog of them in action to\n" \
    "chose the right one.\n" \
    "\n" \
    "The following functions are included:\n" \
    "\n" \
    "    in_back         out_back        in_out_back\n" \
    "    in_bounce       out_bounce      in_out_bounce\n" \
    "    in_circ         out_circ        in_out_circ\n" \
    "    in_cubic        out_cubic       in_out_cubic\n" \
    "    in_elastic      out_elastic     in_out_elastic\n" \
    "    in_expo         out_expo        in_out_expo\n" \
    "    in_quad         out_quad        in_out_quad\n" \
    "    in_quart        out_quart       in_out_quart\n" \
    "    in_quint        out_quint       in_out_quint\n" \
    "    in_sine         out_sine        in_out_sine\n" \
    "\n" \
    "Additionally, I added a 'null' function, so easing can be disabled without\n" \
    "changing the interface in the application.  It's basically a `nop`.\n" \
    "\n" \
    "    null(t) -> t\n" \
    "\n" \
    "In case you want to control the easing function by user input, the `easings`\n" \
    "dictionary provides a map from function names to functions, e.g.\n" \
    "\n" \
    "    eased = rpeasings.easings['out_elastic']\n" \
    "\n" \
    "To use any of the included functions, create a `t` (for 'time') value in the\n" \
    "range 0-1 from your required range (e.g. `t = current / max`).\n" \
    "\n" \
    "Putting this `t` into most(!) easing function, will give you a new 'eased'\n" \
    "value in the range 0-1.\n" \
    "\n" \
    "Note: the following functions over-/undershoot:\n" \
    "\n" \
    "    `in_back`     `out_back`     `in_out_back`\n" \
    "    `in_elastic`  `out_elastic`  `in_out_elastic`\n" \
    "\n" \
    "You can then use this value as a factor or e.g. as input for another `lerp`\n" \
    "function.\n" \
    "\n" \
    "Have fun, once you started using one, you'll probably find usecases for them\n" \
    "everywhere in your game...\n"

#endif
