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

int shortest_path(std::vector<std::vector<int>>& mat, int source_row,
	int source_col, int dest_row, int dest_col)
{
	int r = mat.size();
	int c = mat[0].size();

	std::vector<std::vector<int>> visited(r, std::vector<int>(c, 0));

	std::queue<NodeData> q;
	q.push(NodeData(Coordinate(source_row, source_col), 0));
	visited[source_row][source_col] = 1;

	while (!q.empty())
	{
		NodeData curr = q.front();
		q.pop();

		Coordinate curr_cord = curr.cord;
		int i = curr_cord.x;
		int j = curr_cord.y;
		int curr_dist = curr.dist;

		for (int k = 0; k < 4; ++k)
		{
			int nxt_row = i+ROW[k];
			int nxt_col = j+COL[k];
			if (nxt_row >= 0 && nxt_row < r 
			&& nxt_col >= 0 && nxt_col < c
			&& mat[nxt_row][nxt_col] == 0
			&& visited[nxt_row][nxt_col] == 0)
			{
				if (nxt_row == dest_row && nxt_col == dest_col)
				{
					return 1+curr_dist;
				}
				else  
				{
					q.push(NodeData(Coordinate(nxt_row, nxt_col), curr_dist+1));
					visited[nxt_row][nxt_col] = 1;
				}
			}
		}
	}
	return -1;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    //0 means empty path, 1 means blocked
    std::vector<std::vector<int>> mat = {{0, 0, 0, 1, 0},
										{0, 1, 0, 0, 0},
										{0, 0, 1, 0, 0},
										{0, 1, 0, 0, 0},
										{1, 0, 0, 1, 0}};

	int s_r = 1, s_c = 0;
	int d_r = 3, d_c = 4;

	std::cout << shortest_path(mat, s_r, s_c, d_r, d_c) << "\n";

    return 0;
}
