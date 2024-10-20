#include "lexer.h"
#include <ctype.h>
#include <stdio.h>

#ifndef PARSER_H
#define PARSER_H

#endif // !DEBUG

// Define the structure for a simple AST node
typedef struct ASTNode {
  TokenType type;
  struct ASTNode *left;
  struct ASTNode *right;
  char *value; // For identifiers or literals
} ASTNode;

// Function prototypes
ASTNode *parse_expression(char **input, int *currentIndex);
ASTNode *parse_statement(char **input, int *currentIndex);
void parse(char *input);
void free_ast_node(ASTNode *node);

// Function to create a new AST node
ASTNode *new_ast_node(TokenType type, ASTNode *left, ASTNode *right,
                      char *value) {
  ASTNode *node = malloc(sizeof(ASTNode));
  node->type = type;
  node->left = left;
  node->right = right;
  node->value = value; // Store value for identifiers/literals
  return node;
}

// Recursive function to free AST nodes
void free_ast_node(ASTNode *node) {
  if (node != NULL) {
    free_ast_node(node->left);
    free_ast_node(node->right);
    free(node->value); // Free the value if it was dynamically allocated
    free(node);        // Free the node itself
  }
}

// Recursive function to parse expressions
ASTNode *parse_expression(char **input, int *currentIndex) {
  ASTNode *left = parse_statement(input, currentIndex);

  while (true) {
    int token = lookahead(*input, currentIndex);
    if (token == PLUS || token == MINUS) {
      consume_token(*input, currentIndex); // Consume token
      ASTNode *op_node = new_ast_node(token, left, NULL, NULL);
      op_node->right = parse_statement(input, currentIndex);
      left = op_node;
    } else {
      break;
    }
  }

  return left;
}

// Function to parse individual statements
ASTNode *parse_statement(char **input, int *currentIndex) {
  int token = next_token(*input, currentIndex);

  if (token == IDENTIFIER) {
    char *value = strdup("identifier"); // Store the actual identifier
    return new_ast_node(IDENTIFIER, NULL, NULL, value);
  }

  // Handle other tokens (like numbers, keywords, etc.)
  return NULL;
}

// Main parse function
void parse(char *input) {
  int currentIndex = 0;
  ASTNode *root = parse_expression(&input, &currentIndex);

  // Here you would typically walk the AST to evaluate or transform it
  printf("Parsed expression successfully.\n");

  // Free the AST nodes after use
  free_ast_node(root);
}
