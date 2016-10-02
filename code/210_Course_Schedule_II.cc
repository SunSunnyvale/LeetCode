//210. Course Schedule II
/*

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].


Solution: 

 	/ 1
 0		\	
 	\ 2	  \
 		 \  3


The above problem can be represented by the above graph, The way to solve is by starting the solution from elements that don't have any incoming connections. 

In the above example, for courses 1 and 2 ,0 is mandatory course. and 0 has no dependency. 

so solution start is 0. 

	  1
 0		\	
 	  2	  \
 		 \  3

Now 1 and 2 have no in coming connections so possible orders are [0,2,1] or [0,1,2]

	  1
 0		 	
 	  2	  
 		    3

So the only remaining course is 3. hence the solution is [0,2,1,3] or [0,1,2,3]
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
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    	std::vector<int> result;
    	std::vector<int> dependentCourses(numCourses,0);
    	vector<vector<int> > courseMap(numCourses);
    	for(auto prerequisite:prerequisites){
			courseMap[prerequisite.second].push_back(prerequisite.first);
			dependentCourses[prerequisite.first]++;
		}
		queue<int> coursesWithNoDpndts;
		for(int i=0;i<numCourses;i++){
			if(dependentCourses[i]==0){
				coursesWithNoDpndts.push(i);
			}
		}
		int course=-1;
		while(!coursesWithNoDpndts.empty()){
			course=coursesWithNoDpndts.front();
			coursesWithNoDpndts.pop();
			result.push_back(course);
			for(auto element:courseMap[course]){
				dependentCourses[element]--;
				if(dependentCourses[element]==0){
					coursesWithNoDpndts.push(element);
				}

			}
		}
		if( result.size()< numCourses){
			std::vector<int> v;
			return v;
		}
   		return result;
    }
};


int main(){
    Solution sol;
    int size=0;
    vector<pair<int, int> > prerequisites;
    //[[1,0],[2,0],[3,1],[3,2]]
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(2,0));
    //prerequisites.push_back(make_pair(0,3));
    prerequisites.push_back(make_pair(3,1));
    prerequisites.push_back(make_pair(3,2));
    // vector<int> val= sol.findOrder(4,prerequisites);
    // cout<<"\nResult....";
    // for(auto v:val){
    // 	cout<<" "<<v;
    // }

    vector<int> val2= sol.findOrder(4,prerequisites);
    cout<<"\nResult....";
    for(auto v:val2){
    	cout<<" "<<v;
    }

    vector<pair<int, int> > prerequisites1;
    //[[1,0],[2,0],[3,1],[3,2]]
    //prerequisites1.push_back(make_pair(0,1));
    prerequisites1.push_back(make_pair(1,0));
   
    vector<int> val1= sol.findOrder(2,prerequisites1);
    cout<<"\nResult....";
    for(auto v:val1){
    	cout<<" "<<v;
    }



    
}





