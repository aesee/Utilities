/*
	Meanings of result:
	0x01 - got interrupt
	0x11 - corruption of memory

*/

#include <iostream>
using namespace std;

//# define stack_pointer %x2 // pointer on register ???
//# define result %x28	   // result of execution

//# define N 3

int result;
int N = 3;

int main();
void error(int number);
void write_result(int number);

int main()
{
	asm(" ld x2, N ");
	
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
	catch(int err)
	{
		error(1);
	}
	
	while (true)
		{ asm(" nop "); }
	
	return 0;
}

void error(int number)
{
	switch(number)
	{
		case 1:
			write_result(0x01);
			break;
		case 2:
			write_result(0x11);
			break;
		default:
			write_result(0x00);
	}
}

void write_result(int number)
{
	result = number;
	asm(" ld x31, result ");
}