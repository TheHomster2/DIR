#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

int main(){
	DIR *directory = opendir(".");
	int size = 0;
	struct dirent *current = readdir(directory);

	printf("\nDirectories: \n");
	while (current){
		if (current -> d_type == DT_DIR){
			printf("%s\n", current -> d_name);
		}
		current = readdir(directory);
	}
	closedir(directory);
	directory = opendir(".");

	printf("\nRegular files: \n");
	struct stat *buff = malloc(sizeof(struct stat));
	while (current){
		if (current -> d_type == DT_REG){
			printf("%s\n", current -> d_name);
			stat(current -> d_name, buff);
			size += buff -> st_size;
		}
	}
	closedir(directory);	
	printf("\nTotal Directory Size: %d Bytes\n", size);

	return 0;
}