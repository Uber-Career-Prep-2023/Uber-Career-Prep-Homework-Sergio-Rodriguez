/* 
Given a binary matrix in which 1s represent land and 0s represent water. 
Return the number of islands (contiguous 1s surrounded by 0s or the edge of the matrix).
*/

#include <vector>
#include <list>
#include <iostream>
using namespace std;

int vis[1000][1000];

bool isInBounds(int x, int y, int n, int m){
	return ((x <= n && y <= m) && (x >= 0 && y >= 0));
}

void dfs(vector<vector<int>> mat, int x, int y, int n, int m){
	if(isInBounds(x+1, y, n, m) && !vis[x+1][y]){
		vis[x+1][y] = 1;
		dfs(mat, x+1, y, n, m);
	}
	if(isInBounds(x, y+1, n, m) && !vis[x][y+1]){
		vis[x][y+1] = 1;
		dfs(mat, x, y+1, n, m);
	}
	if(isInBounds(x-1, y, n, m) && !vis[x-1][y]){
		vis[x-1][y] = 1;
		dfs(mat, x-1, y, n, m);
	}
	if(isInBounds(x, y-1, n, m) && !vis[x+1][y]){
		vis[x][y-1] = 1;
		dfs(mat, x, y-1, n, m);
	}
}

int matTraverse(vector<vector<int>> mat, int n, int m){
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == 1 && vis[i][j] == 0){
				count++;
				dfs(mat, i, j, n, m);
			}
		}
	}
	return count;
}

int main(){
	vector<vector<int>> mat1 = {{1,0,1,1,1},{1,1,0,1,1},{0,1,0,0,0},{0,0,0,1,0},{0,0,0,0,0}};
	vector<vector<int>> mat2 = {{1,0,0},{0,0,0}};
	cout << matTraverse(mat1,5, 5) << "\n";
	cout << matTraverse(mat1,2, 3) << "\n";
	return 0;
}


