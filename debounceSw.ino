int led = 13;
int pushButton = 8;
bool currentButton = LOW;
bool lastButton = LOW;
bool ledState = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton, INPUT);
  pinMode(led,       OUTPUT);

}
//This function handles the debouncing of the button
bool swDebounce (bool last) {

  bool currentState = digitalRead(pushButton);
  if (last != currentState) {
    delay(20);
    currentState = digitalRead(pushButton);
  }
  return currentState;

}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = swDebounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {

    ledState = !ledState;
  }

  lastButton = currentButton;

  digitalWrite(led, ledState);

}
