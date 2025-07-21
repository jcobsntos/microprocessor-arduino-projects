// Pin configuration
const int segmentPins[][7] = {
  {2, 3, 4, 5, 6, 7, 8},   // Segment pins for first display
  {11, 12, 13, A0, A1, A2, A3} // Segment pins for second display
};

const int commonPins[] = {9, 10}; // Pins for common cathodes of the displays

// Define segment patterns for each digit (0-9)
const byte digitPatterns[][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Initialize pin modes
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[0][i], OUTPUT);
    digitalWrite(segmentPins[0][i], LOW); // Segments are initially off for first display
    pinMode(segmentPins[1][i], OUTPUT);
    digitalWrite(segmentPins[1][i], LOW); // Segments are initially off for second display
  }
  
  for (int i = 0; i < 2; i++) {
    pinMode(commonPins[i], OUTPUT);
    digitalWrite(commonPins[i], HIGH); // Common cathodes are active low
  }
}

// Function to display a two-digit number
void displayNumber(int num) {
  int tens = num / 10;
  int ones = num % 10;

  // Display tens place for first display
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[0][i], digitPatterns[tens][i]);
  }
  digitalWrite(commonPins[0], LOW); // Turn on first display
  digitalWrite(commonPins[1], HIGH); // Turn off second display
  delay(2); // Adjust delay as needed for brightness

  // Display ones place for second display
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[1][i], digitPatterns[ones][i]);
  }
  digitalWrite(commonPins[0], HIGH); // Turn off first display
  digitalWrite(commonPins[1], LOW); // Turn on second display
  delay(2); // Adjust delay as needed for brightness
}

void loop() {
  // Display numbers from 00 to 99
  for (int num = 0; num < 100; num++) {
    displayNumber(num);
    delay(100); // Adjust delay as needed
  }

  // Display numbers from 99 to 00
  for (int num = 99; num >= 0; num--) {
    displayNumber(num);
    delay(100); // Adjust delay as needed
  }
}
