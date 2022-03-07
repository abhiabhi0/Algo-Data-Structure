//Given an array of N elements. Return max(A[i]&A[j]) where i != j
// the pairs

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int max_and_val(std::vector<int>& vec, int n)
{
	int ans = 0;

	//from i = 30 bcoz for if 31st pos is 1 means negative num 
	for (int i = 30; i >= 0; i--)
	{
		int set_bits = 0;
		for (int j = 0; j < n; ++j)
		{
			if ((vec[j] & (1<<i)) != 0)
			{
				set_bits++;
			}
		}

		if (set_bits >= 2)
		{
			ans = (ans | (1<<i));

			for (int j = 0; j < n; ++j)
			{
				if ((vec[j] & (1<<i)) == 0)
				{
					vec[j] = 0;
				}
			}
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
    	std::cin >> vec[i];

    std::cout << max_and_val(vec, n) << "\n";

    return 0;
}
