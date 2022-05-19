/**
 * Given an array of N elements. Count the number of ways
 * of dividing all the elements into 2 subsets such that 
 * the sum is same
**/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int num_ways(std::vector<int>& arr)
{
	int n = arr.size();
	int tot_sum = 0;

	for (int x : arr)
	{
		tot_sum += x;
	}

	if (tot_sum % 2)
	{
		return 0;
	}

	int k = tot_sum/2;

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

			if (j >= arr[i-1])
			{
				ans += dp[i-1][j-arr[i-1]]; //pick
			}
			dp[i][j] = ans;
		}
	}

	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= k; ++j)
	// 	{
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	return dp[n][k]/2;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> arr = {1, 5, 3, 6, 9, 2};

    std::cout << num_ways(arr) << "\n";

    return 0;
}
