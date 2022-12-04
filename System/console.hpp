#pragma once
#include "UICore.h"

#define posx(x) (term_x0 + x * font_size / 2)
#define posy(y) (term_y0 + y * font_size)
class Console {
private:
    char *term;
    char *inputs;
    uint32_t font_size;
    uint32_t term_x0;
    uint32_t term_y0;
    uint32_t termw; // width of terminal
    uint32_t termh; // height of terminal
    uint32_t curx;  // position of couser
    uint32_t cury;  // position of couser
    UI_Display *uidisp;
    UI_Window *mainw;

public:
    Console(uint32_t fontsize, UI_Display *uidisp, UI_Window *mainw);
    ~Console();
    char *getc(uint32_t x, uint32_t y);
    void puts(char *str);
    void putchar(char c);
    void refresh();
    int read(char c);
};

Console::Console(uint32_t fontsize, UI_Display *ui_disp, UI_Window *ui_win) {
    font_size = fontsize;
    term_x0 = mainw->content_x0;
    term_y0 = mainw->content_y0;
    termw = mainw->content_width / (font_size / 2); // width of terminal
    termh = mainw->content_height / font_size;      // height of terminal
    curx = 0;                                       // position of couser
    cury = 0;                                       // position of couser
    term = (char *)malloc((termw + 1) * termh);
    uidisp = ui_disp;
    mainw = ui_win;
}

Console::~Console() {
    free(term);
    free(inputs);
}

char *Console::getc(uint32_t x, uint32_t y) {
    return term + x * (termw + 1) + y;
}

void Console::puts(char *str) {
    while ((char)*str != '\0') {
        putchar((char)*str);
        str++;
    }
}

void Console::putchar(char c) {
    if (c == '\n') {
        curx = 0;
        cury++;
    } else {
        *getc(curx, cury) = c;
        curx++;
    }
    if (curx >= termw) {
        curx %= termw;
        cury++;
    }
    if (cury >= termh) {
        cury = termh - 1;
        for (uint32_t i = 0; i < termw; i++) {
            for (uint32_t j = 0; j < termh - 1; j++) {
                *getc(j, i) = *getc(j + 1, i) == '\0' ? ' ' : *getc(j + 1, i);
            }
        }
        for (uint32_t i = 0; i < termw; i++) {
            *getc(termh - 1, i) = ' ';
        }
    }
}

void Console::refresh() {
    uidisp->draw_box(mainw->content_x0,
                     mainw->content_y0,
                     mainw->content_x0 + mainw->content_width - 0,
                     mainw->content_y0 + mainw->content_height - 0,
                     -1, 0xFF);
    for (uint32_t i = 0; i < termh; i++) {
        *getc(i, termw) = '\0';
        uidisp->draw_printf(posx(0), posy(i), font_size, 255, -1, "%s", getc(i, 0));
    }
}

int Console::read(char c) {
}

#undef posx
#undef posy
