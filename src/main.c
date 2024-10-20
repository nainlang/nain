#include "./headers/lexer.h"
#include "./headers/parser.h"
// Main function
int main() {
  char code[256]; // Buffer for user input

  // Example input (can be modified for testing)
  strcpy(code, "x + y - 3"); // Example expression

  // Tokenize the input
  get_all_tokens(code); // Call lexer to get tokens

  // Parse the input
  parse(code); // Call parser

  return 0;
}
