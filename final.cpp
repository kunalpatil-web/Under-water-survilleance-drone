// Pin for the PWM input
const int pwmPin = 2;

// Pin for the digital output
const int digitalPin = 3;

// Threshold value for PWM signal
const int threshold = 128;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the PWM pin as INPUT
  pinMode(pwmPin, INPUT);

  // Set the digital pin as OUTPUT
  pinMode(digitalPin, OUTPUT);
}

void loop() {
  // Read the PWM value from the PWM pin
  int pwmValue = analogRead(pwmPin);

  // Convert the PWM value to digital
  if (pwmValue > threshold) {
    digitalWrite(digitalPin, HIGH);
    Serial.println("PWM Signal: HIGH");
  } else {
    digitalWrite(digitalPin, LOW);
    Serial.println("PWM Signal: LOW");
  }

  // Add a delay for stability
  delay(100);
}
