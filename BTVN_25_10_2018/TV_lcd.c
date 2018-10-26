#use delay(clock =20M)
#define   RS   Pin_e0
#define   RW   Pin_e1
#define   E   Pin_e2
#define   output_lcd   OUTPUT_D
void lcd_command(unsigned int8 MDK) {
   output_low(RW);
   output_low(RS); // RS =0
   output_lcd(MDK);
   output_low(E);
   output_high(E);
   delay_ms(1);
}
void lcd_data(unsigned int8 MHT) {
    output_low(RW);
    output_high(RS); // RS =1
    output_lcd(MHT);
    output_low(E);
    output_high(E);
    delay_ms(1);
}
void lcd_setup() {  
    delay_ms(5);
    lcd_command(0x38);
    delay_ms(5);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);
   delay_ms(2);
}
