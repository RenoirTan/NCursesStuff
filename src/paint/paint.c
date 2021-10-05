#include <stdbool.h>
#include "paint.h"
#include "_paint.h"

char CURSOR = 'O';
char FILLED = '#';
char UNFILLED = ' ';

int main_loop(WINDOW *window) {
    int rows, columns;
    getmaxyx(window, rows, columns);
    int x = 0, y = 0;
    int ch;
    bool moved = false;
    penstate_t pen = PEN_UP;

    init_empty_window(window);
    wmove(window, y, x);

    while ((ch = getch()) != EXIT_APP) {
        moved = false;

        switch (ch) {
            case MOVE_UP:
                if (y > 0) {
                    --y;
                    moved = true;
                }
                break;
            case MOVE_DOWN:
                if (y + 1 < rows) {
                    ++y;
                    moved = true;
                }
                break;
            case MOVE_LEFT:
                if (x > 0) {
                    --x;
                    moved = true;
                }
                break;
            case MOVE_RIGHT:
                if (x + 1 < columns) {
                    ++x;
                    moved = true;
                }
                break;
            case RAISE_PEN:
                pen = PEN_UP;
                break;
            case LOWER_PEN:
                pen = PEN_DOWN;
            default:
                break;
        }

        wmove(window, y, x);
        if (pen == PEN_DOWN) {
            wdelch(window);
            winsch(window, FILLED);
        }

        wrefresh(window);
    }
    return 0;
}

void init_empty_window(WINDOW *window) {
    int rows, columns;
    getmaxyx(window, rows, columns);
    int x = 0, y = 0;
    for (x = 0; x < columns; ++x) {
        for (y = 0; y < rows; ++y) {
            mvwaddch(window, y, x, UNFILLED);
        }
    }
}
