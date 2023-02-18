/*
** EPITECH PROJECT, 2023
** csfml.h
** File description:
** By Arhtur M-D
*/

#ifndef CSFML_H_
    #define CSFML_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include "window.h"

    typedef struct sprite_s {
        sfTexture *txt;
        sfSprite *spt;
        sfVector2f scl;
        sfVector2f pos;
    } sprite_t;

    typedef struct menu_s {
        sprite_t back;
        sprite_t button_start;
        sprite_t button_quit;
    } menu_t;

    typedef struct scene_s {
        int id;
    } scene_t;

    void main_menu_init(menu_t *menu);
    void main_menu_update(win_t *window, menu_t *menu);
    void click_event(win_t *window, scene_t *scene, menu_t *menu);
    void main_menu_destroy(menu_t *menu);
#endif /* CSFML_H_ */
