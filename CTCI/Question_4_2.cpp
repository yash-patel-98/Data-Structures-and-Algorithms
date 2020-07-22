/*
                  56
                /   \
               /     \
             43      78
            /  \     / \
           35  51   71  82
                         \
                          88
*/
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int v;
        Node* left;
        Node* right;
};

class LL{
    public:
        int v;
        LL* next;
};

Node* newNode(int data);

Node* minimalBST(vector<int> arr, int s, int e){
    if(e < s)
        return NULL;
    int mid = (s+e)/2;
    Node* node = newNode(arr[mid]);
    node->left = minimalBST(arr,s,mid-1);
    node->right = minimalBST(arr,mid+1,e);
    return node;
}

Node* newNode(int data){
    Node* n = new Node();
    n->v = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}

Node* createBST(vector<int> arr, int s, int e){
    return minimalBST(arr,s,e);
}


void preorder(Node* root){
    if (root != NULL){
        cout << root->v << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->v << " ";
    }
}

// Question 4_3
// List of Depths
/*          List of Depths          */
void listOfDepts(Node* root,vector<vector<int>>& list, int height){
    if (root != NULL){
        vector<int> temp;
        if(height == list.size()){
            temp.push_back(root->v);
            list.push_back(temp);
        }else{
            list[height].push_back(root->v);
        }
        listOfDepts(root->left,list,height+1);
        listOfDepts(root->right,list,height+1);
    }
}
/*          List of Depths          */


/*          Check Balanced          */

void getSubtreeHeight(Node* n, int& h, int& m){
    if(n != NULL){
        ++h;
        if(m < h)
            m = h;
        getSubtreeHeight(n->left,h,m);
        getSubtreeHeight(n->right,h,m);

    }
}

bool checkIfBalanced(Node* root){
    int left = 0;
    int maxLeft = 0;
    int maxRight = 0;
    int right = 0;
    getSubtreeHeight(root->left,left, maxLeft);
    getSubtreeHeight(root->right,right, maxRight);

    cout << "Left height : " << maxLeft << endl;
    cout << "Right height : " << maxRight << endl;
    if(abs(maxLeft - maxRight) < 2)
        return true;
    return false;
}
/*          Check Balanced          */

/*          Check if BST            */

bool checkProperty(Node* root, int minVal, int maxVal){

    if(root == NULL)
        return true;
    if((root->v <= minVal && minVal != INT64_MIN) || (root->v > maxVal && maxVal != INT64_MAX))
        return false;
    if((!checkProperty(root->left,minVal,root->v) || (!checkProperty(root->right,root->v,maxVal))))
        return false;
    return true;
}

bool checkIfBST(Node* root){
    return checkProperty(root, INT64_MIN, INT64_MAX);
}

/*          Check if BST            */

int main(){

    vector<int> arr = {35,43,51,56,71,78,82,88};
    Node* root = createBST(arr, 0,arr.size() - 1);
    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;
    vector<vector<int>> list;
    listOfDepts(root, list , 0);
    for(int i = 0; i < list.size();i++){
        cout << "Height: " << i << " -----> ";
        for(int x = 0; x < list[i].size();x++){
            cout << list[i][x] << " ";
        }
        cout << endl;
    }
    if(checkIfBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;
}