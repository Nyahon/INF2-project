//
// Created by nyahon on 10.06.17.
//
#pragma once

#include <stdbool.h>
#include <stdio.h>

#define DEBUG false
#define CLEAR_BUFFER ;


#ifdef __linux__
#define CLEAR_SCREEN "\e[1;1H\e[2J"
#else
#define CLEAR_SCREEN "\n"
#endif

#define size(x) sizeof(x)/sizeof(*x)

char scanSel(const char* selVal);

bool isFileOpen(void *p, const char *filename);

char* sanitize(char* string, char erroneousChar);

bool countLines(const char* filename, size_t* lines);