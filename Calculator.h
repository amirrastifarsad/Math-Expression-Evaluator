/*
* Calculator.h
*
* Created: 2/21/2019 10:17:35 PM
*  Author: Amir
*/


#include "StateMachine.h"
#ifndef CALCULATOR_H_
#define CALCULATOR_H_


class Calculator{
	public:
	static const int MaxSequence=35;
	inputs input[MaxSequence];
	int index;
	StateMachine* state_machine;
	Calculator(){
		//input={inputs::End};
		state_machine = new StateMachine();
	}
	bool push(inputs inp){
		if (index<MaxSequence)
		{
			//std::cout << "push" << std::endl;
			input[index++]=inp;
			return true;
		}
		else{
			return false;
		}
	}
	float Evaluate(){
		input[index++] = inputs::End;
		
		int procced=0;
		bool isFillingInteger=false;
		OprandNode* node=nullptr;
		while(input[procced]!=inputs::End && procced<index){
			if(input[procced]<=inputs::Dot){
				if (!isFillingInteger)
				{
					//std::cout << "new node" << std::endl;
					node=new OprandNode(input[procced]);
					isFillingInteger=true;
				}
				else{
					//std::cout << "appending node" << std::endl;
					node->append(input[procced]);
				}
			}
			else if (input[procced]==inputs::Evaluate)
			{
				isFillingInteger = false;
				state_machine->AppendNode(node);
				return state_machine->Evaluate();
			}
			else{
				//std::cout << "insert node" << std::endl;
				isFillingInteger=false;
				state_machine->AppendNode(node);
				state_machine->AppendNode(new OperatorNode(input[procced]));
			}
			procced++;
		}
		return state_machine->Evaluate();
	}
	void Reset(){
		delete state_machine;
		state_machine=new StateMachine();
		index=0;
		for (int i=0;i<MaxSequence;i++)
		{
			input[i]=inputs::End;
		}
		
	}
};



#endif /* CALCULATOR_H_ */