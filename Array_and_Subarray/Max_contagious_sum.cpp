#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>

int max_contagious_sum(std::vector<int>& vec)
{
	int ans = INT_MIN, sum = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		sum += vec[i];
		ans = std::max(ans, sum);

		if (sum < 0)
			sum = 0;
	}
	return ans;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string input;
    std::getline(std::cin, input);

    std::vector<int> vec;

    std::stringstream ss(input);
    for (int i; ss >> i;)
    {
    	vec.push_back(i);

    	if (ss.peek() == ',' || ss.peek() == ' ')
    		ss.ignore();
    }

    std::cout << max_contagious_sum(vec) << "\n";

    return 0;
}
