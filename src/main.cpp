#include <Arduino.h>
#include <Servo.h>

// Create servo objects for 6 servos
Servo servo1, servo2, servo3, servo4, servo5, servo6;

int InitFixedAngles[6] = {95, 90, 94, 140, 108, 125};

// Current angles of servos
int currentAngles[6] = {95, 90, 94, 140, 108, 125}; // Initial positions (degrees)

// Target angles for servos
int targetAngles[6] = {95, 90, 94, 140, 108, 125}; // Set target angles here

// Speed for each servo (degrees per update step)
int servoSpeeds[6] = {1, 1, 1, 1, 1, 1}; // Adjust speed as needed

// Servo pins
const int servoPins[6] = {3, 5, 6, 9, 10, 11}; // Connect your servos to these pins

bool updateServoPositions();
void setServoAngle(int index, int angle);
void grab_box1();
void grab_box2();
void grab_box3();

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

  while (!updateServoPositions()); // Wait until movement completes

  delay(500); // Optional: Add a small delay for stability

  grab_box1();
}

void loop() {

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

void grab_box1(){

  delay(2000);
  targetAngles[0] = InitFixedAngles[0] - 19.89;
  targetAngles[1] = InitFixedAngles[1] - 52.29;
  targetAngles[2] = InitFixedAngles[2] + 61.4;
  targetAngles[3] = InitFixedAngles[3] - 49.68;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Wait until movement completes
  // Step 1: Move to the box's location (picking position)
  targetAngles[0] = InitFixedAngles[0] - 19.88;
  targetAngles[1] = InitFixedAngles[1] - 74.24;
  targetAngles[2] = InitFixedAngles[2] + 48.61;
  targetAngles[3] = InitFixedAngles[3] - 10;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions()); // Wait until movement completes

  delay(500); // Optional: Add a small delay for stability

  // Step 2: Grab the box (close gripper)
  targetAngles[5] = 180;
  while (!updateServoPositions());

  delay(500); // Optional: Add a small delay for gripping

  targetAngles[0] = InitFixedAngles[0] - 19.89;
  targetAngles[1] = InitFixedAngles[1] - 52.29;
  targetAngles[2] = InitFixedAngles[2] + 61.4;
  targetAngles[3] = InitFixedAngles[3] - 49.68;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  targetAngles[0] = InitFixedAngles[0] + 19.89;
  targetAngles[1] = InitFixedAngles[1] - 52.29;
  targetAngles[2] = InitFixedAngles[2] + 61.4;
  targetAngles[3] = InitFixedAngles[3] - 49.68;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Step 4: Move to the box's destination (placing position)
  targetAngles[0] = InitFixedAngles[0] + 19.88;
  targetAngles[1] = InitFixedAngles[1] - 74.24;
  targetAngles[2] = InitFixedAngles[2] + 48.61;
  targetAngles[3] = InitFixedAngles[3] - 10;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Step 5: Release the box (open gripper)
  targetAngles[5] = 125;
  while (!updateServoPositions());

  delay(500);

  targetAngles[0] = InitFixedAngles[0] + 19.89;
  targetAngles[1] = InitFixedAngles[1] - 52.29;
  targetAngles[2] = InitFixedAngles[2] + 61.4;
  targetAngles[3] = InitFixedAngles[3] - 49.68;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Step 6: Return to initial position
  for (int i = 0; i < 6; i++) {
    targetAngles[i] = InitFixedAngles[i];
  }
  while (!updateServoPositions());

  delay(500);
}

