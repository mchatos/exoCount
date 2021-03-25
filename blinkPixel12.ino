#include <Adafruit_NeoPixel.h>
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 12 // Popular NeoPixel ring size

// see the strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000 // Time (in milliseconds) to pause between pixels
#define BRIGHTNESS 10

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  blinkPixel(12);
}

void blinkPixel(int temps){

  pixels.clear(); // Set all pixel colors to 'off'

  int secondes = temps / NUMPIXELS;
  int untiers = temps / 3;
  int deuxtiers = untiers * 2;
  int fin = temps - 1;
  
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    
    if (i < deuxtiers){
      pixels.setPixelColor(i, pixels.Color(0, 150, 0)); //GREEN
    }

    if ( i >= deuxtiers && i <= fin ){
      for(int j=0; j<=i; j++) { // For each seconds...
        pixels.setPixelColor(j, pixels.Color(255, 255, 0)); //YELLOW
        }
    }
    
    if (i >= fin){
      pixels.fill(pixels.Color(255, 0, 0));
   }

    pixels.show();   // Send the updated pixel colors to the hardware.

    for(int k=0; k<secondes; k++) { // For each seconds...
        delay(DELAYVAL);
    }
  }
}
