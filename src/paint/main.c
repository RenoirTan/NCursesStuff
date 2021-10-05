#include <ncurses.h>
#include "paint.h"


int main(int argc, char **argv) {
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();

    refresh();
    printw("Use the arrow keys to move the pen around.\n");
    printw("Press `page up` to raise the pen above the paper.\n");
    printw("Press `page down` to lower the pen onto the paper.\n");
    printw("Press `esc` to exit the program.\n");
    printw("Press any key to get rid of this help message.\n");
    getch();
    clear();

    main_loop(stdscr);

    int last_row = getmaxy(stdscr) - 1;
    mvaddstr(last_row, 0, "Press any key to exit.");
    refresh();
    getch();
    endwin();
    return 0;
}
