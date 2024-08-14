#include <Arduino_LSM9DS1.h>

// Initialize variables for sensor data that will be needed
float accelerometerX, accelerometerY, accelerometerZ;
float gyroscopeX, gyroscopeY, gyroscopeZ;

void setup() {
  Serial.begin(115200); // Adjust the baud rate as needed

  // Initialize the IMU sensor
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("IMU Data Logger is ready.");
}

void loop() {
  // Read accelerometer data for printing later on
  IMU.readAcceleration(accelerometerX, accelerometerY, accelerometerZ);

  // Read gyroscope data for printing later on
  IMU.readGyroscope(gyroscopeX, gyroscopeY, gyroscopeZ);

  // Print data to the serial monitor . I will then use areadev.py to extract it from the serial monitor into a csv file
  Serial.print("AccX: "); Serial.print(accelerometerX);
  Serial.print(", AccY: "); Serial.print(accelerometerY);
  Serial.print(", AccZ: "); Serial.print(accelerometerZ);
  Serial.print(", GyroX: "); Serial.print(gyroscopeX);
  Serial.print(", GyroY: "); Serial.print(gyroscopeY);
  Serial.print(", GyroZ: "); Serial.println(gyroscopeZ);

  delay(50); // 20 samples per second for a lartger dataset
}
