#include <algorithm>
#include <string>
#include <map>
#include <optional>
#include <regex>

// This struct and distance function are part of the sort example
struct GameEntity
{
    std::string name;
    std::pair<int, int> cur_location;
};
double distanceToPlayer(const GameEntity entity, const GameEntity player)
{
    double dx = entity.cur_location.first - player.cur_location.first;
    double dy = entity.cur_location.second - player.cur_location.second;
    return std::sqrt(dx * dx + dy * dy);
}

// This function is part of the optional example
std::optional<int> divide(int a, int b)
{
    if (b == 0)
        return std::nullopt;

    return a / b;
}



int main()
{
/*
 * This file contains a number of useful tools from the STL.
 */

/*
 * std::pair, std::tuple
 * Usefulness: 4/10 - Not very general, but useful as a tool to make code more readable.
 * Good way to return multiple values from a function.
 */
{
std::pair<int, int> coordinates2d{1, 2};
std::pair<std::string, int> name_age{"Peter", 21};

std::tuple<int, int, int> coordinates3d{1, 2, 3};
std::pair<std::string, std::pair<int,int>> name_coordinates{"Peter", {1, 2}};
}




{
/*
 * std::reverse(), std::count(), std::find()
 * Usefulness: 10/10 - Very useful in a variety of situations.
 *
 */
std::vector<std::string> names{"Peter", "John", "Mary", "Peter", "Peter", "John", "Peter", "Mary", "Mary", "John"};
int count = std::count(names.begin(), names.end(), "Peter"); // 4
auto it = std::find(names.begin(), names.end(), "Peter"); // points to the first "Peter" in the CustomVector
std::string* peter_location = &*it; // points to the first "Peter" in the CustomVector by getting the address of the iterator's location
names.erase(it); // removes the first "Peter" from the CustomVector
}



{
/*
 * std::sort()
 * Usefulness: 10/10 - Very useful in a variety of situations.
 * Basic usage is quite self-explanatory.
 *
 * This more advanced example sorts a vector of game entities by their distance to the player
 */
GameEntity player{"Mario", {3, 10}};

std::vector<GameEntity> computer_entities;
computer_entities.push_back({"Bowser", {18, 1}});
computer_entities.push_back({"Ganon", {5, 5}});
computer_entities.push_back({"Ganondorf", {2, 2}});
computer_entities.push_back({"Waluigi", {1, 1}});
computer_entities.push_back({"Wario", {1, 2}});

// Sort the entities by their distance to the player; we need to use some helper functions seen at end of file
std::sort(computer_entities.begin(), computer_entities.end(), [&](const GameEntity& a, const GameEntity& b){
    double distance_a_to_player = distanceToPlayer(a, player);
    double distance_b_to_player = distanceToPlayer(b, player);
    return distance_a_to_player < distance_b_to_player;
});
// the vector of computer_entities is now sorted by their distance to the player
}



{
    /*
     * std::next_permutation(), std::rotate()
     * Usefulness: 8/10 - Extremely useful in particular situations.
     */
    std::vector<int> v{1, 2, 3, 4};
    std::vector<std::vector<int>> all_permutations;
    do {
        for (int i : v) {
            all_permutations.push_back(v);
        }
    } while (std::next_permutation(v.begin(), v.end()));
    // all_permutations now contains all permutations of the vector v
    // ex: {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, ...}

    // Rotate takes the start, end, and middle of a range and rotates the elements so that the middle is at the start
    std::vector<int> v2{1, 2, 3, 4};
    std::rotate(v2.begin(), v2.begin() + 2, v2.end());
    // v2 is now {3, 4, 1, 2}
}

{
    /*
     * std::optional
     * Usefulness: 7/10 - There are many situations where this makes code more readable, but it is never really necessary.
     * std::optional is a wrapper around a type that may or may not be present.
     * It is useful for returning a value that may not exist.
     *
     * It is better than returning a nullptr or a magic number because it is more explicit.
     *
     * See example function at top!
     */
    std::optional<int> result = divide(10, 0);
    if (result.has_value()) {
        // access the value with result.value()
    }
    else {
        // result.value() throws an exception if the optional does not have a value
    }
}
    {
        /*
         * std::regex (and boost::regex (not part of STL, but much better than std::regex))
         * Usefulness: 10/10 - Very useful for parsing strings.
         *
         * Regular expressions are a powerful tool that are difficult to memorize but there are plenty of resources online
         * to help you build them.
         */
        // This is a basic example, but you can do incredible things with regex.
        std::string s = "Hello, my name is Peter. I am 21 years old.";
        std::regex name_regex("my name is ([A-Za-z]+)");
        std::regex age_regex("I am ([0-9]+) years old");
        std::smatch match;
        std::regex_search(s, match, name_regex);
        std::string name = match[1]; // Peter
        std::regex_search(s, match, age_regex);
        int age = std::stoi(match[1]); // 21
        // name is now "Peter" and age is now 21
    }

}
