//GHTT-Ativ06 - projeto Hotel LIC
//Gustavo; Henrique; Thomas; Thales - 16/06/2024
/*
Este programa é um sistema de gerenciamento de reservas de um hotel que atende aos seguintes requisistos:
REQ01; REQ02; REQ03; REQ04; REQ05; REQ06; REQ07; REQ08; REQ09; REQ10; REQ11; REQ12
*/

#include<iostream>

void fMapa(char Hotel[21][15]);  // Declaração da função que mostra o mapa do hotel
void fclear();  // Declaração da função que limpa o buffer de entrada do teclado
void fDadosHospede (char Status, char CPF[20], char Nome[20], char Endereco[100], char Telefone[20], char Email[100], int x, int y);	//Declaracao da funcao que mostra os dados do Hospede
char fVerifica (char cpf[20], char ID[20]);	// Declaração da funcao que verifica se o cpf da reserva e do check-in são os mesmos

main() 
{
	struct stapto
    {
		char Status; // ‘O’ = Ocupado ‘R’ = Reservado ‘.’ = livre
	    char CPF[14];
		char Nome[40];
	    char Telefone[15];
		char Endereco[40];
		char Email [100];
	};
	
	struct stapto hospede [21][15];
	char Hotel[21][15];  // Declaração da matriz que representa o mapa do hotel
	float TaxR = 0, TaxO = 0;
	int i, j; 
	int a, q; 
	int S;
	char ident[11];

	// Inicializa a matriz com o caractere '.'
	for(i=0; i<21; i++)
	   for(j=0; j<15; j++)
	      Hotel[i][j] = '.';

    do
    {
    	printf("\n=============================MENU=HOTEL===============================\n");
    	printf("\t\t\t\t\t\t\t\t     |");
	    printf("\nServicos disponiveis:                                                |\n");	
	    printf("                                                                     |\n");
	    printf("(1) - Disposicao de Apartamentos                                     |\n");
	    printf("(2) - Reserva                                                        |\n");
	    printf("(3) - Cancelamento                                                   |\n");
	    printf("(4) - Check-In de hospedede com reserva                              |\n");
	    printf("(5) - Check-In de hospede sem reserva                                |\n");
	    printf("(6) - Check-Out                                                      |\n");
	    printf("(7) - Visualizar Taxa de Reserva e Ocupacao                          |\n");
	    printf("(8) - Visualizar o status do quarto e os dados do hospede            |\n");
	    printf("(9) - SAIR                                                           |\n");
	    printf("                                                                     |\n");
	    printf("======================================================================");
	    printf("\n");
	    printf("\nSelecione o servico desejado: ");
	    scanf("%d", &S);  // Lê a opção escolhida pelo usuário
	    
	
	    switch(S)  // Estrutura de seleção para cada serviço
        {
            case 1:  // Mostrar disposição dos apartamentos
		    fMapa(Hotel);
			break;
	    	
	    	case 2:  // Realizar uma reserva
	    	printf("\nIniciando Reserva...\n");
	    	printf("\nDigite o andar desejado: ");
	        scanf("%d", &a);
	        printf("\nDigite o quarto desejado: ");
	        scanf("%d", &q);
    	    printf("\n");
	        if(Hotel[a][q] == '.')  // Verifica se o quarto está disponível
	        {
	            printf("\n\t\tCadastro do hospede\n");
			    fclear();
		        printf("\nNome: ");
		        gets(hospede[a][q].Nome);
		        printf("\nCPF: ");
		        gets(hospede[a][q].CPF);
		        printf("\nEndereco: ");
		        gets(hospede[a][q].Endereco);
		        printf("\nTelefone: ");
		        gets(hospede[a][q].Telefone);
		        printf("\nEmail: ");
		        gets(hospede[a][q].Email);
			    Hotel[a][q]='R';	// Marca o quarto como reservado
			    fMapa(Hotel);
	            printf("\nA reserva do quarto %d do andar %d foi concluida", q, a);
	            printf("\n");
			}
			else if(a<=0||a>20||q<=0||q>14)  // Verifica se o quarto é inexistente
	        {
	            fMapa(Hotel);
	    	    printf("\n\t\t       Quarto nao existente\n");	
	    	    printf("\n");
		    }
		    else if(Hotel[a][q]=='R')  // Verifica se o quarto já está reservado
		    {	
		        fMapa(Hotel);
			    printf("\n\t\t       Quarto ja reservado\n");	
			    printf("\n");
		    }
		    else if(Hotel[a][q]=='O')  // Verifica se o quarto já está ocupado
		    {
		        fMapa(Hotel);
		        printf("\n\t\t       Quarto ja ocupado\n");
		        printf("\n");
			}
	    	break;
	    	
	    	case 3:  // Cancelar uma reserva
	    	printf("\nIniciando cancelamento de reserva...\n");
	    	printf("\nDigite o andar que havera o cancelamento: ");
	    	scanf("%d", &a);
	    	printf("\nDigite o quarto para o cancelamento: ");
	    	scanf("%d", &q);
	    	if(Hotel[a][q] == 'R')  // Verifica se há uma reserva no quarto
	    	{
	    	    Hotel[a][q] = '.';  // Cancela a reserva
	    	    fMapa(Hotel);
	        	printf("\nO cancelamento do quarto %d do andar %d foi concluido\n", q, a);
	        	printf("\n");
		    }
			else if(Hotel[a][q] == '.')  // Verifica se o quarto não está reservado
		    {
		    	fMapa(Hotel);
		    	printf("\n\t\t       Nao existe reserva para esse quarto\n");
		    	printf("\n");
		    }
	    	else if(a<=0||a>20||q<=0||q>14)  // Verifica se o quarto é inexistente
	        {
	        	fMapa(Hotel);
	        	printf("\n\t\t       Quarto nao existente\n");
	        	printf("\n");
		    }
			break;
	    	
	    	case 4:  // Check-In de hóspede com reserva
	    	printf("\nIniciando Check-In de hospede com reserva...\n ");
	    	printf("\nDigite o andar com reserva para Check-In: ");
	    	scanf("%d", &a);
	    	printf("\nDigite o quarto reservado para Check-In: ");
	    	scanf("%d", &q);
	    	if(Hotel[a][q] == 'R')  // Verifica se há uma reserva no quarto
	        {
	        	printf("\nConfirmacao da identidade (por CPF) do hospede com reserva feita...\n");
	        	printf("\nDigite o CPF: ");
	        	fclear();
	        	gets(ident);
	        	if(fVerifica(hospede[a][q].CPF, ident)==1)
	        		{
	        		Hotel[a][q] = 'O';  // Marca o quarto como ocupado
	        		fMapa(Hotel);
	        		printf("\nO Check-In no quarto %d do andar %d foi concluido\n", q, a);
	        		printf("\n");
					}
	        	else
	        		{
	        		fMapa(Hotel);
	        		printf("\n\t\t   CPF do hospede nao bate com o da reserva\n");
					}
		    }
			else if (Hotel[a][q] == '.')  // Verifica se o quarto não está reservado
		    {
		    	fMapa(Hotel);
				printf("\n\t\t       Nao existem reservas para esse quarto\n");
				printf("\n");
			}
			else if (Hotel[a][q] == 'O')  // Verifica se o quarto já está ocupado
			{
				fMapa(Hotel);
				printf("\n\t\t       Quarto ja ocupado\n");
				printf("\n");
			}
			else if(a<=0||a>20||q<=0||q>14)  // Verifica se o quarto é inexistente
			{
				fMapa(Hotel);
				printf("\n\t\t       Quarto nao existente\n");
				printf("\n");
			}
			break;
	    	
	    	case 5:  // Check-In de hóspede sem reserva
	    	printf("\nIniciando Check-In de hospede sem reserva...\n");
	    	printf("\nDigite o andar para Check-In: ");
	    	scanf("%d", &a);
	    	printf("\nDigite o quarto sem reserva para Check-In: ");
	    	scanf("%d", &q);
	    	if(Hotel[a][q] == '.')  // Verifica se o quarto está disponível
	    	{
	    	    printf("\n\t\tCadastro do hospede\n");
			    fclear();
		        printf("\nNome: ");
		        gets(hospede[a][q].Nome);
		        printf("\nCPF: ");
		        gets(hospede[a][q].CPF);
		        printf("\nEndereco: ");
		        gets(hospede[a][q].Endereco);
		        printf("\nTelefone: ");
		        gets(hospede[a][q].Telefone);
		        printf("\nEmail: ");
		        gets(hospede[a][q].Email);
			    Hotel[a][q]='O';
	    	    fMapa(Hotel);
	    	    printf("\nO Check-In no quarto %d do andar %d foi conlcuido", q, a);
	    	    printf("\n");
			}
			else if (Hotel[a][q] == 'R')  // Verifica se o quarto já está reservado
			{
			    fMapa(Hotel);
			    printf("\n\t\t       Quarto ja reservado");
			    printf("\n");
			}
			else if (Hotel[a][q] == 'O')  // Verifica se o quarto já está ocupado
			{
			    fMapa(Hotel);
			    printf("\n\t\t       Quarto ja ocupado");
			    printf("\n");
			}
			else if(a<=0||a>20||q<=0||q>14)  // Verifica se o quarto é inexistente
			{
				fMapa(Hotel);
				printf("\n\t\t       Quarto nao existente\n");
				printf("\n");
			}
			break;
			
		    case 6:  // Realizar Check-Out
		    printf("\nIniciando Check-Out...\n");
		    printf("\nDigite o andar que deseja realizar Check-Out: ");
		    scanf("%d", &a);
		    printf("\nDigite o quarto que deseja realizar Check-Out: " );
		    scanf("%d", &q);
		    if(Hotel[a][q] == 'O')  // Verifica se o quarto está ocupado
		    {
		        Hotel[a][q] = '.';  // Libera o quarto
		        fMapa(Hotel);
		        printf("\nO Check-Out no quarto %d do andar %d foi concluido", q, a);
		        printf("\n");
			}
			else if(Hotel[a][q] == 'R' || Hotel[a][q] == '.')  // Verifica se o quarto não está ocupado
			{
			    fMapa(Hotel);
			    printf("\n\t\t       Quarto nao ocupado (nao houve Check-In no quarto indicado)\n");
			    printf("\n");
			}
			else if(a<=0||a>20||q<=0||q>14)  // Verifica se o quarto é inexistente
			{
				fMapa(Hotel);
				printf("\n\t\t       Quarto nao existente\n");
				printf("\n");
			}
			break;
			
			case 7:  // Taxa de ocupacao
			for(a=0; a<21; a++)
	           for(q=0; q<15; q++)
	        {
	        if (Hotel[a][q]=='R')
	        	TaxR++;
	        if(Hotel[a][q]=='O')
	        	TaxO++;
			}
			fMapa(Hotel);
			printf("\n\t   Taxa de reserva:%.3f%       Taxa de Ocupacao:%.3f%\n", (TaxR/280)*100, (TaxO/280)*100);	// Calcula e mostra as Taxas
			printf("\n");
			TaxR = 0;	// Zera a Taxa para não recontar o mesmo quarto
			TaxO = 0; 
			break;
			
			case 8:	// Visualizar o status do quarto e as dados do hospede  
			printf("\nIniciando a visualizacao do status dos quartos e os dados do hospede...\n");
			printf("\nDigite o andar para a visualizacao: ");
			scanf("%d", &a);
			printf("\nDigite o quarto para a visualizacao: ");
			scanf("%d", &q);
			if(Hotel[a][q]=='O')
		    {
			    hospede[a][q].Status='O';
		    }
			else if(Hotel[a][q]=='R')
			{
				hospede[a][q].Status='R';
			}
			else if(a<=0||a>20||q<=0||q>14)
			{
				fMapa(Hotel);
				printf("\n\t\t       Quarto inexistente\n");
				printf("\n");
				break;
			}
			else
			{
				fMapa(Hotel);
				printf("\n\t O quarto %d do andar %d esta livre --> Status: '.'", q, a);
				printf("\n\t Portanto, nao ha dados de hospede\n");
				printf("\n");
				break;
			}
			fMapa(Hotel);
			fDadosHospede(hospede[a][q].Status, hospede[a][q].CPF, hospede[a][q].Nome, hospede[a][q].Endereco, hospede[a][q].Telefone, hospede[a][q].Email, a, q);
			break;
			
			case 9:  // Sair do programa
			break;
	    }
   }while(S != 9);
}

