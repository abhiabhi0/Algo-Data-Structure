#include <bits/stdc++.h>

class count_sort
{
  std::map<int, int> m;
  std::map<int, int>::iterator it;

public:

  void counting_sort(std::vector<int>& a){
   for(int i=0; i<a.size(); i++)
   {
    m[a[i]]++;
   }
  }

  void display()
  {
    it = m.begin();
    while(it != m.end())
    {
      for(int i = 0; i < it->second; i++)
      {
        std::cout<<it->first<<" ";
      }
     it++;
   }
   std::cout<<"\n";
  }
};

int main()
{
    count_sort c1;
    std::vector<int>v {2,5,3,0,2,3,0,3};
    std::cout<<"The entered values are \n";
    for(int i = 0; i < v.size(); i++)
    {
      std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
    c1.counting_sort(v);
    std::cout<<"The sorted values \n";
    c1.display();
}
