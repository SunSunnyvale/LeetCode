#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;
/* Find the min number of steps needed to reach a target. 

You can do either to the left or right of current point to i places. 

<---|--|--|--|--|--|--|--|--|--|--|--|--|--|---->
   -7 -6 -5 -4 -3 -2 -1  0  1  2  3  4  5  6

   Target 5 

  i
  1  -1  +1 
  2  -3 1  -1 3 (1 and -1 you already visited you can safely discard)
  3     -6    0    -2   4     -4    2 0 6
  4  -10 -2 -4 4 -6  2 0  8 -8  0 -2  6 -4 4 2 10
  5  5            
*/

class Solution {
public:
    int minPath(int target, int i,int hops,queue<int>& bfsRow){
        queue<int> bfsNextRow;
        cout<<"\n";
        while(!bfsRow.empty()){
            int ele=bfsRow.front();
            bfsRow.pop();
            if(ele-i == target || ele+i==target){
                return hops;
            }
            bfsNextRow.push(ele-i);
            bfsNextRow.push(ele+i);
            cout<<" "<<ele-i<<" "<<ele+i;
        }
        i++;
        hops++;
        return minPath(target,i,hops,bfsNextRow);
    }
};

int main(){
    Solution sol;
    queue<int> bfsRow;
    bfsRow.push(0);
    int val= sol.minPath(21,1,0,bfsRow);
    cout<<"\nResult...."<<val;

   
}