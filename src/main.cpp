#include <Arduino.h>
#include <Tone.h>

// Sound params ======================================
int speakerOutX = 13;
int sliderInX = A2;

// int speakerOutY = 13;
// int sliderInY = A2;

int DEBUG = 1;

Tone tone1;
// Tone tone2;

int toneX = 0;
// int toneY = 0;

int volume = 70;

bool soundIsOn = true;

// Motors params ==========================================
int m_pwm_X = 10;
int m_in_1_X = 7;
int m_in_2_X = 6;

// int m_pwm_Y = 9;
// int m_in_1_Y = 4;
// int m_in_2_Y = 5;

// Arduino lifecycle =================================================
void setup()
{
  pinMode(speakerOutX, OUTPUT);
  pinMode(sliderInX, INPUT);

  // pinMode(speakerOutY, OUTPUT);
  // pinMode(sliderInY, INPUT);

  pinMode(m_pwm_X, OUTPUT);
  pinMode(m_in_1_X, OUTPUT);
  pinMode(m_in_2_X, OUTPUT);

  // pinMode(m_pwm_Y, OUTPUT);
  // pinMode(m_in_1_Y, OUTPUT);
  // pinMode(m_in_2_Y, OUTPUT);

  tone1.begin(speakerOutX);
  // tone2.begin(speakerOutY);

  if (DEBUG)
  {
    Serial.begin(115200); // Set serial out if we want debugging
  }
}

void loop()
{
  // Play sound from sliders
  int inputValX = analogRead(sliderInX);
  toneX = map(inputValX, 0, 1023, 31, 2000);

  // int inputValY = analogRead(sliderInY);
  // toneY = map(inputValY, 0, 1023, 31, 2000);

  if (soundIsOn)
  {
    tone1.play(toneX, volume);
    // tone2.play(toneY);
  }

  // Move motors from sliders
  int m_speed_X = map(inputValX, 0, 1023, 50, 150);
  digitalWrite(m_in_1_X, HIGH);
  digitalWrite(m_in_2_X, LOW);
  analogWrite(m_pwm_X, m_speed_X);

  // int m_speed_Y = map(inputValY, 0, 1023, 50, 150);
  // digitalWrite(m_in_1_Y, HIGH);
  // digitalWrite(m_in_2_Y, LOW);
  // analogWrite(m_pwm_Y, m_speed_Y);

  // Logs
  if (DEBUG)
  {
    Serial.print("X: ");
    Serial.print(inputValX);
    Serial.print(" | ");
    Serial.print(toneX);
    Serial.print(" | ");
    Serial.println(m_speed_X);
    // Serial.print("Y: ");
    // Serial.print(inputValY);
    // Serial.print(" | ");
    // Serial.print(toneY);
    // Serial.print(" | ");
    // Serial.println(m_speed_Y);
  }
}