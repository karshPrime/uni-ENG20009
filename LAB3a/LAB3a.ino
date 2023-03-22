void setup() {
  // start serial communication at 9600 baud
  Serial.begin(9600);
  
  Serial.println("Lab Task 2");
  printMenu(false, true);

  pinMode(6, OUTPUT);  // Buzzer
  pinMode(11, OUTPUT); // LED
}

void loop() {
  static bool buzzerState = false;
  static bool ledHigh = true;
  static int  blinkSpeed = 200;
  static char userInput;
  
  // Read a character
  userInput = Serial.read();

  // user option action
  if (userInput == '1' || userInput == '2' || userInput == '3' || userInput == '4' ) {
    Serial.print(">>> ");
    Serial.println(userInput);

    if (userInput == '1') {
      buzzerState = not buzzerState;
      toggleBuzzer(buzzerState);
    }
    else if (userInput == '2') {
      blinkSpeed -= 30;
      if (blinkSpeed < 0) {blinkSpeed = 0;}
    }
    else if (userInput == '3') {
      blinkSpeed += 30;
    }
    else if (userInput == '4') {
      ledHigh = not ledHigh;
    }

    // print Menu on after every loop
    printMenu(buzzerState, ledHigh);

    userInput = 'x'; // resetting user input
  }

  // blink LED only if its supposed to be on
  if (ledHigh) { blinkLED(blinkSpeed);} else { digitalWrite(11, LOW);}

}

// display all options
void printMenu(bool buzzerState, bool ledHigh) {  
  Serial.println(" "); // blank line
  Serial.print("[1] Turn buzzer ");
  if (buzzerState) { Serial.println("Off"); } else { Serial.println("On"); }

  Serial.println("[2] Increase blink-rate");
  Serial.println("[3] Decrease blink-rate");
  
  Serial.print("[4] Turn LED brightness ");
  if (ledHigh) { Serial.println("Low"); } else { Serial.println("High"); }
}

// toggle buzzer/LED state
void toggleBuzzer(bool state) {
  digitalWrite(6, state);
}

// link LED
void blinkLED(int speed) {
  digitalWrite(11, 1);
  delay(speed);

  digitalWrite(11, 0);
  delay(speed);
}