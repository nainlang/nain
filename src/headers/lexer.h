/*
################################################################################
###   Lexer Header File For The Nain Programming Language                    ###
################################################################################

This file is responsible for lexing the code.
*/

#ifndef LEXER_H
#define LEXER_H
#define LEXER_VER "0.0.1"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tokens
typedef enum {
  IDENTIFIER,
  BACKSLASH,
  DOUBLE_QUOTE,
  SINGLE_QUOTE,
  FORWARD_SLASH,
  NEWLINE,
  TAB,
  SPACE,
  CARRIAGE_RETURN,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  MODULO,
  EXPONENT,
  EQUAL,
  NOT_EQUAL,
  GREATER,
  LESS,
  GREATER_EQUAL,
  LESS_EQUAL,
  AND,
  OR,
  NOT,
  BITWISE_AND,
  BITWISE_OR,
  BITWISE_XOR,
  SHIFT_LEFT,
  SHIFT_RIGHT,
  IF,
  ELSE,
  WHILE,
  FOR,
  BREAK,
  CONTINUE,
  RETURN,
  TRUE,
  FALSE,
  SP_NULL,
  FUNCTION,
  CLASS,
  WITH,
  IMPORT,
  AS,
  STRING,
  NUMBER,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  LBRACKET,
  RBRACKET,
  COMMA,
  DOT,
  COLON,
  SEMICOLON,
  TOKEN_EOF,
  THIS,
} TokenType;

// Inline function to skip whitespace
void skip_whitespace(char *input, int *currentIndex) {
  while (isspace(input[*currentIndex])) {
    (*currentIndex)++;
  }
}

// Inline function to handle single-line comments
void handle_single_line_comment(char *input, int *currentIndex) {
  while (input[*currentIndex] != '\n' && input[*currentIndex] != '\0') {
    (*currentIndex)++;
  }
}

// Inline function to handle multi-line comments
void handle_multi_line_comment(char *input, int *currentIndex) {
  (*currentIndex)++; // Skip the starting "/"
  while (input[*currentIndex] != '\0') {
    if (input[*currentIndex] == '\\') {
      (*currentIndex)++; // Skip the ending backslash
      return;
    }
    (*currentIndex)++;
  }
  // Handle the case where a multi-line comment is not closed
  fprintf(stderr, "Error: unclosed multi-line comment\n");
  exit(EXIT_FAILURE);
}

// Inline function to identify tokens
int identify_token(char currentChar, int *currentIndex, char *input) {
  switch (currentChar) {
  case '(':
    (*currentIndex)++;
    return LPAREN;
  case ')':
    (*currentIndex)++;
    return RPAREN;
  case '{':
    (*currentIndex)++;
    return LBRACE;
  case '}':
    (*currentIndex)++;
    return RBRACE;
  case '[':
    (*currentIndex)++;
    return LBRACKET;
  case ']':
    (*currentIndex)++;
    return RBRACKET;
  case ',':
    (*currentIndex)++;
    return COMMA;
  case '.':
    (*currentIndex)++;
    return DOT;
  case ':':
    (*currentIndex)++;
    return COLON;
  case ';':
    (*currentIndex)++;
    return SEMICOLON;
  case 'f':
    if (strncmp(&input[*currentIndex], "false", 5) == 0) {
      *currentIndex += 5;
      return FALSE;
    } else if (strncmp(&input[*currentIndex], "fn", 2) == 0) {
      *currentIndex += 2;
      return FUNCTION;
    }
    break;
  case 't':
    if (strncmp(&input[*currentIndex], "true", 4) == 0) {
      *currentIndex += 4;
      return TRUE;
    } else if (strncmp(&input[*currentIndex], "this", 4) == 0) {
      *currentIndex += 4;
      return THIS;
    }
    break;
  case 'n':
    if (strncmp(&input[*currentIndex], "nil", 3) == 0) {
      *currentIndex += 3;
      return SP_NULL;
    }
    break;
  }

  // Handle identifiers
  if (isalpha(currentChar) || currentChar == '_') {
    int start = *currentIndex;
    while (isalnum(input[*currentIndex]) || input[*currentIndex] == '_') {
      (*currentIndex)++;
    }
    // Check for reserved keywords here...
    return IDENTIFIER; // For now, treat it as a generic identifier
  }

  return -1; // Unknown token
}

// Inline function to get the next token
int next_token(char *input, int *currentIndex) {
  char currentChar = input[*currentIndex];

  // Skip whitespace
  skip_whitespace(input, currentIndex);
  currentChar = input[*currentIndex]; // Update currentChar after skipping

  // Check for end of input
  if (currentChar == '\0') {
    return TOKEN_EOF;
  }

  // Handle comments
  if (currentChar == '/' && input[*currentIndex + 1] == '/') {
    handle_single_line_comment(input, currentIndex);
    return next_token(input, currentIndex);
  } else if (currentChar == '/') {
    handle_multi_line_comment(input, currentIndex);
    return next_token(input, currentIndex);
  }

  // Identify tokens
  int token = identify_token(currentChar, currentIndex, input);
  if (token != -1) {
    return token;
  }

  fprintf(stderr, "Error: unexpected character '%c' at index %d\n", currentChar,
          *currentIndex);
  exit(EXIT_FAILURE);
}

// Function to retrieve all tokens from input
void get_all_tokens(char *input) {
  int currentIndex = 0;
  int token;

  while ((token = next_token(input, &currentIndex)) != TOKEN_EOF) {
    // Process the token (e.g., print it, store it, etc.)
    printf("Token: %d\n", token);
  }
}

#endif
