// #include <CountDown.h>
// #include <LiquidCrystal.h>

// CountDown CD(CountDown::MILLIS);
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// const int buttonAv = A0; //Avançar A0
// const int buttonCh = A1; //Escolher A1
// const int PWM = 9; // saída pwm para o circuito
// unsigned long demora = 10; //bounce
// unsigned long dezmin = 600000;	// 10 MINUTOS
// unsigned long quinzemin = 900000;	// 15 MINUTOS
// unsigned long vintemin = 1200000;   // 20 MINUTOS
// byte AvSt = 0; //avanca estado
// byte ChSt = 0; //escolhe estado
// int estado;
// byte lbs;


// void setup() {
//   // put your setup code here, to run once:
//   pinMode(buttonAv, INPUT_PULLUP);
//   pinMode(buttonCh, INPUT_PULLUP);
//   pinMode(PWM, OUTPUT);
//   analogWrite(PWM, 0);
//   lcd.begin(16, 2);
//   lcd.print("Welcome to tdcs");
//   delay(900);
//   estado = 0;
 
// }

// bool Edge(byte sig) {

//   if (sig != lbs){ //
// //	lbs = sig;    
//    if (sig == 1) {
//    lbs = sig;    
//    return 1;
// //   lbs = sig;
// 	}
//    else {
// 	lbs = sig;
// 	return 0;
//    }
//   }
//   else {
// 	lbs = sig;
// 	return 0;
//   }
// }



// void MaqEst(){

//   AvSt = digitalRead(buttonAv);
//   ChSt = digitalRead(buttonCh);  
 
//   switch (estado)
//   {
    
// 	case 0:
// 	delay(100);
// 	lcd.clear();
// 	lcd.home();    
// 	lcd.print("Welcome to 0");
// 	estado = 1;
// 	break;
	 
// 	case 1:
// 	delay(100);
// 	lcd.clear();
// 	lcd.home();
// 	lcd.print("Welcome to tdcs!");
// 	delay(1000);
// 	if ( !((Edge(ChSt)) ^ (Edge(AvSt))) ){ //
//   	lcd.clear();
//   	lcd.print("Escolha o tempo");
//   	lcd.setCursor(1,1);
//   	lcd.print("10min   ");
//   	estado = 2;
//   	}
// //	else if (((Edge(AvSt)) == false)   ){ //|| ((Edge(AvSt))== false
//   //	lcd.clear();
// //  	lcd.print("Escolha o tempo");
// //  	lcd.setCursor(1,1);
// //  	lcd.print("10min   ");
// //  	estado = 2;
// //  	}
// 	else {
//   	estado = 1;
// 	}
//   	break;
 	 
//  	case 2:
//  	delay(100);
//  	if (((Edge(ChSt))== true) & ((Edge(AvSt))== false)){
//   	lcd.clear();
//   	lcd.print("Escolha o tempo");
//   	lcd.setCursor(1,1);
//   	lcd.print(" 	15min");
//   	estado = 3; 	 
//  	}
//  	else if ( ((Edge(ChSt))== false) & ((Edge(AvSt))== true) ){
//   	demora = dezmin;  //10 minutos
//   	lcd.clear();
//   	delay(50);
//   	lcd.print("Escolha corrente");
//   	lcd.setCursor(1,1);
// //  	lcd.print("1mA 1,5mA 2mA");
//   	lcd.print("1mA      	");
//   	estado = 5; 	 
//  	}
//  	else {
//   	estado = 2;
//  	}
//  	break;

//  	case 3:
//  	delay(100);
//  	if (((Edge(ChSt))== true) & ((Edge(AvSt))== false)){
//   	lcd.clear();
//   	lcd.print("Escolha o tempo");
//   	lcd.setCursor(1,1);
//   	lcd.print("      	20min");
//   	estado = 4; 	 
//  	}
//  	else if (((Edge(ChSt))== 0) & ((Edge(AvSt))==1)){
//   	demora = quinzemin; //15 minutos
//   	lcd.clear();
//   	delay(50);
//   	lcd.print("Escolha corrente");
//   	lcd.setCursor(1,1);
// //  	lcd.print("1mA 1,5mA 2mA");
//   	lcd.print("1mA      	");
//   	estado = 5; 	 
//  	}
//  	else {
//   	estado = 3;
//  	}
//  	break;	 

//  	case 4:
//  	delay(100);
//  	if (((Edge(ChSt))== true) & ((Edge(AvSt))== false)){
//   	lcd.clear();
//   	lcd.print("Escolha o tempo");
//   	lcd.setCursor(1,1);
//   	lcd.print("10min");
//   	estado = 2; 	 
//  	}
//  	else if (((Edge(ChSt))== 0) & ((Edge(AvSt))==1)){
//   	demora = vintemin; //20 minutos  
//   	lcd.clear();
//   	delay(100);
//   	lcd.print("Escolha corrente");
//   	lcd.setCursor(1,1);
// //  	lcd.print("1mA 1,5mA 2mA");
//   	lcd.print("1mA      	");
//   	estado = 5; 	 
//  	}
//  	else {
//   	estado = 4;
//  	}
//  	break;	 

