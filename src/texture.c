#include "texture.h"

#include "../res/textures_container.c"
#include "../res/textures_led.c"
#include "../res/textures_rotary.c"
#include "../res/textures_text.c"
#include "../res/textures_toggle.c"

const unsigned char *rotary_dial_png[] = {
    rotary_0_png,
    rotary_1_png,
    rotary_2_png,
    rotary_3_png,
    rotary_4_png,
    rotary_5_png,
    rotary_6_png,
    rotary_7_png,
    rotary_8_png,
    rotary_9_png,
    rotary_A_png,
    rotary_B_png,
    rotary_C_png,
    rotary_D_png,
    rotary_E_png,
    rotary_F_png
};

const unsigned int rotary_dial_png_len[] = {
    rotary_0_png_len,
    rotary_1_png_len,
    rotary_2_png_len,
    rotary_3_png_len,
    rotary_4_png_len,
    rotary_5_png_len,
    rotary_6_png_len,
    rotary_7_png_len,
    rotary_8_png_len,
    rotary_9_png_len,
    rotary_A_png_len,
    rotary_B_png_len,
    rotary_C_png_len,
    rotary_D_png_len,
    rotary_E_png_len,
    rotary_F_png_len
};

const unsigned char *text_png[] = {
    text_20_png,
    text_21_png,
    text_22_png,
    text_23_png,
    text_24_png,
    text_25_png,
    text_26_png,
    text_27_png,
    text_28_png,
    text_29_png,
    text_2A_png,
    text_2B_png,
    text_2C_png,
    text_2D_png,
    text_2E_png,
    text_2F_png,
    text_30_png,
    text_31_png,
    text_32_png,
    text_33_png,
    text_34_png,
    text_35_png,
    text_36_png,
    text_37_png,
    text_38_png,
    text_39_png,
    text_3A_png,
    text_3B_png,
    text_3C_png,
    text_3D_png,
    text_3E_png,
    text_3F_png,
    text_40_png,
    text_41_png,
    text_42_png,
    text_43_png,
    text_44_png,
    text_45_png,
    text_46_png,
    text_47_png,
    text_48_png,
    text_49_png,
    text_4A_png,
    text_4B_png,
    text_4C_png,
    text_4D_png,
    text_4E_png,
    text_4F_png,
    text_50_png,
    text_51_png,
    text_52_png,
    text_53_png,
    text_54_png,
    text_55_png,
    text_56_png,
    text_57_png,
    text_58_png,
    text_59_png,
    text_5A_png,
    text_5B_png,
    text_5C_png,
    text_5D_png,
    text_5E_png,
    text_5F_png,
    text_60_png,
    text_61_png,
    text_62_png,
    text_63_png,
    text_64_png,
    text_65_png,
    text_66_png,
    text_67_png,
    text_68_png,
    text_69_png,
    text_6A_png,
    text_6B_png,
    text_6C_png,
    text_6D_png,
    text_6E_png,
    text_6F_png,
    text_70_png,
    text_71_png,
    text_72_png,
    text_73_png,
    text_74_png,
    text_75_png,
    text_76_png,
    text_77_png,
    text_78_png,
    text_79_png,
    text_7A_png,
    text_7B_png,
    text_7C_png,
    text_7D_png,
    text_7E_png
};

