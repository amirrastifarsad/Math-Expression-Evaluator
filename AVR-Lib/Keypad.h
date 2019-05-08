/*
* Keypad.h
*
* Created: 2/28/2019 9:09:30 PM
*  Author: amir
*/


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_Inputs.h"
#include <avr/io.h>
#include <util/delay.h>


#define KeypadPort PORTC
#define KeypadPin PINC
#define KeypadDirection DDRC


namespace Keypad{
	
	inputs CapturePullupInput(){
		KeypadDirection=0xF0;//first four pin input second four pin output
		KeypadPort=0x0F;//inputs as pull up resistor
		
		uint8_t output=0x0F;//don t touch the pull ups!
		for (int col=1,temp=0x10;col<=4;col++,temp*=2)
		{
			
			output&=0x0F;
			output|=(0xF0-temp);
			KeypadPort=output;
			_delay_ms(50);
			switch(KeypadPin){
				case 0xEE:
				return inputs(inputs::one);
				break;
				case 0xDE:
				return inputs(inputs::two);
				break;
				case 0xBE:
				return inputs(inputs::three);
				break;
				case 0x7E:
				return inputs(inputs::plus);
				break;
				case 0xED:
				return inputs(inputs::four);
				break;
				case 0xDD:
				return inputs(inputs::five);
				break;
				case 0xBD:
				return inputs(inputs::six);
				break;
				case 0x7D:
				return inputs(inputs::minus);
				break;
				case 0xEB:
				return inputs(inputs::seven);
				break;
				case 0xDB:
				return inputs(inputs::eight);
				break;
				case 0xBB:
				return inputs(inputs::nine);
				break;
				case 0x7B:
				return inputs(inputs::multiply);
				break;
				case 0xE7:
				return inputs(inputs::Dot);
				break;
				case 0xD7:
				return inputs(inputs::zero);
				break;
				case 0xB7:
				return inputs(inputs::Evaluate);
				break;
				case 0x77:
				return inputs(inputs::devision);
				break;
			}
		}
		return inputs::End;
	}
	inputs CaptureInput(){
		
		KeypadDirection=0xF0;//first four pin input second four pin output
		KeypadPort=0x00;//inputs as pull up resistor Disabled
		uint8_t output;
		
		for (int col=1,temp=0x10;col<=4;col++,temp*=2)
		{
			output&=0x0F;
			output|=temp;
			KeypadPort=output;
			_delay_ms(50);
			switch(KeypadPin){
				case 0x11:
				return inputs(inputs::one);
				break;
				case 0x12:
				return inputs(inputs::two);
				break;
				case 0x14:
				return inputs(inputs::three);
				break;
				case 0x18:
				return inputs(inputs::plus);
				break;
				case 0x21:
				return inputs(inputs::four);
				break;
				case 0x22:
				return inputs(inputs::five);
				break;
				case 0x24:
				return inputs(inputs::six);
				break;
				case 0x28:
				return inputs(inputs::minus);
				break;
				case 0x41:
				return inputs(inputs::seven);
				break;
				case 0x42:
				return inputs(inputs::eight);
				break;
				case 0x44:
				return inputs(inputs::nine);
				break;
				case 0x48:
				return inputs(inputs::multiply);
				break;
				case 0x81:
				return inputs(inputs::Dot);
				break;
				case 0x82:
				return inputs(inputs::zero);
				break;
				case 0x84:
				return inputs(inputs::Evaluate);
				break;
				case 0x88:
				return inputs(inputs::devision);
				break;
				
			}
			
		}
		return inputs::End;
	}
}



#endif /* KEYPAD_H_ */