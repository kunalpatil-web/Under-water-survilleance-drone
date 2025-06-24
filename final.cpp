#define CH1_PIN 2   // Left/Right control
#define CH3_PIN 3   // Up/Down control

// Output pins for motors
#define M1_PIN 8   // Up/Down motor 1
#define M2_PIN 9   // Up/Down motor 2
#define M3_PIN 10  // Left/Right motor 1
#define M4_PIN 11  // Left/Right motor 2

int ch1_pwm, ch3_pwm;

void setup() {
  pinMode(CH1_PIN, INPUT);
  pinMode(CH3_PIN, INPUT);

  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);
  pinMode(M3_PIN, OUTPUT);
  pinMode(M4_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  ch1_pwm = pulseIn(CH1_PIN, HIGH, 25000); // Horizontal
  ch3_pwm = pulseIn(CH3_PIN, HIGH, 25000); // Vertical

  // === Vertical Movement (Up/Down - M1 & M2 Together) ===
  if (ch3_pwm > 1600 || ch3_pwm < 1400) {
    digitalWrite(M1_PIN, HIGH);
    digitalWrite(M2_PIN, HIGH);
  } else {
    digitalWrite(M1_PIN, LOW);
    digitalWrite(M2_PIN, LOW);
  }

  // === Horizontal Movement (Right/Left - M3 & M4 Together) ===
  if (ch1_pwm > 1600 || ch1_pwm < 1400) {
    digitalWrite(M3_PIN, HIGH);
    digitalWrite(M4_PIN, HIGH);
  } else {
    digitalWrite(M3_PIN, LOW);
    digitalWrite(M4_PIN, LOW);
  }

  // Debug output
  Serial.print("CH1: "); Serial.print(ch1_pwm);
  Serial.print(" | CH3: "); Serial.println(ch3_pwm);

  delay(50);
}
