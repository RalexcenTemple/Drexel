var http = require('http');
var express = require('express');
var app = express();
app.listen(8080,function(){
		app.get('/lab3',function(req,res){
			console.log("call for lab 3")
			var code = "<h2>Lab 3 Calculator</h2>"+
"<input type='text' id='seed'>"+
"</input></br></br>"+
"<select id='calcOpt'>"+
"<option value='-------' font='grey'>-------</option>"+
"<option value='Factorial' text='Factorial'>Factorial</option>"+
"<option value='Summation' text='Summation'>Summation</option>"+
"</select></br></br>"+
"<button id='launch'>Submit</button>"+
"</br></br>"+
"<div id='test'></div></br></br>"+
"<div id='test2'></div>"+
"<script>"+
"	$('#launch').click(function(){"+
"		var calc = $('#calcOpt').find('option:selected').html();"+
"		var ui =! isNaN($('#seed').val());"+
"		var seeded = $('#seed').val();"+
"		if(seeded < 1 && ui){"+
"			$('#test2').text('Please  select a calculation and enter a postivie number');"+
"		}else if(calc === 'Factorial' && ui){"+
"			calc = 'fact';"+
"			$('#test2').text('');"+
"		}else if(calc === 'Summation' && ui){"+
"			calc = 'sum';"+
"			$('#test2').text('');"+
"		}else if(calc === '-------' && ui){"+
"			$('#test2').text('Please select one of the calculations to be performed');"+
"		};"+
"		var jsn = {'n' : seeded};"+
"				var URL =  'http://localhost:8080/' + calc;"+
"				$.ajax({"+
"					type: 'GET',"+
"					url: URL,"+
"					contentType:  'application/json; charset=utf-8',"+
"					data: jsn,"+
"					dataType: 'html',"+
"					success: function(result) {"+
"						var json = result;"+
"						$('#test').text('The result of the calculation for ' + seeded + ' is: ' + json);"+
"					},"+
"					error: function (xhr, ajaxOptions, thrownError) {"+
"						$('#test').text('ERROR');"+
"					}"+
"				});"+
"	});"+
"</script>";
			res.send(code);
		});
		app.get('/lab2',function(req,res){
			console.log("call for lab 2")
			var code = '<h1>Hourly Forcast Finder</h1>'+
'<input type="text" id="userin"><br><br>'+
'<button id="WenterB">Enter</button>'+
'    <br>'+
'    <br>'+
'    <div id="displayKey"></div>'+
'    <br>'+
'    <div id="display"></div>'+
'    <br><br>'+
'    <div id="final"></div>'+
'<script>'+
' $(document).ready(function(){'+
'        $("#WenterB").click(function(){'+
'            $("#displayKey").text($("#userin").val());'+
'            $(function(){'+
'    var URLF =  "http://api.wunderground.com/api/";'+
'    var key = $("#userin").val();'+
'    var URLB = "/geolookup/q/autoip.json";'+
'    var code = "";'+
'    var URL = URLF + key + URLB;'+
'    $("#displayKey").text(key);'+
'    $.ajax({'+
'        type: "GET",'+
'        url: URL,'+
'        contentType:  "application/json; charset=utf-8",'+
'        dataType: "jsonp",'+
'        success: function(msg) {'+
'        var  json = msg;'+
'        $("#display").text(json.location.zip);'+
'            var ZIP = json.location.zip;'+
'            var URLL = "http://api.wunderground.com/api/" + key + "/hourly/q/" + ZIP + ".json";'+
'            $.ajax({'+
'                type: "GET",'+
'                url: URLL,'+
'                contentType:"application/json; charset=utf-8",'+
'                dataType: "jsonp",'+
'                success: function(newmsg) {'+
'                var jsonn = newmsg;'+
'                    for(var i=0; i < 25; i++){'+
'                        code = code.concat("<h2>"+i+" oclock</h2><h3>" + jsonn.hourly_forecast[i].temp.english + " degrees</h3><br>" + "<img src= " + jsonn.hourly_forecast[i].icon_url + "><br><br>");'+
'                    }'+
'                $("#final").html(code);'+
'                },'+
'                error: function (xhr, ajaxOptions, thrownError) {'+
'            var mssg = "Error fetching :";'+
'            $("#display").text(mssg + URLL);'+
'        }'+
'            });'+
'    },'+
'        error: function (xhr, ajaxOptions, thrownError) {'+
'            var mssg = "Error fetching :";'+
'            $("#display").text(mssg + URL);'+
'        }'+
'});'+
'        })'+
'        });    });'+
'</script>'
			res.send(code);
			
		});
		//handles summation calculations
		app.get('/sum', function(req,res){
			var seed = req.query.n;
			var resu = 0;
			for(var i = 1 ; i <= seed; i++){
				
				resu += i;
				
			}
			//messages to the console to say it is working properly 
			console.log("Sum Tried");
			console.log("seed: " + seed);
			console.log("result: " + resu);
			res.send(String(resu));
		});
		//handles factorial calculations
		app.get('/fact', function(req,res){
			var seed = req.query.n;
			console.log("" + seed);
			var resu = 1;
			
			for(var i = 1; i <= seed; i++){
				
				resu = resu * i;
				
			}
			console.log("Fact Tried");
			console.log("seed: " + seed);
			console.log("result: " + resu);
			res.send(String(resu));
		});
});