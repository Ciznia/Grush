/*
** EPITECH PROJECT, 2023
** Handle sprite
** File description:
** Destroy/Update/Create Sprite
*/

#include ".h"


// DESTROY

int img_destroy(img_t *img)
{
    sfTexture_destroy(img->texture);
    sfSprite_destroy(img->sprite);
    return (0);
}

// UPDATE

int img_update(img_t *img, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, img->sprite, NULL);
    return (0);
}

//CREATION

img_t img_create(char *path)
{
    img_t img;

    img.texture = sfTexture_createFromFile(path, NULL);
    img.sprite = sfSprite_create();
    sfSprite_setTexture(img.sprite, img.texture, sfFalse);
    return (img);
}