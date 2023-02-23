#include <16F877a.h>
#device ADC=10
#use delay(crystal=20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP

#define LCD_DATA_PORT   0X07 //Utilizar LCD en puerto C
#define LCD_ENABLE_PIN  PIN_C1
#define LCD_RS_PIN      PIN_C3
#define LCD_RW_PIN      PIN_C2
#define LCD_DATA4       PIN_C4
#define LCD_DATA5       PIN_C5
#define LCD_DATA6       PIN_C6
#define LCD_DATA7       PIN_C7

#include <lcd.c> //Incluir librería LCD

const char letrero[] = "Esta es una cadena muy muy larga.";
const int8 len_letrero = 33;

void actualizar_disp(int8 start){
   for(int8 index = 0; index < 16; index++){
     printf(lcd_putc,"%c",letrero[index + start]);
   }
}

void main()
{
   lcd_init(); //Inicializar librería
   
   int8 cont = 0;
   while(1){
      printf(lcd_putc,"\f");
      actualizar_disp(cont);
      cont++;
      if(cont + 16 > len_letrero){
         cont = 0;
      }
      delay_ms(400);
   }
   /*
   int8 contador = 0;
   lcd_putc("\fNumero: ");
   lcd_putc("esta es una cadena muy muy muy larga");
   
   while(TRUE)
   {
      lcd_gotoxy(9,1);
      printf(lcd_putc,"%03u",contador);
      contador++;
      delay_ms(100);
   }
   */
}


