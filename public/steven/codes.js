var slider = document.getElementById("myRange");
var value;
var value2;
var isOn = 0;
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

value = slider.value;
value2 = slider2.value;
slider.oninput = function()
{
  value = this.value;
  console.log(value);
}
slider2.oninput = function()
{
  value = this.value;
  console.log(value);
}
function buttonPressed()
{
  
}
