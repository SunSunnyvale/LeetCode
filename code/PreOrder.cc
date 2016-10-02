#include <iostream>
#include <stack>

using namespace std;

bool isValidSerialization(string preorder) {
        if(preorder[0] == '#'){
            if(preorder.length()!=1){
                return false;
            }else{
                return true;
            }
        }
        int len=preorder.length();
        int count=0;
        stack<int> elements;
        for(int i=0;i<len;i++){
            if(preorder[i] == ','){
                continue;
            }
            if(preorder[i] == '#'){
                if(elements.empty() && i != len-1){
                    return false;
                }
                if(!elements.empty()){
                	elements.pop();
            	}
                count--;
            }else{
                while(i+1 < len && preorder[i+1] >= '0' && preorder[i+1] <= '9'){
                    i++;
                }
                elements.push(preorder[i]-'0');
                count++;
            }
        }
        
        if(count == -1){
            return true;
        }else{
            return false;
        }
        
    }

    int main(){
    	bool isValid=isValidSerialization("9,32,4,#,#,1,#,#,2,#,6,#,#");

    	if(isValid){

    		cout<<" It is valid BT \n";
    	}else{
    		cout<<"\n It is not valid BT";
    	}
    	return 0;

    }