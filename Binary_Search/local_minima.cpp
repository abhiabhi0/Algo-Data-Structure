//Given array of distince elements. Find any one local minima

//a[i-1] > a[i] < a[i+1]

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int local_minima(std::vector<int>& arr, int n)
{
	if (arr[0] < arr[1])
		return arr[0];

	if (arr[n-1] < arr[n-2])
		return arr[n-1];

	int l = 1, r = n-2;

	while (l <= r)
	{
		int mid = (l+r)/2;

		if (arr[mid-1] > arr[mid] && arr[mid+1] > arr[mid])
		{
			return arr[mid];
		}
		else if (arr[mid-1] < arr[mid])
		{
			r = mid - 1;
		}
		else  
		{
			l = mid + 1;
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

    std::cout << local_minima(vec, n);
 
    return 0;
}
