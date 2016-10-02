#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
// #include <boost/algorithm/string>

using namespace std;

class Solution {


public:
			// trim from start (in place)
	static inline void ltrim(std::string &s) {
	    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
	            std::not1(std::ptr_fun<int, int>(std::isspace))));
	}

	// trim from end (in place)
	static inline void rtrim(std::string &s) {
	    s.erase(std::find_if(s.rbegin(), s.rend(),
	            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(std::string &s) {
	    ltrim(s);
	    rtrim(s);
	}
	void reverseString(string &s, int startPos, int endPos){

		if(endPos-startPos <=1){
			return;
		}

		char temp;
		int mid=startPos+ (endPos-startPos)/2;
		for(int i=startPos;i<mid;i++){
			temp=s[i];
			s[i]=s[startPos+endPos-i-1];
			s[startPos+endPos-i-1]=temp;

		}
		//cout<<"\n word::"<< s;
	}
	void doubleRevese(string &s){
		trim(s);
    	if(s.length() <=1)
    		return;
    	reverseString(s,0,s.length());
    	int startPos=0;
    	int endPos=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==' '){
    			//cout<<"\n startPos::"<<startPos<<" i::"<<i;
    			reverseString(s,startPos,i);
    			startPos=i+1;
    		}
    	}
    	reverseString(s,startPos,s.length());

	}


    void reverseWords(string &s) {
    	ltrim(s);
	    rtrim(s);
    	std::stack<string> words;
    	int startPos=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==' '){
    			words.push(s.substr(startPos,i-startPos));
    			while(s[i]==' ' && i<s.length()){
    				i++;
    			}
    			startPos=i;
    		}
    	}
    	string temp=s.substr(startPos,s.length()-startPos);
    	words.push(temp);
    	s.clear();
    	while(!words.empty()){
    		s+=words.top();
    		words.pop();
    		if(!words.empty()){
				s+=' ';
    		}
    		
    	}
		return;
    }
};


int main(){
    Solution sol;
    int size=0;
    string str="hello my name is sunil";
    sol.reverseWords(str);
    cout<<"\n str::"<<str;

    string str1="hello";
    sol.reverseWords(str1);
    cout<<"\n str::"<<str1;

    string str2=" ";
    sol.reverseWords(str2);
    cout<<"\n str::"<<str2 <<",";

    string str3="  a      b    ";
    sol.reverseWords(str3);
    cout<<"\n str::"<<str3 <<",";
   // cout<<"\na..3.."<<sol.rearrangeString("a",0)<<"\n";

}