import x2ztools
import numpy


def test__mass():
    assert numpy.allclose(x2ztools.mass('C'), 21874.661832)
    assert numpy.allclose(x2ztools.mass('C', iso=13), 23703.6661089)


def test__atom_string():
    assert (x2ztools.atom_string('C', (1.123098123, 0., 2.1239081)) ==
            ' C         1.1231              0        2.12391')
