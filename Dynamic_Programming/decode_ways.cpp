#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int decode_ways(std::string& str)
{
	int n = str.size();
	std::vector<int> dp(n, 0);

	if (str[0]-'0' > 0)
	{
		dp[0] = 1;
	}
	else  
	{
		dp[0] = 0;
	}

	int num = ((str[0]-'0') * 10) + ((str[1]-'0'));

	if (num >= 10 && num <= 26)
	{
		dp[1] = dp[0]+1;
	}
	else  
	{
		dp[1] = dp[0];
	}

	for (int i = 2; i < n; ++i)
	{
		num = ((str[i-1]-'0') * 10) + ((str[i]-'0'));
		dp[i] = dp[i-1];
		if (str[i] != '0')
		{
			if (num >= 10 && num <= 26)
			{
				dp[i] += dp[i-2];
			}
		}
		else  
		{
			if (num >= 10 && num <= 26)
			{
				dp[i] += dp[i-2];
			}
			// else if (str[i-1] == '0' || str[i-1] > '2')
			// {
			// 	dp[i] += dp[i-1];
			// }
		}
	}

	// for (int x : dp)
	// {
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n";
	return dp[n-1];
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string str = "173";
    std::cout << decode_ways(str) <<"\n";

    return 0;
}
