/*
    Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
    bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

    BruteForceRotation - This function is does not perform inplace operation. Instead it copies the elements to array and returns
        new array.

*/

#include <iostream>
#include <vector>

using namespace std;

//Brute Force
/*
    Time complexity O(n^2)
    Space complexity O(n)
*/
vector<vector<int>> bruteForceRotation(vector<vector<int>> arr){
    vector<vector<int>> result;
    vector<int> temp;
    int x = arr[0].size();
    int y = arr.size();
    for(int i = 0;i < y;i++){
        for(int j = x-1;j >= 0;j--){
            temp.push_back(arr[j][i]);
        }
        result.push_back(temp);
        temp.clear();
    }
    return result;
}

vector<vector<int>> generateMatrix(int size){
    int count = 0;
    vector<vector<int>> result;
    vector<int>temp;
    for(int i = 0; i < size;i++){
        for(int j = 0; j < size;j++){
            temp.push_back(count);
            count++;
        }
        result.push_back(temp);
        temp.clear();
    }
    return result;
}

// Better method
bool rotation(vector<vector<int>>& arr){

    if(arr.size() == 0 || arr[0].size() != arr.size())
        return false;
    else{
        int layers = arr.size() - 1;
        int totalNumberOfLevels = arr.size() / 2;
        int level = 0;
        while(level < totalNumberOfLevels){
            int i = 0;
            while(i < layers-level){
                swap(arr[level][level+i],arr[i+level][layers]);
                swap(arr[level][level+i],arr[layers][layers - i]);
                swap(arr[level][level+i],arr[layers - i][level]);
                i++;
            }
            layers--;
            level++;
        }
        return true;
    }
}
void printMatrix(vector<vector<int>>& arr){

    for(int i = 0; i < arr.size();i++){
        for(int j = 0; j < arr[0].size();j++){
            cout << arr[i][j] << "      " ;
        }
        cout << endl;
    }
}
int main(void){
    vector<vector<int>> temp =generateMatrix(6);
    // vector<vector<int>> temp = bruteForceRotation(arr);
    printMatrix(temp);
    cout << endl;
    if (rotation(temp)){
        printMatrix(temp);
    }
    else{
        cout << "Matrix not correct" << endl;
    }
}