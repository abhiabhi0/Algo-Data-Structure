//Count all permutations of string A in another string B

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

bool window_equal(std::string& a, std::unordered_map<char, int>& req_count, 
	std::unordered_map<char, int>& curr_count)
{
	for (char c : a)
	{
		if (req_count[c] != curr_count[c])
			return false;
	}
	return true;
}

int count_permutations(std::string& a, std::string& b)
{
	std::unordered_map<char, int> req_count, curr_count;
	for (char c : a)
	{
		if (req_count.find(c) != req_count.end())
		{
			req_count[c]++;
		}
		else  
		{
			req_count.insert({c, 1});
		}
	}

	// std::cout << "Req : \n";
	// for (auto it : req_count)
	// {
	// 	std::cout << it.first << " : " << it.second << " "; 
	// }
	// std::cout << "\n";

	for (int i = 0; i < a.size(); ++i)
	{
		if (curr_count.find(b[i]) != curr_count.end())
		{
			curr_count[b[i]]++;
		}
		else  
		{
			curr_count.insert({b[i], 1});
		}
	}

	// std::cout << "Curr : \n";
	// for (auto it : curr_count)
	// {
	// 	std::cout << it.first << " : " << it.second << " "; 
	// }
	// std::cout << "\n";

	int count = 0;

	if (window_equal(a, req_count, curr_count))
	{
		count++;
	}

	for (int i = 1; i <= (b.size()-a.size()); ++i)
	{
		curr_count[b[i-1]]--;

		if (curr_count.find(b[i+a.size()-1]) != curr_count.end())
		{
			curr_count[b[i+a.size()-1]]++;
		}
		else  
		{
			curr_count.insert({b[i+a.size()-1], 1});
		}

		if (window_equal(a, req_count, curr_count))
		{
			count++;
		}
	}

	return count;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    std::cout << count_permutations(a, b) << "\n";

    return 0;
}
