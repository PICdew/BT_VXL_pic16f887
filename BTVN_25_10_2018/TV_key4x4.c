#use delay(clock = 20M)


const unsigned char quet_Cot[4] = {0xFE, 0xFD, 0xFB, 0xF7};

unsigned int key_4x4() {
	unsigned int mp=0xff,cot, hang=0xff;
	chongdoi:
	for(cot=0;cot<4;cot++) {
		output_b(quet_Cot[cot]);
		if(!input(pin_b4)) {
			hang=0;
			break;
		}
		if(!input(pin_b5)) {
			hang=1;
			break;
		}
		if(!input(pin_b6)) {
			hang=2;
			break;
		}
		if(!input(pin_b7)) {
			hang=3;
			break;
		}
	}
	if(hang!=0xff) {  
		mp= cot*4 + hang;
		hang=0xff;
		delay_ms(20);
		goto chongdoi;
	}
	return mp;
}