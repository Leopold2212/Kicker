#include <Chrono.h>
#include <LightChrono.h>

#include <Adafruit_NeoPixel.h>

// Pins
#define pinLight 2
#define pinLed 6
#define laengeStreifen 10
#define buzzer 12

// Light
bool light_sensor = false;

Adafruit_NeoPixel pixels(laengeStreifen, pinLed, NEO_GRB + NEO_KHZ800);
Chrono sperrzeit;
Chrono blinkzeit;

int score = -1;

void setup() 
{
   pinMode(2, INPUT);
   pinMode(12, OUTPUT);
   Serial.begin(9600);
   pixels.begin();
}

void loop() 
{
   checkSensor();
   
   if(light_sensor && sperrzeit.hasPassed(2500) && score<9)
   {
    score++ ;
    tone(12, 280, 1150);
    sperrzeit.restart();
    setLedStrip(score);
   }
 
  else if (score == 9)
   {
    chickenDinnner();
    score = -1;
    pixels.clear();
    pixels.show();
   }
}


void checkSensor() 
{
  if(digitalRead(pinLight) == HIGH) {
    light_sensor = true;
  } 
  else 
  {
    light_sensor = false;
  }
}

void setLedStrip(int score)
{
   blink_(score);
   pixels.setPixelColor(score, pixels.Color(0,150,0));
   pixels.show();
}

void chickenDinnner()
{
  for(int i=0; i<=5; i++)
  {
     int j = 9-i;
     pixels.setPixelColor(i, pixels.Color(0,0,150));
     pixels.show();
     delay(100);
     pixels.setPixelColor(j, pixels.Color(0,0,150));
     pixels.show();
     delay(100);
  }
  
}

void blink_(int score)
{
    blinkzeit.restart();
    while(!(blinkzeit.hasPassed(2500)))
    {
       pixels.setPixelColor(score, pixels.Color(0,150,0));
       pixels.show();
    
       delay(250);
       pixels.setPixelColor(score, pixels.Color(0,0,0));
       pixels.show();
       delay(250);
    }
    
}
