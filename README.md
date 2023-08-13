# Robert Penner's Easing Functions

There are a plethora of versions available of these, many of which provide an
object oriented interface, while most of the original easing functions could
be simple inline expressions.

This library takes the purely functional approach.  No class instantiation,
just a function call.

See https://easings.net for a good visualisation of these to chose the right
one.

## Module contents

With the exception of `null`, `in_expx` and `out_expx`, this is a pure python
port of "Penner's Easing Functions", based on the js code from
https://easings.net where you can also see a catalog of them in action to
chose the right one.

The following functions are included:

    in_back         out_back        in_out_back
    in_bounce       out_bounce      in_out_bounce
    in_circ         out_circ        in_out_circ
    in_cubic        out_cubic       in_out_cubic
    in_elastic      out_elastic     in_out_elastic
    in_expo         out_expo        in_out_expo
    in_quad         out_quad        in_out_quad
    in_quart        out_quart       in_out_quart
    in_quint        out_quint       in_out_quint
    in_sine         out_sine        in_out_sine

Additionally, I added a 'null' function, so easing can be disabled without
changing the interface in the application.  It's basically a `nop`.

    null(t) -> t

In case you want to control the easing function by user input, the `easings`
dictionary provides a map from function names to functions, e.g.

    eased = rpeasings.easings['out_elastic']

To use any of the included functions, create a `t` (for 'time') value in the
range 0-1 from your required range (e.g. `t = current / max`).

Putting this `t` into most(!) easing function, will give you a new 'eased'
value in the range 0-1.

Note: the following functions over-/undershoot:

    `in_back`     `out_back`     `in_out_back`
    `in_elastic`  `out_elastic`  `in_out_elastic`

Additionally, you can then put that eased value as input into a `lerp`
function to add dynamics to an otherwise linear range.

Have fun, once you started using one, you'll probably find usecases for them
everywhere in your game...
