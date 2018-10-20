var http = require('http');
var express = require('express');
var app = express();
var mysql = require("mysql");
var con = mysql.createConnection({
	host: "localhost",
	port: "3306",
	user: "root",
	password: "Hatters9$$$",
	database: "cs275lab5"
});
con.connect(function(err) {
	if (err) {
		console.log("Error connecting to database: " + String(err));
	}
	else {
		console.log("SUCCESS");
		app.listen(8080, function(){
	app.get('/Students', function(req,res){
			//console.log("GOTStudentCALL")
		req = req;
		res = res;
		con.query("select idSTUDENT, firstName, lastName, birth, major from student",
		function(err,rows,fields){
			if(err){
				console.log("Error during query processing");
				res.send(err);
			}else{
			console.log(rows)
			res.send(rows);
			}
		});
		
	});
	app.get('/Courses', function(req,res){
			//console.log("GOTCoursesCALL")
		req = req;
		res = res;
		con.query("select courseID, courseDesc from course",
		function(err,rows,fields){
			if(err){
				console.log("Error during query processing");
				res.send(err);
			}else{
			console.log(rows)
			res.send(rows);
			}
		});
		
	});
	app.get('/Grades', function(req,res){
			//console.log("GOTGradesCALL")
		req = req;
		res = res;
		con.query("select  courseID, studentID, term, grade from grades",
		function(err,rows,fields){
			if(err){
				console.log("Error during query processing");
				res.send(err);
			}else{
			console.log(rows)
			res.send(rows);
			}
		});
	});
	app.get('/Trans', function(req,res){
			//console.log("GOTStudentCALL")
		con.query("select idSTUDENT, firstName, lastName, birth, major from student",
		function(err,rows,fields){
			if(err){
				console.log("Error during query processing");
				res.send(err);
			}else{
			console.log(rows)
			res.send(rows);
			}
		});
		
	});
});
	}
});

	