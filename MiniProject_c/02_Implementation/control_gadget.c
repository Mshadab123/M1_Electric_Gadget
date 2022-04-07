/*program to control devices using PC parallel port
The devices are controlled by pressing the keys 1-8
that corresponds to each of the 8 possible devices
*/
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#define PORT 0x378 /* This is the parallel port address */
main()
{
    char val = 0, key = 0;
    char str1[] = "ON ";
    char str2[] = "OFF";
    char *str;
    clrscr();
    printf("Press the approriate number key to turn on/off devices:\n\n");
    printf("Here Device1 is connected to D0 of parallel port and so on\n\n");
    printf("Press \"x\" to quit\n\n");
    gotoxy(1, 8);
    printf("Device1:OFF Device2:OFF Device3:OFF Device4:OFF\n");
    printf("Device5:OFF Device6:OFF Device7:OFF Device8:OFF");
    while (key != 'x' && key != 'X')
    {
        gotoxy(1, 12);
        printf("Value in hex sent to the port:");
        key = getch();
        switch (key)
        {
        case '1':
            gotoxy(9, 8);
            val = (val & 0x01) ? (val & (~0x01)) : val | 0x01;
            str = (val & 0x01) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '2':
            gotoxy(21, 8);
            val = (val & 0x02) ? (val & (~0x02)) : val | 0x02;
            str = (val & 0x02) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '3':
            gotoxy(33, 8);
            val = (val & 0x04) ? (val & (~0x04)) : val | 0x04;
            str = (val & 0x04) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '4':
            gotoxy(45, 8);
            val = (val & 0x08) ? (val & (~0x08)) : val | 0x08;
            str = (val & 0x08) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '5':
            gotoxy(9, 9);
            val = (val & 0x10) ? (val & (~0x10)) : val | 0x10;
            str = (val & 0x10) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '6':
            gotoxy(21, 9);
            val = (val & 0x20) ? (val & (~0x20)) : val | 0x20;
            str = (val & 0x20) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '7':
            gotoxy(33, 9);
            val = (val & 0x40) ? (val & (~0x40)) : val | 0x40;
            str = (val & 0x40) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", val);
            break;
        case '8':
            gotoxy(45, 9);
            val = (val & 0x80) ? (val & (~0x80)) : val | 0x80;
            str = (val & 0x80) ? str1 : str2;
            printf("%s", str);
            outportb(PORT, val);
            gotoxy(1, 13);
            printf("%x", (unsigned char)val);
            break;
        }
    }
}