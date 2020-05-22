/**
 *      Question 1_3 - 
 *          URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
            has sufficient space at the end to hold the additional characters, and that you are given the "true"
            length of the string. (Note: if implementing in Java, please use a character array so that you can
            perform this operation in place.)
            
            A common approach in string manipulation problems is to edit the string starting from the end and working
backwards. This is useful because we have an extra buffer at the end, which allows us to change characters
without worrying about what we're overwriting. We will use this approach in this problem. The algorithm employs a two-scan approach. In the first scan, we
count the number of spaces. By tripling this number, we can compute how many extra characters we will
have in the final string. In the second pass, which is done in reverse order, we actually edit the string. When
we see a space, we replace it with %20. If there is no space, then we copy the original character.
*/

#include <iostream>
#include <deque>

using namespace std;

string urlIfy(string str, int trueLength){
    int spaceCount = 0;
    for(int i = 0; i < trueLength;i++){
        if(str.at(i) == ' ')
            spaceCount++;
    }
    int index = trueLength + spaceCount * 2;
    for(int i = trueLength - 1;i >= 0;i--){
        if(str.at(i) == ' '){
            str.at(index-1)='0';
            str.at(index-2)='2';
            str.at(index-3)='%';
            index -= 3;
        }
        else{
            str.at(index-1) = str.at(i);
            index--;
        }
    }
    return str;
}

int main(void){
    string str = "Mr John Smith    ";
    int trueLength = 13;
    cout << urlIfy(str,trueLength) << endl;
}