/*
	Meanings of result:
	In x31 must be median time in integer 

*/

using namespace std;


int timer();
void write_result(int number);

unsigned int time = 0;
unsigned int N = 10000;
unsigned int result;

int main()
{
	unsigned int time1;
	unsigned int time2;
	// write zero in timer
	
	time1 = timer(); // run timer first time
	
	long int memory[N];
	
	for (int i=0; i < N; i++)
	{
		memory[i] = i+1;
	}
	
	time2 = timer();
	
	result = (time2 - time1) / N;
	write_result(result);
	
	while (true)
		{ asm(" nop "); }
	
	return 0;
}

int timer()
{
	// asm(" rdtime x31 ");
	// asm(" sw x31, time, x0 "); // write in time
	asm(" csrrs x31, mcycle, x0 "); //write CSR number of cycles
	asm(" lw x31, time ");
	return time;
}

void write_result(int number)
{
	result = number;
	asm(" ld x31, result ");
}
