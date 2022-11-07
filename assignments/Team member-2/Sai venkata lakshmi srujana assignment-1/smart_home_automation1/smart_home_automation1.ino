// C++ code
//
int distancia = 0;

int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(11, 10);
  if (distancia > 10) {
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, LOW);
    delay(200); // Wait for 200 millisecond(s)
    digitalWrite(5, LOW);
    delay(200); // Wait for 200 millisecond(s)
  } else {
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
  }

  distancia = 0.01723 * readUltrasonicDistance(11, 10);
  if (distancia <= 10) {
    digitalWrite(8, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    delay(200); // Wait for 200 millisecond(s)
    digitalWrite(5, LOW);
    delay(200); // Wait for 200 millisecond(s)
  } else {
    digitalWrite(12, LOW);
    digitalWrite(5, LOW);
  }

  distancia = 0.01723 * readUltrasonicDistance(11, 10);
  if (distancia <= 5) {
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(5, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(5, LOW);
    delay(100); // Wait for 100 millisecond(s)
  } else {
    digitalWrite(13, LOW);
    digitalWrite(5, LOW);
  }
}