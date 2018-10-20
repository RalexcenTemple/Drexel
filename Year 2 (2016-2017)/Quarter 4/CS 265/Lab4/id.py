#!/usr/bin/env python
#
#id.py - Reed Ceniviva 10/15/16
#
#di Look at the ids file. You will read a file like this, break each record
#up into 2 fields; the id, and the name. Look more closely at str.split to
#help you here. You will store the entries in a dictionary, where ID is the
#key, and the name is the satellite data. You will then output, in 2 columns,
#one entry per line, all the entries in your dictionary, sorted (numerically)
#by ID. dict.keys and list.sort should help you here. The input filename will
#be the first command-line argument. Submit a file called id.py
#
#
#
fName = raw_input( "please enter the name of the file: " )

f = open(fName)

myDict = {}

l = f.readline()
while l :		 #takes out the whitespace, converts lines into lists of words,
  	l = l.strip()#and appends them to dict
	entry = l.split()
	myDict[entry[0]] = entry[1:];
	l = f.readline()

keylist = myDict.keys() 
keylist.sort#sorts the keys

for key in keylist:#prints dict in sorted order
	print"%s: %s" % (key, myDict[key])

