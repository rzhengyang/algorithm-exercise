aa: clean widesearch 
widesearch: list.o widesearch.o
	gcc -g -w -o a.out list.o widesearch.o
widesearch.o:widesearch.c list.h
	gcc -g -c -w widesearch.c
list.o:list.c list.h
	gcc -g -c -w list.c
clean:
	rm -rf a.out
	rm -rf *.o
