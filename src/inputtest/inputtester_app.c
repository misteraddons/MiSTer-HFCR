/*============================================================================
    Input Test - Input test state handlers

    Author: Jim Gregory - https://github.com/JimmyStones/
    Version: 1.0
    Date: 2021-07-13

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.
===========================================================================*/

#include "../shared/sys.h"
#include "../shared/ui.h"
#include "../shared/ps2.h"
#include "../shared/sprite.h"
#include "fader.h"
#include "menu.h"
#include "sprite_images.h"
#include "inputtester_app.h"
#include "inputtester_sys.h"
#include "inputtester_ui.h"
#include "inputtester_pings.h"

// Input tester variables
unsigned char joystick_last[12];
signed char ax_l_last[6];
signed char ay_l_last[6];
signed char ax_r_last[6];
signed char ay_r_last[6];
unsigned char px_last[6];
signed char sx_toggle_last[6];
signed char sx_last[6];
unsigned long sx_pos[6];
unsigned char kbd_scan_last = 1;
unsigned char kbd_ascii_last = 1;
unsigned char mse_button1_last = 255;
unsigned char mse_button2_last = 255;
signed char mse_x_last = 1;
signed char mse_y_last = 1;
signed char mse_w_last = 1;
signed short mse_x_acc;
signed short mse_y_acc;
signed short mse_w_acc;

unsigned char socd_ud[6]; // Concurrent press of U and D detected
unsigned char socd_ud_last[6];
unsigned char socd_lr[6]; // Concurrent press of L and R detected
unsigned char socd_lr_last[6];

#define MOUSE_POINTER_SPRITE 9


// Mode switcher variables
char modeswitchtimer_select = 0;
char modeswitchtimer_start = 0;

#define HISTORY_LENGTH 7
char history[HISTORY_LENGTH];

#define PAD_COUNT 2
#define BUTTON_COUNT 12

char pad_offset_x[PAD_COUNT] = {7, 7};
char pad_offset_y[PAD_COUNT] = {5, 16};
char button_symbol[BUTTON_COUNT][6] = {
    "R",
    "L",
    "D",
    "U",
    "A",
    "B",
    "X",
    "Y",
    "L",
    "R",
    "Sel",
    "Start"};
char button_name[BUTTON_COUNT][12] = {
    "DPAD Right",
    "DPAD Left",
    "DPAD Down",
    "DPAD Up",
    "A",
    "B",
    "X",
    "Y",
    "L",
    "R",
    "Select",
    "Start"};
char button_x[BUTTON_COUNT] = {6, 2, 4, 4, 24, 22, 22, 20, 3, 23, 9, 13};
char button_y[BUTTON_COUNT] = {5, 5, 6, 4, 5, 6, 4, 5, 1, 1, 5, 5};

char analog_offset_x[PAD_COUNT] = {1, 20};
char analog_offset_y[PAD_COUNT] = {5, 5};
signed char analog_x[PAD_COUNT];
signed char analog_y[PAD_COUNT];
#define analog_size 18
#define analog_ratio 15 // 256 / 17;

#define timestamp_clock_index 32
#define timestamp_index_1 8
#define timestamp_index_2 16
#define timestamp_index_3 24
bool last_timestamp_clock = 0;
// Button test constants
#define btntest_mode_select 0
#define btntest_mode_ready 1
#define btntest_mode_test 2
#define btntest_mode_results 3
#define btntest_timer_start 60    // vblanks to wait before first prompt
#define btntest_timer_interval 90 // vblanks to wait between prompts
#define btntest_timer_visible 30  // vblanks to wait between prompts
#define btntest_counter_max 5     // Number of button presses required
#define btntest_max 255
#define btntest_highlight_start 2
#define btntest_highlight_end 35

// Analog tester variables
char analog_pad = 0;

