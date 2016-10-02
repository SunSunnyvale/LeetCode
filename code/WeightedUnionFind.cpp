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
    }
};

int main(){
    Solution sol;
}
