var express = require('express');
var app = express();
var cors = require('cors');
app.use(cors());
app.use(express.static("."));
var mysql = require("mysql");

var connection = mysql.createConnection({
	host:       'localhost',
	user:       'root',
	password:   'Hatters9$$$',
	database:   'Project'
});

connection.connect(function(err) {
	if (err) {
		console.log("Error connecting to database");
		console.log(err);
	}
	else {
		console.log("Database successfully connected");
	}
});
app.get('/sendMessage', function(req,res){
	var msg = req.query.msg;
	var sender = req.query.sender;
	var recipient = req.query.recipient;
	var html = "";
	connection.query('INSERT INTO message ' +
		'(timestamp, message, sender, reciever) ' +
		'VALUES ' +
		'('+Math.floor(Date.now()/1000)+', \'' + msg + '\', \'' + sender + '\', \'' + recipient + '\');',function(err,rows,fields){
		if(err) throw err;
		if(recipient !="*"){
			html+="<i>["+Math.floor(Date.now()/1000)+"] " + sender + "> " + msg + "</i></br>";
		}else{
			html+="["+Math.floor(Date.now()/1000)+"] " + sender + "> " + msg + "</br>";
		}
		res.send(html);
	});
});
app.get('/loadChat', function(req,res){
	var recipient = req.query.recipient;
	var lastLoadTime = req.query.lastLoad;
	var html = "";
	connection.query('SELECT * FROM message WHERE (reciever = "*" || reciever = \''+recipient+'\') && sender != \''+recipient+'\' && sender != "root" && timestamp >\'' + lastLoadTime + '\'' , function(err,rows,fields){
		if(err) throw err;
		for (var i = 0; i < rows.length; i++) {
			if(rows[i].reciever !="*"){
				html+="<i>["+rows[i].timestamp+"] " + rows[i].sender + "> " + rows[i].message + "<\i></br>";
			}else{
				html+="["+rows[i].timestamp+"] " + rows[i].sender + "> " + rows[i].message + "</br>";
			}
		}
			
		res.send(html);
	});
});

//Creates the user in the database
//Return an error if the user cant be created
app.get('/createUser', function(req,res){
	var userID = req.query.userID;
	var html = "";
	connection.query('INSERT INTO users ' +
		'(userID, timestamp) ' +
		'VALUES ' +
		'(\'' + userID + '\', '+Math.floor(Date.now()/1000)+');',function(err,rows,fields){
		if(err) throw err;
		res.send(html);
		});
	
});
//Return an error if the userID is not in use and success if it is
app.get('/userExists', function(req,res){
	var user = req.query.userID;
	var html = "";
	var found = false;
	connection.query('SELECT * FROM users',function(err,rows,fields){
		if(err) throw err;
		for(var i = 0; i < rows.length;i++){
			console.log(rows[i].userID);
			console.log(rows[i].userID == user);
			if(rows[i].userID == user){
				found = true;
			}
		}
			console.log(found.toString());
			res.send(found.toString());
	});

});

app.listen(8080,function(){
console.log('Server Running...');
});
