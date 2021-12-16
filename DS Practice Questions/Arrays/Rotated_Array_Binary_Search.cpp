#include<iostream>
#include<vector>

using namespace std;

int search(vector<int> nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while(low <= high){
        mid = (low+high) / 2;
        if(nums[mid] == target)
            return mid;  
        else if(nums[mid] < target){
            if(nums[low] > nums[mid] && nums[high] < target){
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        else{
            if(nums[mid] > nums[high] && nums[low] > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return - 1;
}
/*
Correct Answer
int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high){
            mid = (int)(high+low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target){
                if(nums[low] > nums[mid] && nums[high] < target){
                    high = mid - 1;
                }
                else
                    low = mid+1;
            }
            else{
                if(nums[mid] > nums[high] && nums[low] > target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
*/
int main(void){

    cout << search({4,5,6,7,0,1,2} , 0) << endl;

}