//Given array of distinct elements which is sorted then rotated.
//Find index of target K in this array

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int target_index(std::vector<int>& arr, int n, int k)
{
	if (arr[0] == k)
		return 0;

	int l = 0, r = n-1;
	

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (k > arr[0]) // element in left side
		{
			if (arr[mid] >= arr[0])
			{
				if (arr[mid] == k)
					return mid;
				else if (arr[mid] > k)
					r = mid - 1;
				else  
					l = mid + 1;
			}
			else  
			{
				r = mid - 1;
			}
		}
		else  
		{
			if (arr[mid] < arr[0])
			{
				if (arr[mid] == k)
					return mid;
				else if (arr[mid] > k)
					r = mid - 1;
				else  
					l = mid + 1;
			}
			else  
			{
				l = mid + 1;
			}
		}
	}
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

    std::cout << target_index(vec, n, 5);
 
    return 0;
}
