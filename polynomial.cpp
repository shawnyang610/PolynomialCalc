// Single Variable Polynomial Calculator
// Reads Polynomials in pairs from input.txt, the main logic performs sample
// class level addition, subtraction and multiplications.
// Author: Shawn Yang
// 10/11/2018

#include "polynomial.h"





Polynomial::Polynomial(){};


Polynomial::Polynomial(std::string list) : original_count(0) {
    std::map<int,int>::iterator term;
    std::istringstream iss(list);
    int coe, exp;
    while(iss >> coe >> exp){
        // load canonic map
        term = canonic.find(exp);
        if (term == canonic.end()){
            canonic[exp]=coe;
        }
        else{
            int temp = term->second + coe;
            if (temp==0) {
                canonic.erase(term);
            }
            else{
                term->second = temp;
            }
        }

        // load original
        original[original_count++] = coe;
        original[original_count++] = exp;
    }

}

void Polynomial::operator=(const Polynomial & polynomial) {
    for (int i=0; i<100;i++){
        original[i] = polynomial.original[i];
    }
    canonic = polynomial.canonic;
}

Polynomial Polynomial::operator*(const Polynomial & polynomial) {
    Polynomial ret;

    for (auto term1:canonic){
        for (auto term2:polynomial.canonic){
            int coe = term1.second * term2.second;
            int exp = term1.first + term2.first;
            auto temp = ret.canonic.find(exp);
            if (temp == ret.canonic.end()){
                ret.canonic[exp] = coe;
            }
            else {
                coe = coe + temp->second;
                if (coe==0){
                    ret.canonic.erase(exp);
                }
                else{
                    temp->second = coe;
                }
            }
        }
    }

    return ret;
}

Polynomial Polynomial::operator+(const Polynomial & polynomial) {
    Polynomial ret;
    ret.canonic = this->canonic;
    for (auto term2:polynomial.canonic){
        auto term1 = ret.canonic.find(term2.first);
        if (term1 == ret.canonic.end()){
            ret.canonic[term2.first] = term2.second;
        }
        else{
            int t = term1->second + term2.second;
            if (t==0){
                ret.canonic.erase(term2.first);
            }
            else{
                term1->second = t;
            }
        }
    }
    return ret;
}

Polynomial Polynomial::operator-(const Polynomial & polynomial) {
    Polynomial ret;
    ret.canonic = this->canonic;
    for (auto term2:polynomial.canonic){
        auto term1 = ret.canonic.find(term2.first);
        if (term1 == ret.canonic.end()){
            ret.canonic[term2.first] = -term2.second;
        }
        else{
            int t = term1->second - term2.second;
            if (t==0){
                ret.canonic.erase(term2.first);
            }
            else{
                term1->second = t;
            }
        }
    }
    return ret;
}



void Polynomial::print_original(){
    std::cout<<"original:  ";
    int i=0;
    while (i <=original_count-2){
        if (i==0 || original[i]<0){
            std::cout<<original[i];
        }
        else {
            std::cout<<"+"<<original[i];
        }
        i++;

        if (original[i]>0){
            std::cout<<"X";
            if (original[i]>1){
                std::cout<<"^"<<original[i];
            }
        }
        i++;
    }
    std::cout<<std::endl;
}

void Polynomial::print_canonical() {
    std::cout<<"canonical: ";
    int count=0;
    for (auto term : canonic){
        if (count==0 || term.second<0){
            std::cout<<term.second;
        }
        else {
            std::cout<<"+"<<term.second;
        }
        count++;

        if (term.first>0){
            std::cout<<"X";
            if (term.first>1){
                std::cout<<"^"<<term.first;
            }
        }
        count++;
    }
    std::cout<<std::endl;
}

void Polynomial::output_original(std::ofstream &outfile) {
    outfile<<"original:  ";
    int i=0;
    while (i <=original_count-2){
        if (i==0 || original[i]<0){
            outfile<<original[i];
        }
        else {
            outfile<<"+"<<original[i];
        }
        i++;

        if (original[i]>0){
            outfile<<"X";
            if (original[i]>1){
                outfile<<"^"<<original[i];
            }
        }
        i++;
    }
    outfile<<std::endl;
}

void Polynomial::output_canonical(std::ofstream &outfile) {
    outfile<<"canonical:  ";
    int count=0;
    for (auto term : canonic){
        if (count==0 || term.second<0){
            outfile<<term.second;
        }
        else {
            outfile<<"+"<<term.second;
        }
        count++;

        if (term.first>0){
            outfile<<"X";
            if (term.first>1){
                outfile<<"^"<<term.first;
            }
        }
        count++;
    }
    outfile<<std::endl;
}


