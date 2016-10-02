/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

Hide Company Tags
*/

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;

class Solution {
	

public:
	typedef pair<int,pair<int,int> > SingleNode;

	struct Compare {
		bool operator()(const SingleNode& lhs, const SingleNode& rhs) const
		{
  			return lhs.first > rhs.first;
		}
	};

    int kthSmallest(vector<vector<int> >& matrix, int k) {
    	int size=matrix[0].size();
    	int totSize=size*size;
    	if(totSize < k){
    		return 0;
    	}
    	if(k<=1){
    		return matrix[0][0];
    	}
    	if(k==totSize){
    		return matrix[size-1][size-1];
    	}
    	priority_queue< SingleNode, std::vector< SingleNode >, Compare > minHeap;
    	for(int i=0; i<size;i++){
    		cout<<"\nEle ::"<<matrix[0][i] <<" Row::"<<0<<" column::"<<i;
    		minHeap.push(make_pair(matrix[0][i], make_pair(0,i)) );
    	}
    	pair<int,int> index;
    	int count=0;
    	int row=0,column=0;
    	for(int i=0;i<k;i++){
    		if(count==k-1 ){
    			break;
    		}
    		row=column=0;
    		row=minHeap.top().second.first;
    		column=minHeap.top().second.second;
    		cout<<"\nEle ::"<<minHeap.top().first <<" Row::"<<minHeap.top().second.first<<" column::"<<minHeap.top().second.second;
    		if(row+1 < size){
    			++row;
    		}else{
    			minHeap.pop();
    			count++;
    			i--;
    			continue;

    		}
    		minHeap.pop();
    		count++;
    		minHeap.push(make_pair(matrix[row][column], make_pair(row,column)));
    	}
    	
    	return minHeap.top().first;
    }
};

int main(){
    Solution sol;
    int size=0;
    vector<vector<int> > matrix;
    std::vector<int> v,v1,v2;
    v.push_back(1);
    v.push_back(2);
    //v.push_back(9);

    v1.push_back(1);
    v1.push_back(3);
    //v1.push_back(13);

    v2.push_back(12);
    v2.push_back(13);
    v2.push_back(15);

    matrix.push_back(v);
    matrix.push_back(v1);
    //matrix.push_back(v2);
    

    int val= sol.kthSmallest(matrix,3);

    cout<<"\nResult...."<<val;

   
}