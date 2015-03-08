
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
void setup()  {
 int i; 
  // используем вывод 13-8 для операции вывода
  for (i = 4; i <= 13; i++)
  {
  pinMode(i, OUTPUT);
  }
} 

void loop()  { 
  analogWrite(Pin_In - Order*2 , brightness);
  analogWrite(Pin_Out - Order*2 , 0); 
  // изменяем яркость в цикле, прибавляя заданную величину
  brightness = brightness + fadeAmount;
if ((Order == 4)&&(brightness == 0))
{ int i;
  for (i = 1; i<= 10; i++)
  {
  analogWrite(13 , 255);
  analogWrite(12 , 0);
   analogWrite(11 , 255);
  analogWrite(10 , 0); 
   analogWrite(9 , 255);
  analogWrite(8 , 0); 
   analogWrite(7 , 255);
  analogWrite(6 , 0); 
   analogWrite(5 , 255);
  analogWrite(4 , 0);
  delay(10);
  analogWrite(13 , 0);
  analogWrite(12 , 0);
   analogWrite(11 , 0);
  analogWrite(10 , 0); 
   analogWrite(9 , 0);
  analogWrite(8 , 0); 
   analogWrite(7 , 0);
  analogWrite(6 , 0); 
   analogWrite(5 , 0);
  analogWrite(4 , 0);
  delay(50);
  } 
}
  // меняем порядок затухания на обратный при достижении минимальной или максимальной яркости 
if (brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount ;
  } 
  
 //if (brightness == 1) 
   // {
     // Order = Order + 1;
     // if (Order = 2)
      //  {
      //    Order = 0;
      //  }
  //  }   
  // делаем небольшую паузу для лучшего эффекта
 delay(5);
 
 if (brightness == 0)
  { if (Order == 4)
    {
       Order_Increase = false;
    } 
    if (Order == 0)
    {
       Order_Increase = true;
    }
    if (Order_Increase == true)
    {  
       Order = Order + 1;
    }
    else
    {  
       Order = Order - 1;
    }    
  } 
}
