/*
Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.

*/
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
	typedef struct CountSort{
		bool operator()(const pair<char,int>& left,const pair<char,int>& right){
			return left.second < right.second;
		}
	}CountSort;

public:
	string rearrangeString(string str, int k) {
		int strLen=str.length();
		if(strLen==0 ){
			return "";
		}
		if(k==0){
			return str;
		}

		unordered_map<char,int> charCountMap;
		int maxCount=0;
		for(const char& ele:str){
			charCountMap[ele]++;
			if(charCountMap[ele] > maxCount){
				maxCount=charCountMap[ele];
			}
			cout<<"\n"<<ele<<" "<<charCountMap[ele];
		}

		std::priority_queue<pair<char,int>, std::vector<pair<char,int> >, CountSort > charCount;
		for ( auto it = charCountMap.begin(); it != charCountMap.end(); ++it ){
			charCount.push(make_pair(it->first,it->second));
			cout<<"\n2.."<<it->first<<" "<<it->second;
		}
		int maxBucketSize=strLen/maxCount;

		if(maxBucketSize < k){
			return "";
		}

		std::vector<string> buckets(maxBucketSize,"");
		string result="";
		result.reserve(strLen);
		int count=0;
		vector<pair<char,int> > temp;
		temp.reserve(k);
		while(!charCount.empty()){
			for(int i=0;i<k;i++){
				auto& charMapIterator=const_cast<pair<char,int>& >(charCount.top());
				cout<<"\nfirst::"<<charMapIterator.first<<" second::"<<charMapIterator.second;
				charMapIterator.second--;
				buckets[count]+=charMapIterator.first;
				temp.push_back(charMapIterator);
				charCount.pop();
				cout<<"\ncount.."<<count<<".."<<buckets[count];
			}
			for(int i=k-1;i>=0;i--){
				if(temp[i].second!=0){
					cout<<"\nPush...char.."<<temp[i].first<<".."<<temp[i].second;
					charCount.push(temp[i]);
				}
			}

			cout<<"\ncount.."<<count<<"..buckets[count]::"<<buckets[count];
			count++;
		}
		cout<<"\n";
		for(int i=0;i<buckets.size();i++){
			result+=buckets[i];
			cout<<"\nResult.."<<result<<" bucket::"<<buckets[i];
		}
		return result;

	}
};

int main(){
    Solution sol;
    int size=0;
    //sol.rearrangeString("aabbcc",2);
    // sol.rearrangeString("aaadbbcc",2);
    sol.rearrangeString("aa",1);
    // sol.rearrangeString("a",0);

}