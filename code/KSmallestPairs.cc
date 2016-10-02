#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct KSmallestPairs{
    int sum;
    pair<int,int> numPairs;

    bool operator()(const KSmallestPairs& lhs, const KSmallestPairs& rhs) const
    {
        if(lhs.sum == rhs.sum){
            if(lhs.numPairs.first >= lhs.numPairs.second){
                if(lhs.numPairs.first >= rhs.numPairs.first && lhs.numPairs.first >= rhs.numPairs.second){
                    return true;
                }
            }else if(lhs.numPairs.second >= rhs.numPairs.first && lhs.numPairs.second >= rhs.numPairs.second){
                return true;
            }
            return false;
        }
        return lhs.sum > rhs.sum ;
    }
    
}KSmallestPairs;

class Solution {
public:
    
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1=nums1.size();
        int len2=nums2.size();
        if(len2==0 || len1==0){
            return vector<pair<int, int> >();
        }
        int i=0,j=0;
        int nextSumJ=0,nextSumI=0,count=0;
        vector<pair<int, int> > result;
        result.reserve(k);
        int minElements=2*k+1;
        while(i<len1 && j<len2 && count<minElements){
            while(nums1[i] <= nums2[j] && count<minElements && i<len1){
                i++;
                count++;
            }

            while(nums1[i] >= nums2[j] && count<minElements&& j<len2){
                j++;
                count++;
            }
        }
        int diff=minElements -count;
        if(diff > 0){
            if(i<len1 && j==len2){
                i= ((i+ diff) >len1) ? len1: i+diff;
            }else{
                j= ((j+ diff) >len1) ? len1: j+diff;
            }
            
        }
        int maxLen1=i;
        int maxLen2=j;
        //cout<<"\n maxLen1::"<<maxLen1<<" maxLen2::"<<maxLen2<<" count::"<<count;
        count=0;
        i=0;
        j=0;

        std::priority_queue<KSmallestPairs, std::vector<KSmallestPairs>, KSmallestPairs > numPairs;
        //numPairs.reserve(k);
        for(;i<maxLen1 && count < minElements;i++){
            for(j=0;j<maxLen2 && count < minElements ;j++){
                //cout<<"\nPairs:"<<nums1[i]<<","<<nums2[j];
                pair<int,int> temp=make_pair(nums1[i],nums2[j]);
                KSmallestPairs obj;
                obj.sum=nums1[i]+nums2[j];
                obj.numPairs=temp;
                numPairs.push(obj);
                count++;
            }
        }
        for(int i=0;i<k && !numPairs.empty();i++){
            result.push_back(numPairs.top().numPairs);
            numPairs.pop();
        }
        return result;
        
    }
};

int main(){
    Solution sol;
    int size=0;
   // cout<<"\na..3.."<<sol.rearrangeString("a",0)<<"\n";

}