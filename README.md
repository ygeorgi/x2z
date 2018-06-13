# x2z

[![Build Status](https://travis-ci.org/PACChem/x2z.svg)](https://travis-ci.org/PACChem/x2z)

## Install

The following commands will build the executable and place it in your bin.
```
mkdir build
cd build
cmake ..
make
sudo make install
cd ..
```
You can then try it out on an xyz file like this:
```
x2z examples/ch4.xyz
```
If you wish to use the Python bindings, do
```
export PYTHONPATH=$PYTHONPATH:/usr/local/lib
```
and you should be able to do things like the following.
```
>>> import x2ztools
>>> x2ztools.is_linear(('H', 'H'), [(0., 0., 0.), (0., 0., 1.)])
True
```

## Acknowledgment

This research was supported by the Exascale Computing Project (ECP), Project
Number: 17-SC-20-SC, a collaborative effort of two DOE organizations, the Office
of Science and the National Nuclear Security Administration, responsible for the
planning and preparation of a capable exascale ecosystem including software,
applications, hardware, advanced system engineering, and early test bed
platforms to support the nation's exascale computing imperative. 
