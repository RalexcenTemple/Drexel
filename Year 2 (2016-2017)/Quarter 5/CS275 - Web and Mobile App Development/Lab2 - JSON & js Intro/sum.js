var http = require('http');
var express = require('express');
var app = express();
var server = http.createServer(function(req, res){
	console.log('Request Recieved');
	res.writeHead(200, {content-type: 'text/plain'});
	
	app.use(express.static("."));
	app.listen(8080,function(){
		
		console.log("something is working");
		
	});
	res.end('alright');
})listen(8080);
console.log('Server running on port 8080');