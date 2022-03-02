#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

std::vector<std::vector<int>> subsets(std::vector<int>& vec)
{
    std::vector<std::vector<int>> res;
    int n = vec.size();
    for (int i = 0; i < (1<<n); ++i)
    {
        std::vector<int> sub;
        for (int j = 0; j < n; ++j)
        {
            if ((i & (1<<j)) != 0)
                sub.push_back(vec[j]);
        }
        res.push_back(sub);
    }

    return res;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::vector<int> vec;

    for (int i; ss >> i;)
    {
        if (ss.peek() == ',' || ss.peek() == ' ')
            ss.ignore();

        vec.push_back(i);
    }

    // for (int i = 0; i < vec.size(); ++i)
    // {
    //     std::cout << vec[i] <<" ";
    // }

    auto res = subsets(vec);

    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;

}
