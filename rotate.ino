#include <Servo.h>

Servo motor;
int plasticType;

void setup() {
  Serial.begin(9600);
  motor.attach(9); // Attach the servo motor to pin 9
}

void loop() {
  if (Serial.available() > 0) {
    plasticType = Serial.parseInt(); // Read the plastic type from Python

    // Map plastic types to degrees (adjust these values based on your needs)
    int rotationAngle;
    switch (plasticType) {
      case 1: // Linear Low-Density Polyethylene
        rotationAngle = 0;
        break;
      case 2: // High-Density Polyethylene
        rotationAngle = 45;
        break;
      case 3: // Low-Density Polyethylene
        rotationAngle = 90;
        break;
      case 4: // Polystyrene
        rotationAngle = 135;
        break;
      case 5: // Polyvinyl Chloride
        rotationAngle = 180;
        break;
      case 6: // Polypropylene
        rotationAngle = 225;
        break;
      case 7: // Polyethylene Terephthalate
        rotationAngle = 270;
        break;
      default:
        rotationAngle = 0; // Default angle if the plastic type is not recognized
    }

    motor.write(rotationAngle); // Rotate the motor to the specified angle
    delay(1000); // Delay for stability (adjust as needed)
}
}
