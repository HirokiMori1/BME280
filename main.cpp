#include "mbed.h"
#include "BME280.h"

Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);

BME280 sensor(p28, p27);


int main() {

    pc.baud(9600);
    while(1) {
        led1 = !led1;
        //pc.printf("%2.2f degC, %04.2f hPa, %2.2f %%\n\r", sensor.getTemperature(), sensor.getPressure(), sensor.getHumidity());
        pc.printf("%4.2f,%4.2f,%4.2f\n", sensor.getTemperature(), sensor.getPressure(), sensor.getHumidity());
        wait(1.0);
    }
}

/*
int main() {
    float pressure = 0.0;

    while(1) {
        led1 = !led1;
        
        pressure = 0.0;
        for(int i = 0; i < 100; i++){
            sensor.getTemperature();
            pressure += sensor.getPressure();
            wait(0.1);
        }
        pressure = pressure / 100.0;

        pc.printf("%5.2f hPa\n\r", pressure);
    }
}
*/