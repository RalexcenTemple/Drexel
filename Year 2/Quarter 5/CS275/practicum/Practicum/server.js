var http = require('http');
var express = require('express');
var app = express();
app.listen(8080,function(){
	app.get('/part2',function(req,res){
		console.log("got call");
		var word = req.query.message;
		var count = req.query.count;
		var ret = "";
		for(var i = 0; i < count; i++){
			
			ret = ret + word;
			
		}
		console.log(ret);
		res.send(ret);
	});
});