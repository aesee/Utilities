#ifndef UART_H
#define UART_H
#include "module.h"


class uart : public module
{
    public:
        uart(int a);
        ~uart() override;

    protected:

    private:
};

#endif // UART_H
