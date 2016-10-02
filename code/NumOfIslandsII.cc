/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. 
Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent 
lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/
#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> roots(m*n,-1);
        vector<int> sz(m*n,1);
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<int> res;
        int cnt = 0;
        int id1=0;
        int j=0;
        int y=0,x=0,id2=0;
        for(const auto& position:positions){
            id1 = position.first*n + position.second;
            roots[id1] = id1;
            cnt++;
            for(j=0;j<dir.size();j++){
                y = position.first  + dir[j][0];
                x = position.second + dir[j][1];
                id2 = y*n+x;
                if(x>=0 && x<n && y>=0 && y<m && roots[id2] !=-1){
                    unite(roots,sz,findRoot(roots, id2),findRoot(roots, id1),cnt);
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findRoot(vector<int> & roots, int id){
        while(roots[id]!= id){
           //pass compression
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
    void unite(vector<int> &roots, vector<int> &sz, int root1, int root2,int &cnt){
        if(root1!=root2) cnt--;
        //weighted quick_union
        if(sz[root1]<sz[root2]){
            sz[root2]+=sz[root1];
            roots[root1] = root2;
        }else{
            sz[root1]+=sz[root2];
            roots[root2] = root1;
        }
    }
};