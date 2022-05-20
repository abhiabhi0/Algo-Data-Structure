/**
 * Givwn two strings s1 and s2
 * Convert s1 to s2 in minimum cost.
 * The operations can be performed on s1
 * 	insert - cost : i
 * 	delete - cost : d
 * 	update - cost : u
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int convert_cost(std::string& s1, std::string& s2, int insert, int dlt, int update)
{
	int n1 = s1.size();
	int n2 = s2.size();

	std::vector<std::vector<int>> dp(n1+1, std::vector<int>(n2+1));
	dp[0][0] = 0;

	for (int i = 1; i <= n1; ++i)
	{
		dp[i][0] = dp[i-1][0] + dlt;
	}

	for (int j = 1; j <= n2; ++j)
	{
		dp[0][j] = dp[0][j-1] + insert;
	}

	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else  
			{
				dp[i][j] = std::min(std::min(dlt + dp[i-1][j], insert + dp[i][j-1]),
					update + dp[i-1][j-1]);
			}
		}
	}
	return dp[n1][n2];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string s1 = "abcd";
    std::string s2 = "abe";
    int insert = 2, dlt = 2, update = 3;

    std::cout << convert_cost(s1, s2, insert, dlt, update) << "\n";

    return 0;
}
