#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int submatrix_sum(std::vector<std::vector<int>>& mat, std::pair<int, int>& top_left, std::pair<int, int>& bottom_right)
{
	int r = mat.size();
	int c = mat[0].size();

	std::vector<std::vector<int>> ps_rows(r, std::vector<int>(c));
	std::vector<std::vector<int>> ps(r, std::vector<int>(c));

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (j == 0)
			{
				ps_rows[i][j] = mat[i][j];
			}
			else  
			{
				ps_rows[i][j] = ps_rows[i][j-1] + mat[i][j];
			}
		}
	}

	// for (int i = 0; i < r; ++i)
	// {
	// 	for (int j = 0; j < c; ++j)
	// 	{
	// 		std::cout << ps_rows[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i == 0)
			{
				ps[i][j] = ps_rows[i][j];
			}
			else  
			{
				ps[i][j] = ps[i-1][j] + ps_rows[i][j];
			}
		}
	}

	// for (int i = 0; i < r; ++i)
	// {
	// 	for (int j = 0; j < c; ++j)
	// 	{
	// 		std::cout << ps[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	int start_i = top_left.first, start_j = top_left.second;
	int end_i = bottom_right.first, end_j = bottom_right.second;

	int ans = ps[end_i][end_j];

	if (start_i > 0)
	{
		ans = ans - ps[start_i-1][end_j];
	}

	if (start_j > 0)
	{
		ans = ans - ps[end_i][start_j-1];
	}

	if (start_i > 0 && start_j > 0)
	{
		ans = ans + ps[start_i-1][start_j-1];
	}

	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<std::vector<int>> mat = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}
                            };
										
	std::pair<int, int> top_left = {0, 0};
	std::pair<int, int> bottom_right = {1, 1};

	std::cout << submatrix_sum(mat, top_left, bottom_right) << "\n";

    return 0;
}
