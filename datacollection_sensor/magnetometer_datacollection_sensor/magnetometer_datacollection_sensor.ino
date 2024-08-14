#include <Arduino_LSM9DS1.h>

// Initialize variables for sensor data that will be needed
float mx, my, mz; // Magnetometer

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
  // Read magnetometer data
  IMU.readMagneticField(mx, my, mz);

  // Create a string with the sensor data in the "x, y, z" format
  String sensorData = String(mx) + ", " + String(my) + ", " + String(mz);

  // Print the data to the serial monitor
  Serial.println(sensorData);

  delay(50); // 20 samples per second for a larger dataset
}
