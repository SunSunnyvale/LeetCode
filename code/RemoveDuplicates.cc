#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertPos=0;
        int length=0;
        int maxDuplicates=2;
        int dupCounter=0;
        int size=nums.size();
        if(size==1)
            return 1;
        for(int i=1;i<size;i++){
            if(nums[i]==nums[insertPos]){
                nums[insertPos+1]=nums[insertPos];
                insertPos++;
                i++;
                while(i < size && nums[i]==nums[insertPos]){
                    i++;
                }
                
                if(i<size){
                    insertPos+=1;
                    nums[insertPos]=nums[i];
                }
                
            }else{
                nums[insertPos]=nums[i];
                insertPos++;
            }
        }
        
        return insertPos+1;
        
    }
};

void printVec(vector<int>& nums, int size){
    for(int i=0;i<size;i++){
        cout<<" "<<nums[i];
    }
}

int main(){
        Solution sol;
        int size=0;
        vector<int> sample1;
        sample1.push_back(1);
        sample1.push_back(1);
        printVec(sample1,sample1.size());
        size=sol.removeDuplicates(sample1);
        cout<<"\nSize.."<<size;
        cout<<"\nSample1::";printVec(sample1,size);

        vector<int> sample2;
        sample2.push_back(1);

        printVec(sample2,sample2.size());
        size=sol.removeDuplicates(sample2);
        cout<<"\nSize.."<<size;
        cout<<"\nSample2::";printVec(sample2,size);

        vector<int> sample3;
        sample3.push_back(1);
        sample3.push_back(1);
        sample3.push_back(1);
        sample3.push_back(2);
        sample3.push_back(2);
        sample3.push_back(3);
        printVec(sample3,sample3.size());
        size=sol.removeDuplicates(sample3);
        cout<<"\nSize.."<<size;
        cout<<"\nSample3::";printVec(sample3,size);

        vector<int> sample4;
        sample4.push_back(1);
        sample4.push_back(1);
        sample4.push_back(1);
        sample4.push_back(1);
        sample4.push_back(1);
        sample4.push_back(1);
        printVec(sample4,sample4.size());
        size=sol.removeDuplicates(sample4);
        cout<<"\nSize.."<<size;
        cout<<"\nSample4::";printVec(sample4,size);

        return 0;

    }