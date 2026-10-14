#include <WiFi.h>
#include <WebSocketsServer.h>

const int LED_PIN = 23;

WebSocketsServer ws(81);

void onMessage(uint8_t client, WStype_t type, uint8_t *data, size_t length) {
  if (type != WStype_TEXT) {
    return;
  }

  String message = String((char *) data);
  Serial.println(message);

  if (message.startsWith("led:")) {
    int brightness = constrain(message.substring(4).toInt(), 0, 255);
    analogWrite(LED_PIN, brightness);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  WiFi.softAP("OOTY-DEMO", "gobelins2026");

  Serial.println(WiFi.softAPIP());

  ws.begin();
  ws.onEvent(onMessage);
}

void loop() {
  ws.loop();
}
