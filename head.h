#ifndef HEAD_H
#define HEAD_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#define SCREEN_H 720
#define SCREEN_W 1280

typedef struct
{
    char *url;
    SDL_Rect displayed_img_pos;
    SDL_Rect screen_img_pos;
    SDL_Surface *img;
} image;

typedef struct
{
    SDL_Surface *txt;
    SDL_Rect txt_pos;
    SDL_Colour color_txt;
    TTF_Font *font;
} text;
typedef struct {
    int x, y;
    int w, h;
    int opacity;
} Light;

void init_BGimg(image *img);
void init_OptionsBGimg(image *img);
void init_BTN1img(image *imgbtn);
void init_SelectedBTN1(image *selected_btn);
void init_BTN2img(image *img_btn2);
void init_SelectedBTN2(image *selected_btn2);
void init_BTN3img(image *img_btn3);
void init_SelectedBTN3(image *selected_btn3);


void display_BGimg(SDL_Surface *screen, image img);
void display_img(SDL_Surface *screen, image img);
void lib_image(image img);

void init_menuMusic(Mix_Music **M_music);
void init_lvl1Music(Mix_Music **lvl1_music);
void init_audioeffect(Mix_Chunk *mus);

void init_text(text *txt);
void display_text(SDL_Surface *screen, text txt);

void initLight(Light *light, int x, int y, int w, int h);
void drawLight(SDL_Surface *screen, Light *light);
void animateLight(SDL_Surface *screen, Light *light);
#endif
