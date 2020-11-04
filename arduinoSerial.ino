#define ON HIGH
#define OFF LOW
#define LED_RED 12
#define LED_GREEN 13
#define LED_BLUE 14

void warning();
void allOff();
void greendLight();

String recvData;

void setup() {                
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    recvData = Serial.readStringUntil('\n');
    Serial.println(recvData);
  }
    
  if(recvData == "0") {  // bad tooth
    greendLight();
  } else if(recvData == "1") {
    warning();
  } else {
    allOff();
  }
}

void warning() {
  allOff();
  digitalWrite(LED_RED, ON);
  delay(100);
  digitalWrite(LED_RED, OFF);
  digitalWrite(LED_BLUE, ON);
  delay(100);
  digitalWrite(LED_BLUE, OFF);
}

void greendLight() {
  digitalWrite(LED_GREEN, ON);
  delay(100);
  digitalWrite(LED_GREEN, OFF);
  delay(100);
}

void allOff() {
  digitalWrite(LED_RED,OFF);
  digitalWrite(LED_GREEN,OFF);
  digitalWrite(LED_BLUE,OFF);
}

