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
#include "grush/start_menu.h"

void start_game(void)
{
    win_t *window = window_create();
    img_t *img = img_create(PATH_TO_WALLPAPER);
    menu_t menu;

    main_menu_init(&menu);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        main_menu_update(window, &menu);
        handle_global_events(window);
        sfRenderWindow_display(window);
    }
    window_destroy(window);
    img_destroy(img);
    main_menu_destroy(&menu);
}

w_exit_t main(int argc UNUSED, char **argv UNUSED)
{
    start_game();
    return W_EXIT_OK;
}
