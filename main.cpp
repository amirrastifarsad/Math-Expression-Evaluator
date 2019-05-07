/*
* GccApplication1.cpp
*
* Created: 2/25/2018 11:48:08 PM
* Author : amir
*/

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "AVR_Lib/CppExtensions.h"
#include "AVR_Lib/StringLink.h"
#include "AVR_Lib/Display.h"
#include "AVR_Lib/Keypad.h"
#include "Calculator.h"






int main(void)
{
	Calculator calc;
	
	Display::LCD_Init();
	Display::LCD_setCursor(0,0);
	Display::LCD_Disp("Calculator");
	Display::LCD_setCursor(0,1);//goto next line
	Display::LCD_Disp("Project");
	
	_delay_ms(5000);
	Display::ResetDisplay();
	//main Loop
	while (true)
	{
		
		inputs inp=Keypad::CapturePullupInput();
		
		//if some input captured prevent Debunce
		if (inp!=inputs::End)
		{
			_delay_ms(350);
		}
		
		switch(inp){
			
			case inputs::zero:
			calc.push(inp);
			Display::LCD_Disp("0");
			break;
			case inputs::one:
			calc.push(inp);
			Display::LCD_Disp("1");
			break;
			case inputs::two:
			calc.push(inp);
			Display::LCD_Disp("2");
			break;
			case inputs::three:
			calc.push(inp);
			Display::LCD_Disp("3");
			break;
			case inputs::four:
			calc.push(inp);
			Display::LCD_Disp("4");
			break;
			case inputs::five:
			calc.push(inp);
			Display::LCD_Disp("5");
			break;
			case inputs::six:
			calc.push(inp);
			Display::LCD_Disp("6");
			break;
			case inputs::seven:
			calc.push(inp);
			Display::LCD_Disp("7");
			break;
			case inputs::eight:
			calc.push(inp);
			Display::LCD_Disp("8");
			break;
			case inputs::nine:
			calc.push(inp);
			Display::LCD_Disp("9");
			break;
			case inputs::Dot:
			calc.push(inp);
			Display::LCD_Disp(".");
			break;
			case inputs::plus:
			calc.push(inp);
			Display::LCD_Disp("+");
			break;
			case inputs::minus:
			calc.push(inp);
			Display::LCD_Disp("-");
			break;
			case inputs::devision:
			calc.push(inp);
			Display::LCD_Disp("/");
			break;
			case inputs::multiply:
			calc.push(inp);
			Display::LCD_Disp("*");
			break;
			case inputs::Evaluate:
			calc.push(inp);
			
			Display::LCD_Disp("=");
			Display::LCD_Print_Float(calc.Evaluate());
			
			_delay_ms(6000);
			calc.Reset();
			Display::ResetDisplay();
			break;
			
			case inputs::End:
			//no input do noting
			break;
			
		}
		
		
	}
	
}

