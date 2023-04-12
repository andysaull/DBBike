/*
Made by Andy Saull:
Gyro6 is a class for reading MPU 6050 6-axis (Gyroscope and Accelerometer).

Using: https://github.com/jrowberg/i2cdevlib
*/

//#define interruptPin 2
#define GYRO_X_CALIBRATION 0
#define GYRO_Y_CALIBRATION 0
#define GYRO_Z_CALIBRATION 0

#define ACC_X_CALIBRATION 0
#define ACC_Y_CALIBRATION 0
#define ACC_Z_CALIBRATION 0

class IMU6
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

        float temp;
    } tDataIMU6;
    tDataIMU6 dataIMU6;

    public:
    IMU6();
    void iniIMU6();
    void update();
    float getAngle();
    float getXGForce();
    float getYGForce();

    float getTemp();
};