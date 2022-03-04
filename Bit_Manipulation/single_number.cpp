//In an array, every element appears thrice except one. Find the single number

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int single_number(std::vector<int>& vec, int n)
{
	int ans = 0;
	for (int i = 0; i < 32; ++i)
	{
		int count = 0;
		for (int j = 0; j < n; ++j)
		{
			if ((vec[j]&(1<<i)) != 0)
				count++;
		}

		if (count % 3 == 1)
			ans = (ans | (1<<i));
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

    std::cout << single_number(vec, n) << "\n";

    return 0;
}
