/*
    Question 1.2 - 
        Check Permutation: Given two strings, write a method to decide if one is a permutation of the
        other.

        What is permutation of a string ?
            Characters rearranged for example - "ABC" has following permutations
            ABC ACB BAC BCA CBA CAB
        
        This tells us that the number of characters in the original string and the permutaion string are the same

        Assumptions made :- 
            String consists only of alphabets. Whitespaces are not considered;
*/

#include <iostream>
#include <vector>

using namespace std;

bool checkPermutation(string s1, string s2){
    if(s1.size() != s2.size())
        return false;
    int arr[26] = {0};
    int indexS1,indexS2;
    for(int i = 0; i < s1.size();i++){
        indexS1 = tolower(s1.at(i)) - 96;
        indexS2 = tolower(s2.at(i)) - 96;
        arr[indexS1]++;
        arr[indexS2]--;
    }
    for(int i = 0 ; i < 26;i++){
        if(arr[i] != 0)
            return false;
    }
    return true;
}

int main(void){
    string s1;
    string s2;
    cout << "Enter string 1" << endl;
    cin >> s1;
    cout << "Enter string 2" << endl;
    cin >> s2;
    if(checkPermutation(s1,s2))
        cout << "Yes permutation" << endl;
    else
        cout << "Not a permutation" << endl;
}