/*

String Rotation:Assumeyou have a method isSubstringwhich checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").

*/

#include <iostream>

using namespace std;


bool isRotation(string s1,string s2){

    if(s1.size() != s2.size())
        return false;
    else{
        int i = 0;
        int j = 0;
        for(int i = 0; i < s1.size();i++){
            if(s1.at(i) == s2.at(j)){
                j++;
            }
        }
        if(j == 0)
            return false;
        string s = "";
        while(j < s2.size()){
            s += s2.at(++j);
        }
        if(isSubstring(s,s1))
            return true;
    }

    return false;
}


int main(void){

    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if(isRotation(s1,s2))
        cout << "Yes Roatation" << endl;
    else
        cout << "Not a rotation" << endl;
}