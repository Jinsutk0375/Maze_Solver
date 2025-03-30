// Ultrasonic sensor pins
#define FRONT_TRIG_PIN A0
#define FRONT_ECHO_PIN A1

#define LEFT_TRIG_PIN A2
#define LEFT_ECHO_PIN A3

#define RIGHT_TRIG_PIN A4
#define RIGHT_ECHO_PIN A5

// Motor control pins
#define LEFT_MOTOR_PIN_1 6
#define LEFT_MOTOR_PIN_2 9

#define RIGHT_MOTOR_PIN_1 10
#define RIGHT_MOTOR_PIN_2 11

// Define motor speed constants
#define FORWARD_SPEED 50
#define BACKWARD_SPEED 0
#define TURN_SPEED 135

// Define distance thresholds for obstacle detection
#define FRONT_THRESHOLD 25
#define SIDE_THRESHOLD 15

void setup() {
  // Initialize ultrasonic sensor pins
  pinMode(FRONT_TRIG_PIN, OUTPUT);
  pinMode(FRONT_ECHO_PIN, INPUT);
  pinMode(LEFT_TRIG_PIN, OUTPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);
  pinMode(RIGHT_TRIG_PIN, OUTPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);

  // Initialize motor control pins as OUTPUT
  pinMode(LEFT_MOTOR_PIN_1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN_2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN_1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN_2, OUTPUT);

  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Read sensor data
  int front_distance = getDistance(FRONT_TRIG_PIN, FRONT_ECHO_PIN);
  int left_distance = getDistance(LEFT_TRIG_PIN, LEFT_ECHO_PIN);
  int right_distance = getDistance(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN);

  // Debugging
  Serial.print("Front: "); Serial.println(front_distance);
  Serial.print("Left: "); Serial.println(left_distance);
  Serial.print("Right: "); Serial.println(right_distance);

  // Adjust movement based on sensor readings
  if (front_distance > FRONT_THRESHOLD) {
    moveForward();
  } else if (left_distance > SIDE_THRESHOLD && right_distance > SIDE_THRESHOLD) {
    turnLeft();  // Follow left wall
  } else if (left_distance < right_distance) {
    turnRight();
  } else {
    turnLeft();
  }

  delay(100); // Delay for stability
}

// Function to get distance from ultrasonic sensor
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 58; // Convert pulse duration to distance in cm
}

// Function to move the robot forward
void moveForward() {
  analogWrite(LEFT_MOTOR_PIN_1, FORWARD_SPEED);
  analogWrite(LEFT_MOTOR_PIN_2, BACKWARD_SPEED);
  analogWrite(RIGHT_MOTOR_PIN_1, FORWARD_SPEED);
  analogWrite(RIGHT_MOTOR_PIN_2, BACKWARD_SPEED);
}

// Function to turn the robot left
void turnLeft() {
  analogWrite(LEFT_MOTOR_PIN_1, BACKWARD_SPEED);
  analogWrite(LEFT_MOTOR_PIN_2, FORWARD_SPEED);
  analogWrite(RIGHT_MOTOR_PIN_1, FORWARD_SPEED);
  analogWrite(RIGHT_MOTOR_PIN_2, BACKWARD_SPEED);
}

// Function to turn the robot right
void turnRight() {
  analogWrite(LEFT_MOTOR_PIN_1, FORWARD_SPEED);
  analogWrite(LEFT_MOTOR_PIN_2, BACKWARD_SPEED);
  analogWrite(RIGHT_MOTOR_PIN_1, BACKWARD_SPEED);
  analogWrite(RIGHT_MOTOR_PIN_2, FORWARD_SPEED);
}
