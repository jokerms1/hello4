'use strict';

function Room(name,num){
    this.name = name;
    this.num = num;
}

var creatroom = [];
var newroom,room;
var os = require('os');
var nodeStatic = require('node-static');
var https = require('https');
var socketIO = require('socket.io');
var fs = require('fs');

const options = {
  key: fs.readFileSync('./2043129_huyuanrui.top.key'),
  cert: fs.readFileSync('./2043129_huyuanrui.top.pem')
};


var fileServer = new(nodeStatic.Server)();
var app = https.createServer(options,function(req, res) {  
  
  fs.readFile("./pc-to-phone.html",function(err,data){
      res.end(data);
  })
  //fileServer.serve(req, res);
}).listen(8989);

console.log('start');
var io = socketIO.listen(app);
console.log('listen success');
io.sockets.on('connection', function(socket) {

    console.log('connection success');
  // convenience function to log server messages on the client
    function log() {
    var array = ['Message from server:'];
    array.push.apply(array, arguments);
    socket.emit('log', array);
    }
    socket.on('create or join', function(room) {
        console.log("111222");
        var flag = 0;
        for(var i=0;i<creatroom.length;i++)
        {
                if(creatroom[i].name == room)
                {
                        creatroom[i].num++;
                        flag = 1;
                        room = creatroom[i];
                        break;
                }
        }
        if(flag == 0)
        {
                newroom = new Room(room,1);
                creatroom.push(newroom);
                room = newroom;
        }
    console.log('Received request to create or join room ' + room.name);
    log('Received request to create or join room ' + room.name);
    // var numClients = io.sockets.sockets.length;   
    console.log('Room ' + room.name + ' now has ' + room.num + ' client(s)');
    log('Room ' + room.name + ' now has ' + room.num + ' client(s)');

    if (room.num === 1) {
        console.log('number1');
      socket.join(room.name);
        log('Client ID ' + socket.id + ' created room ' + room.name);
      console.log('Client ID ' + socket.id + ' created room ' + room.name);
      socket.emit('created', room.name, socket.id);
        console.log('created success');

    } else if (room.num === 2) {
      console.log("join");
      log('Client ID ' + socket.id + ' joined room ' + room.name);
      io.sockets.in(room.name).emit('join', room.name);
      socket.join(room.name);
      console.log("222288");
      socket.emit('joined', room.name, socket.id);
      io.sockets.in(room.name).emit('ready');
    } else { // max 5 clients
      socket.emit('full', room.name);
    }

    socket.on('message', function(message) {
    console.log('Client said: ', message);
    log('Client said: ', message);
    // for a real app, would be room-only (not broadcast)
    socket.broadcast.to(room.name).emit('message', message);
    });

    socket.on('bye', function(){
        creatroom.splice(room, 1);
        socket.broadcast.to(room.name).emit('bye', room.name);
        console.log('received bye from'  + room.name);
    });
  });

  socket.on('ipaddr', function() {
    var ifaces = os.networkInterfaces();
    for (var dev in ifaces) {
      ifaces[dev].forEach(function(details) {
        if (details.family === 'IPv4' && details.address !== '127.0.0.1') {
          socket.emit('ipaddr', details.address);
        }
      });
    }
  });
});