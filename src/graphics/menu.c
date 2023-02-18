/*
** EPITECH PROJECT, 2023
** menu->c
** File description:
** By Arthur M-D
*/
#include "grush/csfml.h"
#include "w_types.h"
#include "grush/window.h"

void main_menu_init(menu_t *menu)
{
    menu->back.txt = sfTexture_createFromFile("assets/spritesheet/background.png", NULL);
    menu->back.spt = sfSprite_create();
    menu->back.scl = (sfVector2f){4, 4};
    menu->back.pos = (sfVector2f){0, 0};
    menu->button_start.txt = sfTexture_createFromFile("assets/spritesheet/red_button.png", NULL);
    menu->button_start.spt = sfSprite_create();
    menu->button_start.scl = (sfVector2f){0.2, 0.2};
    menu->button_start.pos = (sfVector2f){800, 100};
    menu->button_quit.txt = sfTexture_createFromFile("assets/spritesheet/red_button.png", NULL);
    menu->button_quit.spt = sfSprite_create();
    menu->button_quit.scl = (sfVector2f){0.2, 0.2};
    menu->button_quit.pos = (sfVector2f){800, 500};


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