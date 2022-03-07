//Given an array of N elements. Calculate the sum of xor of all
// the pairs

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int sum_xor_pairs(std::vector<int>& vec, int n)
{
	int sum = 0;
	for (int i = 0; i < 32; ++i)
	{
		int count_1 = 0;
		for (int j = 0; j < n; ++j)
		{
			// std::cout << "i : " << i << " vec[j] : " << vec[j] << "\n";
			// std::cout << (vec[j]&(1<<i)) << "\n";
			if ((vec[j]&(1<<i)) != 0)
			{
				count_1++;
			}
		}
		sum = sum + ((count_1 * (n - count_1)) * (1<<i));
	}

	return (sum*2);
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
    	std::cin >> vec[i];

    std::cout << sum_xor_pairs(vec, n) << "\n";

    return 0;
}
