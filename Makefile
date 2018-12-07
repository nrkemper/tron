all:
	make event
event:
	gcc -Wall event.c eventtest.c -o eventtest
clean:
	rm -rf eventtest
