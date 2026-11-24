#include QMK_KEYBOARD_H
#include "ergohaven.h"
#include "src/eh_pointing.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                             KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                             KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                             KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                    KC_PGDN,  KC_PGUP,  KC_LCTL,  LOWER,    KC_LALT,  KC_SPACE,           KC_ENT,   KC_RGUI,  RAISE,    KC_RCTL,  KC_LBRC,  KC_RBRC,
                                                                      KC_MUTE,            KC_MUTE
    ),

    [_LOWER] = LAYOUT(
KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                                            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
KC_VOLU,  KC_MNXT,  KC_HOME,  KC_UP,    KC_END,   KC_INS,                                           _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
KC_MUTE,  KC_MPLY,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_ENT,                                           _______,  KC_4,     KC_5,     KC_6,     _______,  _______,
KC_VOLD,  KC_MPRV,  PREVWRD,  _______,  NEXTWRD,  KC_DEL,                                           KC_PSCR,  KC_1,     KC_2,     KC_3,     _______,  _______,
                    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  KC_0,     _______,
                                                                      _______,            _______
    ),

    [_RAISE] = LAYOUT(
_______,  _______,  KC_AT,    KC_DLR,   KC_HASH,  _______,                                          _______,  _______,  KC_CIRC,  _______,  _______,  _______,
_______,  _______,  KC_LT,    KC_EQL,   KC_GT,    KC_GRV,                                           _______,  KC_LBRC,  KC_UNDS,  KC_RBRC,  _______,  _______,
_______,  KC_BSLS,  KC_LPRN,  KC_MINS,  KC_RPRN,  KC_PLUS,                                          KC_PERC,  KC_LCBR,  KC_SCLN,  KC_RCBR,  KC_EXLM,  _______,
_______,  _______,  KC_ASTR,  KC_COLN,  KC_SLSH,  _______,                                          _______,  KC_PIPE,  KC_TILD,  KC_AMPR,  _______,  _______,
                    _______,  _______,  _______,  _______,  _______,  _______,          _______,    _______,  _______,  _______,  _______,  _______,
                                                                      _______,          _______
    ),

    [_ADJUST] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
                    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                                                      _______,            _______
    ),

    [_FOUR] = LAYOUT(
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  _______,  _______,  _______,  _______,  _______,                                          _______,  _______,  _______,  _______,  _______,  _______,
_______,  EH_SCR,   KC_BTN3,  KC_BTN2,  KC_BTN1,  EH_SNP,                                           EH_SNP,   KC_BTN1,  KC_BTN2,  KC_BTN3,  EH_SCR,   _______,
_______,  _______,  _______,  _______,  _______,  EH_TXT,                                           EH_TXT,   _______,  _______,  _______,  _______,  _______,
                    _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                                                      _______,            _______
    ),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, //
    [1] = {ENCODER_CCW_CW(_______, _______)}, //
    [2] = {ENCODER_CCW_CW(_______, _______)}, //
    [3] = {ENCODER_CCW_CW(_______, _______)}, //
    [4] = {ENCODER_CCW_CW(_______, _______)}, //
};
#endif

#include <stdlib.h>
#include <string.h>
#include "hid.h"
#include "ergohaven_rgb.h"
#include "src/eh_ruen.h"
#ifdef MOUSEKEY_ENABLE
#    include "mousekey.h"
#endif

#ifdef POINTING_DEVICE_HIRES_SCROLL_ENABLE
extern bool usb_hires_scroll_v_enabled(void);
#endif

extern pointing_mode_t pointing_mode;

#define POINTING_MODE_ZOOM        POINTING_MODE_USR1
#define POINTING_MODE_SHUTTLE     POINTING_MODE_USR2
#define POINTING_MODE_TAB_CRUISER POINTING_MODE_USR3

#define ZOOM_TICKS_PER_STEP         3
#define ZOOM_IDLE_RELEASE_MS        120
#define SHUTTLE_IDLE_RESTORE_MS     150
#define TAB_CRUISER_DEADZONE_COUNTS 96
#define TAB_CRUISER_STEP_COUNTS     40
#define TAB_CRUISER_REST_RESET_MS   250
#define TAB_CRUISER_KEY_SUPPRESS_MS 200
#define LAYER15_POLL_MS             50
#define F18_LOCK_HOLD_MS            350
#define LOCK_BLINK_PERIOD_MS        220

/* === 1. POINTING MODE & BALL OVERRIDE STATE === */
static pointing_mode_t active_effective_mode     = POINTING_MODE_NORMAL;
static bool            momentary_override_active = false;
static pointing_mode_t momentary_override_mode   = POINTING_MODE_NORMAL;
static uint16_t        override_press_timer      = 0;
static uint16_t        override_pressed_keycode  = KC_NO;
static bool            sticky_override_active    = false;
static pointing_mode_t sticky_override_mode      = POINTING_MODE_NORMAL;
static uint8_t         sticky_override_layer     = 0;

