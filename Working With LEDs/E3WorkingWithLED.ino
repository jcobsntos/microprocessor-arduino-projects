int LED = 12;
int LED1 = 13;
int LED2 = 11;

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
}

void loop() {
  digitalWrite (LED,HIGH);
  delay(500);
  digitalWrite (LED,LOW);
  delay(10);

   digitalWrite (LED1,HIGH);
  delay(500);
  digitalWrite (LED1,LOW);
  delay(10);

  digitalWrite (LED2,HIGH);
  delay(500);
  digitalWrite (LED2,LOW);
  delay(10);
}