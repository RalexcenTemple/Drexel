#!/usr/bin/env python
#
#s1.py is for finding the average of the 3 grades of the students found in
#the file students
#
#EDITOR: cols=80, tabstop=2
#
fName = raw_input("Please enter the name of the input file: ")


f = open(fName, "r") #open the students file for reading

l = f.readline()
while l :
	l = l.strip()
	student = l.split()
	#print student[0]
	total = 0
	for (i) in student[1:]:
		total = total + int(i)
	print (student[0] + " " + str(total/(len(student))-1))
	l = f.readline()

