#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

int max_sum_submatrix(std::vector<std::vector<int>>& mat)
{
	int r = mat.size();
	int c = mat[0].size();

	int ans = INT_MIN;

	for (int row_s = 0; row_s < r; ++row_s)
	{
		std::vector<int> ps_col(c, 0);
		
		for (int row_e = row_s; row_e < r; ++row_e)
		{
			int sum = 0;
			for (int i = 0; i < c; ++i)
			{
				ps_col[i] = ps_col[i] + mat[row_e][i];
				sum += ps_col[i];

				ans = std::max(ans, sum);

				if (sum < 0)
					sum = 0;
			}
		}
	}

	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<std::vector<int> > mat = {
    										{0, -2, -7, 0},
    										{9, 2, -6, 2},
    										{-4, 1, -4, 1},
    										{-1, 8, 0, -2}
    									};

    std::cout << max_sum_submatrix(mat) << "\n";

    return 0;
}
