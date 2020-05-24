/*
    Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
    column are set to 0.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/*
    Below method uses O(N) space. 
*/
void zeroMatrix(vector<vector<int>>& arr){
    int row = arr.size();
    int col = arr[0].size();  
    set<int> colIndex;
    set<int> rowIndex;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            if(arr[i][j] == 0){
                colIndex.insert(j);
                rowIndex.insert(i);
            }
        }
    }
    for(auto y:colIndex){
        for(int i = 0; i < row;i++){
            arr[i][y] = 0;
        }
    }
    for(auto x:rowIndex){
        for(int i = 0; i < col;i++){
            arr[x][i] = 0;
        }
    }
}
/*
    Below method uses O(1) space. 
*/

void nullifyRow(vector<vector<int>>& arr, int row){
    for(int i = 0; i < arr[0].size();i++){
        arr[row][i] = 0;
    }
}

void nullifyCol(vector<vector<int>>& arr, int col){
    for(int i = 0; i < arr.size();i++){
        arr[i][col] = 0;
    }
}
void zeroMatrixLessSpace(vector<vector<int>>& arr){
    int row = arr.size();
    int col = arr[0].size();
    bool rowsZero = false;
    bool colZero = false;
    for(int i = 0; i < col;i++){
        if(arr[0][i] == 0)
            rowsZero = true;
        if(rowsZero)
            break;
    }
    for(int i = 0; i < row;i++){
        if(arr[i][0] == 0)
            colZero = true;
        if(colZero)
            break;
    }  
    for(int i = 1; i < row;i++){
        for(int j = 1; j < col;j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < col;i++){
        if(arr[0][i] == 0)
            nullifyCol(arr,i);
    }
    for(int i = 1; i < row;i++){
        if(arr[i][0] == 0)
            nullifyRow(arr,i);
    }
    if (rowsZero) {
        nullifyRow(arr, 0);
    }
// Nullify first column
    if (colZero) {
        nullifyCol(arr, 0);
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

    vector<vector<int>> arr = {
        {1,2,4,5,6,7},
        {0,2,4,5,6,7},
        {1,2,4,5,6,0}
    };
    cout<<"<--------------------------------------- Original Matrix --------------------------------------->" << endl;
    printMatrix(arr);

    zeroMatrixLessSpace(arr);

    cout << "<--------------------------------------- Changed Matrix --------------------------------------->" << endl;
    printMatrix(arr);

}