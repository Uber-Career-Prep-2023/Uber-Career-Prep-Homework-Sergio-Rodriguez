#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <vector>

std::map<int, std::set<int>> Graph_adjacencySet(std::vector<std::pair<int, int>> &edges);	// Given an array of pairs of values representing edges in an unweighted graph, create the equivalent adjacency list/set representation 
bool Graph_bfs(int target, std::map<int, std::set<int>> &graph);							// BFS searching for a target value 			
bool Graph_dfs(int target, std::map<int, std::set<int>> &graph);							// DFS searching for a target value 	
std::vector<int> Graph_topologicalSort(std::map<int, std::set<int>> &graph);				// Topological sort.

#endif

/*

Time and space complexity
-------------------------------------------------------------------------
Function						| Time				| Space				|
-------------------------------------------------------------------------
Graph_adjacencySet				|	O(n)		    |		O(n)		|
Graph_bfs						|	O(n)		    |		O(n)		|
Graph_dfs						|	O(n)	    	|		O(n)		|
Graph_topologicalSort			|	O(n)	    	|		O(1)		|
-------------------------------------------------------------------------

*/