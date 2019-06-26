function fib(num){
	n = parseInt(num);
	var f;
	var i;
	var b;
	f = 0;
	i = 1;
	b = 1;
	var j;
	for(j = 2; j <= n; j++){
		b = f + i;
		f = i;
		i = b;
	}
	var String txt = toString(b);
	document.getElementById("log").innerHTML=txt;
	return b;
}