static bool eh_txt_held       = false;
static bool eh_usr1_held      = false;
static bool chord_mouse_reset = false;

/* Ball Zoom (EH_USR1 - spring-only) */
static bool     zoom_ctrl_active     = false;
static uint16_t zoom_last_tick_timer = 0;
static int32_t  zoom_accum_counts    = 0;

/* Video Shuttle (EH_USR2) */
static int32_t  shuttle_accum_x         = 0;
static uint16_t shuttle_last_motion_ms  = 0;
static uint16_t shuttle_last_step_ms    = 0;
static uint8_t  shuttle_suppressed_mods = 0;

/* Tab Cruiser (EH_USR3, default on 4: F12) */
static bool     tab_cruiser_armed            = false;
static int32_t  tab_cruiser_deadzone_x       = 0;
static int32_t  tab_cruiser_accum_x          = 0;
static uint16_t tab_cruiser_last_motion_ms   = 0;
static uint16_t tab_cruiser_key_suppress_ms  = 0;
static bool     tab_cruiser_suppress_active  = false;

static uint16_t layer15_poll_timer = 0;

/* === 2. DUAL-THUMB CHORDS & INSTANT SPRING-LATCH TT(1)/TT(3) === */
static bool     lt2_phys_held           = false;
static bool     lt2_was_tt1             = false;
static bool     lt2_used_with_other_key = false;
static bool     lt2_chord_mo4           = false;
static uint16_t lt2_press_timer         = 0;

static bool     rt2_thumb_armed         = false;
static bool     rt2_was_tt3             = false;
static bool     rt2_used_with_other_key = false;
static bool     rt2_chord_mo5           = false;
static uint16_t rt2_press_timer         = 0;

/* === 3. F18 PANORAMA / WIN+L, LG_WORD, AND RGB / LOCK BLINK === */
static bool     f18_active = false;
static bool     f18_fired  = false;
static uint16_t f18_timer  = 0;

static bool eng_word_active = false;
static bool m6_had_caps     = false;

typedef struct {
    uint8_t hue;
    uint8_t sat;
    uint8_t val;
} user_rgb_color_t;

static const user_rgb_color_t user_rgb_palette[EH_RGB_PALETTE_SIZE] = {
    {0, 0, 0},       // 0: Off
    {0, 0, 255},     // 1: White
    {0, 255, 255},   // 2: Red
    {16, 255, 255},  // 3: Orange
    {27, 255, 255},  // 4: Goldenrod
    {38, 255, 255},  // 5: Gold
    {53, 255, 255},  // 6: Yellow
    {74, 255, 255},  // 7: Chartreuse
    {90, 255, 255},  // 8: Lime
    {106, 255, 255}, // 9: Green
    {117, 255, 255}, // 10: Spring Green
    {128, 255, 255}, // 11: Turquoise
    {138, 255, 170}, // 12: Teal
    {149, 255, 255}, // 13: Cyan
    {160, 255, 255}, // 14: Azure
    {165, 255, 255}, // 15: Sky
    {170, 255, 255}, // 16: Blue
    {186, 255, 255}, // 17: Indigo
    {202, 255, 255}, // 18: Purple
    {213, 255, 255}, // 19: Magenta
    {234, 180, 255}, // 20: Pink
    {8, 176, 255},   // 21: Coral
    {14, 128, 255},  // 22: Salmon
    {32, 64, 255},   // 23: Warm White
    {22, 255, 255},  // 24: Amber
};

static rgblight_segment_t user_rgb_segments[EH_RGB_LAYER_COUNT][2] = {
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
    {{0, 2, 0, 0, 255}, {RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0, 0}},
};

static const rgblight_segment_t *const user_rgb_layers[EH_RGB_LAYER_COUNT] = {
    user_rgb_segments[0],  user_rgb_segments[1],  user_rgb_segments[2],  user_rgb_segments[3],
    user_rgb_segments[4],  user_rgb_segments[5],  user_rgb_segments[6],  user_rgb_segments[7],
    user_rgb_segments[8],  user_rgb_segments[9],  user_rgb_segments[10], user_rgb_segments[11],
    user_rgb_segments[12], user_rgb_segments[13], user_rgb_segments[14], user_rgb_segments[15],
};

static bool     contrast_mode_active   = false;
static uint8_t  last_seen_entropy_bri  = 128;
static uint8_t  cached_layer_colors[EH_RGB_LAYER_COUNT];
static bool     lock_blink_active      = false;
static bool     lock_blink_off_phase   = false;
static uint16_t lock_blink_timer       = 0;

