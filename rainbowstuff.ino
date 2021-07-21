
#include <FastLED.h>
#define LED_PIN     12
#define NUM_LEDS    60
int bright = 50;
int lednum = 60;
int timerforcoldelay = 75;
CRGB leds[NUM_LEDS];
uint8_t hue = 0;
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setBrightness(100);
}

void loop() {
 wave();
 //zoom();
//fade_random_color();

}

void fade_random_color()
{
  fill_solid(leds,NUM_LEDS, CRGB(random(255), random(255), random(255)));
for(int x = 0; x <= bright; x++)
{
  FastLED.setBrightness(x);
  FastLED.show();
  delay(timerforcoldelay);
}
for(int x = bright; x >=0; x--)
{
  FastLED.setBrightness(x);
  FastLED.show();
  delay(timerforcoldelay);
}
}


void wave()
{
    FastLED.setBrightness(100);
  for (int i = 0; i < NUM_LEDS; i+=1) {
    //leds[i] = CRGB(120, 255, 15);
    leds[i] = CHSV(hue + (i * 8), 255,255);
  }
  
  FastLED.show();

  
EVERY_N_MILLISECONDS(8)
{
  hue++;
}
}

void zoom()
{
   FastLED.setBrightness(200);
   for(int x = 0; x < NUM_LEDS; x++)
   {
    if (x <= 30)
    {
      leds[x] = CRGB(255,000,000);
    }
    else
    {
      leds[x] = CRGB(255,0,255);
    }
   }
   FastLED.show();
}
