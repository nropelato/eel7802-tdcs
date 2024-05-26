#include <CountDown.h>
#include <LiquidCrystal.h>

CountDown CD(CountDown::MILLIS);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

enum STATES {
  INIT,
  SET_TIME,
  SET_CURRENT,
  SHOW_TIMER
};

const int decrementBtn = A0; //Botão de menos
const int enterBtn = A1; //Botão de OK
const int incrementBtn = A2; //Botão de mais
const int PWM = 9; // saída pwm para o circuito

unsigned long cycleDuration = 600000;	// 10 min
const unsigned long cycleDurationIncrement = 60000; // 1 min

float current = 0.1;
const float currentIncrement = 0.1; // 0.1mA = 5.2
const float pwmIncrement = 5.2; // 0.1mA = 5.2

byte decrementBtnSt = 0; //avanca estado
byte enterBtnSt = 0; //escolhe estado
byte incrementBtnSt = 0; //escolhe estado
enum STATES state;
byte lbs;

void setup() {
  Serial.begin(9600);
  pinMode(decrementBtn, INPUT_PULLUP);
  pinMode(enterBtn, INPUT_PULLUP);
  pinMode(incrementBtn, INPUT_PULLUP);
  pinMode(PWM, OUTPUT);
  analogWrite(PWM, 0);
  lcd.begin(16, 2);
  state = INIT;
}

bool Edge(byte sig) {

  if (sig != lbs){ //
//	lbs = sig;    
   if (sig == 1) {
   lbs = sig;    
   return 1;
//   lbs = sig;
	}
   else {
	lbs = sig;
	return 0;
   }
  }
  else {
	lbs = sig;
	return 0;
  }
}

void MaqEst() {

  decrementBtnSt = digitalRead(decrementBtn);
  enterBtnSt = digitalRead(enterBtn);
  incrementBtnSt = digitalRead(incrementBtn);

  // Serial.print("decrementBtnSt: ");
  // Serial.println(decrementBtnSt);

  // Serial.print("enterBtnSt: ");
  // Serial.println(enterBtnSt);

  // Serial.print("incrementBtnSt: ");
  // Serial.println(incrementBtnSt);

  // Serial.print("PWM: ");
  // Serial.println((current/currentIncrement)*pwmIncrement);

  delay(150);
 
  switch (state) {
	  case INIT:
      lcd.clear();
      lcd.print("Aperte um botao");
      lcd.setCursor(0,1);
      lcd.print("para iniciar");

      if (!decrementBtnSt | !enterBtnSt | !incrementBtnSt) {
        state = SET_TIME;
      }

      break;
	 
    case SET_TIME:
      lcd.clear();
      lcd.print("Escolha o tempo:");
      lcd.setCursor(1,1);
      lcd.print(cycleDuration/60000);
      lcd.print("min");

      if(!enterBtnSt) {
        state = SET_CURRENT;
        break;
      }

      if (decrementBtnSt & !incrementBtnSt) {
        if (cycleDuration < (40 * cycleDurationIncrement))
          cycleDuration += cycleDurationIncrement;
      }
      else if (!decrementBtnSt & incrementBtnSt) {
        if (cycleDuration >= cycleDurationIncrement)
          cycleDuration -= cycleDurationIncrement;
      }

      break;

    case SET_CURRENT:
      lcd.clear();
      lcd.print("Escolha a corrente:");
      lcd.setCursor(1,1);
      lcd.print(current);
      lcd.print("mA");
      
      if(!enterBtnSt) {
        state = SHOW_TIMER;
        break;
      }

      if (decrementBtnSt & !incrementBtnSt) {
        if (current <= 3.9)
          current += currentIncrement;
      }
      else if (!decrementBtnSt & incrementBtnSt) {
        if (current > currentIncrement)
          current -= currentIncrement;
      }

      break;

 	  case SHOW_TIMER:
      uint32_t start, stop;
      start = millis();
      CD.start(cycleDuration);
      analogWrite(PWM, (current/currentIncrement)*pwmIncrement);
      while (CD.remaining() > 0 ) {
        int seconds = floor(CD.remaining()/1000);
        int minutes = floor(seconds/60);
        lcd.clear();
        lcd.print("Tempo: ");
        if (minutes < 10){
          lcd.print("0");
        }
        lcd.print(minutes);	 
        lcd.print(":");
        if( minutes >= 1){
          seconds -= 60 * minutes;
        }
        if (seconds < 10){
          lcd.print("0");
        }
        lcd.print(seconds);
        lcd.setCursor(0,1);
        lcd.print("Corrente: ");
        lcd.print(current);
        lcd.print("mA");
        delay(50);
      }
      analogWrite(PWM, 0);
      state = INIT;
  }
}

void loop() {
  MaqEst();
}