const unsigned int text_png_len[] = {
    text_20_png_len,
    text_21_png_len,
    text_22_png_len,
    text_23_png_len,
    text_24_png_len,
    text_25_png_len,
    text_26_png_len,
    text_27_png_len,
    text_28_png_len,
    text_29_png_len,
    text_2A_png_len,
    text_2B_png_len,
    text_2C_png_len,
    text_2D_png_len,
    text_2E_png_len,
    text_2F_png_len,
    text_30_png_len,
    text_31_png_len,
    text_32_png_len,
    text_33_png_len,
    text_34_png_len,
    text_35_png_len,
    text_36_png_len,
    text_37_png_len,
    text_38_png_len,
    text_39_png_len,
    text_3A_png_len,
    text_3B_png_len,
    text_3C_png_len,
    text_3D_png_len,
    text_3E_png_len,
    text_3F_png_len,
    text_40_png_len,
    text_41_png_len,
    text_42_png_len,
    text_43_png_len,
    text_44_png_len,
    text_45_png_len,
    text_46_png_len,
    text_47_png_len,
    text_48_png_len,
    text_49_png_len,
    text_4A_png_len,
    text_4B_png_len,
    text_4C_png_len,
    text_4D_png_len,
    text_4E_png_len,
    text_4F_png_len,
    text_50_png_len,
    text_51_png_len,
    text_52_png_len,
    text_53_png_len,
    text_54_png_len,
    text_55_png_len,
    text_56_png_len,
    text_57_png_len,
    text_58_png_len,
    text_59_png_len,
    text_5A_png_len,
    text_5B_png_len,
    text_5C_png_len,
    text_5D_png_len,
    text_5E_png_len,
    text_5F_png_len,
    text_60_png_len,
    text_61_png_len,
    text_62_png_len,
    text_63_png_len,
    text_64_png_len,
    text_65_png_len,
    text_66_png_len,
    text_67_png_len,
    text_68_png_len,
    text_69_png_len,
    text_6A_png_len,
    text_6B_png_len,
    text_6C_png_len,
    text_6D_png_len,
    text_6E_png_len,
    text_6F_png_len,
    text_70_png_len,
    text_71_png_len,
    text_72_png_len,
    text_73_png_len,
    text_74_png_len,
    text_75_png_len,
    text_76_png_len,
    text_77_png_len,
    text_78_png_len,
    text_79_png_len,
    text_7A_png_len,
    text_7B_png_len,
    text_7C_png_len,
    text_7D_png_len,
    text_7E_png_len
};

static const char filetype[] = "PNG";

void mftk_init_textures(
    mftk_window *window
)
{
    window->texture_set.container.screw = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(screw_png, screw_png_len),
        1,
        filetype
    );

    window->texture_set.toggle.base = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(toggle_base_png, toggle_base_png_len),
        1,
        filetype
    );

    window->texture_set.toggle.up = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(toggle_up_png, toggle_up_png_len),
        1,
        filetype
    );

    window->texture_set.toggle.center = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(toggle_center_png, toggle_center_png_len),
        1, filetype
    );

    window->texture_set.toggle.down = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(toggle_down_png, toggle_down_png_len),
        1,
        filetype
    );

    window->texture_set.led_red.on = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_red_on_png, led_red_on_png_len),
        1,
        filetype
    );

    window->texture_set.led_red.off = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_red_off_png, led_red_off_png_len),
        1,
        filetype
    );

    window->texture_set.led_amber.on = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_amber_on_png, led_amber_on_png_len),
        1,
        filetype
    );

    window->texture_set.led_amber.off = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_amber_off_png, led_amber_off_png_len),
        1,
        filetype
    );

    window->texture_set.led_small_red.on = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_small_red_on_png, led_small_red_on_png_len),
        1,
        filetype
    );

    window->texture_set.led_small_red.off = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_small_red_off_png, led_small_red_off_png_len),
        1,
        filetype
    );

    window->texture_set.led_small_amber.on = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(led_small_amber_on_png, led_small_amber_on_png_len),
        1,
        filetype
    );

    window->texture_set.led_small_amber.off = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(
            led_small_amber_off_png, led_small_amber_off_png_len
        ),
        1,
        filetype
        );

    window->texture_set.rotary.base = IMG_LoadTextureTyped_IO(
        window->renderer,
        SDL_IOFromConstMem(rotary_base_png, rotary_base_png_len),
        1,
        filetype
    );

    for (int i = 0; i < 16; i++)
    {
        window->texture_set.rotary.dial[i] = IMG_LoadTextureTyped_IO(
            window->renderer,
            SDL_IOFromConstMem(rotary_dial_png[i], rotary_dial_png_len[i]),
            1,
            filetype
        );
    }

    for (int i = 0; i < 95; i++)
    {
        window->texture_set.letter[i] = IMG_LoadTextureTyped_IO(
            window->renderer,
            SDL_IOFromConstMem(text_png[i], text_png_len[i]),
            1,
            filetype
        );
    }
}

void blit(
    SDL_Renderer *renderer,
    SDL_Texture  *texture,
    int           x,
    int           y
)
{
    SDL_FRect dest;
    dest.x = x;
    dest.y = y;
    //SDL_PropertiesID props = SDL_GetTextureProperties(texture);
    //dest.w = SDL_GetNumberProperty(props, SDL_PROP_TEXTURE_WIDTH_NUMBER, 0);
    //dest.h = SDL_GetNumberProperty(props, SDL_PROP_TEXTURE_HEIGHT_NUMBER, 0);
    SDL_GetTextureSize(texture, &(dest.w), &(dest.h));
    SDL_RenderTexture(renderer, texture, NULL, &dest);
}
