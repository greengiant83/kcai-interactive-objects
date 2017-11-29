#include <Stepper.h>
#include <Servo.h> 
#include <Adafruit_NeoPixel.h>
int motorPin = 13;
int motorPin2 = 12;
Servo myservo;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, 6, NEO_GRB + NEO_KHZ800);
int currentChannel;
bool isPowerOn;

void setup() {
  Serial.begin(9600);
   myservo.attach(9);
  myservo.write(90);
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  if(Serial.available())
  {
     String command = Serial.readStringUntil('\n');
     if(command == "Power") 
         PowerButtonPressed();
     if(command == "ChannelIncrease") 
         channelUp();
     if(command == "ChannelDown") 
         channelDown();
  }
     
}

void PowerButtonPressed()
{
  isPowerOn = ! isPowerOn;
  if (isPowerOn == true)
  {
    updateChannel();
  }
  else
  {
    houselightsoff();
    doorClosed();
    churchlightsoff();
  }
}

void channelUp()
{
  currentChannel++;
  if (currentChannel > 5) currentChannel = 1;
  updateChannel();

}

void channelDown()
{
  currentChannel--;
  if (currentChannel < 1) currentChannel = 5;
  updateChannel();

}

void updateChannel()
{
  if (currentChannel == 1)
  {
    openDoor();
    churchlightson();
    houselightson();
  }

  if (currentChannel == 2)
  {
    openDoor();
    churchlightson();
    houselightson();
  }

  if (currentChannel == 3)
  {
    openDoor();
    churchlightson();
    houselightson();
  }

  if (currentChannel == 4)
  {
    openDoor();
    churchlightson();
    houselightson();
  }

  if (currentChannel == 5)
  {
    openDoor();
    churchlightson();
    houselightson();
  }

}

void openDoor()

{

}

void doorClosed()

{

}

void churchlightson()

{
  Serial.println("church lights are on");
}

void churchlightsoff()
{
  Serial.println("church lights are off");
}

void houselightson()
{
  Serial.println("house lights are on boi");
}

void houselightsoff()
{
  Serial.println("house lights are off");
}

void grinch()
{

}

void treemovement()
{

}


