#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char command[128];
	printf("To exit use the command : exit \n");

	while(strcmp(command, "exit\n")) {

		printf("command > ");
		fgets(command, 128, stdin);

		if (fork() == 0) {
			system(command);
			exit(0);
		}
	}
	return 0;
}
