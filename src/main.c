/*
###################################################
### The nain programming language #################
###################################################

Thanks for using nain!
Nain is a new and modern programming language made to be easy to learn and use.

Nain is currently on development, v0.01 dev
*/

#include <stdio.h>
#include "headers/lexer.h"

int main() {
    char *input = "fn main() { print!(\"Hello World!\") }/hi\n\\//hi";
    get_all_tokens(input);
    printf("Lexer version: %s\n", LEXER_VER);
    return 0;
}