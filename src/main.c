#include <stdio.h>
#include <stdlib.h>

#include "rule.h"
#include "game_data.h"

void init_player(rule_t *rule, game_data_t *game_data) {
    game_data->list_player = malloc(sizeof(player_t));
    game_data->player_turn = 0;
    for (int i = 0; i < rule->player_nbr; i++)
        addNodePlayer(game_data->list_player, rule->money, i);
}

void init_default(rule_t *rule) {
    default_rule(rule);
}

void loop(rule_t *rule, game_data_t *game_data) {
    int menuOpt = 0;

    while (1) {
        printf("1. set rule\n2. see rule\n3. start game\n4. exit\n> ");
        if (scanf("%d", &menuOpt) == EOF)
            return;
        switch (menuOpt) {
            case 1:
                set_rule(rule);
                break;
            case 2:
                print_rule(rule);
                break;
            case 3:
                game_loop(rule, game_data);
            case 4:
                return;
            default:
                break;
        }
    }
}

int main() {
    rule_t *rule = malloc(sizeof(rule_t));
    game_data_t *game_data = malloc(sizeof(game_data_t));

    init_default(rule);
    loop(rule, game_data);
    return 0;
}