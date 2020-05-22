/*

    One Away: There are three types of edits that can be performed on strings: insert a character,
    remove a character, or replace a character. Given two strings, write a function to check if they are
    one edit (or zero edits) away.
    EXAMPLE
    pale, ple -> true
    pales, pale -> true
    pale, bale -> true
    pale, bake -> false

*/

#include <iostream>

using namespace std;

bool isEqual(string s1,string s2){
    for(int i = 0; i < s1.size();i++){
        if(s1.at(i) != s2.at(i))
            return false;
    }
    return true;
}

bool isCharacterDifferent(string s1,string s2){
    bool oneCharacterDifferent = false;
    for(int i = 0; i < s1.size();i++){
        if(s1.at(i) != s2.at(i)){
            if(!oneCharacterDifferent)
                oneCharacterDifferent = !oneCharacterDifferent;
            else
                return false;
        }
    }
    return true;
}

bool isOneCharacterRemoved(string s1, string s2){
    if(s2.size() > s1.size())
        swap(s1,s2);
    int charSum = 0;
    int hashMap[26] = {0};
    for(int i = 0; i < s1.size();i++){
        int temp = tolower(s1.at(i));
        charSum += temp ;
        hashMap[temp-96]++;
    }
    for(int i = 0; i < s2.size();i++){
        int temp = tolower(s2.at(i));
        charSum -= temp ;
        hashMap[temp-96]--;
    }
    if(charSum >= 96 && charSum < 128 && hashMap[charSum-96] == 1)
        return true;
    return false;
}

bool isOneCharacterInserted(string s1,string s2){
    if(s2.size() > s1.size())
        swap(s1,s2);
    int charSum = 0;
    for(int i = 0; i < s1.size();i++){
        charSum += tolower(s1.at(i)) ;
    }
    for(int  i = 0; i < s2.size();i++){
        charSum -= tolower(s2.at(i)) ;
    }
    if(charSum >= 96 && charSum < 128)
        return true;
    return false;
}

bool oneAway(string s1,string s2){
    if(s1.size() == s2.size()){
        if(isEqual(s1,s2))
            return true;
        else if(isCharacterDifferent(s1,s2))
            return true;
        else
            return false;
    }
    else{
        if(isOneCharacterRemoved(s1,s2))
            return true;
        else if(isOneCharacterInserted(s1,s2))
            return true;
        else
            return false;
    }
}

int main(void){
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    if(oneAway(s1,s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}