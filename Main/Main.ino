#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Configuration
const int IR_ENTER = 2;
const int IR_EXIT = 4;
const int SERVO_PIN = 3;
const int SLOT_PINS[] = {5, 6, 7, 8, 9, 10};  // Slots 1-6
const int TOTAL_SLOTS = 6;

// LCD Configuration
const int LCD_ADDRESS = 0x27; // Change to 0x3F if needed
const int LCD_COLS = 20;
const int LCD_ROWS = 4;

// Global Objects
Servo barrier;
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

// System State
bool slotStatus[TOTAL_SLOTS] = {0};  // true = occupied, false = empty
bool flagEntry = false;
bool flagExit = false;
int availableSlots = TOTAL_SLOTS;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing System...");

  // Initialize IR sensors
  pinMode(IR_ENTER, INPUT);
  pinMode(IR_EXIT, INPUT);
  for (int i = 0; i < TOTAL_SLOTS; i++) {
    pinMode(SLOT_PINS[i], INPUT);
  }
  
  // Initialize barrier
  barrier.attach(SERVO_PIN);
  barrier.write(90);  // Close barrier
  
  // Initialize LCD
  lcd.init();  // Use lcd.init() instead of lcd.begin()
  lcd.backlight();  // Ensure backlight is on
  Serial.println("LCD Initialized.");

  showWelcomeMessage();
  
  // Initial system update
  updateSlotStatus();
  displayStatus();
}

void loop() {
  updateSlotStatus();
  displayStatus();
  handleEntryExit();
  delay(1);
}

// Welcome Message Display
void showWelcomeMessage() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Smart Parking System ");
  delay(3000);  // Increase delay to give LCD time to display
  lcd.clear();
}

// Read parking slot status
void updateSlotStatus() {
  int occupied = 0;
  for (int i = 0; i < TOTAL_SLOTS; i++) {
    slotStatus[i] = (digitalRead(SLOT_PINS[i]) == LOW);
    if (slotStatus[i]) occupied++;
  }
  availableSlots = TOTAL_SLOTS - occupied;
}

// Display slot status on LCD
void displayStatus() {
  lcd.clear();
  
  // Show available slots
  lcd.setCursor(0, 0);
  lcd.print("Available: ");
  lcd.print(availableSlots);
  lcd.print("  ");  // Clear extra spaces

  // Show status for each pair of slots
  for (int i = 0; i < TOTAL_SLOTS; i += 2) {
    lcd.setCursor(0, (i / 2) + 1);
    lcd.print("S");
    lcd.print(i + 1);
    lcd.print(":");
    lcd.print(slotStatus[i] ? "Full " : "Empty");

    lcd.setCursor(10, (i / 2) + 1);
    lcd.print("S");
    lcd.print(i + 2);
    lcd.print(":");
    lcd.print(slotStatus[i + 1] ? "Full " : "Empty");
  }
}

// Handle Entry & Exit
void handleEntryExit() {
  // Handle vehicle entry
  if (digitalRead(IR_ENTER) == LOW && !flagEntry) {
    if (availableSlots > 0) {
      flagEntry = true;
      if (!flagExit) {
        barrier.write(180);  // Open barrier
      }
    } else {
      showParkingFullMessage();
    }
  }

  // Handle vehicle exit
  if (digitalRead(IR_EXIT) == LOW && !flagExit) {
    flagExit = true;
    if (!flagEntry) {
      barrier.write(180);  // Open barrier
    }
  }

  // Reset barrier after vehicle passes
  if (flagEntry && flagExit) {
    delay(1000);
    barrier.write(90);  // Close barrier
    flagEntry = false;
    flagExit = false;
  }
}

// Parking Full Message
void showParkingFullMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Parking Full");
  delay(2000);
  lcd.clear();
}
