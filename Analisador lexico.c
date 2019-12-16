/*
-----------	ANALISADOR LEXICO -----------

----------- Aluno: Arthur Oliveira -----------
----------- Matricula.: 142030144   -----------
//  -> consegue ler o arquivo e analisar caractere a caractere
*/



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>



int main(){
	
	/*using namespace std;
    int main (void){
	char character;
	int i, erro = 0;
	
	// Abrindo arquivo modo leitura
	ifstream fin("ArquivoFonte1.mln");

	while(fin.get(character)){
		for(i=0;i<TA;i++){
			if(character != alfabeto[i]){
				erro = 1;
			}
		}
	}
	if(erro == 1){
		cout << "Erro ao compilar, algum caracter esta invalido!" << endl;		
	}else{
		while(fin.get(character)){
		cout << character;
		}
	}
	
	for(i=0;i<TA;i++){
		cout << log[i] << endl;
	}
	
	fin.close();
	return 0;
}*/
	
	
	
	setlocale(LC_ALL, "");
	
	//char symbol;
	char *rib; 
	char x; 
	char buf[15];
	char operant[14] = { '(', ')', '{', '}', '=', '>', '<', '+', '-', '*', '/', '%',':'};
	char alphabet[] = {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l', 'm',
		'n', 'o', 'p', 'q','r', 's', 't', 'u','v', 'w', 'y','x', 'z', '0',
		'1', '2', '3', '4','5', '6', '7', '8', '9', '=','<', '>', '(', ')',
		'{', '}','+', '-', '%', ',', ';', '"', ';', '[', ']', '/', ':'};
	
	
	
	
	FILE *file;
	int i, j=0, k=0, hr=0, line=1, size=0;            
	
	file = fopen("ArquivoFonte1.mln","r");              
	
	if(file == NULL){
		printf("Unable to open file.\n");
		exit(0);
	}
	
	while(fgetc(file) != EOF){
		size++;                           
	}
	
	rib = (char *)malloc((size+1) * sizeof(char));      
	
	fseek(file, 0, SEEK_SET);             
	
	
   
	while((x = fgetc(file)) != EOF){      
   		rib[k] = x;
		rib[++k] = '\0'; 
		if(x == '\n'){
		line++;
		}  
	}
	
	
	while((x = rib[hr]) != '\0'){
		for(i = 0; i < 12; ++i){
	   		if(x == operant[i]){
	   			printf("Operator: %c\n", x);
	   			}
			}	
		if(anum(x)){
	   		buf[j++] = x;
			}else if((x == ' ' || x == '\n' || '"' ) && (j != 0)){
	   			buf[j] = '\0';
	   			j = 0;
	   			
	   			if(aword(buf) == 1){
		   			printf("Keyword: %s\n", buf);
					}else if(try(buf) == 1){
		   			printf("Identifier: %s\n", buf);
		   			}else if(number(buf) == 1){
		   				printf("Number: %s\n", buf);
					   }	 				
		   	}
				
	hr++;	   		
	}
	
		
	printf("\nSize: %d.", size}
	printf("\nLines: %d\n", line);
	
	
	free(rib);
	fclose(file);
	
	return 0;
}

/*void a0();
void a1();
void a2();
void a3();
void a4();
void a5();
void a6();

void functiontest(char symbol){
	var[measure] = symbol;
	measure++;
}*/

int aword(char buf[]){
	char aword[12][10] = {"for","step","step","sqrt","if","else","return",
							"print","read","to","num","string"};
	int i; 
	flg = 0;
	
	for(i = 0; i < 12; ++i){
		if(strcmp(aword[i], buf) == 0){
			flg = 1;
			break;
		}
	}
	
	return flg;
}

int number(char buf[]) { 
	int i, len = strlen(buf); 

	if (len == 0) 
		return 0; 
	for (i = 0; i < len; i++) { 
		if (buf[i] != '0' && buf[i] != '1' && buf[i] != '2'
			&& buf[i] != '3' && buf[i] != '4' && buf[i] != '5'
			&& buf[i] != '6' && buf[i] != '7' && buf[i] != '8'
			&& buf[i] != '9' || (buf[i] == '-' && i > 0)) 
			return 0; 
	} 
	return 1; 
} 


int try(char buf[]) {
 	
 	int i=0, j=0, k=0;
    
    if (digit(buf[0]) && alpha(buf[1])){
    	
    	printf("%s Null word!\n", buf);	
				
	}else if(alpha(buf[0]) && alpha(buf[1])){
		
		return 1;	
	}
}
 
 
 


