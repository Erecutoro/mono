#ifndef RULE_H
#define RULE_H

typedef struct rule_s {
    int max_turn;
    int money;
    int player_nbr;
    char *map;
} rule_t;

void default_rule(rule_t *rule);
void set_rule(rule_t *rule);
void print_rule(rule_t *rule);
#endif