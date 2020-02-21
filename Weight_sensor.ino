// This program uses a weight sensor connected to a wheatstone bridge of which the output is fed into the arduino
// to calculate the weight placed on the sensor

float DU = 0.0048; // Range 0.15 to 4.81: 4.81 - 0.15 = 4.66, divide by 1023 = 0.0045
float offset=0.0; // 0 to start of range
int sensorPin = A0;    
int sensorValue = 0;
float voltage = 0.0;
float c=2.3687; //Constant
float m= 0.0084; //slope
float weight = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    sensorValue = analogRead(sensorPin);
    voltage = sensorValue*DU-offset; // adding scale value brings the value into scale
    Serial.print("The Voltage measured is: ");
    Serial.print(voltage);
    Serial.println(" volts");

    weight = (voltage-c)/m;
    Serial.print("The weight measured is: ");
    Serial.print(weight);
    Serial.println(" grams"); 

    delay(1000);

    // Connect 5v to pin 7 to reset value when no weight on sensor
    if(digitalRead(7))
    {
      offset = voltage;
    }
}
