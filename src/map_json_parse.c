#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "json.h"
#include "game_data.h"

void process_object(json_value* value, map_t *map, map_t *tmp)
{
    int length, x;

    if (value == NULL) return;
    length = value->u.object.length;
    for (x = 0; x < length; x++) {
            // printf("object[%d].name = %s\n", x, value->u.object.values[x].name);
            process_value(value->u.object.values[x].value, map, tmp, value->u.object.values[x].name);
    }
    addNodeMap(map, tmp);
}

void process_value(json_value* value, map_t *map, map_t *tmp, char *type)
{
    if (value == NULL) return;

    switch (value->type) {
        case json_object:
            process_object(value, map, tmp);
            break;
        case json_array:
            process_array(value, map, tmp);
            break;
        case json_integer:
            if (type != NULL && !strcmp(type, "type"))
                tmp->type = (long)value->u.integer;
            else
                tmp->cost = (long)value->u.integer;
            break;
        case json_string:
            if (type != NULL && !strcmp(type, "name"))
                tmp->name = strdup(value->u.string.ptr);
            break;
    }
}

void process_array(json_value* value, map_t *map, map_t *tmp)
{
    int length;
    int x;

    if (value == NULL) return;
    length = value->u.array.length;
    // printf("array\n");
    for (x = 0; x < length; x++)
            process_value(value->u.array.values[x], map, tmp, NULL);
}

json_value *get_json_data(rule_t *rule) {
    FILE *fp;
    struct stat filestatus;
    int file_size;
    char* file_contents;
    json_char* json;
    char *buff = malloc(sizeof(char) * strlen(rule->map)+5);

    strcat(buff, "map/");
    strcat(buff, rule->map);
    if (stat(buff, &filestatus) != 0) {
            fprintf(stderr, "File %s not found\n", buff);
            return NULL;
    }
    file_size = filestatus.st_size;
    file_contents = (char*)malloc(filestatus.st_size);
    if (file_contents == NULL) {
        fprintf(stderr, "Memory error: unable to allocate %d bytes\n", file_size);
        return NULL;
    }
    fp = fopen(buff, "rt");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open %s\n", buff);
        fclose(fp);
        free(file_contents);
        return NULL;
    }
    if (fread(file_contents, file_size, 1, fp) != 1 ) {
        fprintf(stderr, "Unable to read content of %s\n", buff);
        fclose(fp);
        free(file_contents);
        return NULL;
    }
    fclose(fp);
    json = (json_char*)file_contents;
    return json_parse(json,file_size);
}