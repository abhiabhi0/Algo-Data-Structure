//Swapping of non-consecutive indices is not allowed

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void count_sort(std::vector<int>& vec, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1-i; ++j)
		{
			if (vec[j] > vec[j+1])
				std::swap(vec[j], vec[j+1]);
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

    count_sort(vec, n);

    for (int i = 0; i < n; ++i)
    {
    	std::cout << vec[i] << "\n";
    }

    return 0;
}
