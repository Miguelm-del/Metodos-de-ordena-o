#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
	char nome[100];
	int cpf;
	int idade;
	float salario;
}Funcionario;
/*
void quickSort(Funcionario *vetFuncionario, int tam){
	int a=1, b= tam-1, pivo;
	pivo = vetFuncionario[0].nome;

	do{
		while((strcmp(vetFuncionario[a],pivo) < 0) && ( a < 1)){
			a++;
		}
		while((strcmp()))
	}
}
void quickSortMain(Funcionario *)


void quick(int v[], int tam){
  int a=1, b=tam-1, pivo;
  pivo = v[0];

  if (tam <=1)
    return;
  while(a<=b){
    printf("\n A: %d, B: %d", a, b);
    while (v[a]<pivo && a<tam){
      a++;
    }
    while (v[b]>pivo && b>0){
      b--;
    }
    if (a<b){
      int aux = v[b];
      v[b] = v[a];
      v[a] = aux;
      a++;
      b--;
    }
  }
  v[0] = v[b];
  v[b] = pivo;
  quick(v, b);
  quick(&v[a], tam-a);
}

*/

//METODO BOLHA PRINCIPIOS
void ordenarVet(Funcionario *vetFuncionario, int num_componentes){
	int contador;
    for (int i = 0; i < num_componentes; i++) {
                    for (int j = 0; j < (num_componentes - 1); j++) {
                        if (strcmp(vetFuncionario[j].nome, vetFuncionario[j + 1].nome) > 0) {
                            Funcionario aux;
														

                            aux = vetFuncionario[j];
                            vetFuncionario[j] = vetFuncionario[j + 1];
                            vetFuncionario[j + 1] = aux;
														contador++;
                        }
                    }
                }

                printf("\nFuncionarios ordenados crescentemente por nome:\n");

                for (int i = 0; i < num_componentes; i++) {
                    printf("\nPosicao [%d]", i);
                    printf("\nNOME: %s \n", vetFuncionario[i].nome);
										printf("\nCPF: %d \n", vetFuncionario[i].cpf);
										printf("\nIDADE: %d \n", vetFuncionario[i].idade);
										printf("\nSALARIO: %f \n", vetFuncionario[i].salario);


}
	printf("FORAM FEITAS [%d] trocas",contador);
}
//

void quickS(Funcionario *vetFuncionario, int left, int right, int num_componentes)
{
  int i, j;
  char *x;
  char temp[100];
	int contador = 0;
  i = left;
  j = right;
  x = vetFuncionario[(left+right)/2].nome;

  do {
    while((strcmp(vetFuncionario[i].nome,x) < 0) && (i < right)) {
       i++;
			 contador++;
    }
    while((strcmp(vetFuncionario[j].nome,x) > 0) && (j > left)) {
        j--;
				contador++;
    }
    if(i <= j) {
      strcpy(temp, vetFuncionario[i].nome);
      strcpy(vetFuncionario[i].nome, vetFuncionario[j].nome);
      strcpy(vetFuncionario[j].nome, temp);
      i++;
      j--;
			contador++;
   }
  } while(i <= j);

  if(left < j) {
     quickS(vetFuncionario, left, j, num_componentes);
		 contador++;
  }
  if(i < right) {
     quickS(vetFuncionario, i, right, num_componentes);
		 contador++;
  }
	               printf("\nFuncionarios ordenados crescentemente por nome:\n");

                for (int i = 0; i < num_componentes; i++) {
                   // printf("%d", i);
                    printf("\nNOME: %s \n", vetFuncionario[i].nome);
										printf("\nCPF: %d \n", vetFuncionario[i].cpf);
										printf("\nIDADE: %d \n", vetFuncionario[i].idade);
										printf("\nSALARIO: %f \n", vetFuncionario[i].salario);
										


}
printf("\nFORAM FEITAS [%d] trocas",contador);
}





void ordenar(Funcionario *vetFuncionario, int tam){
	int x,y,r;
	char aux[100];
	for (x = 0; x <=tam;x++){
		for(y = x+1; y <= tam; y++){
				r = strcmp(vetFuncionario[x].nome, vetFuncionario[y].nome);
				if(r > 0){
					strcpy(aux, vetFuncionario[x].nome);
					strcpy(vetFuncionario[x].nome, vetFuncionario[y].nome);
					strcpy(vetFuncionario[y].nome, aux);
				}
		}

	}
}



