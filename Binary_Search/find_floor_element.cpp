//Given sorted array in ascending order. Find floor of 
//given target k.

//greatest element <= k

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int find_floor(std::vector<int>& arr, int n, int k)
{
	int ans = -1;
	int l = 0, r = n-1;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (arr[mid] == k)
		{
			return arr[mid];
		}
		else if (arr[mid] < k)
		{
			ans = arr[mid];
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

    std::cout << find_floor(vec, n, 19);
 
    return 0;
}
