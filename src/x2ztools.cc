#include <iostream>
#include <string>
#include <sstream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "libx2z/atom.hh"

namespace py = pybind11;


// Helpers
AtomBase _atom_base(const std::string& l, int iso = 0) {
    AtomBase a;
    if (iso == 0)
        a = AtomBase(l);
    else
        a = AtomBase(l, iso);
    return a;
}


Atom _atom(const std::string& l, const std::vector<double>& xyz,
                 int iso = 0) {
    Atom a = Atom(l);
    a[0] = xyz[0];
    a[1] = xyz[1];
    a[2] = xyz[2];
    return a;
}


// Functions for python binding
double mass(const std::string& l, int iso = 0) {
    AtomBase a = _atom_base(l, iso);
    return a.mass();
}


std::string atom_string(const std::string& l, const std::vector<double>& xyz,
                        int iso = 0) {
    Atom a = _atom(l, xyz, iso);
    std::ostringstream stream;
    stream << a;
    std::string s = stream.str();
    return s;
}


PYBIND11_MODULE(x2ztools, module) {
    module.def("mass", &mass,
               "Get the mass of an isotope",
               py::arg("l"), py::arg("iso")=0);
    module.def("atom_string", &atom_string,
               "Get the string representation of an atom",
               py::arg("l"), py::arg("xyz"), py::arg("iso")=0);
}
