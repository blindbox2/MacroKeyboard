#include <Rotary.h>
#include <Keyboard.h>

#define left_Control 0x80
#define left_Shift 0x81
#define key_PGUP 0xD3
#define key_F1 0xC2
#define key_F2 0xC3
#define key_F3 0xC4
#define key_F4 0xC5
#define key_F5 0xC6
#define key_F6 0xC7
#define key_F7 0xC8
#define key_F8 0xC9
#define key_F9 0xCA
#define key_F10 0xCB
#define key_F11 0xCC

Rotary rotary1 = Rotary(A2, A3);
Rotary rotary2 = Rotary(15, A0);
char profile_Key = 0;

void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  Keyboard.begin();
  delay(200);
}

void loop() {
  //3State switch logic
  if (digitalRead(4) == LOW) {
    profile_Key = left_Control;
  }
  if (digitalRead(5) == LOW) {
    profile_Key = left_Shift;
  }
  if (digitalRead(6) == LOW) {
    profile_Key = key_PGUP;
  }

  //Rotary Decoders
  unsigned char result1 = rotary1.process();
  if (result1 == DIR_CW) {
    Press_Key(profile_Key, KEY_F1, 25);
  } else if (result1 == DIR_CCW) {
    Press_Key(profile_Key, KEY_F2, 25);
  }
  if (digitalRead(14) == LOW) {
    Press_Key(profile_Key, KEY_F3, 200);
  }
  unsigned char result2 = rotary2.process();
  if (result2 == DIR_CW) {
    Press_Key(profile_Key, KEY_F4, 25);
  } else if (result2 == DIR_CCW) {
    Press_Key(profile_Key, KEY_F5, 25);
  }
  if (digitalRead(3) == LOW) {
    Press_Key(profile_Key, KEY_F6, 200);
  }

  //Press button logic
  if (digitalRead(16) == LOW) {
    Press_Key(profile_Key, KEY_F7, 200);
  }
  if (digitalRead(10) == LOW) {
    Press_Key(profile_Key, KEY_F8, 200);
  }
  if (digitalRead(9) == LOW) {
    Press_Key(profile_Key, KEY_F9, 200);
  }
  if (digitalRead(8) == LOW) {
    Press_Key(profile_Key, KEY_F10, 200);
  }
  if (digitalRead(7) == LOW) {
    Press_Key(profile_Key, KEY_F11, 200);
  }
}

void Press_Key(char profile, char key, int time_out){
  Keyboard.press(profile);
  Keyboard.press(key);
  delay(time_out);
  Keyboard.releaseAll();
}
