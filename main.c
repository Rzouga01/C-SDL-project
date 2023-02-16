#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main()
{
    SDL_Surface *screen;
    image IMAGE, IMAGE_BTN1, IMAGE_BTN2, IMAGE_BTN1_var, IMAGE_BTN2_var, IMAGE_MENU_ANIMATION, IMAGE_SETTINGS, IMAGE_SETTINGS_MENU, IMAGE_BACKGROUND_LEVEL_1;
    image SETTINGS_BACK, SETTINGS_PLUS_SETTINGS_MINUS, SETTINGS_AUDIO_BAR, SETTINGS_AUDIO_BALL, SETTINGS_AUDIO_ICON, SETTINGS_AUDIO_MUTE;
    Mix_Music *music;
    Mix_Chunk *mus;
    texte txte;
    SDL_Event event;

    int boucle = 1, tab_active = 0, num_buttons = 2, active_button_index = 0, volume_steps = 5, volume_offset = 0, x_offset_animation = 0, level = 0, music_menu_bg_play = 0, music_level_1_background_play = 0, music_settings_menu_play = 0, settings_menu_show = 0, background_music_volume = 120, FULLSCREEN = 0;

    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not initialise SDL : %s .\n", SDL_GetError());
        return -1;
    }
    SDL_WM_SetCaption("Game", "Hello World");
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("%s\n", SDL_GetError());
    }
    else
    {

        initialiser_imageBACK(&IMAGE);
        initialiser_imageBOUTON1(&IMAGE_BTN1);
        initialiser_texte(&txte);
        initialiser_imageBOUTON1_variation(&IMAGE_BTN1_var);
        initialiser_imageBOUTON2(&IMAGE_BTN2);
        initialiser_imageBOUTON2_variation(&IMAGE_BTN2_var);
        initialiser_animation_menu(&IMAGE_MENU_ANIMATION);
        initialiser_image_settings(&IMAGE_SETTINGS);
        initialiser_settings_menu(&IMAGE_SETTINGS_MENU);
        initialiser_image_bg_level_1(&IMAGE_BACKGROUND_LEVEL_1);
        initialiser_image_settings_backward(&SETTINGS_BACK);
        initialiser_image_settings_audio_bar(&SETTINGS_AUDIO_BAR);
        initialiser_image_settings_audio_ball(&SETTINGS_AUDIO_BALL);
        initialiser_image_audio_menu(&SETTINGS_AUDIO_ICON);
        initialiser_image_audio_menu_mute(&SETTINGS_AUDIO_MUTE);

        while (boucle)
        {

            switch (level)
            {
            case -1: // SETTINGS
                while (SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                    case SDL_QUIT:
                        boucle = 0;
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_f && (event.key.keysym.mod & KMOD_LCTRL))
                        {
                            if (FULLSCREEN == 0)
                            {
                                FULLSCREEN = !FULLSCREEN;
                                screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                            }
                            else
                            {
                                screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                FULLSCREEN = !FULLSCREEN;
                            }
                        }
                        if (background_music_volume <= 120 && background_music_volume >= 0)
                        {
                            if (event.key.keysym.sym == SDLK_KP_PLUS)
                            {
                                if (volume_steps < 5)
                                {
                                    background_music_volume += 20;
                                    volume_steps++;
                                    volume_offset += 50;
                                }
                            }
                            if (event.key.keysym.sym == SDLK_KP_MINUS)
                            {
                                if (volume_steps >= 0)
                                {
                                    background_music_volume -= 20;
                                    volume_steps--;
                                    volume_offset -= 50;
                                }
                            }
                            Mix_VolumeMusic(background_music_volume);
                        }

                        if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            level = 0;
                            music_settings_menu_play = 0;
                            Mix_HaltMusic();
                        }

                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= 143 && event.motion.y >= 50 && (event.motion.x <= 150 && event.motion.x > 50))) // BACKWARD MENU
                        {
                            initialiser_audiobref(mus);
                            level = 0;
                            music_settings_menu_play = 0;
                            Mix_HaltMusic();
                        }
                    }
                    break;
                }

                if (music_settings_menu_play == 0)
                {
                    initialiser_audio_menu_settings(music, &background_music_volume);
                    music_settings_menu_play = 1;
                }

                afficher_imageBMP(screen, IMAGE);
                afficher_image_animation(screen, IMAGE_MENU_ANIMATION, &x_offset_animation);
                afficher_image_settings_menu(screen, IMAGE_SETTINGS_MENU);
                afficher_image(screen, SETTINGS_BACK);
                afficher_image(screen, SETTINGS_AUDIO_BAR);
                if (background_music_volume > 0)
                {
                    afficher_image(screen, SETTINGS_AUDIO_ICON);
                }
                else
                {
                    afficher_image(screen, SETTINGS_AUDIO_MUTE);
                }
                afficher_image_setting_audio_ball(screen, SETTINGS_AUDIO_BALL, &volume_offset);
                break;
            case 0: // MAIN MENU
                music_level_1_background_play = 0;
                music_settings_menu_play = 0;
                if (music_menu_bg_play == 0)
                {
                    initialiser_audio(music, &background_music_volume);
                    music_menu_bg_play = 1;
                }

                afficher_imageBMP(screen, IMAGE);
                afficher_imageBTN1(screen, IMAGE_BTN1);
                afficher_imageBTN2(screen, IMAGE_BTN2);
                afficher_texte(screen, txte);
                afficher_image_settings(screen, IMAGE_SETTINGS);
                afficher_image_animation(screen, IMAGE_MENU_ANIMATION, &x_offset_animation);

                while (SDL_PollEvent(&event))
                {

                    switch (event.type)
                    {
                    case SDL_QUIT:
                        boucle = 0;
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_TAB)
                        {

                            tab_active = !tab_active;
                        }
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            boucle = 0;
                        }
                        if (tab_active == 1)
                        {
                            if (event.key.keysym.sym == SDLK_UP)
                            {
                                active_button_index--;
                            }
                            if (event.key.keysym.sym == SDLK_DOWN)
                            {
                                active_button_index++;
                            }
                            if (event.key.keysym.sym == SDLK_RETURN)
                            {
                                if (active_button_index == 0)
                                {
                                    level = 1;
                                }
                                else
                                {
                                    boucle = 0;
                                }
                            }
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= 785 && event.motion.y >= 600 && (event.motion.x <= 545 && event.motion.x > 50))) // BUTTON QUIT
                        {
                            boucle = 0;
                        }
                        if (event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= 860 && event.motion.y >= 760) && (event.motion.x <= 1900 && event.motion.x > 1800)) // SETTINGS
                        {
                            initialiser_audiobref(mus);
                            level = -1;
                            music_menu_bg_play = 0;
                            Mix_HaltMusic();
                        }
                        if (event.button.button == SDL_BUTTON_LEFT && (event.motion.y <= 585 && event.motion.y >= 400 && event.motion.x <= 545 && event.motion.x > 50)) // BUTTON PlAY
                        {
                            level = 1;
                            music_menu_bg_play = 0;
                            Mix_HaltMusic();
                        }

                        break;

                    case SDL_MOUSEMOTION:
                        if (event.motion.y <= 585 && event.motion.y >= 400 && event.motion.x <= 545 && event.motion.x > 50) // BUTTON VARIATION 1
                        {
                            afficher_imageBTN1_variation(screen, IMAGE_BTN1_var);
                        }
                        if (event.motion.y <= 785 && event.motion.y >= 600 && (event.motion.x <= 545 && event.motion.x > 50)) // BUTTON VARIATION 2
                        {
                            afficher_imageBTN2_variation(screen, IMAGE_BTN2_var);
                        }
                        if ((event.motion.y <= 785 && event.motion.y >= 600 && (event.motion.x <= 545 && event.motion.x > 50)) || (event.motion.y <= 585 && event.motion.y >= 400 && event.motion.x <= 545 && event.motion.x > 50))
                        {
                            initialiser_audiobref(mus);
                        }
                        break;
                    }
                }
                if (tab_active == 1)
                {
                    active_button_index = (active_button_index + num_buttons) % num_buttons;
                    if (active_button_index == 0)
                    {
                        afficher_imageBTN1_variation(screen, IMAGE_BTN1_var);
                    }
                    else
                    {
                        afficher_imageBTN2_variation(screen, IMAGE_BTN2_var);
                    }
                }
                break;
            case 1:
                while (SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                    case SDL_QUIT:
                        boucle = 0;
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            level = 0;
                            music_level_1_background_play = 0;
                            Mix_HaltMusic();
                        }

                        break;
                    }
                }

                if (music_level_1_background_play == 0)
                {
                    initialiser_audio_background_level_1(music, &background_music_volume);
                    music_level_1_background_play = 1;
                }
                afficher_image_bg_level_1(screen, IMAGE_BACKGROUND_LEVEL_1);
                break;
            }
            SDL_Flip(screen);
        }

        liberer_image(IMAGE);
        liberer_image(IMAGE_BTN1);
        liberer_image(IMAGE_BTN2);
        liberer_image(IMAGE_BTN1_var);
        liberer_image(IMAGE_BTN2_var);
        liberer_image(IMAGE_MENU_ANIMATION);
        liberer_image(IMAGE_SETTINGS);
        liberer_image(IMAGE_SETTINGS_MENU);
        liberer_image(IMAGE_BACKGROUND_LEVEL_1);
        liberer_image(SETTINGS_BACK);
        liberer_image(SETTINGS_AUDIO_BAR);
        liberer_image(SETTINGS_AUDIO_BALL);
        liberer_image(SETTINGS_AUDIO_ICON);
        liberer_image(SETTINGS_AUDIO_MUTE);

        liberer_musique(music);
        liberer_musiquebref(mus);
        liberer_texte(txte);

        SDL_Quit();
    }
    return 0;
}