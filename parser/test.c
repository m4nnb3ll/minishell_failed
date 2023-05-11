#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the token types
#define T_PIPE 1
#define T_IN_REDIR 2
#define T_OUT_REDIR 3
#define T_APPEND 4
#define T_HEREDOC 5
#define T_IDENTIFIER 6
#define T_DOLLAR 7

// Function declarations
void error(char* message);
void command_line();
void pipeline();
void command();
void cmd_name();
void cmd_suffix();
void io_redirect();
void word();

// Global variables
char* input;
int pos = 0;
int input_length = 0;

int main() {
  // Read the input from stdin
  printf("Enter the command line: ");
  size_t buffer_size = 1024;
  input = malloc(buffer_size);
  getline(&input, &buffer_size, stdin);
  input_length = strlen(input);

  // Parse the input
  command_line();

  printf("Parsing successful!\n");

  return 0;
}

void error(char* message) {
  printf("Error: %s\n", message);
  exit(1);
}

void command_line() {
  pipeline();
}

void pipeline() {
  command();
  while (pos < input_length && input[pos] == '|') {
    pos++;
    command();
  }
}

void command() {
  cmd_name();
  while (pos < input_length) {
    cmd_suffix();
  }
}

void cmd_name() {
  word();
}

void cmd_suffix() {
  if (pos < input_length
        && (input[pos] == '<'
        || input[pos] == '>'
        || input[pos] == '>>'
        || input[pos] == '<<')) {
    io_redirect();
  } else {
    return;
  }
}

void io_redirect() {
  if (input[pos] == '<') {
    pos++;
    word();
  } else if (input[pos] == '>') {
    pos++;
    word();
  } else if (pos + 1 < input_length
            && input[pos] == '>'
            && input[pos + 1] == '>')
  {
    pos += 2;
    word();
  } else if (pos + 1 < input_length
            && input[pos] == '<'
            && input[pos + 1] == '<')
  {
    pos += 2;
    word();
  } else {
    error("Invalid input!");
  }
}

void word() {
  if (pos < input_length && input[pos] == '$') {
    pos++;
  }
  if (pos < input_length && input[pos] == ' ') {
    pos++;
  } else {
    error("Invalid input!");
  }
  while (pos < input_length && input[pos] != ' ') {
    pos++;
  }
}
