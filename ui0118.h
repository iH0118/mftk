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
    UI0118_WIDGET_CONTAINER,
    UI0118_WIDGET_TOGGLE,
    UI0118_WIDGET_TOGGLE_MOM,
    UI0118_WIDGET_LED_RED,
    UI0118_WIDGET_LED_AMBER,
    UI0118_WIDGET_ROTARY,
    UI0118_WIDGET_TEXT,
    //UI0118_WIDGET_TEXT_INPUT
} ui0118_widget_type;

struct ui0118_widget_data_container
{
    ui0118_widget *child_top;
    ui0118_widget *child_bottom;
    unsigned int padding;
    SDL_Color color_bg;
};

struct ui0118_widget_data_toggle
{
    void (*trigger_up)(void *data);
    void (*trigger_down)(void *data);
    char state;
};

struct ui0118_widget_data_toggle_mom
{
    void (*trigger_up)(void *data);
    void (*trigger_down)(void *data);
    char state;
    char orientation;
};

struct ui0118_widget_data_led
{
    char state;
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
    char flags;
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
    int offset_x;
    int offset_y;
    int redraw_priority;
};

struct ui0118_window
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    ui0118_widget *widget_top;
    ui0118_widget *widget_bottom;
};
 
ui0118_window *ui0118_create_window(
    const char *title, unsigned int size_x, unsigned int size_y
);

int ui0118_redraw_window(ui0118_window *window, int priority);

void ui0118_insert_widget(ui0118_widget *widget, ui0118_widget *prev);

ui0118_widget *ui0118_create_widget_container(
    unsigned int padding, SDL_Color color_bg
);

ui0118_widget *ui0118_create_widget_array(ui0118_widget *child);

#endif
