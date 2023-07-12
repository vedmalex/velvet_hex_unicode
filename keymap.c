#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"
#include "keymap_russian.h"

#define RESET QK_BOOT

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_ALT MO(_ALT)

#define DF_RU DF(_RU)
#define DF_EN DF(_EN) oklkjyuuoynmnjnjh
#define DF_MOUSE TG(_MOUSE)

#define QUOT S(KC_GRV)
#define PIPE S(KC_BSLS)
#define DPIPE S(RALT(KC_BSLS))
#define SCLN S(KC_LBRC)
#define CLN S(KC_RBRC)
#define GRV RALT(KC_GRV)
#define BSL RALT(KC_BSLS)

#define SPACE_L C(G(KC_LEFT))
#define SPC_R C(G(KC_RGHT))

#define TAB_L C(S(KC_TAB))
#define TAB_R C(KC_TAB)

#define LSW C(KC_SPC)

enum layers {
    _EN,
    _RU,
    _SYM,
    _NAV,
    _NUM,
    _ALT,
    _MOUSE,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,       // Switch to next window         (alt-tab)
    SW_TAB,       // Switch to next browser tab    (ctrl-tab)
    SW_LANG,      // Switch layout in macos (ctrl-space)
    SW_UNDO_REDO, // ctrl+z
    SW_FORWARD,   // ctrl + -
    SAVE,         // CMD+S
    CUT,          // CMD+X
    COPY,         // CMD+C
    PASTE,        // CMD+V
    SELECT_ALL,   // CMD+A
    JS_ARROW,     // =>
};

#define KC_DQT S(KC_QUOT)
#define KC_USCR S(KC_MINS)
#define KC_CLN S(KC_SCLN)
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_EN] = LAYOUT_all(
      KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
      KC_A,    KC_S,   KC_D,   KC_F,   KC_G,          KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,
      KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,          KC_N,   KC_M,S(KC_7),KC_LBRC,KC_RBRC,
           DF_MOUSE,SW_LANG, KC_SPC, LA_NAV,        LA_SYM,KC_LSFT, LA_ALT,  DF_RU
    ),

    [_RU] = LAYOUT_all(
    _______,_______,_______,_______,_______,       _______,_______,_______,  RU_ZE,  RU_HA,
    _______,_______,_______,_______,_______,       _______,_______,_______,_______, RU_ZHE,
    _______,_______,_______,_______,_______,       _______,_______,  RU_BE,  RU_YU,   RU_E,
            _______,_______,_______,_______,       _______,_______,_______,  DF_EN
    ),

    [_SYM] = LAYOUT_all(
    KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,       KC_CIRC,KC_QUES,KC_ASTR,KC_LPRN,KC_RPRN,
    KC_TILD, KC_GRV,KC_QUOT, KC_DQT,KC_MINS,       KC_PLUS,OS_SHFT,OS_CTRL, OS_ALT, OS_CMD,
    KC_BSLS,KC_PIPE,KC_SCLN,KC_COMM,KC_USCR,        KC_EQL, KC_DOT, KC_CLN,KC_PIPE,KC_SLSH,
            _______,_______,_______,_______,       _______,_______,_______,_______
    ),

    [_NAV] = LAYOUT_all(
     SW_TAB, SW_WIN,  TAB_L,  TAB_R, KC_GRV,        KC_ESC,KC_HOME, KC_END,KC_BSPC, KC_DEL,
     OS_CMD, OS_ALT,OS_CTRL,OS_SHFT, KC_ENT,        KC_ENT,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,
    SPACE_L,  SPC_R,_______,KC_PSCR, KC_TAB,        KC_TAB,KC_PGUP,KC_PGDN,XXXXXXX,XXXXXXX,
            _______,_______,_______,_______,       _______,_______,_______,_______
    )

    [_NUM] = LAYOUT_all(
      KC_P1,  KC_P2,  KC_P3,  KC_P4,  KC_P5,         KC_P6,  KC_P7,  KC_P8,  KC_P9,  KC_P0,
     OS_CMD, OS_ALT,OS_CTRL,OS_SHFT, KC_F11,        KC_F12,OS_SHFT,OS_CTRL, OS_ALT, OS_CMD,
      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,         KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,
            _______,_______,_______,_______,       _______,_______,_______,_______
    ),

    [_ALT] = LAYOUT_all(
    _______,_______,_______,_______,  RU_YO,       _______,_______,RU_SHCH,_______,_______,
    _______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,       _______,RU_HARD,_______,_______,_______,
            _______,_______,_______,_______,       _______,_______,_______,_______
    ),

    [_MOUSE] = LAYOUT_all(
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  RESET,       KC_BTN1,KC_BTN2,KC_BTN3,KC_BTN4,KC_BTN5,
    KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,XXXXXXX,       XXXXXXX,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            _______,_______,_______,_______,       _______,_______,_______,_______
    ),
};
// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT, keycode, record);
    update_swapper(&sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT, keycode, record);
    // update_swapper(&sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT, keycode, record);
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    switch (keycode) {
        case SW_LANG: {
            if (record->event.pressed) {
                if (get_highest_layer(layer_state) == _EN) {
                    layer_clear();
                    layer_on(_RU);
                } else {
                    layer_clear();
                    layer_on(_EN);
                }
                register_code(KC_LCTL);
                SEND_STRING_DELAY(" ", 100);
                unregister_code(KC_LCTL);
            }
            return false;
        }
            // case JS_ARROW: {
            //     if (record->event.pressed) {
            //         SEND_STRING("=>");
            //     }
            //     return false;
            // }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

void keyboard_pre_init_user(void) {
    set_single_persistent_default_layer(_EN);
}
