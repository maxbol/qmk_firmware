/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

enum planck_keycodes { PLOVER = SAFE_RANGE, BACKLIT, EXT_PLV, LBRC_EQL, ARROW_NOT };

// enum { TD_LOWER_TAB, TD_LCTRL_ENTER, TD_LSHIFT_SPACE, TD_RAISE_BS }

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LT_LOWER_TAB LT(_LOWER, KC_TAB)
#define LT_RAISE_BSPC LT(_RAISE, KC_BSPC)
#define LT_RAISE_L LT(_RAISE, KC_L)
#define LT_RAISE_S LT(_RAISE, KC_S)
#define MT_LALT_Z MT(MOD_LALT, KC_Z)
#define MT_LCTL_ENTER MT(MOD_LCTL, KC_ENTER)
#define MT_LCTL_ESC MT(MOD_LCTL, KC_ESC)
#define MT_LGUI_EQL MT(MOD_LGUI, KC_EQL)
#define MT_LGUI_F MT(MOD_LGUI, KC_F)
#define MT_LGUI_J MT(MOD_LGUI, KC_J)
#define MT_LSFT_D MT(MOD_LSFT, KC_D)
#define MT_LSFT_K MT(MOD_LSFT, KC_K)
#define MT_LSFT_SLSH MT(MOD_LSFT, KC_SLSH)
#define MT_LSFT_SPC MT(MOD_LSFT, KC_SPC)
#define MT_RGUI_LPRN MT(MOD_RGUI, KC_LPRN)
#define MT_RSFT_RPRN MT(MOD_RSFT, KC_RPRN)

const uint16_t PROGMEM lbrc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM lbrk_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM rbrk_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM rbrk_combo2[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM eql_combo[]  = {KC_P, KC_LBRC, COMBO_END};

combo_t key_combos[] = {
    COMBO(lbrc_combo, LSFT(KC_LBRC)),
    COMBO(rbrc_combo, LSFT(KC_RBRC)),
    COMBO(lbrk_combo, KC_LBRC),
    COMBO(rbrk_combo, KC_RBRC),
    COMBO(rbrk_combo2, KC_RBRC),
    COMBO(eql_combo, KC_EQL),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_LSFT_SPC:
            return 120;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_LSFT_SPC:
            return false;
        default:
            return true;
    }
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_planck_grid('L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', '*', '*', '*', '*', 'R', 'R', 'R', 'R');

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `---------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_MINS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
    MT_LCTL_ESC,  KC_A,    LT_RAISE_S,    KC_D,    MT_LGUI_F,    KC_G,    KC_H,    MT_LGUI_J,    KC_K,    LT_RAISE_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, MT_LALT_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_EQL, KC_EQL, KC_EQL, KC_EQL, LT_LOWER_TAB, MT_LCTL_ENTER, MT_LSFT_SPC, LT_RAISE_BSPC, KC_BRID, KC_BRIU, KC_VOLD,   KC_VOLU
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    KC_RBRC,
    _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT,KC_EQL, LSFT(KC_EQL),
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MPRV,    KC_MNXT, KC_MUTE, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_GRV, S(KC_COMM), S(KC_DOT), KC_MINS,  KC_PIPE, KC_CIRC, S(KC_LBRC), S(KC_RBRC), KC_DLR, ARROW_NOT,   _______,
    _______, KC_EXLM, KC_ASTR,   KC_BSLS, KC_EQL,  KC_AMPR, KC_HASH, KC_LPRN,  KC_RPRN, KC_SCLN, KC_QUOT,    _______,
    _______, KC_TILD, S(KC_EQL), KC_LBRC, KC_RBRC, KC_PERC, KC_AT,   S(KC_SCLN), KC_COMM, KC_DOT,  S(KC_QUOT), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef ENCODER_MAP_ENABLE
/* Rotary Encoders
 */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    /* Qwerty
     *    v- (index) Clockwise / Counter Clockwise                        v- (index) Clockwise / Counter Clockwise
     * ,---------------------------------------------------------------------------------------.
     * | (0) Vol-    / Vol+    |   |   |   |   |   |   |   |   |   |   | (4) Vol-    / Vol+    |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (1) KC_MNXT / KC_MPRV |   |   |   |   |   |   |   |   |   |   | (5) KC_MNXT / KC_MPRV |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (2) KC_WBAK / KC_WFWD |   |   |   |   |   |   |   |   |   |   | (6) KC_SPC  / KC_ENT  |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (3) KC_LEFT / KC_RGHT |   |   |   |   |       |   |   |   |   | (7) KC_DOWN / KC_UP   |
     * `---------------------------------------------------------------------------------------'
     */
    [_QWERTY] = {
        // LEFT SIDE (index 0 to 3)
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(KC_MNXT, KC_MPRV),
        ENCODER_CCW_CW(KC_WBAK, KC_WFWD),
        ENCODER_CCW_CW(KC_LEFT, KC_RGHT),
        // RIGHT SIDE (index 4 to 7)
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(KC_MNXT, KC_MPRV),
        ENCODER_CCW_CW(KC_SPC,  KC_ENT),
        ENCODER_CCW_CW(KC_DOWN, KC_UP)
    },

    /* Adjust (Lower + Raise)
     *    v- (index) Clockwise / Counter Clockwise                        v- (index) Clockwise / Counter Clockwise
     * ,---------------------------------------------------------------------------------------.
     * | (0) _______ / _______ |   |   |   |   |   |   |   |   |   |   | (4) _______ / _______ |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (1) _______ / _______ |   |   |   |   |   |   |   |   |   |   | (5) _______ / _______ |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (2) UG_NEXT / UG_PREV |   |   |   |   |   |   |   |   |   |   | (6) SAT- / SAT+       |
     * |-----------------------+---+---+---+---+---+---+---+---+---+---+-----------------------|
     * | (3) UG_VALD / UG_VALU |   |   |   |   |       |   |   |   |   | (7) HUE- / HUE+       |
     * `---------------------------------------------------------------------------------------'
     */
    [_ADJUST] = {
        // LEFT SIDE (index 0 to 3)
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(UG_NEXT, UG_PREV),
        ENCODER_CCW_CW(UG_VALD, UG_VALU),
        // RIGHT SIDE (index 4 to 7)
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(UG_SATD,  UG_SATU),
        ENCODER_CCW_CW(UG_HUEU,  UG_HUED)
    }
};
#endif
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool play_encoder_melody(uint8_t index, bool clockwise);

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint8_t mod_state;
bool    process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
#ifdef ENCODER_MAP_ENABLE
    if (IS_ENCODEREVENT(record->event) && record->event.pressed) {
        play_encoder_melody(record->event.key.col, record->event.type == ENCODER_CCW_EVENT);
    }
#endif
    switch (keycode) {
        case ARROW_NOT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING("->");
                    set_mods(mod_state);
                } else {
                    SEND_STRING("=>");
                }
            }
            return true;
            break;
        case LBRC_EQL:
            if (mod_state & MOD_MASK_SHIFT) {
                if (record->event.pressed) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_EQL);
                    set_mods(mod_state);
                } else {
                    unregister_code(KC_EQL);
                }
            } else {
                if (record->event.pressed) {
                    register_code(KC_LBRC);
                } else {
                    unregister_code(KC_LBRC);
                }
            }
            return false;
            break;
        case MT_RSFT_RPRN:
            if (record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case MT_RGUI_LPRN:
            if (record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float *)note = 440.0f;
    return 0;
}

bool play_encoder_melody(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return play_encoder_melody(index, clockwise);
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
