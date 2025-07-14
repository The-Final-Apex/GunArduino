#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int triggerPin = 2;
const int reloadPin = 3;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(triggerPin, INPUT_PULLUP);
  pinMode(reloadPin, INPUT_PULLUP);

  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  Serial.println("READY");
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert gyroscope values to simplified tilt (just demo purposes)
  float tiltX = gx / 131.0;  // degrees/sec
  float tiltY = gy / 131.0;

  // Buttons
  bool trigger = digitalRead(triggerPin) == LOW;
  bool reload = digitalRead(reloadPin) == LOW;

  // Output as CSV: action, tiltX, tiltY
  if (trigger) {
    Serial.print("SHOOT,");
  } else if (reload) {
    Serial.print("RELOAD,");
  } else {
    Serial.print("MOVE,");
  }

  Serial.print(tiltX, 2);
  Serial.print(",");
  Serial.println(tiltY, 2);

  delay(50); // small delay for serial stability
}

