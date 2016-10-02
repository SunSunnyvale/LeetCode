/*
*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
    */

class Solution {
public:
    int findClosestElement(vector<int>& nums, int target,int startIndex,int endIndex){
        int mid=startIndex+(endIndex-startIndex)/2;
        int low=startIndex;
        int high=endIndex;
        while(low < high){
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid] < target){
                low=mid+1;
            }else if(nums[mid] > target){
                high=mid-1;
            }
            mid=startIndex+(endIndex-startIndex)/2;
        }

    }
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end())
        if(size <3){
            for(int ele:nums){
                sum+=ele;
            }
            return sum;
        }

        int closestToTarget=0;
        int current_diff=abs(target-sum);
        int newDiff=0;
        
        for(int i=0,low,high;i<size-2;i++){
           low=i+1;
           high=size;

            
        }
        
        
    }
};