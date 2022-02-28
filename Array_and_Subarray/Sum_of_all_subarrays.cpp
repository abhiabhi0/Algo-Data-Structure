//Given an array. Return the sum of all possible subarrays.

#include <iostream>
#include <vector>
#include <algorithm>

int subarray_sum(std::vector<int>& vec, int n)
{
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += (vec[i] * (i+1) * (n-i));
	}

	return sum;
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

    std::cout << subarray_sum(vec, n) << "\n";

    return 0;

}
