/*
** EPITECH PROJECT, 2023
** sprite.h
** File description:
** sprite.h
*/

#ifndef GRUSH_SPRITE_H_
    #define GRUSH_SPRITE_H_

    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

    #define PATH_TO_WALLPAPER "assets/spritesheet/battle_background.png"

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scl;
} img_t;

img_t *img_create(char *path);
void img_update(img_t *img, sfRenderWindow *window);
void img_destroy(img_t *img);

#endif /* !GRUSH_SPRITE_H_ */
