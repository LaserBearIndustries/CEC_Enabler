#include <stdint.h>
#include <stdlib.h>

#include "ws2812.pio.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"
#include "ws2812.h"

void put_pixel(uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}
void put_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    uint32_t mask = (green << 16) | (red << 8) | (blue << 0);
    put_pixel(mask);
}

void ws2812_init(void)
{
PIO pio = pio0;
int sm = 0;
uint offset = pio_add_program(pio, &ws2812_program);

ws2812_program_init(pio, sm, offset, 16, 800000, true);
}