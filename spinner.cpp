#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void sleepPlease(unsigned int microseconds)
{
	this_thread::sleep_for(chrono::milliseconds(microseconds));
}

void printFrame(char glifo, unsigned int microseconds)
{
	cout << "\b";
	cout << glifo;
	cout.flush();
	sleepPlease(microseconds);
}

void printSpin(int numberOfCycles, unsigned int microseconds)
{
	for (int i = 0; i < numberOfCycles; i++)
	{
		printFrame('|', microseconds);
		printFrame('/', microseconds);
		printFrame('-', microseconds);
		printFrame('\\', microseconds);
	}
}

void printSpinBuble(int numberOfCycles, unsigned int microseconds)
{
	for (int i = 0; i < numberOfCycles; i++)
	{
		printFrame('O', microseconds);
		printFrame('o', microseconds);
		printFrame('.', microseconds);
		printFrame('o', microseconds);
	}
}

int main(void)
{
	const unsigned int microseconds = 80;
	const int numberOfCycles = 10;
	printSpinBuble(numberOfCycles, microseconds);

	return 0;
}
