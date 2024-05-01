const float pi = 3.14159265358979323846;
const float F = 200.0; 
const float Fs = 10 * F; 
const float duration = 10.0; 
const float M = 1.687; 
void setup() {
  // serial communication
  Serial.begin(9600);


  pinMode(A0, INPUT);
  analogReadResolution(12); 
  
  
}

void loop() {
  float T = 1.0 / Fs; //  sampling period
  int N = Fs * duration; //  number of samples

  Serial.println("Time\ sin_wave\tadc\tRMSE");
 float sumSquareError = 0.0;

  unsigned long startTime = millis(); 

  // Read values
  for (int n = 0; n < N; n++) {
    float t = n * T; // Current 
    float sin_wave = M * sin(2 * pi * F * t);
     float Analog_Value = map(sin_wave, -M, M, 0, 4095); 
    analogWrite(DAC0, Analog_Value); // analog value to DAC
    float adcValue = analogRead(A0) * (3.3 / 4095); 
    float error = sin_wave - adcValue; // Calculate error
    sumSquareError += error * error; // according to given formula

    Serial.print(t);
    Serial.print("\t");
    Serial.print(sin_wave, 3);
    Serial.print("\t");
    Serial.print(adcValue);
    delay(1000 / Fs); 

  
    if (millis() - startTime > duration * 1000) { // 10 seconds
      break; 
    }
  }
  float RMSE=sqrt(sumSquareError/N);
  Serial.print("\nRMSE ");
  Serial.println(RMSE,3);

  //  stop the loop
  while (true) {
    delay(100); 
  }
}



