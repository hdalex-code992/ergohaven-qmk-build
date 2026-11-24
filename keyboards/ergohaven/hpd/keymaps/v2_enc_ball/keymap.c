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

#include "hid.h"
#ifdef MOUSEKEY_ENABLE
#    include "mousekey.h"
#endif

extern pointing_mode_t pointing_mode;

#define POINTING_MODE_ZOOM POINTING_MODE_USR1
#define ZOOM_TICKS_PER_STEP 3
#define ZOOM_IDLE_RELEASE_MS 120
#define LAYER15_POLL_MS 50

static pointing_mode_t active_effective_mode     = POINTING_MODE_NORMAL;
static bool            momentary_override_active = false;
static pointing_mode_t momentary_override_mode   = POINTING_MODE_NORMAL;
static uint16_t        override_press_timer      = 0;
static uint16_t        override_pressed_keycode  = KC_NO;
static bool            sticky_override_active    = false;
static pointing_mode_t sticky_override_mode      = POINTING_MODE_NORMAL;
static uint8_t         sticky_override_layer     = 0;

static bool     zoom_ctrl_active     = false;
static uint16_t zoom_last_tick_timer = 0;
static int16_t  zoom_accum           = 0;
static uint16_t layer15_poll_timer   = 0;

static void zoom_release_ctrl(void) {
    zoom_accum = 0;
    if (zoom_ctrl_active) {
        del_weak_mods(MOD_BIT(KC_LCTL));
        send_keyboard_report();
        zoom_ctrl_active = false;
        wait_ms(2);
    }
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
            default:
                break;
        }
    }
    if (layer == 4 || layer == 5) {
        return POINTING_MODE_SCROLL;
    }
    return POINTING_MODE_NORMAL;
}

static pointing_mode_t hw_mode_for_effective(pointing_mode_t mode) {
    if (mode == POINTING_MODE_ZOOM) {
        return POINTING_MODE_SCROLL;
    }
    if (mode > POINTING_MODE_TEXT) {
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
        if (prev_mode == POINTING_MODE_ZOOM && next_mode != POINTING_MODE_ZOOM) {
            zoom_release_ctrl();
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
    if (get_pointing_mode() != POINTING_MODE_NORMAL) {
        set_pointing_mode(POINTING_MODE_NORMAL);
    }
    layer15_poll_timer = timer_read();
    sync_pointing_mode_for_state(layer_state | default_layer_state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    sync_pointing_mode_for_state(layer_state | state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    sync_pointing_mode_for_state(state | default_layer_state);
    return state;
}

void housekeeping_task_user(void) {
    if (zoom_ctrl_active && timer_elapsed(zoom_last_tick_timer) >= ZOOM_IDLE_RELEASE_MS) {
        zoom_release_ctrl();
    }
    if (timer_elapsed(layer15_poll_timer) >= LAYER15_POLL_MS) {
        layer15_poll_timer = timer_read();
        sync_pointing_mode_for_state(layer_state | default_layer_state);
    }
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    (void)keycode;
    if (zoom_ctrl_active && record->event.pressed) {
        zoom_release_ctrl();
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (zoom_ctrl_active && record->event.pressed) {
        zoom_release_ctrl();
    }

    if (IS_QK_TO(keycode)) {
        if (record->event.pressed) {
            sticky_override_active    = false;
            momentary_override_active = false;
            override_pressed_keycode  = KC_NO;
            sync_pointing_mode_for_state(layer_state | default_layer_state);
        }
        return true;
    }

    switch (keycode) {
        case EH_SNP:
        case EH_SCR:
        case EH_TXT:
        case EH_USR1:
        case EH_USR2:
        case EH_USR3: {
            const pointing_mode_t target_mode = (pointing_mode_t)(POINTING_MODE_SNIPER + (keycode - EH_SNP));
            if (record->event.pressed) {
                momentary_override_active = true;
                momentary_override_mode   = target_mode;
                override_press_timer      = timer_read();
                override_pressed_keycode  = keycode;
                sync_pointing_mode_for_state(layer_state | default_layer_state);
            } else {
                if (override_pressed_keycode == keycode) {
                    momentary_override_active = false;
                    override_pressed_keycode  = KC_NO;
                    if (timer_elapsed(override_press_timer) < get_tapping_term(keycode, record)) {
                        uint8_t cur_layer = get_highest_layer(layer_state | default_layer_state);
                        if (cur_layer != 0) {
                            if (sticky_override_active &&
                                sticky_override_layer == cur_layer &&
                                sticky_override_mode == target_mode) {
                                sticky_override_active = false;
                            } else {
                                sticky_override_active = true;
                                sticky_override_mode   = target_mode;
                                sticky_override_layer  = cur_layer;
                            }
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
        if (held_buttons != 0) {
            zoom_release_ctrl();
            mrpt.h = 0;
            mrpt.v = 0;
            return mrpt;
        }

        int16_t raw_v = mrpt.v;
        if (get_invert_scroll()) {
            raw_v = -raw_v;
        }
        mrpt.h = 0;
        mrpt.v = 0;

        if (raw_v != 0) {
            if ((raw_v > 0 && zoom_accum < 0) || (raw_v < 0 && zoom_accum > 0)) {
                zoom_accum = 0;
            }
            zoom_accum += raw_v;

            int8_t step = 0;
            if (zoom_accum >= ZOOM_TICKS_PER_STEP) {
                step       = 1;
                zoom_accum = zoom_accum % ZOOM_TICKS_PER_STEP;
            } else if (zoom_accum <= -ZOOM_TICKS_PER_STEP) {
                step       = -1;
                zoom_accum = zoom_accum % ZOOM_TICKS_PER_STEP;
            }

            if (step != 0) {
                if (!zoom_ctrl_active || !(get_weak_mods() & MOD_BIT(KC_LCTL))) {
                    add_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();
                    wait_ms(2);
                    zoom_ctrl_active = true;
                }
                zoom_last_tick_timer = timer_read();
                mrpt.v               = step;
            }
        }
    }

    return mrpt;
}
