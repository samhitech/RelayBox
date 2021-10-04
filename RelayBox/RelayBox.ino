int led = LED_BUILTIN;


int FlashIn_1 = 2;    // <-- Arduino pin Flash Input #1
int FlashIn_2 = 3;    // <-- Arduino pin Flash Input #2
int FlashVCC_1 = 4;    // <-- Arduino pin Flash VCC #1
int FlashVCC_2 = 5;    // <-- Arduino pin Flash VCC #2

int L405pin = 6;     // <-- Arduino pin 405nm TTL 
int L488pin = 7;     // <-- Arduino pin 488nm TTL 
int L520pin = 8;     // <-- Arduino pin 520nm TTL 
int L638pin = 9;     // <-- Arduino pin 638nm TTL 

enum state {
    Off, 
    On,
    FL1,
    FL2
};

bool F1, F2, test = false;
volatile bool ALEX = false;
volatile int L405_State = Off;
volatile int L488_State = FL1;
volatile int L520_State = Off;
volatile int L638_State = FL2;

char character;
String serialCommand = "";

volatile byte ALEX_state = LOW;

void setup() {
  // setting pin modes:
  pinMode(led, OUTPUT);
  pinMode(FlashIn_1, INPUT); 
  pinMode(FlashIn_2, INPUT); 
  pinMode(L405pin, OUTPUT);
  pinMode(L488pin, OUTPUT);
  pinMode(L520pin, OUTPUT);
  pinMode(L638pin, OUTPUT);
  pinMode(FlashVCC_1, OUTPUT);
  pinMode(FlashVCC_2, OUTPUT);
  pinMode(10, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(FlashIn_1), blink, RISING);
  
  digitalWrite(FlashVCC_1, HIGH);
  digitalWrite(FlashVCC_2, HIGH);

  Serial.begin(115200);
}

void blink() {
  ALEX_state = !ALEX_state;
}

void loop() {
  if (Serial.available() > 0) {
    
     serialCommand = Serial.readStringUntil('\r');

    if (serialCommand.length() > 0) {
      if (serialCommand.indexOf("ALEXON") > -1){
        ALEX = true;}
      if (serialCommand.indexOf("ALEXOFF") > -1){
        ALEX = false;}
        
      // 405nm Laser settings
      if (serialCommand.indexOf("L405OFF") > -1){
        L405_State = Off;}
      if (serialCommand.indexOf("L405ON") > -1){
        L405_State = On;}
      if (serialCommand.indexOf("L405F1") > -1){
        L405_State = FL1;}
      if (serialCommand.indexOf("L405F2") > -1){
        L405_State = FL2;}
  
      // 488nm Laser settings
      if (serialCommand.indexOf("L488OFF") > -1){
        L488_State = Off;}
      if (serialCommand.indexOf("L488ON") > -1){
        L488_State = On;}
      if (serialCommand.indexOf("L488F1") > -1){
        L488_State = FL1;}
      if (serialCommand.indexOf("L488F2") > -1){
        L488_State = FL2; }
      
      // 520nm Laser settings
      if (serialCommand.indexOf("L520OFF") > -1){
        L520_State = Off;}
      if (serialCommand.indexOf("L520ON") > -1){
        L520_State = On;}
      if (serialCommand.indexOf("L520F1") > -1){
        L520_State = FL1;}
      if (serialCommand.indexOf("L520F2") > -1){
        L520_State = FL2;}
  
      // 638nm Laser settings
      if (serialCommand.indexOf("L638OFF") > -1){
        L638_State = Off;}
      if (serialCommand.indexOf("L638ON") > -1){
        L638_State = On;}
      if (serialCommand.indexOf("L638F1") > -1){
        L638_State = FL1;}
      if (serialCommand.indexOf("L638F2") > -1){
        L638_State = FL2;}

      Serial.println(serialCommand);
      serialCommand = "";
      }
  }
  // put your laser pin setting here:
  F1 = digitalRead(FlashIn_1);
  F2 = digitalRead(FlashIn_2);
  // Indicator LED shows Flash 1 status
  digitalWrite(led, F1);

  switch (L405_State) {
    case Off:
      digitalWrite(L405pin, LOW);
      break;
    case On:
      digitalWrite(L405pin, HIGH);
      break;
    case FL1:
      if (!ALEX){
        digitalWrite(L405pin, F1);
      }else {digitalWrite(L405pin, F1 && ALEX_state);}
      break;
    case FL2:
      if (!ALEX){
        digitalWrite(L405pin, F2);
      }else {digitalWrite(L405pin, F2 && !ALEX_state);}
      break;
  }

  switch (L488_State) {
    case Off:
      digitalWrite(L488pin, LOW);
      break;
    case On:
      digitalWrite(L488pin, HIGH);
      break;
    case FL1:
      if (!ALEX){
        digitalWrite(L488pin, F1);
      }else {digitalWrite(L488pin, F1 && ALEX_state);}
      break;
    case FL2:
      if (!ALEX){
        digitalWrite(L488pin, F2);
      }else {digitalWrite(L488pin, F2 && !ALEX_state);}
      break;
  }

  switch (L520_State) {
    case Off:
      digitalWrite(L520pin, LOW);
      break;
    case On:
      digitalWrite(L520pin, HIGH);
      break;
    case FL1:
      if (!ALEX) {
        digitalWrite(L520pin, F1);
      }else {digitalWrite(L520pin, F1 && ALEX_state);}
      break;
    case FL2:
      if (!ALEX) {
        digitalWrite(L520pin, F2);
      } else {digitalWrite(L520pin, F2 && !ALEX_state);}
      break;
  }

  switch (L638_State) {
    case Off:
      digitalWrite(L638pin, LOW);
      break;
    case On:
      digitalWrite(L638pin, HIGH);
      break;
    case FL1:
      if (!ALEX) {
        digitalWrite(L638pin, F1);
        } else {digitalWrite(L638pin, F1 && ALEX_state);}
      break;
    case FL2:
      if (!ALEX){
        digitalWrite(L638pin, F2);
      }else {digitalWrite(L638pin, F2 && !ALEX_state);}
      break;
  }
  
  test = !test;
  digitalWrite(10, test);
}
