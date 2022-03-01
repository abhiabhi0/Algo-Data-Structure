//Return number of subarrays with sum = 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int subarrays_0_sum(std::vector<int>& vec, int n)
{
    int count0 = 0;
    std::vector<int> ps(n);
    std::unordered_map<int, int> um;

    ps[0] = vec[0];

    um.insert({ps[0], 1});

    for (int i = 1; i < n; ++i)
    {
        ps[i] = ps[i-1] + vec[i];

        if (vec[i] == 0)
        {
            count0++;
        }

        if (um.find(ps[i]) != um.end())
        {
            um[ps[i]]++;
        }
        else  
        {
            um.insert({ps[i], 1});
        }
    }

    for (auto it : um)
    {
        if (it.first == 0)
            count0 += it.second;
        else 
        {
            if (it.second > 1)
            {
                count0 += (it.second/2);
            }
        }      
    }

    return count0;
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

    std::cout << subarrays_0_sum(vec, n) << "\n";

    return 0;

}
