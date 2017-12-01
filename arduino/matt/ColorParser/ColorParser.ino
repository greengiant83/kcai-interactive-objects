int brightness = 0;
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String msg = "56&255&12&34"; //assume brightess, red, green, blue
  brightness = getValue(msg, '&', 0).toInt();
  red = getValue(msg, '&', 1).toInt();
  green = getValue(msg, '&', 2).toInt();
  blue = getValue(msg, '&', 3).toInt();
  
  Serial.print("brightness: ");
  Serial.println(brightness);

  Serial.print("r: ");
  Serial.println(red);

  Serial.print("g: ");
  Serial.println(green);

  Serial.print("b: ");
  Serial.println(blue);
  
}

void loop() 
{
  if(Serial.available() > 0)
  {
    String command = Serial.readStringUntil('\n');  
    Serial.print("I heard this: ");
    Serial.println(command);
  }
}

// https://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
