#ifndef PLAYER_H
#define PLAYER_H

typedef struct player_s {
    int pos;
    int money;
    int playerNbr;
    struct player_s *next;
} player_t;

void addNodePlayer(player_t *head, int money, int nbr);
#endif