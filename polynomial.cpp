// Single Variable Polynomial Calculator
// Reads Polynomials in pairs from input.txt, the main logic performs sample
// class level addition, subtraction and multiplications.
// Author: Shawn Yang
// 10/11/2018

#include "polynomial.h"



Term::Term (int coe, int exp) {
    this->coe = coe;
    this->exp = exp;
}

Polynomial::Polynomial(){};


Polynomial::Polynomial(std::string list) {
    std::istringstream iss(list);
    int coe, exp;
    while(iss >> coe >> exp){
        origin_plynm.push_back(Term(coe, exp));
    }

    set_canonic();
}

//void Polynomial::operator=(const Polynomial & polynomial) {
//    origin_plynm = polynomial.origin_plynm;
//    canonic_plynm = polynomial.canonic_plynm;
//    set_canonic();
//}

Polynomial Polynomial::operator*(const Polynomial & polynomial) {
    Polynomial temp;
    for (Term t1 : canonic_plynm){
        for (Term t2 : polynomial.canonic_plynm){
            temp.origin_plynm.push_back(Term(t1.coe*t2.coe, t1.exp + t2.exp));
        }
    }
    temp.set_canonic();
    return temp;
}

Polynomial Polynomial::operator+(const Polynomial & polynomial) {
    Polynomial temp;
    for (Term term : origin_plynm){
        temp.origin_plynm.push_back(Term(term));
    }
    for (Term term : polynomial.origin_plynm){
        temp.origin_plynm.push_back(Term(term));
    }
    temp.set_canonic();
    return temp;
}

Polynomial Polynomial::operator-(const Polynomial & polynomial) {
    Polynomial temp;
    for (Term term : origin_plynm){
        temp.origin_plynm.push_back(Term(term));
    }
    for (Term term : polynomial.origin_plynm){
        temp.origin_plynm.push_back(Term(0-term.coe, term.exp));
    }
    temp.set_canonic();
    return temp;
}

void Polynomial::set_canonic() {
    // add up same exp terms
    for (auto term : origin_plynm) {
        bool is_saved = false;
        for (int i = 0; i < canonic_plynm.size(); i++) {
            if (canonic_plynm.at(i).exp == term.exp) {
                canonic_plynm.at(i).coe = canonic_plynm.at(i).coe + term.coe;
                is_saved = true;
                break;
            }
        }
        if (is_saved==false) {
            canonic_plynm.push_back(Term(term));
        }
    }
    // order terms from big exp to small exp and get ride of terms with coe=0
    bool is_changed=true;
    while (is_changed==true) {
        is_changed=false;
        for (int i = 1; i < canonic_plynm.size(); i++) {
        if (canonic_plynm.at(i-1).coe == 0){
            canonic_plynm.erase(canonic_plynm.begin()+i-1);
        }
            // bubble sort all terms from left to right
            if (canonic_plynm.at(i - 1).exp < canonic_plynm.at(i).exp) {
                int temp_coe = canonic_plynm.at(i - 1).coe;
                int temp_exp = canonic_plynm.at(i - 1).exp;

                canonic_plynm.at(i - 1).coe = canonic_plynm.at(i).coe;
                canonic_plynm.at(i - 1).exp = canonic_plynm.at(i).exp;

                canonic_plynm.at(i).coe = temp_coe;
                canonic_plynm.at(i).exp = temp_exp;
                is_changed = true;
            }
        }
    }
}

void Polynomial::print_original(){
    std::cout<<"original:  ";
    print(origin_plynm);
}

void Polynomial::print_canonical() {
    std::cout<<"canonical: ";
    print(canonic_plynm);
}

void Polynomial::output_original(std::ofstream &outfile) {
    outfile<<"original:  ";
    output(origin_plynm, outfile);
}

void Polynomial::output_canonical(std::ofstream &outfile) {
    outfile<<"canonical:  ";
    output(canonic_plynm, outfile);
}



void Polynomial::print(const std::vector<Term> & plynm) {
    for (int i=0; i<plynm.size(); i++){
        if (i==0 || plynm.at(i).coe<0){
            std::cout<<plynm.at(i).coe;
        }
        else {
            std::cout<<"+"<<plynm.at(i).coe;
        }

        if (plynm.at(i).exp>0){
            std::cout<<"X";
            if (plynm.at(i).exp>1){
                std::cout<<"^"<<plynm.at(i).exp;
            }
        }
    }
    std::cout<<std::endl;
}

void Polynomial::output(const std::vector<Term> &plynm, std::ofstream &outfile) {
    for (int i=0; i<plynm.size(); i++){
        if (i==0 || plynm.at(i).coe<0){
            outfile<<plynm.at(i).coe;
        }
        else {
            outfile<<"+"<<plynm.at(i).coe;
        }

        if (plynm.at(i).exp>0){
            outfile<<"X";
            if (plynm.at(i).exp>1){
                outfile<<"^"<<plynm.at(i).exp;
            }
        }
    }
    outfile<<std::endl;
}