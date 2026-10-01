#define PICO_GAME_CONTROLLER_C
#include "led_strip.h"
#include "tusb.h"
#include "controller_config.h"
#include "PicoLed.hpp"

auto strip = PicoLed::addLeds<PicoLed::WS2812B>(pio1, 1, WS2812B_GPIO, WS2812B_LED_SIZE, PicoLed::FORMAT_GRB);

void reset(void)
{
}

void set_pixels(const std::vector<color> &payload, int zone)
{
    const size_t count = std::min<size_t>((size_t)WS2812B_LEDS_PER_ZONE, payload.size());
    const size_t offset = zone * WS2812B_LEDS_PER_ZONE;
    for (size_t i = 0; i < count; ++i)
        strip.setPixelColor(offset + i, PicoLed::RGB(payload[i].r, payload[i].g, payload[i].b));
    strip.show();
}

void set_pixel(int pixel, color led)
{
    strip.setPixelColor(pixel, PicoLed::RGB(led.r, led.g, led.b));
}

void fill_strip(void)
{
    strip.show();
}

void set_brightness(uint8_t brightness)
{
    strip.setBrightness(brightness);
    strip.show();
}

void set_effect(Effect effect) {}

void update_effect(void) {}

void update_effect_timed(uint32_t timeGone) {}

bool should_update_effect(Effect newEffect)
{
    return true;
}