// Button test variables
char btntest_mode = 0;
char btntest_buttonbank = 0;
char btntest_buttonindex = 0;
char btntest_buttonlast = 1;
char btntest_timer = 0;
char btntest_counter = 0;
unsigned short btntest_presses[btntest_max];
unsigned short btntest_prompts[btntest_counter_max];
char btntest_pos = 0;
char btntest_buttondownlast = 0;
bool btntest_results_refresh = 0;
char btntest_results_offset = 0;
char btntest_highlight = 0;
char btntest_aftertimer = 0;


// Draw static elements for digital input test page
void page_inputtester_digital()
{
    page_frame(true, false);
    // Draw pads
    for (char j = 0; j < PAD_COUNT; j++)
    {
        write_stringf("JOY %d", colour_text_primary, pad_offset_x[j] - 5, pad_offset_y[j] + 5, j + 1);
        draw_pad(pad_offset_x[j], pad_offset_y[j]);
    }
}

// Draw static elements for analog input test page
void page_inputtester_analog()
{
    page_frame(true, false);
    // Draw analog grids
    char j = 0;
    write_string("ANALOG LEFT", colour_text_primary, analog_offset_x[j], analog_offset_y[j] - 1);
    draw_analog(analog_offset_x[j], analog_offset_y[j], analog_size, analog_size);
    write_string("X:", colour_text_primary, analog_offset_x[j] + 1, analog_offset_y[j] + analog_size + 1);
    write_string("Y:", colour_text_primary, analog_offset_x[j] + 10, analog_offset_y[j] + analog_size + 1);

    write_stringf("PAD %d", colour_text_primary, 18, analog_offset_y[j] - 1, analog_pad + 1);

    j = 1;
    write_string("ANALOG RIGHT", colour_text_primary, analog_offset_x[j] + analog_size - 11, analog_offset_y[j] - 1);
    draw_analog(analog_offset_x[j], analog_offset_y[j], analog_size, analog_size);
    write_string("X:", colour_text_primary, analog_offset_x[j] + 1, analog_offset_y[j] + analog_size + 1);
    write_string("Y:", colour_text_primary, analog_offset_x[j] + 10, analog_offset_y[j] + analog_size + 1);

    write_string("Cycle selected pad with A / B", colour_analog_text_cycle, 5, analog_offset_y[j] + analog_size + 2);
}

// Draw static elements for advanced input test page
void page_inputtester_advanced()
{
    page_frame(true, false);

    write_string("RLDUABXYLRsS", colour_text_primary, 7, 5);
    write_string("ALX", colour_text_primary, 21, 5);
    write_string("ALY", colour_text_primary, 25, 5);
    write_string("ARX", colour_text_primary, 30, 5);
    write_string("ARY", colour_text_primary, 34, 5);

    write_string("POS", colour_text_primary, 7, 13);
    write_string("SPD  POS", colour_text_primary, 20, 13);

    char label[5];
    for (unsigned char j = 0; j < 6; j++)
    {
        sprintf(label, "JOY%d", j + 1);
        write_string(label, colour_text_primary, 2, 6 + j);

        sprintf(label, "PAD%d", j + 1);
        write_string(label, colour_text_primary, 2, 14 + j);

        sprintf(label, "SPN%d", j + 1);
        write_string(label, colour_text_primary, 14, 14 + j);
    }

    write_string("KEYBOARD", colour_text_primary, 2, 21);

    write_string("MOUSE", colour_text_primary, 2, 23);
    write_string("WHL", colour_text_primary, 16, 23);
    write_string("BTNS", colour_text_primary, 24, 23);

    SET_BIT(video_ctl, 0); // Enable sprite priority over charmap
}

// Draw static elements for button test page
void page_btntest(bool showMenuButton, bool showContinueButton)
{
    page_frame(showMenuButton, showContinueButton);
    write_string("BUTTON TEST", colour_buttontest_text_primary, 15, 4);
}

