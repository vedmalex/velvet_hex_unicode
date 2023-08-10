#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"
#include "keymap_russian.h"

#define RESET QK_BOOT

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_NUM MO(_NUM)
#define LA_EDIT MO(_EDIT)
#define LA_MOUSE MO(_MOUSE)

#define DF_RU DF(_RU)
#define DF_EN DF(_EN)
#define DF_MOUS TG(_MOUSE)

#define QUOT S(KC_GRV)
#define PIPE S(KC_BSLS)
#define DPIPE S(A(KC_BSLS))
#define SCLN S(KC_LBRC)
#define CLN S(KC_RBRC)
#define GRV RALT(KC_GRV)
#define BSL RALT(KC_BSLS)

#define SPACE_L C(G(KC_LEFT))
#define SPC_R C(G(KC_RGHT))

#define NAV_SPC TD(0) // nav layer + space
#define NUM_TAB TD(1) // num layer + tab
#define EDT_ESC TD(2) // tab + edit layer
#define SYM_SPC TD(3) // sym layer + space
#define TAB_SHF TD(4) // tab + shift
#define ESC_ALT TD(5) // esc + alt
#define CAP_MSE TD(6) // caps lock + mouse

enum layers { _QWERTY, _SYM, _NAV, _NUM, _MOUSE, _EDIT };

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = QK_KB_0,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    ALT_TAB, // Switch to next window         (alt-tab)
    GUI_TAB, // Switch to next browser tab    (gui-tab)
    CTL_TAB, // Switch to next browser tab    (ctrl-tab)
    S_LANG,  // Switch layout in macos (ctrl-space)
    S_UN_RE, // ctrl+z
    S_FWD,   // ctrl + -
    SAVE,    // CMD+S
    CUT,     // CMD+X
    COPY,    // CMD+C
    PASTE,   // CMD+V
    SEL_ALL, // CMD+A
    CMD_D,
};

// clang-format off
const uint16_t
PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
      KC_A,    KC_S,   KC_D,   KC_F,   KC_G,          KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,
      KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,          KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,
            CAP_MSE,EDT_ESC,NUM_TAB,NAV_SPC,       SYM_SPC,TAB_SHF,ESC_ALT,CAP_MSE
            //KC_ESC,LA_EDIT, KC_SPC, LA_NAV,        LA_SYM,KC_LSFT,KC_LALT,KC_CAPS
    )
    ,
    [_SYM] = LAYOUT(
       KC_1,   KC_2,   KC_3,   KC_4,   KC_5,          KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
    KC_SCLN,    GRV, KC_GRV,   QUOT,KC_MINS,       KC_PLUS,OS_SHFT,OS_CTRL, OS_ALT, OS_CMD,
        BSL,  DPIPE,   SCLN,KC_LBRC,KC_UNDS,        KC_EQL,KC_RBRC,    CLN,   PIPE,KC_BSLS,
            _______,_______,_______,_______,       _______,_______,_______,_______
    )
    ,
    [_NAV] = LAYOUT(
    GUI_TAB,ALT_TAB,CTL_TAB, S_LANG, KC_ESC,        KC_ESC,KC_HOME, KC_END,KC_BSPC, KC_DEL,
     OS_CMD, OS_ALT,OS_CTRL,OS_SHFT, KC_ENT,        KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_ENT,
    SPACE_L,  SPC_R,DF_MOUS,KC_PSCR, KC_TAB,        KC_TAB,KC_PGUP,KC_PGDN,XXXXXXX,XXXXXXX,
            _______,_______,_______,_______,       _______,_______,_______,_______
    )
    ,
    [_NUM] = LAYOUT(
      KC_P1,  KC_P2,  KC_P3,  KC_P4,  KC_P5,         KC_P6,  KC_P7,  KC_P8,  KC_P9,  KC_P0,
     OS_CMD, OS_ALT,OS_CTRL,OS_SHFT, KC_F11,        KC_F12,OS_SHFT,OS_CTRL, OS_ALT, OS_CMD,
      KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,         KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,
            _______,_______,_______,_______,       _______,_______,_______,_______
    )
    ,
    [_MOUSE] = LAYOUT(
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  RESET,       KC_BTN1,KC_BTN2,KC_BTN3,KC_BTN4,KC_BTN5,
    XXXXXXX,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,       KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,XXXXXXX,
    XXXXXXX,XXXXXXX,DF_MOUS,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            _______,_______,_______,_______,       _______,_______,_______,_______
    ),
    [_EDIT] = LAYOUT(
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    SEL_ALL,   SAVE,  CMD_D,XXXXXXX,  S_FWD,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    S_UN_RE,    CUT,   COPY,  PASTE,XXXXXXX,       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            _______,_______,_______,_______,       _______,_______,_______,_______
    ),
};
// clang-format on
//
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
        case LA_EDIT:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYM:
        case LA_NAV:
        case LA_EDIT:
        case KC_LSFT:
        case KC_LALT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool alt_tab_active    = false;
