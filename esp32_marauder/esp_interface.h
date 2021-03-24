#ifndef esp_interface_h
#define esp_interface_h

#include "Display.h"
#include <HardwareSerial.h>

#define ESP_RST  14
#define ESP_ZERO 13
#define BAUD     57600

extern Display display_obj;

class EspInterface {
  public:
    bool supported = false;

    void RunUpdate();
    void bootProgramMode();
    void bootRunMode();
    void begin();

    void program();
    void main(uint32_t current_time);
};

#endif
