// Define the analog pin where LM35 temperature sensor is connected
const int lm35Pin = A0;

// Define the onboard LED pin
const int ledPin = 13;

// Define the threshold temperature
const int thresholdTemp = 30;

// Variables to store temperature readings
int temperature;
float tempCelsius;

// Variables to store time intervals for LED blinking
unsigned long previousMillis = 0;
unsigned long interval = 250;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog value from LM35 temperature sensor
  int sensorValue = analogRead(lm35Pin);

  // Convert the analog value to temperature in Celsius
  tempCelsius = (sensorValue * 5.0) / 1024.0 / 0.01;

  // Print temperature to serial monitor
  Serial.print("Temperature: ");
  Serial.print(tempCelsius);
  Serial.println(" °C");

  // Check temperature conditions and control LED blinking
  if (tempCelsius < thresholdTemp) {
    // Blink LED every 250 milliseconds
    blinkLED(250);
  } else {
    // Blink LED every 500 milliseconds
    blinkLED(500);
  }
}

// Function to control LED blinking
void blinkLED(unsigned long interval) {
  unsigned long currentMillis = millis();

  // Check if it's time to blink the LED
  if (currentMillis - previousMillis >= interval) {
    // Save the last time LED blinked
    previousMillis = currentMillis;

    // Toggle LED state
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}
