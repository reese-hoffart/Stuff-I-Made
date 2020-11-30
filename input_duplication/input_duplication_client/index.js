const net = require('net');
const robotjs = require('robotjs');

const client = net.createConnection(8080, '192.168.0.32', function() {
    console.log('Connected to the server');
    client.write('hello this is client');
});

client.on('data', function(data) {
    //console.log('[SERVER] ' + data.toString());
    var arr = data.toString().split(' ');
    switch (arr[0]) {
        case 'm':
            console.log('MouseMove: ' + Number(arr[1]) + ' ' + Number(arr[2]));
            if(!isNaN(arr[1]) && !isNaN(arr[2])) robotjs.moveMouse(Number(arr[1])*1.4, Number(arr[2])*1.4);
            break;
        case 'c':
            console.log('MouseButtonClick: ' + Number(arr[1]));
            if(Number(arr[1]) == 1) robotjs.mouseToggle('down', 'left');
            else if(Number(arr[1]) == 2) robotjs.mouseToggle('down', 'right');
            break;
        case 'r':
            console.log('MouseButtonRelease: ' + Number(arr[1]));
            if(Number(arr[1]) == 1) robotjs.mouseToggle('up', 'left');
            else if(Number(arr[1]) == 2) robotjs.mouseToggle('up', 'right');
            break;
        case 'd':
            console.log('KeyDown: ' + Number(arr[1]));
            if(!isNaN(arr[1])) robotjs.keyToggle(String.fromCharCode(Number(arr[1])), 'down');
            break;
        case 'u':
            console.log('KeyUp: ' + Number(arr[1]));
            if(!isNaN(arr[1])) robotjs.keyToggle(String.fromCharCode(Number(arr[1])), 'up');
            break;
        default:
            break;
    }
    //client.end();
});

client.on('end', function() {
    console.log('Disconnected from the server');
});