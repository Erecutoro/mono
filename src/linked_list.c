#include "map.h"
#include "player.h"

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getLength(map_t *head) {
    map_t *tmp = head;
    int i = 0;

    if (head->name != NULL)
        i = 1;
    while(tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void addFront(map_t *head, map_t *newHead) {
    char *tmp = strdup(newHead->name);

    newHead->next = head->next;
    newHead->name = strdup(head->name);
    head->name = tmp;
    head->next = newHead;
}

void addNodeMap(map_t *head, map_t *data) {
    map_t *new = malloc(sizeof(map_t));
    map_t *tmp = head;

    if (head->name == NULL) {
        head->name = strdup(data->name);
        head->type = data->type;
        head->cost = data->cost;
        head->next = head;
        free(new);
        return;
    }
    new->name = strdup(data->name);
    new->type = data->type;
    new->cost = data->cost;
    new->next = head;
    while(tmp->next != head)
        tmp = tmp->next;
    tmp->next = new;
}

void addNodePlayer(player_t *head, int money, int nbr) {
    player_t *new = malloc(sizeof(player_t));
    player_t *tmp = head;

    if (!head->money) {
        head->money = money;
        head->playerNbr = nbr;
        free(new);
        return;
    }
    new->money = money;
    new->playerNbr = nbr;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

int search(map_t *head, char *name) {
    int i = 0;

    for (map_t *tmp = head; tmp->name != NULL || tmp->next != NULL; tmp = tmp->next) {
        if (tmp->name != NULL && strcmp(tmp->name, name) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

int isNumber(map_t *head, char *pos) {
    for (int j = 0; pos[j]; j++)
        if (!isdigit(pos[j]))
            return 0;
    return atoi(pos);
}

void deleteNode(map_t *head, char *name) {
    int i = 0;
    map_t *tmp = head;
    map_t *last = head;
    int pos = search(head, name);

    if (pos == -1 && !isNumber(head, name))
        return;
    while (tmp->next != NULL) {
        if (i == pos) {
            last->next = tmp->next;
            return;
        }
        last = tmp;
        tmp = tmp->next;
        i++;
    }
    last->next = NULL;
    free(tmp);
}

void isEmpty(map_t *head) {
    if (head->name == NULL && head->next == NULL) {
        printf("list is empty\n");
        return;
    }
    printf("list is not empty\n");
}

void display(map_t *head) {
    for (map_t *tmp = head;  tmp->name != NULL; tmp = tmp->next) {
        printf("%s -> ", tmp->name);
        if (tmp->next == NULL)
            break;
    }
    printf("NULL\n");
}
