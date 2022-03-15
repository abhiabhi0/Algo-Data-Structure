//Given an array of positive numbers. Find maximum length K,
//such that there is no subarray of length K with sum >= B

//All subarrays of length K have sum < B

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool check_sum(std::vector<int>& arr, int n, int k, int B)
{
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += arr[i];
	}

	if (sum >= B)
		return false;

	for (int i = k; i < n; ++i)
	{
		sum += arr[i];
		sum -= arr[i-k];

		if (sum >= B)
			return false;
	}
	return true;
} 

int max_len(std::vector<int>& arr, int n, int B)
{
	int l = 0, r = n-1;
	int ans;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (check_sum(arr, n, mid, B))
		{
			ans = mid;
			l = mid+1;
		}
		else  
		{
			r = mid-1;
		}
	}
	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
    	std::cin >> vec[i];
    }

    std::cout << max_len(vec, n, 20);
 
    return 0;
}
