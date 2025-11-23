#include <Keyboard.h>

int val;

/* this is the code for a keyboard - see the github file for schematics
it uses the rows as input and columns as output
as you can see, i set the schematic to do something really weird
I used Arduino bc Arduino > Micropython 
Sticky Keys are turned on by default. I'm too lazy to change that 
Inspired by Keychron q1 custom keyboard
It only works theoretically */

// set amount of rows/columns
#define ROWS 6
#define COLUMNS 15
#define DEEPSLEEP 10000 // when to deep/light sleep in ms
#define DEEPSLEEPWHEN 60000
#define LIGHTSLEEP 2000
#define LIGHTSLEEPWHEN 10000

// set column and row pins(bc they're irregular)
int row_pins[ROWS] = { 10, 11, 12, 13, 14, 15 };
int column_pins[COLUMNS] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 17, 18, 19, 20, 21, 22 };

// set lower alphabet(type[column][row]) - assuming that shift will automatically be called
// 0 represents a blank space
int alphabet[ROWS][COLUMNS] = {
  { 177,  194,  195,  196,  197,  198,  199,  200,  201,  202,  203,  204,  205,  212,  209  },
  { 96,   '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  45,   61,   178,  211  },
  { 179,  'q',  'w',  'e',  'r',  't',  'y',  'u',  'i',  'o',  'p',  91,   93,   92,   214  },
  { 193,  'a',  's',  'd',  'f',  'g',  'h',  'j',  'k',  'l',  59,   39,   '\n', 0,    210  },
  { 129,  'z',  'x',  'c',  'v',  'b',  'n',  'm',  44,   46,   47,   133,  218,  0,    0    },
  { 128,  130,  131,  0,    0,    32,   0,    0,    135,  0,    132,  216,  217,  0,    215  }
};

// set which row the output is on, whether shift and control and windows is on
int iteration_count = 0;
bool is_shift = false;
bool is_ctrl = false;
bool is_gui = false;
bool is_alt = false;

int specialKeyIsPressed[4][3] = {
  {0, 129, false}, // 0=is_shift, 129=keyToPress, 0=isPressed?
  {1, 128, false},
  {2, 131, false},
  {3, 135, false}
};
// when was keypress last "registered"
unsigned long lastKeyPress = millis(); 
unsigned long calculateKeyPress;
bool isKeyPressedDown = false;


// helper functions ; skip to main stuff
void doWhenKeyIsPressed(int x, int y) {
  val = digitalRead(column_pins[x]); // is column x connected when row y is on? Button thus pressed
  if (val == 0) {
    Serial.print("Key pressed: "); // beta beta
    Serial.print(x); // beta beta
    Serial.print(','); // beta beta
    Serial.print(y); // beta beta
    Serial.print(','); // beta beta
    Serial.println(alphabet[y][x]); // beta beta
    is_shift = ((x == 0 && y == 4) || (x == 11 && y == 4));  // shift key
    is_ctrl = ((x == 0 && y == 5) || (x == 11 && y == 5));   // ctrl key
    is_gui = ((x == 2 && y == 5) || (x == 9 && y == 5));     // windows key
    is_alt = ((x == 8 && y == 5) || (x == 1 && y == 5)); // alt key

    if ()
    if (!isShiftPressed && !isCtrlPressed && !isGuiPressed && !is_alt) {

    }
    // if (!is_shift && !is_ctrl && !is_gui && !is_alt) {
    //   Keyboard.write(alphabet[y][x]); // wierd i know but counts rows before columns
    //   Keyboard.releaseAll();
    //   isKeyPressedDown = false;
    // }
    // else {
    //   isKeyPressedDown = true;
    //   Keyboard.press(alphabet[y][x]); // sticky keys :) too much work to implement differently
    // }

    lastKeyPress = millis(); // reset keyboard sleepyness
  }
}

void shouldKeyboardSleep() { // sleep NOT power saving :)
  calculateKeyPress = millis() - lastKeyPress;
  if (calculateKeyPress > DEEPSLEEPWHEN) {
    delay(DEEPSLEEP);
  } else if (calculateKeyPress > LIGHTSLEEPWHEN) {
    delay(LIGHTSLEEP);
  }
}

void turnOffKeysIfNeeded() { // for fancy keyboard.press stuff
  if (isKeyPressedDown == true && (lastKeyPress - millis() > 3000)) { // if key pressed for long time...
    Keyboard.releaseAll();
    isKeyPressedDown = false;
  }
}



// main stuff
void setup() {
  Serial.begin(9600);
  Serial.println("Starting Keyboard..."); // beta beta

  // set rows as input - takes power
  for (int i = 0; i < ROWS; i++) {
    pinMode(row_pins[i], OUTPUT);
    digitalWrite(row_pins[i], HIGH);
  }

  // set columns as output - gives power
  for (int i = 0; i < COLUMNS; i++) {
    pinMode(column_pins[i], INPUT_PULLUP); // input w/pullup
  }

  Keyboard.begin();
}

void loop() {
  // very simple loop - iterate thorugh x then y coords and check if there is output
  for (int y = 0; y < ROWS; y++) {
    digitalWrite(row_pins[y], LOW);
    delay(1);
    for (int x = 0; x < COLUMNS; x++) {
      doWhenKeyIsPressed(x, y); // is key pressed? if so, do smth
    }

    digitalWrite(row_pins[y], HIGH);
  }

  // Keyboard.releaseAll(); //test1
  shouldKeyboardSleep(); // if keyboard want sleep keyboard yes sleep 
  turnOffKeysIfNeeded(); // :) only if they're pressed for longer than 3 seconds

  // standard delay for HID keyboard according to ch*tgpt
  delay(80);

  // don't touch until after tested
  delay(1000);
}