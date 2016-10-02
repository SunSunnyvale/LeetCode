#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size()-1,m=0;
        while(l <= r)
        {
             m = l+((r-l)>>1);
            if(nums[m] == target) return m;
            if(nums[m] < nums[r])
            {
                if(nums[m]<target && target<=nums[r]) l = m+1;
                else r = m-1;
            }
            else if(nums[m] > nums[r])
            {
                if(nums[l]<=target && target<nums[m]) r = m-1;
                else l = m+1;
            }
            else r--;
        }
        return -1;
    }
    
};

int main() {
  Solution obj;
  
  vector<int> testSet;
  testSet.push_back(1);
  testSet.push_back(2);
  testSet.push_back(11);
  testSet.push_back(-3);
  testSet.push_back(-2);
  testSet.push_back(1);
  
  int position=obj.search(testSet,1);

  cout<<"\nresult :::"<<position;

  return 0;
}