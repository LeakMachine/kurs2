// Copyright 2022 Marina Usova

#include <stdio.h>
#include <string>


#include "../lib_polynomial/polynomial.h"


int main() {
    CPolynomial poly, poly2;
    poly.Parse("2x");
    poly2.Parse("2y");
    poly = poly * poly2;
    std::string maths = poly.toString();
    std::cout << poly.findResult(1, 1, 0, maths);
    return 0;
}
