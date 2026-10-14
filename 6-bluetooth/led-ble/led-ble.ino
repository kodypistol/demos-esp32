#include <BLEDevice.h>
#include <BLEServer.h>

const int LED_PIN = 23;
const char *SERVICE_UUID = "601e00fe-4903-499d-9844-df2ab22ab484";
const char *LED_UUID = "90bb32b6-d623-4919-91be-66c7c3e7ecbf";

class LedCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *characteristic) {
    String message = characteristic->getValue();
    Serial.println(message);

    if (message.startsWith("led:")) {
      int brightness = constrain(message.substring(4).toInt(), 0, 255);
      analogWrite(LED_PIN, brightness);
    }
  }
};

class ConnectionCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *server) {
    Serial.println("téléphone connecté");
  }

  void onDisconnect(BLEServer *server) {
    Serial.println("téléphone parti, on se rend visible");
    BLEDevice::startAdvertising();
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  BLEDevice::init("OOTY-LED");
  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ConnectionCallbacks());

  BLEService *service = server->createService(SERVICE_UUID);
  BLECharacteristic *led = service->createCharacteristic(LED_UUID, BLECharacteristic::PROPERTY_WRITE);
  led->setCallbacks(new LedCallbacks());
  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  BLEDevice::startAdvertising();
  Serial.println("visible sous le nom OOTY-LED");
}

void loop() {
}
