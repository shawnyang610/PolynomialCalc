#include "polynomial.h"
#include <iostream>
#include <fstream>
#include <sstream>


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

//    read_text_example();

    std::ifstream infile ("input.txt");
    std::string line;
    while (std::getline(infile, line)){
        Polynomial a(line);

        std::getline(infile, line);
        Polynomial b(line);

        a.print_original();
        b.print_original();
    }

    return 0;
}