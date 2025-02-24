//#create a Simple Project With the Ultrasonic Sensor (HC-SR04) +LED, Arduino 
//#(echo A0, trig A1), led pin 4, if distance is less than 100 cm, the led lights up/ 1 sec per blink, if distance is more than 100cm the led on breadboard shuts

#define trigPin A1   // Trigger pin connected to A1 (Ultrasonic Sensor)
#define echoPin A0   // Echo pin connected to A0 (Ultrasonic Sensor)
#define ledPin 4     // LED connected to digital pin 4 (Breadboard LED)

long duration;  // Variable to store the pulse duration
int distance;   // Variable to store the calculated distance

void setup() {
  pinMode(trigPin, OUTPUT);  // Set trigPin as OUTPUT to send pulses
  pinMode(echoPin, INPUT);   // Set echoPin as INPUT to receive the echo
  pinMode(ledPin, OUTPUT);   // Set ledPin as OUTPUT (Breadboard LED)
}

void loop() {
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time it took for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.0344 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If distance is less than 100 cm, make the LED blink
  if (distance < 100) {
    digitalWrite(ledPin, HIGH); // Turn LED on
    delay(500);                 // Wait 500ms
    digitalWrite(ledPin, LOW);  // Turn LED off
    delay(500);                 // Wait 500ms/ 1 sec per blink default
  } else {
    digitalWrite(ledPin, LOW);  // Ensure LED is off when distance is greater
  }

  delay(100); // Small delay before the next measurement
}
