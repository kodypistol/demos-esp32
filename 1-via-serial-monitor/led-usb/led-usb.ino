const int LED_PIN = 23;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (Serial.available() == 0) {
    return;
  }

  String message = Serial.readStringUntil('\n');
  message.trim();

  if (message.startsWith("led:")) {
    int brightness = constrain(message.substring(4).toInt(), 0, 255);
    analogWrite(LED_PIN, brightness);
    Serial.println("ok, led à " + String(brightness));
  }
}