void reset_inputstates()
{
    modeswitchtimer_select = 0;
    modeswitchtimer_start = 0;
    for (char i = 0; i < 12; i++)
    {
        joystick_last[i] = 1;
    }
    for (char i = 0; i < 6; i++)
    {
        ax_l_last[i] = 1;
        ay_l_last[i] = -1;
        ax_r_last[i] = 1;
        ay_r_last[i] = -1;
        px_last[i] = 1;
        sx_toggle_last[i] = 1;
        sx_last[i] = 1;
        sx_pos[i] = 0;
        socd_lr[i] = 0;
        socd_ud[i] = 0;
    }
}

// Initialise digital inputtester state and draw static elements
void start_inputtester_digital()
{
    state = STATE_INPUTTESTER;

    // Draw page
    page_inputtester_digital();

    // Reset last states for inputs
    reset_inputstates();
}

// Initialise analog inputtester state and draw static elements
void start_inputtester_analog()
{
    state = STATE_INPUTTESTERANALOG;

    // Draw page
    page_inputtester_analog();

    // Reset last states for inputs
    reset_inputstates();
}

// Initialise advanced inputtester state and draw static elements
void start_inputtester_advanced()
{
    state = STATE_INPUTTESTERADVANCED;

    // Draw page
    page_inputtester_advanced();

    // Setup mouse pointer
    enable_sprite(MOUSE_POINTER_SPRITE, sprite_palette_pointer, sprite_size_pointer, 0);
    spr_index[MOUSE_POINTER_SPRITE] = sprite_index_pointer_first;
    spr_on[MOUSE_POINTER_SPRITE] = 0;
    mse_x_acc = 336;
    mse_y_acc = 256;

    // Reset last states for inputs
    reset_inputstates();
}

// Initialise button test state and draw static elements
void start_btntest()
{
    state = STATE_BTNTEST;
    btntest_mode = btntest_mode_select;
    btntest_buttonbank = 0;
    btntest_buttonindex = 0;
    btntest_buttonlast = 1;
    btntest_timer = 0;
    btntest_counter = 0;
    btntest_pos = 0;

    // Draw page
    page_btntest(true, false);
    write_string("Press the button you want to test", colour_text_primary, 3, 14);
    write_string("Remember to enable fast USB polling!", colour_buttontest_text_secondary, 2, 25);
}

// Rotate DPAD direction history and push new entry
void pushhistory(char new)
{
    for (char h = 1; h < HISTORY_LENGTH; h++)
    {
        history[h - 1] = history[h];
    }
    history[HISTORY_LENGTH - 1] = new;
}

// Track input history of P1 DPAD for secret codes!
void handle_codes()
{
    if (!input_up && input_up_last)
    {
        pushhistory(1);
    }
    if (!input_down && input_down_last)
    {
        pushhistory(2);
    }
    if (!input_left && input_left_last)
    {
        pushhistory(3);
    }
    if (!input_right && input_right_last)
    {
        pushhistory(4);
    }
    if (!input_a && input_a_last)
    {
        pushhistory(5);
    }
    if (!input_b && input_b_last)
    {
        pushhistory(6);
    }

    // Check for SNEK code
    if (history[0] == 1 && history[1] == 1 && history[2] == 2 && history[3] == 2 && history[4] == 3 && history[5] == 4 && history[6] == 5)
    {
        pushhistory(0);
        state = STATE_START_ATTRACT;
        return;
    }
    // Check for Zorblax code
    if (history[0] == 1 && history[1] == 1 && history[2] == 2 && history[3] == 2 && history[4] == 3 && history[5] == 4 && history[6] == 6)
    {
        pushhistory(0);
        state = STATE_START_ZORBLAXX;
        return;
    }
}

