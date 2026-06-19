#ifndef NEW_NORMACLI_H
#define NEW_NORMACLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* buffer;
	size_t buffer_length;
	ssize_t input_length;

} InputBuffer;

typedef enum { META_COMMAND, NON_META_COMMAND } MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED } PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct { StatementType type; } Statement;

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);

}

MetaCommandResult exec_meta(InputBuffer* input_buffer){
	if (strcmp(input_buffer->buffer, ":exit") == 0){
		close_input_buffer(input_buffer);
		exit(EXIT_SUCCESS);
	} else {
		return NON_META_COMMAND;
	}
}

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
	if (strncmp(input_buffer->buffer, "insert", 6) == 0){
		statement->type = STATEMENT_INSERT;
		return PREPARE_SUCCESS;
	}
	if (strcmp(input_buffer->buffer, "select") == 0){
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}

	return PREPARE_UNRECOGNIZED;
}

void exec_statement(Statement* statement){
	switch (statement->type){
		case (STATEMENT_INSERT):
			printf("Insert execution block.");
			break;
		case (STATEMENT_SELECT):
			printf("Select execution block.");
			break;
	}
}

InputBuffer* new_input_buffer() {

  InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;

}

void print_prompt(char* mssg) { printf(mssg); }

void read_input(InputBuffer* input_buffer) {
  
	ssize_t bytes_read =
        getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
	
	printf("Error reading input\n");
	exit(EXIT_FAILURE);
	}

	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}

void print_welcome(char* prog_name){
        printf("Welcome to %s\n", prog_name);
}

#endif
