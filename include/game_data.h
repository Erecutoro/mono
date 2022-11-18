#ifndef GAME_DATA_H
#define GAME_DATA_H

#include "player.h"
#include "map.h"
#include "rule.h"

typedef struct game_data_s {
    int turn;
    int player_turn;
    struct map_s *map;
    struct player_s *list_player;
} game_data_t;

void init_map(game_data_t *game_data, rule_t *rule);
void print_map(game_data_t *game_data);
void print_player_score(game_data_t *game_data);

void game_loop(rule_t *rule, game_data_t *game_data);
void init_player(rule_t *rule, game_data_t *game_data);
#endif