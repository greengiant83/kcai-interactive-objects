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
  switch (this.value)
  {
    case "1":
      slider.className = "slider red";
      break;
    case "2":
      slider.className = "slider yellow";
      break;
    case "3":
      slider.className = "slider green";
      break;
    case "4":
      slider.className = "slider cyan";
      break;
    case "5":
      slider.className = "slider blue";
      break;
    case "6":
      slider.className = "slider purple";
      break;
    case "7":
      slider.className = "slider white";
      break;
    default:
      slider.className = "slider";
      break;
  }
  color = color + "c";
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
    socket.emit('msg',"0p");
  }else if (!isOn)
  {
    buttonImage.src="Light-Icon.png"
    isOn = true;
    socket.emit('msg',"1p");
  }
}
