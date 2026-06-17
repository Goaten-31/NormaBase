#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "normacli.h"

#define CMD_MSSG "NormaBase => "
#define PROG_NAME "NormaBase"

int main(int argc, char* argv[]){

	InputBuffer* input_buffer = new_input_buffer();
	print_welcome(PROG_NAME);
	while (1){
		print_prompt(CMD_MSSG);
		read_input(input_buffer);


	if (strcmp(input_buffer -> buffer, ":exit") == 0){
		close_input_buffer(input_buffer);
		exit(EXIT_SUCCESS);

	} else {
		printf("Unrecognized command '%s'.\n",  input_buffer->buffer);
	}
	}

	return 0;
}
