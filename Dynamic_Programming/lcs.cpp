#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int lcs(std::string& s1, std::string& s2)
{
	int n1 = s1.size();
	int n2 = s2.size();

	std::vector<std::vector<int>> dp(n1+1, std::vector<int>(n2+1, 0));

	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else  
			{
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
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

    std::string s1 = "ABCDGH";
    std::string s2 = "AEDFHR";

    std::cout << lcs(s1, s2) << "\n";
    return 0;
}
