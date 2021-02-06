#include "keyboard_interface.h"

void KeyboardInterface::begin() {
  if (!Wire.begin(I2C_SDA, I2C_SCL))
    Serial.println("Could not configure I2C interface...");
  else
    Serial.println("Successfully configured I2C interface");
    
  this->init_time = millis();
}

void KeyboardInterface::main(uint32_t current_time) {
  // Request data from I2C slave
  if (current_time - this->init_time >= KEYBOARD_INT) {
    Wire.requestFrom(I2C_ADDR, 1);
    while (Wire.available())
    {
      char c = Wire.read(); // receive a byte as character
      this->KEY = c;

      /*
      if (c) {
        if (c == 0x18)
          Serial.println("\nUP");
        else if (c == 0x19)
          Serial.println("\nDOWN");
        else if (c == 0x1A)
          Serial.println("\nRIGHT");
        else if (c == 0x1B)
          Serial.println("\nLEFT");
        else if (c == 0x05)
          Serial.println("\nCENTER");
        else
          Serial.print(c);         // print the character
      }
      */
    }

    this->init_time = millis();
  }
}
