//Given an array and Q queries. In every query you get start and end index
//of a subarray. Print the sum of the subarray for every query.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> prefix_sum_array(std::vector<int>& vec, int n)
{
	std::vector<int> ps(n);
	ps[0] = vec[0];

	for (int i = 1; i < n; ++i)
	{
		ps[i] = ps[i-1] + vec[i];	
	}

	return ps;
}

int subarray_sum(std::vector<int>& ps, int start, int end)
{
	return (ps[end] - ps[start-1]);
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

    std::vector<int> ps = prefix_sum_array(vec, n);

    int q;
    std::cin >> q;

    while (q--)
    {
    	int s, e;
    	std::cin >> s >> e;

    	std::cout << subarray_sum(ps, s, e) << "\n";
    }


    return 0;
}
