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
    #define YOUR_POKEMON_PATH "assets/spritesheet/grenouss.png"
    #define OPPONENT_POKEMON_PATH "assets/spritesheet/grass_types.png"

typedef struct img_s{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scl;
    sfVector2f pos;
} img_t;

typedef struct game_s {
    img_t background;
    img_t your_pokemon;
    img_t pokemon_opponent;
} game_t;

game_t *img_create(char *path);
void img_update(game_t *game, sfRenderWindow *window);
void img_destroy(game_t *game);

#endif /* !GRUSH_SPRITE_H_ */
