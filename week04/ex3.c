#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char command[128];
	printf("To exit use the command : exit \n");

	while(strcmp(command, "exit")) {
		printf("command > ");
		scanf("%s", command);

		system(command);
	}
	return 0;
}
