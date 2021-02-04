#include "Animations.h"

/* Score Slow Animation
    Info:
    [0] = number of goals
*/
void scoreSlow_Animation(Strip strip, AnimationInfo info) {
    for(int i = 0; i < info.values[0]; i++) {
        strip.setPixelColor(i, info.color);
        strip.show();
        delay(70);
    }
}

/* Score Fast Animation
    Info:
    [0] = number of goals
*/
void scoreFast_Animation(Strip strip, AnimationInfo info) {
    for(int i = 0; i < info.values[0]; i++) {
        strip.setPixelColor(i, info.color);
        strip.show();
    }
}

/* Ready Animation
    Info:
    -
*/
void ready_Animation(Strip strip, AnimationInfo info) {
    flash(strip, info.color, 150);
    delay(150);
    flash(strip, info.color, 150);
    delay(150);
    flash(strip, info.color, 300);
}

/* Blink Animation
    Info:
    -
*/
void blink_Animation(Strip strip, AnimationInfo info) {
    for(int i = 0; i < 8; i++) {
        flash(strip, info.color, 100);
        delay(100);
    }
}

/* Fade Animation
    Info:
    -
*/
void fade_Animation(Strip strip, AnimationInfo info) {
    strip.setBrightness(1);
    strip.fill(info.color);
    strip.show();

    for(int i = 0; i < 8; i++) {
        for(int brightness = 1; brightness <= 255; brightness += 2) {
            strip.setBrightness(brightness);
            strip.show();
            delay(1);
        }
        for(int brightness = 255; brightness >= 1; brightness -= 2) {
            strip.setBrightness(brightness);
            strip.show();
            delay(1);
        }
    }
}

/* Chicken Dinner Animation
    Info:
    -
*/
void chickenDinner_Animation(Strip strip, AnimationInfo info) {
    for(int i = 0; i <= 5; i++) {
        int j = 9 - i;
        strip.setPixelColor(i, info.color);
        strip.show();
        delay(100);
        strip.setPixelColor(j, info.color);
        strip.show();
        delay(100);
    }
}

/* Flash Helper Animation */
static void flash(Strip strip, uint32_t color, int length) {
    strip.clear();
    strip.fill(color);
    strip.show();
    delay(length);
    strip.clear();
    strip.show();
}

/* setup Helper Function */
static void setupStrip(Strip strip, int brightness) {
    strip.clear();
    strip.setBrightness(brightness);
}
