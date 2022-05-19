/**
 * Given a number K. Find the minimum number of perfect square
 * needed to get the sum K
**/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int min_num_perfect_sq(int K)
{
	std::vector<int> dp(K+1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= K; ++i)
	{
		dp[i] = i;
		for (int j = 1; j*j <= i; ++j)
		{
			int tmp = j*j;

			if (tmp > i)
			{
				break;
			}
			else  
			{
				dp[i] = std::min(dp[i], 1+dp[i-tmp]);
			}
		}
	}

	// for (int x : dp)
	// {
	// 	std::cout << x << " ";
	// }
	return dp[K];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n = 6;
    std::cout << min_num_perfect_sq(n) << "\n";

    return 0;
}
