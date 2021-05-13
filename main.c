#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include <xc.h>
#include <PIC18F4520.h>

#pragma config OSC = INTIO67 // Oscillator Selection bits
#pragma config WDT = OFF     // Watchdog Timer Enable bit 
#pragma config PWRT = OFF    // Power-up Enable bit
//#pragma config BOREN = ON   // Brown-out Reset Enable bit
//#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF     // Low Voltage (single -supply) In-Circute Serial Pragramming Enable bit
#pragma config CPD = OFF     // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)
#define _XTAL_FREQ 200000
#define rc0 PORTCbits.RC0
#define rc1 PORTCbits.RC1 
#define rc2 PORTEbits.RE0 
#define rc3 PORTCbits.RC3 
#define rc4 PORTCbits.RC4 
#define rc5 PORTCbits.RC5 
#define rc6 PORTEbits.RE1 
#define rc7 PORTEbits.RE2 

char str[20];

void setBits(unsigned char a,unsigned char b,unsigned char c,unsigned char d,unsigned char e,unsigned char f,unsigned char g,unsigned char h){
    rc0=a;
    rc1=b;
    rc2=c;
    rc3=d;
    rc4=e;
    rc5=f;
    rc6=g;
    rc7=h;
}

void main(void) 
{
    //oscillator frequency=4MHZ
//    OSCCONbits.IRCF = 0b110;
    //Initialize TRISD
    TRISD=0;
    TRISC=0;
    TRISE=0;
    TRISA=1;
    PORTC = 0;
    //select VREF default Vss Vdd   
    ADCON1bits.VCFG1=0b0;
    ADCON1bits.VCFG0=0b0;
    //select port control
    ADCON1bits.PCFG=0b1110;
    //select input channel AN0
//    ADCON0bits.CHS=0b0000;
    //select conversion clock
    ADCON2bits.ADCS=0b100;    
    //select acquisition time
    ADCON2bits.ACQT=0b010;
    //Turn on module
    ADCON0bits.ADON=0b1;
    //select justified method
    ADCON2bits.ADFM=0b0;
    //initializing interrupt
//    RCONbits.IPEN=0b1;
//    INTCONbits.GIEH=0b1;
//    PIE1bits.ADIE=0b1;
//    PIR1bits.ADIF=0b0;
//    IPR1bits.ADIP=0b1;
//    ADCON0bits.GO_nDONE=0b1;
//    while(1);
    
    SYSTEM_Initialize() ;
    int check = 0;
    
//    UART_Write_Text("One day a person is ");
    while(1) {
        // TODO 
        strncpy(str,GetString(),5);
        str[5]='\0';
        if(strcmp(str,"start") == 0) {
            ClearBuffer();
            UART_Write_Text("\nOne day a girl is ");
            ClearBuffer();
        }
        unsigned int x = ADC_Read(0);
//        char out[10];
//        sprintf(out,"%4d",x);
//        UART_Write_Text(out);
//        if(check == 1) {
//            UART_Write_Text("One day a person is ");
//            check = 0;
//        }
        if(0<=x&&x<23){             //1, walking1
            if(check == 0) {
                UART_Write_Text("walking, ");
                check = 1;
            }
            PORTD = 0b01111111;
            setBits(0,1,0,0,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b10111111;
            setBits(0,0,1,0,0,0,0,1);
            __delay_ms(30);
            PORTD = 0b11011111;
            setBits(1,1,0,1,0,1,1,1);
            __delay_ms(30);
            PORTD = 0b11101111;
            setBits(1,1,1,1,1,0,0,0);
            __delay_ms(30);
            PORTD = 0b11110111;
            setBits(1,1,0,1,0,1,0,1);
            __delay_ms(30);
            PORTD = 0b11111011;
            setBits(0,0,0,1,0,0,1,1);
            __delay_ms(30);
            PORTD = 0b11111101;
            setBits(0,0,0,1,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b11111110;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }
        if(23<=x&&x<46){             //2, walking2
            if(check == 1) {
                UART_Write_Text("walking, ");
                check = 0;
            }
            PORTD = 0b00111111;
            setBits(0,0,0,1,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b11011111;
            setBits(1,1,0,1,0,1,0,0);
            __delay_ms(30);
            PORTD = 0b11101111;
            setBits(1,1,1,1,1,0,0,1);
            __delay_ms(30);
            PORTD = 0b11110111;
            setBits(1,1,0,1,0,1,1,1);
            __delay_ms(30);
            PORTD = 0b11111011;
            setBits(0,0,0,0,1,0,0,0);
            __delay_ms(30);
            PORTD = 0b11111101;
            setBits(0,0,0,0,0,1,0,0);
            __delay_ms(30);
            PORTD = 0b11111110;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }  
        else if(46<=x&&x<69){       //3, drink
            if(check == 0) {
                UART_Write_Text("then she felt thirsty, so she decided to buy a bubble tea, ");
                check = 1;
            }
            PORTD = 0b01111111;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b10111111;
            setBits(0,0,1,1,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b11001111;
            setBits(0,0,1,1,1,1,1,1);
            __delay_ms(30);
            PORTD = 0b11110111;
            setBits(1,1,1,1,1,1,1,1);
            __delay_ms(30);
            PORTD = 0b11111011;
            setBits(1,0,1,1,1,1,1,1);
            __delay_ms(30);
            PORTD = 0b11111101;
            setBits(1,0,1,1,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b11111110;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }
        else if(69<=x&&x<92){        //4, fall1
            if(check == 1) {
                UART_Write_Text("after she got the drink, ");
                check = 0;
            }
            PORTD = 0b01110111;
            setBits(0,0,0,1,0,0,0,1);
            __delay_ms(30);
            PORTD = 0b10101111;
            setBits(1,1,1,0,1,0,1,0);
            __delay_ms(30);
            PORTD = 0b11011111;
            setBits(1,1,1,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b11111000;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }
        else if(92<=x&&x<115){      //5, fall2
            if(check == 0) {
                UART_Write_Text("she was too excited ");
                check = 1;
            }
            PORTD = 0b01111111;
            setBits(0,0,0,1,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b10111111;
            setBits(0,0,0,0,1,0,0,0);
            __delay_ms(30);
            PORTD = 0b11011111;
            setBits(0,1,1,0,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b11101111;
            setBits(0,0,0,1,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b11110011;
            setBits(1,1,1,0,1,0,0,0);
            __delay_ms(30);
            PORTD = 0b11111101;
            setBits(1,1,1,0,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b11111110;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }
        else if(115<=x&&x<138){     //6, fall3
            if(check == 1) {
                UART_Write_Text("that all of a sudden she fall down ");
                check = 0;
            }
            PORTD = 0b01111111;
            setBits(0,0,1,0,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b10111111;
            setBits(0,0,0,1,0,1,0,0);
            __delay_ms(30);
            PORTD = 0b11011111;
            setBits(0,0,0,0,1,0,0,0);
            __delay_ms(30);
            PORTD = 0b11101111;
            setBits(0,0,0,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b11110111;
            setBits(0,0,1,0,1,0,1,0);
            __delay_ms(30);
            PORTD = 0b11111011;
            setBits(0,0,0,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b11111101;
            setBits(0,0,0,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b11111110;
            setBits(0,0,0,1,1,1,0,0);
            __delay_ms(10);
        }
        else if(138<=x&&x<161){     //7, drink
            if(check == 0) {
                UART_Write_Text("at the same time the drink ");
                check = 1;
            }
            PORTD = 0b01111111;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b10111111;
            setBits(0,0,1,1,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b11001111;
            setBits(0,0,1,1,1,1,1,1);
            __delay_ms(30);
            PORTD = 0b11110111;
            setBits(1,1,1,1,1,1,1,1);
            __delay_ms(30);
            PORTD = 0b11111011;
            setBits(1,0,1,1,1,1,1,1);
            __delay_ms(30);
            PORTD = 0b11111101;
            setBits(1,0,1,1,0,0,0,0);
            __delay_ms(30);
            PORTD = 0b11111110;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }
        else if(161<=x&&x<184){     //8, X
            if(check == 1) {
                UART_Write_Text("is split, ");
                check = 0;
            }
            PORTD = 0b10111101;
            setBits(0,1,0,0,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b11011011;
            setBits(0,0,1,0,0,1,0,0);
            __delay_ms(30);
            PORTD = 0b11100111;
            setBits(0,0,0,1,1,0,0,0);
            __delay_ms(30);
            PORTD = 0b01111110;
            setBits(1,0,0,0,0,0,0,1);
            __delay_ms(30);
        }
        else if(184<=x&&x<210){     //9, sad
            if(check == 0) {
                UART_Write_Text("she was so sad QQ, ");
                check = 1;
            }
            PORTD = 0b01111110;
            setBits(0,0,1,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b10111101;
            setBits(0,1,0,0,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b11011011;
            setBits(1,0,1,0,0,1,0,1);
            __delay_ms(30);
            PORTD = 0b11100111;
            setBits(1,0,0,0,1,0,0,1);
            __delay_ms(30);
            PORTD = 0b11011011;
            setBits(0,0,1,0,0,0,0,0);
            __delay_ms(30);
        }
        else if(210<=x&&x<233){     //10, 101
            if(check == 1) {
                UART_Write_Text("but the salesperson told her that she was the 101st person to split the drink here, ");
                check = 0;
            }
            PORTD = 0b01111110;
            setBits(0,1,1,1,1,1,1,0);
            __delay_ms(30);
            PORTD = 0b11011011;
            setBits(0,0,1,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b11100111;
            setBits(0,1,0,0,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b10111101;
            setBits(0,0,0,0,0,0,0,0);
            __delay_ms(30);
        }
        else if(233<=x){            //11, happy
            if(check == 0) {
                UART_Write_Text("so she got a brand new drink. > < ");
                check = 1;
            }
            PORTD = 0b01111110;
            setBits(0,0,1,1,1,1,0,0);
            __delay_ms(30);
            PORTD = 0b10111101;
            setBits(0,1,0,0,0,0,1,0);
            __delay_ms(30);
            PORTD = 0b11011011;
            setBits(1,0,1,0,1,0,0,1);
            __delay_ms(30);
            PORTD = 0b11100111;
            setBits(1,0,0,0,0,1,0,1);
            __delay_ms(30);
            PORTD = 0b11011011;
            setBits(0,0,1,0,0,0,0,0);
            __delay_ms(30);
        }
        /*strncpy(str,GetString(),1);
        str[1]='\0';
        if(strcmp(str,"1") == 0) {
            ClearBuffer();
            UART_Write_Text("Enter mode1");
            ClearBuffer();
            PORTD = 0;
            rc0=1;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            ClearBuffer();
        }
        else if(strcmp(str,"2") == 0) {
            ClearBuffer();
            
            while(1) {
                strcpy(str,GetString());
                if(str[0]=='e'){
                   ClearBuffer();
                   break; 
                }
                float x = ADC_Read(7);
                x = x / 1023 * 5;
                char out[10];
                sprintf(out,"%.2f",x);
                UART_Write_Text(out);
                for(int i = 0; i < 1000; i++);
                     
                //__delay_ms(1000);
                     }
            ClearBuffer();
        }*/
    }
    return;  
}

// old version: 
// void interrupt high_priority Hi_ISR(void)
void __interrupt(high_priority) Hi_ISR(void)
{
     if(PIR1bits.CCP1IF == 1) {
        RC2 ^= 1;
        PIR1bits.CCP1IF = 0;
        TMR3 = 0;
    }
   /* if(PIR1bits.ADIF == 1) {
        unsigned int x = ADRESH;
        if(0<=x&&x<32){
            PORTD = 0b11111111;
            rc0=0;
            rc1=0;
            rc2=0;
            rc3=0;
            rc4=0;
            rc5=0;
            rc6=0;
            rc7=0;
        }
        if(32<=x&&x<64){
            PORTD = 0b01111111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(50);
            PORTD = 0b10111111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }  
        else if(64<=x&&x<96){
            PORTD = 0b01111111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b10111111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11011111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11101111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        else if(96<=x&&x<128){
            PORTD = 0b01111111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b10111111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11011111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11101111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11110111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111011;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        else if(128<=x&&x<160){
            PORTD = 0b01111111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b10111111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11011111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11101111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11110111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11111011;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111101;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111110;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        else if(160<=x&&x<192){
            PORTD = 0b11111111;
            rc0=0;
            rc1=0;
            rc2=0;
            rc3=0;
            rc4=0;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        else if(192<=x&&x<224){
            PORTD = 0b01111111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b10111111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11011111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11101111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11110111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11111011;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111101;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111110;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        else if(224<=x&&x<256){
            PORTD = 0b11111111;
            rc0=0;
            rc1=0;
            rc2=0;
            rc3=0;
            rc4=0;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        else if(256<=x){
            PORTD = 0b01111111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b10111111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11011111;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11101111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11110111;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=1;
            __delay_ms(30);
            PORTD = 0b11111011;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=1;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111101;
            rc0=0;
            rc1=1;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=1;
            rc6=0;
            rc7=0;
            __delay_ms(30);
            PORTD = 0b11111110;
            rc0=0;
            rc1=0;
            rc2=1;
            rc3=1;
            rc4=1;
            rc5=0;
            rc6=0;
            rc7=0;
            __delay_ms(30);
        }
        INTCONbits.GIEH=0b1;
        PIR1bits.ADIF=0b0;
        ADCON0bits.GO_nDONE=0b1;
        _delay(50); 
    }*/
    return;
}