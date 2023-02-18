/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** Global Event Handler
*/
#include "SFML/Window/Event.h"
#include "SFML/Graphics.h"
#include "grush/csfml.h"
#include "grush/window.h"

void click_event(win_t *window, scene_t *scene, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > 750 && mouse.y > 100 && mouse.x < 1200 && mouse.y < 358) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            scene->scenes = 1;
        }
    }
    if (mouse.x > 750 && mouse.y > 500 && mouse.x < 1200 && mouse.y < 758) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            window_destroy(window);
            main_menu_destroy(menu);
            sfRenderWindow_close(window);
        }
    }
}

void handle_global_events(win_t *window)
{
    sfEvent event;
    
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
