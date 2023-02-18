/*
** EPITECH PROJECT, 2023
** menu->c
** File description:
** By Arthur M-D
*/
#include "grush/start_menu.h"

void main_menu_init(menu_t *menu)
{
    menu->back.txt = sfTexture_createFromFile(BACKGROUND_FILE_PATH, NULL);
    menu->back.spt = sfSprite_create();
    menu->back.scl = (vec2f_t){BACKGROUND_SCALE, BACKGROUND_SCALE};
    menu->back.pos = (vec2f_t){BACKGROUND_POS, BACKGROUND_POS};
    menu->button_start.txt = sfTexture_createFromFile(BTN_START_PATH, NULL);
    menu->button_start.spt = sfSprite_create();
    menu->button_start.scl = (vec2f_t){BTN_SCALE, BTN_SCALE};
    menu->button_start.pos = (vec2f_t){BTN_START_X, BTN_START_Y};
    menu->button_quit.txt = sfTexture_createFromFile(BTN_QUIT_PATH, NULL);
    menu->button_quit.spt = sfSprite_create();
    menu->button_quit.scl = (vec2f_t){BTN_SCALE, BTN_SCALE};
    menu->button_quit.pos = (vec2f_t){BTN_QUIT_X, BTN_QUIT_Y};
    sfSprite_setTexture(menu->back.spt, menu->back.txt, sfTrue);
    sfSprite_setScale(menu->back.spt, menu->back.scl);
    sfSprite_setPosition(menu->back.spt, menu->back.pos);
    sfSprite_setTexture(menu->button_start.spt, menu->button_start.txt, sfTrue);
    sfSprite_setScale(menu->button_start.spt, menu->button_start.scl);
    sfSprite_setPosition(menu->button_start.spt, menu->button_start.pos);
    sfSprite_setTexture(menu->button_quit.spt, menu->button_quit.txt, sfTrue);
    sfSprite_setScale(menu->button_quit.spt, menu->button_quit.scl);
    sfSprite_setPosition(menu->button_quit.spt, menu->button_quit.pos);
}

void main_menu_update(win_t *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->back.spt, NULL);
    sfRenderWindow_drawSprite(window, menu->button_start.spt, NULL);
    sfRenderWindow_drawSprite(window, menu->button_quit.spt, NULL);
}

void main_menu_destroy(menu_t *menu)
{
    sfSprite_destroy(menu->back.spt);
    sfSprite_destroy(menu->button_start.spt);
    sfSprite_destroy(menu->button_quit.spt);
}
