#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> decimal_to_binary(int n)
{
	std::vector<int> binary;

	while (n)
	{
		if (n % 2 == 1)
			binary.push_back(1);
		else  
			binary.push_back(0);

		n = (n >> 1);
	}
	std::reverse(binary.begin(), binary.end());

	return binary;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    int n;
    std::cin >> n;

    std::vector<int> r = decimal_to_binary(n);

    for (int x : r)
    	std::cout << x;

    return 0;

}
