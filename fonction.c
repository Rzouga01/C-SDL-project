#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#include <math.h>

void initialiser_imageBACK(image *imge)
{
    imge->url = "images/bg.jpeg";
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = 0;
    imge->pos_img_ecran.y = 0;
    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = SCREEN_H;
    imge->pos_img_affiche.w = SCREEN_W;
}

void initialiser_image_bg_level_1(image *imge)
{
    imge->url = "images/level_1_bg.jpg";
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = 0;
    imge->pos_img_ecran.y = 0;
    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = SCREEN_H;
    imge->pos_img_affiche.w = SCREEN_W;
}

void initialiser_image_settings_audio_bar(image *imge)
{

    imge->url = "images/Settings/bar2.png";
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_affiche.h = 0;
    imge->pos_img_affiche.w = 0;
    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_ecran.x = 800;
    imge->pos_img_ecran.y = 500;
}


void initialiser_image_audio_menu_mute(image *imge)
{
    imge->url = "images/Settings/audio_mute.png";
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = 0;
    imge->pos_img_affiche.w = 0;
    imge->pos_img_ecran.x = 850;
    imge->pos_img_ecran.y = 275;
}


void initialiser_image_settings_audio_ball(image *imge)
{

    imge->url = "images/Settings/ball2.png";
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_affiche.h = 0;
    imge->pos_img_affiche.w = 0;
    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_ecran.x = 1100;
    imge->pos_img_ecran.y = 500;
}

