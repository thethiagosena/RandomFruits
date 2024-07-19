#include <iostream>
#include <string>

using namespace std;

class Fruit
{
private:
    string name;
    int min;
    int max;

public:
    Fruit(string name, int min, int max) : name(name), min(min), max(max) {}

    string getFruitName() { return name; }
    int getFruitMin() { return min; }
    int getFruitMax() { return max; }
};

int main()
{
    Fruit apple("Apple", 1, 10);

    cout << "Fruit name: " << apple.getFruitName() << endl;
    cout << "Min: " << apple.getFruitMin() << endl;
    cout << "Max: " << apple.getFruitMax() << endl;

    return 0;
}
