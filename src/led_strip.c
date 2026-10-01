#include "led_strip.h"



void reset(void) {}

void set_pixels(const color *payload, int count) {}

void set_pixel(int pixel, color led) {}

void fill_strip(void) {}

void set_brightness(uint8_t brightness) {}

void set_effect(Effect effect) {}

void update_effect(void) {}

void update_effect_timed(uint32_t timeGone) {}

bool should_update_effect(Effect newEffect) {
    return true;
}
