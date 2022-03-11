//Find total pairs (i, j) such that i < j && A[i] > A[j] 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int merge(std::vector<int>& vec, int l, int y, int r)
{
	int a = l;
	int b = y;
	int c = 0, count = 0;
	std::vector<int> tmp(r-l+1);

	while (a < y && b <= r)
	{
		if (vec[a] <= vec[b])
		{
			tmp[c++] = vec[a++];
		}
		else  
		{
			tmp[c++] = vec[b++];
			count = count + (y - a);	
		}
	}

	while (a < y)
		tmp[c++] = vec[a++];

	while (b <= r)
		tmp[c++] = vec[b++];

	c = 0;
	for (int i = l; i <= r; ++i)
		vec[i] = tmp[c++];

	return count;
}

int inversion_count(std::vector<int>& vec, int l, int r)
{

	if (l < r)
	{
		int mid = (l+r)/2;
		
		int x = inversion_count(vec, l, mid);
		int y = inversion_count(vec, mid+1, r); 
		int z = merge(vec, l, mid+1, r);

		return x+y+z;
	}

	return 0;
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

    std::cout << inversion_count(vec, 0, n-1) << "\n";

    return 0;
}
