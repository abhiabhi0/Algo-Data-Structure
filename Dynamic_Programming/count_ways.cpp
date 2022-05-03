/**
 * Given N stairs. Count the number of ways of going 
 * from 0th to nth step.
 * Given that from ith step you can go to (i+1) or (i+2)th step
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int num_ways(int n)
{
	std::vector<int> dp(n+1);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::cout << num_ways(n) << "\n";

    return 0;
}
