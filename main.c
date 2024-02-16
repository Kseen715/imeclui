#include <stdio.h>

#include "imeclui.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, NULL);

    ime_clear_screen();
    int cols, rows;
    ime_get_tsize(&cols, &rows);

    /* Classic */
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    printf("Hello, World!\n");

    char *normal = ime_style_builder(IME_NORMAL, IME_BG_NORMAL, 0);
    char *style;

    /* Common red text */
    printf(normal);
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    style = ime_style_builder(IME_RED, IME_BG_NORMAL, 0);
    printf(style);
    free(style);
    printf("Hello, World!\n");

    /* Inverted colors */
    printf(normal);
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    style = ime_style_builder(IME_NORMAL, IME_BG_GREEN, IME_STYLE_INVERTED);
    printf(style);
    free(style);
    printf("Hello, World!\n");

    /* Super-ultra-fancy-RGB colors and styles */
    printf(normal);
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    style = ime_style_builder(IME_256_COLOR(50), IME_BG_RGB_COLOR(19, 19, 19),
                              IME_STYLE_BOLD | IME_STYLE_UNDERLINE |
                                  IME_STYLE_BLINK | IME_STYLE_STRIKETHROUGH);
    printf(style);
    free(style);
    printf("Hello, World!\n");

    /* Cell builder */
    printf(normal);
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    Cell *cell = ime_alloc_cell('Б', IME_256_COLOR(50),
                                IME_BG_RGB_COLOR(19, 19, 19),
                                IME_STYLE_BLINK | IME_STYLE_ITALIC);
    __ime_log_cell(cell);
    ime_free_cell(cell);

    /* Buffer builder */
    printf(normal);
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    CellBuffer *buf = ime_alloc_cells(3, 3);
    __ime_log_cells(buf);
    ime_free_cells(buf);

    /* Drawing separate cells */
    printf(normal);
    printf("---==== %s:%d ====---\n", __FILE__, __LINE__ + 1);
    Cell *dr_cell = ime_alloc_cell('@', IME_RGB_COLOR(255, 19, 19),
                                   IME_BG_RGB_COLOR(120, 120, 120),
                                   IME_STYLE_BLINK | IME_STYLE_ITALIC);
    ime_draw_cell(dr_cell, 30, 22);
    ime_draw_cell(dr_cell, 31, 22);
    ime_free_cell(dr_cell);

    printf(normal);
    printf("0x%04X", 'Б');
    Cell *rect_cell = ime_alloc_cell(0xC4, IME_RGB_COLOR(19, 190, 190),
                                     IME_BG_RGB_COLOR(120, 120, 120),
                                     IME_STYLE_BLINK);
    ime_fill_rect(rect_cell, 70, 5, 100, 13);
    ime_fill_rect(rect_cell, 90, 13, 120, 15);

    getch();
    return 0;
}