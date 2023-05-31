/*
** EPITECH PROJECT, 2023
** server.h
** File description:
** server.h
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/queue.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdbool.h>
#include <uuid/uuid.h>
#include <time.h>

#define ARG_COND ; optind < ac \
&& av[optind][0] != '-'; optind++
#define MAX_BODY_LENGTH 1024
enum state {
    NONE,
    DEAD,
    FORK,
    EJECT,
    EGG,
};

typedef struct inventory {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory;

typedef struct gui_player {
    int x;
    int y;
    int socket;
} gui_player;

typedef struct egg {
    int x;
    int y;
    int time;
    int level;
    int max_level;
} egg;

typedef struct player {
    char *uuid;
    int x;
    int y;
    int level;
    inventory *inv;
    int is_dead;
    char orientation;
    char *team_name;
    int socket;
} player;

typedef struct tile {
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    player *player; // if a player is on the tile
} tile;

typedef struct client {
    int socket;
    char *uid;
    char *buffer;
    char *team_name;
    player *player;
    gui_player *gui_player;
    LIST_ENTRY(client) next;
} client_t;

typedef struct team {
    char *name;
    int max_clients;
    int clients;
    LIST_ENTRY(team) next;
} team_t;

extern LIST_HEAD(list_head, client) head;
extern LIST_HEAD(team_listhead, team) team_head;

typedef struct server_s {
    int port;
    int width;
    int height;
    char **sname;
    int clientsNb;
    int freq;
    int socket;
    struct list_head head;
    struct team_listhead team_head;
} server_t;


void print_help(void);
void fetch_arguments(server_t *s_infos, int arg, char **av, int ac);
void check_args(server_t *s_infos);
server_t *create_server_struct(void);
int my_arrlen(char **arr);
void init_server(server_t *s_infos);
void add_client(server_t *s_infos);
void loop_server(server_t *s_infos);
client_t *generate_client(int socket);
void check_command(client_t *cli, server_t *s_infos);
void handle_client_data(server_t *s_infos, fd_set *readfds);
void generate_teams(server_t *server, struct team_listhead *team_head);
team_t *generate_team(char *name, int maxclient);
int commands(server_t *server, client_t *client, char *buffer);
int add_client_to_team(server_t *s_infos, char *team, client_t *cli);
int get_available_slots_in_team(server_t *s_infos, char *team);
int does_team_has_space(server_t *s_infos, char *team);
int does_team_exists(server_t *s_infos, char *team);
void remove_client_from_team(client_t *cli, server_t *s_infos);
