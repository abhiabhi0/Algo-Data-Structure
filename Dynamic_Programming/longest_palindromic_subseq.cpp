#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int longest_palindromic_subsequence(std::string& A)
{
	int la = A.size();
	std::vector<std::vector<int>> dp(la, std::vector<int>(la, 0));

	for (int i = 0; i < la; ++i)
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < la; ++i)
	{
		int r = 0, c = i;

		while (r+i < la && c < la)
		{
			if (A[r] == A[c])
			{
				dp[r][c] = 2 + dp[r+1][c-1];
			}
			else  
			{
				dp[r][c] = std::max(dp[r+1][c], dp[r][c-1]);
			}
			r++;
			c++;
		}
	}

	// for (int i = 0; i < la; ++i)
	// {
	// 	for (int j = 0; j < la; ++j)
	// 	{
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	return dp[0][la-1];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string str = "agbdba";

    std::cout << longest_palindromic_subsequence(str) << "\n";

    return 0;
}
