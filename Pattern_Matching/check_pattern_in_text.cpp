//Given a text of length N and a pattern of length M. 
//Check if the pattern exists in the text. (N >> M)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool check_pattern(std::string& pattern, std::string& text)
{
	text = pattern + '$' + text;

	int n = text.size();
	int len = 0, i = 1;
	std::vector<int> lps(n);
	lps[0] = 0;

	while (i < n)
	{
		if (text[i] == text[len])
		{
			lps[i] = ++len;
			i++;

			if (len == pattern.size())
			{
				return true;
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
	return false;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string pattern, text;
    std::getline(std::cin, pattern);
    std::getline(std::cin, text);
    
    std::cout << check_pattern(pattern, text) << "\n";

    return 0;
}