//  	case 5:
//  	delay(100);
//  	if (((Edge(ChSt))== true) & ((Edge(AvSt))== false)){
//   	lcd.clear();
//   	lcd.print("Escolha corrente");
//   	lcd.setCursor(1,1);
//   	lcd.print("	1,5mA	");
//   	estado = 6; 	 
//  	}
//  	else if ( ( (Edge(ChSt)) == 0) & ( (Edge(AvSt))==1) ){
//   	lcd.clear();
//   	lcd.home();
//   	umV(demora); //1 mA
//   	delay(50);
//   	lcd.clear();
//   	lcd.print("Concluido");
//   	delay(5000);
//   	estado = 1; 	 
//  	}
//  	else {
//   	estado = 5;
//  	}
//  	break;	 

//  	case 6:
//  	delay(100);
//  	if (((Edge(ChSt))== true) & ((Edge(AvSt))== false)){
//   	lcd.clear();
//   	lcd.print("Escolha corrente");
//   	lcd.setCursor(1,1);
//   	lcd.print("      	2mA");
//   	estado = 7; 	 
//  	}
//  	else if ( ( (Edge(ChSt) ) == 0) & ( ( Edge(AvSt) ) == 1) ){
//   	lcd.clear();
//   	lcd.home();
//   	ummeioV(demora); //1,5 mA
//   	delay(50);
//   	lcd.clear();
//   	lcd.print("Concluido");
//   	delay(5000);
//   	estado = 1; 	 
//  	}
//  	else {
//   	estado = 6;
//  	}
//  	break;	 

//  	case 7:
//  	delay(100);
//  	if (((Edge(ChSt))== true) & ((Edge(AvSt))== false)){
//   	lcd.clear();
//   	lcd.print("Escolha corrente");
//   	lcd.setCursor(1,1);
//   	lcd.print("1mA      	");
//   	estado = 5; 	 
//  	}
//  	else if ( ((Edge(ChSt))== 0) & ((Edge(AvSt) )== 1) ){
//   	lcd.clear();
//   	lcd.home();
//   	doisV(demora); //2 mA
//   	delay(50);
//   	lcd.clear();
//   	lcd.print("Concluido");
//   	delay(5000);
//   	estado = 1; 	 
//  	}
	 
//  	else {
//   	estado = 7;
//   	}
//  	break;	 
 
//   }
// }


// void loop() {


//   MaqEst();
 
// }

// // 0.1mA - 5.2
// // 1mA - 51
//  // +26
// // 1.5mA - 77
//  // +25
// // 2.0mA - 102

// void umV(unsigned long dem){  // 20% e 1V
 
//   uint32_t start, stop;
//   start = millis();
//   CD.start(dem);
//   while (CD.remaining() > 0 )
//   {
//  	int sec = (CD.remaining())/1000;
//  	int minu = (CD.remaining())/60000;
//  	analogWrite(PWM, 51);
//  	lcd.clear();
//  	lcd.home();
//  	if (minu < 10){
//   	lcd.print("0");
//  	}
//  	if (minu < 1){
//   	minu = 0;
//  	}
//  	lcd.print(minu);	 
//  	lcd.print(":");
//  	if( minu >= 1){
//   	sec = (sec  - (60*minu));
//  	}
//  	if (sec < 10){
//   	lcd.print("0");
//  	}
//  	lcd.print(sec);
//  	delay(50);
	 
//   }
// 	analogWrite(PWM, 0);

// };

// void ummeioV(unsigned long dem){ // 30% e 1,5V
//   int Temp =0;
//   uint32_t temporizadorF = 0;
//   Temp = (dem/1000);
//   while (Temp > 0){
// 	analogWrite(PWM, 77);
// 	lcd.setCursor(0,0);
// 	lcd.print(((Temp/60) / 10));
// 	lcd.print(((Temp/60) % 10));
// 	lcd.print(":");
// 	lcd.print(((Temp%60) / 10));
// 	lcd.print(((Temp%60) % 10));
// 	Temp--;
// 	temporizadorF = millis();

//   }
//   analogWrite(PWM, 0);

// };

// void doisV(unsigned long dem){  	// 40% e 2V
//   int Temp =0;
//   uint32_t temporizadorF = 0;
//   Temp = (dem/1000);
//   while (millis() - temporizadorF >= dem){
// 	analogWrite(PWM, 102);  
// 	lcd.setCursor(0,0);
// 	lcd.print(((Temp/60) / 10));
// 	lcd.print(((Temp/60) % 10));
// 	lcd.print(":");
// 	lcd.print(((Temp%60) / 10));
// 	lcd.print(((Temp%60) % 10));
// 	Temp--;
// 	temporizadorF = millis();
//   }
 
//   analogWrite(PWM, 0);

// };


