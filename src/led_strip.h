#pragma once
#include <stdbool.h>
#include <stdint.h>

#include "effects.h"

typedef struct {
    uint8_t r, g, b;
} color;

#ifdef __cplusplus
#include <vector>
extern "C" {
#endif

void reset(void);
void set_pixel(int pixel, color led);
void fill_strip(void);
void set_brightness(uint8_t brightness);
void set_effect(Effect effect);
void update_effect(void);
void update_effect_timed(uint32_t timeGone);
bool should_update_effect(Effect newEffect);

#ifdef __cplusplus
}
void set_pixels(const std::vector<color> &payload, int zone);
#endif
