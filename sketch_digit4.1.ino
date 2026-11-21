
const int DATA_PIN  = 2; 
const int LATCH_PIN = 4; 
const int CLOCK_PIN = 5;
const int STEP_DELAY = 200; 
const byte START_PATTERN = 0b00000001;
byte pattern = 0b00000001;
const byte SHIFT_STEP = 1;
const byte EMPTY_PATTERN = 0; 

void SetPin(){
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
}
void sendByte(byte data) {
  digitalWrite(LATCH_PIN, LOW);

  for (int i = 7; i >= 0; i--) {
    digitalWrite(DATA_PIN, (data >> i) & START_PATTERN ); 
    digitalWrite(CLOCK_PIN, HIGH);          
    digitalWrite(CLOCK_PIN, LOW);
  }
  digitalWrite(LATCH_PIN, HIGH); 
}

void runningLightStep() {
  sendByte(pattern);
  delay(STEP_DELAY);

  pattern <<= SHIFT_STEP;          
  if (pattern == EMPTY_PATTERN) {     
    pattern = START_PATTERN; 
  }
}

void setup() {
  SetPin();
}

void loop() {
  runningLightStep();
}