/*void trocar(Funcionario *pv, int x, int y){

Funcionario aux = pv[x];
pv[x] = pv[y];
pv[y] = aux;
}

void buble(Funcionario *vetFuncionario, int tam){
	int i, j;
	
	for (i = tam-1; i > 0; i--){
		for( j=0; j < i; j++){

			if(vetFuncionario[j].nome > vetFuncionario[j+1].nome)

				trocar(vetFuncionario, j, j+1);
		}
	}
}
*/

void mostrarVet(Funcionario *p, int tam){
	int i;

		for ( i=0; i < tam; i++ ){
			printf("\nNome [%s]", p->nome);
			i++;
		}
}




void realocar(Funcionario *vetFuncionario, int *num_componentes, int novo_tamanho){
	if(*num_componentes < novo_tamanho){
		vetFuncionario = (Funcionario*) realloc(vetFuncionario,sizeof(Funcionario) * novo_tamanho);
	}else if(*num_componentes > novo_tamanho){
		int dif = novo_tamanho - *num_componentes;
		vetFuncionario = (Funcionario*) realloc(vetFuncionario, sizeof(Funcionario) * (*num_componentes + dif));
		*num_componentes += dif;
	}

}

void lerFuncionarios(Funcionario *vetFuncionario, int tam){
	for (int i = 0; i < tam; i++){
			printf("\nCADASTRO FUNCIONARIO");
			printf("\n\nDigite o nome do Funcionario: ");
			scanf("%s", vetFuncionario[i].nome);
			printf("\nDigite o CPF do Funcionario: ");
			scanf("%d", &vetFuncionario[i].cpf);
			printf("\nDigite a idade do Funcionario: ");
			scanf("%d", &vetFuncionario[i].idade);
			printf("\nDigite o salario do Funcionario: ");
			scanf("%f", &vetFuncionario[i].salario);
	}
}

void exibir(Funcionario *vetFuncionario, int tam){
		printf("\n\nFUNCIONARIOS: ");
	for (int i = 0; i< tam; i++){	
		printf("\n----------------------\n");
		printf("\nFuncionario[%i] - Nome[%s]", i+1, vetFuncionario[i].nome);
		printf("\nFuncionario[%i] - CPF[%d]", i+1, vetFuncionario[i].cpf);
		printf("\nFuncionario[%i] - Idade[%d]",i+1, vetFuncionario[i].idade);
		printf("\nFuncionario[%i] - Salario[%2.f]", i+1, vetFuncionario[i].salario);
		printf("\n----------------------");
	}
}

//PESQUISA SEQUENCIAL PRINCIPIOS
int PesquisaSequencial(Funcionario *vetFuncionario, int pesq, int tamanho)
{
     int i, cont =0;
     for(i=0;i<tamanho;i++)
     {
			 		cont++;
          if(vetFuncionario[i].cpf==pesq)
          {
							printf("\n %d comparações",cont);
              return i;
          }
     }
		 printf("\n %d comparações",cont);
     return -1;   // Não encontrado
}
//PESQUISA  BUSCABIN PRINCIPIOS
int buscaBin(Funcionario *vetFuncionario, int elemento, int tam){
	int fim = tam -1;
	int ini = 0;
	int contad =0;
	while(ini <= fim){
		int meio = (fim + ini)/2;
		if(vetFuncionario[meio].cpf < elemento){
			ini = meio + 1;
			contad++;
		}else{
			if(vetFuncionario[meio].cpf > elemento){
				fim = meio -1;
				contad++;
			}
			else{
				printf("\n %d comparações",contad);
				printf("\n Esta cadastrado");
				return meio;
			}
			
		}

	}
	printf("\n %d comparações",contad);
	printf("\nN esta cadastrado");
	return -1;
}



