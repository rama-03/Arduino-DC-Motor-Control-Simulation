// Motor driver input pins
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // 1) Move forward for 30 seconds
  moveForward();
  delay(30000);

  // 2) Move backward for 60 seconds
  moveBackward();
  delay(60000);

  // 3) Alternate right and left for 60 seconds
  unsigned long startTime = millis();

  while (millis() - startTime < 60000)
  {
    turnRight();
    delay(3000);

    turnLeft();
    delay(3000);
  }

  // Stop all motors
  stopMotors();
}

void loop()
{
}


// Move forward
void moveForward()
{
  // Left motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Right motors - opposite rotation
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


// Move backward
void moveBackward()
{
  // Left motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Right motors - opposite rotation
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


// Turn right
void turnRight()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


// Turn left
void turnLeft()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


// Stop all motors
void stopMotors()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}