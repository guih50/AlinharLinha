#include <stdio.h>
#include <string.h>
//nesse programa, é entrado uma string, um tamanho e o tipo de alinhamento, e a função alinha a string adicionando a quantidade 
//de espaços especificador pelo tamanho, e o alinha em justificado, centralizado ou sla o outro
char* alignStr(char palavra[60],int tamanho,int alinhamento){
	char aux[60];
	int cont/*cont2*/,i,j,k;
	cont = strlen(palavra);
	if(alinhamento==-1){
		for(i=0;i!=tamanho;i++){
			aux[i]=' ';
		}
		for(j=0;j!=cont;j++,i++){
			aux[i]=palavra[j];
		}
	}
	else if(alinhamento==0){
		for(i=0;i!=tamanho/2;i++){
			aux[i]=' ';
		}
		for(j=0;j!=cont;j++,i++){
			aux[i]=palavra[j];
		}
		for(k=i,cont=0;cont!=tamanho/2;k++,cont++){
			aux[k]=' ';
		}
	}
	else{
		for(i=0,j=0;i!=cont;i++,j++){
			aux[i]=palavra[j];
		}
		for(i=i,k=0;k!=tamanho;i++,k++){
			aux[i]=' ';
		}
	}
	palavra=aux;
	return palavra;
}

int main()
{
	char palavra[60],alinhado[60];
	int tamanho=-1,alinhamento=2;
	
	printf("Digite a palavra: ");
	scanf("%s",palavra);
	while(tamanho<0){
		printf("Digite o tamanho: ");
		scanf("%d",&tamanho);
		if(tamanho<0){
			printf("Valor negativo invalido, digite um valor positivo inteiro: ");
		}
	}
	while((alinhamento!=1) && (alinhamento!=0) && (alinhamento!=-1)){
		printf("digite -1 para alinhar a esquerda, 0 para centralizar e 1 para alinhar a direita: ");
		scanf("%d",&alinhamento);
		if((alinhamento!=1) && (alinhamento!=0) && (alinhamento!=-1)){
			printf("Valor invalido, digite -1, 0 ou 1: ");
		}
	}
	
	strcpy(alinhado, alignStr(palavra,tamanho,alinhamento));
	
	printf("-%s-",alinhado);
}

