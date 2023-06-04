#include <iostream>
#include <vector>
#include <algorithm>

bool ascendingComparison(int a, int b) {
    return a < b;
}

bool descendingComparison(int a, int b) {
    return a > b;
}

namespace psv
{

template<typename Iterator, typename Compare>
void mySort(Iterator begin, Iterator end, Compare cmp) {
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = i + 1; j != end; ++j) {
            if (cmp(*j, *i)) {
                std::iter_swap(i, j);
            }
        }
    }
}

}

int main() {
    std::vector<int> numbers = {4, 2, 7, 1, 5};

    // Sort the vector using the ascending custom sort function
    psv::mySort(numbers.begin(), numbers.end(), ascendingComparison);
    std::cout << "Ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the vector using the descending custom sort lambda function (c++11 feature)
    psv::mySort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    std::sort(numbers.begin(), numbers.end() );

    std::cout << "Descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
