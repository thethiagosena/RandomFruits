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

// It will randomize the fruits and select on.
// It will also do a sequencial list of dawn fruits and
// count how many times each fruit was drew.
class FruitSelector
{
private:
    // Sequential list of draw fruits.
    map<int, Fruit> drewFruits;

    // Dictionary of draw fruits and respective amount per fruit
    map<Fruit, int> fruitsCounter;

    // Created fruit basket.
    FruitBasket fruitBasket;

public:
    // Do a random selection of fruits.
    Fruit randomFruitSelection(FruitBasket xFruitBasket)
    {
        FruitBasket fruitbasket = xFruitBasket;

        int offset = fruitBasket.getFruitInBasket(0).getFruitMin();
        int range = 0;
        for (int i = 0; i = (fruitBasket.basketLenght - 1); i++)
        {
            range += fruitBasket.getFruitInBasket(i).getFruitWeight();
            cout << "Range: " << range << endl;
        };

        Fruit randomFruit;

        srand((unsigned int)time(NULL));
        int random = offset + (rand() % range);

        for (int i = 0; i = (fruitBasket.basketLenght - 1); i++)
        {
            if (random >= fruitBasket.getFruitInBasket(i).getFruitMin() && random < fruitBasket.getFruitInBasket(i).getFruitMax())
            {
                return fruitBasket.getFruitInBasket(i);
            }
        }
        /*
                if (random >= 0 && random <= 9)
                {
                    return fruitBasket.getFruitInBasket(0);
                }
                else if (random >= 10 && random <= 24)
                {
                    return fruitBasket.getFruitInBasket(1);
                }
                else if (random >= 25 && random <= 44)
                {
                    return fruitBasket.getFruitInBasket(2);
                }
                else if (random >= 45 && random <= 69)
                {
                    return fruitBasket.getFruitInBasket(3);
                }
                else if (random >= 70 && random <= 84)
                {
                    return fruitBasket.getFruitInBasket(4);
                }
                else if (random >= 85 && random <= 94)
                {
                    return fruitBasket.getFruitInBasket(5);
                }
                else
                {
                    return fruitBasket.getFruitInBasket(6);
                }

                return randomFruit;*/
    };

    // Getter and Setter for the drewFruits, which do a sequential list of every drawn fruit.
    map<int, Fruit> getDrewFruits()
    {
        return drewFruits;
    };

    void addDrawnFruit()
    {
    }

    void removeDrawnFruit()
    {
    }

    // Getter and Setter for fruitCounter, which count how many fruits of each type were drawn.
    map<Fruit, int> getFruitsCounter()
    {
        return fruitsCounter;
    }

    void addSelectedFruit()
    {
    }

    void removeSelectedFruit()
    {
    }
};

int main()
{
    FruitBasket fruitbasket;

    std::cout << fruitbasket.getFruitInBasket(0).getFruitName() << endl;
    return 0;
}