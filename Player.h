#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player
{
    char Name[32];
    unsigned int Score;
    char Icon;
} Player;

Player* addPlayer(char* name);

#endif