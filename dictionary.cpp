/****
* PSEUDOCODE:
* MinimumWord Length:
* int shortest = 0;
* int word_length = 0;  
* for(....){
*   word_length = words[pos].length();
*   if( lenghth of word < shortest or shortest == 0){
*     shortest = word_length
*   }
* }
* return shortest
*
* MaxWordLength:
* int longest = 0;
* int word_length = 0;  
* for(....){
*   word_length = words[pos].length();
*   if( lenghth of word > longest or longest == 0){
*     longest = word_length
*   }
* }
* return longest
* 
* WordLengthRange: 
* int longest = 0; 
* int shortest = 0;
* word_length = 0;
* for(...){
*   word_length = words[pos].length();
*   if( word length less than shortest or shortest is empty [initialized with 0]){
*     shortest = word_length;
*   }
*   else if( wordlength is greater than longest or longest is empty [ initialized with 0]){
*   longest = word_length;
*   }
* }
* int range = longest - shortest
* return range
*
* AvgWordLength
* int avg = 0;
* int sum = 0;
* for(...)
*   find length of each word and the lenghths into sum
*   
* avg =  sum /length of array 
* return avg
*
* MostCommonWordLength
* sort
* int string 
* bool swap
* do{
*  swap is set to false
*  while( ......){
*    if word length at pos is greater than wordlength at pos+ 1
*      word at pos is placed into holder
*      word at pos is initialized with word at pos+1
*      word at pos + 1 is intialized with 0(swap has occured)
*  }
* }while swap is true   
* 
* int count_occur, mode occur set to one ( each length in the array will occur at least once)
* int mode_length to keep track of the length of the word that occurs the most
* while(.....){
*  if word length at pos equal wordlength 
*    occur count goes up  
*  else{ 
*    if {the the occur count is > than the mode_occur
*      mode occur is intialized with the occur_count
*      mode length is set at the the word lengh at that particualr pos
*    }
*  }
* reset mode occur move on to next word
* }
* if mode occur doesnt change 
* return -1 
* return mode_length
*/
#include <string>
#include <iostream>
#include "dictionary.h"


int MinWordLength(std::string words[], int length) {
    // TODO implement this function
    int shortest = 0;
    int word_length = 0;
    int i = 0;
    while(i<length ){
        word_length = words[i].length();
        if( word_length < shortest || shortest == 0){
            shortest = word_length;
        }
        i++;
    }
    return shortest;
}

int MaxWordLength(std::string words[], int length) {
    int longest = 0;
    int word_length = 0;
    int i = 0;
    while(i< length ){
        word_length = words[i].length();
        if( word_length > longest || longest == 0){
            longest = word_length;
        }
        i++;
    }
    return longest;
}

int WordLengthRange(std::string words[], int length) {
    int i = 0;
    int word_length = 0;
    int longest = words[i].length();
    int shortest = words[i].length();
    while( i < length){
        word_length = words[i].length();
        if(word_length > longest){
            longest = word_length;
        }
        else if( word_length < shortest){
            shortest = word_length;
        }
        i++;
    }
    int range = longest - shortest;
    return range;
}

int AverageWordLength(std::string words[], int length) {
    int average = 0;
    int sum = 0;
    for( int i = 0; i < length; i++){
        sum += words[i].length();
    }
    average = sum/length;
    return average;
}
 
int MostCommonWordLength(std::string words[], int length) {
    // sort function
    std::string holder;
    bool swap;
    do{
        swap = false;
        for(int i = 0; i < length; i++){
            if( words[i].length() > words[i+1].length()){
                holder = words[i];
                words[i] = words[i+1];
                words[i+1] = holder; 
                swap = true;
            }
        }
    } while(swap == true);
    int count_occur = 1;
    int mode_occur = 1;
    int mode_length = 0;
    for(int i = 0; i < length; i++){
        if(words[i].length() == words[i+1].length()){
            count_occur++;
        }
        else{
            if(count_occur > mode_occur){
                mode_occur = count_occur;
                mode_length = words[i].length();
            }
            count_occur = 1;
        }
        
    }
    if( mode_occur == 1){
        return -1;
    }
    return mode_length;
}