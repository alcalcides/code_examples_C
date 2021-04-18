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

int app () {
	int op;
	do
	{
		cout << endl;
		cout << "1 - Spinner" << endl;
		cout << "2 - Buble" << endl;
		cout << "3 - Port" << endl;
		cout << "0 - EXIT" << endl;
		cout << "Your order: ";
		cout.flush();
		cin >> op;
	} while (op < 0 || op > 3);

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
		printSpinPort(numberOfCycles, microseconds * 2);
		break;

	default:
		break;
	}
	return op;
}

int main(void)
{
	int op;
	do{
		op = app();
	} while(op != 0);

	return 0;
}
