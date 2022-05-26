#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int lis(std::vector<int>& vec)
{
	int n = vec.size();
	std::vector<int> dp(n);
	dp[0] = 1;

	for (int i = 1; i < n; ++i)
	{
		int curr = 0;
		for (int j = 0; j < i; ++j)
		{
			if (vec[j] < vec[i])
			{
				curr = std::max(curr, dp[j]);
			}
		}
		dp[i] = curr + 1;
	}
	return *max_element(dp.begin(), dp.end());
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::vector<int> vec = {10, 3, 12, 7, 2, 9, 11, 20, 11, 13, 6, 8};
    std::cout << lis(vec) << "\n";

    return 0;
}
