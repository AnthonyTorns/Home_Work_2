#include <iostream>
#include <string>
#include "nth_root_finder.h"

int main() {
    int digit = 105;
    int root =  3;
    int decimal_places = 6;
    std::cout<<FindNthRoot( digit, root, decimal_places)<<std::endl;
    return 0;
}