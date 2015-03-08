
/*
 Затухание
 
 Пример показывает, как управлять затуханием светодиода на выводе 10,
 используя функцию analogWrite()

 */
int Pin_In = 13;
int Pin_Out = 12;
int brightness = 0;    // начальная яркость светодиода
int fadeAmount = 5;    // величина изменения яркости светодиода
int DelayLED = 50;
int Order = 0;
boolean Order_Increase = true;
boolean ToLH = 1;


String val;

void setup()  {
 int i;
  Serial.begin(9600);
  Serial.write("Power On"); 
  // используем вывод 13-8 для операции вывода
  for (i = 4; i <= 13; i++)
  {
  pinMode(i, OUTPUT);
  }
} 
boolean state = 0;

void loop()  {
  int i; 
  while (Serial.available()) { //Пришла команда
    val = Serial.read() ;
    if (val == "Enable") state = 1;
    if (val == "Disabl") state = 0;
    if(state)
    {
      Serial.println("LEDs IS ON");
      for (i = 0; i<= 4; i++)
      {
      digitalWrite(Pin_In-i*2, HIGH);
      digitalWrite(Pin_Out-i*2, LOW);
      }
    }
    else
    { Serial.println("LEDs IS OFF");
      for (i = 0; i<= 4; i++)
      {
      digitalWrite(Pin_In-i*2, LOW);
      digitalWrite(Pin_Out-i*2, LOW);
      }}

  }
}
