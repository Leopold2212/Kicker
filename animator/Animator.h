#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include <Arduino.h>

#include "Animations.h"

typedef Color uint32_t;

class Strip {
public:
    virtual void setColor(int led, Color color) = 0;
    virtual void setBrightness(int led, uint8_t brightness) = 0;
    virtual void show() = 0;
    virtual int  getLength() = 0;
};

template<int MAX_STRIPS>
class Animator {
private:
    Strips m_strips[MAX_STRIPS];
    int m_stripsCount = 0;

public:
    static Animator& get() {
        static Animator instance;
        return instance;
    }

    static int addStrip(Strip strip) {
        return get().addStripImpl(strip);
    }

    static void play(const int stripIndex,const AnimationType& type, const AnimationInfo& info) {
        get().playImpl(type, info);
    }

    static void playRand(const int stripIndex, const AnimationInfo& info) {
        get().playRandImpl(info);
    }

    static void playAll(const AnimationType& type, const AnimationInfo& info) {
        get().playAllImpl(type, info);
    }

    static void playRandAll(const AnimationInfo& info) {
        get().playRandAllImpl(info);
    }

private:
    int  addStripImpl(Strip& strip);

    void playImpl(const int stripIndex, const AnimationType& type, const AnimationInfo& info);
    void playRandImpl(const int stripIndex, const AnimationInfo& info);
    void playAllImpl(const AnimationType& type, const AnimationInfo& info);
    void playRandAllImpl(const AnimationInfo& info);

public:
    Animator(const Animator&) = delete;

private:
    Animator() {};
};

#endif
