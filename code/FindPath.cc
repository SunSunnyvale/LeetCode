//FindPath

/*

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

*/
using namespace std;

class Solution{
private:
	string popNeighbour(multiset<string>& neighbours){
		auto ret=neighbours.begin();
		neighbours.erase(neighbours.begin());
		return ret;
	}

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
    	unordered_map<string, multiset<string> > edges;
    	for(pair<string,string> ticket:tickets){
    		edges[ticket.first].insert(ticket.second);
    	}

    	stack<string> nodes;
    	nodes.push("JFK");

    	vector<string> path(tickets.size() + 1);
        int path_idx = path.size() - 1;

    	// DFS.
        while (!nodes.empty()) {
            while (!edges[nodes.top()].empty()) {
                nodes.push(PopNeigh(edges[nodes.top()]));
            }
            path[path_idx--] = nodes.top();
            nodes.pop();
        }

        return path;

    }
	
};