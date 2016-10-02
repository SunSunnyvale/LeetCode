#include <cstddef>
#include <bitset>
#include <string>
#include <iostream>

using namespace std;

class TrieNode{
    
public:
    // Initialize your data structure here.
    bitset<26> element;
	TrieNode *next[26];
	bool isWord;
    TrieNode() {
    	element=0;
    	isWord=false;
    	for(int i=0;i<26;i++){
    		next[i]=NULL;
    	}
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp=root;
        int index=0;
        int val=1;
        int wordLen=word.length();
        int counter=0;
        for(const char &c:word){
        	index=tolower(c) - 'a';
        	val=1;
        	val=val<<index;
        	if(counter==0){
	        	temp->element[index]=temp->element[index]|val;
	        	counter++;
	        }else{
	        	if(temp->next[index] == NULL){
	        		temp->next[index]=new TrieNode();
	        	}
	        	temp=temp->next[index];
	        	temp->element[index]=temp->element[index]|val;
	        }
        }
        temp->isWord=true;
        
    }

    // Returns if the word is in the trie.
    bool search(string word) {
    	TrieNode* temp=root;
    	uint16_t index=0;
    	int counter=0;
    	int val=1;
    	for(const char &c:word){
    		index=tolower(c) - 'a';
        	val=1;
        	val=val<<index;
        	//cout<<"\n val"<<val;
        	if(counter!=0){
        		if(temp->next[index] == NULL){
	        		//cout<<"\nc::"<<c<<" isWord::"<<temp->isWord<<" temp->element[index]::"<<temp->element[index]<<" index::"<<index<<" temp->next[index] == NULL";
	        		return false;
	        	}
	        	temp=temp->next[index];
	        }else{
	        	counter++;
	        }

	        if(!(temp->element.to_ulong() & val )){
        		//cout<<"\nc::"<<c<<" isWord::"<<temp->isWord<<" temp->element::"<<temp->element<<" index::"<<index<<"  val"<<val;
        		return false;
        	}
        }
        if(!temp->isWord){
        	//cout<<"\nisWord::"<<temp->isWord<<" temp->element[index]::"<<temp->element[index]<<" index::"<<index<<" !temp->isWord";
	        		
        	return false;
        }
        
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
    	TrieNode* temp=root;
    	uint16_t index=0;
    	int counter=0;
    	int val=1;
    	for(const char &c:prefix){
    		index=tolower(c) - 'a';
        	val=1;
        	val=val<<index;
        	//cout<<"\n val"<<val;
        	if(counter!=0){
        		if(temp->next[index] == NULL){
	        		//cout<<"\nc::"<<c<<" isWord::"<<temp->isWord<<" temp->element[index]::"<<temp->element[index]<<" index::"<<index<<" temp->next[index] == NULL";
	        		return false;
	        	}
	        	temp=temp->next[index];
	        }else{
	        	counter++;
	        }

	        if(!(temp->element.to_ulong() & val )){
        		//cout<<"\nc::"<<c<<" isWord::"<<temp->isWord<<" temp->element::"<<temp->element<<" index::"<<index<<"  val"<<val;
        		return false;
        	}
        }
        
        return true;
    }

    void printTree(){
    	TrieNode* temp=root;
    	uint16_t index=0;
    	if(temp==NULL){
    		cout<<"\nTree is empty";
	        return ;
	    }

	    while(temp != NULL){
	    	cout<< "\n"<<temp->element;
	    	for(int i=0;i<26  ;i++){
	    		if(temp->next[i] == NULL)
	    			continue;
	    		cout<<"\n.....";
	    		cout<< "\n"<<temp->next[i]->element;
	    	}
	    	break;
		}
    }

    

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
int main(){
Trie trie;
trie.insert("ab");
trie.printTree();
cout<<"\n Search Result:: "<<trie.search("a");
cout<<"\n Starts with Result:: "<<trie.startsWith("a");

}