/*Bebtek engine v2*/
/*More optimized and faster version of Bebtek engine v1*/
/*Created Dec 16th, 2023*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <termios.h>

/*IMPLEMENTATION
In main.cpp:

#include <iostream>
#include "Engine.h"

int main(){
    Engine engine;
    engine.waitForInput();
    return 0;
}

*/

class Engine {
public:
    void waitForInput() {
        setTerminalMode();
        char c;
        while (true) {
            std::cout << "command -> ";
            std::cin.get(c);
            if (c == 'p') {
                std::cout << "Test" << std::endl;
            } else if (c == 'e') {
                system("clear");
                break;
            } else {
                std::cout << "Unknown command..." << std::endl;
            }
        }
        restoreTerminalMode();
    }
private:
    struct termios originalTermios;

    void setTerminalMode() {
        tcgetattr(STDIN_FILENO, &originalTermios);

        struct termios newTermios = originalTermios;
        newTermios.c_lflag &= ~ICANON; // Disable canonical mode
        newTermios.c_lflag &= ~ECHO;   // Disable echoing input characters

        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    }

    void restoreTerminalMode() {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
    }
};
