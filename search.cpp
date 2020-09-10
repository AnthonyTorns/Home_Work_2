/*
*Linear Search:
* for( ......)
*  if (number is found at pos)
*       return pos. 
*  if( i greater than lenghth )
        return -1.
* Binary Search:
* int first, middle, last
* middle = (last-first)/2
* 
*   if( number is found at array[middle])
*     return at pos
*   else {
*     if( number is grater than value at array[middle]){
*       search values after midpoint
*      }
*      else if(number is less than value at array[middle]){
*          search before array[middle]
*      }
*   }
*
*
*  
*/
#include "search.h"
int LinearSearch(int numbers[], int length, int n) {
    int i;
    for( i = 0; i < length; i++){
        if( numbers[i] == n){
            return i;
        }
    }
    if( i == length ){
        return -1;
    }
    

   return 1;
}

int BinarySearch(int numbers[], int length, int n) {
    int first = length-length;
    int last = length--;
    int middle;
    int found = false;
    for(int i = 0; i < length; i++){
        middle = (last-first)/2;
        if( numbers[middle]==n){
            return middle;
        }
        else{ 
            if(n>numbers[middle]){
                first = middle++;
            }
            else{
                last = middle--;

            }
        }
    }
    if (found == false){
        return -1;
    }

     return 1;
}

