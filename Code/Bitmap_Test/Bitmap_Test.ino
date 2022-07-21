
//https://www.youtube.com/watch?v=CMNuMOcvpFM
//https://javl.github.io/image2cpp/


//Solution: Keep Serial Monitor closed while programming. 
//Serial Monitor. Serial output works as expected.




#include <Arduino.h>
#include <Wire.h>

// GxEPD2_HelloWorld.ino by Jean-Marc Zingg

// see GxEPD2_wiring_examples.h for wiring suggestions and examples
// if you use a different wiring, you need to adapt the constructor parameters!

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <GFX.h>

#define SPI_EPD_CLK     4
#define SPI_EPD_MOSI    6
#define SPI_EPD_MISO    5
#define SPI_EPD_CS      7
#define SPI_EPD_BUSY    1
#define SPI_EPD_RST     10
#define SPI_EPD_DC      3

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "Bitmaps.h"

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// or select the display constructor line in one of the following files (old style):
// #include "GxEPD2_display_selection.h"
// #include "GxEPD2_display_selection_added.h"

// alternately you can copy the constructor from GxEPD2_display_selection.h or GxEPD2_display_selection_added.h to here
// e.g. for Wemos D1 mini:
//GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(/*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4)); // GDEH0154D67



const char HelloWorld[] = "TEST";

void helloWorld()
{
  
  
}


void setup()
{
  Serial.begin(115200);
  SPI.end(); // release standard SPI pins, e.g. SCK(18), MISO(19), MOSI(23), SS(5)
  SPI.begin(SPI_EPD_CLK, SPI_EPD_MISO, SPI_EPD_MOSI, SPI_EPD_CS); // map and init SPI pins SCK(13), MISO(12), MOSI(14), SS(15)
  display.init();
  display.setRotation(1);
  //display.setFont(&FreeMonoBold9pt7b);
  //display.setTextColor(GxEPD_BLACK);

  //helloWorld();
  drawBitmaps(ACROBOTIC_LOGO);

  // display.hibernate();
}



const char HelloEpaper[] = "ESP32-C3 eInk!";

void loop() 
{
  /*
  Serial.println("Testing");
  display.setRotation(2);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  // align with centered HelloWorld
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  // height might be different
  display.getTextBounds(HelloEpaper, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t y = (display.height() * 3 / 4) + tbh / 2; // y is base line!
  // make the window big enough to cover (overwrite) descenders of previous text
  uint16_t wh = FreeMonoBold9pt7b.yAdvance;
  uint16_t wy = (display.height() * 3 / 4) - wh / 2;
  // full window mode is the initial mode, set it anyway
  display.setFullWindow();
  // DO NOT display.fillScreen(GxEPD_WHITE); keep current content!
  // display.fillRect(0, wy, display.width(), wh, GxEPD_WHITE); // clear rect instead
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(random(0,30), random(20,display.height()));
  display.print(HelloEpaper);
  display.display();
  delay(5000);
  */
}



void drawBitmaps(const unsigned char *bitmap) 
{
  // Configure the display according to our preferences
  //display.setRotation(0);
  display.setFullWindow();
  // Display the bitmap image
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(0, 0, bitmap, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
  } while(display.nextPage());
}
