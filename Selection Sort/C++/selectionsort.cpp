#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <iterator>

 template <typename ForwardItr>
 void selectionSort(ForwardItr first, ForwardItr last)
 {
   while(first != last)
   {
     ForwardItr min = std::min_element(first, last);
       std::iter_swap(min, first);
     ++first;
   }
 }

 template <typename Itr>
 void print(Itr first, Itr last)
 {
   while(first != last)
   {
     std::cout << *first <<" ";
     ++first;
   }
   std::cout << "\n";
 }

 int main()
 {
   std::vector<int> v({5, 3, 12, 2, 8});
   std::cout << "Original Array :";
   print(v.begin(), v.end());
   selectionSort(v.begin(), v.end());
   std::cout <<"Sorted Array :";
   print(v.begin(), v.end());
   std::cout << '\n';

   std::vector<char> c({'t', 'q', 'a', 'r', 'p'});
   std::cout << "Original Array :";
   print(c.begin(), c.end());
   selectionSort(c.begin(), c.end());
   std::cout <<"Sorted Array :";
   print(c.begin(), c.end());
   std::cout << '\n';

   std::vector<std::string> str({"code", "live", "love", "sing", "create"});
   std::cout << "Original Array :";
   print(str.begin(), str.end());
   selectionSort(str.begin(), str.end());
   std::cout <<"Sorted Array :";
   print(str.begin(), str.end());
   std::cout << '\n';

}
