#include <iostream>
#include <string>
#include <algorithm>

std::string & removeDuplicate(std::string& str)
{
  int length = str.length();
  for(unsigned int i = 0; i < length; i++)
  {
    char currChar = str[i]; //holds current character
    for(unsigned int j = i+1; j < length; j++)
    {
      if(currChar == str[j])
        str.erase (std::remove(str.begin()+j, str.end(), str[j]), str.end());
    }
  }
  return str;
}

int main()
{
  std::string str;
  std::cout << "Enter string \n";
  std::getline(std::cin, str);
  str = removeDuplicate(str);
  std::cout <<"New String is " << str << "\n";
}
