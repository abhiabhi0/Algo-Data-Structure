#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int rearrange(std::vector<int>& arr, int l, int r)
{
	int p1 = l+1, p2 = r;

	while (p1 <= p2)
	{
		if (arr[p1] <= arr[l])
		{
			p1++;
		}
		else if (arr[p2] > arr[l])
		{
			p2--;
		}
		else  
		{
			std::swap(arr[p1], arr[p2]);
			p1++;
			p2--;
		}
	}
	std::swap(arr[l], arr[p1-1]);
	return p1-1;
}

void quick_sort(std::vector<int>& arr, int l, int r)
{
	if (l >= r)
		return;

	int index = rearrange(arr, l, r);
	quick_sort(arr, l, index-1);
	quick_sort(arr, index+1, r);
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

    quick_sort(vec, 0, n-1);

    for (int i = 0; i < n; ++i)
    {
    	std::cout << vec[i] <<" ";
    }
    std::cout << "\n";
    return 0;
}