// Menu opening handler
bool modeswitcher()
{
    // Check system menu trigger
    if (system_menu)
    {
        system_menu = 0;
        modeswitchtimer_select = 0;
        start_menu();
        return 1;
    }

    // Open menu if select is held
    if (input_select)
    {
        modeswitchtimer_select++;
        if (modeswitchtimer_select == menu_openholdtime)
        {
            modeswitchtimer_select = 0;
            start_menu();
            return 1;
        }
    }
    else
    {
        modeswitchtimer_select = 0;
    }
    return 0;
}

// Digital input tester state
void inputtester_digital()
{

    // Handle PS/2 inputs whenever possible to improve latency
    handle_ps2();

    // Handle secret code detection (joypad 1 directions)
    if (HBLANK_RISING)
    {
        basic_input();
        handle_codes();
    }

    // As soon as vsync is detected start drawing screen updates
    if (VBLANK_RISING)
    {
        // Handle test mode switch
        if (modeswitcher())
        {
            return;
        }

        // Draw control pad buttons
        for (char joy = 0; joy < PAD_COUNT; joy++)
        {
            char index = joy * 4;
            for (char button = 0; button < BUTTON_COUNT; button++)
            {
                char color = (button < 8 ? CHECK_BIT(joystick[index], button) : CHECK_BIT(joystick[index + 1], button - 8)) ? colour_button_active : colour_button_inactive;
                write_string(button_symbol[button], color, pad_offset_x[joy] + button_x[button], pad_offset_y[joy] + button_y[button]);
            }
            // SOCD detection
            socd_lr[joy] = CHECK_BIT(joystick[index], 0) && CHECK_BIT(joystick[index], 1);
            if (socd_lr[joy])
            {
                write_string("SOCD L+R", colour_cga_lightred, pad_offset_x[joy] + 9, pad_offset_y[joy] + 8);
            }
            else
            {
                if (socd_lr_last[joy])
                {
                    write_string("SOCD L+R", colour_cga_darkred, pad_offset_x[joy] + 9, pad_offset_y[joy] + 8);
                }
            }
            socd_lr_last[joy] = socd_lr[joy];

            socd_ud[joy] = CHECK_BIT(joystick[index], 2) && CHECK_BIT(joystick[index], 3);
            if (socd_ud[joy])
            {
                write_string("SOCD U+D", colour_cga_lightred, pad_offset_x[joy] + 9, pad_offset_y[joy] + 9);
            }
            else
            {
                if (socd_ud_last[joy])
                {
                    write_string("SOCD U+D", colour_cga_darkred, pad_offset_x[joy] + 9, pad_offset_y[joy] + 9);
                }
            }
            socd_ud_last[joy] = socd_ud[joy];
        }
    }
}

// Analog input tester state
void inputtester_analog()
{

    // Handle PS/2 inputs whenever possible to improve latency
    handle_ps2();

    if (HBLANK_RISING)
    {
        basic_input();
        handle_codes();

        // Pad selection
        if (!input_a && input_a_last)
        {
            if (analog_pad == 5)
            {
                analog_pad = 0;
            }
            else
            {
                analog_pad += 1;
            }
            page_inputtester_analog();
        }
        if (!input_b && input_b_last)
        {
            if (analog_pad == 0)
            {
                analog_pad = 5;
            }
            else
            {
                analog_pad -= 1;
            }
            page_inputtester_analog();
        }
    }

    // As soon as vsync is detected start drawing screen updates
    if (VBLANK_RISING)
    {
        // Handle test mode switch
        if (modeswitcher())
        {
            return;
        }

        // Draw analog left point
        char side = 0;
        char mx = analog_offset_x[side] + (analog_size / 2);
        char my = analog_offset_y[side] + (analog_size / 2);

        // Reset previous color
        set_fgcolour(colour_analog_grid, analog_x[side] + mx, analog_y[side] + my);

        signed char ax = analog_l[(analog_pad * 2)];
        signed char ay = analog_l[(analog_pad * 2) + 1];

        analog_x[side] = ax / analog_ratio;
        analog_y[side] = ay / analog_ratio;

        // Set new color
        set_fgcolour(colour_text_primary, analog_x[side] + mx, analog_y[side] + my);

        write_stringfs("%4d", colour_text_primary, analog_offset_x[side] + 3, analog_offset_y[side] + analog_size + 1, ax);
        write_stringfs("%4d", colour_text_primary, analog_offset_x[side] + 12, analog_offset_y[side] + analog_size + 1, ay);

        // Draw analog right point
        side = 1;
        mx = analog_offset_x[side] + (analog_size / 2);
        my = analog_offset_y[side] + (analog_size / 2);

        // Reset previous color
        set_fgcolour(colour_analog_grid, analog_x[side] + mx, analog_y[side] + my);

        ax = analog_r[(analog_pad * 2)];
        ay = analog_r[(analog_pad * 2) + 1];

        analog_x[side] = ax / analog_ratio;
        analog_y[side] = ay / analog_ratio;

        // Set new color
        set_fgcolour(colour_text_primary, analog_x[side] + mx, analog_y[side] + my);

        write_stringfs("%4d", colour_text_primary, analog_offset_x[side] + 3, analog_offset_y[side] + analog_size + 1, ax);
        write_stringfs("%4d", colour_text_primary, analog_offset_x[side] + 12, analog_offset_y[side] + analog_size + 1, ay);
    }
}

