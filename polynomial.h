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
#include <map>


// Stores all terms from a line in both original form and canonical form.
class Polynomial {
    std::map<int,int> canonic;
    int original[100];
    int original_count;
public:
    // Constructor
    Polynomial();
    Polynomial(std::string list);

    void operator= (const Polynomial &);
    Polynomial operator+ (const Polynomial &);
    Polynomial operator- (const Polynomial &);
    Polynomial operator* (const Polynomial &);

    void print_original();
    void print_canonical();

    void output_original(std::ofstream &);
    void output_canonical(std::ofstream &);

};


#endif //POLYNOMIAL_CALC_POLYNOMIAL_H
