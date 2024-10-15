#include <iostream>
#include <string>
#include <thread>
#include <map>

using namespace std;

// The minimum part of the code: a fruit.
class Fruit
{
private:
	string name;
	int min;
	int max;
	int weight;

public:
	Fruit() {};
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
	Fruit fruits[7] = { {"Seven", 0, 9, 10},
					   {"Bell", 10, 24, 15},
					   {"Melon", 25, 44, 20},
					   {"Plum", 45, 69, 25},
					   {"Orange", 70, 84, 15},
					   {"Lemon", 85, 94, 10},
					   {"Cherry", 95, 99, 5} };

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
	// Created fruit basket.
	FruitBasket fruitBasket;
	Fruit fruit{};

public:
	// Do a random selection of fruits.
	FruitSelector() {};
	Fruit randomFruitSelection(FruitBasket xFruitBasket)
	{
		fruitBasket = xFruitBasket;

		int randomStart = fruitBasket.getFruitInBasket(0).getFruitMin();
		int randomRange = 0;
		for (int i = 0; i < fruitBasket.basketLenght; i++)
		{
			randomRange += fruitBasket.getFruitInBasket(i).getFruitWeight();
		};

		Fruit randomFruit;

		srand((unsigned int)time(NULL));
		int random = randomStart + (rand() % randomRange);

		for (int i = 0; i < fruitBasket.basketLenght; i++)
		{
			if (random >= fruitBasket.getFruitInBasket(i).getFruitMin() && random <= fruitBasket.getFruitInBasket(i).getFruitMax())
			{
				fruit = fruitBasket.getFruitInBasket(i);

			}
		}

		return fruit;
	}
};

int main()
{
	// Fruit that will be drawn
	Fruit selectedFruit{};
	// The basket with the fruits to be randomized
	FruitBasket fruitBasket;
	// The selector to randomize the fruti basket.
	FruitSelector fruitSelector;
	//List of fruits to storage how many times they have been called;
	map <string, int> fruitList;

	//List os frutis contructed based on bastket fruit.
	for (int i = 0; i < fruitBasket.basketLenght; i++) {
		fruitList.insert({ fruitBasket.getFruitInBasket(i).getFruitName(), 0 });
	}

	int randomTries = 15;

	cout<< "------------------------\n" 
		<< "----- Fruits Game! -----\n"
		<< "------------------------\n"
		<< "\n";

	//Draw the fruits.
	for (int i = 1; i <= randomTries; i++)
	{
		selectedFruit = fruitSelector.randomFruitSelection(fruitBasket);
		cout << i << ". Selected fruit: " << selectedFruit.getFruitName() << endl;
		fruitList[selectedFruit.getFruitName()] += 1;
		std::this_thread::sleep_for(2000ms);
	}

	//Show all the fruits and how many times they have been drawn.
	cout << "\nCalled Fruits\n"
		<< "------------------------\n";

	//Read the list of fruits and print how many times it has been drawn
	map<string, int>::iterator fruitItem = fruitList.begin();
	while (fruitItem != fruitList.end()) {
		cout << "#" << fruitItem->first
			<< "\t- \tx" << fruitItem->second << endl;
		++fruitItem;
	}

	cout << "\n "
		<< "------------------------\n\n\n";


	return 0;

}