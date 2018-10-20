var http = require('http');
var server = http.createServer(function(req, res){
	console.log('Request Recieved');
	res.writeHead(200, {content-type: 'text/plain'});
	req.on('seed', function(seeded){
		
		console.log('fact found: ' + seeded);
		
	});
	res.end('alright');
	
})listen(8080);
console.log('Server running on port 8080');