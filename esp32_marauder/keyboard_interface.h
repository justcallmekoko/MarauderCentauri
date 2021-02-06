#ifndef keyboard_interface_h
#define keyboard_interface_h

#include <Wire.h>
#include <Arduino.h>

#define I2C_SDA 33
#define I2C_SCL 22 
#define I2C_ADDR 0x08
#define KEYBOARD_INT 10

class KeyboardInterface {
  private:
    uint32_t init_time;

  public:
    char KEY = NULL;
    
    void begin();
    void main(uint32_t current_time);
};

#endif
