const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int ledPin1 = 9;  // LED for Direction 1
const int ledPin2 = 10; // LED for Direction 2

long duration1, duration2;
int distance1, distance2;
const int threshold = 300;  // Threshold distance in cm (adjust as necessary)

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Sensor 1 - Direction 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Sensor 2 - Direction 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Debugging: Print distances
  Serial.print("Distance 1: ");
  Serial.println(distance1);
  Serial.print("Distance 2: ");
  Serial.println(distance2);

  // Logic to control LEDs based on distance
  if (distance1 < threshold) {
    digitalWrite(ledPin2, HIGH);  // Turn on LED for Direction 2
    digitalWrite(ledPin1, LOW);   // Turn off LED for Direction 1
  } else if (distance2 < threshold) {
    digitalWrite(ledPin1, HIGH);  // Turn on LED for Direction 1
    digitalWrite(ledPin2, LOW);   // Turn off LED for Direction 2
  } else {
    digitalWrite(ledPin1, LOW);   // Turn off both LEDs if no vehicle detected
    digitalWrite(ledPin2, LOW);
  }

  delay(100);  // Short delay before the next loop
}