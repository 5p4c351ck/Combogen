#ifndef COMBOGEN_H
#define COMBOGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void comboGenHelper(char** keywords, int numKeywords, char* combination, int currLength, int maxLength, FILE* outputFile);      /*Recursive function to generate the combinations*/
void comboGen(char** keywords, int numKeywords, FILE* outputFile);      /*Calls the helper function for each length*/

#endif