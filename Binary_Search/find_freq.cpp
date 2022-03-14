//Given sorted array in ascending order. Find freq of
//given target k.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int find_freq(std::vector<int>& arr, int n, int k)
{
	int f = -1, lst = -1;

	//finding first occurrence
	int l = 0, r = n-1;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (arr[mid] == k)
		{
			f = mid;
			r = mid - 1;
		}
		else if (arr[mid] < k)
		{
			l = mid + 1;
		}
		else  
		{
			r = mid - 1;
		}
	}

	//finding last occurrence
	l = f, r = n-1;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (arr[mid] == k)
		{
			lst = mid;
			l = mid + 1;
		}
		else if (arr[mid] < k)
		{
			l = mid + 1;
		}
		else  
		{
			r = mid - 1;
		}
	}

	return (lst - f + 1);
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

    std::cout << find_freq(vec, n, 7);
 
    return 0;
}
