/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** main
*/
#include "SFML/Graphics.h"

#include "w_exit_states.h"
#include "w_utils.h"

#include "grush/window.h"
#include "grush/events.h"
#include "grush/sprite.h"

void start_game(void)
{
    win_t *window = window_create();
    img_t *img = img_create(PATH_TO_WALLPAPER);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        img_update(img, window);
        handle_global_events(window);
        sfRenderWindow_display(window);
    }
    window_destroy(window);
    img_destroy(img);
}

w_exit_t main(int argc UNUSED, char **argv UNUSED)
{
    start_game();
    return W_EXIT_OK;
}
