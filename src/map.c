#include <stdio.h>
#include <stdlib.h>

#include "json.h"
#include "game_data.h"

void print_map(game_data_t *game_data) {
    for (map_t *tmp = game_data->map; tmp->next != game_data->map; tmp = tmp->next) {
        printf("%s -> ", tmp->name);
    }
    printf("\n\n");
}

void init_map(game_data_t *game_data, rule_t *rule) {
    map_t tmp;
    json_value *data = get_json_data(rule);
    game_data->map = malloc(sizeof(map_t));

    if (data == NULL) {
        printf("Error: invalid map or invalid map name (map have to be in map folder)\n");
        return;
    }
    process_value(data, game_data->map, &tmp, NULL);
}
