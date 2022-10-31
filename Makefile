INCLUDE := -I ~/include
LDGLAGS := -L ~/lib -lsense -lm

slist: studentList.o
	cc -o slist studentList.o $(LDFLAGS)

clean:
	rm -f *.o slist
studentList.o: studentList.c studentList.h
	cc -c studentList.c -I ~/include
