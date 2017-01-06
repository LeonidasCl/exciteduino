#include <Wire.h>
#include <CN_SSD1306_Wire.h>
#include "U8glib.h"
#include "codetab.c"   //codetab


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);	// I2C / TWI  constructor of ssd1306 oled

CN_SSD1306_Wire lucky(8);//HardWare I2C


const uint8_t rook_bitmap[] PROGMEM = {
  0x00,         // 00000000 
  0x55,         // 01010101
  0x7f,          // 01111111
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x3e,         // 00111110
  0x3e,         // 00111110 
  0x7f           // 01111111
};

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.drawBitmapP( 0, 0, 1, 8, rook_bitmap);
}

void setup()
{
  lucky.Initial();
  delay(10);
}

void loop()
{
  
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(2000);
  
  unsigned char i;
  lucky.Fill_Screen(0xff,0xff);
  delay(2000);
  lucky.Fill_Screen(0x00,0x00);
  for(i=0;i<=3;i++)
  {
    //parameters: 1st:x axis coordinator  2nd:y axis coordinator 3rd:CN number in codetab.c 
    lucky.ShowCN(0+i*16,i*2,i);
    lucky.ShowCN(16+i*16,i*2,4);
    lucky.ShowCN(32+i*16,i*2,5);
    lucky.ShowCN(48+i*16,i*2,6);
  }
  delay(5000);
}
