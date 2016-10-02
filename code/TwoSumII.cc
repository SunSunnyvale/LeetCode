class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1=0;
        int length=numbers.size();
        int index2=length-1;
        int sum=0;
        vector<int> indices(2,-1);
        while(index1<index2){
            sum=numbers[index1]+numbers[index2];
            if(sum ==target){
                indices[0]=index1+1;
                indices[1]=index2+1;
                break;
            }
            if(sum < target){
                index1++;
            }else{
                index2--;
            }
        }
        return indices;
        
        
    }
};