// Advanced input tester state
void inputtester_advanced()
{

    // Handle PS/2 inputs whenever possible to improve latency
    handle_ps2();

    // Handle secret code detection (joypad 1 directions)
    if (HBLANK_RISING)
    {
        basic_input();
        handle_codes();
    }

    // As soon as vsync is detected start drawing screen updates
    if (VBLANK_RISING)
    {
        // Handle test mode switch
        if (modeswitcher())
        {
            clear_sprites();
            update_sprites();
            return;
        }

        // Draw joystick inputs (only update each byte if value has changed)
        for (char inputindex = 0; inputindex < 6; inputindex++)
        {
            char mask = 0b00000001;
            char cx = 6;
            char y = 6 + inputindex;
            char inputoffset = (inputindex * 4);
            char lastoffset = (inputindex * 2);
            for (char b = 0; b < 2; b++)
            {
                char index = b + inputoffset;
                char lastindex = b + lastoffset;
                char joy = joystick[index];
                if (joy != joystick_last[lastindex])
                {
                    mask = 0b00000001;
                    char bytes = (b == 0 ? 8 : 4);
                    for (char i = 0; i < bytes; i++)
                    {
                        cx++;
                        write_char((joy & mask) ? asc_1 : asc_0, colour_text_primary, cx, y);
                        mask <<= 1;
                    }
                }
                else
                {
                    cx += 8;
                }
                joystick_last[lastindex] = joy;
            }

            char stra[10];
            // Draw analog left inputs (only update if value has changed)
            signed char ax_l = analog_l[(inputindex * 2)];
            signed char ay_l = analog_l[(inputindex * 2) + 1];
            if (ax_l != ax_l_last[inputindex] || ay_l != ay_l_last[inputindex])
            {
                sprintf(stra, "%4d%4d", ax_l, ay_l);
                write_string(stra, colour_text_primary, 20, 6 + inputindex);
            }
            ax_l_last[inputindex] = ax_l;
            ay_l_last[inputindex] = ay_l;

            // Draw analog right inputs (only update if value has changed)
            signed char ax_r = analog_r[(inputindex * 2)];
            signed char ay_r = analog_r[(inputindex * 2) + 1];
            if (ax_r != ax_r_last[inputindex] || ay_r != ay_r_last[inputindex])
            {
                sprintf(stra, "%4d%4d", ax_r, ay_r);
                write_string(stra, colour_text_primary, 29, 6 + inputindex);
            }
            ax_r_last[inputindex] = ax_r;
            ay_r_last[inputindex] = ay_r;

            // Draw paddle inputs (only update if value has changed)
            unsigned char px = paddle[(inputindex)];
            if (px != px_last[inputindex])
            {
                char strp[5];
                sprintf(strp, "%4d", px);
                write_string(strp, colour_text_primary, 6, 14 + inputindex);
            }
            px_last[inputindex] = px;

            // Draw spinner inputs (only update when update clock changes)
            bool sx_toggle = CHECK_BIT(spinner[(inputindex * 2) + 1], 0);
            signed char sx = spinner[(inputindex * 2)];
            if (sx_toggle != sx_toggle_last[inputindex])
            {
                sx_pos[inputindex] += sx;
                write_stringf("%4d", colour_text_primary, 24, 14 + inputindex, sx_pos[inputindex]);
            }
            else
            {
                if (sx == 1 || sx == -1)
                {
                    sx = 0;
                }
            }
            if (sx_last[inputindex] != sx)
            {
                write_stringfs("%4d", colour_text_primary, 19, 14 + inputindex, sx);
            }
            sx_last[inputindex] = sx;
            sx_toggle_last[inputindex] = sx_toggle;
        }

        // Scancode output
        if (kbd_scan != kbd_scan_last || kbd_ascii != kbd_ascii_last)
        {
            write_stringf("%02x", colour_text_primary, 11, 21, kbd_scan);
            write_char(kbd_ascii, colour_text_primary, 14, 21);

            kbd_scan_last = kbd_scan;
            kbd_ascii_last = kbd_ascii;
        }

        if (mse_changed)
        {
            // Mouse position accumulator
            mse_x_acc += mse_x;
            mse_y_acc -= mse_y;
            mse_w_acc += mse_w;

            // Enforce mouse pointer limit
            if (mse_x_acc < 32)
            {
                mse_x_acc = 32;
            }
            else if (mse_x_acc >= 671)
            {
                mse_x_acc = 671;
            }
            if (mse_y_acc < 32)
            {
                mse_y_acc = 32;
            }
            else if (mse_y_acc >= 511)
            {
                mse_y_acc = 511;
            }
            unsigned short mx = (mse_x_acc / 2);
            unsigned short my = (mse_y_acc / 2);
            if (mse_x != 0 || mse_y != 0)
            {
                spr_on[MOUSE_POINTER_SPRITE] = 1;
                set_sprite_position(MOUSE_POINTER_SPRITE, mx, my);
            }
            write_stringf_ushort("%3d", colour_text_primary, 8, 23, mx - 16);
            write_stringf_ushort("%3d", colour_text_primary, 12, 23, my - 16);
            write_stringf("%3d", colour_text_primary, 20, 23, mse_w_acc);

            if (mse_button1_last != mse_button1)
            {
                char x = 28;
                char m = 0b00000001;
                for (char i = 0; i < 3; i++)
                {
                    x++;
                    write_char((mse_button1 & m) ? asc_1 : asc_0, colour_text_primary, x, 23);
                    m <<= 1;
                }
                input_mouse_left = CHECK_BIT(mse_button1, 0);
                input_mouse_right = CHECK_BIT(mse_button1, 1);
            }
            mse_button1_last = mse_button1;
            if (mse_button2_last != mse_button2)
            {
                char x = 31;
                char m = 0b00000001;
                for (char i = 0; i < 5; i++)
                {
                    x++;
                    write_char((mse_button2 & m) ? asc_1 : asc_0, colour_text_primary, x, 23);
                    m <<= 1;
                }
            }
            mse_button2_last = mse_button2;

            if (input_mouse_left && !input_mouse_left_last)
            {
                add_ping(0, mx - 8, my - 8);
            }
            if (input_mouse_right && !input_mouse_right_last)
            {
                add_ping(1, mx - 8, my - 8);
            }

            mse_changed = 0;
        }

        handle_pings();
        update_sprites();
    }
}

