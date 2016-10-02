#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length=nums.size();
        int low=0;
        int max=length-1;

        cout<<"\nLength.."<<length;
        if(length ==0){
            return 0;
        }
        if(nums[0]>= target){
            return 0;
        }
        
        if(nums[length-1] == target){
            return length-1;
        }
        if(nums[length-1] < target){
            return length;
        }
        
        int mid=(low+max)/2;
        cout<<"\n mid.."<<mid;
        while( mid >= low && mid <= max){
            cout<<"\n Mid...."<<mid<<"Value..."<<nums[mid];
            if(nums[mid]==target){
                return mid;
            }
            
            if(mid-1 >= 0){
                if (nums[mid-1] < target && nums[mid]  > target){
                    return mid;
                }else if(mid+1 <length){
                    if (nums[mid] < target && nums[mid+1]  >= target)
                        return mid+1;
                }
            }else if(mid+1 <length){
                if (nums[mid] < target && nums[mid+1]  >= target)
                    return mid+1;
            }
            if(nums[mid]> target){
                low=low;
                max=mid-1;
            }else{
                low=mid+1;
                max=max;
            }
            mid= (max+low)/2;
        }
        return mid;
    }
};

int main() {
  Solution obj;
  vector<int> testSet;
  int count=-5000;
  for(int i=0;i<10000;i++){
    testSet.push_back(count+i);
  }

  // vector<int> testSet;
  // testSet.push_back(-3);
  // testSet.push_back(-2);
  // testSet.push_back(-1);
  // testSet.push_back(1);
  // testSet.push_back(2);
  // testSet.push_back(11);

  int position=obj.searchInsert(testSet,1309);

  cout<<"\nresult :::"<<position;

  return 0;
}