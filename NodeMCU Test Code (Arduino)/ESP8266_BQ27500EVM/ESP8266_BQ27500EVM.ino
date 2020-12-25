#include <Wire.h>
#include "SSD1306Brzo.h"

#define SDA_PIN D1
#define SCL_PIN D2
#define smbusAddress 0x55

//SSD1306Brzo display(0x3c, SDA_PIN, SCL_PIN);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically based on your board's pins_arduino.h

char s[33];

void setup() {
  // put your setup code here, to run once:

  // I2C Setup
  Wire.begin(SDA_PIN, SCL_PIN); //also tried different Pins like 0,2 or D1,D2
  Wire.setClockStretchLimit(35000);
  Wire.setClock(40000);

  // Serial Setup
  Serial.begin(9600);
  Serial.println("\nESP8266 BQ27500EVM");

  //display.init();
  //display.flipScreenVertically();
  //display.clear();

  //display.setFont(ArialMT_Plain_10);
  //display.drawString(0, 0, "Loading ...");
  //display.display();
}

byte ReadByte(uint8_t command) {
  byte b;
  Wire.beginTransmission(smbusAddress);
  Wire.write(command);

  if (Wire.endTransmission(false) == 0) {
    Wire.requestFrom(smbusAddress, 1, true);
    b = Wire.read();
    return b;
  }
  return 0;
}

short ReadInt(uint8_t command) {
  uint8_t b1, b2;
  Wire.beginTransmission(smbusAddress);
  Wire.write(command);
  if (Wire.endTransmission(false) == 0) {
    Wire.requestFrom(smbusAddress, 2, true);
    b1 = Wire.read();
    b2 = Wire.read();
    return b1 | (b2 << 8);
  }
  return 0;
}

void ReadString(char str[], uint8_t command) {
  str[0] = (char)0;
  int n;
  Wire.beginTransmission(smbusAddress);
  Wire.write(command);
  if (Wire.endTransmission(false) == 0) {
    Wire.requestFrom(smbusAddress, 33, true); //hack, instead of 1, request max char[] size per docs
    n = Wire.read();
    //Wire.requestFrom(smbusAddress, n, false); //broken, not sure why
    for (int i = 0; i < n; i++)
      str[i] = (char)Wire.read();
    str[n] = (char)0;
  }
}

void Write_8bit(uint8_t Register, uint8_t Data)
{
  Wire.beginTransmission(smbusAddress); // transmit to device #4
  Wire.write(Register);        // sends five bytes
  Wire.write(Data);            // sends one byte
  Wire.endTransmission();    // stop transmitting
}

void Write_16bit(uint8_t Register, uint16_t Data)
{
  Wire.beginTransmission(smbusAddress); // transmit to device #4
  Wire.write(Register);        // sends five bytes
  Wire.write(Data & 0xFF);
  Wire.write((Data >> 8) & 0xFF);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}


void loop() {

  Serial.println();
  Serial.println();
  Serial.println();

  // Device Name
  Serial.print("Device Name: ");
  ReadString(s, 0x63);
  Serial.println(s);

  // Pack's Voltage
  Serial.print("Pack's Voltage: ");
  Serial.print(ReadInt(0x08));
  Serial.print(" mV , ");
  Serial.print((float)((float)ReadInt(0x08) / 1000));
  Serial.println(" V");

  // Design Capacity
  Serial.print("Design Capacity: ");
  Serial.print(ReadInt(0x3C));
  Serial.println(" mAh");

  // State Of Charge
  Serial.print("State Of Charge: ");
  Serial.print(ReadInt(0x2C));
  Serial.println(" %");

  // Nominal Available Capacity
  Serial.print("Nominal Available Capacity: ");
  Serial.print(ReadInt(0x0C));
  Serial.println(" mAh");

  // Full Available Capacity
  Serial.print("Nominal Available Capacity: ");
  Serial.print(ReadInt(0x0E));
  Serial.println(" mAh");

  // Remaining Capacity
  Serial.print("Remaining Capacity: ");
  Serial.print(ReadInt(0x10));
  Serial.println(" mAh");

  // FullChargeCapacity
  Serial.print("FullCharge Capacity: ");
  Serial.print(ReadInt(0x12));
  Serial.println(" mAh");

  // Average Current
  Serial.print("Average Current: ");
  Serial.print(ReadInt(0x14));
  Serial.println(" mA");

  // Time To Empty
  Serial.print("Time To Empty: ");
  Serial.print(ReadInt(0x16));
  Serial.println(" Minute/(s)");

  // Time To Full
  Serial.print("Time To Full: ");
  Serial.print(ReadInt(0x18));
  Serial.println(" Minute/(s)");

  // Standby Current
  Serial.print("Standby Current: ");
  Serial.print(ReadInt(0x1A));
  Serial.println(" mA");

  // Standby Time To Empty
  Serial.print("Standby Time To Empty: ");
  Serial.print(ReadInt(0x1C));
  Serial.println(" Minute/(s)");

  // Max Load Current
  Serial.print("Max Load Current: ");
  Serial.print(ReadInt(0x1E));
  Serial.println(" mA");

  // Max Load Time To Empty
  Serial.print("Max Load Time To Empty: ");
  Serial.print(ReadInt(0x20));
  Serial.println(" mA");

  // Available Energy
  Serial.print("Available Energy: ");
  Serial.print(ReadInt(0x22));
  Serial.println(" mWh");

  // Average Power
  Serial.print("Average Power: ");
  Serial.print(ReadInt(0x24));
  Serial.println(" mW");

  // Time To Empty At Constant Power
  Serial.print("Time To Empty At Constant Power: ");
  Serial.print(ReadInt(0x26));
  Serial.println(" Minute/(s)");

  // Cycle Count
  Serial.print("Cycle Count: ");
  Serial.print(ReadInt(0x2A));
  Serial.println(" Time/(s)");


  delay(10000);
}
