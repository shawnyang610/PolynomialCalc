// Single Variable Polynomial Calculator
// Reads Polynomials in pairs from input.txt, the main logic performs sample
// class level addition, subtraction and multiplications.
// Author: Shawn Yang
// 10/11/2018

#include "polynomial.h"



void read_text_example(){
    std::ifstream infile ("input.txt");
    std::string line;
    while (std::getline(infile, line)){
        std::istringstream iss(line);
        int a, b;
        while (iss>>a>>b) {
            std::cout << a << " " << b << " ";
        }
        std::cout <<std::endl;
    }
    infile.close();
}

int main() {

    int count=0;

    std::ifstream infile ("input.txt");
    std::ofstream outfile ("output.txt");
    std::string line;
    while (std::getline(infile, line)){
        std::cout<<"Pair "<<count++<<std::endl;
        outfile<<"Pair "<<count<<std::endl;

        // Create a pair of Polinomials
        Polynomial a(line);
        std::getline(infile, line);
        Polynomial b(line);

        // Print original and canonical of the pair
        a.print_original();
        a.print_canonical();
        a.output_original(outfile);
        a.output_canonical(outfile);

        b.print_original();
        b.print_canonical();
        b.output_original(outfile);
        b.output_canonical(outfile);

        // Arithmetics
        std::cout<<"======= Addition ======="<<std::endl;
        outfile<<"======= Addition ======="<<std::endl;

        Polynomial c;
        c = a + b;
        c.print_canonical();
        c.output_canonical(outfile);

        std::cout<<"======= Subtraction ======="<<std::endl;
        outfile<<"======= Subtraction ======="<<std::endl;

        Polynomial d;
        d = a - b;
        d.print_canonical();
        d.output_canonical(outfile);

        std::cout<<"======= Multiplication ======="<<std::endl;
        outfile<<"======= Multiplication ======="<<std::endl;

        Polynomial e;
        e = a * b;
        e.print_canonical();
        e.output_canonical(outfile);


        std::cout<<std::endl;
        outfile<<std::endl;
    }
    infile.close();
    outfile.close();



    return 0;
}