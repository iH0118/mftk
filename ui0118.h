#ifndef INCLUDE_UI0118_H
#define INCLUDE_UI0118_H

//#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#define UI0118_UNIT 11

typedef struct ui0118_window ui0118_window;
typedef struct ui0118_widget ui0118_widget;
typedef union ui0118_widget_data ui0118_widget_data;
typedef struct ui0118_widget_data_container ui0118_widget_data_container;
typedef struct ui0118_widget_data_array ui0118_widget_data_array;
typedef struct ui0118_widget_data_toggle ui0118_widget_data_toggle;
typedef struct ui0118_widget_data_toggle_mom ui0118_widget_data_toggle_mom;
typedef struct ui0118_widget_data_led ui0118_widget_data_led;
typedef struct ui0118_widget_data_rotary ui0118_widget_data_rotary;
typedef struct ui0118_widget_data_text ui0118_widget_data_text;

enum ui0118_widget_type
{
    UI0118_WIDGET_CONTAINER,
    UI0118_WIDGET_ARRAY,
    UI0118_WIDGET_TOGGLE,
    UI0118_WIDGET_TOGGLE_MOM,
    UI0118_WIDGET_LED_RED,
    UI0118_WIDGET_LED_AMBER,
    UI0118_WIDGET_ROTARY,
    UI0118_WIDGET_TEXT
};

struct ui0118_widget_data_container
{
    struct ui0118_widget *child;
    unsigned int padding;
    SDL_Color color_bg;
};

struct ui0118_widget_data_array
{
    struct ui0118_widget **members;
    unsigned int count;
    int spacing_x;
    int spacing_y;
};

struct ui0118_widget_data_toggle
{
    void (*trigger_up(void *data));
    void (*trigger_down(void *data));
    char state;
};

struct ui0118_widget_data_toggle_mom
{
    void (*trigger_up(void *data));
    void (*trigger_down(void *data));
    char state;
    char orientation;
};

struct ui0118_widget_data_led
{
    char state;
};

struct ui0118_widget_data_rotary
{
    void (*trigger_up(void *data));
    void (*trigger_down(void *data));
    char state;
};

struct ui0118_widget_data_text
{
    char* text;
    unsigned int width;
    char flags;
};

union ui0118_widget_data
{
    struct ui0118_widget_data_container container;
    struct ui0118_widget_data_array array;
    struct ui0118_widget_data_toggle toggle;
    struct ui0118_widget_data_toggle_mom toggle_mom;
    struct ui0118_widget_data_led led;
    struct ui0118_widget_data_rotary rotary;
    struct ui0118_widget_data_text text;
};

struct ui0118_widget
{
    struct ui0118_widget *prev;
    struct ui0118_widget *next;
    enum ui0118_widget_type type;
    union ui0118_widget_data data;
    int offset_x;
    int offset_y;
};

struct ui0118_window
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    struct ui0118_widget *widget_top;
    char *title;
    unsigned int size_x;
    unsigned int size_y;
};

struct ui0118_window *ui0118_create_window(
    const char *title, unsigned int size_x, unsigned int size_y
);

#endif
