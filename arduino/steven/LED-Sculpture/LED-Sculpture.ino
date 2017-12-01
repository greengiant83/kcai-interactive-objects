#include <Adafruit_NeoPixel.h>
String command;
int numLights;
int color;
int rgb[] = {255, 255, 255};
int power = 1;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(6, 9, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
  numLights = 6;
}
void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    pixels.clear();
    if (command.indexOf("c") > 0) {
      command.remove('c');
      color = command.toInt();
      switch (color) {
        case 1:
          //red//
          rgb[0] = 255;
          rgb[1] = 0;
          rgb[2] = 0;
          break;
        case 2:
          //yellow//
          rgb[0] = 255;
          rgb[1] = 255;
          rgb[2] = 0;
          break;
        case 3:
          //green//
          rgb[0] = 0;
          rgb[1] = 255;
          rgb[2] = 0;
          break;
        case 4:
          //cyan//
          rgb[0] = 0;
          rgb[1] = 255;
          rgb[2] = 255;
          break;
        case 5:
          //blue//
          rgb[0] = 0;
          rgb[1] = 0;
          rgb[2] = 255;
          break;
        case 6:
          //magenta//
          rgb[0] = 255;
          rgb[1] = 0;
          rgb[2] = 255;
          break;
        case 7:
          rgb[0] = 255;
          rgb[1] = 255;
          rgb[2] = 255;
          break;
      }
    }
    else if (command.indexOf('b') > 0) {
      command.remove('b');
      pixels.setBrightness(command.toInt()*10);
    }
    else if (command.indexOf('p') > 0) {
      command.remove('p');
      power = command.toInt();
    } if (power == 0) {
      pixels.clear();
      pixels.show();
    } else if (power == 1) {
      for (int i = 0; i < numLights; i++) {
        pixels.setPixelColor(i, pixels.Color(rgb[0], rgb[1], rgb[2]));
      }
      pixels.show();
    }
  }
}
