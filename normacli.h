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


void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);

}

void print_welcome(char* prog_name){
        printf("Welcome to %s\n", prog_name);
}

#endif
