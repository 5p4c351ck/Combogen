#include "combogen.h"

int main(int argc, char* argv[]) {
    char* outputFilename = NULL;
    char** keywords = NULL;
    int numKeywords = 0;

    /*Parse command line arguments*/
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                outputFilename = argv[i + 1];
                i++;  /*Skip the next argument that is the filename and go to keywords*/
            } else {
                printf("Error: Output file name missing.\n");
                return 1;
            }
        } else {
            numKeywords++;
            keywords = realloc(keywords, numKeywords * sizeof(char*));
            keywords[numKeywords - 1] = (char*)malloc(strlen(argv[i]) + 1);
            strcpy(keywords[numKeywords - 1], argv[i]);
        }
    }

    /*Open the output file in write mode*/
    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: Failed to open the output file.\n");
        return 1;
    }

    /*Generates the combinations and writes them to outputFile*/
    comboGen(keywords, numKeywords, outputFile);

    /*Close file and free memory*/
    fclose(outputFile);
    for (int i = 0; i < numKeywords; i++) {
        free(keywords[i]);
    }
    free(keywords);

    printf("Output file generation successful.\n");

    return 0;
}