var http = require('http');
var express = require('express');
var app = express();
app.listen(8080);
var server = http.createServer(function(req, res){
	console.log('Request Recieved');
	
		request.on("end", function(){
			
			app.get('/sum', function(req,res){
			var seed = req.query.seed;
			var resu = 0;
			var i = 1;
			for(i ; i <= seed; i++){
				
				resu += i;
				
			}
			res.send(resu);
		
		});
	
		app.get('/fact', function(req,res){
		
			var seed = req.query.seed;
			var resu = 1;
			
			for(var i = 1; i <= seed; i++){
				
				resu = resu * i;
				
			}
			
			res.send(resu);
		
		});
	
	res.end('alright');
			
		});
		
});
server.listen(8080);
console.log('Server running on port 8080');