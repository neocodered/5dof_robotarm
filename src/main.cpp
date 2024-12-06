#include <Arduino.h>
#include <Servo.h>

// Create servo objects for 6 servos
Servo servo1, servo2, servo3, servo4, servo5, servo6;

int InitFixedAngles[6] = {94, 90, 94, 126, 108, 125};

// Current angles of servos
int currentAngles[6] = {94, 90, 94, 126, 108, 125}; // Initial positions (degrees)

// Target angles for servos
int targetAngles[6] = {94, 90, 94, 126, 108, 125}; // Set target angles here

// Speed for each servo (degrees per update step)
int servoSpeeds[6] = {1, 1, 1, 1, 1, 1}; // Adjust speed as needed

// Servo pins
const int servoPins[6] = {3, 5, 6, 9, 10, 11}; // Connect your servos to these pins

bool updateServoPositions();
void setServoAngle(int index, int angle);

void setup() {
  // Attach servos to pins
  servo1.attach(servoPins[0]);
  servo2.attach(servoPins[1]);
  servo3.attach(servoPins[2]);
  servo4.attach(servoPins[3]);
  servo5.attach(servoPins[4]);
  servo6.attach(servoPins[5]);

  // Set initial positions
  for (int i = 0; i < 6; i++) {
    setServoAngle(i, currentAngles[i]);
  }
}

void loop() {
  // Update servo angles smoothly
  bool movementComplete = updateServoPositions();

  // Example of dynamically changing target angles and speed
  if (movementComplete) {
    // New target angles (example)
    targetAngles[0] = InitFixedAngles[0] - 26.2;
    targetAngles[1] = InitFixedAngles[1] - 43.94;
    targetAngles[2] = InitFixedAngles[2] + 70.39;
    targetAngles[3] = InitFixedAngles[3] - 158.44;
    targetAngles[4] = InitFixedAngles[4];
    targetAngles[5] = 125;
    
    // targetAngles[0] = random(60, 120);
    // targetAngles[1] = random(60, 120);
    // targetAngles[2] = random(60, 120);
    // targetAngles[3] = random(60, 120);
    // targetAngles[4] = random(60, 120);
    // targetAngles[5] = random(125, 175);

    // // Change speeds (example)
    // servoSpeeds[0] = random(1, 2);
    // servoSpeeds[1] = random(1, 2);
    // servoSpeeds[2] = random(1, 2);
    // servoSpeeds[3] = random(1, 2);
    // servoSpeeds[4] = random(1, 2);
    // servoSpeeds[5] = random(1, 2);

    delay(2000); // Wait 2 seconds before moving to the next position
  }
}

bool updateServoPositions() {
  bool allReached = true;

  for (int i = 0; i < 6; i++) {
    if (currentAngles[i] != targetAngles[i]) {
      allReached = false;

      // Calculate the step direction
      if (currentAngles[i] < targetAngles[i]) {
        currentAngles[i] = min(currentAngles[i] + servoSpeeds[i], targetAngles[i]);
      } else {
        currentAngles[i] = max(currentAngles[i] - servoSpeeds[i], targetAngles[i]);
      }

      // Update the servo angle
      setServoAngle(i, currentAngles[i]);
    }
  }

  delay(20); // Small delay for smooth motion
  return allReached;
}

void setServoAngle(int index, int angle) {
  switch (index) {
    case 0: servo1.write(angle); break;
    case 1: servo2.write(angle); break;
    case 2: servo3.write(angle); break;
    case 3: servo4.write(angle); break;
    case 4: servo5.write(angle); break;
    case 5: servo6.write(angle); break;
  }
}

