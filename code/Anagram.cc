#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int size=strs.size();
        vector<vector<string> > op;
        if(size==0){
            return op;
        }
        
        int opCounter=0;
        int indexToStart=0;
        vector<uint8_t> charCounter(26,0);
        
        unordered_map<string,vector<string> >resultMap;
        string hashCode="";
        hashCode.reserve(26);
        for(int i=0;i<size;i++){
            hashCode="";
            const string& str=strs[i];
            for(int j=0;j<26;j++){
                charCounter[j]=0;
            }
            for(const char& c:str){
                charCounter[c-'a']++;
            }
            //hashCode=to_string(charCounter);
            for(int j=0;j<26;j++){
                hashCode.append(to_string(charCounter[j]));
            }
            cout<<"\nHashCode::"<<hashCode<<" string::"<<str;
            if(resultMap.find(hashCode) != resultMap.end()){
                vector<string>& anagramList=resultMap[hashCode];
                anagramList.push_back(str);
            }else{
                vector<string> anagramList;
                anagramList.push_back(str);
                resultMap[hashCode]=anagramList;
            }
        }
        
        for(auto anagramList:resultMap){
            op.push_back(anagramList.second);
        }
        
        return op;
        
    }
};