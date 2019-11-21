// Zahid Ali 2018-CS-136

//1- this program will convert infix expression into valid postfix expression
//2- this program will solve valid postfix expression and print result in numaric

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

//converting infix expression to postfix expression

//stack for first task

#define size 50
class node
	 {
	 public:
		int data;
		node*next;
};
class stack{
	public:
		node*head;
		node*tail;
	public:
		stack(){	
			head=NULL;
			tail=NULL;
		}
    	void push(char n);
    	char pop ();
    	char top ();	
};
void stack::push(char n){
   	node* temp;
	temp = head;

	node* temp2 = new node();
	temp2->data = n;
	tail=temp2;
	tail->next =NULL ;

	if (head == NULL)
	{
		head = temp2;
		tail = temp2;
		tail->next=NULL;
	}
	
	else {
		while(temp->next!=NULL)
		{
			temp=temp->next;
			
    	}
      temp->next=temp2;
	}
}
char stack::pop(){
	node *current = head;
	node *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			head = head -> next;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
			previous -> next = current -> next;
	    	return n ;
		}
		
	}
}
char stack::top(){
	node *current = head;
	node *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
	    	return n ;
		}
		
	}
}

// checking presidence of operators

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
	char operand[size];
	cout << "Enter infix Expression: " << endl;
	cin >> infix;
	int length = strlen(infix);
	for(int i = 0; i < length; i++){
        if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
        	operand[j] = infix[i];
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
						operand[j++] = temp;
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
							operand[j++] = temp;
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
		operand[j++] = P.pop();
		n++;
	}
	string postfixString = "";
	cout << "postfix expression is: ";
	if(infix[0] == '('){
		for(int i=0; i < length - (b +1); i++){
			cout << operand[i];
			postfixString = postfixString + operand[i];   //converting array into string
		}
	//	cout << endl << "string is: " << postfixString << endl << "string length is: " << postfixString.length() << endl;
		return postfixString;			//returning postfix string

	}else{
		for(int i=0; i < length - b; i++){
			cout << operand[i];
			postfixString = postfixString + operand[i];   //converting array into string
		}
	//	cout << endl << "string is: " << postfixString << endl << "string length is: " << postfixString.length() << endl;
		return postfixString;			//returning postfix string

	}

}

//sloving postfix expression
//stack for 2nd task

class node2
	 {
	 public:
		int data;
		node2*next;
};
class stack2{
	public:
		node2*head;
		node2*tail;
	public:
		stack2(){	
			head=NULL;
			tail=NULL;
		}
    	void push2(int n);
    	int pop2 ();
    	int top2 ();	
};
void stack2::push2(int n){
   	node2* temp;
	temp = head;

	node2* temp2 = new node2();
	temp2->data = n;
	tail=temp2;
	tail->next =NULL ;

	if (head == NULL)
	{
		head = temp2;
		tail = temp2;
		tail->next=NULL;
	}
	
	else {
		while(temp->next!=NULL)
		{
			temp=temp->next;
			
    	}
      temp->next=temp2;
	}
}
int stack2::pop2(){
	node2 *current = head;
	node2 *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			head = head -> next;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
			previous -> next = current -> next;
	    	return n ;
		}
		
	}
}
int stack2::top2(){
	node2 *current = head;
	node2 *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
	    	return n ;
		}
		
	}
}

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

int main(){
	postEvaluator(postfix());
	return 0;
}
