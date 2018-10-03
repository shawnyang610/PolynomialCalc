//
// Created by shawn on 10/2/18.
//

#include "polynomial.h"



Term::Term (int coe, int exp) {
    this->coe = coe;
    this->exp = exp;
}

Polynomial::Polynomial(std::string list) {
    std::istringstream iss(list);
    int coe, exp;
    while(iss >> coe >> exp){
        origin_plynm.push_back(Term(coe, exp));
    }

    set_canonic();
}

void Polynomial::operator*(const Polynomial & polynomial) {
    // TODO
}

void Polynomial::operator+(const Polynomial & polynomial) {
    // TODO
}

void Polynomial::operator-(const Polynomial & polynomial) {
    // TODO
}

void Polynomial::set_canonic() {
    // TODO
}

void Polynomial::print_original(){
    print(origin_plynm);
}

void Polynomial::print_canonical() {
    // TODO
}

void Polynomial::print(const std::vector<Term> & plynm) {
    for (Term term:plynm){
        std::cout<<term.coe<<" "<<term.exp<<" ";
    }
    std::cout<<std::endl;
}