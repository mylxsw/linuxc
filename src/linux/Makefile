
CC_PTHREAD=gcc -o ../../bin/$@ $< -lpthread -D_REENTRANT

%: %.c
	gcc -o ../../bin/$@ $<

thread4: thread4.c
	$(CC_PTHREAD)

thread3a: thread3a.c
	$(CC_PTHREAD)

thread3: thread3.c
	$(CC_PTHREAD)

thread1: thread1.c
	$(CC_PTHREAD)

connect1: connect1.c
	rm -fr connect1
	gcc -I /usr/local/mysql/include/ connect1.c -L /usr/local/mysql/lib/ -lmysqlclient -o connect1
