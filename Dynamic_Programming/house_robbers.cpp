//Maximum sum without adjacent elements

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int max_sum(std::vector<int>& vec)
{
	std::vector<int> money(vec.size());
	money[0] = vec[0];
	money[1] = vec[1];

	for (int i = 2; i < vec.size(); ++i)
	{
		money[i] = std::max(vec[i] + money[i-2], money[i-1]);
	}

	return money[vec.size()-1];
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

    std::cout << max_sum(vec) << "\n";

    return 0;
}
