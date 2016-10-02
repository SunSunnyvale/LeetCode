#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int firstSize=nums1.size();
        int secondSize=nums2.size();
        
        if(firstSize < secondSize){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int nums1Start=0,nums1End=firstSize,nums2Start=0,nums2End=secondSize;
        int nums1Mid=0,nums2Mid=0;
        bool isOdd=(firstSize+secondSize)%2;
        double median=0.0;
        
        while(true){
        	
        	nums1Mid=nums1Start+(nums1End-nums1Start)/2;
        	nums2Mid=nums2Start+(nums2End-nums2Start)/2;

        	cout<<"\n nums1Start::"<<nums1Start<<" nums1End::"<<nums1End<<" nums1Mid::"<<nums1Mid<<"..........nums2Start::"<<nums2Start<<" nums2End::"<<nums2End
        	<<" nums2Mid::"<<nums2Mid <<" nums1[nums1Mid]::"<<nums1[nums1Mid]<<" nums2[nums2Mid]::"<<nums2[nums2Mid];

        	if(nums2[nums2Mid]==nums1[nums1Mid]){
        		return nums1[nums1Mid];
        	}else if(nums2[nums2Mid]<=nums1[nums1Mid] && nums2[nums2Mid+1]>=nums1[nums1Mid]){
            	if(isOdd){
                	return nums1[nums1Mid];
            	}else{
            		return (nums1[nums1Mid] + max(nums2[nums2Mid+1],nums1[nums1Mid+1]))/2;
            	}
            }else if(nums1[nums1Mid]<=nums2[nums2Mid] && nums1[nums1Mid+1]>=nums2[nums2Mid]){
            	if(isOdd){
                	return nums2[nums2Mid];
            	}else{
            		return (nums2[nums2Mid] + max(nums1[nums1Mid+1],nums2[nums2Mid+1]))/2;
            	}
            }
            //1,4,3     2,6
            if(nums2[nums2Mid] > nums1[nums1Mid] ){
            	cout<<"\n 1...";
            	nums1End=nums1Mid-1;
            	nums2Start=nums1Mid+1;

            }else if(nums2[nums2Mid] < nums1[nums1Mid] ){
            	cout<<"\n 2...";
            	nums2End=nums2Mid-1;
            	nums1Start=nums2Mid+1;

            }
            //cout<<"\n nums1Start::"<<nums1Start<<" nums1End::"<<nums1End<<" nums1Mid::"<<nums1Mid<<"..........nums2Start::"<<nums2Start<<" nums2End::"<<nums2End
        	//<<" nums2Mid::"<<nums2Mid;
        }
        return -1;
        
    }
};

int main(){
    Solution sol;
    int size=0;
    

    vector<int> testSet;
	testSet.push_back(1);
	testSet.push_back(2);
	testSet.push_back(11);
	testSet.push_back(13);

	vector<int> testSet1;
	testSet1.push_back(4);
	testSet1.push_back(6);
	// testSet1.push_back(6);

	cout<<"\n Median...."<<sol.findMedianSortedArrays(testSet,testSet1);
}   