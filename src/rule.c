#include <stdio.h>
#include <string.h>

#include "rule.h"

int input(int rule) {
    int in = 0;

    while (1) {
        if (scanf("%d", &in) == EOF)
            return rule;
        return in;
    }
}

void default_rule(rule_t *rule) {
    rule->max_turn = 20;
    rule->money = 1000;
    rule->player_nbr = 2;
    rule->map = "map.json";
}

void set_rule(rule_t *rule) {
    int opt = 0;
    char *in = NULL;

    while (1) {
        printf("1. change max_turn\n");
        printf("2. change starting money\n");
        printf("3. change number of playing player\n");
        printf("4. change map(map need to be in map folder no need to add map/mapname.json just mapname.json)\n");
        printf("5. exit\n> ");
        if (scanf("%d", &opt) == EOF)
            return;
        printf("> ");
        switch (opt) {
        case 1:
            rule->max_turn = input(rule->max_turn);
            break;
        case 2:
            rule->money = input(rule->money);
            break;
        case 3:
            rule->player_nbr = input(rule->player_nbr);
            break;
        case 4:
            if (scanf("%s", in) == EOF)
                return;
            rule->map = strdup(in);
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}

void print_rule(rule_t *rule) {
    printf("Max turn: %d\n", rule->max_turn);
    printf("Starting money: %d\n", rule->money);
    printf("Number of player: %d\n", rule->player_nbr);
    printf("Selected map: %s\n", rule->map);
}