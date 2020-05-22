/*
    String Compression: Implement a method to perform basic string compression using the counts
    of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
    "compressed" string would not become smaller than the original string, your method should return
    the original string. You can assume the string has only uppercase and lowercase letters (a - z).
    Hints:#92, #110
*/

#include<iostream>
#include<vector>

using namespace std;

string compressString(string str){
    int hashMap[128] = {0};
    vector<string> compressedStr;
    int count = 1;
    char temp = str.at(0);
    for(int i = 1; i < str.size();i++){
        if(temp == str.at(i))
            count++;
        else{
            string s(1,temp);
            compressedStr.push_back(s);
            compressedStr.push_back(to_string(count));
            count = 1;
            temp = str.at(i);
        }
    }
    string s(1,temp);
    compressedStr.push_back(s);
    compressedStr.push_back(to_string(count));
    // for(int i = 65, j = 97;i < 91 && j < 128;i++,j++){
    //     if(hashMap[i] != 0){
    //         char x = (char)i;
    //         string s(1,x);
    //         compressedStr.push_back(s);
    //         compressedStr.push_back(to_string(hashMap[i]));
    //     }
    //     if(hashMap[j] != 0){
    //         char x = (char)j;
    //         string s(1,x);
    //         compressedStr.push_back(s);
    //         compressedStr.push_back(to_string(hashMap[j]));
    //     }
    // }
    std::string result;
    for (const auto &piece : compressedStr) result += piece;
    if (result.size() < str.size())
        return result;
    return str;
}

int main(void){
    string s1;
    cout << "Enter string to be compressed" << endl;
    cin >> s1;
    cout << compressString(s1) << endl;
}