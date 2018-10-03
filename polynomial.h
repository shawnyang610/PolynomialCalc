//
// Created by shawn on 10/2/18.
//

#ifndef POLYNOMIAL_CALC_POLYNOMIAL_H
#define POLYNOMIAL_CALC_POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <sstream>

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
    Polynomial(std::string list);

    void operator+ (const Polynomial &);
    void operator- (const Polynomial &);
    void operator* (const Polynomial &);

    void print_original();
    void print_canonical();
    void print(const std::vector<Term> &);

private:
    // reduce its terms to canonical form
    void set_canonic();
};


#endif //POLYNOMIAL_CALC_POLYNOMIAL_H
