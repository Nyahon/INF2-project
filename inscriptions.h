//
// Created by nyahon on 10.06.17.
//
#pragma once

#include <stdbool.h>

static const char* CATEGORY[] = {  "junior",
                            "senior",
                            "homme",
                            "femme"};

static const char* FILE_PARTICIPANTS = "participants.txt";


void inscr();

bool inscrMenu(char* name, char* surname, char* category);

bool checkInscriptionData(const char *, const char *, const char *);

bool addParticipant(const char* name, const char* surname, const char* category);