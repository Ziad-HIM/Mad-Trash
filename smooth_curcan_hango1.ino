#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 3;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance <= 5) { // Adjust '5' based on your trash can's bottom distance
    myServo.write(0);  // Moves servo to one position
    delay(500);
    myServo.write(90); // Moves servo back
    delay(1000);
  }
  delay(100);
}