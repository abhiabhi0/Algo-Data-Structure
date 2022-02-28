//Given an array of size N. Find the maximum sum of subarray of
//length K.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


//Using sliding window technique
int max_sum(std::vector<int>& vec, int n, int k)
{
	int sum = 0, mx = INT_MIN;

	for (int i = 0; i < k; ++i)
	{
		sum += vec[i];
	}

	mx = std::max(sum, mx);

	for (int i = 1; i <= n-k; ++i)
	{
		sum += vec[i+k-1] - vec[i-1];
		mx = std::max(sum, mx);
	}

	return mx;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    std::cout << max_sum(vec, n, k) << "\n";

    return 0;
}