void fMapa(char Hotel[21][15])  // Função que mostra o mapa do hotel
{
	system("cls");  // Limpa a tela
	
	int i, j;
    printf("========================================================================\nApto -> \t");
	for(j=1; j<15; j++)
        printf("%2d ", j);
    printf("\n\n");
	
	// Dados da matriz
	for(int i=20; i>0; i--)
	{
	    printf("Andar %2d\t", i );
	    for(int j=1; j<15; j++)
		    printf("%2c ", Hotel[i][j]);
	    printf("\n");
	}
	printf("\nLegenda: \t '.' = Livre    \t'R' = Reservado    \t'O' = Ocupado\n");
	printf("\n");
}

void fDadosHospede (char Status, char CPF[20], char Nome[20], char Endereco[100], char Telefone[20], char Email[100], int x, int y) 	// Funcao que mostra os dados do hospede
{
	printf("\n\tStatus do andar %d quarto %d: '%c' -->", x, y, Status);
	if(Status=='R')
		{
		printf(" 'Reservado'\n");
    	}
	else if(Status=='O')
		{
		printf(" 'Ocupado'\n");
		}
	printf("\n\t==== Dados do hospede ====\n");
	printf("\n\tNome: %s\n", Nome);
	printf("\n\tCPF: %s\n", CPF);
	printf("\n\tEndereco: %s\n", Endereco);
	printf("\n\tTelefone: %s\n", Telefone);
	printf("\n\tEmail: %s\n", Email);
	printf("\n");
}

char fVerifica (char cpf[20], char ID[20])    // Funcão que verifica se o cpf da reserva e do check-in são os mesmos
{  
  int v, a, b, c;
  v = 1;
  
  for(a=0 ; ID[a]!='\0';a++);
  for(c=0; cpf[c]!='\0'; c++);
  
  if(a>c)
    v=0;
    
  for(b=0; cpf[b]!='\0'; b++)
    {
    if(cpf[b]!=ID[b])
     v = 0;
	}
    return v;
}

void fclear()	// Função que limpa o buffer de entrada do teclado
{
  char carac;
  while ( (carac = fgetc (stdin)) != EOF && carac != '\n') {}
}
