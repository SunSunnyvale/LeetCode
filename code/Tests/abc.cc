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
#include <unordered_set>


using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
		vector<vector<bool> > courseMap(numCourses,vector<bool>(numCourses, false));
		vector<int> dependencyCount(numCourses,0);
		std::vector<int> result;
		result.reserve(numCourses);

		stack<int> indptNodes;
		for(auto prerequisite:prerequisites){
			cout<<"\nInput...."<<prerequisite.first<< " second "<<prerequisite.second;
			if(courseMap[prerequisite.first][prerequisite.second] == false){
				courseMap[prerequisite.first][prerequisite.second]=true;
				dependencyCount[prerequisite.first]++;
			}
		}
		for(int i=0;i<numCourses;i++){
			if(dependencyCount[i]==0)
				indptNodes.push(i);
		}
		uint16_t count=0;
		while(!indptNodes.empty()){
			int element=indptNodes.top();
			indptNodes.pop();
			result.push_back(element);
	    	count++;	
    		for(int j=0;j<numCourses;j++){
				cout<<"\ncourseMap[j][i]...."<<courseMap[j][element]<< " second "<<dependencyCount[j]<<" i "<<element<<" j "<<j;
				if(courseMap[j][element]){
					courseMap[j][element]=false;
					dependencyCount[j]--;
					if(dependencyCount[j]==0){
						indptNodes.push(j);
					}
				}
			}		
	    	
		}
		if(count==numCourses){
    		return result;
    	}	
		std::vector<int> v;
		return v;
    }

    //void dfs()

    void dfs(stack<int>& sortedSet, const vector<vector<int> >& courseMap,unordered_set<int>& visited,int index){
    	const std::vector<int>& v=courseMap[index];
    	if(visited.find(index) == visited.end()){
    		visited.insert(index);
    	}else{
    		return;
    	}
    	int size=v.size();
    	for(int i=0;i<size;i++){
			if(visited.find(v[i]) == visited.end()){
				visited.insert(v[i]);
				dfs(sortedSet,courseMap,visited,v[i]);

			}
		}
		sortedSet.push(index);
    }

    vector<int> findOrder2(int numCourses, vector<pair<int, int> >& prerequisites) {
    	stack<int> sortedSet;
    	unordered_set<int> visited;
    	vector<vector<int> > courseMap;
    	courseMap.reserve(numCourses);
    	for(auto prerequisite:prerequisites){
			cout<<"\nInput...."<<prerequisite.first<< " second "<<prerequisite.second;
			if(courseMap[prerequisite.first][prerequisite.second] == false){
				courseMap[prerequisite.first].push_back(prerequisite.second);
			}
		}
		for(int i=0;i<numCourses;i++){
			dfs(sortedSet,courseMap,visited,i);
		}
		int* end   = &sortedSet.top() + 1;
   		int* begin = end - sortedSet.size();
   		std::vector<int> stack_contents(begin, end);
   		return stack_contents;
    }
};


int main(){
    Solution sol;
    int size=0;
    vector<pair<int, int> > prerequisites;
    //[[1,0],[2,0],[3,1],[3,2]]
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(2,0));
    prerequisites.push_back(make_pair(3,1));
    prerequisites.push_back(make_pair(3,2));
    // vector<int> val= sol.findOrder(4,prerequisites);
    // cout<<"\nResult....";
    // for(auto v:val){
    // 	cout<<" "<<v;
    // }

    vector<int> val2= sol.findOrder2(4,prerequisites);
    cout<<"\nResult....";
    for(auto v:val2){
    	cout<<" "<<v;
    }

    vector<pair<int, int> > prerequisites1;
    //[[1,0],[2,0],[3,1],[3,2]]
    prerequisites1.push_back(make_pair(0,1));
   
    vector<int> val1= sol.findOrder(2,prerequisites1);
    cout<<"\nResult....";
    for(auto v:val1){
    	cout<<" "<<v;
    }



    
}





