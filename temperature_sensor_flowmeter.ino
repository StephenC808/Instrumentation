
// Description: This program takes in analog voltage input from a wheatstone bridge, converts it into a digital input,
// and that digital value is used to calculate voltage, thevanin resistance and use these values to calculate temperature
// in Celsius and Kelvin. The second part of the code reads a pulse from a flowmeter and uses the temperature to calculate
// the energy used.
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float outputValue=0.0;
float R1=2835.0;
float R2=2835.0;
float R3=33027.0;
float vs = 1.39;
float vo = 0.0;
float beta = 3892.0;
float newtemp=0.0;
float Rth =0.0;
int pin = 7; // digital pin 7
float duration;
float freq=0.0;
float HC = 4.184;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin, INPUT);
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  //outputValue = map(sensorValue, 0, 1023, 0.0, 5.0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue*(5.0/1023.0);
 
  // print out the value you read:
  Serial.print("The Voltage measured is: ");
  Serial.print(voltage);
  Serial.println(" volts");

  vo=sensorValue*(1.0/1023.0);
  Rth = (vo*R2*(R1+R3))/((R3*vs)-(vo*R1)-(vo*R3));

  Serial.print("The Rth calculated is: ");
  Serial.print(Rth);
  Serial.println(" Ohms");
    
  newtemp = 1/((exp((Rth/10000))/beta) - (1/298.15));

  Serial.print("The temp calculated is: ");
  Serial.print(newtemp);
  Serial.println(" Kelvin");
  float C = newtemp - 273.15;
  Serial.print(C);
  Serial.println(" Degrees Celsius\n*****************");

  //Flowmeter
  duration = pulseIn(pin,LOW);
  float T = duration/1000;
  float frequency = 1/(2*T);

  Serial.print("Frequency is:");
  Serial.println(frequency*1000);

  Serial.print("Frequency is:");
  Serial.println(frequency);
  Serial.print("Energy is: ");
  Serial.print(frequency*HC*newtemp);
  Serial.println("Joules");

  delay(1000);
  
}
