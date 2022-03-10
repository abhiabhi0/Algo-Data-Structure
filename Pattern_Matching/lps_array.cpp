//Given a string of length N. Return LPS array.
//LPS[i] = LPS of substring from index 0 to i.
//LPS - Largest prefix suffix

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> lps_array(std::string& s)
{
	int n = s.size();

	std::vector<int> lps(n);
	lps[0] = 0;

	int len = 0, i = 1;

	while (i < n)
	{
		if (s[i] == s[len])
		{
			lps[i] = ++len;
			i++;
		}
		else  
		{
			if (len != 0)
			{
				len = lps[len-1];
			}
			else  
			{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string str;
    std::getline(std::cin, str);

    auto res = lps_array(str);

    for (int i = 0; i < res.size(); ++i)
    {
    	std::cout << res[i] << " ";
    }

    return 0;
}
