/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** Window Management
*/
#include <SFML/Graphics.h>
#include "window_internal.h"

sfRenderWindow *window_create(void)
{
    sfVideoMode video_mode = {
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        WINDOW_COLOR_MODE
    };

    return sfRenderWindow_create(video_mode, WINDOW_TITLE, sfClose, NULL);
}

void window_destroy(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}
