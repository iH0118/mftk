#ifndef INCLUDE_MFTK_TYPES_H
#define INCLUDE_MFTK_TYPES_H

#include <SDL2/SDL.h>

typedef struct mftk_window mftk_window;
typedef struct mftk_widget mftk_widget;
typedef union mftk_widget_data mftk_widget_data;
typedef struct mftk_widget_data_container mftk_widget_data_container;
typedef struct mftk_widget_data_toggle mftk_widget_data_toggle;
typedef struct mftk_widget_data_toggle_mom mftk_widget_data_toggle_mom;
typedef struct mftk_widget_data_led mftk_widget_data_led;
typedef struct mftk_widget_data_rotary mftk_widget_data_rotary;
typedef struct mftk_widget_data_text mftk_widget_data_text;
typedef struct mftk_widget_data_text_count mftk_widget_data_text_count;
typedef struct mftk_texture_set mftk_texture_set;
//typedef struct mftk_widget_data_text_input mftk_widget_data_text_input;

struct mftk_texture_set {
    struct {
        SDL_Texture *screw;
    } container;
    struct {
        SDL_Texture *base;
        SDL_Texture *up;
        SDL_Texture *center;
        SDL_Texture *down;
    } toggle;
    struct {
        SDL_Texture *on;
        SDL_Texture *off;
    } led_red;
    struct {
        SDL_Texture *on;
        SDL_Texture *off;
    } led_amber;
    struct {
        SDL_Texture *on;
        SDL_Texture *off;
    } led_small_red;
    struct {
        SDL_Texture *on;
        SDL_Texture *off;
    } led_small_amber;
    struct {
        SDL_Texture *base;
        SDL_Texture *dial[16];
    } rotary;
    SDL_Texture *letter[95];
};

typedef enum mftk_widget_type {
    MFTK_CONTAINER,
    MFTK_TOGGLE,
    MFTK_TOGGLE_MOM,
    MFTK_LED_RED,
    MFTK_LED_AMBER,
    MFTK_ROTARY,
    MFTK_TEXT,
    MFTK_TEXT_COUNT,
    //MFTK_WIDGET_TEXT_INPUT
} mftk_widget_type;

struct mftk_widget_data_container {
    unsigned int size_x;
    unsigned int size_y;
    SDL_Color    color;
};

struct mftk_widget_data_toggle {
    //void (**trigger_up)(void *data);
    //void (**trigger_down)(void *data);
    long state;
    long trans_state;
    int  count;
};

struct mftk_widget_data_toggle_mom {
    //void (**trigger_up)(void *data);
    //void (**trigger_down)(void *data);
    long state;
    long trans_state;
    long orientation;
    int  count;
};

struct mftk_widget_data_led {
    long state;
    int  count;
};

struct mftk_widget_data_rotary {
    //void (*trigger_up)(void *data);
    //void (*trigger_down)(void *data);
    char state;
};

struct mftk_widget_data_text {
    char         *text;
    unsigned int  width;
    char          line : 1;
};

struct mftk_widget_data_text_count {
    int          start;
    unsigned int count;
    int          step;
};

union mftk_widget_data {
    mftk_widget_data_container  container;
    mftk_widget_data_toggle     toggle;
    mftk_widget_data_toggle_mom toggle_mom;
    mftk_widget_data_led        led;
    mftk_widget_data_rotary     rotary;
    mftk_widget_data_text       text;
    mftk_widget_data_text_count text_count;
};

struct mftk_widget {
    mftk_widget      *prev;
    mftk_widget      *next;
    char             *label;
    mftk_widget_data  data;
    mftk_widget_type  type;
    int               x;
    int               y;
};

struct mftk_window {
    SDL_Window       *window;
    SDL_Renderer     *renderer;
    mftk_widget      *widget_top;
    mftk_texture_set  texture_set;
    SDL_Color         color_bg;
    unsigned int      trans_counter;
};

#endif