void btntest_starttest()
{
    btntest_mode = btntest_mode_test;
    page_btntest(false, false); // reset screen

    // Prepare variables
    btntest_timer = btntest_timer_start;

    // Reset hardware timer
    timer[0] = 0;

    write_string("Press here", colour_buttontest_purple, 14, 14);
    write_char(19, colour_buttontest_purple, 19, 15);
    write_string("---\x3\x3\x3\x2\x2\x2\x1\x1\x1\xA6\xA6\xA6\x7f\x7f\x7f\xA6\xA6\xA6\x1\x1\x1\x2\x2\x2\x3\x3\x3---", colour_buttontest_purple, 3, 16);
}

// Button test - button select state
void btntest_select()
{

    if (HBLANK_RISING)
    {
        // If any of 1st 8 buttons is pressed
        if (joystick[0] != 0 && joystick_last[0] == 0)
        {
            btntest_buttonbank = 0;
            // Find which button
            for (char b = 0; b < 8; b++)
            {
                if (CHECK_BIT(joystick[btntest_buttonbank], b))
                {
                    btntest_buttonindex = b;
                    break;
                }
            }
            btntest_mode = btntest_mode_ready;
            page_btntest(false, false); // reset screen
            write_string("Hit the button at each prompt", colour_cga_lightcyan, 5, 14);
            write_string("Selected button is: ", colour_text_primary, 6, 16);
            char i = btntest_buttonindex + (btntest_buttonbank * 8);
            write_string(button_name[i], colour_cga_lightred, 26, 16);
            write_string("Press again to start test", colour_cga_yellow, 7, 18);
            btntest_timer = 10;
            return;
        }
        else if (joystick[1] != 0 && joystick_last[1] == 0)
        {
            btntest_buttonbank = 1;
            // Find which button
            for (char b = 0; b < 8; b++)
            {
                if (CHECK_BIT(joystick[btntest_buttonbank], b))
                {
                    btntest_buttonindex = b;
                    break;
                }
            }
            btntest_mode = btntest_mode_ready;
            page_btntest(false, false); // reset screen
            write_string("Hit the button at each prompt", colour_cga_lightcyan, 5, 14);
            write_string("Selected button is: ", colour_text_primary, 6, 16);
            char i = btntest_buttonindex + (btntest_buttonbank * 8);
            write_string(button_name[i], colour_cga_lightred, 26, 16);
            write_string("Press again to start test", colour_cga_yellow, 7, 18);
            btntest_timer = 10;
            return;
        }

        for (unsigned char i = 0; i < 16; i++)
        {
            joystick_last[i] = joystick[i];
        }
    }

    if (VBLANK_RISING)
    {
        // Check inputs for select hold to enter menu
        basic_input();
        modeswitcher();
    }
}

