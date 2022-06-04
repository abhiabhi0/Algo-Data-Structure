#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void dfs(int u, std::vector<std::vector<int>>& adj_list, std::vector<int>& visited)
{
	visited[u] = 1;
	auto v = adj_list[u];
	for (int x : v)
	{
		x = x-1;
		if (visited[x] == 0)
		{
			dfs(x, adj_list, visited);
		}
	}
}

int num_connected_components(std::vector<std::vector<int>>& adj_list)
{
	int connected = 0;
	std::vector<int> visited(adj_list.size(), 0);
	for (int i = 0; i < adj_list.size(); ++i)
	{
		int u = i; // vertex;
		if (visited[u] == 0)
		{
			connected++;
			dfs(u, adj_list, visited);
		}
	}
	return connected;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<std::vector<int>> adj_list = {{2, 4},
											{1, 3},
											{2, 4},
											{1, 3},
											{6},
											{5},
											{8},
											{7, 9, 10},
											{8},
											{8},
											{}};
	std::cout << num_connected_components(adj_list) << "\n";

    return 0;
}
