/**
 * Given an array of N elements. Divide all elements into
 * 2 subsets such that the absolute difference in their
 * sum is minimum.
**/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int min_abs_diff(std::vector<int>& arr)
{
	int n = arr.size();
	int tot_sum = 0;

	for (int x : arr)
	{
		tot_sum += x;
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

	int j = k;

	while (dp[n][j] == 0)
	{
		j--;
	}

	int ans = 2*(k-j);

	if (tot_sum % 2)
	{
		ans++;
	}
	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> arr = {3, 6, 2, 9, 26};

    std::cout << min_abs_diff(arr) << "\n";

    return 0;
}
