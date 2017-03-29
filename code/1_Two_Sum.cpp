/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Show Company Tags
Show Tags
Show Similar Problems 

Solution: 
1. Idea is to put use the undordered_map of all the elements and start looking for a solution. 
2. Another idea is to sort the elements in the vector and use binary search to find the diff of the target. 


The first solutions beats 90.1% of CPP submisstions on March 29th, 2017

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result; 
        int len=nums.size();
        std::unordered_map<int,int> numsMap;
        for(int i=0;i<len;i++){
            numsMap[nums[i]]=i;
        }
        int diff=0;
        int targIdx=0;
        for(int i=0;i<len;i++){
            diff=target-nums[i];
            std::unordered_map<int,int>::const_iterator iter=numsMap.find(diff);// 1. Never use auto if you want to gain performance. 
            if(iter != numsMap.end() && i!= iter->second){
                result.push_back(i);
                result.push_back(iter->second);
                break;
            }
        }
        return result;
        
    }
};

