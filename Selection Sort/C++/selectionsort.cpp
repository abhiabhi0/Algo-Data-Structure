#include <iostream>
#include <vector>

template<typename T>
void selection_sort(std::vector<T>& array)
{
    typedef typename std::vector<T>::iterator Itr;
    Itr itr = array.begin();
    while(itr != array.end())
    {
        Itr itr_min = itr;
        for(Itr i = itr + 1; i != array.end(); i++)
        {
            if(*i < *itr_min)
            {
                itr_min = i;
            }
        }
        std::iter_swap(itr, itr_min);
        itr++;
    }
}

template<typename T>
void print(const std::vector<T>& array)
{
    for(auto itr = array.begin(); itr != array.end(); itr++)
    {
       std::cout << *itr << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> v({5, 3, 12, 2, 8});
    std::cout << "Original Array :";
    print(v);
    selection_sort(v);
    std::cout <<"Sorted Array :";
    print(v);
    std::cout << '\n';

    std::vector<char> c({'t', 'q', 'a', 'r', 'p'});
    std::cout << "Original Array :";
    print(c);
    selection_sort(c);
    std::cout <<"Sorted Array :";
    print(c);
    std::cout << '\n';

    std::vector<std::string> str({"code", "live", "love", "sing", "create"});
    std::cout << "Original Array :";
    print(str);
    selection_sort(str);
    std::cout <<"Sorted Array :";
    print(str);
    std::cout << '\n';
}

