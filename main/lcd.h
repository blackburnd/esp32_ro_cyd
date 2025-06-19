#pragma once

#include <esp_err.h>
#include <esp_lcd_panel_io.h>
#include <esp_lcd_panel_ops.h>
#include <lvgl.h>

// Initialize LCD display
esp_err_t app_lcd_init(esp_lcd_panel_io_handle_t *lcd_io, esp_lcd_panel_handle_t *lcd_panel);

// Initialize LVGL display
lv_display_t *app_lvgl_init(esp_lcd_panel_io_handle_t lcd_io, esp_lcd_panel_handle_t lcd_panel);

// Initialize LCD backlight
esp_err_t lcd_display_brightness_init(void);

// Set LCD brightness (0-100%)
esp_err_t lcd_display_brightness_set(int brightness_percent);

// Turn off LCD backlight
esp_err_t lcd_display_backlight_off(void);

// Turn on LCD backlight
esp_err_t lcd_display_backlight_on(void);

// Rotate LCD display
esp_err_t lcd_display_rotate(lv_display_t *lvgl_disp, lv_display_rotation_t dir);