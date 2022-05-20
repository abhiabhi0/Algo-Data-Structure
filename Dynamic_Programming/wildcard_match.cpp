#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int match_str(std::string& s1, std::string& s2)
{
	int n1 = s1.size();
	int n2 = s2.size();

	std::vector<std::vector<bool>> dp(n1+1, std::vector<bool>(n2+1));
	dp[0][0] = true;

	for (int i = 1; i <= n1; ++i)
	{
		dp[i][0] = false;
	}

	for (int j = 1; j <= n2; ++j)
	{
		if (s2[j-1] == '*')
		{
			dp[0][j] = dp[0][j-1];
		}
		else  
		{
			dp[0][j] = false;
		}
	}

	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			if (s2[j-1] >= 'a' && s2[j-1] <= 'z')
			{
				if (s1[i-1] == s2[j-1])
				{
					dp[i][j] = dp[i-1][j-1];
				}
			}
			else if (s2[j-1] == '?')
			{
				dp[i-1][j] = dp[i-1][j-1];
			}
			else if (s2[j-1] == '*')
			{
				dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
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

    std::string s1 = "aaabbasdfadfdb";
    std::string s2 = "a*b";

    std::cout << match_str(s1, s2) << "\n";

    return 0;
}
