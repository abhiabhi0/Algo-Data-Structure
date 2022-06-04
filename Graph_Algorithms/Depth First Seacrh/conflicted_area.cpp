/**
 * Given the map of conflicted area b/w two countries, I and P.
 * 'I' will take back all land that is completely surrounded by 'I'.
 * Return the final state of map.
**/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> ROW = {1, 0, 0, -1};
std::vector<int> COL = {0, 1, -1, 0};

void dfs(int i, int j, std::vector<std::vector<char>>& mat)
{
	if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()
		|| mat[i][j] == 'I' || mat[i][j] == 'F')
	{
		return;
	}
	mat[i][j] = 'F'; //free
	
	for (int k = 0; k < 4; ++k)
	{
		int nx_r = i + ROW[k];
		int nx_c = j + COL[k];

		dfs(nx_r, nx_c, mat);
	}
}

void new_map_state(std::vector<std::vector<char>>& mat)
{
	for (int i = 0; i < mat.size(); ++i)
	{
		if (i == 0 || i == mat.size()-1)
		{
			for (int j = 0; j < mat[0].size(); ++j)
			{
				if (mat[i][j] == 'P')
				{
					dfs(i, j, mat);
				}
			}
		}
	}

	for (int i = 0; i < mat.size(); ++i)
	{
		for (int j = 0; j < mat[0].size(); ++j)
		{
			if (j == 0 || j == mat[0].size()-1 && mat[i][j] == 'P')
			{
				dfs(i, j, mat);
			}
		}
	}
	
	
	for (int i = 0; i < mat.size(); ++i)
	{
		for (int j = 0; j < mat[0].size(); ++j)
		{
			if (mat[i][j] == 'F')
			{
				mat[i][j] = 'P';
			}
			else if (mat[i][j] == 'P')
			{
				mat[i][j] = 'I';
			}
		}
	}
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<std::vector<char>> mat = {
    	{'I', 'I', 'P', 'I', 'I'},
    	{'I', 'P', 'P', 'I', 'I'},
    	{'I', 'I', 'I', 'I', 'I'},
    	{'I', 'P', 'I', 'I', 'P'},
    	{'I', 'P', 'P', 'I', 'P'},
    	{'I', 'I', 'I', 'I', 'P'},
    	{'I', 'I', 'I', 'P', 'I'}
    };

	new_map_state(mat);

	for (int i = 0; i < mat.size(); ++i)
	{
		for (int j = 0; j < mat[0].size(); ++j)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << "\n";
	}

    return 0;
}
