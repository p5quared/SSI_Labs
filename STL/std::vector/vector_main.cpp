#include <iostream>
#include "vector.h"

int main() {
    psv::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }

    class car{
    public:
        car(int speed, int year, std::string name) : speed(speed), year(year), name(name) {}
        car() = default;
        int speed{};
        int year{};
        std::string name;
    };

    psv::vector<car> cars;
    cars.push_back({100, 2010, "Toyota"});
    cars.push_back({200, 2015, "Honda"});
    cars.emplace_back(300, 2020, "Tesla");

    for (int i = 0; i < cars.size(); ++i) {
        std::cout << cars[i].speed << " " << cars[i].year << " " << cars[i].name << std::endl;
    }




    return 0;
}
