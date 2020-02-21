// This program uses a NORPS 12 Light Dependant Resistor (LDR) which is a variable resistor that is dependant on the amount of light
// available. This would be used to determine the amount of potential solar energy available in an area over a specified 
// amount of time.

float DU = 0.0045; // Range 0.15 to 4.81: 4.81 - 0.15 = 4.66, divide by 1023 = 0.0045
float scale = 0.15; // 0 to start of range
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;
float r1 = 2500;
float voltage = 0.0;
//float resistance = 0.0;
float ldr_res = 0.0; //To calculate the ldr's resistance
float vin = 5.0; //doesnt change
float c=4.9162; //Constant
float m= -0.7205; //slope
float lux= 0.0;
float temp = 0.0; //temporary variable

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    sensorValue = analogRead(sensorPin);
    voltage = sensorValue*DU+scale; // adding scale value brings the value into scale
    Serial.print("The Voltage measured is: ");
    Serial.print(voltage);
    Serial.println(" volts"); //Working

    ldr_res = r1*((vin/voltage)-1); //manipulated voltage divider formula

    Serial.print("The LDR measured is: ");
    Serial.print(ldr_res);
    Serial.println(" Ohms");

    temp = (log(ldr_res)- c)/m;
    float lux = pow(10, temp); 

    Serial.print("The Lux measured is: ");
    Serial.print(lux);
    Serial.println(" lux");
    Serial.print(temp);

    delay(1000);
    
}
