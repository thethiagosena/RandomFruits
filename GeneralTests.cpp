#include <iostream>
#include <string>
#include <map>

using namespace std;

// The minimum part of the code: a fruit.
class Fruit
{
private:
    string name = "fruit";
    int min = 0;
    int max = 1;
    int weight = 1;

public:
    Fruit();
    Fruit(string name, int min, int max, int weight) : name(name), min(min), max(max), weight(weight) {}

    string getFruitName() { return name; }
    int getFruitMin() { return min; }
    int getFruitMax() { return max; }
    int getFruitWeight() { return weight; }
};

// A absket to receive all the necessary fruits.
class FruitBasket
{

private:
    Fruit fruits[7] = {{"Seven", 0, 9, 10},
                       {"Bell", 10, 24, 15},
                       {"Melon", 25, 44, 20},
                       {"Plum", 45, 69, 25},
                       {"Orange", 70, 84, 15},
                       {"Lemon", 85, 94, 10},
                       {"Cherry", 95, 99, 5}};

public:
    Fruit getFruitInBasket(int i) { return fruits[i]; }
    int basketLenght = sizeof(fruits) / sizeof(fruits[0]);
};

int main()
{
    FruitBasket fruitbasket;

    std::cout << fruitbasket.getFruitInBasket(0).getFruitName() << endl;
    cout << fruitbasket.basketLenght << endl;
    return 0;
}