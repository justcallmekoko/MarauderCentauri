/* Interfaces with an interprets key presses from a keyboard matrix
 * using the Adafruit Keypad library
 * 
 * Reports key presses over I2C bus to master upon request
 */

#include <Wire.h>
#include <Arduino.h>
#include "Adafruit_Keypad.h"

#define I2C_ADDR 0x08
#define KEYS 38
#define CAPS_LED A2
#define SYM_LED A3
#define FN_LED A3

char KEY = NULL; // Key the has just been pressed

const byte ROWS = 4; // rows
const byte COLS = 10; // columns

bool SYM = false;
bool CAPS = false;
bool FN = false;

//define the symbols on the buttons of the keypads
/*char keys[ROWS][COLS] = {
  {'1','2','3','A',0x18},
  {'4','5','6','B',0x05},
  {'7','8','9','C',0x1B},
  {'*','0','#','D',0x19}
};*/
char keys[ROWS][COLS] = {
  {'q','w','e','r','t','y','u','i','o','p'},
  {'a','s','d','f','g','h','j','k','l',0x08},
  {'z','x','c','v','b','n','m',',','.','\n'},
  {0x14,'`',' ',0x02,0x01,0x18,0x05,0x1B,0x1A,0x19}
};

char spec_keys[KEYS][4] = {
  {'q','Q','1','!'},
  {'w','W','2','@'},
  {'e','E','3','#'},
  {'r','R','4','$'},
  {'t','T','5','%'},
  {'y','Y','6','^'},
  {'u','U','7','&'},
  {'i','I','8','*'},
  {'o','O','9','('},
  {'p','P','0',')'},
  {'a','A',0x0,0x0},
  {'s','S',0x0,0x0},
  {'d','D','/','?'},
  {'f','F',';',':'},
  {'g','G','\'','"'},
  {'h','H','[','{'},
  {'j','J',']','}'},
  {'k','K','-','_'},
  {'l','L','=','+'},
  {'z','Z',0x0,0x0},
  {'x','X',0x0,0x0},
  {'c','C',0x0,0x0},
  {'v','V',0x0,0x0},
  {'b','B',0x0,0x0},
  {'n','N',0x0,0x0},
  {'m','M',0x0,0x0},
  {',','<',',',','},
  {'.','>','.','.'},
  {' ',' ',' ',' '},
  {'`','~','`','`'},
  {'\n','\n','\n','\n'},
  {0x08,0x08,0x08,0x08},
  {0x0D,0x0D,0x0D,0x0D},
  {0x18,0x18,0x18,0x18},
  {0x05,0x05,0x05,0x05},
  {0x1B,0x1B,0x1B,0x1B},
  {0x1A,0x1A,0x1A,0x1A},
  {0x19,0x19,0x19,0x19}
};

// ESP32
//byte rowPins[ROWS] = {0, 26, 27, 14}; 
//byte colPins[COLS] = {12, 13, 15, 4, 21}; 

// ATMEGA328P
byte rowPins[ROWS] = {12, 13, A0, A1};
byte colPins[COLS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setCaps(bool setting) {
  CAPS = setting;
  if (setting)
    digitalWrite(CAPS_LED, HIGH);
  else
    digitalWrite(CAPS_LED, LOW);
}

void setSym(bool setting) {
  SYM = setting;
  if (setting)
    digitalWrite(SYM_LED, HIGH);
  else
    digitalWrite(SYM_LED, LOW);
}

void setFn(bool setting) {
  FN = setting;
  if (setting)
    digitalWrite(FN_LED, HIGH);
  else
    digitalWrite(FN_LED, LOW);
}

void controlSym() {
  if (SYM) {
    setSym(false);
    Serial.println("\nSYM off");
  }
  else {
    setCaps(false);
    setFn(false);
    setSym(true);
    Serial.println("\nSYM on");
  }
}

void controlFn() {
  if (FN) {
    setFn(false);
    Serial.println("\nFN off");
  }
  else {
    setSym(false);
    setCaps(false);
    setFn(true);
    Serial.println("\nFN on");
  }
}

void controlCaps() {
  if (CAPS) {
    setCaps(false);
    Serial.println("\nCAPS off");
  }
  else {
    setSym(false);
    setFn(false);
    setCaps(true);
    Serial.println("\nCAPS on");
  }
}

void setup() {
  pinMode(CAPS_LED, OUTPUT);
  pinMode(SYM_LED, OUTPUT);
  pinMode(FN_LED, OUTPUT);

  digitalWrite(CAPS_LED, LOW);
  digitalWrite(SYM_LED, LOW);
  digitalWrite(FN_LED, LOW);
  
  Serial.begin(115200);

  Serial.println("Keypad test...");
  
  customKeypad.begin();

  Wire.begin(I2C_ADDR);
  Wire.onRequest(requestEvent);
}

void requestEvent() {
  // Send key only if a key has been pressed since last write
  if (KEY != NULL) {
    Wire.write(KEY);
    KEY = NULL;
  }
}

void loop() {
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    if(e.bit.EVENT == KEY_JUST_PRESSED) {
      switch ((char)e.bit.KEY) {
        case 0x14:
          controlCaps();
          break;
        case 0x02:
          controlSym();
          break;
        case 0x01:
          controlFn();
          break;
        default:
          for (int i = 0; i < KEYS; i++) {
            if (spec_keys[i][0] == (char)e.bit.KEY){
              if (CAPS)
                KEY = spec_keys[i][1];
              else if (SYM)
                KEY = spec_keys[i][2];
              else if (FN)
                KEY = spec_keys[i][3];
              else
                KEY = (char)e.bit.KEY;

              break;
            }
            
          }
          //KEY = (char)e.bit.KEY;

        Serial.print((char)KEY);
        Serial.println(" pressed");
      }
    }
  }
  
  delay(10);
}
