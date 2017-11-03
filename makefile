all:
	gcc -o DIRinfo dirinfo.c 

run: all
		./DIRinfo

clean: 
	rm *~