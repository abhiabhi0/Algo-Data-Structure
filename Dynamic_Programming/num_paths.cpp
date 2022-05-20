#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int num_paths(int N, int M)
{
	std::vector<std::vector<int>> dp(N, std::vector<int>(M, 1));

	dp[0][0] = 0;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[N-1][M-1];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::cout << num_paths(6, 4) << "\n";

    return 0;
}
