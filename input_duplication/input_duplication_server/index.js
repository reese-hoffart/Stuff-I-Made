const net = require('net');
const iohook = require('iohook');

const server = net.createServer(function(socket) {
    console.log('Server Connected');

    socket.on('data', function(data) {
        console.log('[CLIENT] ' + data.toString());
    });

    var mousemoveLastTime = 0;
    iohook.on('mousemove', function(e) {
        const date = new Date();
        if(date.getTime() - mousemoveLastTime >= 50) {
            mousemoveLastTime = date.getTime();
            socket.write('m ' + e.x + " " + e.y)
        }
    });

    var mousedownLastTime = 0;
    iohook.on('mousedown', function(e) {
        const date = new Date();
        if(date.getTime() - mousedownLastTime >= 50) {
            mousedownLastTime = date.getTime();
            socket.write('c ' + e.button);
        }
    });

    var mouseupLastTime = 0;
    iohook.on('mouseup', function(e) {
        console.log('mouseup!')
        const date = new Date();
        if(date.getTime() - mouseupLastTime >= 50) {
            mouseupLastTime = date.getTime();
            socket.write('r ' + e.button);
        }
    });

    var keydownLastTime = 0;
    iohook.on('keydown', function(e) {
        const date = new Date();
        if(date.getTime() - keydownLastTime >= 50) {
            keydownLastTime = date.getTime();
            socket.write('d ' + e.rawcode);
        }
    });

    var keyupLastTime = 0;
    iohook.on('keyup', function(e) {
        const date = new Date();
        if(date.getTime() - keyupLastTime >= 50) {
            keyupLastTime = date.getTime();
            socket.write('u ' + e.rawcode);
        }
    });

    //socket.end('server is closing connection');
});

server.listen(8080, function() {
    console.log('Server listening on port ' + server.address().port)
});

iohook.start();