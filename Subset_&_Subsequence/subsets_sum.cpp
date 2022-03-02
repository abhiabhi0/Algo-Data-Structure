// Find sum of all subsets sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int sum_subsets(std::vector<int>& vec)
{
	int n = vec.size();
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += (vec[i] * (1<<(n-1)));
	}

	return sum;
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
    	if (ss.peek() == ',' || ss.peek() == ' ')
    		ss.ignore();

    	vec.push_back(i);
    }

    std::cout << sum_subsets(vec) << "\n";
    return 0;
}
