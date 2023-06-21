#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <list>
#include <iostream>
#include "./graph.h"

std::map<int, std::set<int>> Graph_adjacencySet(std::vector<std::pair<int, int>> &edges){
	std::map <int, std::set<int>> graph;
	for(auto& edge : edges){
		graph[edge.first].insert(edge.second);
	}
	return graph;
}


bool Graph_dfsUtil(int target, std::map<int, std::set<int>> &graph, std::unordered_map<int, bool> &visited){
	std::list<int> t_order;
	t_order.push_back(graph.begin()->first);
	while(!t_order.empty()){
		if(t_order.front() == target){
			return true;
		}
		Graph_dfsUtil(t_order.front(), &graph, &visited)
		t_order.pop();
	}
	return false;
}

bool Graph_bfsUtil(int target, std::map<int, std::set<int>> &graph, std::unordered_map<int, bool> &visited){
	std::list<int> t_order;
	t_order.push_back(graph.begin()->first);
	while(!t_order.empty()){
		int node = t_order.front();
		t_order.pop_front();
		if(node == target){
			return true;
		}
		visited[node] = true;
		for(const int &it : graph[node]){
			if(visited.find(it) == visited.end()){
				visited[it] = true;
				t_order.push_back(it);
			}
		}
	}
	return false;
}

bool Graph_bfs(int target, std::map<int, std::set<int>> &graph){
	std::unordered_map<int, bool> visited;
	for(int i = 0; i < graph.size(); i++){
		if(visited.find(i) == visited.end()){
			if(Graph_bfsUtil(target, graph, visited)){
				return true;
			}
		}
	}
	return false;
}

bool Graph_dfs(int target, std::map<int, std::set<int>> &graph){
	std::unordered_map<int, bool> visited;
	for(int i = 0; i < graph.size(); i++){
		if(visited.find(i) == visited.end()){
			if(Graph_dfsUtil(target, graph, visited)){
				return true;
			}
		}
	}
	return false;
}

std::vector<int> Graph_topologicalSort(std::map<int, std::set<int>> &graph);
