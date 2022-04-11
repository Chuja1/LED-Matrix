#include <FastLED.h>

/*
 * LED MATRIX FUNCTIONS BY JUSTIN CHU
 * ECE 387
 * USES LIBRARY FASTLED
 * THIS FILE INCLUDES MULTIPLE DIFFERENT FUNCTIONS THAT HELP WITH 
 * WRITING AND USING THE LED MATRIX
 * THIS FILE CAN SET ALL LEDS ON, ALL OFF, 
 * ENABLE CERTAIN LEDS TO TURN ON, CHANGE
 * COLOR OF CURRENT LEDS, AND DISPLAY A 
 * SIMPLE SNAKING PATTERN
 */
 
#include <FastLED.h>

// Define number of leds in matrix and output pin
#define NUM_LEDS 256
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS);
  
}

void loop() {
  //Place any looping code here

}


//All functions below are to help with accomplishing basic functions of the LED matrix quickly

void LEDAllOff() {
  //Sets all LEDs off
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(0, 0, 0);
  }
  FastLED.show();
}

void LEDAllOn(int g, int r, int b) {
  //Sets all LEDs on with given color mapping
  for(int i = 0; i < NUM_LEDS; i++){
   leds[i] = CHSV(g, r, b);
  }
  FastLED.show();
}

void LEDChangeOn(int g, int r, int b) {
  //Change all current LEDs that are on to given color mapping
  for(int i = 0; i < NUM_LEDS; i++) {
    if(leds[i] != CRGB(0)) {
      leds[i] = CHSV(g, r, b);
    }
  }
  FastLED.show();
}

void LEDTrace(int g, int r, int b) {
  //Send a dot from the start to the end of the matrix in a snake pattern
  for(int i = 0; i < NUM_LEDS; i++){
   leds[i] = CHSV(g, r, b);
   if(i !=0) {
     leds[i-1] = CHSV(0,0,0);
   }
  FastLED.show();
  delay(100);
  }
  leds[255] = CHSV(0, 0, 0);
  FastLED.show();
}

void LEDSelectOn(int s[], int arrayLength, int g, int r, int b) {
  //Takes in array of desired LEDs and array size and sets them to given color
  //Can be used to turn select off by setting g r and b to 0
  int currLED = 0;
  for(int i = 0; i<arrayLength; i++) {
    currLED = s[i];
    leds[currLED] = CHSV(g, r, b);
  }
  FastLED.show();
  
}
