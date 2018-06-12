#include <iostream>
#include <string>
#include <pybind11/pybind11.h>
#include "libx2z/atom.hh"


int isotope(const std::string& s) {
    AtomBase a = AtomBase(s);
    return a.isotope();
}


PYBIND11_MODULE(x2ztools, module) {
    module.def("isotope", &isotope);
}