int main(void){
	int opcao,opt;
	int num_componentes, novo_tamanho;
	int pesq,x,h, atualizar;

  do{
		printf("\n------------------------------");
		printf("\n\nManutencao de Funcionarios\n");
		printf("\n[1] – Contratar funcionário");
		printf("\n[2] – Exibir funcionários por nome");
		printf("\n[3] - Consultar funcionário [CPF]");
		printf("\n[4] – Atualizar dados de um funcionário");
		printf("\n[5] – Sair");
		//printf("\n[6] – Realocar funcionario");

		printf("\n\nOpcao: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
			printf("\nQuantos funcionarios deseja cadastrar?\n: ");
			scanf("%d", &num_componentes);
			Funcionario *vetFuncionario = (Funcionario *) malloc(sizeof(Funcionario) * num_componentes);
			lerFuncionarios(vetFuncionario, num_componentes);
			exibir(vetFuncionario, num_componentes);

			/*printf("\nCADASTRO FUNCIONARIO");
			printf("\n\nDigite o nome do Funcionario: ");
			printf("\nDigite o CPF do Funcionario: ");
			printf("\nDigite a idade do Funcionario: ");
			printf("\nDigite o salario do Funcionario: ");*/
			
			break;
			case 6:
			printf("\nDigite o novo tamanho para a quantidade de funcionario: ");
			scanf("%d", &novo_tamanho);
			realocar(vetFuncionario, &num_componentes, novo_tamanho);
			break;
			case 2:
			printf("Qual metodo e ordenacao deseja utilizar:\n [1] - Bubble Sort\n [2] - Quicksort\n---: ");
			scanf("%d", &opt);
			if(opt == 1){
				printf("\nOrdenacao BUBBLESORT");
				ordenarVet(vetFuncionario,num_componentes);
				break;
			}else if(opt == 2){
				printf("\nOrdenacao QUICKSORT");
				quickS(vetFuncionario,0, num_componentes -1,num_componentes );
				
				break;
			}
			break;
			case 3:
			printf("Qual CPF deseja consultar: ");
			scanf("%d", &pesq);
			printf("Qual metodo de pesquisa deseja utilizar:\n [1] - Sequencial \n [2] - Binaria\n---: ");
			scanf("%d", &opt);
			if(opt == 1){
				printf("\nPesquisa Sequencial");
				x = PesquisaSequencial(vetFuncionario, pesq,num_componentes);
				if(x < 0){
					printf("\nNao esta cadastrado");
				}else{
					printf("\n ESTA CADASTRADO NA POSICAO [%d] ",x);
				}
				
				break;
			}else if(opt == 2){
				printf("\nPesquisa Binaria");
				h = buscaBin(vetFuncionario, pesq,num_componentes);
					/*if(h == -1){
					printf("\nNao esta cadastrado");
				}else{
					printf("\n ESTA CADASTRADO NA POSICAO [%d] ",h);
				}*/
			
				break;
			}
			break;
			case 4:
			printf("\nAtualização de dados dos Funcionarios");
			printf("\nDigite o CPF do funcionario que deseja atualizar os dados: ");
			scanf("%d", &atualizar);
			x  = PesquisaSequencial(vetFuncionario, atualizar, num_componentes);
				if(x < 0){
					printf("\nNao esta cadastrado");
				}else{
					printf("\n\nATUALIZANDO DADOS: ");
			printf("\n\nDigite o nome do Funcionario: ");
			scanf("%s", vetFuncionario[x].nome);
			printf("\nDigite o CPF do Funcionario: ");
			scanf("%d", &vetFuncionario[x].cpf);
			printf("\nDigite a idade do Funcionario: ");
			scanf("%d", &vetFuncionario[x].idade);
			printf("\nDigite o salario do Funcionario: ");
			scanf("%f", &vetFuncionario[x].salario);

			exibir(vetFuncionario, num_componentes);


				}			

			break;
			case 5:
			printf("\nFinalizando sistema");
			break;
			default:
			printf("\nValor invalido");
			
		}
		
/*Fazer uma aplicação para a manutenção de funcionários de uma empresa. Para cada funcionário são
lidos: nome, CPF, idade, salário. O número de funcionários é indeterminado. Pede-se que a
aplicação apresente o seguinte menu para ser usado pelo gerente de recursos humanos da empresa:

1 – Contratar funcionário (deverá ler os dados de um número x de funcionários)
2 – Exibir funcionários por nome (deverá exibir por ordem crescente de nome)
3 - Consultar funcionário (dado o CPF, exibir se o funcionário está cadastrado ou não)
4 – Atualizar dados de um funcionário (solicitar o CPF do funcionário)
5 – Sair

	Na implementação do item 2 deverá ser perguntando ao usuário qual método de ordenação
utilizar (bubble sort ou quicksort) e deverá ser exibido quantas trocas foram efetuadas no
final da ordenação;

• Na implementação do item 3 deverá ser perguntando ao usuário qual o método de pesquisa:
sequencial ou binário, e no final além de exibir se o funcionário está cadastrado ou não,
deverá exibir quantas comparações foram executadas até encontrar ou não o funcionário
desejado.
*/
	}while(opcao!=5);
	

  return 0;
}
