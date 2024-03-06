https://github.com/AdamLBS/zappy/assets/30260219/6f358351-4f3f-48b2-9c77-82d37c1ac537


# Zappy Project Documentation




Zappy is a project consisting of three programs: AI, Server, and GUI. These programs can be compiled using a make file provided in the project. The `make` command can be used to build the programs, and `make re` can be used to rebuild them.

## Game
The game itself isn't played by humans but by an AI. The goal of the game is to make the trantorians go to Level 8, you can connect more than one team to make them compete with eachother. This repository contains the Zappy Server, the core of the game, that handles the players actions & the map, it also contains the GUI and the AI used to play the game.

## AI Program

The AI program allows you to control an AI agent in the Zappy game. It can be launched using the following command:
./zappy_ai -p port -n name -h machine

**Usage:**
- `port` is the port number.
- `name` is the name of the team.
- `machine` is the name of the machine (localhost by default).

**Code:**
The code is in the AI subdirectory.

## Server Program

The Server program is responsible for managing the Zappy game server. It can be launched using the following command:

./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq


**Usage:**
- `port` is the port number.
- `width` is the width of the game world.
- `height` is the height of the game world.
- `nameX` is the name of team X.
- `clientsNb` is the number of authorized clients per team.
- `freq` is the reciprocal of the time unit for execution of actions.

**Code:**
The code is in the server subdirectory.

## GUI Program

The GUI program provides a graphical interface to visualize the Zappy game. It can be launched using the following command:

./zappy_gui

**Code:**
The code is in the GUI subdirectory.

**Note:** The whole Zappy project requires Python3, SFML, and LibUUID to be installed. It has been tested on Debian, Ubuntu, Fedora & WSL2.

Please refer to the project's documentation for more details on building, configuring, and running the Zappy programs.

## Credits

The Zappy project was developed by the following team members:

- Adam ELAOUMARI (adam.elaoumari@epitech.eu)
- Corentin FORTES (corentin.fortes@epitech.eu)
- Florian GRIMA (florian.grima@epitech.eu)
- Gabriel MORAIS (gabriel.de-souza-morais@epitech.eu)
- Martin RAMDANE (martin.ramdane@epitech.eu)
- Lucas RIZZUTO (lucas.rizzuto@epitech.eu)
