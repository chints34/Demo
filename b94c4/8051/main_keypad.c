#include<reg51.h>
#include"keypad.h"
#define leds P1
main()
{
while(1)
{
leds=~keyscan();

}


}
