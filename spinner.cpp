#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void sleepPlease(unsigned int microseconds)
{
	this_thread::sleep_for(chrono::milliseconds(microseconds));
}

void printFrame(string glifo, unsigned int microseconds)
{
	cout << "\b\b\b\b\b";
	cout << glifo;
	cout.flush();
	sleepPlease(microseconds);
}

void printSpin(int numberOfCycles, unsigned int microseconds)
{
	for (int i = 0; i < numberOfCycles; i++)
	{
		printFrame("|", microseconds);
		printFrame("/", microseconds);
		printFrame("-", microseconds);
		printFrame("\\", microseconds);
	}
	cout << "\b";
}

void printSpinBuble(int numberOfCycles, unsigned int microseconds)
{
	for (int i = 0; i < numberOfCycles; i++)
	{
		printFrame("O", microseconds);
		printFrame("o", microseconds);
		printFrame(".", microseconds);
		printFrame("o", microseconds);
	}
	cout << "\b";
}

void printSpinPort(int numberOfCycles, unsigned int microseconds)
{
	for (int i = 0; i < numberOfCycles; i++)
	{
		printFrame("[   ]", microseconds);
		printFrame("_( )_", microseconds);
		printFrame("__*__", microseconds);
	}
	cout << "\b\b\b\b\b";
}

int main(void)
{
	int op;
	cout << "1 - Spinner" << endl;
	cout << "2 - Buble" << endl;
	cout << "3 - Port" << endl;
	cout << "Your order: ";
	cin >> op;

	const unsigned int microseconds = 80;
	const int numberOfCycles = 5;

	switch (op)
	{
	case 1:
		printSpin(numberOfCycles, microseconds);
		break;
	case 2:
		printSpinBuble(numberOfCycles, microseconds);
		break;
	case 3:
		printSpinPort(numberOfCycles, microseconds*2);
		break;

	default:
		break;
	}
	return 0;
}
