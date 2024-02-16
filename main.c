#include <stdio.h>

#include "imeclui.h"

int main()
{
    ime_clear_screen();
    int cols, rows;
    ime_get_tsize(&cols, &rows);
    // printf(IME_BG_CYAN);

    // printf("%s", __ime_get_escape_string(IME_RED));
    // Cell cell = {'a', IME_RED, IME_BG_CYAN};
    // Cell *cell = ime_alloc_cell('a', IME_NORMAL, IME_BG_NORMAL);
    // __ime_log_cell(cell);
    printf("Hello, World!\n");
    printf("\x1B[32m");
    printf("Hello, World!\n");
    printf("\x1B[1;32m");
    printf("Hello, World!\n");

    char *style = ime_style_builder(IME_256_COLOR(50), IME_BG_RGB_COLOR(19, 19, 19), IME_STYLE_BOLD | IME_STYLE_UNDERLINE | IME_STYLE_BLINK | IME_STYLE_STRIKETHROUGH);
    printf(style);
    printf("Hello, World!\n");

    // __ime_log_cell(cell);

    // printf(buffer);
    getch();

    // ime_free_cell(cell);
    return 0;
}