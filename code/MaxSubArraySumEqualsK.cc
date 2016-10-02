/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

*/

// The Idea 
// Calculate sum of each increasing sequence , {1, -1, 5, -2, 3} sums={1,0,5,3,6}
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        int size=nums.size();
        sums.reserve(size);
        int cur_sum = 0;
        int max_len = 0;
        for (int i = 0; i <size ; i++) {
            cur_sum += nums[i];
            if (cur_sum == k) {
                max_len = i + 1;
            } else if (sums.find(cur_sum - k) != sums.end()) {
                max_len = max(max_len, i - sums[cur_sum - k]);
            }
            if (sums.find(cur_sum) == sums.end()) {
                sums[cur_sum] = i;
            }            
        }
        return max_len;
        
    }
};