static void refresh_user_rgb_segments(void) {
    uint8_t base_bri = get_led_rgb_brightness();
    for (uint8_t i = 0; i < EH_RGB_LAYER_COUNT; ++i) {
        uint8_t cidx = get_layer_rgb_color(i);
        if (cidx >= EH_RGB_PALETTE_SIZE) {
            cidx = 0;
        }
        cached_layer_colors[i] = cidx;
        user_rgb_color_t col   = user_rgb_palette[cidx];

        uint8_t eff_bri = base_bri;
        if (contrast_mode_active) {
            eff_bri = (i == 0 || i == 1 || i == 14) ? 85 : 255;
        }
        uint16_t scaled_val = lock_blink_off_phase ? 0 : (((uint16_t)col.val * (uint16_t)eff_bri) / 255);

        user_rgb_segments[i][0].hue = col.hue;
        user_rgb_segments[i][0].sat = col.sat;
        user_rgb_segments[i][0].val = (uint8_t)scaled_val;
    }

    uint8_t cur_layer = get_highest_layer(layer_state | default_layer_state);
    uint8_t raw_val   = contrast_mode_active ? ((cur_layer == 0 || cur_layer == 1) ? 85 : 255) : base_bri;
    if (lock_blink_off_phase) {
        raw_val = 0;
    }
    rgblight_sethsv_noeeprom(rgblight_get_hue(), rgblight_get_sat(), raw_val);
    rgblight_set();
}

static void fast_clear_lock_leds(void) {
    if (!is_keyboard_master()) {
        return;
    }
    led_t leds = host_keyboard_led_state();
    if (leds.caps_lock) {
        register_code(KC_CAPS_LOCK);
        wait_ms(2);
        unregister_code(KC_CAPS_LOCK);
    }
    if (leds.scroll_lock) {
        register_code(KC_SCROLL_LOCK);
        wait_ms(2);
        unregister_code(KC_SCROLL_LOCK);
    }
}

static void zoom_release_ctrl(void) {
    zoom_accum_counts = 0;
    if (zoom_ctrl_active) {
        del_weak_mods(MOD_BIT(KC_LCTL));
        send_keyboard_report();
        zoom_ctrl_active = false;
        wait_ms(2);
    }
}

static void shuttle_restore_mods(void) {
    shuttle_accum_x = 0;
    if (shuttle_suppressed_mods != 0) {
        add_mods(shuttle_suppressed_mods);
        shuttle_suppressed_mods = 0;
        send_keyboard_report();
    }
}

static void tab_cruiser_reset(void) {
    tab_cruiser_armed           = false;
    tab_cruiser_deadzone_x      = 0;
    tab_cruiser_accum_x         = 0;
    tab_cruiser_suppress_active = false;
}

static pointing_mode_t default_pointing_mode_for_layer(uint8_t layer) {
    if (layer < 16) {
        uint16_t cfg_kc = dynamic_keymap_get_keycode(15, layer / 6, layer % 6);
        switch (cfg_kc) {
            case MS_BTN1:
            case MS_UP:
                return POINTING_MODE_NORMAL;
            case EH_SNP:
                return POINTING_MODE_SNIPER;
            case EH_SCR:
                return POINTING_MODE_SCROLL;
            case EH_TXT:
                return POINTING_MODE_TEXT;
            case EH_USR1:
                return POINTING_MODE_ZOOM;
            case EH_USR2:
                return POINTING_MODE_SHUTTLE;
            case EH_USR3:
                return POINTING_MODE_TAB_CRUISER;
            default:
                break;
        }
    }
    if (layer == 4) {
        return POINTING_MODE_TAB_CRUISER;
    }
    if (layer == 5) {
        return POINTING_MODE_SCROLL;
    }
    return POINTING_MODE_NORMAL;
}

static pointing_mode_t hw_mode_for_effective(pointing_mode_t mode) {
    if (mode > POINTING_MODE_TEXT) {
        /* USR1 (Zoom), USR2 (Video Shuttle), USR3 (Tab Cruiser) use raw/accelerated XY in pointing_device_task_kb */
        return POINTING_MODE_NORMAL;
    }
    return mode;
}

static void sync_pointing_mode_for_state(layer_state_t effective_state) {
    uint8_t layer = get_highest_layer(effective_state);

    if (sticky_override_active) {
        if (layer == 0 ||
            (effective_state & ((layer_state_t)1 << sticky_override_layer)) == 0 ||
            (sticky_override_layer == 1 && layer == 2) ||
            (sticky_override_layer == 2 && layer == 1)) {
            sticky_override_active = false;
        }
    }

    pointing_mode_t next_mode = default_pointing_mode_for_layer(layer);
    if (momentary_override_active) {
        next_mode = momentary_override_mode;
    } else if (sticky_override_active && layer == sticky_override_layer) {
        next_mode = sticky_override_mode;
    }

    pointing_mode_t prev_mode = active_effective_mode;
    pointing_mode_t next_hw   = hw_mode_for_effective(next_mode);

    if (prev_mode != next_mode) {
        if (prev_mode == POINTING_MODE_ZOOM) {
            zoom_release_ctrl();
        }
        if (prev_mode == POINTING_MODE_SHUTTLE) {
            shuttle_restore_mods();
        }
        if (prev_mode == POINTING_MODE_TAB_CRUISER || next_mode == POINTING_MODE_TAB_CRUISER) {
            tab_cruiser_reset();
        }
        if (prev_mode != POINTING_MODE_NORMAL) {
            pointing_mode          = POINTING_MODE_NORMAL;
            report_mouse_t zero_mr = {0};
            (void)pointing_device_task_user(zero_mr);
        }
        active_effective_mode = next_mode;
        if (pointing_mode != next_hw) {
            pointing_mode = next_hw;
            if (is_hid_active()) {
                hid_send_pointing_mode(next_hw);
            }
        }
    } else if (pointing_mode != next_hw) {
        pointing_mode = next_hw;
        if (is_hid_active()) {
            hid_send_pointing_mode(next_hw);
        }
    }
}

