#include "MicroBit.h"
#include "inc/neopixel.h"
#include "Adafruit_SSD1306.h"

MicroBit uBit;
Neopixel coucou = Neopixel(MICROBIT_PIN_P0, 2);


int feux(){
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
    return 0;
}

int neopixel(){
    uBit.init();
    while (true) {
        coucou.showColor(1, 0, 0, 0);
        coucou.showColor(0, 255, 0, 0);
        uBit.sleep(1000);
        coucou.showColor(0, 0, 0, 0);
        coucou.showColor(1, 0, 0, 255);
        uBit.sleep(1000);

    }
   while (true) {
        uBit.sleep(1000);
    }
   return 0;
}

int serie() {
    // Initialise le micro:bit runtime
    uBit.init();

    while (true) {
        // Lire les données du capteur de température
        int temperature = uBit.thermometer.getTemperature(); // Obtenir la température en degrés Celsius
        
        // Lire les données de l'accéléromètre (accélération en mg)
        int x = uBit.accelerometer.getX();
        int y = uBit.accelerometer.getY();
        int z = uBit.accelerometer.getZ();

        // Envoyer les données par liaison série
        uBit.serial.printf("Temperature: %d C, Accelerometer: X=%d, Y=%d, Z=%d\r\n", temperature, x, y, z);

        // Attendre 1 seconde avant d'envoyer les prochaines données
        uBit.sleep(1000);
    }
}

int monoDisplay(){
    Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.display();
    delay(1000);

    // Clear the buffer.
    display.clearDisplay();
    display.display();

    // text display tests
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.print("Connecting to SSID\n'adafruit':");
    display.print("connected!");
    display.println("IP: 10.0.1.23");
    display.println("Sending val #0");
    display.setCursor(0,0);
    display.display(); // actually display all of the above
}

int main()
{
    //feux();
    //neopixel();
    //serie();
    monoDisplay():
    return 0;
}

