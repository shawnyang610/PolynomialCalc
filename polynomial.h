// Single Variable Polynomial Calculator
// Reads Polynomials in pairs from input.txt, the main logic performs sample
// class level addition, subtraction and multiplications.
// Author: Shawn Yang
// 10/11/2018

#ifndef POLYNOMIAL_CALC_POLYNOMIAL_H
#define POLYNOMIAL_CALC_POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

// Store each pair of numbers read from a line aka Term in Polynomial
struct Term {
    int coe;
    int exp;
    Term (int, int);
};

// Stores all terms from a line in both original form and canonical form.
class Polynomial {
    std::vector<Term> origin_plynm;
    std::vector<Term> canonic_plynm;

public:
    // Constructor
    Polynomial();
    Polynomial(std::string list);

//    void operator= (const Polynomial &);
    Polynomial operator+ (const Polynomial &);
    Polynomial operator- (const Polynomial &);
    Polynomial operator* (const Polynomial &);

    void print_original();
    void print_canonical();

    void output_original(std::ofstream &);
    void output_canonical(std::ofstream &);

    void print(const std::vector<Term> &);
    void output(const std::vector<Term> &, std::ofstream &);


    // reduce its terms to canonical form
    void set_canonic();
};


#endif //POLYNOMIAL_CALC_POLYNOMIAL_H
