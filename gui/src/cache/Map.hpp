/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#pragma once

#include "Tile.hpp"
#include "Teams.hpp"
#include "Trantorians.hpp"
#include "Egg.hpp"
#include <tuple>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>

class MapT
{
    private:
        int x = 0;
        int y = 0;
        std::map<std::tuple<double, double>, Tile> tile;
        std::vector<Teams> teams;
        std::vector<Trantorian> trantorians;
        std::vector<Egg> eggs;
        double frequency = 0.0;
    public:
        MapT();
        ~MapT();
        void setX(int x);
        void setY(int y);
        void setTile(std::tuple<double, double> pos, Tile tile);
        int getX();
        int getY();
        Tile getTile(int x, int y);
        void addTeam(Teams team);
        void addTrantorian(Trantorian trantorian);
        void addEgg(Egg egg);
        void removeEgg(int egg);
        void removeTrantorian(int id);
        void removeTeam(std::string id);
        void setTrantorianPos(int id, int x, int y, int orientation);
        void setTrantorianLvl(int id, int lvl);
        void setTrantorianStock(int id, int x, int y, Stock stock);
        void setTrantorianMessage(int id, std::string message);
        std::vector<Egg> getEggs();
        int getEggsFromPos(int x, int y);
        std::vector<Teams> getTeams();
        std::vector<Trantorian> getTrantorians();
        Trantorian getTrantorian(int id);
        double getFrequency();
        void setFrequency(double frequency);
        sf::Vector2i firstPlacedEgg();
};