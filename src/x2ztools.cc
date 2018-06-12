#include <iostream>
#include <string>
#include "libx2z/atom.hh"


int atom_isotope(const std::string& s) {
    AtomBase a = AtomBase(s);
    return a.isotope();
}


int main() {
    const std::string s = "C";
    std::cout << atom_isotope(s) << std::endl;
}
