/**
 * Given two strings A and B.
 * Count num of unique ways in which we can create B
 * as a subseq of A
**/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int num_str(std::string& s1, std::string& s2)
{
	int n1 = s1.size();
	int n2 = s2.size();

	std::vector<std::vector<int>> dp(n1+1, std::vector<int>(n2+1));

	dp[0][0] = 1;
	for (int i = 1; i <= n1; ++i)
	{
		dp[i][0] = 1;
	}

	for (int j = 1; j <= n2; ++j)
	{
		dp[0][j] = 0;
	}

	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s1[i-1] != s2[j-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else 
			{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
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

    std::string s1 = "RABBBIT";
    std::string s2 = "RABBIT";

    std::cout << num_str(s1, s2) << "\n";

    return 0;
}