// Button test - ready state
void btntest_ready()
{
    if (HBLANK_RISING)
    {
        char button = CHECK_BIT(joystick[btntest_buttonbank], btntest_buttonindex);
        if (btntest_timer > 0)
        {
            if (joystick[btntest_buttonbank] == 0)
            {
                btntest_timer--;
            }
        }
        else
        {
            // Check for selected button to be pressed again
            if (!button && btntest_buttonlast)
            {
                btntest_starttest();
            }
        }
        btntest_buttonlast = button;
    }
}

// Button test - begin test state
void btntest_test()
{

    // Track button presses
    bool down = CHECK_BIT(joystick[btntest_buttonbank], btntest_buttonindex);
    if (down && !btntest_buttondownlast)
    {
        btntest_presses[btntest_pos] = GET_TIMER;
        btntest_pos++;
        if (btntest_pos == 14)
        {
            btntest_mode = btntest_mode_results;
            btntest_results_refresh = true;
            page_btntest(true, true); // reset screen
            return;
        }
    }
    btntest_buttondownlast = down;

    if (VBLANK_RISING)
    {
        // Count down to next prompt on vblanks
        btntest_timer--;

        set_bgcolour(0x0, btntest_highlight, 16);
        if (btntest_timer == 30)
        {
            btntest_highlight = btntest_highlight_start;
        }
        if (btntest_highlight > 0)
        {
            if ((btntest_timer % 2) == 0)
            {
                btntest_highlight++;
                if (btntest_highlight > btntest_highlight_end)
                {
                    btntest_highlight = 0;
                }
            }
        }
        if (btntest_highlight > 0)
        {
            set_bgcolour(colour_text_primary, btntest_highlight, 16);
        }

        if (btntest_aftertimer > 0)
        {
            btntest_aftertimer--;
            if (btntest_aftertimer == 0)
            {
                // End test here
                if (btntest_counter == btntest_counter_max)
                {
                    btntest_mode = btntest_mode_results;
                    btntest_results_refresh = true;
                    page_btntest(true, true); // reset screen
                    return;
                }
            }
        }

        if (btntest_timer == 0)
        {
            // Capture timer
            btntest_prompts[btntest_counter] = GET_TIMER;

            // Display test counter
            write_stringf("%2d", colour_text_primary, 18, 6, btntest_counter + 1);

            btntest_timer = btntest_timer_interval;
            btntest_aftertimer = 33;
            btntest_counter++;
        }
    }
}

