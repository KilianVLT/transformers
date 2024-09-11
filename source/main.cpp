#include "MicroBit.h"

MicroBit uBit;

int main()
{
    uBit.init();

    while(1)
    {
        uBit.io.P12.setDigitalValue(0);
        uBit.io.P1.setDigitalValue(1);
        uBit.sleep(3000);
        uBit.io.P1.setDigitalValue(0);
        uBit.io.P2.setDigitalValue(1);
        uBit.sleep(3000);
        uBit.io.P2.setDigitalValue(0);
        uBit.io.P12.setDigitalValue(1);
        uBit.sleep(3000);
    }
    
    release_fiber();
}

