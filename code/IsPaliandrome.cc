#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    
public:
    bool isValidChar(const char& c){
        if ((c >='a' && c<='z') || (c >='A' && c<='Z') || (c >='0' && c<='9')  ){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int size=s.length();
        if(size<=1){
            return true;
        }
        size=size-1;
        int i=0,leftDiff=0,rightDiff=0;
        int left=size-i-rightDiff,right=i+leftDiff;
        //cout<< "\n op::"<<(size-i-rightDiff+1) << " "<<(i+leftDiff );
        while( left+1 > right ){
            //cout<<"\n Comparing::"<<s[size-i-rightDiff]<<" "<<s[i+leftDiff ]<<" i::"<<i<<" leftDiff"<<leftDiff<<" rightDiff"<<rightDiff;
            while(!isValidChar(s[left]) && (left > right) ){
                rightDiff++;
                left=size-i-rightDiff;
            }
            while(!isValidChar(s[right]) && (left > right) ){
                leftDiff++;
                right=i+leftDiff;
            }
            // cout<<"\n Comparing::"<<s[size-i-rightDiff]<<" "<<s[size-i-rightDiff]<<" i::"<<i<<" leftDiff"<<leftDiff<<" rightDiff"<<rightDiff;
            
            if(s[left]!=s[right] ){
                 if(! (toupper(s[left])==toupper(s[right]) )) {
                    // cout<<"\n Comparing::"<<toupper(s[size-i-rightDiff])<<" "<<toupper(s[i+leftDiff]);
                    return false;
                 }
            }
            i++;
            left=size-i-rightDiff;
            right=i+leftDiff;
        }
        return true;
    }
};

int main(){

    Solution sol;
    int size=0;
    cout<<"\nA man, a plan, a canal: Panama::"<<sol.isPalindrome("A man, a plan, a canal: Panama");
   

}   