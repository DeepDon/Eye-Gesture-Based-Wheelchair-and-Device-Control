```c
#include <htc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Motor output macro definitions */
#define stop  {RB7 = 0; RB4 = 0;}
#define front {RB6 = 1; RB5 = 1; DelayMs(200); RB7 = 1; RB4 = 1;}
#define back  {RB6 = 0; RB5 = 0; DelayMs(200); RB7 = 1; RB4 = 1;}
#define right {RB6 = 0; RB5 = 1; DelayMs(200); RB7 = 0; RB4 = 1;}
#define left  {RB6 = 1; RB5 = 0; DelayMs(200); RB7 = 1; RB4 = 0;}

void DelayMs(unsigned long i);
void DelayUs(unsigned long i);
void init_com1(void);
void putc_com1(unsigned char data);
unsigned char getc_com1(void);

void main(void)
{
    unsigned char data, flag;
    PORTB = 0x00;
    DelayMs(1000);
    ADCON1 = 0x07;
    TRISB = 0x00;
    PORTB = 0x00;

    init_com1();
    flag = 0;

    while(1)
    {
        data = getc_com1();

        if(data == 'U')
        {
            stop;
            front;
            flag = 1;
        }
        if(data == 'S')
        {
            stop;
            flag = 0;
        }
        if((data == 'L') && (flag))
        {
            stop;
            left;
        }
        if((data == 'R') && (flag))
        {
            stop;
            right;
        }
        if(data == 'D')
        {
            stop;
            back;
            flag = 1;
        }
    }
}

void DelayMs(unsigned long i)
{
    unsigned int count;
    while(i--)
    {
        for(count = 0; count < 405; count++) {}
    }
}

void DelayUs(unsigned long i)
{
    while(i--) {}
}

void init_com1(void)
{
    TRISC6 = 0; // TX1
    TRISC7 = 1; // RX1
    SPBRG = 129; // 9600 Baud Rate @ 20MHz
    RCSTA = 0b10010000; // CREN enabled
    TXSTA = 0b00100100;
}

void putc_com1(unsigned char data)
{
    while(!TXIF) continue;
    TXREG = data;
}

unsigned char getc_com1(void)
{
    CREN = 1;
    while(!RCIF) continue;
    CREN = 0;
    return RCREG;
}
