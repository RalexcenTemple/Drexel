#!/usr/bin/env python
#
#id2.py - Reed Ceniviva 10/15/16
#
#Modify id.py so that if it isn't given any arguments (filename on the
#cmd-line), it will read stdin, much like cat,grep, head, etc. Submit a file
#called id2.py
#
#
import sys
# get user innput for file or stdin
fName = raw_input( "please enter the name of the file: " )
if len(sys.argv) > 1 :
	f = sys.stdin
else :
	f = open(fName)

myDict = {}
#removes whitespace, turns lines to lists of words, appends list to dict
l = f.readline()
while l :
   l = l.strip()
   entry = l.split()
   myDict[entry[0]] = entry[1:];
   l = f.readline()

#sorts list that holds keys
keylist = myDict.keys()
keylist.sort

#prints dict in order of sorted keys list
for key in keylist:
   print"%s: %s" % (key, myDict[key])


