//Given a string. Find number of end-start rotation giving the same string

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int count_same_rotation_string(std::string& str)
{
	int s_sz = str.size();
	std::string text = str + str;
	text = str + '$' + text;

	int n = text.size();
	int len = 0, i = 1;
	std::vector<int> lps(n);
	lps[0] = 0;

	int count = 0;
	while (i < n)
	{
		if (text[i] == text[len])
		{
			lps[i] = ++len;
			i++;

			if (len == s_sz)
			{
				count++;
			}
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
	return count-1;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string str;
    std::getline(std::cin, str);
    
    std::cout << count_same_rotation_string(str) << "\n";

    return 0;
}
