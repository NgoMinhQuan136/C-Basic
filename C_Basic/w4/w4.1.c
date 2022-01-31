#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char value;
	struct node *next;
}node;

typedef struct stack{
	node *top;
}stack;

stack* Init(){
	stack *s;
	s = (stack*)calloc(1, sizeof(stack));
	return s;
}

void push( stack *s, char i){
	node *tmp;
	tmp = (node*)calloc(1,sizeof(node));
	tmp->value = i;
	tmp->next = s->top;
	s->top = tmp;
}

char pop( stack *s){
	float i;
	node *tmp;
	tmp = s->top;
	i = tmp->value;
	s->top = tmp->next;
	free( tmp);
	return i;
}

void destroy( stack *s){
	while( s->top != NULL){
		pop(s);
	}
	free(s);
}


typedef struct nodef{
	float value;
	struct node *next;
}nodef;

typedef struct stackf{
	node *top;
}stackf;

stackf* Initf(){
	stackf *s;
	s = (stackf*)calloc(1, sizeof(stackf));
	return s;
}

void pushf( stackf *s, float i){
	node *tmp;
	tmp = (node*)calloc(1,sizeof(node));
	tmp->value = i;
	tmp->next = s->top;
	s->top = tmp;
}

char popf( stackf *s){
	float i;
	node *tmp;
	tmp = s->top;
	i = tmp->value;
	s->top = tmp->next;
	free( tmp);
	return i;
}

void destroyf( stackf *s){
	while( s->top != NULL){
		popf(s);
	}
	free(s);
}


int getPriority( char value){
	if( value == '*' || value == '/'){
		return 2;
	}else{
		return 1;
	}
}

char *convert( char trungto[]){
	int i;
	int idx = 0;
	char op1, op2;
	char *hauto = (char*)malloc( strlen( trungto) + 1);
	stack *s = Init();
	for( i = 0; i < strlen( trungto); i++){
		if( trungto[i] >= '0' && trungto[i] <= '9'){
			hauto[idx] = trungto[i];
			idx++;
		}else{
			if( s->top != NULL){
				op1 = pop(s);
				op2 = trungto[i];
				if( getPriority(op1) >= getPriority(op2)){
					hauto[idx] = op1;
					idx++;
					push( s, op2);
				}else{
					push( s, op1);
					push( s, op2);
				}
			}else{
				push( s, trungto[i]);
			}
		}
	}

	while( s->top != NULL){
		hauto[idx] = pop( s);
		idx++;
	}
	hauto[idx] = '\0';
	free(s);
	return hauto;
}

float result( char hauto[], stackf *s){
	s = Initf();
	int i;
	float value1, value2;
	for( i = 0; i < strlen(hauto); i++){
		if( hauto[i] >= '0' && hauto[i] <= '9' ){
			value1 =  hauto[i] - '0';
			pushf( s, value1);
		}else if ( hauto[i] == '+'){
			value1 =  popf(s);
			value2 =  popf(s);
			value2 += value1;
			pushf( s,value2);
		}else if ( hauto[i] == '-'){
			value1 =  popf(s);
			value2 =  popf(s);
			value2 -= value1;
			pushf( s, value2);
		}else if ( hauto[i] == '*'){
			value1 =  popf(s);
			value2 =  popf(s);
			value2 *= value1;
			pushf( s, value2);
		}else if ( hauto[i] == '/'){
			value1 =  (float)popf(s);
			value2 =  (float)popf(s);
			value2 /= value1;
			pushf( s, value2);
		}
	}
	return popf(s);
}
int main(){
	char trungto[20];
	char *hauto;
	printf("Nhap vao bieu thuc:\n");
	fflush(stdin);
	gets(trungto);
	hauto = convert( trungto);
	printf("Output:\n");
	printf("%s\n", hauto);

	stackf *s;
	printf("%5.1f", result( hauto, s));
	destroyf( s);
	return 0;
}
