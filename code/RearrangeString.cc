#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct LL{
	int count;
	char c;

	bool operator()(const LL& lhs, const LL& rhs) const
	{
	    return lhs.count <= rhs.count;
	}


}LL;

class Solution {
public:
	string rearrangeString(string str, int k) {
		////
		cout<<"\n str..."<<str;
        const uint16_t length=str.length();
        //
        cout <<"\nlength::"<<length;
        if(k >length){
        	return str;
        }
        if((length==1 && k<=1) || k==0){
        	return str;
        }
        //
        cout <<"\nlength::"<<length;
        
        unordered_map<char,int> charStackCount;
        char a[k];
        int currentStart=0;
        int currentEnd=0;
        int count=0;
        int maxCountPerChar=length/k;
        //
        cout <<"\nlength::"<<length;
        for(auto const &c:str){
        	if(charStackCount.find(c) !=charStackCount.end()){
        		count=charStackCount[c];
        		count++;
        		charStackCount[c]=count;
        	}else{
        		charStackCount[c]=1;	
        	}
        }
        std::priority_queue<LL, std::vector<LL>, LL > charCountQueue;

        for(auto iter=charStackCount.begin();iter!=charStackCount.end();iter++){
        	LL ele;
        	ele.count=iter->second;
        	ele.c=iter->first;
        	charCountQueue.push(ele);
        }
        cout <<"\nlength::"<<length;
		char result[length+1];
        char priorArr[length+1];
        for(int i=0;i<length;i++){
        	result[i]='1';
        	priorArr[i]='1';
        }
        result[length]='\0';
        cout<<"\n1..result.."<<result<<" length"<<length;
        int startPos=0;
        while(!charCountQueue.empty()) {
	        const LL& temp=charCountQueue.top();
	        cout<<"\ntemp..."<<temp.c<<" count.."<<temp.count;
	        int count=temp.count;
	        int charCount=1;
	        priorArr[charCount-1]=temp.c;
	        cout<<"\n charCount "<<charCount<<" ... priorArr::"<<priorArr<<" temp.c::"<<temp.c;
	        charCountQueue.pop();
	        while(!charCountQueue.empty() && count==charCountQueue.top().count){
	        	charCount++;
	        	priorArr[charCount-1]=charCountQueue.top().c;
	        	charCountQueue.pop();
	        }
	        //
	        cout<<"\n charCount "<<charCount<<" ... priorArr::"<<priorArr<<"..count.."<<count<<" startPos::"<<startPos;
	        int i=startPos;
	        while(i< length && count>=0){
	        	if(i!=startPos){
                    if(charCount <= k ){
	        		     i=i+k-charCount;
                    }else{
                        i=

                    }
	        	}
	        	//
	        	cout<<"\n charCount "<<charCount<<" ... priorArr::"<<priorArr<<"..count.."<<count<<" i::"<<i;
	        	for(size_t j=0;j<charCount && j < length && i<length;j++,i++){
	        		result[i]=priorArr[j];
	        		cout<<"\n2..result.."<<result;
	        	}
	        	count--;
	        }

	        cout<<"\n3..result.."<<result<<"..count.."<<count<<"\n";
	        if(count >=0 ){
	        	return "";
	        }
	        startPos++;
        	if(result[startPos]!='1'){
        		while(result[startPos]!='1'){
        			startPos++;
        		}
        	}
        	cout<<"\n2..result.."<<result<<"\n";

	    }
	    cout<<"\n3..result.."<<result <<"\n";

	    return result;
	
    }
};

int main(){
    Solution sol;
    int size=0;
    cout<<"\na..3.."<<sol.rearrangeString("a",0)<<"\n";
    cout<<"\nabb..3.."<<sol.rearrangeString("abb",2)<<"\n";
    cout<<"\naabbcc..2.."<<sol.rearrangeString("aabbcc",2)<<"\n";
    cout<<"\naabbcc..3.."<<sol.rearrangeString("aabbcc",3)<<"\n";
    cout<<"\naaabc..3.."<<sol.rearrangeString("aaabc",3);
    cout<<"\naaadbbcc..2.."<<sol.rearrangeString("aaadbbcc",2);
}	