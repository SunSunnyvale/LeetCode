#include <map>
#include <iostream>

using namespace std;

int main(){
	map<char,int> arrMap;
	map<char,int>::iterator it;


	for(int i=0;i<10;i++){
		arrMap['a'+i]= i;
	}
	it=arrMap.begin();
	while(it != arrMap.end()){

		cout<<"\nKey.."<<it->first<<"   Value.."<<it->second;
		it++;
	}
	return 1;
}