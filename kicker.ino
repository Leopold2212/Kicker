#ifndef MAIN_
#define MAIN_

#include <Chrono.h>
#include <LightChrono.h>
#include <Adafruit_NeoPixel.h>

#include "Game.h"

// Pins
#define PIN_SENSOR_S04  2
#define PIN_SENSOR_BVB  3

#define PIN_STRIP_S04   6
#define PIN_STRIP_BVB   7

#define PIN_BUZZER      12

// LED Strip
#define STRIP_SIZE 10
Adafruit_NeoPixel stripS04(STRIP_SIZE, PIN_STRIP_S04, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripBVB(STRIP_SIZE, PIN_STRIP_BVB, NEO_GRB + NEO_KHZ800);

// Game
Game game(stripS04, stripBVB);

void setup() {
   pinMode(PIN_SENSOR_S04, INPUT);
   pinMode(PIN_SENSOR_BVB, INPUT);
   pinMode(PIN_BUZZER, OUTPUT);
   
   Serial.begin(9600);
}

void loop() {
   if(has_ball_entered_goal(PIN_SENSOR_S04)) {
      game.score(Team::S04);
   }
   if(has_ball_entered_goal(PIN_SENSOR_BVB)) {
      game.score(Team::BVB);
   }
}

bool has_ball_entered_goal(int pin) {
   return digitalRead(pin) == HIGH;
}

#endif