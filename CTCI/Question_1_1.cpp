/*
    Question
    1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
        cannot use additional data structures?
*/


#include <iostream>
#include <vector>

using namespace std;

//Using bit vector
// Assuming there are only alphabets in the string. If there are other characters then to be mentioned or ask the interviewer regarding the same;
bool checkUnique(string str){
    bool arr[26] = {false};
    int index;
    for(int i = 0; i < str.size();i++){
        index = tolower(str.at(i)) - 96;
        if(!arr[index])
            arr[index] = !arr[index];
        else
            return false;
    }
    return true;
}


bool checkIfAllUnique(string str){
    vector<int>hashMap(26);
    for(int i = 0; i < str.size();i++){
        int index = tolower(str.at(i)) - 96;
        hashMap[index]++;
        if(hashMap[index] > 1)
            return false;
    }
    return true;
}

int main(void){
    cout << "Enter String" << endl;
    string str;
    cin >> str;
    if(checkIfAllUnique(str))
        cout << "All uniques" << endl;
    else
        cout << "Not all characters unique" << endl;
}