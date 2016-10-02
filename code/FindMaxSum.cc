#include <iostream>

using namespace std;

/*
3,4,3,1 = 3,3 > 4,1
5,6 = 6+ 6,1 > 5

10,5 = 

*/
int findMaxSum(int a[], int n){
	int incl = a[0];
  int excl = 0;
  int excl_new=0;
  int i;
 
  for (i = 1; i < n; i++)
  {
  	 // cout<<"\n excl_new :: "<<excl_new<<" incl :: "<<incl<<" excl :: "<<excl;
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;
 
     /* current max including i */
     incl = excl + a[i];
     excl = excl_new;
     cout<<"\n2... excl_new :: "<<excl_new<<" incl :: "<<incl<<" excl :: "<<excl;
  }
 

	return ((incl > excl)? incl : excl);


}
int main(){
	int a[]={3,4,3,1,5,6};
	cout<<"\nMax Sum ::"<<findMaxSum(a,6);

	cout<<"Hello...\n";
}