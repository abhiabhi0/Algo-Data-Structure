/**
 * Can move in right or down direction
 * The starting cell is 0,0 and ending cell is N-1, M-1
 * if health <= 0 then dead
 * 
 * Return the minimum amount of health with which he should
 * start so that he reaches the princess in living condition
 * (health > 0)
**/  

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int min_health(std::vector<std::vector<int>>& vec, int r, int c)
{
	std::vector<std::vector<int>> dp(r, std::vector<int>(c));

	if (1-vec[r-1][c-1] > 0)
	{
		dp[r-1][c-1] = 1-vec[r-1][c-1];
	}
	else  
	{
		dp[r-1][c-1] = 1;
	}

	for (int i = r-2; i >= 0; i--)
	{
		if (dp[i+1][c-1] - vec[i][c-1] > 0)
		{
			dp[i][c-1] = dp[i+1][c-1] - vec[i][c-1];
		}
		else  
		{
			dp[i][c-1] = 1;
		}
	}

	for (int i = c-2; i >= 0; i--)
	{
		if (dp[r-1][i+1] - vec[r-1][i] > 0)
		{
			dp[r-1][i] = dp[r-1][i+1] - vec[r-1][i];
		}
		else  
		{
			dp[r-1][i] = 1;
		}
	}

	for (int i = r-2; i >= 0; i--)
	{
		for (int j = c-2; j >= 0; j--)
		{
			
			if (std::min(dp[i+1][j], dp[i][j+1]) - vec[i][j] > 0)
			{
				dp[i][j] = std::min(dp[i+1][j], dp[i][j+1]) - vec[i][j];
			}
			else  
			{
				dp[i][j] = 1;
			}
		}
	}

	// for (int i = 0; i < r; ++i)
	// {
	// 	for (int j = 0; j < c; ++j)
	// 	{
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	return dp[0][0];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

   	std::vector<std::vector<int>> vec = {{-2, -3, 3},
   										{-5, -10, 1},
   										{10, 30, -5}};

   	std::cout << min_health(vec, 3, 3) << "\n";

    return 0;
}
