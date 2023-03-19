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
  static int  start = 0;
  static int  num = 0;

  // getting dip-switch data
  for (int j = 2; j < 6; j++) {
    int switchState = digitalRead(j);
    if (not switchState) {
      num += pow(2, (5-j));
    }
  }

  // different leds for different num
  if (num == 1) {
    int r[13] = { 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7 };
    int c[13] = { 1, 2, 0, 2, 2, 2, 2, 2, 2, 0, 1, 2, 3 };
    drawChar(13, r, c, start);
  }
  else if (num == 2) {
    int r[13] = { 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7 };
    int c[13] = { 1, 2, 0, 3, 3, 2, 1, 0, 0, 0, 1, 2, 3 };
    drawChar(13, r, c, start);
  }
  else if (num == 3) {
    int r[13] = { 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 6, 7, 7 };
    int c[13] = { 1, 2, 0, 3, 3, 1, 2, 3, 3, 0, 3, 1, 2 };
    drawChar(13, r, c, start);
  }
  else if (num == 4) {
    int r[13] = { 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 6, 7 };
    int c[13] = { 0, 0, 0, 3, 0, 3, 0, 1, 2, 3, 3, 3, 3 };
    drawChar(13, r, c, start);
  }
  else if (num == 5) {
    int r[15] = { 0, 0, 0, 0, 1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7 };
    int c[15] = { 0, 1, 2, 3, 0, 0, 0, 1, 2, 3, 3, 0, 3, 1, 2 };
    drawChar(15, r, c, start);
  }
  else if (num == 6) {
    int r[15] = { 0, 0, 1, 1, 2, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[15] = { 1, 2, 0, 3, 0, 0, 0, 1, 2, 0, 3, 0, 3, 1, 2 };
    drawChar(15, r, c, start);
  }
  else if (num == 7) {
    int r[11] = { 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7 };
    int c[11] = { 0, 1, 2, 3, 3, 3, 2, 1, 1, 1, 1 };
    drawChar(11, r, c, start);
  }
  else if (num == 8) {
    int r[16] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[16] = { 1, 2, 0, 3, 0, 3, 1, 2, 0, 3, 0, 3, 0, 3, 1, 2 };
    drawChar(16, r, c, start);
  }
  else if (num == 9) {
    int r[15] = { 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7 };
    int c[15] = { 1, 2, 0, 3, 0, 3, 1, 2, 3, 3, 3, 0, 3, 1, 2 };
    drawChar(15, r, c, start);
  }
  else if (num == 10) {
    int r[20] = { 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[20] = { 1, 2, 3, 0, 4, 0, 4, 0, 1, 2, 3, 4, 0, 4, 0, 4, 0, 4, 0, 4 };
    drawChar(20, r, c, start);
  }
  else if (num == 11) {
    int r[22] = { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7 };
    int c[22] = { 0, 1, 2, 3, 0, 4, 0, 4, 0, 1, 2, 3, 0, 3, 0, 4, 0, 4, 0, 1, 2, 3 };
    drawChar(22, r, c, start);
  }
  else if (num == 12) {
    int r[12] = { 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7 };
    int c[12] = { 2, 3, 4, 1, 0, 0, 0, 0, 1, 2, 3, 4 };
    drawChar(12, r, c, start);
  }
  else if (num == 13) {
    int r[18] = { 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7 };
    int c[18] = { 0, 1, 2, 0, 3, 0, 4, 0, 4, 0, 4, 0, 4, 0, 3, 0, 1, 2 };
    drawChar(18, r, c, start);
  }
  else if (num == 14) {
    int r[17] = { 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 7, 7, 7 };
    int c[17] = { 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 0, 0, 1, 2, 3, 4 };
    drawChar(17, r, c, start);
  }
  else if (num == 15) {
    int r[14] = { 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 5, 6, 7 };
    int c[14] = { 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0 };
    drawChar(14, r, c, start);
  }
  else {
    int r[16] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int c[16] = { 1, 2, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 0, 3, 1, 2 };
    drawChar(16, r, c, start);
  }

  num = 0; // resetting num back to 0
}

void drawChar(int arrayLen, int* r, int* c, int start) {
  int cPos;
  for (int i = 0; i < arrayLen; i++) {
    if (start+c[i] > 9) { cPos = start+c[i] - 9; } else { cPos = start+c[i]; }
    onLED(cPos, r[i]); 
  }
}

void onLED(int x, int y) {
  ledreset();
  digitalWrite(rows[y], HIGH);
  digitalWrite(cols[x], LOW);
}

void ledreset() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}

