#include <stdio.h>
#include <stdlib.h>

#include "game_data.h"

int dice() {
    return rand() % 6 + 1;
}

void print_player_score(game_data_t *game_data) {
    printf("\n");
    for (player_t *tmp = game_data->list_player; tmp != NULL; tmp = tmp->next) {
        printf("Player %d's score: %d\n", tmp->playerNbr + 1, tmp->money);
    }
    printf("\n");
}

void move_player(game_data_t *game_data) {
    int move = dice();
    int i = 0;
    map_t *tmp = game_data->map;
    player_t *curr_player = game_data->list_player;

    printf("Player %d roled a %d !\n", game_data->player_turn + 1, move);
    for (int i = 0; i < move; i++)
        tmp = tmp->next;
    printf("Player %d is now at %s!\n", game_data->player_turn + 1, tmp->name);
    for (int i = 0; i < game_data->player_turn; i++)
        curr_player = curr_player->next;
    curr_player->money += tmp->cost;
}

void print_game(game_data_t *game_data) {
    print_map(game_data);
    print_player_score(game_data);
}

void init_game(rule_t *rule, game_data_t *game_data) {
    init_map(game_data, rule);
    init_player(rule, game_data);
}

void winner(game_data_t *game_data) {
    player_t *best = game_data->list_player;

    for (player_t *tmp = game_data->list_player; tmp != NULL; tmp = tmp->next) {
        if (best->money < tmp->money)
            best = tmp;
    }
    printf("The winner is player %d with %d money !\n", best->playerNbr + 1, best->money);
}

void game_loop(rule_t *rule, game_data_t *game_data) {
    int opt = 0;

    init_game(rule, game_data);
    for (int move = 0, turn = 0; turn < rule->max_turn * rule->player_nbr; move = 0, turn++) {
        print_game(game_data);
        move_player(game_data);
        printf("press 1 to quit\n> ");
        if (scanf("%d", &opt) == EOF)
            return;
        if (opt == 1) return;
        if (game_data->player_turn >= rule->player_nbr - 1)
            game_data->player_turn = 0;
        else
            game_data->player_turn++;
    }
    winner(game_data);
}
