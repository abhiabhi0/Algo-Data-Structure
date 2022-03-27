#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>

std::string postfix_notation(std::string& str)
{
	std::string res = "";
	std::stack<char> st;
	std::unordered_map<char, int> um;
	um.insert({'*', 4});
	um.insert({'/', 4});
	um.insert({'-', 3});
	um.insert({'+', 3});

	for (char c : str)
	{
		if (c != '+' && c != '-' && c != '*' && c != '/' 
			&& c != '(' && c != ')' )
		{
			res += c;
		}
		else  
		{
			if (st.empty())
			{
				st.push(c);
			}
			else  
			{
				if (c == '(' || um[c] > um[st.top()])
				{
					st.push(c);
				}
				else if (c == ')')
				{
					while (st.top() != '(')
					{
						res += st.top();
						st.pop();
					}

					if (st.top() == '(')
					{
						st.pop();
					}
				}
				else if (um[c] <= um[st.top()])
				{
					while (!st.empty() && um[c] <= um[st.top()])
					{
						res += st.top();
						st.pop();
					}
					st.push(c);
				}
			}
		}
	}

	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}

	return res;
}

int main()
{
	#ifndef FILE_INOUT
 
    	freopen("in.txt", "r", stdin);
 	
    	freopen("out.txt", "w", stdout);
   
	#endif

    std::string str;
    std::cin >> str;
    std::string res = postfix_notation(str);

    std::cout << res << "\n";

    return 0;
}
