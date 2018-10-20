cc = gcc
EXE = foo
JAVAC = javac
JRE = java
PAGER = less
TEST_OUT = test.out
EXP_OUT = expected.out

.PHONY :clean
.PHONY :run-py
.PHONY :run-c
.PHONY :read
.PHONY :run-java
.PHONY :save-java
.PHONY :test-java

all : foo.o main.o $(EXE) run-c run-py read foo.class run-java save-java save-java test-java clean

foo.o : foo.c foo.h
	$(cc) -c foo.c 

main.o : main.c foo.h
	$(cc) -c main.c

$(EXE) : foo.o main.o
	$(cc) -o $(EXE) main.o foo.o

run-c: $(EXE)
	./$(EXE)

run-py : foo.py
	./foo.py

read :
	if[-f README] ;\
	then $(PAGER) README \
	fi

foo.class : foo.java
	$(JAVAC) foo.java

run-java : foo.class
	$(JRE) foo

save-java : run-java
	make run-java > $(TEST_OUT)

test-java : save-java
	-@if diff $(TEST_OUT) $(EXP_OUT) &> /dev/null ; then \
	echo "Passed!" ;\
	else \
	echo "Not the same!" ;\
	fi;

clean :  
	rm foo.o main.o foo.class $(EXE) $(TEST_OUT)
