const int batteryPin = 6; // Analog pin connected to the voltage divider
  String batterylife;
  const float minVoltage = 1.93; // Minimum voltage of the battery
  const float maxVoltage = 3.24; // Maximum voltage of the battery

//const float minVoltage = 2.8; // Minimum voltage of the battery
//const float maxVoltage = 4.3; // Maximum voltage of the battery
void setup() {
  Serial.begin(9600); // Initialize serial communication
  analogReadResolution(12); // Set ADC resolution to 12 bits (0-4095)
}

void loop() {
  float rawValue = analogRead(batteryPin); // Read the raw ADC value
  float voltage = map(rawValue, 0, 4095, 0, 3240) / 1000.0; // Convert ADC value to voltage (4.2V max)

  unsigned int percentage = map(voltage * 100, minVoltage * 100, maxVoltage * 100, 0, 100); // Calculate voltage percentage
  float Volt1 = voltage*1.3;

  //Serial.print("Battery Voltage: ");
  Serial.print(Volt1);
  Serial.println("V");
  Serial.print("Battery Percentage: ");
  if ( percentage>0)
  {
  Serial.print(percentage);
  Serial.println("%");
  }
  else 
  Serial.println( "power OFF");


  delay(1000); // Delay between measurements
}