#include <stdint.h>
#include <ncurses.h>

int32_t main_loop(WINDOW *window) {
    int32_t n_keys = 0;
    int ch;

    while ((ch = wgetch(window)) != KEY_F(4)) {
        ++n_keys;
        wprintw(window, "%d: ", n_keys);
        wattron(window, A_BOLD);
        wprintw(window, "%c", ch);
        wattroff(window, A_BOLD);
        wprintw(window, " ");
        wattron(window, A_ITALIC);
        wprintw(window, "%d", ch);
        wattroff(window, A_ITALIC);
        wprintw(window, "\n");
        wrefresh(window);
    }

    return n_keys;
}

int main(int argc, char **argv) {
    initscr();
    raw(); // Disable line buffering
    keypad(stdscr, true); // Allow use of function keys and arrow keys etc
    noecho(); // Don't echo during getch

    printw("Keylogger. Press F4 to end.\n");
    int32_t count = main_loop(stdscr);

    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    return 0;
}
