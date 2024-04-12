// Define the pins
const int flameSensorPin = A0; // Flame sensor connected to analog pin A0
const int buzzerPin = 8;       // Buzzer connected to digital pin 8

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(flameSensorPin, INPUT);  // Set flame sensor pin as input
  pinMode(buzzerPin, OUTPUT);      // Set buzzer pin as output
}

void loop() {
  int flameValue = analogRead(flameSensorPin);  // Read the value from the flame sensor
  
  // Print the flame sensor value to the serial monitor
  Serial.print("Flame Sensor Value: ");
  Serial.println(flameValue);
  
  // Check if flame is detected
  if (flameValue < 1020) {  // Adjust this threshold according to your sensor's sensitivity
    // If flame is detected, turn on the buzzer and print a message
    Serial.println("Flame detected! Sound alarm.");
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    delay(1000);  // Delay for 1 second
  } else {
    // If no flame is detected, turn off the buzzer
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
  }
  
  delay(500);  // Delay for stability
}
