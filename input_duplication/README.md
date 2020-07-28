# Input Duplication

Input Duplication is a set of clint-server NodeJS programs that allows a server to send user input data to the client using sockets.
The server-side program collects mouse and keyboard input, and the client-side program moves the mouse and/or simulates keypresses based on the server's data.
Some code such as IP-Addresses will need to be modified for use on other machines.

To use:
* Run the `node index.js` file in the `input_duplication_server` folder on the machine that you want to collect input data
* Run the `node index.js` file in the `input_duplication_client` folder on the machine that you want to control input

Dependencies:
* iohook (`npm install iohook`)
* robotjs (`npm install robotjs`)