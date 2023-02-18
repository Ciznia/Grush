/*
** EPITECH PROJECT, 2023
** sprite.h
** File description:
** sprite.h
*/

#ifndef SPRITE_H__
#define SPRITE_H__

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h> 

typedef struct img_s {
    sfTexture *texture;
    sfSprite *sprite;
} img_t;

img_t img_create(char *path);
int img_update(img_t *img, sfRenderWindow *window);
int img_destroy(img_t *img);

#endif /* SPRITE_H__ */
