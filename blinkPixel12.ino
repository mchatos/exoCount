#include <Adafruit_NeoPixel.h>

#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 12 // Popular NeoPixel ring size
#define DELAYVAL 1000 // Time (in milliseconds) to pause between pixels
#define BRIGHTNESS 10
#define TIME 1000

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop()
{
  pixels.clear();
  rest(25);
  delay(100000); // Wait for 1000 millisecond(s)
}

void rest(float secondes)
{

  int count = 0;
  
  int greenTime = round((66*secondes)/100);
  int redTime = int(secondes);
  int ledOnTime = calcLedOnTime(secondes);
  
  Serial.println(ledOnTime);
  Serial.println(secondes);
  Serial.println(greenTime);
  
  while (count < greenTime){
    Serial.println("greenTime");
    Serial.println(count);
    ledOnGreenLight(count, ledOnTime);
    blinkWait();
    count++;
  }

  for(int j=0; j<=count; j++) {
    ledOnYellowLight(j, ledOnTime);
  }

  while (count < redTime){
    Serial.println("yellowTime");
    Serial.println(count);
    ledOnYellowLight(count, ledOnTime);
    blinkWait();
    count++;
  }
  
  if (count = redTime){
    Serial.println("redTime");
    ledOnRedLight();
    blinkWait();
    Serial.println("fin");
  }

}

int calcLedOnTime(int x){

  int onTime;
  onTime=(x/NUMPIXELS);
  return onTime;
}

void ledOnGreenLight(int x, int ledOnTime){

  int led;
  led=(x/ledOnTime);
  //Serial.println("Green Led");
  //Serial.println(led);
  pixels.setPixelColor(led, pixels.Color(0, 255, 0)); //GREEN
  pixels.show();
}

void ledOnYellowLight(int x, int ledOnTime){

  int led;
  led=(x/ledOnTime);
  //Serial.println("Yellow Led");
  //Serial.println(led);
  pixels.setPixelColor(led, pixels.Color(255, 255, 0)); //YELLOW
  pixels.show();
}

void ledOnRedLight(){
  pixels.fill(pixels.Color(255, 0, 0));
  pixels.show();
}

void blinkWait(){
  
  digitalWrite(13, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(13, LOW);
  delay(500); // Wait for 500 millisecond(s)
  
}
