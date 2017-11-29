int i = 0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("Begin");
}

void loop() 
{
  Serial.print("I like the number ");
  Serial.println(i);
  i = (i + 1) % 10;
  delay(500);
}
