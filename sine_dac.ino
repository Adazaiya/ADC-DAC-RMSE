const float pi = 3.14159265358979323846;
const float F = 200.0; 
const float Fs = 10 * F; 
const float duration = 10.0; 
const float M = 1.687; 
void setup() {
Serial.begin(9600);


  pinMode(DAC0, OUTPUT);

  // Set ADC pin as input
  pinMode(A0, INPUT);
  Serial.println("Generating Table 1"); // generating the table

  
}

void loop() {
  
    float T = 1 / Fs; // sampling period
    int N = Fs * duration; //  total number of samples

    // timer
    unsigned long startTime = millis(); 

    for (int n = 0; n < N; n++) {
      float t = n * T;
      float sin_wave = M * sin(2 * pi * F * t);
      float Analog_Value = map(sin_wave, -M, M, 0, 4095); // mapping
      analogWrite(DAC0, Analog_Value); // Output analog value to DAC
         Serial.print("\t");
      Serial.println(sin_wave, 3);
      delay(1000 / Fs); // sampling rate
      analogReadResolution(12);
 
    
    // 
    if (millis() - startTime > duration * 1000) { // 10 seconds
      break; // Exit the loop 
    }
    }

    
    while (true){
    delay(1000);
    }
}

