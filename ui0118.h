#ifndef INCLUDE_UI0118_H
#define INCLUDE_UI0118_H

#include <SDL2/SDL.h>

#define UI0118_UNIT 11

typedef struct ui0118_window ui0118_window;
typedef struct ui0118_widget ui0118_widget;
typedef union ui0118_widget_data ui0118_widget_data;
typedef struct ui0118_widget_data_container ui0118_widget_data_container;
typedef struct ui0118_widget_data_toggle ui0118_widget_data_toggle;
typedef struct ui0118_widget_data_toggle_mom ui0118_widget_data_toggle_mom;
typedef struct ui0118_widget_data_led ui0118_widget_data_led;
typedef struct ui0118_widget_data_rotary ui0118_widget_data_rotary;
typedef struct ui0118_widget_data_text ui0118_widget_data_text;
//typedef struct ui0118_widget_data_text_input ui0118_widget_data_text_input;

typedef enum ui0118_widget_type
{
    UI0118_CONTAINER,
    UI0118_TOGGLE,
    UI0118_TOGGLE_MOM,
    UI0118_LED_RED,
    UI0118_LED_AMBER,
    UI0118_ROTARY,
    UI0118_TEXT,
    //UI0118_WIDGET_TEXT_INPUT
} ui0118_widget_type;

struct ui0118_widget_data_container
{
    unsigned int size_x;
    unsigned int size_y;
    SDL_Color color;
};

struct ui0118_widget_data_toggle
{
    void (**trigger_up)(void *data);
    void (**trigger_down)(void *data);
    long state;
    int count;
};

struct ui0118_widget_data_toggle_mom
{
    void (**trigger_up)(void *data);
    void (**trigger_down)(void *data);
    long state;
    long orientation;
    int count;
};

struct ui0118_widget_data_led
{
    long state;
    int count;
};

struct ui0118_widget_data_rotary
{
    void (*trigger_up)(void *data);
    void (*trigger_down)(void *data);
    char state;
};

struct ui0118_widget_data_text
{
    char *text;
    unsigned int width;
    char line;
};

union ui0118_widget_data
{
    ui0118_widget_data_container container;
    ui0118_widget_data_toggle toggle;
    ui0118_widget_data_toggle_mom toggle_mom;
    ui0118_widget_data_led led;
    ui0118_widget_data_rotary rotary;
    ui0118_widget_data_text text;
};

struct ui0118_widget
{
    ui0118_widget *prev;
    ui0118_widget *next;
    ui0118_widget_type type;
    ui0118_widget_data data;
    int x;
    int y;
    int layer;
};

struct ui0118_window
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    ui0118_widget *widget_top;
    //SDL_Color color;
};
 
ui0118_window *ui0118_create_window(
    const char *title, unsigned int size_x, unsigned int size_y
);

#endif
