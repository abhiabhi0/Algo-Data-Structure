//A single item can be picked as many times as we want

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int max_value(std::vector<int>& wt, std::vector<int>& val,
	int k)
{
	int val_sz = val.size();

	std::vector<std::vector<int>> dp(val_sz+1, std::vector<int>(k+1, 0));

	for (int i = 1; i <= val_sz; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp[i][j] = dp[i-1][j];

			if (j >= wt[i-1])
			{
				dp[i][j] = std::max(dp[i][j], dp[i][j-wt[i-1]] + val[i-1]);
			}
		}
	}

	// for (int i = 0; i <= val_sz; ++i)
	// {
	// 	for (int j = 0; j <= k; ++j)
	// 	{
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	return dp[val_sz][k];
}

int main() 
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> vals = {100, 60, 40, 150};
    std::vector<int> wt = {20, 13, 10, 40};
    int k = 50;

    std::cout << max_value(wt, vals, k) << "\n";

    return 0;
}
