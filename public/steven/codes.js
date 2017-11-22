var slider = document.getElementById("Color");
var slider2 = document.getElementById("Brightness");
var buttonImage = document.getElementById("buttonImage");
var isOn = true;
var color = 1;
var brightness = 0;

var socket = io();
socket.on('news', function (data) {
  console.log(data);

});

function turnOn()
{
  console.log("Turning on...");
  socket.emit('msg', "10");
}

function turnOff()
{
  console.log("Turning off...");
  socket.emit('msg', "0");
}

color = slider.value;
brightness = slider2.value;
slider.oninput = function()
{
  color = this.value;
  color = color + "c";
  console.log("Color: " + color);
  socket.emit('msg', color);
}
slider2.oninput = function()
{
  brightness = this.value;
  console.log("Brightness: " + brightness);
  socket.emit('msg', brightness + "b");
}

function buttonPressed()
{
  if(isOn)
  {
    buttonImage.src="Dark-Icon.png"
    isOn = false;
    socket.emit('Switch',"off");
    console.log("color switched");
  }else if (!isOn)
  {
    buttonImage.src="Light-Icon.png"
    isOn = true;
      socket.emit('Switch',"on");
  }
}
