# TOFU65_Custom_Firmware

"config.h" - 
  - Was edited to add "#define RGB_MATRIX_KEYPRESSES" &
                    "#define RGB_MATRIX_FRAMEBIFFER_EFFECTS"
    These were added to enable keypress reaction.

"key index matrix.c" -
  - This file is not included when running "qmk compile"
  - The purpose for this file was a reference to the 
    key index = led index.

  "keyboard-layout.json" -
    - Edited the file to specify the keycap size for 
      the keyboard layout. 

  "v1.c" -
    - Taken from the qmk firmware.
    - Edited it to add "led_config_t g_led_config = {};"
    - This configured the led key matrix and allowed me to 
      specify the matrix for my specific keyboard.

"keymap.c" - 
  *This is completely custom, and my use case specific*
  - Initially specified the keymap layout, and layers.
  - Code for "key_index_map" which specify which key index
    translates to a specific row & col.
  - Code for "rgb_matrix_indicators_user"
  - 2 for, to initially begin at [row][col] [0][0]
  - Then uses "row++" & "col++" to move 1 row & col for each index.
  - The first part, sets up "key_index_map" to equal "key_index".
  - To begin, the code will ensure the "key_index" does not equal "NO_LED",
    this is done by using "!=".
  - Using an if statement, I grouped a list of keys that I wanted to be (0, 238, 254)
    by referencing each "key_index" and "==".
  - Using 3 else if statements to configure the rest of the keys to specific colors.
    NOTE: WASD keys are slightly off, this is done on PURPOSE.
  - The next part of the function, uses an additional if statement.
  - Under this if statement, I use switch to specify each case to their respective
    "key_index".
    NOTE: For some reason I was not able to configure each case for their
    respective keycode. Example, "KC_ESC" = 0, "KC_1" = 1.
    When configuring this, using "KC_ESC" manipulated "key_index == 67"
    rather than "key_index == 0".
    I will be revising this file if I figure this out. Until then,
    case 0 = key_index -- 0, "KC_ESC"
    case 1 = key_index == 1, "KC_1"
    case 2 = key_index == 2, "KC_2"
    ...

  - The purpose for specifying each individual key index and case,
    was to match the specific keycap color on the keyboard, then
    when the key is pressed, change to the opposite color.
    Example, ESC is Blue, on keypress, it turns to purple,
    1 is purple, on keypress, it turns blue,
    ...

  - Initially not all keys function on keypress, but I am unable to determine
    why this is. These keys are the right color, but either do nothing, or
    odd behavior like being 1 key off to the left upon keypress. 
    * Right Shift,
    * Enter,
    * Space bar,
    * Right Alt,
    * Right Function,
    * Right Control,    
