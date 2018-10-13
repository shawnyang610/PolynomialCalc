// Single Variable Polynomial Calculator
// Reads Polynomials in pairs from input.txt, the main logic performs sample
// class level addition, subtraction and multiplications.
// Author: Shawn Yang
// 10/11/2018

#ifndef POLYNOMIAL_CALC_POLYNOMIAL_H
#define POLYNOMIAL_CALC_POLYNOMIAL_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "vector.h"

struct Term {
    int coe;
    int exp;
    Term(){
        coe=0;
        exp=0;
    };
    Term (int coe, int exp) {
        this->coe = coe;
        this->exp = exp;
    }
};



// Stores all terms from a line in both original form and canonical form.
class Polynomial {
    Vector<Term> origin_plynm;
    Vector<Term> canonic_plynm;

public:
    // Constructor
    Polynomial();
    Polynomial(std::string list);

//    void operator= (const Polynomial &);
    Polynomial operator+ (Polynomial &);
    Polynomial operator- (Polynomial &);
    Polynomial operator* (Polynomial &);

    void print_original();
    void print_canonical();

    void output_original(std::ofstream &);
    void output_canonical(std::ofstream &);

    void print(Vector<Term> &);
    void output(Vector<Term> &, std::ofstream &);


    // reduce its terms to canonical form
    void set_canonic();
};


#endif //POLYNOMIAL_CALC_POLYNOMIAL_H
