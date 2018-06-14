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

## Notice

Copyright (c) 2018-2018 Yuri Georgievski (ygeorgi@anl.gov), Stephen J.
Klippenstein (sjk@anl.gov), and Argonne National Laboratory.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
