#define trigPin 9 // Trigger pin of the ultrasonic sensor
#define echoPin 10 // Echo pin of the ultrasonic sensor

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as an OUTPUT
  pinMode(echoPin, INPUT); // Set echo pin as an INPUT
}

void loop() {
  long duration, distance; // Variables to store the duration and distance

  // Clear the trigger pin and wait for a short delay
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = (duration / 2) / 29.1; // Speed of sound in air at 20°C is approximately 343 meters per second (or 29.1 microseconds per centimeter)

  // Display the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait for a moment before taking the next reading
}
