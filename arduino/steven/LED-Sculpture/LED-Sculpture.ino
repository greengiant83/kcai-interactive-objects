#include <Adafruit_NeoPixel.h>
String command;
int numLights;
int color;
int rgb[] = {255, 255, 255};
int brightness = 100;
int power = 1;
int lastb = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(6, 9, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
  pixels.begin();
   pixels.setBrightness(100);
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
      brightness = command.toInt();
      switch (brightness) {
        case 1:
          pixels.setBrightness(10);
          lastb = 10;
          break;
        case 2:
          pixels.setBrightness(20);
          lastb = 20;
          break;
        case 3:
          pixels.setBrightness(30);
          lastb = 30;
          break;
        case 4:
          pixels.setBrightness(40);
          lastb = 40;
          break;
        case 5:
          pixels.setBrightness(50);
          lastb = 50;
          break;
        case 6:
          pixels.setBrightness(60);
          lastb = 60;
          break;
        case 7:
          pixels.setBrightness(70);
          lastb = 70;
          break;
        case 8:
          pixels.setBrightness(80);
          lastb = 80;
          break;
        case 9:
          pixels.setBrightness(90);
          lastb = 90;
          break;
        case 10:
          pixels.setBrightness(100);
          lastb = 100;
          break;
        default:
          pixels.setBrightness(100);
          break;
      }
    }
    else if (command.indexOf('p') > 0) {
      command.remove('p');
      power = command.toInt();
    } if (power == 0) {
      pixels.setBrightness(0);
      pixels.show();
    } else if (power == 1) {
      for (int i = 0; i < numLights; i++) {
        pixels.setBrightness(lastb);
        pixels.setPixelColor(i, pixels.Color(rgb[0], rgb[1], rgb[2]));

      }
      pixels.show();
    }
  }
}
