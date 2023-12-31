#include <Servo.h> 
 #include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   64
#define LOGO_WIDTH    64
static const unsigned char PROGMEM angry[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 
	0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 
	0x7f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0x7f, 0xf8, 0x3f, 0xff, 0xff, 0xfc, 0x1f, 0xfe, 
	0x7f, 0xfe, 0x03, 0xff, 0xff, 0xe0, 0x7f, 0xfe, 0x7f, 0xff, 0x80, 0x0f, 0xf0, 0x00, 0xff, 0xfe, 
	0x7f, 0xff, 0x00, 0x0f, 0xf0, 0x00, 0xff, 0xfe, 0x7f, 0xff, 0x03, 0xff, 0xff, 0xc0, 0xff, 0xfe, 
	0x3f, 0xff, 0x03, 0xff, 0xff, 0xc0, 0xff, 0xfe, 0x3f, 0xff, 0x87, 0xff, 0xff, 0xe1, 0xff, 0xfc, 
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
	0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x03, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x80, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM kiss[] =
{  
0xff, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 
	0xff, 0xf8, 0x00, 0x0f, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0x00, 0x0f, 0xff, 
	0xff, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xf8, 0x01, 0xff, 
	0xff, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 
	0xfe, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7f, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3f, 
	0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 
	0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 
	0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x07, 
	0xc0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
	0x80, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x01, 0x80, 0xff, 0xe0, 0x7f, 0xfc, 0x03, 0xff, 0x01, 
	0x81, 0xff, 0xc0, 0x3f, 0xf0, 0x00, 0xff, 0x81, 0x81, 0xff, 0xc0, 0x3f, 0xe0, 0x00, 0x7f, 0x81, 
	0x01, 0xff, 0xc0, 0x3f, 0xe0, 0x00, 0x7f, 0x80, 0x01, 0xff, 0xc0, 0x3f, 0xe0, 0x00, 0x7f, 0x80, 
	0x03, 0xff, 0xe0, 0x7f, 0xe1, 0xf8, 0x7f, 0xc0, 0x03, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x03, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xe0, 0x3f, 0xff, 0xff, 0xc0, 
	0x01, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0x80, 
	0x81, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0x81, 0x81, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0x81, 
	0x80, 0xff, 0xff, 0xfe, 0x07, 0xfe, 0x1f, 0x81, 0x80, 0xff, 0xff, 0xfc, 0x0f, 0xfc, 0x07, 0xc3, 
	0xc0, 0xff, 0xff, 0xf8, 0x1f, 0xf8, 0x07, 0xff, 0xc0, 0x7f, 0xff, 0xe0, 0x3f, 0xf0, 0x03, 0xff, 
	0xe0, 0x7f, 0xff, 0xe0, 0x3f, 0xf0, 0x03, 0xff, 0xe0, 0x3f, 0xff, 0xf8, 0x1f, 0xf0, 0x01, 0xff, 
	0xf0, 0x3f, 0xff, 0xfc, 0x0f, 0xf0, 0x01, 0x07, 0xf0, 0x1f, 0xff, 0xfe, 0x07, 0xf0, 0x00, 0x01, 
	0xf8, 0x0f, 0xff, 0xfe, 0x07, 0xf8, 0x00, 0x01, 0xf8, 0x07, 0xff, 0xfe, 0x07, 0xf8, 0x00, 0x00, 
	0xfc, 0x03, 0xff, 0xfc, 0x0f, 0xf8, 0x00, 0x00, 0xfe, 0x01, 0xff, 0xf8, 0x1f, 0xf8, 0x00, 0x00, 
	0xff, 0x00, 0xff, 0xe0, 0x3f, 0xfc, 0x00, 0x00, 0xff, 0x00, 0x7f, 0xf1, 0xff, 0xfc, 0x00, 0x00, 
	0xff, 0x80, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x01, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x03, 
	0xff, 0xf0, 0x00, 0xff, 0xff, 0x3e, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x0f, 0xf0, 0x1e, 0x00, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x00, 0x1e, 0x07, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff
};
static const unsigned char PROGMEM cry[] =
{ 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
	0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xe0, 
	0x0f, 0xf0, 0x3f, 0xff, 0xff, 0xfc, 0x0f, 0xf0, 0x0f, 0xfe, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xf0, 
	0x0f, 0xff, 0xc3, 0xff, 0xff, 0xc3, 0xff, 0xf0, 0x1f, 0xff, 0xe1, 0xff, 0xff, 0xc7, 0xff, 0xf8, 
	0x1f, 0xff, 0x03, 0xff, 0xff, 0xc0, 0xff, 0xf8, 0x1f, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xf8, 
	0x1f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3c, 
	0x20, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x04, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 
	0x01, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0x80, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0x80, 
	0x03, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xe0, 
	0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf8, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 
	0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 
	0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 
	0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 
	0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 
	0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 
	0x00, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0x00, 
	0x00, 0x7f, 0xfe, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x0f, 0xff, 0xfc, 0x00, 
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
	0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM amazed[] =
{ 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x4f, 0xff, 0xff, 0xf2, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 
	0x00, 0x04, 0x38, 0xff, 0xff, 0x0e, 0x20, 0x00, 0x00, 0x0c, 0xfc, 0xff, 0xff, 0x3f, 0x30, 0x00, 
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x1f, 0xff, 0x9f, 0xff, 0xff, 0xf9, 0xff, 0xf8, 0x1f, 0xff, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xf8, 
	0x1f, 0xfe, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xfc, 0x3f, 0xfe, 0x03, 0xff, 0xff, 0xe0, 0x3f, 0xfc, 
	0x3f, 0xfc, 0x03, 0xff, 0xff, 0xc0, 0x3f, 0xfc, 0x3f, 0xfc, 0x03, 0xff, 0xff, 0xc0, 0x3f, 0xfe, 
	0x7f, 0xfc, 0x03, 0xff, 0xff, 0xc0, 0x3f, 0xfe, 0x7f, 0xfc, 0x03, 0xff, 0xff, 0xc0, 0x3f, 0xfe, 
	0x7f, 0xfe, 0x03, 0xff, 0xff, 0xe0, 0x3f, 0xfe, 0x7f, 0xfe, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xfe, 
	0x7f, 0xfe, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0x7f, 0xff, 0x8f, 0xff, 0xff, 0xf8, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 
	0x7f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 
	0x7f, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xfe, 
	0x3f, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x3f, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xfc, 
	0x3f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x3f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xfc, 
	0x1f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x1f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf8, 
	0x0f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf0, 
	0x07, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x03, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xe0, 
	0x03, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x01, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0x80, 
	0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0xff, 0xfe, 0x00, 
	0x00, 0x3f, 0xff, 0x80, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x03, 0xff, 0xf8, 0x00, 
	0x00, 0x0f, 0xff, 0xe0, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x1f, 0xff, 0xe0, 0x00, 
	0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00
};
Servo myservo;
 
int min_pos = 34;
int max_pos = 170;

unsigned long last_click_timestamp = 0;
int fast_clicks = 0;
bool tease_mode = false;
 
void setup() 
{ 
  myservo.attach(2);
  myservo.write(min_pos);
  
  pinMode(4, INPUT_PULLUP);

  randomSeed(analogRead(0));

  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.clearDisplay();
  last_click_timestamp = millis();
} 

bool move_servo(int end_pos, int step_delay, bool look_for_switch)
{
  int cur_pos = myservo.read();
  if(cur_pos == end_pos)
  {
    return true;
  }
  int servo_step = cur_pos < end_pos ? 1 : -1;
  bool switching_state = (cur_pos >= end_pos);
  drawAngry();
  for(; cur_pos != end_pos; cur_pos += servo_step)
  {                                
    myservo.write(cur_pos);
    delay(step_delay);
    // If servo is moving forward - expect for switch off
    // if moving backward - switch on will break the loop
    if(look_for_switch && (digitalRead(4) == switching_state))
    {
      display.clearDisplay();
      return false;
    }
  } 
display.clearDisplay();
  return true;
}

void tease()
{
  const int tease_min_pos = 90;
  const int tease_max_pos = 120;

  Serial.println("Teasing!");
  drawAmazed();
  delay(600);
  move_servo(tease_min_pos, random(4, 6), false);
  delay(200 + random(2000));
  
  do
  {
    Serial.println("Tease loop!");

    if(digitalRead(4)) // User again clicked the switch
      return;
    
    move_servo(tease_max_pos, random(2, 6), false);
    delay(random(1000)); 
    move_servo(tease_min_pos, random(4, 6), false);
    delay(200 + random(2000));  
  }
  while(random(5) > 2);

  if(digitalRead(4)) // User again clicked the switch
    return;
  
  Serial.println("Exiting tease loop!");
  move_servo(min_pos, random(4, 6), false);
  
  // No longer tease
  if(random(5) > 2)
  {
    Serial.println("No longer tease!");
    tease_mode = false;
  }
  display.clearDisplay();
}

void check_for_bothering()
{
  const int fast_click_threshold = 2000; //2 seconds
  const int clicks_for_tease_mode = 4;

  unsigned long cur_timestamp = millis();
  
  
  if(cur_timestamp - last_click_timestamp > fast_click_threshold)
  {
    // If last click was to far back (normal user) - reset the clicks counter
    Serial.println("Slow Click!");
    drawCry();
    delay(600);
    fast_clicks = 0;
  }
  else
  {
    // Our user is nerd of clicking
    Serial.println("Fast Click!");
    fast_clicks++;
  }
  
  last_click_timestamp = cur_timestamp;
  
  // If user bother us with clicking - enter tease mode
  if(fast_clicks > clicks_for_tease_mode)
  {
    Serial.println("Tease mode");
    tease_mode = true;
  }
}

bool should_tease()
{
  const int tease_threshold = 4000; // 5 seconds after the last click

  unsigned long cur_timestamp = millis();

  // Check whether there was no action during last few seconds so we may tease
  if(tease_mode && (cur_timestamp - last_click_timestamp > tease_threshold))
    return true;
    
  return false;
}

void loop() 
{ 
  int speed1 = random(2, 5);
  int speed2 = random(2, 8);
   drawKiss();
  if(should_tease()){
    tease();
   display.clearDisplay();
  }
  //TODO Sleep while not turned on
  // Wait for click
  if(!digitalRead(4))
    return;
    
  //Serial.println("Turned on!");
  
  check_for_bothering();

  // Move forward until switch is off  
  move_servo(max_pos, speed1, true);

  //Serial.println("Turned off");
  
  // Now move backward until min pos or user clicked switch again
  move_servo(min_pos, speed2, true);
  
  //Serial.println("End of lopp");
} 
void drawAngry(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH )/2.5,
    (display.height() - LOGO_HEIGHT)/2,
    angry, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}
void drawAmazed(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH )/2.5,
    (display.height() - LOGO_HEIGHT)/2,
    amazed, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}
void drawCry(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH )/2.5,
    (display.height() - LOGO_HEIGHT)/2,
    cry, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}
void drawKiss(void) {
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH )/2.5,
    (display.height() - LOGO_HEIGHT)/2,
    kiss, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}