void initialiser_image_settings_backward(image *imgebtn)
{

    imgebtn->url = "images/Settings/back2.png";
    imgebtn->img = IMG_Load(imgebtn->url);
    if (imgebtn->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn->pos_img_affiche.x = 0;
    imgebtn->pos_img_affiche.y = 0;
    imgebtn->pos_img_affiche.h = 0;
    imgebtn->pos_img_affiche.w = 0;
    imgebtn->pos_img_ecran.x = 50;
    imgebtn->pos_img_ecran.y = 50;
}

void initialiser_image_settings(image *imgebtn)
{

    imgebtn->url = "images/settings_cog_menu2.png";
    imgebtn->img = IMG_Load(imgebtn->url);
    if (imgebtn->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn->pos_img_affiche.x = 0;
    imgebtn->pos_img_affiche.y = 0;
    imgebtn->pos_img_affiche.h = 0;
    imgebtn->pos_img_affiche.w = 0;
    imgebtn->pos_img_ecran.x = 1800;
    imgebtn->pos_img_ecran.y = 760;
}

void initialiser_imageBOUTON1(image *imgebtn)
{

    imgebtn->url = "images/play.png";
    imgebtn->img = IMG_Load(imgebtn->url);
    if (imgebtn->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn->pos_img_affiche.x = 0;
    imgebtn->pos_img_affiche.y = 0;
    imgebtn->pos_img_affiche.h = 0;
    imgebtn->pos_img_affiche.w = 0;
    imgebtn->pos_img_ecran.x = 50;
    imgebtn->pos_img_ecran.y = 400;
}
void initialiser_imageBOUTON1_variation(image *imgebtn)
{

    imgebtn->url = "images/play_variation_clicked.png";
    imgebtn->img = IMG_Load(imgebtn->url);
    if (imgebtn->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn->pos_img_affiche.x = 0;
    imgebtn->pos_img_affiche.y = 0;
    imgebtn->pos_img_affiche.h = 0;
    imgebtn->pos_img_affiche.w = 0;
    imgebtn->pos_img_ecran.x = 50;
    imgebtn->pos_img_ecran.y = 400;
}
void initialiser_imageBOUTON2(image *imgebtn2)
{
    imgebtn2->url = "images/quit.png";
    imgebtn2->img = IMG_Load(imgebtn2->url);
    if (imgebtn2->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn2->pos_img_affiche.x = 0;
    imgebtn2->pos_img_affiche.y = 0;
    imgebtn2->pos_img_affiche.h = 0;
    imgebtn2->pos_img_affiche.w = 0;
    imgebtn2->pos_img_ecran.x = 50;
    imgebtn2->pos_img_ecran.y = 600;
}
void initialiser_imageBOUTON2_variation(image *imgebtn2)
{
    imgebtn2->url = "images/quit_variation_clicked.png";
    imgebtn2->img = IMG_Load(imgebtn2->url);
    if (imgebtn2->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn2->pos_img_affiche.x = 0;
    imgebtn2->pos_img_affiche.y = 0;
    imgebtn2->pos_img_affiche.h = 0;
    imgebtn2->pos_img_affiche.w = 0;
    imgebtn2->pos_img_ecran.x = 50;
    imgebtn2->pos_img_ecran.y = 600;
}

void initialiser_settings_menu(image *imgebtn2)
{
    imgebtn2->url = "images/Settings_menu.png";
    imgebtn2->img = IMG_Load(imgebtn2->url);
    if (imgebtn2->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn2->pos_img_affiche.x = 0;
    imgebtn2->pos_img_affiche.y = 0;
    imgebtn2->pos_img_affiche.h = 0;
    imgebtn2->pos_img_affiche.w = 0;
    imgebtn2->pos_img_ecran.x = 600;
    imgebtn2->pos_img_ecran.y = 100;
}
void initialiser_image_audio_menu(image *imgebtn2)

{
    imgebtn2->url = "images/Settings/audio.png";
    imgebtn2->img = IMG_Load(imgebtn2->url);
    if (imgebtn2->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn2->pos_img_affiche.x = 0;
    imgebtn2->pos_img_affiche.y = 0;
    imgebtn2->pos_img_affiche.h = 0;
    imgebtn2->pos_img_affiche.w = 0;
    imgebtn2->pos_img_ecran.x = 850;
    imgebtn2->pos_img_ecran.y = 275;
}
void initialiser_animation_menu(image *imgebtn2)
{
    imgebtn2->url = "images/flat_750x1000_075_f-removebg-preview(2).png";
    imgebtn2->img = IMG_Load(imgebtn2->url);
    if (imgebtn2->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }

    imgebtn2->pos_img_affiche.x = 0;
    imgebtn2->pos_img_affiche.y = 0;
    imgebtn2->pos_img_affiche.h = 0;
    imgebtn2->pos_img_affiche.w = 0;
    imgebtn2->pos_img_ecran.x = SCREEN_W;
    imgebtn2->pos_img_ecran.y = 40;
}

void afficher_image_animation(SDL_Surface *screen, image imge, int *x)
{
    (*x) += 1;
    imge.pos_img_ecran.x = SCREEN_W - ((*x) % SCREEN_W * 1.1);
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_image_setting_audio_ball(SDL_Surface *screen, image imge, int *volume_offset)
{
    imge.pos_img_ecran.x += (*volume_offset);
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_image_settings_menu(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_image_settings(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_image_settings_backward(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_imageBMP(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_image_bg_level_1(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_image(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_imageBTN1(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void afficher_imageBTN1_variation(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void afficher_imageBTN2(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void afficher_imageBTN2_variation(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}
void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}

void initialiser_audio(Mix_Music *music, int *volume)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadMUS("music/Dragon Ball Z Opening 8 bit.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic((*volume));
}

void initialiser_audio_background_level_1(Mix_Music *music, int *volume)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadMUS("music/Silver_Surfer_Level_1_Nes_Music.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic((*volume));
}

void initialiser_audio_menu_settings(Mix_Music *music, int *volume)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", SDL_GetError());
    }
    music = Mix_LoadMUS("music/Kirby_Return_to_Dream_Land_Title_Theme_8 Bit.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic((*volume));
}

void liberer_musique(Mix_Music *music)
{
    Mix_FreeMusic(music);
}

void initialiser_audiobref(Mix_Chunk *music)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    music = Mix_LoadWAV("music/menu_click_sound_hover.wav");
    Mix_PlayChannel(-1, music, 0);
    if (music == NULL)
    {
        printf("%s\n", SDL_GetError());
    }
}
void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}

void initialiser_texte(texte *txte)
{
    TTF_Init();
    txte->police = TTF_OpenFont("fonts/8-bit-hud.ttf", 45);
    txte->color_txt.r = 231;
    txte->color_txt.g = 106;
    txte->color_txt.b = 36;

    txte->pos_txt.x = SCREEN_W / 2;
    txte->pos_txt.y = 0;
}

void initialiser_texte_settings_menu(texte *txte)
{
    TTF_Init();
    txte->police = TTF_OpenFont("fonts/8-bit-hud.ttf", 45);
    txte->color_txt.r = 231;
    txte->color_txt.g = 106;
    txte->color_txt.b = 36;

    txte->pos_txt.x = SCREEN_W / 2;
    txte->pos_txt.y = 0;
}

void afficher_texte(SDL_Surface *screen, texte txte)
{
    txte.txt = TTF_RenderText_Blended(txte.police, "Game_Test", txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
}

void afficher_texte_settings_menu(SDL_Surface *screen, texte txte)
{
    txte.txt = TTF_RenderText_Blended(txte.police, "Settings", txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
}

void liberer_texte(texte txte)
{
    TTF_CloseFont(txte.police);
    TTF_Quit();
}