var app = require('express')();
var server = require('http').Server(app);
var io = require('socket.io')(server);
var SerialPort = require("serialport");
var port = new SerialPort("COM6", {
  baudRate: 9600
});


server.listen(8000);

app.get('/', function (req, res) {
  res.sendfile(__dirname + '/index.html');
});

app.get('/stream.html', function (req, res) {
  res.sendfile(__dirname + '/stream.html');
});

io.on('connection', function (socket) {
  socket.emit('news', { hello: 'merica' });
  socket.on('msg', function (data) {
    console.log(data);
    port.write(data + "\n");
  });
});