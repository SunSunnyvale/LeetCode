/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.


*/
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;
class Solution {
public:
	int combinationSum(vector<int>& nums, vector<int>& arr,int target) {
		if(nums.empty() || target<0) return 0;
		if(target == 0) return 1;
        if(arr[target] != -1) return arr[target];
        long count = 0;
        for(int i = 0; i < nums.size(); ++i)
            count += combinationSum(nums, arr,target-nums[i]);
        return arr[target] = count;
	}
    int combinationSum4(vector<int>& nums, int target) {
    	std::vector<int> v(target+1,-1);
    	return combinationSum(nums,v,target);
    }
};

int main(){
    Solution sol;
    int size=0;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int val= sol.combinationSum4(v,4);
    cout<<"\nResult...."<<val;

   
}