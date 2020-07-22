#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int longestSequence(string num){
    vector<int> zeroLocations;
    zeroLocations.push_back(0);
    int count = 0;
    for(int i = num.size() - 1;i >= 0; i--){
        if(num.at(i) != '1'){
            zeroLocations.push_back(count);
        }
        count++;
    }
    for(int i = 0; i < zeroLocations.size();i++)
        cout << zeroLocations[i] << " ";
    cout << endl;
    int maxSize = -1;
    for(int i = 1; i < zeroLocations.size() - 1;i++){
        int temp = zeroLocations[i+1] - zeroLocations[i-1];
        if (temp > maxSize)
            maxSize = temp;
    }
    return maxSize;
}

int main(void){
    int num;
    cin >> num;
    bitset<32> numBitset(num);
    int seq = longestSequence(numBitset.to_string());
    cout << "Max length = " << seq << endl;
}