// Button test - results view
void btntest_results()
{

    if (btntest_results_refresh)
    {
        write_string("Prompts", colour_text_primary, 2, 6);
        //        write_string("-------", colour_text_primary, 2, 7);
        write_string("Presses", colour_text_primary, 11, 6);
        //        write_string("-------", colour_text_primary, 11, 7);

        char y = 7;
        char press = 0;
        char prompt = 0;
        char done = false;

        unsigned short prompt_last = 0;
        unsigned short press_last = 0;

        while (!done)
        {

            unsigned short prompt_time = prompt < btntest_counter_max ? btntest_prompts[prompt] : 65535;
            unsigned short press_time = press < btntest_pos ? btntest_presses[press] : 65535;

            if (prompt_time < press_time)
            {
                write_stringf_ushort("%6dms", colour_text_primary, 2, y, btntest_prompts[prompt]);
                y++;
                prompt++;
                prompt_last = prompt_time;
            }
            else if (press_time < prompt_time)
            {
                write_stringf_ushort("%6dms", colour_text_primary, 11, y, btntest_presses[press]);

                // Is this early or late or just nowhere near?!
                unsigned short prompt_next = prompt + 1 <= btntest_counter_max ? btntest_prompts[prompt] : 65535;

                unsigned short diff_last = abs(press_time - prompt_last);
                unsigned short diff_next = abs(prompt_next - press_time);

                if (diff_next < 500)
                {
                    write_stringf_short("%3dms before", colour_cga_yellow, 20, y, diff_next);
                }
                else if (diff_last <= 500)
                {
                    write_stringf_short("%3dms after", colour_cga_lightcyan, 20, y, diff_last);
                }
                else
                {
                    write_stringf_short("????", colour_cga_lightred, 20, y, diff_next);
                }
                y++;
                press++;
            }
            else
            {
                done = true;
            }
        }

        btntest_results_refresh = 0;
    }

    if (VBLANK_RISING)
    {

        // Check inputs for select hold to enter menu
        basic_input();
        modeswitcher();

        if (input_start && !input_start_last)
        {
            for (unsigned char i = 0; i < 16; i++)
            {
                joystick_last[i] = 1;
            }
            start_btntest();
        }
    }
}

// Button test - mode handler
void btntest()
{

    switch (btntest_mode)
    {
    case btntest_mode_select:
        btntest_select();
        break;
    case btntest_mode_ready:
        btntest_ready();
        break;
    case btntest_mode_test:
        btntest_test();
        break;
    case btntest_mode_results:
        btntest_results();
        break;
    }
}
