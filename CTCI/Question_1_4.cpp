/*

    1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

*/

#include <iostream>

using namespace std;

bool palindromePermutation(string str){
    int hashMap[128] = {0};
    for(int i = 0; i < str.size();i++){
        if(str.at(i) != ' ')
            hashMap[(int)tolower(str.at(i))]++;
    }
    int numberOdd = 0;
    for(int i = 0; i < 128;i++){
        if(hashMap[i] % 2 != 0)
            numberOdd++;
        if(numberOdd > 1)
            return false;
    }
    return true;
}

int main(void){
    string str = "bulbul";
    if(palindromePermutation(str))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}