#include<bits/stdc++.h>

using namespace std;

void go(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
}

string solve(string a, string b){
    string small = a.size() < b.size() ? a : b;
    string big = a.size() <  b.size() ? b : a;
    string ans = big;
    int n = small.size() - 1;
    int m = big.size() - 1;
    int carry = 0;
    int temp;
    for(int i = n; i >= 0; i--){
        temp = (small.at(i) - '0') + (big.at(m) - '0') + carry;
        if(temp > 9){
             temp -= 10;
             carry = 1;
        }else{
            carry = 0;
        }
        ans[m] = temp + '0';
        m--;
    }
    while(m >= 0){
        temp = carry + (big.at(m) - '0');
//        cout << "m = " << m << "temp = " << temp << endl;
        if(temp > 9){
            temp -= 10;
            carry = 1;
        }else{
            carry = 0;
        }
        ans[m] = temp + '0';
        m--;
    }
    if(m < 0 && carry)
        ans.insert(0,"1");
    return ans;
}

int main(void){
    go();
    string a, b;
    cin >> a >> b;
    cout << solve(a,b) << endl;
}
