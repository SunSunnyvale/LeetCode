#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        uint16_t s_len=s.length();
        uint16_t t_len=t.length();
        //
        //cout<<"\n Slen"<<s_len<<" t_len "<<t_len;
        
        if(s_len < t_len){
            return isOneEditDistance(t,s);
        }
        
        if(s_len-t_len > 1 || (s_len==0 && t_len==0)){
            
            //cout<<"\n1..";
            return false;
        }
        uint16_t distance=0;
        int ldiff=0;
        int i=0 ;
        for(;i+ldiff< s_len ;i++){
            //cout<<"\n distance::"<<distance<<" s_len::"<<s_len<<" i::"<<i<<" ldiff.."<< ldiff<<" t_len::"<<t_len<<"\n";
            if(t_len <= i){
                distance++;
                if(distance >1){
                    //cout<<"\n2..";
                    return false;
                }
                continue;
            }
            if(s[i+ldiff]!=t[i]){
                distance++;
                if(s_len!=t_len){
                    ldiff++;
                    if(s[i+ldiff]!=t[i]){
                        //cout<<"\n2-1..";
                        return false;
                    }
                }
            }
        }
        //cout<<"\n distance::"<<distance<<" s_len::"<<s_len<<" i::"<<i<<" ldiff.."<< ldiff<<"\n";
        distance+=s_len-i-ldiff;
        if ( distance==1 ){
            //cout<<"\n3..hello";
            return true;
        }
        
        //cout<<"\n4..hello11111";
        return false;
    }
        
        
    
};

int main(){
    Solution sol;
    int size=0;
    assert(sol.isOneEditDistance("a","ac")==true);
    assert(sol.isOneEditDistance("ab","ac")==true);
    assert(sol.isOneEditDistance("ca","ac")==false);
    assert(sol.isOneEditDistance("abc","ac")==true);
    assert(sol.isOneEditDistance("abc","bc")==true);
    assert(sol.isOneEditDistance("aaa","aaa")==false);
    assert(sol.isOneEditDistance("ab","acd")==false);
    assert(sol.isOneEditDistance("a","ca")==true);
   
}   