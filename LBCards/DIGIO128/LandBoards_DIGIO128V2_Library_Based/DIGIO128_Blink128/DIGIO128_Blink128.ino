/////////////////////////////////////////////////////////////////////////////////////////////////
// DIGIO128_Blink128 code
// Make all 128 lines outputs
// Blink each line, one at a time
// http://land-boards.com/blwiki/index.php?title=DIGIO-128
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "LandBoards_Digio128V2.h"

LandBoards_Digio128V2 Dio128;		// Call the class constructor for the DigIO-128 card

/////////////////////////////////////////////////////////////////////////////////////////////////
// setup() - Initialize the card
/////////////////////////////////////////////////////////////////////////////////////////////////

void setup(void)
{
  Dio128.begin();              // connects to the 8 MCP23017 parts
  for (uint8_t pin = 0; pin < 128; pin++)
    Dio128.pinMode(pin, OUTPUT);    // make all pins into INPUTs
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Blink all 128 lines, one at a time
/////////////////////////////////////////////////////////////////////////////////////////////////

void loop(void)
{
  for (uint8_t pin = 0; pin < 128; pin++)    // bounce an LED through all the channels
  {
    Dio128.digitalWrite(pin, HIGH);
    delay(100);
    Dio128.digitalWrite(pin, LOW);
  }
}