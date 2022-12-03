#pragma once
#include "UICore.h"

namespace cons {
    const short font_size = 12;
    const short term_x0 = mainw->content_x0;
    const short term_y0 = mainw->content_y0;
    const short termw = mainw->content_width / (font_size / 2); // width of terminal
    const short termh = mainw->content_height / font_size;      // height of terminal
    static char term[termh][termw + 1];                         // terminal display screen
    static short curx = 0;                                      // position of couser
    static short cury = 0;                                      // position of couser
    char* inputs;
#define posx(x) (term_x0 + x * font_size / 2)
#define posy(y) (term_y0 + y * font_size)

    int puts(char *str) {
        while ((char)*str != '\0') {
            putchar((char)*str);
            str++;
        }
    }

    int putchar(char c) {
        if (c == '\n') {
            curx = 0;
            cury++;
        } else {
            term[curx][cury] = c;
            curx++;
        }
        if (curx >= termw) {
            curx %= termw;
            cury++;
        }
        if (cury >= termh) {
            cury = termh - 1;
            for (short i = 0; i < termw; i++) {
                for (short j = 0; j < termh - 1; j++) {
                    term[j][i] = term[j + 1][i] == '\0' ? ' ' : term[j + 1][i];
                }
            }
            for (short i = 0; i < termw; i++) {
                term[termh - 1] = ' ';
            }
        }
    }

    void refresh() {
        uidisp->draw_box(mainw->content_x0,
                         mainw->content_y0,
                         mainw->content_x0 + mainw->content_width - 0,
                         mainw->content_y0 + mainw->content_height - 0,
                         -1, 0xFF);
        for (short i = 0; i < termh; i++) {
            term[i][termw] = '\0';
            uidisp->draw_printf(posx(0), posy(i), font_size, 255, -1, "%s", term[i]);
        }
    }

    int read(char c){}

#undef posx
#undef posy
} // namespace cons
