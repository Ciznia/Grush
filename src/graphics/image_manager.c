/*
** EPITECH PROJECT, 2023
** Handle sprite
** File description:
** Destroy/Update/Create Sprite
*/

#include "grush/sprite.h"

img_t *img_create(char *path)
{
    img_t *img = malloc(sizeof (img_t));

    img->texture = sfTexture_createFromFile(path, NULL);
    img->sprite = sfSprite_create();
    img->scl = (sfVector2f) {2, 2};
    sfSprite_setTexture(img->sprite, img->texture, sfFalse);
    sfSprite_setScale(img->sprite, img->scl);
    return img;
}

void img_update(img_t *img, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, img->sprite, NULL);
}

void img_destroy(img_t *img)
{
    sfTexture_destroy(img->texture);
    sfSprite_destroy(img->sprite);
}
