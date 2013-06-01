/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2013 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any
 * later version. Please see the file LICENSE-GPL for details.
 *
 * Web Page: http://mielke.cc/brltty/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#include "prologue.h"

#include <android/keycodes.h>

#include "sys_android.h"

#include "kbd.h"
#include "kbd_internal.h"
#include "kbd_android.h"

const unsigned char keyCodeMap[] = {
  [ANDROID_KEY_0] = KBD_KEY_SYMBOL_Zero_RightParenthesis,
  [ANDROID_KEY_1] = KBD_KEY_SYMBOL_One_Exclamation,
  [ANDROID_KEY_2] = KBD_KEY_SYMBOL_Two_At,
  [ANDROID_KEY_3] = KBD_KEY_SYMBOL_Three_Number,
  [ANDROID_KEY_3D_MODE] = 0,
  [ANDROID_KEY_4] = KBD_KEY_SYMBOL_Four_Dollar,
  [ANDROID_KEY_5] = KBD_KEY_SYMBOL_Five_Percent,
  [ANDROID_KEY_6] = KBD_KEY_SYMBOL_Six_Circumflex,
  [ANDROID_KEY_7] = KBD_KEY_SYMBOL_Seven_Ampersand,
  [ANDROID_KEY_8] = KBD_KEY_SYMBOL_Eight_Asterisk,
  [ANDROID_KEY_9] = KBD_KEY_SYMBOL_Nine_LeftParenthesis,

  [ANDROID_KEY_A] = KBD_KEY_LETTER_A,
  [ANDROID_KEY_ALT_LEFT] = KBD_KEY_FUNCTION_AltLeft,
  [ANDROID_KEY_ALT_RIGHT] = KBD_KEY_FUNCTION_AltRight,
  [ANDROID_KEY_APOSTROPHE] = KBD_KEY_SYMBOL_Apostrophe_Quote,
  [ANDROID_KEY_APP_SWITCH] = 0,
  [ANDROID_KEY_ASSIST] = KBD_KEY_FUNCTION_Help,
  [ANDROID_KEY_AT] = 0,
  [ANDROID_KEY_AVR_INPUT] = 0,
  [ANDROID_KEY_AVR_POWER] = 0,

  [ANDROID_KEY_B] = KBD_KEY_LETTER_B,
  [ANDROID_KEY_BACK] = 0,
  [ANDROID_KEY_BACKSLASH] = KBD_KEY_SYMBOL_Backslash_Bar,
  [ANDROID_KEY_BOOKMARK] = 0,
  [ANDROID_KEY_BREAK] = 0,
  [ANDROID_KEY_BUTTON_1] = 0,
  [ANDROID_KEY_BUTTON_10] = 0,
  [ANDROID_KEY_BUTTON_11] = 0,
  [ANDROID_KEY_BUTTON_12] = 0,
  [ANDROID_KEY_BUTTON_13] = 0,
  [ANDROID_KEY_BUTTON_14] = 0,
  [ANDROID_KEY_BUTTON_15] = 0,
  [ANDROID_KEY_BUTTON_16] = 0,
  [ANDROID_KEY_BUTTON_2] = 0,
  [ANDROID_KEY_BUTTON_3] = 0,
  [ANDROID_KEY_BUTTON_4] = 0,
  [ANDROID_KEY_BUTTON_5] = 0,
  [ANDROID_KEY_BUTTON_6] = 0,
  [ANDROID_KEY_BUTTON_7] = 0,
  [ANDROID_KEY_BUTTON_8] = 0,
  [ANDROID_KEY_BUTTON_9] = 0,
  [ANDROID_KEY_BUTTON_A] = 0,
  [ANDROID_KEY_BUTTON_B] = 0,
  [ANDROID_KEY_BUTTON_C] = 0,
  [ANDROID_KEY_BUTTON_L1] = 0,
  [ANDROID_KEY_BUTTON_L2] = 0,
  [ANDROID_KEY_BUTTON_MODE] = 0,
  [ANDROID_KEY_BUTTON_R1] = 0,
  [ANDROID_KEY_BUTTON_R2] = 0,
  [ANDROID_KEY_BUTTON_SELECT] = 0,
  [ANDROID_KEY_BUTTON_START] = 0,
  [ANDROID_KEY_BUTTON_THUMBL] = 0,
  [ANDROID_KEY_BUTTON_THUMBR] = 0,
  [ANDROID_KEY_BUTTON_X] = 0,
  [ANDROID_KEY_BUTTON_Y] = 0,
  [ANDROID_KEY_BUTTON_Z] = 0,

  [ANDROID_KEY_C] = KBD_KEY_LETTER_C,
  [ANDROID_KEY_CALCULATOR] = 0,
  [ANDROID_KEY_CALENDAR] = 0,
  [ANDROID_KEY_CALL] = 0,
  [ANDROID_KEY_CAMERA] = 0,
  [ANDROID_KEY_CAPS_LOCK] = KBD_KEY_LOCK_Capitals,
  [ANDROID_KEY_CAPTIONS] = 0,
  [ANDROID_KEY_CHANNEL_DOWN] = 0,
  [ANDROID_KEY_CHANNEL_UP] = 0,
  [ANDROID_KEY_CLEAR] = 0,
  [ANDROID_KEY_COMMA] = KBD_KEY_SYMBOL_Comma_Less,
  [ANDROID_KEY_CONTACTS] = 0,
  [ANDROID_KEY_CTRL_LEFT] = KBD_KEY_FUNCTION_ControlLeft,
  [ANDROID_KEY_CTRL_RIGHT] = KBD_KEY_FUNCTION_ControlRight,

  [ANDROID_KEY_D] = KBD_KEY_LETTER_D,
  [ANDROID_KEY_DEL] = KBD_KEY_FUNCTION_DeleteBackward,
  [ANDROID_KEY_DPAD_CENTER] = 0,
  [ANDROID_KEY_DPAD_DOWN] = KBD_KEY_FUNCTION_ArrowDown,
  [ANDROID_KEY_DPAD_LEFT] = KBD_KEY_FUNCTION_ArrowLeft,
  [ANDROID_KEY_DPAD_RIGHT] = KBD_KEY_FUNCTION_ArrowRight,
  [ANDROID_KEY_DPAD_UP] = KBD_KEY_FUNCTION_ArrowUp,
  [ANDROID_KEY_DVR] = 0,

  [ANDROID_KEY_E] = KBD_KEY_LETTER_E,
  [ANDROID_KEY_EISU] = 0,
  [ANDROID_KEY_ENDCALL] = 0,
  [ANDROID_KEY_ENTER] = KBD_KEY_FUNCTION_Enter,
  [ANDROID_KEY_ENVELOPE] = 0,
  [ANDROID_KEY_EQUALS] = KBD_KEY_SYMBOL_Equals_Plus,
  [ANDROID_KEY_ESCAPE] = KBD_KEY_FUNCTION_Escape,
  [ANDROID_KEY_EXPLORER] = 0,

  [ANDROID_KEY_F] = KBD_KEY_LETTER_F,
  [ANDROID_KEY_F1] = KBD_KEY_FUNCTION_F1,
  [ANDROID_KEY_F10] = KBD_KEY_FUNCTION_F10,
  [ANDROID_KEY_F11] = KBD_KEY_FUNCTION_F11,
  [ANDROID_KEY_F12] = KBD_KEY_FUNCTION_F12,
  [ANDROID_KEY_F2] = KBD_KEY_FUNCTION_F2,
  [ANDROID_KEY_F3] = KBD_KEY_FUNCTION_F3,
  [ANDROID_KEY_F4] = KBD_KEY_FUNCTION_F4,
  [ANDROID_KEY_F5] = KBD_KEY_FUNCTION_F5,
  [ANDROID_KEY_F6] = KBD_KEY_FUNCTION_F6,
  [ANDROID_KEY_F7] = KBD_KEY_FUNCTION_F7,
  [ANDROID_KEY_F8] = KBD_KEY_FUNCTION_F8,
  [ANDROID_KEY_F9] = KBD_KEY_FUNCTION_F9,
  [ANDROID_KEY_FOCUS] = 0,
  [ANDROID_KEY_FORWARD] = 0,
  [ANDROID_KEY_FORWARD_DEL] = KBD_KEY_FUNCTION_DeleteForward,
  [ANDROID_KEY_FUNCTION] = 0,

  [ANDROID_KEY_G] = KBD_KEY_LETTER_G,
  [ANDROID_KEY_GRAVE] = KBD_KEY_SYMBOL_Grave_Tilde,
  [ANDROID_KEY_GUIDE] = 0,

  [ANDROID_KEY_H] = KBD_KEY_LETTER_H,
  [ANDROID_KEY_HEADSETHOOK] = 0,
  [ANDROID_KEY_HENKAN] = 0,
  [ANDROID_KEY_HOME] = 0,

  [ANDROID_KEY_I] = KBD_KEY_LETTER_I,
  [ANDROID_KEY_INFO] = 0,
  [ANDROID_KEY_INSERT] = KBD_KEY_FUNCTION_Insert,

  [ANDROID_KEY_J] = KBD_KEY_LETTER_J,

  [ANDROID_KEY_K] = KBD_KEY_LETTER_K,
  [ANDROID_KEY_KANA] = 0,
  [ANDROID_KEY_KATAKANA_HIRAGANA] = 0,

  [ANDROID_KEY_L] = KBD_KEY_LETTER_L,
  [ANDROID_KEY_LANGUAGE_SWITCH] = 0,
  [ANDROID_KEY_LEFT_BRACKET] = KBD_KEY_SYMBOL_LeftBracket_LeftBrace,

  [ANDROID_KEY_M] = KBD_KEY_LETTER_M,
  [ANDROID_KEY_MANNER_MODE] = 0,
  [ANDROID_KEY_MEDIA_CLOSE] = 0,
  [ANDROID_KEY_MEDIA_EJECT] = 0,
  [ANDROID_KEY_MEDIA_FAST_FORWARD] = 0,
  [ANDROID_KEY_MEDIA_NEXT] = 0,
  [ANDROID_KEY_MEDIA_PAUSE] = 0,
  [ANDROID_KEY_MEDIA_PLAY] = 0,
  [ANDROID_KEY_MEDIA_PLAY_PAUSE] = 0,
  [ANDROID_KEY_MEDIA_PREVIOUS] = 0,
  [ANDROID_KEY_MEDIA_RECORD] = 0,
  [ANDROID_KEY_MEDIA_REWIND] = 0,
  [ANDROID_KEY_MEDIA_STOP] = 0,
  [ANDROID_KEY_MENU] = 0,
  [ANDROID_KEY_META_LEFT] = 0,
  [ANDROID_KEY_META_RIGHT] = 0,
  [ANDROID_KEY_MINUS] = KBD_KEY_SYMBOL_Minus_Underscore,
  [ANDROID_KEY_MOVE_END] = KBD_KEY_FUNCTION_End,
  [ANDROID_KEY_MOVE_HOME] = KBD_KEY_FUNCTION_Home,
  [ANDROID_KEY_MUHENKAN] = 0,
  [ANDROID_KEY_MUSIC] = 0,
  [ANDROID_KEY_MUTE] = 0,

  [ANDROID_KEY_N] = KBD_KEY_LETTER_N,
  [ANDROID_KEY_NOTIFICATION] = 0,
  [ANDROID_KEY_NUM] = 0,
  [ANDROID_KEY_NUMPAD_0] = KBD_KEY_KEYPAD_Zero_Insert,
  [ANDROID_KEY_NUMPAD_1] = KBD_KEY_KEYPAD_One_End,
  [ANDROID_KEY_NUMPAD_2] = KBD_KEY_KEYPAD_Two_ArrowDown,
  [ANDROID_KEY_NUMPAD_3] = KBD_KEY_KEYPAD_Three_PageDown,
  [ANDROID_KEY_NUMPAD_4] = KBD_KEY_KEYPAD_Four_ArrowLeft,
  [ANDROID_KEY_NUMPAD_5] = KBD_KEY_KEYPAD_Five,
  [ANDROID_KEY_NUMPAD_6] = KBD_KEY_KEYPAD_Six_ArrowRight,
  [ANDROID_KEY_NUMPAD_7] = KBD_KEY_KEYPAD_Seven_Home,
  [ANDROID_KEY_NUMPAD_8] = KBD_KEY_KEYPAD_Eight_ArrowUp,
  [ANDROID_KEY_NUMPAD_9] = KBD_KEY_KEYPAD_Nine_PageUp,
  [ANDROID_KEY_NUMPAD_ADD] = KBD_KEY_KEYPAD_Plus,
  [ANDROID_KEY_NUMPAD_COMMA] = KBD_KEY_KEYPAD_Comma,
  [ANDROID_KEY_NUMPAD_DIVIDE] = KBD_KEY_KEYPAD_Slash,
  [ANDROID_KEY_NUMPAD_DOT] = KBD_KEY_KEYPAD_Period_Delete,
  [ANDROID_KEY_NUMPAD_ENTER] = KBD_KEY_KEYPAD_Enter,
  [ANDROID_KEY_NUMPAD_EQUALS] = KBD_KEY_KEYPAD_Equals,
  [ANDROID_KEY_NUMPAD_LEFT_PAREN] = KBD_KEY_KEYPAD_LeftParenthesis,
  [ANDROID_KEY_NUMPAD_MULTIPLY] = KBD_KEY_KEYPAD_Asterisk,
  [ANDROID_KEY_NUMPAD_RIGHT_PAREN] = KBD_KEY_KEYPAD_RightParenthesis,
  [ANDROID_KEY_NUMPAD_SUBTRACT] = KBD_KEY_KEYPAD_Minus,
  [ANDROID_KEY_NUM_LOCK] = KBD_KEY_KEYPAD_NumLock_Clear,

  [ANDROID_KEY_O] = KBD_KEY_LETTER_O,

  [ANDROID_KEY_P] = KBD_KEY_LETTER_P,
  [ANDROID_KEY_PAGE_DOWN] = KBD_KEY_FUNCTION_PageDown,
  [ANDROID_KEY_PAGE_UP] = KBD_KEY_FUNCTION_PageUp,
  [ANDROID_KEY_PERIOD] = KBD_KEY_SYMBOL_Period_Greater,
  [ANDROID_KEY_PICTSYMBOLS] = 0,
  [ANDROID_KEY_PLUS] = 0,
  [ANDROID_KEY_POUND] = 0,
  [ANDROID_KEY_POWER] = KBD_KEY_FUNCTION_Power,
  [ANDROID_KEY_PROG_BLUE] = 0,
  [ANDROID_KEY_PROG_GREEN] = 0,
  [ANDROID_KEY_PROG_RED] = 0,
  [ANDROID_KEY_PROG_YELLOW] = 0,

  [ANDROID_KEY_Q] = KBD_KEY_LETTER_Q,

  [ANDROID_KEY_R] = KBD_KEY_LETTER_R,
  [ANDROID_KEY_RIGHT_BRACKET] = KBD_KEY_SYMBOL_RightBracket_RightBrace,
  [ANDROID_KEY_RO] = 0,

  [ANDROID_KEY_S] = KBD_KEY_LETTER_S,
  [ANDROID_KEY_SCROLL_LOCK] = KBD_KEY_LOCK_Scroll,
  [ANDROID_KEY_SEARCH] = 0,
  [ANDROID_KEY_SEMICOLON] = KBD_KEY_SYMBOL_Semicolon_Colon,
  [ANDROID_KEY_SETTINGS] = 0,
  [ANDROID_KEY_SHIFT_LEFT] = KBD_KEY_FUNCTION_ShiftLeft,
  [ANDROID_KEY_SHIFT_RIGHT] = KBD_KEY_FUNCTION_ShiftRight,
  [ANDROID_KEY_SLASH] = KBD_KEY_SYMBOL_Slash_Question,
  [ANDROID_KEY_SOFT_LEFT] = 0,
  [ANDROID_KEY_SOFT_RIGHT] = 0,
  [ANDROID_KEY_SPACE] = KBD_KEY_FUNCTION_Space,
  [ANDROID_KEY_STAR] = 0,
  [ANDROID_KEY_STB_INPUT] = 0,
  [ANDROID_KEY_STB_POWER] = 0,
  [ANDROID_KEY_SWITCH_CHARSET] = 0,
  [ANDROID_KEY_SYM] = 0,
  [ANDROID_KEY_SYSRQ] = KBD_KEY_FUNCTION_SystemRequest,

  [ANDROID_KEY_T] = KBD_KEY_LETTER_T,
  [ANDROID_KEY_TAB] = KBD_KEY_FUNCTION_Tab,
  [ANDROID_KEY_TV] = 0,
  [ANDROID_KEY_TV_INPUT] = 0,
  [ANDROID_KEY_TV_POWER] = 0,

  [ANDROID_KEY_U] = KBD_KEY_LETTER_U,
  [ANDROID_KEY_UNKNOWN] = 0,

  [ANDROID_KEY_V] = KBD_KEY_LETTER_V,
  [ANDROID_KEY_VOLUME_DOWN] = KBD_KEY_FUNCTION_VolumeDown,
  [ANDROID_KEY_VOLUME_MUTE] = KBD_KEY_FUNCTION_Mute,
  [ANDROID_KEY_VOLUME_UP] = KBD_KEY_FUNCTION_VolumeUp,

  [ANDROID_KEY_W] = KBD_KEY_LETTER_W,
  [ANDROID_KEY_WINDOW] = 0,

  [ANDROID_KEY_X] = KBD_KEY_LETTER_X,

  [ANDROID_KEY_Y] = KBD_KEY_LETTER_Y,
  [ANDROID_KEY_YEN] = 0,

  [ANDROID_KEY_Z] = KBD_KEY_LETTER_Z,
  [ANDROID_KEY_ZENKAKU_HANKAKU] = 0,
  [ANDROID_KEY_ZOOM_IN] = 0,
  [ANDROID_KEY_ZOOM_OUT] = 0,
};
const int keyCodeLimit = ARRAY_COUNT(keyCodeMap);

int
forwardKeyEvent (int code, int press) {
  return 0;
}

int
monitorKeyboards (KeyboardCommonData *kcd) {
  return 1;
}
