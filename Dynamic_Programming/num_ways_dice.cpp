/**
 * Given a dice and a number N. COunt the num of ways to get
 * a sum N if you can roll the dice as may times as required
**/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int num_ways_dice(int N)
{
	std::vector<int> dp(N+1, 0);
	dp[0] = 1;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			if (i-j >= 0)
			{
				dp[i] += dp[i-j]; 
			}
		}
	}
	return dp[N];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n = 4;
    std::cout << num_ways_dice(n) << "\n";

    return 0;
}
