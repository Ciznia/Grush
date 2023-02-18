/*
** EPITECH PROJECT, 2023
** Handle sprite
** File description:
** Destroy/Update/Create Sprite
*/

#include "grush/sprite.h"

game_t *img_create(char *path)
{
    game_t *game = malloc(sizeof (game_t));

    game->background.texture = sfTexture_createFromFile(path, NULL);
    game->background.sprite = sfSprite_create();
    game->background.scl = (sfVector2f) {2, 2};
    game->your_pokemon.texture = sfTexture_createFromFile(YOUR_POKEMON_PATH, NULL);
    game->your_pokemon.sprite = sfSprite_create();
    game->your_pokemon.pos = (sfVector2f) {500, 400};
    game->your_pokemon.scl = (sfVector2f) {2, 2};
    game->pokemon_opponent.texture = sfTexture_createFromFile(OPPONENT_POKEMON_PATH, NULL);
    game->pokemon_opponent.sprite = sfSprite_create();
    game->pokemon_opponent.scl = (sfVector2f) {2, 2};
    game->pokemon_opponent.pos = (sfVector2f) {1000, 100};
    sfSprite_setTexture(game->background.sprite, game->background.texture, sfFalse);
    sfSprite_setScale(game->background.sprite, game->background.scl);
    sfSprite_setTexture(game->your_pokemon.sprite, game->your_pokemon.texture, sfFalse);
    sfSprite_setPosition(game->your_pokemon.sprite, game->your_pokemon.pos);
    sfSprite_setScale(game->your_pokemon.sprite, game->your_pokemon.scl);
    sfSprite_setTexture(game->pokemon_opponent.sprite, game->pokemon_opponent.texture, sfFalse);
    sfSprite_setPosition(game->pokemon_opponent.sprite, game->pokemon_opponent.pos);
    sfSprite_setScale(game->pokemon_opponent.sprite, game->pokemon_opponent.scl);

    return game;
}

void img_update(game_t *game, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, game->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->your_pokemon.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->pokemon_opponent.sprite, NULL);

}

void img_destroy(game_t *game)
{
    sfTexture_destroy(game->background.texture);
    sfSprite_destroy(game->background.sprite);
    sfTexture_destroy(game->your_pokemon.texture);
    sfSprite_destroy(game->your_pokemon.sprite);
    sfTexture_destroy(game->pokemon_opponent.texture);
    sfSprite_destroy(game->pokemon_opponent.sprite);    
}
