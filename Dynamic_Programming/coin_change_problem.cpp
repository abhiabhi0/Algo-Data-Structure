/**
 * Given N coins and a sum K
 * Find number of ways to form the sum K if one coin can be 
 * picke at most once. (0/1)
**/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int num_ways(std::vector<int>& coins, int k)
{
	int n = coins.size();
	std::vector<std::vector<int>> dp(n+1, std::vector<int>(k+1, 0));

	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			int ans = dp[i-1][j]; //skip

			if (j >= coins[i-1])
			{
				ans += dp[i-1][j-coins[i-1]]; //pick
			}
			dp[i][j] = ans;
		}
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			std::cout << dp[i][j] << " ";
		}
		std::cout << "\n";
	}

	return dp[n][k];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> coins = {1, 2, 3, 6, 7};
    int k = 10;

    std::cout << num_ways(coins, k) << "\n";

    return 0;
}
