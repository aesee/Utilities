/*
	Memory Perfomance Test

	Meanings of result:
	In x31 must be median time in integer

*/

//#include <cmath>

void test1();

unsigned int N = 10000;
long unsigned int s_pointer = 0x10020000;

extern "C"
{
	void setup_stack_pointer(long unsigned int);
	unsigned long int timer(void);
	void write_result(int number);
}

int main()
{
	setup_stack_pointer(s_pointer);

	test1();

	for(;;);

	return 0;
}

void test1()
{
	unsigned long int time1;
	unsigned long int time2;

	// write zero in timer
	//timer_clear();

	time1 = timer(); // run timer first time

	long int memory[N];

	for (int i=0; i < N; i++)
	{
		memory[i] = i+1;
	}

	//timer_clear();
	time2 = timer();

	//result = std::abs((time2 - time1)) / N;
	double result = (double) (time2 - time1) / N;
	long int final = (long int) result;
	write_result(final);

	for(;;);
}
