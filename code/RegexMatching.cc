#include <iostream>

using namespace std;

/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") == false
isMatch("aa","aa") == true
isMatch("aaa","aa") == false
isMatch("aa", "a*") == true
isMatch("aa", ".*") == true
isMatch("ab", ".*") == true
isMatch("aab", "c*a*b") == true
*/

class Solution {
private:

public:

	bool isMatch(string& s1, string& p1) {
		char *s = s1.c_str();
		char *p = p1.c_str();
    	
        if (!p[0]){  
            return !s[0];  
        }
  
        int slen = s.length(), plen = p.length();  
        if (plen == 1 || p[1] != '*') { 
            return slen && (p[0] == '.' || s[0] == p[0])  
                && isMatch(s.substring(1), p+1);  
        }
        while (s[0] && (p[0] == '.' || s[0] == p[0])){  
            if (isMatch(s++, p + 2)){  
                return true;  
            }
        }
        return isMatch(s, p + 2);  
    }     
};


int main(){
	Solution sol;
	if(sol.isMatch("aa","a")!=false){
		cout<<"aa, a didn't pass";
	}
	if(sol.isMatch("aa","aa") !=true){
		cout<<"aa, aa didn't pass";
	}
	if(sol.isMatch("aaa","aa") != false){
		cout<<"aaa, aa didn't pass";
	}
	if(sol.isMatch("aa", "a*") != true){
		cout<<"aa, a* didn't pass";
	}
	if(sol.isMatch("aa", ".*") != true){
		cout<<"aa, .* didn't pass";
	}
	if(sol.isMatch("ab", ".*") != true){
		cout<<"ab, .* didn't pass";
	}
	if(sol.isMatch("aab", "c*a*b") != true){
		cout<<"aa, a didn't pass";
	}

}