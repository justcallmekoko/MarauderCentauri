#include "esp_interface.h"

void EspInterface::begin() {
  pinMode(ESP_RST, OUTPUT);
  pinMode(ESP_ZERO, OUTPUT);

  delay(100);

  digitalWrite(ESP_ZERO, HIGH);

  Serial2.begin(115200);

  this->bootRunMode();
}

void EspInterface::bootProgramMode() {
  Serial.println("[!] Setting ESP12 in program mode...");
  digitalWrite(ESP_ZERO, LOW);
  delay(100);
  digitalWrite(ESP_RST, LOW);
  delay(100);
  digitalWrite(ESP_RST, HIGH);
  delay(100);
  digitalWrite(ESP_ZERO, HIGH);
  Serial.println("[!] Complete");
}

void EspInterface::bootRunMode() {
  Serial.println("[!] Setting ESP12 in run mode...");
  digitalWrite(ESP_ZERO, HIGH);
  delay(100);
  digitalWrite(ESP_RST, LOW);
  delay(100);
  digitalWrite(ESP_RST, HIGH);
  delay(100);
  digitalWrite(ESP_ZERO, HIGH);
  Serial.println("[!] Complete");
}

void EspInterface::main(uint32_t current_time) {
  if (Serial2.available()) {
    Serial.write((uint8_t)Serial2.read());
  }

  if (Serial.available()) {
    Serial2.write((uint8_t)Serial.read());
  }
}
