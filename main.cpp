#include "mbed.h"
#include "MPU6050.h"
//creating an object of serial class
//so that we can communicate with PC
Serial pc(SERIAL_TX, SERIAL_RX);
//setting LED1 to give digital output
DigitalOut myled(LED1);
//creating onject of MPU6050 class
MPU6050 ark(PB_8,PB_9);
int main()
{
    while(1) {

        //reading Temprature
        float temp = ark.getTemp();
        pc.printf("temprature = %0.2f ^C\r\n",temp);
        
        //reading Grometer readings
        float gyro[3];
        ark.getGyro(gyro);
        pc.printf("Gyro0=%f,\tGyro1=%f,\tGyro2=%f\r\n",gyro[0],gyro[1],gyro[2]);
        
        //reading Acclerometer readings
        float acce[3];
        ark.getAccelero(acce);
        pc.printf("Acce0=%f,Acce1=%f,Acce2=%f\r\n",acce[0],acce[1],acce[2]);

        wait(1); //wait 1000ms
    }
}
