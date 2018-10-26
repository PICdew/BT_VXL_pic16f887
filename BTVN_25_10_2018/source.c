#include <16f887.h>
#include <TV_key4x4.c>
#include <TV_lcd.c>

#FUSES NOWDT, NOPROTECT, NOLVP, HS, PUT
#use delay(clock = 20M)

unsigned int i, maPhimBam;
unsigned char hang2[16] = {" "};

void lcd_HienThi();

void main() {
   set_tris_e(0x00);
   set_tris_d(0x00);
   set_tris_b(0xF0);
   lcd_setup();
   port_b_pullups(0xF0);

   lcd_command(0x80);
   delay_us(10);
   lcd_data(" DH SPKT TPHCM");
   lcd_command(0xC0);
   while(1) {
    	maPhimBam = key_4x4();
    	if (maPhimBam != 0xFF) {
			if (maPhimBam < 10)
		    	maPhimBam += 0x30; // chuyen so tu 0->9 sang ascii
			else if (maPhimBam >= 10)
				maPhimBam += 0x37; // chuyen ky tu A->F sang ascii
			lcd_HienThi();
      }   
   }
}

void lcd_HienThi() {
   lcd_command(0xC0);
   delay_us(10);
   for (i = 0; i < 15; ++i) {
      hang2[i] = hang2[i + 1];
   }
   hang2[15] = maPhimBam;
   for (i = 0; i < 16; ++i)
      lcd_data(hang2[i]);
}
