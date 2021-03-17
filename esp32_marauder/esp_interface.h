#ifndef esp_interface_h
#define esp_interface_h

#include "Display.h"

#define ESP_RST  14
#define ESP_ZERO 13

extern Display display_obj;

class EspInterface {
  public:
    void bootProgramMode();
    void bootRunMode();
    void begin();

    void main(uint32_t current_time);
};

#endif
