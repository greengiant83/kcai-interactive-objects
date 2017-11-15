#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 6, NEO_GRB + NEO_KHZ800);
void setup() 
{
  Serial.begin(9600);
  Serial.println("Your in!");

  strip.begin();
}

void loop() 
{
  if(Serial.available())
  {
    String command = Serial.readStringUntil('\n');
    int count = command.toInt();
    strip.clear();
    for(int i=0;i<count;i++)
    {
      strip.setPixelColor(i, 0x0000ff);
    }
    strip.show();
  }

}
