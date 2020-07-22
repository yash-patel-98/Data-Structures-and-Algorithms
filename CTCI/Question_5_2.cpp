#include <iostream>

using namespace std;

string toBinaryString(double num){
    int bits = 31;
    string ans = "";
    while(bits--){
        num = num * 2;
        if(num == 1.0){
            ans.append("1");
            break;
        }
        else{
            if (num > 1){
                ans.append("1");
                num -= 1;
            }
            else{
                ans.append("0");
            }
        }
    }
    if(num == 1.0)
        return ans;
    else
        return "";
}

int main(void){
    double number;
    cout << "Enter number: " << endl;
    cin >> number ;

    string binary = toBinaryString(number);
    if(binary.empty())
        cout << "Cannot represent number in 32 bits\n";
    else{
        cout << "32 bit Binary Representation is - \n";
        cout << binary << endl;
    }
}