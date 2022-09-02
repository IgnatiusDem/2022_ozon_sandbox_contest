/** @file main.cpp
 *  @brief Output of the sum of two integers
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>

int main() {
    int t; // number of input data sets
    std::cin>>t;
    for(int i=0;i<t;i++){
        int a,b; // two integers
        std::cin>>a>>b;
        std::cout<<a+b<<std::endl; // sum of two integers
    }
}
