#include <iostream>

char **ai_turn(char **gamefield, int turn_number) {
    // int turn_counter = 0;

    if (turn_number == 0 and gamefield[1][1] == ' ') {
        gamefield[1][1] = 'O';
        return gamefield;

    } else if (turn_number == 0 and gamefield[1][1] == 'X') {
        int positions[4] = {1, 3, 7, 9};
        int lenght = sizeof(positions) / sizeof(int);
        int random_position = positions[rand() % lenght];

        if (random_position == 1) {
            gamefield[0][0] = 'O';
            return gamefield;
        } else if (random_position == 3) {
            gamefield[0][2] = 'O';
            return gamefield;
        } else if (random_position == 7) {
            gamefield[2][0] = 'O';
            return gamefield;
        } else if (random_position == 9) {
            gamefield[2][2] = 'O';
            return gamefield;
        }

    } else if (turn_number == 1) {
        if (gamefield[0][0] == 'X') {
            gamefield[2][2] = 'O';
            return gamefield;
        } else if (gamefield[0][2] == 'X') {
            gamefield[2][0] = 'O';
            return gamefield;
        } else if (gamefield[2][0] == 'X') {
            gamefield[0][2] = 'O';
            return gamefield;
        } else if (gamefield[2][2] == 'X') {
            gamefield[0][0] = 'O';
            return gamefield;
        }

    } else if (turn_number > 0) {

        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (gamefield[y][x] == 'X') {
                    if (x - 1 >= 0 and gamefield[y][x - 1] == 'X') {
                        if (x + 1 <= 2 and gamefield[y][x + 1] != 'O') {
                            gamefield[y][x + 1] = 'O';
                            return gamefield;
                        } else if (x - 1 >= 0 and gamefield[y][x + 1] != 'O'){
                            gamefield[y][x - 1] = 'O';
                            return gamefield;
                        }

                    } else if (x + 1 <= 2 and gamefield[y][x + 1] == 'X') {
                        if (x + 1 <= 2 and gamefield[y][x + 1] != 'O') {
                            gamefield[y][x + 1] = 'O';
                            return gamefield;
                        } else if (x - 1 >= 0 and gamefield[y][x + 1] != 'O'){
                            gamefield[y][x - 1] = 'O';
                            return gamefield;
                        }

                    } else if (y - 1 >= 0 and gamefield[y - 1][x] == 'X') {
                        if (y + 1 <= 2 and gamefield[y + 1][x] != 'O') {
                            gamefield[y + 1][x] = 'O';
                            return gamefield;
                        } else if (y - 1 >= 0 and gamefield[y - 1][x] != 'O'){
                            gamefield[y - 1][x] = 'O';
                            return gamefield;
                        }
                    } else if (y + 1 <= 2 and gamefield[y + 1][x] == 'X') {
                        if (y + 1 <= 2 and gamefield[y + 1][x] != 'O') {
                            gamefield[y + 1][x] = 'O';
                            return gamefield;
                        } else if (y - 1 >= 0 and gamefield[y - 1][x] != 'O'){
                            gamefield[y - 1][x] = 'O';
                            return gamefield;
                        }

                    } else if ((y + 1 <= 2 and x - 1 >= 0) and gamefield[y + 1][x - 1] == 'X') {
                        if (x + 1 <= 2 and y - 1 >= 0 and gamefield[y - 1][x + 1] != 'O') {
                            gamefield[y - 1][x + 1] = 'O';
                            return gamefield;
                        }
                    } else if ((y + 1 <= 2 and x + 1 <= 2) and gamefield[y + 1][x + 1] == 'X') {
                        if (x - 1 >= 0 and y - 1 >= 0 and gamefield[y - 1][x + 1] != 'O') {
                            gamefield[y - 1][x - 1] = 'O';
                            return gamefield;
                        }
                    } else if ((y - 1 >= 0 and x - 1 >= 0) and gamefield[y - 1][x - 1] == 'X') {
                        if (x + 1 <= 2 and y + 1 <= 2 and gamefield[y + 1][x + 1] != 'O') {
                            gamefield[y + 1][x + 1] = 'O';
                            return gamefield;
                        }
                    } else if ((y - 1 >= 0 and x + 1 <= 2) and gamefield[y - 1][x + 1] == 'X' and
                               gamefield[y + 1][x - 1] == 'O') {
                        if (x - 1 >= 0 and y + 1 <= 2 and gamefield[y + 1][x - 1] != 'O') {
                            gamefield[y + 1][x - 1] = 'O';
                            return gamefield;
                        }

                    } else if (y + 2 == 2 and gamefield[y + 2][x] == 'X' and gamefield[y + 1][x] != 'O') {
                        gamefield[y + 1][x] = 'O';
                        return gamefield;
                    } else if (y - 2 == 0 and gamefield[y - 2][x] == 'X' and gamefield[y - 1][x] != 'O') {
                        gamefield[y - 1][x] = 'O';
                        return gamefield;
                    } else if (x - 2 == 0 and gamefield[y][x - 2] == 'X' and gamefield[y][x - 1] != 'O') {
                        gamefield[y][x - 1] = 'O';
                        return gamefield;
                    } else if (x + 2 == 0 and gamefield[y][x + 2] == 'X' and gamefield[y][x + 1] != 'O') {
                        gamefield[y][x + 1] = 'O';
                        return gamefield;

                    } else if ((y + 2 == 2 and x + 2 == 2) and gamefield[y + 2][x + 2] == 'X' and
                               gamefield[y + 1][x + 1] != 'O') {
                        gamefield[y + 1][x + 1] = 'O';
                        return gamefield;
                    } else if ((y + 2 == 2 and x - 2 == 0) and gamefield[y + 2][x - 2] == 'X' and
                               gamefield[y + 1][x - 1] != 'O') {
                        gamefield[y + 1][x - 1] = 'O';
                        return gamefield;
                    } else if ((y - 2 == 0 and x + 2 == 2) and gamefield[y - 2][x + 2] == 'X' and
                               gamefield[y - 1][x - 1] != 'O') {
                        gamefield[y - 1][x - 1] = 'O';
                        return gamefield;
                    } else if ((y - 2 == 0 and x - 2 == 0) and gamefield[y - 2][x - 2] == 'X' and
                               gamefield[y - 1][x - 1] != 'O') {
                        gamefield[y - 1][x - 1] = 'O';
                        return gamefield;
                    }


                }
            }
        }

    }
}

void printGF(char **gf) {
    std::cout << " " << gf[0][0] << " | " << gf[0][1] << " | " << gf[0][2] << std::endl <<
              "---+---+---" << std::endl <<
              " " << gf[1][0] << " | " << gf[1][1] << " | " << gf[1][2] << std::endl <<
              "---+---+---" << std::endl <<
              " " << gf[2][0] << " | " << gf[2][1] << " | " << gf[2][2] << std::endl;
}


int main() {

    char **gf = new char *[3];

    gf[0] = new char[3]{'X', ' ', 'O'};
    gf[1] = new char[3]{' ', ' ', ' '};
    gf[2] = new char[3]{'X', ' ', ' '};

    printGF(ai_turn(gf, 2));
}