/*
  Title: EEG-Based Robotic Arm Control (Left/Right Movement)
  Description:
    This is a demo code to simulate basic robotic arm movement (left/right)
    using EEG brainwave signals captured through an analog input sensor.
    
    The system reads EEG signal levels from BioAmp EXG Pill (or any EEG analog sensor),
    compares it against a threshold, and moves a robotic arm motor left or right accordingly.

  Note: 
    - This is a simplified demo.
    - Real applications require pre-processing and classification (e.g., deep learning).
    - Can be extended to multi-directional movement and multi-axis arms.
    
  Author: Vedant Mate & Nandakumar
  Patent Filed: Symbiosis International (Deemed University), Aug 2024
*/

const int eegPin = A0;           // EEG signal input pin (analog)
const int leftMotorPin = 8;      // Motor control for left movement
const int rightMotorPin = 9;     // Motor control for right movement

int eegThreshold = 520;          // Default threshold (can be set after calibration)

void setup() {
  pinMode(eegPin, INPUT);
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("EEG Robotic Arm Control Initialized...");
  delay(1000);
}

void loop() {
  // Step 1: Read EEG Signal from analog pin
  int eegValue = analogRead(eegPin);

  // Step 2: Display EEG Value on Serial Monitor
  Serial.print("EEG Value: ");
  Serial.println(eegValue);

  // Step 3: Basic movement logic based on threshold
  if (eegValue > eegThreshold + 20) {
    moveRight();
  } else if (eegValue < eegThreshold - 20) {
    moveLeft();
  } else {
    stopMotors();  // Neutral state
  }

  delay(200); // Small delay to stabilize readings
}

void moveRight() {
  Serial.println("→ Moving RIGHT");
  digitalWrite(rightMotorPin, HIGH);
  digitalWrite(leftMotorPin, LOW);
  delay(500); // Move briefly
  stopMotors();
}

void moveLeft() {
  Serial.println("← Moving LEFT");
  digitalWrite(leftMotorPin, HIGH);
  digitalWrite(rightMotorPin, LOW);
  delay(500);
  stopMotors();
}

void stopMotors() {
  digitalWrite(leftMotorPin, LOW);
  digitalWrite(rightMotorPin, LOW);
}
