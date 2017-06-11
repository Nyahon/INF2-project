//
// Created by nyahon on 10.06.17.
//

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CONCAT(a, b) (a"" b)


char scanSel(const char* selVal){
    char in;
    do{
        printf("tapez votre selection:\n");
        scanf(" %c",&in);

        //clear input buffer
        CLEAR_BUFFER;
    }while(!strchr(selVal, in));

    return in;
}

bool isFileOpen(void *p, const char *filename){
    const char* ERROR = "Error in #filename";
    if(!p){
        perror(filename);
        return EXIT_FAILURE;
    }
    return true;
}

//https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c
char* sanitize(char* string, char erroneousChar){
    char *src, *dst;
    for (src = dst = string; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != erroneousChar) dst++;
    }
    *dst = '\0';
    return dst;
}

bool countLines(const char* filename, size_t* lines){
    FILE* fp;
    fp = fopen(filename, "r");
    if(!isFileOpen(fp, filename))
        return false;
    char ch;
    *lines =0;

    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            (*lines)++;
        }
    }
    fclose(fp);
    return true;
}