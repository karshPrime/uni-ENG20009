#include <math.h>

// Declaring pins
int rows[8] = { 14, 15, 16, 17, 18, 19, 20, 21 };
int cols[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };

void setup() {
  // start serial communication at 9600 baud
  Serial.begin(9600);
  
  // dip switch
  for (int i = 2; i != 6; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  // LED Matrix
  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}

void loop() {
  //creditTask();
  distinctions(10);
}

// get num from dip-switch
void creditTask() {
  int num = 0;

  for (int j = 2; j < 6; j++) {
    int switchState = digitalRead(j);
    if (not switchState) {
      num += pow(2, (5-j));
    }
  }

  loadSequence(num, 2);
}

// move required character
void distinctions(int num) {
  static int  start = 2;
  static int  speedBuffer = 1;
  static int  speed = 0;
  static int  speedOption[3] = {50, 100, 200};
  static bool moveRight = false;

  if (not digitalRead(5)) {
    moveRight = true;
    speed = (1.5 * pow(speed, 2)) - (3.5 * speed) + 2;
    delay(200);
  }
  
  // move character if required
  if (moveRight) {
    speedBuffer++;
    if (speedBuffer > speedOption[speed]) {start += 1; speedBuffer = 0;}
    if (start == 9) {start = 0;}
  }

  loadSequence(num, start);
}

// decide row and column coords to draw char
void loadSequence(int num, int start) {
    // different leds for different num
  if (num == 1) {
    int r[13] = { 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7 };
    int c[13] = { 1, 2, 0, 2, 2, 2, 2, 2, 2, 0, 1, 2, 3 };
    drawSequence(13, r, c, start);
  }
  else if (num == 2) {
    int r[13] = { 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7 };
    int c[13] = { 1, 2, 0, 3, 3, 2, 1, 0, 0, 0, 1, 2, 3 };
    drawSequence(13, r, c, start);
  }
  else if (num == 3) {
    int r[13] = { 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 6, 7, 7 };
    int c[13] = { 1, 2, 0, 3, 3, 1, 2, 3, 3, 0, 3, 1, 2 };
    drawSequence(13, r, c, start);
  }
  else if (num == 4) {
    int r[13] = { 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 6, 7 };
    int c[13] = { 0, 0, 0, 3, 0, 3, 0, 1, 2, 3, 3, 3, 3 };
    drawSequence(13, r, c, start);
  }
  else if (num == 5) {
    int r[15] = { 0, 0, 0, 0, 1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7 };
    int c[15] = { 0, 1, 2, 3, 0, 0, 0, 1, 2, 3, 3, 0, 3, 1, 2 };
    drawSequence(15, r, c, start);
  }
  else if (num == 6) {
    int r[15] = { 0, 0, 1, 1, 2, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[15] = { 1, 2, 0, 3, 0, 0, 0, 1, 2, 0, 3, 0, 3, 1, 2 };
    drawSequence(15, r, c, start);
  }
  else if (num == 7) {
    int r[11] = { 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7 };
    int c[11] = { 0, 1, 2, 3, 3, 3, 2, 1, 1, 1, 1 };
    drawSequence(11, r, c, start);
  }
  else if (num == 8) {
    int r[16] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[16] = { 1, 2, 0, 3, 0, 3, 1, 2, 0, 3, 0, 3, 0, 3, 1, 2 };
    drawSequence(16, r, c, start);
  }
  else if (num == 9) {
    int r[15] = { 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7 };
    int c[15] = { 1, 2, 0, 3, 0, 3, 1, 2, 3, 3, 3, 0, 3, 1, 2 };
    drawSequence(15, r, c, start);
  }
  else if (num == 10) {
    int r[20] = { 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[20] = { 1, 2, 3, 0, 4, 0, 4, 0, 1, 2, 3, 4, 0, 4, 0, 4, 0, 4, 0, 4 };
    drawSequence(20, r, c, start);
  }
  else if (num == 11) {
    int r[22] = { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7 };
    int c[22] = { 0, 1, 2, 3, 0, 4, 0, 4, 0, 1, 2, 3, 0, 3, 0, 4, 0, 4, 0, 1, 2, 3 };
    drawSequence(22, r, c, start);
  }
  else if (num == 12) {
    int r[12] = { 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7 };
    int c[12] = { 2, 3, 4, 1, 0, 0, 0, 0, 1, 2, 3, 4 };
    drawSequence(12, r, c, start);
  }
  else if (num == 13) {
    int r[18] = { 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7 };
    int c[18] = { 0, 1, 2, 0, 3, 0, 4, 0, 4, 0, 4, 0, 4, 0, 3, 0, 1, 2 };
    drawSequence(18, r, c, start);
  }
  else if (num == 14) {
    int r[17] = { 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 7, 7, 7 };
    int c[17] = { 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 0, 0, 1, 2, 3, 4 };
    drawSequence(17, r, c, start);
  }
  else if (num == 15) {
    int r[14] = { 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 };
    int c[14] = { 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0 };
    drawSequence(14, r, c, start);
  }
  else { // zero
    int r[16] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[16] = { 1, 2, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 2 };
    drawSequence(16, r, c, start);
  }
}

// take in rows and columns sequence and get each of them drawn
void drawSequence(int arrayLen, int* r, int* c, int start) {
  int cPos;
  for (int i = 0; i < arrayLen; i++) {
    if (start+c[i] > 9) { cPos = start+c[i] - 9; } else { cPos = start+c[i]; }
    singleLED(cPos, r[i]); 
  }
}

// turn on single led
void singleLED(int x, int y) {
  ledReset();
  digitalWrite(rows[y], HIGH);
  digitalWrite(cols[x], LOW);
}

// reset grid
void ledReset() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}
