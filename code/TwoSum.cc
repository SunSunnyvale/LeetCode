#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Subscribe to see which companies asked this question


*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sumVals;
        int size=nums.size();
        int max=size-1;
        int min=0;
        unordered_map<int,int> sumMap;
        
        std::unordered_map<int,int>::iterator it;
        int diff=0;
        for(int i=0;i<size;i++){
            diff=target-nums[i];
            it=sumMap.find(nums[i]);
            if(it != sumMap.end()){
                min=it->second;
                max=i;
                break;
            }else{
                sumMap[diff]=i;
            }
        }
        
        sumVals.push_back(min);
        sumVals.push_back(max);
        return sumVals;
    }
};

int main() {
  Solution obj;
  vector<int> testSet;
  testSet.push_back(3);
  testSet.push_back(2);
  testSet.push_back(4);

  //obj.sortByColor("abccbba");
  vector<int> result=obj.twoSum(testSet,6);

  cout<<"\nresult :::"<<result[0] <<"..."<<result[1];

  // obj.sortByColor("ccccbbbaaaa");
  // obj.sortByColor("aabcbbaa");
  // obj.sortByColor("cccbbb");
  ///obj.sortByColor("ccccccc");
  //obj.sortByColor("aaaaaaa");
  return 0;
}