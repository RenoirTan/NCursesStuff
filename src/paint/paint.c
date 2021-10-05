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
    int underneath = winch(window);
    bool moved = false;
    penstate_t pen = PEN_UP;

    wmove(window, y, x);

    while ((ch = getch()) != EXIT_APP) {
        moved = false;
        underneath = winch(window);
        waddch(window, CURSOR);

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

        if (pen == PEN_DOWN) {
            underneath = FILLED;
        }
        if (moved) {
            waddch(window, underneath);
            wmove(window, y, x);
        }

        wrefresh(window);
    }
    return 0;
}
