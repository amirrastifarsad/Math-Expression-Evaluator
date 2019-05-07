/*
* StateMachine.h
*
* Created: 2/10/2019 4:33:05 PM
*  Author: amir
*/

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include "AVR_Lib/Keypad_Inputs.h"
enum class NodeTypes{OPERAND,OPERATOR};
	
class ExpressionNode{
	protected:
	NodeTypes Type;
	ExpressionNode* Next=nullptr;
	public:
	inputs value;
	ExpressionNode(){
		
	}
	friend class StateMachine;
};
class OprandNode:public ExpressionNode{
	
	public:
	float value;
	bool hasDot = false;
	int floating = 0;
	OprandNode(inputs inp){
		Type=NodeTypes::OPERAND;
		value=int(inp);
	}
	void append(inputs inp){
		if (!hasDot) {
			if (inp!=inputs::Dot)
			{
				value *= 10;
				value += int(inp);
			}
			else
			{
				hasDot = true;
				floating = 1;
			}
		}
		else {
			float input = int(inp);
			for (int i = 0; i < floating; i++)
			{
				input /= 10;
			}
			floating++;
			
			value += input;
		}
	}
	int operator + (OprandNode* node){
		return node->value+this->value;
	}
	void operator = (int value){
		this->value=value;
	}
};
class OperatorNode:public ExpressionNode
{
	public:
	OperatorNode(inputs inp){
		Type=NodeTypes::OPERATOR;
		value=inp;
	}
	
};
class StateMachine{
	public:
	ExpressionNode* First;//first element in the chain
	ExpressionNode* Last=nullptr;
	StateMachine(){
		First=new ExpressionNode();
		Last=First;
	}
	void AppendNode(ExpressionNode* node){
		//std::cout << "append" << std::endl;
		Last->Next=node;
		Last=Last->Next;
	}
	float Evaluate(){
		//Resault->value=0;
		ExpressionNode* Procced=First;
		
		OprandNode *op1(nullptr),*op2(nullptr);
		while (First->Next->Next != nullptr)
		{

		Procced = First;
		while (Procced->Next!=nullptr)
		{
			//std::cout << (int)(Procced->value) << "---------------------";
			
			Procced=Procced->Next;
			if (Procced->Type==NodeTypes::OPERAND)
			{
				op1=static_cast<OprandNode*>(Procced);
			}
			else if (Procced->Type==NodeTypes::OPERATOR)
			{
				if (Procced->value >= GetNextOperator(Procced)->value)
				{
					op2=static_cast<OprandNode*>(Procced->Next);
					switch (Procced->value)
					{
					case inputs::plus:
						op1->value = op2->value + op1->value;
						break;
					case inputs::minus:
						op1->value = op1->value - op2->value;
						break;
					case inputs::multiply:
						op1->value = op1->value * op2->value;
						break;
					case inputs::devision:
						op1->value = op1->value / op2->value;
						break;
					default:
						break;
					}
					
					op1->Next=op2->Next;
					delete op2;
					delete Procced;
					Procced=static_cast<ExpressionNode*>(First);
					
				}
				else{
					//std::cout << int(Procced->value) <<"=="<< int(GetNextOperator(Procced)->value) << std::endl;
					op1 = static_cast<OprandNode*>(Procced->Next);
					Procced = op1;

				}
			}

		}
		}
		return static_cast<OprandNode*>(First->Next)->value;
	}
	OperatorNode* GetNextOperator(ExpressionNode* Procced){
		ExpressionNode* procc;
		procc=Procced;
		while (procc->Next != nullptr)
		{
			procc = procc->Next;
			if (procc->Type==NodeTypes::OPERATOR)
			{
				return static_cast<OperatorNode*>(procc);
			}
			

		}
		static OperatorNode* low;
		if (low==nullptr)
		{
			low=new OperatorNode(inputs::zero);
		}
		
		return low;
	}
	
	
};



#endif /* STATEMACHINE_H_ */