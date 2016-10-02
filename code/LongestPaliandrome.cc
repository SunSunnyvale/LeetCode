#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


typedef struct PalData{
    int minPos;
    int maxPos;
    int size;
}PalData;
class Solution {
public:
    string longestPalindrome(string s) {
        string hashedString;
        hashedString.reserve(s.length() * 2+1);
        hashedString.clear();
        for(const char& c:s){
            hashedString+="#";
            hashedString+=c;
        }
        hashedString+="#";
        //cout<<"\nhashedString.."<<hashedString;

        PalData palData;
        palData.minPos=0;
        palData.maxPos=0;
        palData.size=0;
        int length=hashedString.length();
        int leftPtr=0;
        int rightPtr=0;
        int distance=0;

        int leftPtr_=0;
        int rightPtr_=0;
        int distance_=0;

        int mid=length/2;
        int isEven=length%2;
        int potentialLength=0;
        for(int i=mid,j=(isEven)?mid-1:mid;i<length && j>=0;i++,j--){
            //cout<<"\nMain...."<<hashedString[i];
            potentialLength=(length-i)*2;
            // cout<<"\npotentialLength.."<<potentialLength;
            if(potentialLength<palData.size){
                break;
            }
            
            distance=0;
            leftPtr=i-1;
            rightPtr=i+1;
            // cout<<"\n1..i::"<<i<<" leftPtr::"<<leftPtr<<" rightPtr"<<rightPtr<<" distance"<<distance<<
            // " palData.minPos::"<<palData.minPos<<" maxPos"<<palData.maxPos<<" palData.size"<<palData.size;
            while(hashedString[leftPtr]==hashedString[rightPtr] && leftPtr>=0 && rightPtr<length){
                // cout<<"\n 2..hashedString...leftPtr"<<hashedString[leftPtr]<<" rightPtr"<<hashedString[rightPtr];
                leftPtr--;
                rightPtr++;
            }
            leftPtr++;
            rightPtr--;
            distance=rightPtr-leftPtr+1;
            if(palData.size < distance){
                palData.minPos=leftPtr;
                palData.maxPos=rightPtr;
                palData.size=distance;
            }

            if(i!=j){
                distance_=0;
                leftPtr_=j-1;
                rightPtr_=j+1;
                // cout<<"\n1..i::"<<i<<" leftPtr::"<<leftPtr<<" rightPtr"<<rightPtr<<" distance"<<distance<<
                // " palData.minPos::"<<palData.minPos<<" maxPos"<<palData.maxPos<<" palData.size"<<palData.size;
                while(hashedString[leftPtr_]==hashedString[rightPtr_] && leftPtr_>=0 && rightPtr_<length){
                    // cout<<"\n 2..hashedString...leftPtr"<<hashedString[leftPtr]<<" rightPtr"<<hashedString[rightPtr];
                    leftPtr_--;
                    rightPtr_++;
                }
                leftPtr_++;
                rightPtr_--;
                distance_=rightPtr_-leftPtr_+1;
            }

            if(palData.size < distance || palData.size < distance_){
                if(distance>distance_){
                    palData.minPos=leftPtr;
                    palData.maxPos=rightPtr;
                    palData.size=distance;
                }else{
                     palData.minPos=leftPtr_;
                    palData.maxPos=rightPtr_;
                    palData.size=distance_;

                }
            }

            // cout<<"\n2..i::"<<i<<" leftPtr::"<<leftPtr<<" rightPtr"<<rightPtr<<" distance"<<distance<<
            // " palData.minPos::"<<palData.minPos<<" maxPos"<<palData.maxPos<<" palData.size"<<palData.size<<"\n";
            
        }
        string result="";
        result.reserve(palData.size);
        for(int i=palData.minPos;i< palData.maxPos;i++){
            if(hashedString[i]=='#')
                continue;
            result+=hashedString[i];
        }
        
        return result;
    }
};

int main(){

    Solution sol;
    int size=0;
    
    
    cout<<"\naba::"<<sol.longestPalindrome("aba");
    cout<<"\nab::"<<sol.longestPalindrome("ab");

    cout<<"\naa::"<<sol.longestPalindrome("aa");

    cout<<"\nababa::"<<sol.longestPalindrome("ababa");
    cout<<"\nbabcbabcbaccba::"<<sol.longestPalindrome("nbabcbabcbaccba");

}   