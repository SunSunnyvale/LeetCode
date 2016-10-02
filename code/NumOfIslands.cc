/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void exploreIsland(int m, int n, vector<vector<char> >& positions,char islandId,int i,int j,const vector<vector<int> >& dir, bool isFirstCall){
        //cout<<"\n2..i::"<<i<<" j::"<<j<<" islandId::"<<islandId<<" isFirstCall::"<<isFirstCall;
		if(i<0 ||i>=m || j<0 || j>=n || positions[i][j]=='0' || ( positions[i][j]==islandId && !isFirstCall) ){
			return;
		}
		
		positions[i][j]=islandId;
		//cout<<"\n3..i::"<<i<<" j::"<<j<<" grid[i][j]::"<<positions[i][j];
		for(int k=0;k<4;k++){
			exploreIsland(m,n, positions,islandId,i+dir[k][0], j+dir[k][1],dir,false);
		}
	}
	void print(vector<vector<char> >& grid){
	    for(const auto& subVec:grid){
	        cout<<"\n";
	        for(const auto& ele:subVec){
	            cout<<ele<<" ";
	        }
	    }
	}

    int numIslands(vector<vector<char> >& grid) {
        int count=0;
    	char startCount='2';
    	vector<vector<int> > dir= {{0,1},{0,-1},{1,0},{-1,0}};
    	count=0;
    	
    	int m=grid.size();
    	if(m==0){
    	    return 0;
    	}
    	int n= grid[0].size();
    	if(n==0){
    	    return 0;
    	}
    	
    	//cout<<"\nm.."<<m<<" n::"<<n;
    	for(int i=0;i<m;i++){
    	    //print(grid);
    		for(int j=0;j<n;j++){
    		    //cout<<"\ni::"<<i<<" j::"<<j<<" grid[i][j]::"<<grid[i][j];
    			if(grid[i][j]=='1'){
    			    grid[i][j]=startCount+count;
    				exploreIsland(m,n,grid,(startCount+count),i,j,dir,true);
    				count++;
    			}
    		}
    		//print(grid);
    		//cout<<"\nDone.."<<i;
    	}
    	return count;
    }
};