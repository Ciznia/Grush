/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** Global Event Handler
*/
#include "SFML/Window/Event.h"
#include "SFML/Graphics.h"
#include "window_internal.h"

void handle_global_events(win_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
