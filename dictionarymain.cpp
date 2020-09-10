#include <iostream>
#include <string> 
#include "dictionary.h"

int main(){
    std::string words[] = { "Apple", "Orange", "Pear", "Pineapple",};
    int array_size = sizeof(words)/sizeof(words[0]);
    std::cout<<array_size<<std::endl;
    std::cout<<MinWordLength(words, array_size)<<std::endl;
    std::cout<<MaxWordLength(words, array_size)<<std::endl;
    std::cout<<WordLengthRange(words, array_size)<<std::endl;
    std::cout<<AverageWordLength(words, array_size)<<std::endl;
    std::cout<<MostCommonWordLength(words,array_size)<<std::endl;


    return 0;
}