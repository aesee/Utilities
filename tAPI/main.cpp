#include <iostream>
#include "module.h"
#include "gost.h"
#include "uart.h"
#include <list>
#include <vector>
#include <memory>
//#include <boost>

void foo(module* obj)
{
    std::cout << "What's here: " << obj->something << std::endl;
}

int main()
{
//    module A, *pA;
    gost B(8); //, *pB;
    uart C(11); //, *pC;
//    pA = &A;
    //pB = &B;
    //pC = &C;
    //std::list<module> config = {*pA,*pB,*pC};

    //list<module>::iterator it = config.begin();
    //std::advance(it,3);

    //std::vector<module*> config = {  *pB, *pC };
    std::vector<module*> config = {  &B, &C };

    foo(&B);

    //std::cout << "config[1] = " << config << std::endl;
    std::cout << "config[1] = " << (*config[1]).id << std::endl;
    std::cout << "Ok!" << std::endl;
    return 0;
}

// шаблон
template <typename typed, size_t n> int getSize(typed (&a)[n])
{
	int count = 0;
	for (size_t q=0; q<n; ++q)
		count++;
	return count;
}

