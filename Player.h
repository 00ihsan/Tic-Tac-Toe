#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player
{
    char Name[32];
    unsigned int Score;
} Player;

Player* addPlayer(char* name);

#endif