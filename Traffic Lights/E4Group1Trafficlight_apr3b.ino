#define RED1 7
#define YELLOW1 8
#define GREEN1 9

#define RED2 10
#define YELLOW2 11
#define GREEN2 3

void setup() {
  // Set the LED pins as outputs
  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
}

void loop() {
   // Intersection 1
  // Red
  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(GREEN2, HIGH);
  delay(5000); // Red light for 5 seconds
  
  // Yellow
  digitalWrite(RED1, LOW);
  digitalWrite(YELLOW1, HIGH);
  digitalWrite(GREEN2, HIGH);
  delay(2000); // Yellow light for 2 seconds

  // Green
  digitalWrite(YELLOW1, LOW);
  digitalWrite(GREEN1, HIGH);
  digitalWrite(RED2, HIGH);
  digitalWrite(GREEN2, LOW);
  delay(3000); // Green light for 5 seconds

  // Intersection 2
  // Red
  digitalWrite(RED2, HIGH);
  digitalWrite(GREEN2, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN1, HIGH);
  delay(5000); // Red light for 5 seconds
  
  // Yellow
  digitalWrite(RED2, LOW);
  digitalWrite(YELLOW2, HIGH);
  digitalWrite(GREEN1, HIGH);
  delay(2000); // Yellow light for 2 seconds

  // Green
  digitalWrite(YELLOW2, LOW);
  digitalWrite(GREEN2, HIGH);
  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN1, LOW);
  delay(3000); // Green light for 5 seconds

}
