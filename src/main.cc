#include "bounded_stack.h"
#include "bounded_queue.h"
#include "circular_queue.h"

#include <iostream>
#include <string>

using namespace algorithmic;

struct Bitches
{
	int a;
};

char* ReverseString(char* string)
{
	int num_chars = 0;
	while (true)
	{
		if (string[num_chars] != '\0')
			num_chars++;
		else
			break;
	}

	BoundedStack<char> tempStack(num_chars);

	for (int i = 0; i < num_chars; i++)
	{
		char* c = &(string[i]);
		tempStack.Push(c);
	}

	char* reversedString = new char[num_chars + 1];
	for (int i = 0; i < num_chars; i++)
	{
		reversedString[i] = *(tempStack.Pop());
	}

	reversedString[num_chars] = '\0';

	return reversedString;
}

int main(int argc, char** argv)
{
	std::cin.get();
}





