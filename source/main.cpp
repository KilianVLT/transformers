/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"

MicroBit uBit;
MicroBitThermometer thermometer;
int i = 0;
int degree = 0;

void increment(MicroBitEvent e){
    i++;
    if(i>=10){
        uBit.display.scroll(i);
    }
    else{
        uBit.display.print(i);
    }
}

void temperature(MicroBitEvent e){
    uBit.display.scroll(thermometer.getTemperature());
}

void compass(MicroBitEvent e){
    degree = uBit.compass.heading();

    if((degree >= 0 && degree <= 50) || (degree >= 310 && degree <= 360)){
        uBit.display.print('N');
    }
    
    else if(degree > 50 && degree <= 100){
        uBit.display.print('E');
    }
    
    else if(degree >= 260 && degree < 310){
        uBit.display.print('W');
    }

    else{
        uBit.display.print('S');
    }
}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_TILT_LEFT, increment);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, temperature);
    uBit.messageBus.listen(MICROBIT_ID_COMPASS, MICROBIT_COMPASS_EVT_DATA_UPDATE, compass);

    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

