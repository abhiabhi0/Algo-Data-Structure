#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

class Coordinate
{
	public:
	int x;
	int y;

	Coordinate(int x, int y) : x(x), y(y) {}
};

class NodeData
{
	public:
	Coordinate cord;
	int dist;

	NodeData(Coordinate c, int d) : cord(c), dist(d) {}
};

std::vector<int> ROW = {-1, 0, 0, 1};
std::vector<int> COL = {0, -1, 1, 0};

std::vector<std::vector<int>> shortest_path(std::vector<std::vector<char>>& mat)
{
	int r = mat.size();
	int c = mat[0].size();

	std::vector<std::vector<int>> visited(r, std::vector<int>(c, 0));
	std::vector<std::vector<int>> result(r, std::vector<int>(c));

	std::queue<NodeData> q;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (mat[i][j] == 'H')
			{
				q.push(NodeData(Coordinate(i, j), 0));
				visited[i][j] = 1;
			}
		}
	}

	while (!q.empty())
	{
		NodeData curr = q.front();
		q.pop();

		Coordinate curr_cord = curr.cord;
		int i = curr_cord.x;
		int j = curr_cord.y;
		int curr_dist = curr.dist;

		result[i][j] = curr_dist;

		for (int k = 0; k < 4; ++k)
		{
			int nxt_row = i+ROW[k];
			int nxt_col = j+COL[k];
			if (nxt_row >= 0 && nxt_row < r 
			&& nxt_col >= 0 && nxt_col < c
			&& visited[nxt_row][nxt_col] == 0)
			{
				
				q.push(NodeData(Coordinate(nxt_row, nxt_col), curr_dist+1));
				visited[nxt_row][nxt_col] = 1;
			}
		}
	}
	return result;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    //R means residency, H means house
    std::vector<std::vector<char>> mat = {{'R', 'R', 'R', 'H'},
										{'R', 'R', 'H', 'H'},
										{'R', 'H', 'H', 'R'}};

	auto res = shortest_path(mat);

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[0].size(); ++j)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << "\n";
	}

    return 0;
}
