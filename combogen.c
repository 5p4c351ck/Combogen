#include "combogen.h"


void comboGenHelper(char** keywords, int numKeywords, char* combination, int currLength, int maxLength, FILE* outputFile) {
    if (currLength == maxLength) {
        fputs(combination, outputFile);
        fputs("\n", outputFile);
        return;
    }

    for (int i = 0; i < numKeywords; i++) {
        char* newCombination = (char*)malloc(strlen(combination) + strlen(keywords[i]) + 1);
        strcpy(newCombination, combination);
        strcat(newCombination, keywords[i]);
        comboGenHelper(keywords, numKeywords, newCombination, currLength + 1, maxLength, outputFile);
        free(newCombination);
    }
}

void comboGen(char** keywords, int numKeywords, FILE* outputFile) {
    for (int length = 1; length <= numKeywords; length++) {
        char* combination = (char*)malloc(1);
        combination[0] = '\0';

        comboGenHelper(keywords, numKeywords, combination, 0, length, outputFile);

        free(combination);
    }
}