/*
Made by Andy Saull:
Gyro9 is a class for reading MPU 9250 9-axis (Gyroscope, Accelerometer and Magnetometer).

Using: https://github.com/jrowberg/i2cdevlib
*/

//#define interruptPin 2
#define GYRO_X_CALIBRATION 0
#define GYRO_Y_CALIBRATION 0
#define GYRO_Z_CALIBRATION 0

#define ACC_X_CALIBRATION 0
#define ACC_Y_CALIBRATION 0
#define ACC_Z_CALIBRATION 0

class IMU9
{
    private:
    typedef struct
    {
        float gyroX;
        float gyroY;
        float gyroZ;

        float accX;
        float accY;
        float accZ;

        float magX;
        float magY;
        float magZ;

        float temp;
    } tDataIMU9;
    tDataIMU9 dataIMU9;

    public:
    IMU9();
    void iniIMU9();
    void update();

    float getAngle();

    float getXGForce();
    float getYGForce();
    
    float getCompass();

    float getTemp();
};