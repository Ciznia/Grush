/*
** EPITECH PROJECT, 2023
** Grush
** File description:
** Window Management Internal Header
*/
#ifndef GRUSH_WINDOW_INTERNAL_H_
    #define GRUSH_WINDOW_INTERNAL_H_

    #define WINDOW_TITLE "Grush"

    #define WINDOW_WIDTH (1920)
    #define WINDOW_HEIGHT (1080)
    #define WINDOW_COLOR_MODE (32)
    
    #ifndef win_t
typedef sfRenderWindow win_t;
    #endif

#endif /* !GRUSH_WINDOW_INTERNAL_H_ */
