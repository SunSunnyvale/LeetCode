#include<iostream>
#include<unordered_set>

using namespace std;

class Permutations {
    int count;

public:
	Permutations():count(0){}
    void swap(char& x, char& y)
	{
    	char temp;
    	temp = x;
    	x = y;
    	y = temp;
	}
 
	void permute(string& a, int l, int r)
	{
		int i;
	   if (l == r){
	   	 count++;
	     cout<<"\n"<<a<<" count"<<count;

	   }else{

	       for (i = l; i <= r; i++)
	       {
	       	  swap(a[l], a[i]);
	          permute(a, l+1, r);
	          swap(a[l], a[i]); 
	       }
	   }
	}
 
};

int main(){
	Permutations sol;
    string test="abcd";
    cout<<"Result...";
    sol.permute(test,0,test.length()-1);

}
