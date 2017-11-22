var slider = document.getElementById("Color");
var slider2 = document.getElementById("Brightness");
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
  console.log("Color: " + color);
}
slider2.oninput = function()
{
  brightness = this.value;
  console.log("Brightness: "+brightness);
}

function buttonPressed()
{

}
