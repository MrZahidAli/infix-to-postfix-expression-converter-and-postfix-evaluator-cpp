//1- this program will convert infix expression into valid postfix expression
//2- this program will solve valid postfix expression and print result in numaric

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

//converting infix expression to postfix expression

//stack for first task

#define size 50
class node{
	public:
		int data;
		node* next;
};
class stack{
	public:
		node *head, *tail;
	public:
		stack(){
			head = NULL;
			tail = NULL;
		}
		void push(char value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		char pop() {
			
    		node *current;
			current = head;
			
			node* previous;
			previous= head;
			
			if(head == NULL){
				return -1;
			}
			else if(head == tail){
					char headData = head -> data;
					head = head -> next;
					return headData;
			}
			else{
    			while(current->next != NULL) {
    				previous = current;
    				current = current->next;	
				}
				tail = previous;
				previous->next = current -> next;
				char outChar = current -> data;
				delete current;
				return outChar;
			}
		}
		char top() {
			
    		node *current;
			current = head;
			
			node* previous;
			previous= head;
			
			if(head == NULL){
				return -1;
			}
			else if(head == tail){
					char headData = head -> data;
					return headData;
			}
			else{
    			while(current->next != NULL) {
    				previous = current;
    				current = current->next;	
				}
				char outChar = current -> data;
				return outChar;
			}
		}

};

// checking presidence of operators
class postfi{
	public:
		int preseidence(char opera){
			if(opera == '(' || opera == ')'){
				return 0;
			}
			if(opera == '+' || opera == '-'){
				return 1;
			}
			if(opera == '*' || opera == '/'){
				return 2;
			}
			if(opera == '^'){
				return 3;
			}
			return 0;
		}
		
		//converting infix expression into postfix expression
		
		string postfix(){
			int c = 0;
			int b = 0;
			stack P;
			char temp;
			int j = 0;
			char infix[size];
			char expression[size];
			cout << "Enter infix Expression: " << endl;
			cin >> infix;
			int length = strlen(infix);
			for(int i = 0; i < length; i++){
		        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
		        	expression[j] = infix[i];
		        	j++;
				}
				else{
					if(P.head == NULL){
						P.push(infix[i]);
						c++;
					}
					else{
						if(infix[i] != '(' && infix[i] != ')'){
							if(preseidence(infix[i]) <= preseidence(P.top())){
								temp = P.pop();
								c--;
								expression[j++] = temp;
								P.push(infix[i]);
								c++;
							}
							else{
								P.push(infix[i]);
								c++;
							}
						}
						else{
							if(infix[i] == '('){
								P.push(infix[i]);
								c++;
								b++;
							}
							if(infix[i] == ')'){
								temp = P.pop();
								c--;
								b++;
								while(temp != '('){
									expression[j++] = temp;
									temp = P.pop();
									c--;
								}
							}
						}
					}
				}
			}
			int n = 0;
			while(n<c){
				expression[j++] = P.pop();
				n++;
			}
			string postfixString = "";
			cout << "postfix expression is: ";
			if(infix[0] == '('){
				for(int i=0; i < length - (b +1); i++){
					cout << expression[i];
					postfixString = postfixString + expression[i];   //converting array into string
				}
			//	cout << endl << "string is: " << postfixString << endl << "string length is: " << postfixString.length() << endl;
				return postfixString;			//returning postfix string
		
			}else{
				for(int i=0; i < length - b; i++){
					cout << expression[i];
					postfixString = postfixString + expression[i];   //converting array into string
				}
			//	cout << endl << "string is: " << postfixString << endl << "string length is: " << postfixString.length() << endl;
				return postfixString;			//returning postfix string
		
			}
		
		}
};

//sloving postfix expression
//stack for 2nd task

class node2{
	public:
		int data;
		node2* next;
};
class stack2{
	public:
		node2 *head, *tail;
	public:
		stack2(){
			head = NULL;
			tail = NULL;
		}
		void push2(int value){
			node2 *temp = new node2;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		int pop2() {
			
    		node2 *current;
			current = head;
			
			node2* previous;
			previous= head;
			
			if(head == NULL){
				return -1;
			}
			else if(head == tail){
					int headData = head -> data;
					head = head -> next;
					return headData;
			}
			else{
    			while(current->next != NULL) {
    				previous = current;
    				current = current->next;	
				}
				tail = previous;
				previous->next = current -> next;
				int outChar = current -> data;
				delete current;
				return outChar;
			}
		}

};

class postFixEvaluation{
	public:
		//type casting(converting characters into integers
		int typeCast(char charValue){
			return charValue - '0';
		}
		//solving postfix expression
		int postEvaluator(string postfix){
			stack2 Z;
			char operation;
			int intOpe1;
			int intOpe2;
			int intPush;
			int length = postfix.length();
			for(int i = 0; i < length; i++){
				if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='/' && postfix[i]!='*' && postfix[i]!='^' && postfix[i]!='(' && postfix[i]!=')'){
					intPush = typeCast(postfix[i]);
					Z.push2(intPush);
				}
				else{
					intOpe1 = Z.pop2();
					intOpe2 = Z.pop2();
					operation = postfix[i];
					
					if(operation == '+') Z.push2(intOpe1 + intOpe2);
					else if(operation == '-') Z.push2(intOpe2 - intOpe1);
					else if(operation == '*') Z.push2(intOpe2 * intOpe1);
					else if(operation == '/') Z.push2(intOpe2 / intOpe1);
					else if(operation == '^') Z.push2(pow(intOpe2, intOpe1));
				}
			}
			cout << endl << "postfix expression result: " << Z.pop2();   //printing postfix expression result into numaric data
		}
};

int main(){
	postfi P;
	postFixEvaluation E;
	E.postEvaluator(P.postfix());  //postfix() returning the postfix expression in string
	return 0;
}
