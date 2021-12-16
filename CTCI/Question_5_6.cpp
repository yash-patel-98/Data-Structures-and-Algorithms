#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int a,b;
    cin >> a;
    cin >> b;
    int count = 0;
    for(int c = a ^ b; c != 0; c >> 1){
        count += c & 1;
    }
    cout << count;
}