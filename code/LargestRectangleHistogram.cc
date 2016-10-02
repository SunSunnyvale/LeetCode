/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.


*/


#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_set>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz=heights.size();
        stack<int> areaStack;
        stack<int> startIndex;
        int maxArea=0;
        int currentHeight=0;
        areaStack.push(0);
        startIndex.push(0);
        for(int i=0;i<sz;i++){
            currentHeight=heights[i];
            if(currentHeight == areaStack.top()){
                continue;
            }
            if(currentHeight > areaStack.top()){
            	//cout<<"\nPush..."<<currentHeight<<" Index::"<<i;
                areaStack.push(currentHeight);
                startIndex.push(i);
                continue;
            }
            int currHtStrtIndx=i;
            while(currentHeight <  areaStack.top() && !areaStack.empty()){
            	//cout<<"\nareaStack.top()..."<<areaStack.top()<<" i- startIndex.top()::"<<(i - startIndex.top());
                maxArea=max(maxArea, ( areaStack.top() * (i- startIndex.top() )) );
                currHtStrtIndx=startIndex.top();
                areaStack.pop();
                startIndex.pop();

            }
            if(currentHeight >  areaStack.top()){
                areaStack.push(currentHeight);
                startIndex.push(min(i,currHtStrtIndx));
            }
        }
        while(!areaStack.empty()){
        	//cout<<"\nareaStack.top()..."<<areaStack.top()<<" i- startIndex.top()::"<<(sz - startIndex.top());
            maxArea=max(maxArea, ( areaStack.top() * (sz- startIndex.top() )) );
            areaStack.pop();
            startIndex.pop();
        }
        return maxArea;
        
    }
};

int main(){
    Solution sol;
    int size=0;
    vector<int > area;
    //2,1,5,6,2,3
    area.push_back(2);
    area.push_back(1);
    // prerequisites.push_back(make_pair(0,3));
    area.push_back(5);
    area.push_back(6);
    area.push_back(2);
    area.push_back(3);
    
    int val2= sol.largestRectangleArea(area);

    cout<<"\nResult...."<<val2;

    vector<int > area2;
    //2,1,5,6,2,3
    area2.push_back(2);
    area2.push_back(1);
    // prerequisites.push_back(make_pair(0,3));
    area2.push_back(2);

    int val= sol.largestRectangleArea(area2);

    cout<<"\nResult...."<<val;

   
}