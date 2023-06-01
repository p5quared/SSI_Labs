#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    { // Searching
        // It is common to desire to search for an element in a container. We can do this using the find function.
        // Let's say we have a CustomVector of ints:
        std::vector<int> v{1, 2, 3, 4, 5};

        // We can use std::find to search for an element in the CustomVector:
        auto it = std::find(v.begin(), v.end(), 3);

        // If the element is found, it will return an iterator to the element. If the element is not found, it will return
        // an iterator to the end of the CustomVector.

        // An iterator is a class containing a pointer to an element in a container.
        // We can dereference an iterator to get the value of the element it points to:
        std::cout << *it << std::endl; // 3

        // We can use iterators like regular pointers to move through a container:
        std::cout << *(it + 1) << std::endl; // 4

        // We can instantiate them by using the begin and end functions:
        auto it3 = v.begin();
        auto it4 = v.end();

        // We can also use the find function to search for an element in a map:
        std::map<std::string, int> m{{"a", 1}, {"b", 2}, {"c", 3}};
        auto it2 = m.find("b");
        std::cout << it2->second << std::endl; // 2

        // We can also use something called destructuring to get the key and value of the element:
        auto [key, value] = *it2;
        std::cout << key << " " << value << std::endl; // b 2
    }

    { // Sorting
        // It is common to desire to sort a container. We can do this using the sort function.
        // Let's say we have a CustomVector of ints:
        std::vector<int> v{5, 4, 3, 2, 1};

        // We can use std::sort to sort the CustomVector:
        std::sort(v.begin(), v.end()); // {1, 2, 3, 4, 5}
    }
    return 0;
}