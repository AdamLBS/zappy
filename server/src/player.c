/*
** EPITECH PROJECT, 2023
** player.c
** File description:
** player
*/

#include "../include/server.h"

void generate_player(server_t *server, client_t *cli, int socket, char *team_name)
{
    cli->player = malloc(sizeof(player));
    cli->player->x = 0; // TODO: Check if the start position is random or not
    cli->player->y = 0; cli->player->level = 1;
    cli->player->inv = malloc(sizeof(inventory));
    cli->player->inv->food = 10; cli->player->inv->linemate = 0;
    cli->player->inv->deraumere = 0; cli->player->inv->sibur = 0;
    cli->player->inv->mendiane = 0; cli->player->inv->phiras = 0;
    cli->player->inv->thystame = 0; cli->player->is_dead = 0;
    cli->player->orientation = 'N';
    cli->player->team_name = strdup(team_name); cli->player->socket = socket;
    cli->player->state = ALIVE; cli->player->uid = strdup(cli->uid);
    server->game->map[0][0].players = malloc(sizeof(player_queue));
    player_queue *p_queue = malloc(sizeof(player_queue));
    p_queue->player = cli->player;
    LIST_INSERT_HEAD(&server->game->map[0][0].player_head, p_queue, next);
}

void generate_gui_player(client_t *cli, int socket)
{
    cli->gui_player = malloc(sizeof(gui_player));
    cli->gui_player->x = 0;
    cli->gui_player->y = 0;
    cli->gui_player->socket = socket;
}

int check_if_solo_on_tile(server_t *server, client_t *cli)
{
    int count = 0;
    LIST_FOREACH(cli, &server->head, next) {
        if (count > 1) {
            return 1;
        }
        count++;
    }
    return 0;
}

void add_player_from_queue(tile *tile, player *player)
{
    player_queue *p_queue = malloc(sizeof(player_queue));
    p_queue->player = player;
    LIST_INSERT_HEAD(&tile->player_head, p_queue, next);
}

void remove_player_from_queue(tile *tile, player *player)
{
    player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &tile->player_head, next) {
        if (strcmp(tmp->player->uid, player->uid) == 0) {
            LIST_REMOVE(tmp, next);
        }
    }
}

player *get_player_from_queue(tile *target, player *player)
{
    player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &target->player_head, next) {
        if (strcmp(tmp->player->uid, player->uid) == 0)
            return tmp->player;
    }
    return NULL;
}