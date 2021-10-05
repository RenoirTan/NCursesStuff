#ifndef _NCURSES_STUFF_PAINT_PAINT_H
#   define _NCURSES_STUFF_PAINT_PAINT_H

#   include <ncurses.h>

#   ifdef __cplusplus
extern "C" {
#   endif

char CURSOR;
char FILLED;
char UNFILLED;

typedef enum paintkey_t {
    EXIT_APP = 27, // Esc
    MOVE_UP = KEY_UP,
    MOVE_DOWN = KEY_DOWN,
    MOVE_LEFT = KEY_LEFT,
    MOVE_RIGHT = KEY_RIGHT,
    RAISE_PEN = 339, // Page Up
    LOWER_PEN = 338 // Page Down
} paintkey_t;

typedef enum penstate_t {
    PEN_DOWN = 1,
    PEN_UP = 0
} penstate_t;

void init_empty_window(WINDOW *window);

#   ifdef __cplusplus
}
#   endif

#endif
