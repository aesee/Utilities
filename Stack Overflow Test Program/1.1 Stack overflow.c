# include <stdio.h>
# include <stdlib.h>

# define N 3

int main();
int recursive(long int iteration);

long int counter;

int main()
{
		counter = 1;
		//long int a = recursive(1);
		long int a = recursive(counter);
		long int result = a * 3 * 4;
	
	// return 0;
	return result;
}

int recursive(long int iteration)
{
	//int *ptr = calloc(iteration*N, sizeof(int));
	//if (malloc(sizeof(int)*iteration*N) == NULL) 
	if (malloc(sizeof(int)*iteration*N) == NULL) 
	return counter;
	int locals[iteration * N];
	for (int i = 0; i < iteration * N; i++)
	{
		locals[i] = i + 1;
	}
	
	for (int i = 0; i < iteration * N; i++)
	{
		if (locals[i] != i + 1)
			return iteration;
	}
	
	//free(sizeof(int)*iteration*N);
	counter += 1;
	return recursive(counter);
}
