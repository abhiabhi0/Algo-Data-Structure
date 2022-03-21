// Remove any 2 consecutive duplicate characters

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

std::string remove_consecutive_duplicates(std::string& str)
{
	std::stack<char> st;
	std::string res = "";

	for (char c : str)
	{
		if (st.empty())
		{
			st.push(c);
		}
		else  
		{
			if (st.top() == c)
			{
				st.pop();
			}
			else  
			{
				st.push(c);
			}
		}
	}

	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	std::reverse(res.begin(), res.end());

	return res;
} 

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string str = "abcdeedcaabxxdad";
    std::string res = remove_consecutive_duplicates(str);

    std::cout << res;
    return 0;
}
