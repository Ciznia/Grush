/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** Grush Window Header
*/
#ifndef GRUSH_WINDOW_H_
    #define GRUSH_WINDOW_H_

    #include <SFML/Graphics/Types.h>

    #ifndef win_t
typedef sfRenderWindow win_t;
    #endif

win_t *window_create(void);
void window_destroy(win_t *window);
#endif /* !GRUSH_WINDOW_H_ */
