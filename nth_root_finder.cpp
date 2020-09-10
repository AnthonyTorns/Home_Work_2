/****
* PSEUDOCODE:
* if the number(radicand) is = 0
*   the root will be zero
* else if the number(radicand) == 1 or (n) the radical == 0
*  root = 1
* else if n(radical) is 1
*   root == number(radicand)
* else if n(radical) == 0 && number(radicand) == 0
*  root in string form is intialized with ERROR
* else 
* while( the variable radicand != number){
*   for(.....)(used to multiply guessed root by iself starting from 0){
*     ........    
*   }
*   radicand == calculated result after root is multiplied by itself n times (n refers to the radicsl)
*   if radicand < number then
*      root is incremented by 1 or .1, or .01...... depends on decimal spo in variable decimal_palces
*      root_hold = 1 to allow the root to be multiplied by itself again
*   if radicand > number then
*     root is de incramented by the value in decimal places since the root is currently to big
*     decimal_places is multiplied by .1 to allow for adding of another decimal place
*     root_hold = 1 to allow for the root to be multiplied by itself 
}
* sstream used to convert root value into a string 
* return root_string
* 
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

std::string FindNthRoot(int number, int n, int precision) {
    double root = 0;
    float radicand = 0;
    double root_hold = 1;
    double decimal_places = 1;
    stringstream convert_to_string;
    std::string root_string;
    
    if(number == 0){
        root = 0;
    }
    else if(number == 1 || n == 0){
        root = 1;
    }
    else if(n==1){
        root = number;
    }
    else if( n == 0 && number == 0){
        root_string = "ERROR";
    }
    else{ 
        while(radicand != number){
            for(int i = 0; i < n; i++){
                root_hold=root*root_hold;
            }
            radicand = root_hold;

            if(radicand < number){
                root += decimal_places;
                root_hold = 1;
            }
             if(radicand > number){
                root -= decimal_places;
                decimal_places *= .1;
                root += decimal_places;
                root_hold = 1;
            }
        }
    }
    convert_to_string<<std::fixed<<std::setprecision(precision)<<root;
    root_string = convert_to_string.str();
    return root_string;
}
