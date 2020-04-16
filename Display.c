#include <stdio.h>
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include <stdlib.h>

#define HEX1
#define HEX2
#define HEX3

int main(void){
	int HEX_bits = 0x00000001;  // pattern for HEX displays
	int SW_value, KEY_value;
	volatile float delay_count;   // volatile so the C compiler doesn't remove the loop
	char chaine_recu[10];
	char* ptr_entier;
	int LED_bits  = 0x00000001;
	int entier;
	//int valeur;
    int sens = 0;
	while(1)
	{
		printf("Tu veut afficher quoi?\n");
		fgets(chaine_recu, 10, stdin);

		if(chaine_recu[0]=='r'){
			ptr_entier = &chaine_recu[2];
			entier = atoi(ptr_entier);
			IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE,entier);
		}
		else if(chaine_recu[0]=='a'){
			while(chaine_recu[0]=='a') {    SW_value = IORD_ALTERA_AVALON_PIO_DATA(SLIDER_SWITCHES_BASE);		// read the SW slider switch values
					IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE,SW_value);		// light up the green LEDs




					KEY_value =  IORD_ALTERA_AVALON_PIO_DATA(PUSHBUTTONS_BASE); 		// read the pushbutton KEY values
					if (KEY_value != 0x3)			// check if any KEY was pressed
					{
						HEX_bits = ~SW_value;		// set pattern using SW values

						while (KEY_value != 0x3);	// wait for pushbutton KEY release
					}
					//*(HEX3_HEX0_ptr) = HEX_bits;		// display pattern on HEX3 ... HEX0
					IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,HEX_bits);
					IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE,LED_bits);
					/* rotate the pattern shown on the HEX displays */
					if (LED_bits & 0x000200){
						sens = 1;}
					else if (LED_bits & 0x000001)
						{sens = 0;}

					if (sens == 1)
						LED_bits = LED_bits >> 1;
					else if (sens==0)
						LED_bits = LED_bits << 1;
					//else if(HEX_bits & 0x00000200)
					//	HEX_bits = (1 << HEX_bits) | 512;
					//else if(HEX_bits & 0x00000001)
						//HEX_bits = HEX_bits << 1;
					/*if (HEX_bits & 0x00000200)
											HEX_bits = (HEX_bits << 1) | 1;
					else
						HEX_bits = HEX_bits << 1;*/
					printf("SW:%x\n", SW_value);
					if(chaine_recu[0]=='b'){
						break;
					}
					for (delay_count = (300000/(1+SW_value)); delay_count != 0; --delay_count); // delay loop

			 }
			}
		else if(chaine_recu[0]=='h'){
			ptr_entier = &chaine_recu[3];
			entier = atoi(ptr_entier);
			switch(chaine_recu[1]){
			case '0':
				switch(entier){
				case 0:
					IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF40);
					break;
				case 1:
					IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFFF9);
					break;
				case 2:
					IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF24);
					break;
				case 3:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF30);
									break;
				case 4:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF19);
									break;
				case 5:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF12);
									break;

				case 6:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF02);
									break;
				case 7:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFFF8);
									break;

				case 8:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF00);
									break;

				case 9:
									IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFFF10);
									break;

									}break;
				case '1':
					switch(entier){
					case 0:
						IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF40FF);
						break;
					case 1:
						IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFF9FF);
						break;
					case 2:
						IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF24FF);
						break;
					case 3:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF30FF);
										break;
					case 4:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF19FF);
										break;
					case 5:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF12FF);
										break;

					case 6:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF02FF);
										break;

					case 7:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFFF8FF);
										break;

					case 8:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF00FF);
										break;

					case 9:
										IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFFF10FF);
										break;


						}break;
					case '2':
										switch(entier){
										case 0:
											IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF40FFFF);
											break;
										case 1:
											IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFF9FFFF);
											break;
										case 2:
											IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF24FFFF);
											break;
										case 3:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF30FFFF);
															break;
										case 4:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF19FFFF);
															break;
										case 5:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF12FFFF);
															break;

										case 6:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF02FFFF);
															break;

										case 7:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFFF8FFFF);
															break;

										case 8:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF00FFFF);
															break;

										case 9:
															IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xFF10FFFF);
															break;


											}break;
										case '3':
															switch(entier){
															case 0:
																IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x40FFFFFF);
																break;
															case 1:
																IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xF9FFFFFF);
																break;
															case 2:
																IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x24FFFFFF);
																break;
															case 3:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x30FFFFFF);
																				break;
															case 4:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x19FFFFFF);
																				break;
															case 5:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x12FFFFFF);
																				break;

															case 6:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x02FFFFFF);
																				break;

															case 7:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0xF8FFFFFF);
																				break;

															case 8:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x00FFFFFF);
																				break;

															case 9:
																				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_HEX0_BASE,0x10FFFFFF);
																				break;


																}break;





					}

			}
	}


}


