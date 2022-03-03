#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int sum_submatrices(std::vector< std::vector<int> >& mat)
{
	int sum = 0;
	int r = mat.size(), c = mat[0].size();

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int top_l = (i+1) * (j+1);
			int bottom_r = (r-i) * (c-j);

			sum += (top_l * bottom_r) * mat[i][j];
		}
	}
	return sum;	
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<std::vector<int>> mat = {{1, 1},
										{1, 1}};

	std::cout << sum_submatrices(mat) << "\n";

    return 0;
}
