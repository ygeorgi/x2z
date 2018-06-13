import x2ztools
import numpy
import pytest


def test__mass():
    assert numpy.allclose(x2ztools.mass('C'), 21874.661832)
    assert numpy.allclose(x2ztools.mass('C', iso=13), 23703.6661089)


def test__is_linear():

    with pytest.raises(ValueError):
        x2ztools.is_linear(('H',), [(0., 0.)])

    with pytest.raises(ValueError):
        x2ztools.is_linear(('H',), [(0., 0., 0.), (0., 0., 1.)])

    assert x2ztools.is_linear(('O', 'H', 'H'),
                              [(0., 0., 0.),
                               (0., 0., 1.),
                               (0., 1., 0.)]) is False
    assert x2ztools.is_linear(('O', 'H', 'H'),
                              [(0., 0., 0.),
                               (0., 0., 1.),
                               (0., 0., 2.)]) is True


def test__is_planar():
    r2 = numpy.sqrt(2.)
    assert x2ztools.is_planar(('N', 'H', 'H', 'H'),
                              [(0., 0., 1.),
                               (r2, 0., 0.),
                               (-1., -1., 0.),
                               (-1., +1., 0.)]) is False
    assert x2ztools.is_planar(('N', 'H', 'H', 'H'),
                              [(0., 0., 0.),
                               (r2, 0., 0.),
                               (-1., -1., 0.),
                               (-1., +1., 0.)]) is True
