#ifndef MAP_H
#define MAP_H

#include "rule.h"
#include "json.h"

#define START 0
#define HOTEL 1
#define EVENT 2

typedef struct map_s {
    char *name;
    int type;
    int cost;
    struct map_s *next;
} map_t;

void addNodeMap(map_t *head, map_t *data);

void process_value(json_value* value, map_t *map, map_t *tmp, char *type);
void process_object(json_value* value, map_t *map, map_t *tmp);
void process_array(json_value* value, map_t *map, map_t *tmp);
json_value *get_json_data(rule_t *rule);
#endif