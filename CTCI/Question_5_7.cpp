#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;

    int even_bits = (n & 0xAAAAAAAA) >> 1;
    int odd_bits = (n & 0x55555555) << 1;
    int ans = even_bits | odd_bits;
    cout << ans << endl;
}