var express = require("express");
var config = require("./config.js");
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);
var SerialPort = require("serialport");
var ReadLine = SerialPort.parsers.Readline;
var parser = new ReadLine();
var port = new SerialPort(config.serialPort, {
	baudRate: 9600
});

server.listen(8000);

app.use(express.static('public'))

io.on('connection', function (socket) {
	socket.on('msg', function (data) {
		console.log(data);
		port.write(data + "\n");
  	});
});

port.pipe(parser);
parser.on("data", function(data)
{
	console.log(data);
	io.emit("msg", data);
})