void keyboard_post_init_user(void) {
    if (get_led_blinks()) {
        set_led_blinks(false);
    }
    if (get_pointing_mode() != POINTING_MODE_NORMAL) {
        set_pointing_mode(POINTING_MODE_NORMAL);
    }
    last_seen_entropy_bri = get_led_rgb_brightness();
    rgblight_layers       = user_rgb_layers;
    refresh_user_rgb_segments();
    layer15_poll_timer = timer_read();
    sync_pointing_mode_for_state(layer_state | default_layer_state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    sync_pointing_mode_for_state(layer_state | state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    sync_pointing_mode_for_state(state | default_layer_state);
    if (is_keyboard_master() && contrast_mode_active) {
        refresh_user_rgb_segments();
    }
    return state;
}

void housekeeping_task_user(void) {
    if (zoom_ctrl_active && timer_elapsed(zoom_last_tick_timer) >= ZOOM_IDLE_RELEASE_MS) {
        zoom_release_ctrl();
    }
    if (shuttle_suppressed_mods != 0 && timer_elapsed(shuttle_last_step_ms) >= SHUTTLE_IDLE_RESTORE_MS) {
        shuttle_restore_mods();
    }
    if (timer_elapsed(layer15_poll_timer) >= LAYER15_POLL_MS) {
        layer15_poll_timer = timer_read();
        sync_pointing_mode_for_state(layer_state | default_layer_state);
    }

    if (!is_keyboard_master()) {
        return;
    }

    if (f18_active && !f18_fired && timer_elapsed(f18_timer) >= F18_LOCK_HOLD_MS) {
        f18_fired = true;
        clear_weak_mods();
        tap_code16(G(KC_L));
    }

    uint8_t cur_entropy_bri = get_led_rgb_brightness();
    bool    colors_changed  = false;
    if (cur_entropy_bri != last_seen_entropy_bri) {
        last_seen_entropy_bri = cur_entropy_bri;
        contrast_mode_active  = false;
        colors_changed        = true;
    } else {
        for (uint8_t i = 0; i < EH_RGB_LAYER_COUNT; ++i) {
            uint8_t c = get_layer_rgb_color(i);
            if (c >= EH_RGB_PALETTE_SIZE) {
                c = 0;
            }
            if (cached_layer_colors[i] != c) {
                colors_changed = true;
                break;
            }
        }
    }

    led_t leds        = host_keyboard_led_state();
    bool  locks_on    = leds.caps_lock || leds.scroll_lock;
    if (locks_on) {
        if (!lock_blink_active) {
            lock_blink_active    = true;
            lock_blink_off_phase = true;
            lock_blink_timer     = timer_read();
            colors_changed       = true;
        } else if (timer_elapsed(lock_blink_timer) >= LOCK_BLINK_PERIOD_MS) {
            lock_blink_timer     = timer_read();
            lock_blink_off_phase = !lock_blink_off_phase;
            colors_changed       = true;
        }
    } else if (lock_blink_active) {
        lock_blink_active    = false;
        lock_blink_off_phase = false;
        colors_changed       = true;
    }

    if (colors_changed) {
        refresh_user_rgb_segments();
    }

    uint8_t cur_layer = get_highest_layer(layer_state | default_layer_state);
    bool    want_14   = (cur_layer == 0) && (get_cur_lang() == LANG_EN || eng_word_active);
    if (rgblight_get_layer_state(14) != want_14) {
        rgblight_set_layer_state(14, want_14);
    }
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (zoom_ctrl_active && record->event.pressed) {
        zoom_release_ctrl();
    }

    /* Keep Video Shuttle suppressed Shift/Ctrl synchronized with physical modifier releases/presses */
    if (shuttle_suppressed_mods != 0) {
        if (!record->event.pressed) {
            switch (keycode) {
                case KC_LSFT:
                    shuttle_suppressed_mods &= ~MOD_BIT(KC_LSFT);
                    break;
                case KC_RSFT:
                    shuttle_suppressed_mods &= ~MOD_BIT(KC_RSFT);
                    break;
                case KC_LCTL:
                    shuttle_suppressed_mods &= ~MOD_BIT(KC_LCTL);
                    break;
                case KC_RCTL:
                    shuttle_suppressed_mods &= ~MOD_BIT(KC_RCTL);
                    break;
                default:
                    break;
            }
        } else if (keycode != KC_LSFT && keycode != KC_RSFT && keycode != KC_LCTL && keycode != KC_RCTL) {
            shuttle_restore_mods();
        }
    }

    if (f18_active && record->event.pressed && keycode != KC_F18) {
        f18_active = false;
    }

    const bool is_key_ev = IS_KEYEVENT(record->event);
    const bool is_lt2    = is_key_ev && record->event.key.row == 4 && record->event.key.col == 5;
    const bool is_rt2    = is_key_ev && record->event.key.row == 10 && record->event.key.col == 5;

    if (record->event.pressed && !is_lt2 && !is_rt2) {
        if (lt2_phys_held) {
            lt2_used_with_other_key = true;
        }
        if (rt2_thumb_armed) {
            rt2_used_with_other_key = true;
        }
        if (active_effective_mode == POINTING_MODE_TAB_CRUISER && keycode != EH_USR3) {
            tab_cruiser_key_suppress_ms = timer_read();
            tab_cruiser_suppress_active = true;
            tab_cruiser_armed           = false;
            tab_cruiser_deadzone_x      = 0;
            tab_cruiser_accum_x         = 0;
        }
    }

    /* Fast 2 ms auto-clear of Caps/Scroll Lock on LT2, Esc, M(3), M(4) */
    if (record->event.pressed &&
        (is_lt2 || keycode == KC_ESC || keycode == QK_MACRO + 3 || keycode == QK_MACRO + 4)) {
        fast_clear_lock_leds();
    }

    /* LG_WORD termination on Space, Enter, Esc, or unshifted Minus (while preserving S(KC_MINS) = '_') */
    if (eng_word_active && record->event.pressed) {
        bool shift_now = ((get_mods() | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) != 0 || is_caps_word_on();
        if (keycode == KC_SPC || keycode == KC_ENT || keycode == KC_ESC ||
            (keycode == KC_MINS && !shift_now)) {
            eng_word_active = false;
            caps_word_off();
            (void)process_record_ruen(LG_SET_RU, record);
        }
    }

    /* Dual-thumb chords (LT2 <-> RT2) & instant spring-latch TT(1) / TT(3) */
    if (is_lt2) {
        if (record->event.pressed) {
            if (rt2_thumb_armed) {
                rt2_used_with_other_key = true;
                lt2_chord_mo4           = true;
                lt2_phys_held           = true;
                layer_on(4);
                return false;
            }
            uint8_t  cur_layer = get_highest_layer(layer_state | default_layer_state);
            uint16_t raw_kc    = keymap_key_to_keycode(layer_switch_get_layer(record->event.key), record->event.key);
            if (raw_kc == TT(1)) {
                lt2_phys_held           = true;
                lt2_was_tt1             = (cur_layer == 0) && !layer_state_is(1);
                lt2_used_with_other_key = false;
                lt2_press_timer         = timer_read();
                layer_on(1);
                return false;
            } else if (raw_kc == TO(1)) {
                lt2_phys_held           = true;
                lt2_was_tt1             = false;
                lt2_used_with_other_key = false;
                if (!sticky_override_active || sticky_override_layer != 1) {
                    sticky_override_active = false;
                }
                momentary_override_active = false;
                override_pressed_keycode  = KC_NO;
                layer_move(1);
                sync_pointing_mode_for_state(layer_state | default_layer_state);
                return false;
            }
        } else {
            if (lt2_chord_mo4) {
                lt2_chord_mo4 = false;
                lt2_phys_held = false;
                layer_off(4);
                return false;
            }
            if (lt2_phys_held) {
                lt2_phys_held = false;
                if (lt2_was_tt1) {
                    lt2_was_tt1 = false;
                    if (lt2_used_with_other_key || timer_elapsed(lt2_press_timer) >= get_tapping_term(TT(1), record)) {
                        layer_off(1);
                    }
                }
                return false;
            }
        }
    }

    if (is_rt2) {
        if (record->event.pressed) {
            if (lt2_phys_held) {
                lt2_used_with_other_key = true;
                rt2_chord_mo5           = true;
                rt2_thumb_armed         = true;
                layer_on(5);
                return false;
            }
            uint8_t cur_layer = get_highest_layer(layer_state | default_layer_state);
            if (cur_layer != 2) {
                uint16_t raw_kc = keymap_key_to_keycode(layer_switch_get_layer(record->event.key), record->event.key);
                if (raw_kc == TT(3)) {
                    rt2_thumb_armed         = true;
                    rt2_was_tt3             = !layer_state_is(3);
                    rt2_used_with_other_key = false;
                    rt2_press_timer         = timer_read();
                    layer_on(3);
                    return false;
                } else if (raw_kc == TO(3)) {
                    rt2_thumb_armed         = true;
                    rt2_was_tt3             = false;
                    rt2_used_with_other_key = false;
                    if (!sticky_override_active || sticky_override_layer != 3) {
                        sticky_override_active = false;
                    }
                    momentary_override_active = false;
                    override_pressed_keycode  = KC_NO;
                    layer_move(3);
                    sync_pointing_mode_for_state(layer_state | default_layer_state);
                    return false;
                } else if (raw_kc == KC_NO) {
                    rt2_thumb_armed = true;
                    rt2_was_tt3     = false;
                    return false;
                }
            }
        } else {
            if (rt2_chord_mo5) {
                rt2_chord_mo5   = false;
                rt2_thumb_armed = false;
                layer_off(5);
                return false;
            }
            if (rt2_thumb_armed) {
                rt2_thumb_armed = false;
                if (rt2_was_tt3) {
                    rt2_was_tt3 = false;
                    if (rt2_used_with_other_key || timer_elapsed(rt2_press_timer) >= get_tapping_term(TT(3), record)) {
                        layer_off(3);
                    }
                }
                return false;
            }
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (zoom_ctrl_active && record->event.pressed) {
        zoom_release_ctrl();
    }

    if (IS_QK_TO(keycode)) {
        if (record->event.pressed) {
            uint8_t target = QK_TO_GET_LAYER(keycode);
            if (!sticky_override_active || target != sticky_override_layer) {
                sticky_override_active = false;
            }
            momentary_override_active = false;
            override_pressed_keycode  = KC_NO;
            sync_pointing_mode_for_state(layer_state | default_layer_state);
        }
        return true;
    }

    switch (keycode) {
        /* M(3) / M(4) / language keys clear eng_word_active */
        case QK_MACRO + 3:
        case QK_MACRO + 4:
        case LG_SET_RU:
        case LG_SET_EN:
        case LG_TOGGLE:
        case LG_SYNC:
            if (record->event.pressed) {
                eng_word_active = false;
            }
            return true;

        /* M(6) = Exit + LG_WORD: preserve Caps Word / Shift and clear Shift mods cleanly */
        case QK_MACRO + 6:
            if (record->event.pressed) {
                m6_had_caps = is_caps_word_on() || (((get_mods() | get_oneshot_mods() | get_weak_mods()) & MOD_MASK_SHIFT) != 0);
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                }
                if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                }
            }
            return true;

        /* Custom LG_WORD handler: preserves '_' (S(KC_MINS)), Caps Word, and lights 14: ENG */
        case LG_WORD:
            if (record->event.pressed) {
                bool want_caps = m6_had_caps || is_caps_word_on() || (((get_mods() | get_oneshot_mods() | get_weak_mods()) & MOD_MASK_SHIFT) != 0);
                m6_had_caps    = false;
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                }
                if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                }
                if (get_cur_lang() == LANG_RU && !eng_word_active) {
                    eng_word_active = true;
                    (void)process_record_ruen(LG_SET_EN, record);
                }
                if (want_caps) {
                    caps_word_on();
                }
            }
            return false;

        /* KC_F18: Tap = Panorama (Ctrl+Alt+Tab), Hold >= 350 ms = Lock (Win+L) */
        case KC_F18:
            if (record->event.pressed) {
                f18_timer  = timer_read();
                f18_active = true;
                f18_fired  = false;
            } else {
                if (f18_active && !f18_fired) {
                    tap_code16(CA(KC_TAB));
                }
                f18_active = false;
            }
            return false;

        /* KC_F20: Em-dash '—' (Alt + KP_0 KP_1 KP_5 KP_1) */
        case KC_F20:
            if (record->event.pressed) {
                uint8_t saved_mods = get_mods();
                if (saved_mods) {
                    del_mods(saved_mods);
                }
                clear_weak_mods();
                bool restore_num = !host_keyboard_led_state().num_lock;
                if (restore_num) {
                    tap_code(KC_NUM_LOCK);
                    wait_ms(5);
                }
                register_code(KC_LALT);
                tap_code(KC_KP_0);
                tap_code(KC_KP_1);
                tap_code(KC_KP_5);
                tap_code(KC_KP_1);
                unregister_code(KC_LALT);
                if (restore_num) {
                    wait_ms(5);
                    tap_code(KC_NUM_LOCK);
                }
                if (saved_mods) {
                    add_mods(saved_mods);
                }
            }
            return false;

        /* 6: SYS LED Brightness Presets (KC_F21..KC_F24) */
        case KC_F21:
        case KC_F22:
        case KC_F23:
            if (record->event.pressed) {
                uint8_t target_bri    = (keycode == KC_F21) ? 28 : ((keycode == KC_F22) ? 128 : 255);
                contrast_mode_active  = false;
                set_led_rgb_brightness(target_bri);
                last_seen_entropy_bri = target_bri;
                refresh_user_rgb_segments();
            }
            return false;

        case KC_F24:
            if (record->event.pressed) {
                contrast_mode_active = !contrast_mode_active;
                refresh_user_rgb_segments();
            }
            return false;

        /* Right 38-mm Trackball Modes + Adjacent Chord EH_TXT + EH_USR1 = "Включить Мышь" */
        case EH_SNP:
        case EH_SCR:
        case EH_TXT:
        case EH_USR1:
        case EH_USR2:
        case EH_USR3: {
            if (keycode == EH_TXT) {
                eh_txt_held = record->event.pressed;
            } else if (keycode == EH_USR1) {
                eh_usr1_held = record->event.pressed;
            }

            if (eh_txt_held && eh_usr1_held) {
                chord_mouse_reset         = true;
                sticky_override_active    = false;
                momentary_override_active = false;
                override_pressed_keycode  = KC_NO;
                zoom_release_ctrl();
                shuttle_restore_mods();
                sync_pointing_mode_for_state(layer_state | default_layer_state);
                return false;
            }

            const pointing_mode_t target_mode = (pointing_mode_t)(POINTING_MODE_SNIPER + (keycode - EH_SNP));
            if (record->event.pressed) {
                if (!chord_mouse_reset) {
                    momentary_override_active = true;
                    momentary_override_mode   = target_mode;
                    override_press_timer      = timer_read();
                    override_pressed_keycode  = keycode;
                    sync_pointing_mode_for_state(layer_state | default_layer_state);
                }
            } else {
                if (chord_mouse_reset) {
                    if (!eh_txt_held && !eh_usr1_held) {
                        chord_mouse_reset = false;
                    }
                    momentary_override_active = false;
                    override_pressed_keycode  = KC_NO;
                    sync_pointing_mode_for_state(layer_state | default_layer_state);
                    return false;
                }

                if (override_pressed_keycode == keycode) {
                    momentary_override_active = false;
                    override_pressed_keycode  = KC_NO;
                    /* EH_USR1 (Ball Zoom) is strictly spring-only; all other ball modes latch ON (never toggle off!) */
                    if (keycode != EH_USR1 && timer_elapsed(override_press_timer) < get_tapping_term(keycode, record)) {
                        uint8_t cur_layer = get_highest_layer(layer_state | default_layer_state);
                        if (cur_layer != 0) {
                            sticky_override_active = true;
                            sticky_override_mode   = target_mode;
                            sticky_override_layer  = cur_layer;
                        }
                    }
                }
                sync_pointing_mode_for_state(layer_state | default_layer_state);
            }
            return false;
        }

        default:
            break;
    }

    return true;
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    report_mouse_t mrpt = pointing_device_task_user(mouse_report);

    if (active_effective_mode == POINTING_MODE_ZOOM) {
        uint8_t held_buttons = mrpt.buttons;
#ifdef MOUSEKEY_ENABLE
        held_buttons |= mousekey_get_report().buttons;
#endif
        int32_t raw_v = -(int32_t)mrpt.y;
        mrpt.x        = 0;
        mrpt.y        = 0;
        mrpt.h        = 0;
        mrpt.v        = 0;

        if (held_buttons != 0) {
            zoom_release_ctrl();
            return mrpt;
        }

        if (raw_v != 0) {
            if ((raw_v > 0 && zoom_accum_counts < 0) || (raw_v < 0 && zoom_accum_counts > 0)) {
                zoom_accum_counts = 0;
            }
            zoom_accum_counts += raw_v;

            int32_t step_counts = (int32_t)MAX((uint8_t)1, get_scroll_sens()) * ZOOM_TICKS_PER_STEP;
            int8_t  step        = 0;
            if (zoom_accum_counts >= step_counts) {
                step              = 1;
                zoom_accum_counts = zoom_accum_counts % step_counts;
            } else if (zoom_accum_counts <= -step_counts) {
                step              = -1;
                zoom_accum_counts = zoom_accum_counts % step_counts;
            }

            if (step != 0) {
                if (!zoom_ctrl_active || !(get_weak_mods() & MOD_BIT(KC_LCTL))) {
                    add_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();
                    wait_ms(2);
                    zoom_ctrl_active = true;
                }
                zoom_last_tick_timer = timer_read();
#ifdef POINTING_DEVICE_HIRES_SCROLL_ENABLE
                mrpt.v = (mouse_hv_report_t)(step * (usb_hires_scroll_v_enabled() ? 120 : 1));
#else
                mrpt.v = step;
#endif
            }
        }
        return mrpt;
    }

    if (active_effective_mode == POINTING_MODE_SHUTTLE) {
        int32_t dx = mrpt.x;
        mrpt.x     = 0;
        mrpt.y     = 0;
        mrpt.h     = 0;
        mrpt.v     = 0;

        if (dx == 0) {
            if (shuttle_accum_x != 0 && timer_elapsed(shuttle_last_motion_ms) >= 200) {
                shuttle_accum_x = 0;
            }
            return mrpt;
        }

        if ((dx > 0 && shuttle_accum_x < 0) || (dx < 0 && shuttle_accum_x > 0)) {
            shuttle_accum_x = 0;
        }
        shuttle_last_motion_ms = timer_read();
        shuttle_accum_x += dx;

        int32_t div   = (int32_t)MAX((uint8_t)4, get_text_sens());
        int32_t steps = shuttle_accum_x / div;
        if (steps != 0) {
            shuttle_accum_x -= steps * div;
            int32_t count = abs(steps);
            if (count > 2) {
                count           = 2;
                shuttle_accum_x = 0;
            }

            uint8_t fine_mods = (get_mods() | shuttle_suppressed_mods) & (MOD_MASK_SHIFT | MOD_MASK_CTRL);
            if (fine_mods != 0) {
                if ((get_mods() & (MOD_MASK_SHIFT | MOD_MASK_CTRL)) != 0) {
                    shuttle_suppressed_mods |= get_mods() & (MOD_MASK_SHIFT | MOD_MASK_CTRL);
                    del_mods(MOD_MASK_SHIFT | MOD_MASK_CTRL);
                    clear_weak_mods();
                    send_keyboard_report();
                } else {
                    clear_weak_mods();
                }
                shuttle_last_step_ms = timer_read();
                uint16_t fine_kc     = (steps > 0) ? KC_DOT : KC_COMM;
                for (int32_t i = 0; i < count; ++i) {
                    tap_code(fine_kc);
                }
            } else {
                uint16_t coarse_kc = (steps > 0) ? KC_RGHT : KC_LEFT;
                for (int32_t i = 0; i < count; ++i) {
                    tap_code(coarse_kc);
                }
            }
        }
        return mrpt;
    }

    if (active_effective_mode == POINTING_MODE_TAB_CRUISER) {
        int32_t dx = mrpt.x;
        mrpt.x     = 0;
        mrpt.y     = 0;
        mrpt.h     = 0;
        mrpt.v     = 0;

        if (tab_cruiser_suppress_active) {
            if (timer_elapsed(tab_cruiser_key_suppress_ms) < TAB_CRUISER_KEY_SUPPRESS_MS) {
                return mrpt;
            }
            tab_cruiser_suppress_active = false;
        }

        if (dx == 0) {
            if ((tab_cruiser_armed || tab_cruiser_deadzone_x != 0) &&
                timer_elapsed(tab_cruiser_last_motion_ms) >= TAB_CRUISER_REST_RESET_MS) {
                tab_cruiser_armed      = false;
                tab_cruiser_deadzone_x = 0;
                tab_cruiser_accum_x    = 0;
            }
            return mrpt;
        }

        tab_cruiser_last_motion_ms = timer_read();

        if (!tab_cruiser_armed) {
            if ((dx > 0 && tab_cruiser_deadzone_x < 0) || (dx < 0 && tab_cruiser_deadzone_x > 0)) {
                tab_cruiser_deadzone_x = 0;
            }
            tab_cruiser_deadzone_x += dx;
            if (abs(tab_cruiser_deadzone_x) >= TAB_CRUISER_DEADZONE_COUNTS) {
                tab_cruiser_armed = true;
                if (tab_cruiser_deadzone_x > 0) {
                    tab_cruiser_accum_x = tab_cruiser_deadzone_x - TAB_CRUISER_DEADZONE_COUNTS;
                    tap_code16(C(KC_TAB));
                } else {
                    tab_cruiser_accum_x = tab_cruiser_deadzone_x + TAB_CRUISER_DEADZONE_COUNTS;
                    tap_code16(CS(KC_TAB));
                }
                tab_cruiser_deadzone_x = 0;
            }
            return mrpt;
        }

        if ((dx > 0 && tab_cruiser_accum_x < 0) || (dx < 0 && tab_cruiser_accum_x > 0)) {
            tab_cruiser_accum_x = 0;
        }
        tab_cruiser_accum_x += dx;

        if (tab_cruiser_accum_x >= TAB_CRUISER_STEP_COUNTS) {
            tab_cruiser_accum_x = tab_cruiser_accum_x % TAB_CRUISER_STEP_COUNTS;
            tap_code16(C(KC_TAB));
        } else if (tab_cruiser_accum_x <= -TAB_CRUISER_STEP_COUNTS) {
            tab_cruiser_accum_x = tab_cruiser_accum_x % TAB_CRUISER_STEP_COUNTS;
            tap_code16(CS(KC_TAB));
        }
        return mrpt;
    }

    return mrpt;
}
