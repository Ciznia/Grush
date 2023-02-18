/*
** EPITECH PROJECT, 2023
** csfml.h
** File description:
** By Arthur M-D
*/

#ifndef GRUSH_START_MENU_H_
    #define GRUSH_START_MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include "window.h"

    #define BTN_SCALE (0.2F)

    #define BTN_START_X (750)
    #define BTN_START_Y (100)
    #define BTN_START_PATH "assets/spritesheet/red_button_start.png"

    #define BTN_QUIT_X (BTN_START_X)
    #define BTN_QUIT_Y (500)
    #define BTN_QUIT_PATH "assets/spritesheet/red_button_quit.png"

    #define BACKGROUND_POS (0)
    #define BACKGROUND_SCALE (4)
    #define BACKGROUND_FILE_PATH "assets/spritesheet/background.png"

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

typedef sfVector2f vec2f_t;

void main_menu_init(menu_t *menu);
void main_menu_update(win_t *window, menu_t *menu);
void main_menu_destroy(menu_t *menu);
#endif /* !GRUSH_START_MENU_H_ */
