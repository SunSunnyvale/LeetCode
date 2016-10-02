/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int size=nums.size();
        if(size==0){
            return ranges;
        }
        ranges.reserve(size);
        int num=0;
        string range="";
        int start=0;
        int end=0;
        range.reserve(6);
        for(int i=0;i<size;i++){
            num=nums[i];
            if(range.empty()){
                range.append(to_string(num));
                start=i;
                continue;
            }
            if(num != nums[i-1]+1 ){
                end=i;
                if(end-start >1){
                    range.append("->");
                    range.append(to_string(nums[i-1]));
                    ranges.push_back(range);
                }else{
                   ranges.push_back(range); 
                }
                range="";
                range.append(to_string(num));
                start=i;
                continue;
            }
            if(i+1==size){
                end=i;
                if(end-start >=1){
                    range.append("->");
                    range.append(to_string(nums[i]));
                    ranges.push_back(range);
                }else{
                   ranges.push_back(range); 
                }
                range="";
            }
        }
        if(!range.empty()){
            ranges.push_back(range);
        }
        return ranges;
        
    }
};