RGB_MATRIX_EFFECT(ISRAEL_EFFECT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define C_B {0,   0,   255}
#define C_W {255, 255, 255}

static const RGB static_image_map[82] = {
    C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B,
    C_W, C_W, C_W, C_W, C_W, C_B, C_W, C_B, C_W, C_B, C_W, C_W, C_W, C_W, C_W,
    C_W, C_W, C_W, C_W, C_W, C_B, C_W, C_W, C_B, C_W, C_W, C_W, C_W, C_W, C_W,
    C_W, C_W, C_W, C_W, C_W, C_B, C_W, C_W, C_B, C_W, C_W, C_W, C_W, C_W,
    C_W, C_W, C_W, C_W, C_B, C_W, C_B, C_W, C_B, C_W, C_W, C_W, C_W,
    C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B, C_B
};

static bool ISRAEL_EFFECT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t brightness = rgb_matrix_config.hsv.v;

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        RGB color = static_image_map[i];

        uint8_t r = scale8(color.r, brightness);
        uint8_t g = scale8(color.g, brightness);
        uint8_t b = scale8(color.b, brightness);

        rgb_matrix_set_color(i, r, g, b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
