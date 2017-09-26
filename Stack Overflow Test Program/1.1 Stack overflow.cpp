/*
	Meanings of result:
	0x01 - got interrupt
	0x11 - corruption of memory

*/

#include <iostream>
using namespace std;

# define stack_pointer %x2 // pointer on register ???
# define result %x28	   // result of execution

# define N 3

int main();
void error(int number);

int main()
{
	try
	{
		int stack[3*N];
	
		for (int i = 0; i < 3*N; i++)
		{
			stack[i] = i+1;
		}
	
		for (int i = 0; i < 3*N; i++)
		{
			if (stack[i] != i+1)
				error(2);
		}
	}
	catch()
	{
		error(1);
	}
	return 0;
}

void error(int number)
{
	switch(number)
	{
		case 1:
			result = 0x01;
			break;
		case 2:
			result = 0x11;
			break;
		default:
			result = 0x00;
	}
}
