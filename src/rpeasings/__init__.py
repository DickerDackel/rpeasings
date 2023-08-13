"""With the exception of `null`, `in_expx` and `out_expx`, this is a python
port of "Penner's Easing Functions", based on the js code from
https://easings.net where you can also see a catalog of them in action to chose
the right one.

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
dictionary provides a map from function names to functions.

"""
from math import sin, cos, pi

__all__ = ['in_quad', 'out_quad', 'in_out_quad', 'in_cubic', 'out_cubic',
           'in_out_cubic', 'in_quart', 'out_quart', 'in_out_quart',
           'in_quint', 'out_quint', 'in_out_quint', 'in_sine', 'out_sine',
           'in_out_sine', 'in_expo', 'out_expo', 'in_out_expo', 'in_circ',
           'out_circ', 'in_out_circ', 'in_back', 'out_back', 'in_out_back',
           'in_elastic', 'out_elastic', 'in_out_elastic', 'in_bounce',
           'out_bounce', 'in_out_bounce', 'null']


def null(t):
    return t


c1 = 1.70158
c2 = c1 * 1.525
c3 = c1 + 1
c4 = (2 * pi) / 3
c5 = (2 * pi) / 4.5


def bounce_out(t):
    n1 = 7.5625
    d1 = 2.75

    if t < 1 / d1:
        return n1 * t * t
    elif t < 2 / d1:
        ft = t - 1.5 / d1
        return n1 * ft * ft + 0.75
    elif t < 2.5 / d1:
        ft = t - 2.25 / d1
        return n1 * ft * ft + 0.9375
    else:
        ft = t - 2.625 / d1
        return n1 * ft * ft + 0.984375


def in_quad(t):
    return t * t


def out_quad(t):
    return 1 - (1 - t) * (1 - t)


def in_out_quad(t):
    return 2 * t * t if t < 0.5 else 1 - (-2 * t + 2) ** 2 / 2


def in_cubic(t):
    return t * t * t


def out_cubic(t):
    return 1 - (1 - t) ** 3


def in_out_cubic(t):
    return 4 * t * t * t if t < 0.5 else 1 - (-2 * t + 2) ** 3 / 2


def in_quart(t):
    return t * t * t * t


def out_quart(t):
    return 1 - (1 - t) ** 4


def in_out_quart(t):
    return 8 * t * t * t * t if t < 0.5 else 1 - (-2 * t + 2) ** 4 / 2


def in_quint(t):
    return t * t * t * t * t


def out_quint(t):
    return 1 - (1 - t) ** 5


def in_out_quint(t):
    return 16 * t * t * t * t * t if t < 0.5 else 1 - (-2 * t + 2) ** 5 / 2


def in_sine(t):
    return 1 - cos((t * pi) / 2)


def out_sine(t):
    return sin((t * pi) / 2)


def in_out_sine(t):
    return -(cos(pi * t) - 1) / 2


def in_expo(t):
    return 0 if t == 0 else 2 ** (10 * t - 10)


def out_expo(t):
    return 1 if t == 1 else 1 - 2 ** (-10 * t)


def in_out_expo(t):
    if t == 0:
        return 0
    elif t == 1:
        return 1
    elif t < 0.5:
        return 2 ** (20 * t - 10) / 2
    else:
        return (2 - 2 ** (-20 * t + 10)) / 2

    if t == 0:
        return 0
    elif t == 1:
        return 1
    elif t < 0.5:
        return 2 ** (20 * t - 10) / 2
    else:
        return (2 - 2 ** (-20 * t + 10)) / 2

    return 0 if t == 0 else (1 if t == 1 else (2 ** (20 * t - 10) / 2 if t < 0.5 else (2 - 2 ** (-20 * t + 10)) / 2))


def in_circ(t):
    return 1 - (1 - t ** 2) ** 0.5


def out_circ(t):
    return (1 - (t - 1) * (t - 1)) ** 0.5


def in_out_circ(t):
    return (1 - (1 - (2 * t) ** 2) ** 0.5) / 2 if t < 0.5 else ((1 - (-2 * t + 2) ** 2) ** 0.5 + 1) / 2


def in_back(t):
    return c3 * t * t * t - c1 * t * t


def out_back(t):
    return 1 + c3 * (t - 1) ** 3 + c1 * (t - 1) ** 2


def in_out_back(t):
    return ((2 * t) ** 2 * ((c2 + 1) * 2 * t - c2)) / 2 if t < 0.5 else ((2 * t - 2) ** 2 * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2


def in_elastic(t):
    if t == 0:
        return 0
    elif t == 1:
        return 1
    else:
        return -(2 ** (10 * t - 10)) * sin((t * 10 - 10.75) * c4)


def out_elastic(t):
    if t == 0:
        return 0
    elif t == 1:
        return 1
    else:
        return 2 ** (-10 * t) * sin((t * 10 - 0.75) * c4) + 1


def in_out_elastic(t):
    if t == 0:
        return 0
    elif t == 1:
        return 1
    elif t < 0.5:
        return -( 2 ** (20 * t - 10) * sin((20 * t - 11.125) * c5)) / 2
    else:
        return (2 ** (-20 * t + 10) * sin((20 * t - 11.125) * c5)) / 2 + 1


def in_bounce(t):
    return 1 - bounce_out(1 - t)


out_bounce = bounce_out


def in_out_bounce(t):
    return (1 - bounce_out(1 - 2 * t)) / 2 if t < 0.5 else (1 + bounce_out(2 * t - 1)) / 2


# Yeah, I know, pep8.  But so I can see that it's complete.
easings = {
    'in_back': in_back,       'out_back': out_back,       'in_out_back': in_out_back,
    'in_bounce': in_bounce,   'out_bounce': out_bounce,   'in_out_bounce': in_out_bounce,
    'in_circ': in_circ,       'out_circ': out_circ,       'in_out_circ': in_out_circ,
    'in_cubic': in_cubic,     'out_cubic': out_cubic,     'in_out_cubic': in_out_cubic,
    'in_elastic': in_elastic, 'out_elastic': out_elastic, 'in_out_elastic': in_out_elastic,
    'in_expo': in_expo,       'out_expo': out_expo,       'in_out_expo': in_out_expo,
    'in_quad': in_quad,       'out_quad': out_quad,       'in_out_quad': in_out_quad,
    'in_quart': in_quart,     'out_quart': out_quart,     'in_out_quart': in_out_quart,
    'in_quint': in_quint,     'out_quint': out_quint,     'in_out_quint': in_out_quint,
    'in_sine': in_sine,       'out_sine': out_sine,       'in_out_sine': in_out_sine,
    'null': null,
}
