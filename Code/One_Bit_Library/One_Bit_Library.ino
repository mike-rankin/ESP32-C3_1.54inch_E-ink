//
// OneBitDisplay EPD (e-ink) demo sketch
// Written by Larry Bank 7/10/2022
//
// This program shows how to use epd panels
// with the OneBitDisplay library. The general idea
// is that it doesn't support "immediate" mode with e-ink. 
// You'll need to allocate a buffer to hold the pixel
// data, draw on it, then dump it all at once to the panel
// as a full update (display) or partial (displayPartial).
// This demo draws some text using the built-in fonts and
// a custom font in Adafruit_GFX format
//
// The target hardware for this demo is the Pimoroni Badger2040
// A RPI Pico MCU with a UC8151 2.9" 128x296 1-bpp epd
//
#include <OneBitDisplay.h>
#include "Roboto_Black_40.h"

ONE_BIT_DISPLAY lcd;

#define BADGER_FREQ 12000000  //Was 12000000
#define BADGER_CS 7
#define BADGER_BUSY 1
#define BADGER_RES 10
#define BADGER_DC 3
#define BADGER_MOSI 6
#define BADGER_SCK 4
#define BADGER_BATT 0

void setup() 
{
  // Initialize the library by telling it how the display is connected
  lcd.setSPIPins(BADGER_CS, BADGER_MOSI, BADGER_SCK, BADGER_DC, BADGER_RES, BADGER_BUSY);
  lcd.SPIbegin(EPD42R_400x300, BADGER_FREQ);

  // Set the orientation to draw in the direction we want
  lcd.setRotation(0); // the panel is actually 128 wide by 296 tall, but oriented 90 right
  lcd.allocBuffer(); // allocate a back buffer and keep it internal to the class
  lcd.fillScreen(0); // 0 for EPDs is white (for OneBitDisplay)
  lcd.setFont(FONT_12x16); // use the internal stretched/smoothed font
  lcd.setCursor(10,10);
  lcd.print("This was a full update");
  lcd.display(); // do a full update
  for (int i=24; i<120; i += 32) {
    lcd.fillCircle(i, i, 8, 1);
    lcd.displayPartial(); // draw a ball and show intermediate results with a partial update
  }
  lcd.setCursor(10, 10);
    //lcd.print("then a partial update");
    //lcd.displayPartial(); // final partial update
  delay(4000);
  lcd.fillScreen(0);
  lcd.setTextColor(OBD_RED);
  lcd.setFreeFont(&Roboto_Black_40);
  lcd.setCursor(0,40);
  lcd.println("Love");
  lcd.println("the red");
  lcd.setFont(FONT_12x16);
  lcd.setCursor(0,112);
  lcd.println("Finished");
  lcd.display(); // show final screen with a full update
}

void loop() {
 // nothing going on here
}

/*
obdDrawLine(&obd, x, 0, OLED_WIDTH-x, OLED_HEIGHT-1, 1, 1);


ulTime = micros() - ulTime;
  obdFill(&obd, 0, 1);
  obdWriteString(&obd, 0, 0, 0, (char *)"100 frames drawn", FONT_8x8, 0, 1);
  sprintf(szTemp, "in %d ms", (int)(ulTime/1000));


 sprintf(szTemp, "%d bytes generated", obdGetCommandLen(&obdCMD));
  obdWriteString(&obd, 0,0,2, szTemp, FONT_6x8, 0, 1);
  delay(4000);
  obdExecCommands(ucBuffer, obdGetCommandLen(&obdCMD), &obd, 0);
  obdDumpBuffer(&obd, NULL);


char szTemp[32];
unsigned long ms;

obdFill(&obd, 0, 0);
ms = micros();
obdWriteStringCustom(&obd, (GFXfont *)&FreeSerif12pt7b, 0, 16, (char *)"Hello World",1);
obdWriteStringCustom(&obd, (GFXfont *)&FreeSerif12pt7b, 0, 16+FreeSerif12pt7b.yAdvance, (char *)"Fast Perf!", 1);
ms = micros() - ms;
obdDumpBuffer(&obd, NULL);
sprintf(szTemp, "rendered in %d us", (int)ms);
obdWriteString(&obd, 0,0,7,szTemp, FONT_6x8, 0, 1);
delay(4000);
*/
