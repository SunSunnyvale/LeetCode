#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool isElementFoundInRow(int arr[3][4], int low, int high, int column, int target){

	int mid=(low+high)/2;
	while(low <= high){
		if(arr[mid][column] == target){
			return true;
		}else if(arr[mid][column] < target){
			low = mid+1;
		}else{
			high = mid-1;
		}
		mid=(low+high)/2;
	}
	return false;

}

bool isElementFoundInColumn(int arr[3][4],  int low, int high, int row, int target){

	int mid=(low+high)/2;
	while(low <= high){
		if(arr[row][mid] == target){
			return true;
		}else if(arr[row][mid] < target){
			low = mid+1;
		}else{
			high = mid-1;
		}
		mid=(low+high)/2;
	}

	return false;

	
}

bool isTargetPresent(int arr[3][4], int m, int n, int target){

	
	if(!(arr[0][0]<=target && arr[m][n] >=target)){
		return false;
	}

	int row=m;
	int column=0;

	while(row >=0 && column <n){
		if (arr[row][column] == target){
			return true;
		}else if(arr[row][column] < target){
			if(isElementFoundInColumn(arr,0,column+1,row,target)){
				return true;
			}
		}else{
			if(isElementFoundInRow(arr,0,row-1,column,target)){
				return true;
			}
		}
		row--;
		column++;

	}

	if(column==n && row >=0){
		while(row < m ){
			if (arr[row][n-1] == target){
				return true;
			}
			row--;
		}
	}else if(column < n && row == 0){
		while(column < n ){
			if (arr[0][column] == target){
				return true;
			}
			column++;

		}

	}
	return false;

}


int main() {
  int arr[3][4] = {
  	{2,4,7,9},
  	{5,8,10,11},
  	{6,15,18,21}

  };

  cout<<"\n Is target found for 3 : "<< isTargetPresent(arr,3,4,3);

  cout<<"\n Is target found for 7 : "<< isTargetPresent(arr,3,4,7);


  cout<<"\n Is target found for 5 : "<< isTargetPresent(arr,3,4,5);

  cout<<"\n Is target found for 11 : "<< isTargetPresent(arr,3,4,11);

  cout<<"\n Is target found for 15 : "<< isTargetPresent(arr,3,4,15);

  cout<<"\n Is target found for 9 : "<< isTargetPresent(arr,3,4,9);


  cout<<"\n Is target found for 12 : "<< isTargetPresent(arr,3,4,12);
  return 0;
}