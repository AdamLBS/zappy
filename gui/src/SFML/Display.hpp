/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "IEntity.hpp"
#include "STrantorian.hpp"
#include "STile.hpp"
#include "../cache/Map.hpp"
#include "SBottom_menu.hpp"

class Display {
    public:
        Display(int width, int height);
        ~Display();
        void render();
        std::unique_ptr<sf::RenderWindow> &getWindow();
        void eventHandler(MapT cache);
        void createMap(int width, int height);
        void update(MapT *cache);
        void keyHandler(MapT cache);
        void clickHandler(MapT cache);
        void createViews(int map_width, int map_height);
        std::string getMessage();
        void resetMessage();

    protected:
    private:
        std::unique_ptr<sf::RenderWindow> _window;
        sf::Event _event;
        std::map<int, std::unique_ptr<IEntity>> _trantorians;
        std::vector<std::unique_ptr<IEntity>> _map;
        std::unique_ptr<SBottom_menu> _bottomMenu;
        sf::View _view;
        sf::View _bottomMenuView;
        sf::Clock _clock_map;
        sf::Clock _clock_trantorian;
        sf::Time _time;
        int _width;
        int _height;
        sf::Vector2f _mapCenter;
        bool _mapCreated = false;
        bool _ShowBottomMenu = false;
        sf::Vector2i _click_pos;
        std::string _message;
};