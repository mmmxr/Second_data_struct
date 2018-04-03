dlinkist:dlinklist.o
	gcc -o $@ $^

.PHONY:clean
	rm -rf dlinkist
