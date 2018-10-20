#!/usr/bin/env python
#
#s2.py is for reading in the student names and grades and outputing the name
#with the average of the grades from the file students.cvs
#
fName = raw_input("Please enter the name of the input file: ")


f = open(fName, "r") #open the students file for reading

l = f.readline()
while l :
   l = l.strip()
   student = l.split(",")
   #print student[0]
   total = 0
   for (i) in student[1:]:
      total = total + int(i)
   print (student[0] + " " + str(total/(len(student))-1))
   l = f.readline()

