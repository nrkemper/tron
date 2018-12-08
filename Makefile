.PHONY:	test
all:
	make tron
	make test
tron:
	gcc -Wall event.c key.c tron.c -lncurses -o bin/tron
test:
	gcc -Wall event.c test/eventtest.c -o bin/eventtest
	gcc -Wall test/citest.c -o bin/citest
	gcc -Wall event.c key.c test/keytest.c -lncurses -o bin/keytest
clean:
	rm -rf bin/eventtest
	rm -rf bin/citest
	rm -rf bin/keytest
	rm -rf bin/tron
