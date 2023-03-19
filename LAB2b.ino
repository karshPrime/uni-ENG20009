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

}
