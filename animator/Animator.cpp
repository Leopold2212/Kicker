#include "Animator.h"

#define STD_BRIGHTNESS 255

int Animator::addStripImpl(Strip strip) {
    if(m_stripsCount < MAX_STRIPS) {
        m_strips[m_stripsCount] = strip;
        return m_stripsCount++;
    }

    return -1;
}

void animator_play(Strip strip, AnimationType type, AnimationInfo info) {
    setupStrip(strip, STD_BRIGHTNESS);

    switch(type) {
        case AnimationType::SCORE_SLOW:
            scoreSlow_Animation(strip, info);
            break;
        case AnimationType::SCORE_FAST:
            scoreFast_Animation(strip, info);
            break;
        case AnimationType::READY:
            ready_Animation(strip, info);
            break;
        case AnimationType::BLINK:
            blink_Animation(strip, info);
            break;
        case AnimationType::FADE:
            fade_Animation(strip, info);
            break;
        case AnimationType::CHICKEN_DINNER:
            chickenDinner_Animation(strip, info);
            break;
        default:
            blink_Animation(strip, info);
    }
}

void animator_playRand(Strip strip, AnimationInfo info) {
    animator_play(strip, random(AnimationType::GOAL_ANIMATIONS_START-1, AnimationType::SIZE), info);
}
