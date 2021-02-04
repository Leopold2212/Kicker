#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_

#include <Arduino.h>

#include "Animator.h"

enum AnimationType {
    SCORE_SLOW,
    SCORE_FAST,
    READY,

    GOAL_ANIMATIONS_START,
    // Goals
    BLINK,
    FADE,
    CHICKEN_DINNER,
    STAIRCASE,
    STARWARS,
    HOMERUN,
    WINDOWS,

    // Always last
    SIZE
};

#define ANIMATION_INFO_SIZE 2

struct AnimationInfo {
    Color color;
    int values[ANIMATION_INFO_SIZE];
};

// Score Animations
void scoreSlow_Animation(Strip strip, AnimationInfo info);
void scoreFast_Animation(Strip strip, AnimationInfo info);

// Ready Animation
void ready_Animation(Strip strip, AnimationInfo info);

// Celebration Animations
void blink_Animation(Strip strip, AnimationInfo info);
void fade_Animation(Strip strip, AnimationInfo info);
void chickenDinner_Animation(Strip strip, AnimationInfo info);

// Helper Animations
void flash(Strip strip, Color color, int length);
void setupStrip(Strip strip, int brightness);

#endif
