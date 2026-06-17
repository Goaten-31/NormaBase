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


	if (input_buffer -> buffer[0], ":"){
		switch (exec_command(input_buffer)) {
			case (META_COMMAND):
				continue;
			case (NON_META_COMMAND):
				printf("Unrecognized command '%s'\n", input_buffer->buffer);
				continue;
		}
	}

	Statement statement;
	switch (prepare_statement(input_buffer, &statement)){
		case (PREPARE_SUCCESS):
			break;
		case (PREPARE_UNRECOGNIZED):
			printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
			continue;
	}

	execute_statement(&statement);
	printf("Execution Successful.\n");

	return 0;
}
