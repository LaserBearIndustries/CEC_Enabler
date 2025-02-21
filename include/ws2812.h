#ifndef WS2812_H
#define WS2812_H

#include <stdint.h>

void ws2812_init(void);
void put_rgb(uint8_t red, uint8_t green, uint8_t blue);
void put_pixel(uint32_t pixel_grb);

#endif // WS2812_H