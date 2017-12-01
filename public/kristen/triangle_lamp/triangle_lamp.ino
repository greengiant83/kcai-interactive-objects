#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 9, NEO_GRB + NEO_KHZ800);

int brightness = 0;
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    
    int brightness = getValue(command, '&', 0).toInt();
    int red = getValue(command, '&', 1).toInt();
    int green = getValue(command, '&', 2).toInt();
    int blue = getValue(command, '&', 3).toInt();

  /*  Serial.print("brightness: ");
    Serial.println(brightness);

    Serial.print("r: ");
    Serial.println(red);

    Serial.print("g: ");
    Serial.println(green);

    Serial.print("b: ");
    Serial.println(blue); */

    for (int i = 0; i < 61; i++) {
      strip.setPixelColor(i, red, green, blue);
      strip.setBrightness(brightness);
    }
    strip.show();
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