void grab_box2() {
  // Step 1: Move to the box's location (picking position)
  targetAngles[0] = InitFixedAngles[0] - 35.71;
  targetAngles[1] = InitFixedAngles[1] - 42.94;
  targetAngles[2] = InitFixedAngles[2] - 11.13;
  targetAngles[3] = InitFixedAngles[3] + 12.06;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions()); // Wait until movement completes

  delay(500); // Optional: Add a small delay for stability

  // Step 2: Grab the box (close gripper)
  targetAngles[5] = 180;
  while (!updateServoPositions());

  delay(500); // Optional: Add a small delay for gripping

  targetAngles[3] = InitFixedAngles[3] + 30;
  while (!updateServoPositions());

  delay(500); // Optional: Add a small delay for gripping

  // Step 4: Move to the box's destination (placing position)
  targetAngles[0] = InitFixedAngles[0] + 35.71;
  targetAngles[1] = InitFixedAngles[1] - 42.94;
  targetAngles[2] = InitFixedAngles[2] - 11.13;
  targetAngles[3] = InitFixedAngles[3] + 30;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  targetAngles[3] = InitFixedAngles[3] + 12.06;
  while (!updateServoPositions());

  delay(500);

  // Step 5: Release the box (open gripper)
  targetAngles[5] = 125;
  while (!updateServoPositions());

  delay(500);

  targetAngles[3] = InitFixedAngles[3] + 40;
  while (!updateServoPositions());

  delay(500);

  // Step 6: Return to initial position
  for (int i = 0; i < 6; i++) {
    targetAngles[i] = InitFixedAngles[i];
  }
  while (!updateServoPositions());

  delay(500);

  // Box grabbing and placing operation complete
}

void grab_box3(){

  delay(2000);

  targetAngles[0] = InitFixedAngles[0] - 54.13;
  targetAngles[1] = InitFixedAngles[1] + 15.77;
  targetAngles[2] = InitFixedAngles[2] - 32.18;
  targetAngles[3] = InitFixedAngles[3] - 25.59;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Wait until movement completes
  // Step 1: Move to the box's location (picking position)
  targetAngles[0] = InitFixedAngles[0] - 54.13;
  targetAngles[1] = InitFixedAngles[1] - 36.18;
  targetAngles[2] = InitFixedAngles[2] - 32.18;
  targetAngles[3] = InitFixedAngles[3] + 26.36;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions()); // Wait until movement completes

  delay(500); // Optional: Add a small delay for stability

  // Step 2: Grab the box (close gripper)
  targetAngles[5] = 180;
  while (!updateServoPositions());

  delay(500); // Optional: Add a small delay for gripping

  targetAngles[0] = InitFixedAngles[0] - 54.13;
  targetAngles[1] = InitFixedAngles[1] + 15.77;
  targetAngles[2] = InitFixedAngles[2] - 32.18;
  targetAngles[3] = InitFixedAngles[3] - 25.59;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  targetAngles[0] = InitFixedAngles[0] + 54.13;
  targetAngles[1] = InitFixedAngles[1] + 15.77;
  targetAngles[2] = InitFixedAngles[2] - 32.18;
  targetAngles[3] = InitFixedAngles[3] - 25.59;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Step 4: Move to the box's destination (placing position)
  targetAngles[0] = InitFixedAngles[0] + 54.13;
  targetAngles[1] = InitFixedAngles[1] - 36.18;
  targetAngles[2] = InitFixedAngles[2] - 32.18;
  targetAngles[3] = InitFixedAngles[3] + 26.36;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Step 5: Release the box (open gripper)
  targetAngles[5] = 125;
  while (!updateServoPositions());

  delay(500);

  targetAngles[0] = InitFixedAngles[0] + 54.13;
  targetAngles[1] = InitFixedAngles[1] + 15.77;
  targetAngles[2] = InitFixedAngles[2] - 32.18;
  targetAngles[3] = InitFixedAngles[3] - 25.59;
  targetAngles[4] = InitFixedAngles[4];
  while (!updateServoPositions());

  delay(500);

  // Step 6: Return to initial position
  for (int i = 0; i < 6; i++) {
    targetAngles[i] = InitFixedAngles[i];
  }
  while (!updateServoPositions());

  delay(500);
}



