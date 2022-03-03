//Find the length of the longest set of consecutive elements

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include <climits>

int consecutive_seq(std::vector<int>& vec)
{
	std::set<int> st;
	int mx = INT_MIN;

	for (int x : vec)
	{
		st.insert(x);
	}

	for (int x : vec)
	{
		if (st.find(x-1) == st.end())
		{
			int ans = 0;
			int v = x;

			while (st.find(v) != st.end())
			{
				v++;
				ans++;
			}
			mx = std::max(mx, ans);
		}
	}
	return mx;
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

    std::cout << consecutive_seq(vec) << "\n";

    return 0;
}
