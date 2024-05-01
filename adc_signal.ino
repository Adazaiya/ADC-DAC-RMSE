const float pi = 3.14159265358979323846;
const float F = 200.0; 
const float Fs = 10 * F; 
const float duration = 10.0; 
const float M = 1.687; 



void setup() {
  // serial communication
  Serial.begin(9600);

  // Set ADC input pin
  pinMode(A0, INPUT);
  analogReadResolution(12); 

  Serial.println("Generating Table 2"); 
  
}

void loop() {
  float T = 1.0 / Fs; //  sampling period
  int N = Fs * duration; // number of samples

  // Start a timer 
  unsigned long startTime = millis(); // Get the current time in milliseconds

  // Read from the ADC 
  for (int n = 0; n < N; n++) {
    float t = n * T; // Current time
     // Read the ADC value
    float adcValue = analogRead(A0) * (3.3 / 4095); 
    
    Serial.print(t, 4); 
    Serial.print(", ");
    Serial.println(adcValue); 

    delay(1000 / Fs); 

    
    if (millis() - startTime > duration * 1000) { // 10 seconds
      break; 
    }
  }

  // stop the loop
  while (true) {
    delay(100); 
  }
}

