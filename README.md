# Minesweeper

The Minesweeper Game — Classic implementation in C++.

## Description

This repository contains a version of the popular Minesweeper game developed mainly in C++. The objective of the game is to uncover all empty squares on a board without revealing a mine.

## Features

- Text-based interface to play in the terminal.
- Mine generation logic and cell handling.
- Win and loss detection.
- Modular and documented code.
- Compatible with Unix/Linux systems.
- Player management via a file.

## Technologies used

- **Main language:** C++
- Other languages: Makefile, Objective-C, C, Shell, BitBake

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/carloss433/BUSCAMINAS.git
   cd BUSCAMINAS
   ```

2. Build the project (requires `make` and a C++ compiler):

   ```bash
   make
   ```

3. Run the game:

   ```bash
   ./buscaminas -f <rows> -c <columns> -m <mines> -fich <players_file> -nick <player_nick>
   ```

   - `<rows>`: number of rows of the board.
   - `<columns>`: number of columns of the board.
   - `<mines>`: number of mines.
   - `<players_file>`: file where player data is stored.
   - `<player_nick>`: player nickname.

   Example:
   ```bash
   ./buscaminas -f 10 -c 10 -m 15 -fich jugadores.txt -nick carlos433
   ```

## Usage

Follow the instructions shown in the terminal to play. Choose the cells you want to reveal and try to avoid the mines.

## Project structure

- `src/` — Main source code in C++.
- `Makefile` — Script to build the project.
- Other files related to configuration and support.

## Contributions

Contributions are welcome! If you find a bug or want to propose an improvement, open an issue or a pull request.

## License

This project is distributed under the Eclipse Public License v2.0. See the [LICENSE](LICENSE) file for more details.

---


# BUSCAMINAS

El Juego del Buscaminas — Implementación clásica en C++.

## Descripción

Este repositorio contiene una versión del popular juego Buscaminas (Minesweeper) desarrollada principalmente en C++. El objetivo del juego es descubrir todas las casillas vacías de un tablero sin detonar ninguna mina.

## Características

- Interfaz de texto para jugar en la terminal.
- Lógica de generación de minas y manejo de casillas.
- Detección de victoria y derrota.
- Código modular y documentado.
- Compatible con sistemas Unix/Linux.
- Gestión de jugadores mediante fichero.

## Tecnologías utilizadas

- **Lenguaje principal:** C++
- Otros lenguajes: Makefile, Objective-C, C, Shell, BitBake

## Instalación

1. Clona el repositorio:

   ```bash
   git clone https://github.com/carloss433/BUSCAMINAS.git
   cd BUSCAMINAS
   ```

2. Compila el proyecto (requiere `make` y compilador de C++):

   ```bash
   make
   ```

3. Ejecuta el juego:

   ```bash
   ./buscaminas -f <filas> -c <columnas> -m <minas> -fich <fichero_jugadores> -nick <nick_jugador>
   ```

   - `<filas>`: número de filas del tablero.
   - `<columnas>`: número de columnas del tablero.
   - `<minas>`: número de minas.
   - `<fichero_jugadores>`: archivo donde se almacenan los datos de los jugadores.
   - `<nick_jugador>`: nombre de usuario del jugador.

   **Ejemplo:**
   ```bash
   ./buscaminas -f 10 -c 10 -m 15 -fich jugadores.txt -nick carlos433
   ```

## Uso

Sigue las instrucciones que aparecen en la terminal para jugar. Elige las casillas que quieres descubrir e intenta evitar las minas.

## Estructura del proyecto

- `src/` — Código fuente principal en C++.
- `Makefile` — Script para compilar el proyecto.
- Otros archivos relacionados a la configuración y soporte.

## Contribuciones

¡Las contribuciones son bienvenidas! Si encuentras un bug o quieres proponer una mejora, abre un issue o un pull request.

## Licencia

Este proyecto se distribuye bajo la licencia Eclipse Public License v2.0. Consulta el archivo [LICENSE](LICENSE) para más detalles.
