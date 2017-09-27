/*
	Meanings of result:
	0x01 - 
	0x11 - 

*/

#include <iostream>
using namespace std;


int main();
int timer();

unsigned int time = 0;
unsigned int N = 10000;

int main()
{
	unsigned int time1;
	unsigned int time2;
	// write zero in timer
	
	time1 = timer(); // run timer first time
	
	for (int i=0; i < N; i++)
	{
		
	}
	
	return 0;
}

int timer()
{
	asm(" rdtime x31 ");
	asm(" sw x31, time, x0 "); // write in time
	return time;
}
