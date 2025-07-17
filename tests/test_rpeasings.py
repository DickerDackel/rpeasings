import pytest

from importlib.resources import files
from pytest import approx

import rpeasings


def test_null():
    assert approx(rpeasings.null(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.null(0.3), abs=0.00001) == 0.3
    assert approx(rpeasings.null(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.null(0.6), abs=0.00001) == 0.6
    assert approx(rpeasings.null(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.null(5.0), abs=0.00001) == 5.0

def test_bounce_out():
    assert approx(rpeasings.bounce_out(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.bounce_out(0.3), abs=0.00001) == 0.68062
    assert approx(rpeasings.bounce_out(0.5), abs=0.00001) == 0.76562
    assert approx(rpeasings.bounce_out(0.6), abs=0.00001) == 0.7725
    assert approx(rpeasings.bounce_out(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.bounce_out(5.0), abs=0.00001) == 124.75

def test_in_quad():
    assert approx(rpeasings.in_quad(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_quad(0.3), abs=0.00001) == 0.09
    assert approx(rpeasings.in_quad(0.5), abs=0.00001) == 0.25
    assert approx(rpeasings.in_quad(0.6), abs=0.00001) == 0.36
    assert approx(rpeasings.in_quad(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_quad(5.0), abs=0.00001) == 25.0

def test_out_quad():
    assert approx(rpeasings.out_quad(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_quad(0.3), abs=0.00001) == 0.51
    assert approx(rpeasings.out_quad(0.5), abs=0.00001) == 0.75
    assert approx(rpeasings.out_quad(0.6), abs=0.00001) == 0.84
    assert approx(rpeasings.out_quad(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_quad(5.0), abs=0.00001) == -15.0

def test_in_out_quad():
    assert approx(rpeasings.in_out_quad(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_quad(0.3), abs=0.00001) == 0.18
    assert approx(rpeasings.in_out_quad(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_quad(0.6), abs=0.00001) == 0.68
    assert approx(rpeasings.in_out_quad(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_quad(5.0), abs=0.00001) == -31.0

def test_in_cubic():
    assert approx(rpeasings.in_cubic(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_cubic(0.3), abs=0.00001) == 0.027
    assert approx(rpeasings.in_cubic(0.5), abs=0.00001) == 0.125
    assert approx(rpeasings.in_cubic(0.6), abs=0.00001) == 0.216
    assert approx(rpeasings.in_cubic(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_cubic(5.0), abs=0.00001) == 125.0

def test_out_cubic():
    assert approx(rpeasings.out_cubic(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_cubic(0.3), abs=0.00001) == 0.657
    assert approx(rpeasings.out_cubic(0.5), abs=0.00001) == 0.875
    assert approx(rpeasings.out_cubic(0.6), abs=0.00001) == 0.936
    assert approx(rpeasings.out_cubic(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_cubic(5.0), abs=0.00001) == 65.0

def test_in_out_cubic():
    assert approx(rpeasings.in_out_cubic(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_cubic(0.3), abs=0.00001) == 0.108
    assert approx(rpeasings.in_out_cubic(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_cubic(0.6), abs=0.00001) == 0.744
    assert approx(rpeasings.in_out_cubic(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_cubic(5.0), abs=0.00001) == 257.0

def test_in_quart():
    assert approx(rpeasings.in_quart(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_quart(0.3), abs=0.00001) == 0.0081
    assert approx(rpeasings.in_quart(0.5), abs=0.00001) == 0.0625
    assert approx(rpeasings.in_quart(0.6), abs=0.00001) == 0.1296
    assert approx(rpeasings.in_quart(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_quart(5.0), abs=0.00001) == 625.0

def test_out_quart():
    assert approx(rpeasings.out_quart(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_quart(0.3), abs=0.00001) == 0.7599
    assert approx(rpeasings.out_quart(0.5), abs=0.00001) == 0.9375
    assert approx(rpeasings.out_quart(0.6), abs=0.00001) == 0.9744
    assert approx(rpeasings.out_quart(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_quart(5.0), abs=0.00001) == -255.0

def test_in_out_quart():
    assert approx(rpeasings.in_out_quart(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_quart(0.3), abs=0.00001) == 0.0648
    assert approx(rpeasings.in_out_quart(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_quart(0.6), abs=0.00001) == 0.7952
    assert approx(rpeasings.in_out_quart(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_quart(5.0), abs=0.00001) == -2047.0

def test_in_quint():
    assert approx(rpeasings.in_quint(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_quint(0.3), abs=0.00001) == 0.00243
    assert approx(rpeasings.in_quint(0.5), abs=0.00001) == 0.03125
    assert approx(rpeasings.in_quint(0.6), abs=0.00001) == 0.07776
    assert approx(rpeasings.in_quint(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_quint(5.0), abs=0.00001) == 3125.0

def test_out_quint():
    assert approx(rpeasings.out_quint(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_quint(0.3), abs=0.00001) == 0.83193
    assert approx(rpeasings.out_quint(0.5), abs=0.00001) == 0.96875
    assert approx(rpeasings.out_quint(0.6), abs=0.00001) == 0.98976
    assert approx(rpeasings.out_quint(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_quint(5.0), abs=0.00001) == 1025.0

def test_in_out_quint():
    assert approx(rpeasings.in_out_quint(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_quint(0.3), abs=0.00001) == 0.03888
    assert approx(rpeasings.in_out_quint(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_quint(0.6), abs=0.00001) == 0.83616
    assert approx(rpeasings.in_out_quint(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_quint(5.0), abs=0.00001) == 16385.0

def test_in_sine():
    assert approx(rpeasings.in_sine(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_sine(0.3), abs=0.00001) == 0.10899
    assert approx(rpeasings.in_sine(0.5), abs=0.00001) == 0.29289
    assert approx(rpeasings.in_sine(0.6), abs=0.00001) == 0.41221
    assert approx(rpeasings.in_sine(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_sine(5.0), abs=0.00001) == 1.0

def test_out_sine():
    assert approx(rpeasings.out_sine(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_sine(0.3), abs=0.00001) == 0.45399
    assert approx(rpeasings.out_sine(0.5), abs=0.00001) == 0.70711
    assert approx(rpeasings.out_sine(0.6), abs=0.00001) == 0.80902
    assert approx(rpeasings.out_sine(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_sine(5.0), abs=0.00001) == 1.0

def test_in_out_sine():
    assert approx(rpeasings.in_out_sine(0.0), abs=0.00001) == -0.0
    assert approx(rpeasings.in_out_sine(0.3), abs=0.00001) == 0.20611
    assert approx(rpeasings.in_out_sine(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_sine(0.6), abs=0.00001) == 0.65451
    assert approx(rpeasings.in_out_sine(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_sine(5.0), abs=0.00001) == 1.0

def test_in_expo():
    assert approx(rpeasings.in_expo(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_expo(0.3), abs=0.00001) == 0.00781
    assert approx(rpeasings.in_expo(0.5), abs=0.00001) == 0.03125
    assert approx(rpeasings.in_expo(0.6), abs=0.00001) == 0.0625
    assert approx(rpeasings.in_expo(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_expo(5.0), abs=0.00001) == 1099511627776.0

def test_out_expo():
    assert approx(rpeasings.out_expo(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_expo(0.3), abs=0.00001) == 0.875
    assert approx(rpeasings.out_expo(0.5), abs=0.00001) == 0.96875
    assert approx(rpeasings.out_expo(0.6), abs=0.00001) == 0.98438
    assert approx(rpeasings.out_expo(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_expo(5.0), abs=0.00001) == 1.0

def test_in_out_expo():
    assert approx(rpeasings.in_out_expo(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_expo(0.3), abs=0.00001) == 0.03125
    assert approx(rpeasings.in_out_expo(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_expo(0.6), abs=0.00001) == 0.875
    assert approx(rpeasings.in_out_expo(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_expo(5.0), abs=0.00001) == 1.0

def test_in_circ():
    assert approx(rpeasings.in_circ(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_circ(0.3), abs=0.00001) == 0.04606
    assert approx(rpeasings.in_circ(0.5), abs=0.00001) == 0.13397
    assert approx(rpeasings.in_circ(0.6), abs=0.00001) == 0.2
    assert approx(rpeasings.in_circ(1.0), abs=0.00001) == 1.0

def test_out_circ():
    assert approx(rpeasings.out_circ(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_circ(0.3), abs=0.00001) == 0.71414
    assert approx(rpeasings.out_circ(0.5), abs=0.00001) == 0.86603
    assert approx(rpeasings.out_circ(0.6), abs=0.00001) == 0.91652
    assert approx(rpeasings.out_circ(1.0), abs=0.00001) == 1.0

def test_in_out_circ():
    assert approx(rpeasings.in_out_circ(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_circ(0.3), abs=0.00001) == 0.1
    assert approx(rpeasings.in_out_circ(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_circ(0.6), abs=0.00001) == 0.8
    assert approx(rpeasings.in_out_circ(1.0), abs=0.00001) == 1.0

def test_in_back():
    assert approx(rpeasings.in_back(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_back(0.3), abs=0.00001) == -0.0802
    assert approx(rpeasings.in_back(0.5), abs=0.00001) == -0.0877
    assert approx(rpeasings.in_back(0.6), abs=0.00001) == -0.02903
    assert approx(rpeasings.in_back(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_back(5.0), abs=0.00001) == 295.158

def test_out_back():
    assert approx(rpeasings.out_back(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_back(0.3), abs=0.00001) == 0.90713
    assert approx(rpeasings.out_back(0.5), abs=0.00001) == 1.0877
    assert approx(rpeasings.out_back(0.6), abs=0.00001) == 1.09935
    assert approx(rpeasings.out_back(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_back(5.0), abs=0.00001) == 201.1264

def test_in_out_back():
    assert approx(rpeasings.in_out_back(0.0), abs=0.00001) == -0.0
    assert approx(rpeasings.in_out_back(0.3), abs=0.00001) == -0.07883
    assert approx(rpeasings.in_out_back(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_back(0.6), abs=0.00001) == 0.91007
    assert approx(rpeasings.in_out_back(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_back(5.0), abs=0.00001) == 1004.33394

def test_in_elastic():
    assert approx(rpeasings.in_elastic(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_elastic(0.3), abs=0.00001) == -0.00391
    assert approx(rpeasings.in_elastic(0.5), abs=0.00001) == -0.01563
    assert approx(rpeasings.in_elastic(0.6), abs=0.00001) == -0.03125
    assert approx(rpeasings.in_elastic(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_elastic(5.0), abs=0.00001) == -549755813887.993

def test_out_elastic():
    assert approx(rpeasings.out_elastic(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_elastic(0.3), abs=0.00001) == 0.875
    assert approx(rpeasings.out_elastic(0.5), abs=0.00001) == 1.01562
    assert approx(rpeasings.out_elastic(0.6), abs=0.00001) == 0.98438
    assert approx(rpeasings.out_elastic(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_elastic(5.0), abs=0.00001) == 1.0

def test_in_out_elastic():
    assert approx(rpeasings.in_out_elastic(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_elastic(0.3), abs=0.00001) == 0.02394
    assert approx(rpeasings.in_out_elastic(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_elastic(0.6), abs=0.00001) == 1.11746
    assert approx(rpeasings.in_out_elastic(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_elastic(5.0), abs=0.00001) == 1.0

def test_in_bounce():
    assert approx(rpeasings.in_bounce(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_bounce(0.3), abs=0.00001) == 0.06937
    assert approx(rpeasings.in_bounce(0.5), abs=0.00001) == 0.23438
    assert approx(rpeasings.in_bounce(0.6), abs=0.00001) == 0.09
    assert approx(rpeasings.in_bounce(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_bounce(5.0), abs=0.00001) == -120.0

def test_out_bounce():
    assert approx(rpeasings.out_bounce(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.out_bounce(0.3), abs=0.00001) == 0.68062
    assert approx(rpeasings.out_bounce(0.5), abs=0.00001) == 0.76562
    assert approx(rpeasings.out_bounce(0.6), abs=0.00001) == 0.7725
    assert approx(rpeasings.out_bounce(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.out_bounce(5.0), abs=0.00001) == 124.75

def test_in_out_bounce():
    assert approx(rpeasings.in_out_bounce(0.0), abs=0.00001) == 0.0
    assert approx(rpeasings.in_out_bounce(0.3), abs=0.00001) == 0.045
    assert approx(rpeasings.in_out_bounce(0.5), abs=0.00001) == 0.5
    assert approx(rpeasings.in_out_bounce(0.6), abs=0.00001) == 0.65125
    assert approx(rpeasings.in_out_bounce(1.0), abs=0.00001) == 1.0
    assert approx(rpeasings.in_out_bounce(5.0), abs=0.00001) == 245.75

def test_include():
    assert (files('rpeasings.include') / 'rpeasings.h').exists()


if __name__ == "__main__":
    test_null()
    test_bounce_out()
    test_in_quad()
    test_out_quad()
    test_in_out_quad()
    test_in_cubic()
    test_out_cubic()
    test_in_out_cubic()
    test_in_quart()
    test_out_quart()
    test_in_out_quart()
    test_in_quint()
    test_out_quint()
    test_in_out_quint()
    test_in_sine()
    test_out_sine()
    test_in_out_sine()
    test_in_expo()
    test_out_expo()
    test_in_out_expo()
    test_in_circ()
    test_out_circ()
    test_in_out_circ()
    test_in_back()
    test_out_back()
    test_in_out_back()
    test_in_elastic()
    test_out_elastic()
    test_in_out_elastic()
    test_in_bounce()
    test_out_bounce()
    test_in_out_bounce()
    test_include()
