#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "libx2z/units.hh"
#include "libx2z/chem.hh"

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


Atom _atom(const std::string& l, const std::vector<double>& xyz, int iso = 0) {
    if (xyz.size() != 3)
        throw std::invalid_argument("Coordinate vector must have 3 elements.");

    Atom a = Atom(l);
    if (iso == 0)
        a = Atom(l);
    else
        a = Atom(l, iso);
    a[0] = xyz[0];
    a[1] = xyz[1];
    a[2] = xyz[2];
    return a;
}


MolecGeom _molec_geom(const std::vector<std::string>& ls,
                      const std::vector<std::vector<double>>& xyzs,
                      const std::vector<int>& isos = std::vector<int>()) {
    int n = ls.size();

    if (xyzs.size() != n || (isos.size() !=n && isos.size() != 0))
        throw std::invalid_argument("Molecule arguments do not match");

    MolecGeom mg;
    for (int i = 0; i < n; ++i) {
        Atom a = _atom(ls[i], xyzs[i]);
        a /= Phys_const::bohr;
        mg.push_back(a);
    }
    return mg;
}


MolecOrient _molec_orient(const std::vector<std::string>& ls,
                          const std::vector<std::vector<double>>& xyzs,
                          const std::vector<int>& isos = std::vector<int>()) {
    MolecGeom mg = _molec_geom(ls, xyzs, isos);
    MolecOrient mo(mg);
    return mo;
}


// Functions for python binding
double mass(const std::string& l, int iso = 0) {
    AtomBase a = _atom_base(l, iso);
    return a.mass();
}


bool is_linear(const std::vector<std::string>& ls,
               const std::vector<std::vector<double>>& xyzs) {
    MolecOrient mo = _molec_orient(ls, xyzs);
    return mo.is_linear();
}


bool is_planar(const std::vector<std::string>& ls,
               const std::vector<std::vector<double>>& xyzs) {
    MolecOrient mo = _molec_orient(ls, xyzs);
    return mo.is_plane();
}


PYBIND11_MODULE(x2ztools, module) {
    module.def("mass", &mass,
               "Get the mass of an isotope",
               py::arg("l"), py::arg("iso")=0);
    module.def("is_linear", &is_linear,
               "Find out whether a molecule is linear",
               py::arg("ls"), py::arg("xyzs"));
    module.def("is_planar", &is_planar,
               "Find out whether a molecule is planar",
               py::arg("ls"), py::arg("xyzs"));
}
