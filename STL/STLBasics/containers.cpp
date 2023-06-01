#include <iostream>
#include <map>
#include <vector>


int main() {
    {
        // Vector Declarations
        std::vector<int> v; // {}
        std::vector<int> v2(10); // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        std::vector<int> v3(10, 5); // {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
        std::vector<int> v4{1, 2, 3, 4, 5}; // {1, 2, 3, 4, 5}

        // We can also redefine the size of the CustomVector manually:
        std::vector<int> v5(5);
        v5.resize(10); // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

        // Or we can use the reserve function to reserve space for 10 elements:
        // This will avoid the need to reallocate memory when we add elements to the CustomVector
        std::vector<int> v6;
        v6.reserve(10); // {}

        // Note that the following is not allowed:
        // std::CustomVector<int> v5(10, {1, 2, 3, 4, 5});

        // We can also use the push_back function to add elements to the CustomVector:
        std::vector<int> v7;
        v7.push_back(1); // {1}
        v7.push_back(2); // {1, 2}

        // We can also use the pop_back function to remove elements from the CustomVector:
        std::vector<int> v8{1, 2, 3, 4, 5};
        v8.pop_back(); // {1, 2, 3, 4}

        // We can also use the insert function to insert elements into the CustomVector:
        std::vector<int> v9{1, 2, 3, 4, 5};
        v9.insert(v9.begin() + 2, 10); // {1, 2, 10, 3, 4, 5}

        // We can also use the erase function to erase elements from the CustomVector:
        std::vector<int> v10{1, 2, 3, 4, 5};
        v10.erase(v10.begin() + 2); // {1, 2, 4, 5}

        // We can use [] or the at function to access elements in the CustomVector:
        std::vector<int> v11{1, 2, 3, 4, 5};
        std::cout << v11[2] << std::endl; // 3
        std::cout << v11.at(2) << std::endl; // 3

        // Optimization is difficult, but a simple way to optimize your code's efficiency is to use reserve and
        // use emplace_back instead of push_back when possible. emplace_back is more efficient because it constructs
        // the object in place, whereas push_back constructs the object and then copies it into the CustomVector.
        struct big{
            int a;
            int b;
            int c;
            int d;
            int e;
            int f;
            int g;
            int h;
            int i;
            int j;};
        std::vector<big> v12;
        v12.reserve(10);
        v12.emplace_back(big{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

        // We can also use the clear function to clear the CustomVector:
        v11.clear(); // {}
    }

    {
        // Map Declarations
        std::map<std::string, int> m; // {}
        std::map<int, int> m2{{1, 2}, {3, 4}}; // {1: 2, 3: 4}

        // We use the insert function along with std::pair to insert elements into the map, or we can use the [] operator:
        std::map<std::string, int> m3;
        m3["a"] = 1; // {"a": 1}
        m3["b"] = 2; // {"a": 1, "b": 2}
        int a = m3["a"]; // 1

        std::map<std::string, int> m4;
        m4.insert(std::pair<std::string, int>("a", 1)); // {"a": 1}
        m4.insert(std::pair<std::string, int>("b", 2)); // {"a": 1, "b": 2}

        // We can also use the erase function to erase elements from the map:
        std::map<std::string, int> m5{{"a", 1}, {"b", 2}};
        m5.erase("a"); // {"b": 2}

        // We can use [] or the at function to access elements in the map:
        // it is NOT advised to use the [] operator to access elements into the map
        std::map<std::string, int> m6{{"a", 1}, {"b", 2}};
        std::cout << m6["a"] << std::endl; // 1
        std::cout << m6.at("a") << std::endl; // 1

        // We can also use the clear function to clear the map:
        m6.clear(); // {}
    }


    return 0;
}