bool gui_tab_active    = false;
bool ctrl_tab_active   = false;
bool ctrl_spc_active   = false;
bool undo_red_active   = false;
bool ctrl_minus_active = false;
bool gui_d_active      = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // swappers
    update_swapper(&alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, OS_SHFT, keycode, record);
    update_swapper(&gui_tab_active, KC_LGUI, KC_TAB, GUI_TAB, OS_SHFT, keycode, record);
    update_swapper(&ctrl_tab_active, KC_LCTL, KC_TAB, CTL_TAB, OS_SHFT, keycode, record);
    update_swapper(&ctrl_spc_active, KC_LCTL, KC_SPC, S_LANG, OS_SHFT, keycode, record);
    update_swapper(&undo_red_active, KC_LCMD, KC_Z, S_UN_RE, OS_SHFT, keycode, record);
    update_swapper(&ctrl_minus_active, KC_LCTL, KC_MINS, S_FWD, OS_SHFT, keycode, record);
    update_swapper(&gui_d_active, KC_LCMD, KC_D, CMD_D, OS_SHFT, keycode, record);
    // oneshots
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    switch (keycode) {
        case SAVE: {
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("s"));
            }
            return false;
        }
        case CUT: {
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("x"));
            }
            return false;
        }
        case COPY: {
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("c"));
            }
            return false;
        }
        case PASTE: {
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
            }
            return false;
        }
        case SEL_ALL: {
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("a"));
            }
            return false;
        }
    }
    return true;
}

void keyboard_pre_init_user(void) {
    set_single_persistent_default_layer(_QWERTY);
    layer_on(_QWERTY);
}

void keyboard_post_init_user(void) {
    vial_tap_dance_entry_t TD_NAV_SPACE      = {KC_SPC, LA_NAV, KC_NO, KC_NO, TAPPING_TERM};
    vial_tap_dance_entry_t TD_NUM_TAB        = {KC_TAB, LA_NUM, KC_NO, KC_NO, TAPPING_TERM};
    vial_tap_dance_entry_t TD_EDIT_ESC       = {KC_ESC, LA_EDIT, KC_NO, KC_NO, TAPPING_TERM};
    vial_tap_dance_entry_t TD_SYM_SPACE      = {KC_SPC, LA_SYM, KC_NO, KC_NO, TAPPING_TERM};
    vial_tap_dance_entry_t TD_TAB_L_SHIFT    = {KC_TAB, KC_LSFT, KC_NO, KC_NO, TAPPING_TERM};
    vial_tap_dance_entry_t TD_ESC_ALT        = {KC_ESC, KC_LALT, KC_NO, KC_NO, TAPPING_TERM};
    vial_tap_dance_entry_t TD_CAPSLOCK_MOUSE = {KC_CAPS, LA_MOUSE, KC_NO, KC_NO, TAPPING_TERM};

    dynamic_keymap_set_tap_dance(0, &TD_NAV_SPACE);      // the first value corresponds to the TD(0) slot
    dynamic_keymap_set_tap_dance(1, &TD_NUM_TAB);        // the first value corresponds to the TD(1) slot
    dynamic_keymap_set_tap_dance(2, &TD_EDIT_ESC);       // the first value corresponds to the TD(2) slot
    dynamic_keymap_set_tap_dance(3, &TD_SYM_SPACE);      // the first value corresponds to the TD(3) slot
    dynamic_keymap_set_tap_dance(4, &TD_TAB_L_SHIFT);    // the first value corresponds to the TD(4) slot
    dynamic_keymap_set_tap_dance(5, &TD_ESC_ALT);        // the first value corresponds to the TD(5) slot
    dynamic_keymap_set_tap_dance(6, &TD_CAPSLOCK_MOUSE); // the first value corresponds to the TD(6) slot
}
