#include <Servo.h>

Servo myServo;
// define sonar sensor's pins
int trig = 7;
int echo = 8;
// received data
byte val = "";

void setup() {
  myServo.attach(2); // Attach the servo to pin 2
  Serial.begin(9600); // Initialize serial communication for communication with Python
}

void standby() {
  // Set the servo to its standby position (you can define this)
  myServo.write(90); // Adjust the angle as needed
}

void hi() {
  // Perform the "hi" action with the servo
  // Adjust servo angles as needed
  myServo.write(45); // Example angle
  delay(1000);
  myServo.write(135); // Example angle
  delay(1000);
  standby();
}

// Define other actions like hands_up(), look_left(), etc., similarly

void loop() {
  standby();
  while (Serial.available() > 0) {
    val = Serial.read();
    if (val == 'h') {
      hi();
    }
    
    // Add more conditions for other commands as needed
  }
    if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming command
    
    // Process commands
    if (command == 'p') {
      // Perform action for 'p'
      // Example: myServo.write(90); 
    } else if (command == 'u') {
      // Perform action for 'u'
      // Example: myServo.write(120); 
    } else if (command == 'l') {
      // Perform action for 'l'
      // Example: myServo.write(60);
    }
    // Add other actions here using if statements
  }
}
