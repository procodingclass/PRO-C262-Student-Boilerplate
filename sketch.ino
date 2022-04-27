#include <Adafruit_NeoPixel.h>

const byte data_pin = 15;
const byte led_num = 16;
const int pir_pin = 2;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_num, data_pin, NEO_GRB + NEO_KHZ800);

void setup() 
{
  Serial.begin(115200);
  pinMode(pir_pin , INPUT);

  pixels.begin(); // initialize the library
  pixels.show();
}

void loop() 
{
  //  if motion is detected
  Serial.println(digitalRead(pir_pin));
  if (digitalRead(pir_pin)  ==  1){
    generate_random_pattern();
  }

  //  for better working of simulator
  delay(10);
}

void generate_random_pattern(){
  pixels.setPixelColor(0,255,0,0);
  pixels.show();
}