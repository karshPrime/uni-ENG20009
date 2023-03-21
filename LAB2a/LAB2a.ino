bool led1 = 0;
bool led2 = 1;
int  rate = 100;

void setup() {
  Serial.begin(9600);

  for (int i = 8; i < 12; i++) {
    pinMode(i, OUTPUT);
  }

  for (int i = 2; i < 6; i++) {
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  passTask();
  passPlus();
}

// pass task: first button turns 
void passTask() {
  if (not digitalRead(2)) { led1 = not led1; }

  digitalWrite(11, led1);
}

// pass plus: more buttons
void passPlus() {
  static int states[2] = {HIGH, LOW};

  // flicking LED
  digitalWrite(10, HIGH); delay(rate+100);
  digitalWrite(10, LOW);  delay(rate+100);

  // modifying delay rate between flicks
  if (not digitalRead(3)) { rate -= 70; }
  if (not digitalRead(4)) { rate += 70; }

  // setting up extreme values
  if (rate < 0  ) { rate = 0; }
  if (rate > 200) { rate = 200; }

  // 3rd LED HIGH-LOW change
  if (not digitalRead(5)) { led2 = 1 - led2; }
  digitalWrite(9, states[led2]);
}