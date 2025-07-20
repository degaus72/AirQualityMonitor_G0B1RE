#ifndef ST7789_H
#define ST7789_H

#include <fonts.h> // Include font definitions
#include "main.h" // For HAL types and configurations
#include "spi.h"  // For SPI handle
#include "gpio.h" // For GPIO control

// --- Pin Definitions (Adjust based on your CubeIDE configuration) ---
#define LCD_DC_GPIO_Port     GPIOA
#define LCD_DC_Pin           GPIO_PIN_8

#define LCD_RST_GPIO_Port    GPIOB
#define LCD_RST_Pin          GPIO_PIN_14

#define LCD_CS_GPIO_Port     GPIOB
#define LCD_CS_Pin           GPIO_PIN_6

#define LCD_BL_GPIO_Port     GPIOC
#define LCD_BL_Pin           GPIO_PIN_7

// --- Display Dimensions ---
#define ST7789_WIDTH  240
#define ST7789_HEIGHT 280

// --- Color Definitions (RGB565) ---
#define ST7789_BLACK       0x0000
#define ST7789_NAVY        0x000F
#define ST7789_DARKGREEN   0x03E0
#define ST7789_DARKCYAN    0x03EF
#define ST7789_MAROON      0x7800
#define ST7789_PURPLE      0x780F
#define ST7789_OLIVE       0x7BE0
#define ST7789_LIGHTGREY   0xC618
#define ST7789_DARKGREY    0x7BEF
#define ST7789_BLUE        0x001F
#define ST7789_GREEN       0x07E0
#define ST7789_CYAN        0x07FF
#define ST7789_RED         0xF800
#define ST7789_MAGENTA     0xF81F
#define ST7789_YELLOW      0xFFE0
#define ST7789_WHITE       0xFFFF
#define ST7789_ORANGE      0xFD20
#define ST7789_GREENYELLOW 0xAFE5
#define ST7789_PINK        0xFC18

// --- Command Definitions ---
#define ST7789_NOP          0x00
#define ST7789_SWRESET      0x01
#define ST7789_RDDID        0x04
#define ST7789_RDDST        0x09
#define ST7789_SLPIN        0x10
#define ST7789_SLPOUT       0x11
#define ST7789_PTLON        0x12
#define ST7789_NORON        0x13
#define ST7789_INVOFF       0x20
#define ST7789_INVON        0x21
#define ST7789_DISPOFF      0x28
#define ST7789_DISPON       0x29
#define ST7789_CASET        0x2A
#define ST7789_RASET        0x2B
#define ST7789_RAMWR        0x2C
#define ST7789_RAMRD        0x2E
#define ST7789_PTLAR        0x30
#define ST7789_VSCRDEF      0x33
#define ST7789_TEAROFF      0x34
#define ST7789_TEARON       0x35
#define ST7789_MADCTL       0x36
#define ST7789_IDMOFF       0x38
#define ST7789_IDMON        0x39
#define ST7789_COLMOD       0x3A
#define ST7789_WRMEMC       0x3C
#define ST7789_RDMEMC       0x3E
#define ST7789_PWCTRL1      0xC0
#define ST7789_PWCTRL2      0xC1
#define ST7789_VMCTR1       0xC3
#define ST7789_VMCTR2       0xC4
#define ST7789_RDID1        0xDA
#define ST7789_RDID2        0xDB
#define ST7789_RDID3        0xDC
#define ST7789_RDID4        0xDD
#define ST7789_GMCTRP1      0xE0
#define ST7789_GMCTRN1      0xE1

#define FONT_START_ASCII 32
#define FONT_END_ASCII 126
#define FONT_TOTAL_CHARS (FONT_END_ASCII - FONT_START_ASCII + 1) // This calculates 95

// --- Function Prototypes ---
void ST7789_Init(SPI_HandleTypeDef *hspi);
void ST7789_FillScreen(uint16_t color);
void ST7789_DrawPixel(int16_t x, int16_t y, uint16_t color);
void ST7789_DrawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void ST7789_DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void ST7789_DrawChar(int16_t x, int16_t y, char ch, const sFONT *font, uint16_t color, uint16_t background_color);
void ST7789_DrawString(int16_t x, int16_t y, const char* str, const sFONT *font, uint16_t color, uint16_t background_color);
void ST7789_FillRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void ST7789_WriteString(int16_t x, int16_t y, const char* str, const sFONT *font, uint16_t color, uint16_t bgcolor);
void ST7789_SetRotation(uint8_t m); // 0, 1, 2, 3 for 0, 90, 180, 270 degrees
void ST7789_DisplayOn(void);
void ST7789_DisplayOff(void);
void ST7789_SetBacklight(uint8_t state); // 0 = OFF, 1 = ON

// Internal functions (do not call directly)
void ST7789_WriteCommand(uint8_t cmd);
void ST7789_WriteData(uint8_t *buff, size_t buff_size);
void ST7789_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

#endif /* ST7789_H */
