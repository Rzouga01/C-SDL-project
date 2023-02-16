#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 885
#define SCREEN_W 1920

typedef struct
{
    char *url;
    SDL_Rect pos_img_affiche;
    SDL_Rect pos_img_ecran;
    SDL_Surface *img;
} image;

typedef struct
{
    SDL_Surface *txt;
    SDL_Rect pos_txt;
    SDL_Colour color_txt;
    TTF_Font *police;
} texte;

void initialiser_imageBACK(image *imge);
void initialiser_imageBOUTON1(image *imgbtn);
void initialiser_imageBOUTON1_variation(image *imgbtn);
void initialiser_imageBOUTON2(image *img_btn2);
void initialiser_imageBOUTON2_variation(image *imgbtn);
void initialiser_image_settings(image *imgebtn);
void initialiser_settings_menu(image *imgebtn);
void initialiser_image_bg_level_1(image *imge);
void initialiser_image_audio_menu(image *imgebtn2);
void initialiser_image_settings_backward(image *imgebtn);
void initialiser_image_settings_audio_bar(image *imge);
void initialiser_image_settings_audio_ball(image *imge);
void initialiser_image_audio_menu_mute(image *imge);

void initialiser_animation_menu(image *imgebtn2);
void afficher_image_animation(SDL_Surface *screen, image imge, int *x);

void afficher_imageBMP(SDL_Surface *screen, image imge);
void afficher_imageBTN1(SDL_Surface *screen, image imge);
void afficher_imageBTN1_variation(SDL_Surface *screen, image imge);
void afficher_imageBTN2(SDL_Surface *screen, image imge);
void afficher_imageBTN2_variation(SDL_Surface *screen, image imge);
void afficher_image_settings(SDL_Surface *screen, image imge);
void afficher_image_bg_level_1(SDL_Surface *screen, image imge);
void afficher_image_settings_menu(SDL_Surface *screen, image imge);

void afficher_image_setting_audio_ball(SDL_Surface *screen, image imge,int *volume_offset);

void afficher_image_settings_backward (SDL_Surface *screen, image imge);

void afficher_image(SDL_Surface *screen, image imge);


void set_button_active_state(image *button, int active);


void liberer_image(image imge);

void initialiser_audio(Mix_Music *music, int *volume);
void liberer_musique(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);

void initialiser_audio_background_level_1(Mix_Music *music, int *volume);
void initialiser_audio_menu_settings(Mix_Music *music, int *volume);

void initialiser_texte(texte *txte);
void initialiser_texte_settings_menu(texte *txte);

void afficher_texte(SDL_Surface *screen, texte txte);
void afficher_texte_settings_menu(SDL_Surface *screen, texte txte);
void liberer_texte(texte txte);
#endif