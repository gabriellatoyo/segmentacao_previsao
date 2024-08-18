/*
    Aplicação para segmentação de mercado e previsão de vendas utilizando dados históricos de vendas, 
    incluindo informações demográficas, comportamentais e preferências dos clientes.

    A funcionalidade de segmentação de mercado permitirá identificar grupos de clientes com características 
    e perfis de compra semelhantes, possibilitando a criação de campanhas de marketing mais direcionadas.

    A funcionalidade de previsão de vendas fornecerá insights sobre períodos de pico e sazonalidade dos produtos, 
    auxiliando no planejamento estratégico e na gestão de estoque de acordo com as previsões.

    Desenvolvedores: Gabriella Toyo Vieira e Lucas Brizola Fontoura
*/



#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{

    //Var Menus
    int codigo_menu, continuar;
    char comecar;
    
    //Var vendas
    int idade_cliente, codigo_produto, codigo_categoria, codigo_segmentacao, quantidade_produto, dia_venda, mes_venda, ano_venda, genero_cliente;
    char estado_cliente[50], cidade_cliente[50];
    float valor_venda;
    bool venda_inserida = false;
    
    //Var previsao
    int jan = 0, fev = 0, mar = 0, abr = 0, maio = 0, jun = 0, jul = 0, ago = 0, set = 0, out = 0, nov = 0, dez = 0;
    int inicio_mes_categoria1 = 0, inicio_mes_categoria2 = 0, inicio_mes_categoria3 = 0, inicio_mes_categoria4 = 0;
    int fim_mes_categoria1 = 0, fim_mes_categoria2 = 0, fim_mes_categoria3 = 0, fim_mes_categoria4 = 0;
    char mes_mais_vendas[50];
    
    //Var segmentacao
    int produto_18_24_categoria1 = 0, produto_25_34_categoria1 = 0, produto_35_44_categoria1 = 0, produto_45_54_categoria1 = 0, produto_55_64_categoria1 = 0, produto_65_categoria1 = 0;
    int produto_18_24_categoria2 = 0, produto_25_34_categoria2 = 0, produto_35_44_categoria2 = 0, produto_45_54_categoria2 = 0, produto_55_64_categoria2 = 0, produto_65_categoria2 = 0;
    int produto_18_24_categoria3 = 0, produto_25_34_categoria3 = 0, produto_35_44_categoria3 = 0, produto_45_54_categoria3 = 0, produto_55_64_categoria3 = 0, produto_65_categoria3 = 0;
    int produto_18_24_categoria4 = 0, produto_25_34_categoria4 = 0, produto_35_44_categoria4 = 0, produto_45_54_categoria4 = 0, produto_55_64_categoria4 = 0, produto_65_categoria4 = 0;
    char produto_mais_vendido_18_24[50], produto_mais_vendido_25_34[50], produto_mais_vendido_35_44[50], produto_mais_vendido_45_54[50], produto_mais_vendido_55_64[50], produto_mais_vendido_65_mais[50];
    int quantidade_maxima_18_24, quantidade_maxima_25_34, quantidade_maxima_35_44, quantidade_maxima_45_54, quantidade_maxima_55_64, quantidade_maxima_65_mais;
    int categoria1_masculino = 0, categoria2_masculino = 0, categoria3_masculino = 0, categoria4_masculino = 0, categoria1_feminino = 0, categoria2_feminino = 0, categoria3_feminino = 0, categoria4_feminino = 0, categoria1_outro = 0, categoria2_outro = 0, categoria3_outro = 0, categoria4_outro = 0; 
	
	//Var tempo
	time_t tempo_atual = time(NULL);
	struct tm tm = *localtime(&tempo_atual);
	int ano_atual = tm.tm_year + 1900;
	int mes_atual = tm.tm_mon + 1;
	int dia_atual = tm.tm_mday;


	// Apresentação do Programa
    printf("\nOlá.\n");
	printf("Seja Bem-vindo/a!\n");
	printf("Este Programa tem por objetivo realizar a segmentação de mercado");
	printf(" e a previsão de vendas a partir de dados históricos de vendas inseridos por você.\n");
	printf("Para começar, você deve inserir os dados do cliente.\n");
	printf("----------------------------------------------------------------------------------------\n");

	printf("Pressione 'Enter' para continuar: ");
	scanf("%c", &comecar);
	
	do 
	{
    	system("clear");
    				
    	//Menu
    	printf("O que deseja fazer?\n");
    	printf("1 - Inserir venda\n");
    	printf("2 - Segmentação de mercado\n");
    	printf("3 - Previsão de vendas\n");
    	printf("4 - Sair\n");
    	scanf("%d", &codigo_menu);
    	
    	switch (codigo_menu)
    	{
    		case 1:
    			// Pedir informações da venda
    			do
    			{
                    system("clear");
    				
    				// Data da venda
    				printf("Digite o dia da venda:\n");
    				scanf("%d", &dia_venda);
    				printf("Digite mês da venda:\n");
    				scanf("%d", &mes_venda);
    				printf("Digite o ano da venda:\n");
    				scanf("%d", &ano_venda);
    
    				// Tratar erro ano
    				while (ano_venda > ano_atual || ano_venda < 1) 
    				{
    					printf("Ano inválido.\n");
    					printf("Digite um ano válido: ");
    					scanf("%d", &ano_venda);
    				}
    				
    				// Tratar erro mês		
    				if(ano_venda == ano_atual)
    				{
    					while(mes_venda > mes_atual || mes_venda < 1)
    					{
    						printf("Mês inválido.\n");
    						printf("Digite um mês válido: ");
    						scanf("%d", &mes_venda);
    					}
    				}
    				else
    				{
    					while(mes_venda > 12 || mes_venda < 1)
    					{
    						printf("Mês inválido.\n");
    						printf("Digite um mês válido: ");
    						scanf("%d", &mes_venda);
    					}
    				}
    				
    				
    				//Tratar erro dia
    				if(ano_venda == ano_atual && mes_venda == mes_atual)
    				{
    					while(dia_venda > dia_atual || dia_venda < 1)
    					{
    						printf("Dia inválido.\n");
    						printf("Digite um dia válido: ");
    						scanf("%d", &dia_venda);
    					}
    				}
    				else
    				{
    					switch(mes_venda)
    					{
    						case 1:
    						case 3:
    						case 5:
    						case 7:
    						case 8:
    						case 10:
    						case 12:
    							while(dia_venda > 31 || dia_venda < 1)
    							{
    								printf("Dia inválido.\n");
    								printf("Digite um dia válido: ");
    								scanf("%d", &dia_venda);
    							}
    							
    						break;
    						case 2:
    							if(ano_venda % 4 == 0 && ano_venda % 100 != 0)
    							{
    								while(dia_venda > 29 || dia_venda < 1)
    								{
    									printf("Dia inválido.\n");
    									printf("Digite um dia válido: ");
    									scanf("%d", &dia_venda);
    								}
    							}
    							else
    							{
    								while(dia_venda > 28 || dia_venda < 1)
    								{
    									printf("Dia inválido.\n");
    									printf("Digite um dia válido: ");
    									scanf("%d", &dia_venda);
    								}
    							}
    						break;
    						case 4:
    						case 6:
    						case 9:
    						case 11:
    							while(dia_venda > 30 || dia_venda < 1)
    							{
    								printf("Dia inválido.\n");
    								printf("Digite um dia válido: ");
    								scanf("%d", &dia_venda);
    							}
    						break;
    					}
    				}
                    
                    
    				system("clear");
    
    				//Produtos
    				printf("01 - Vestido azul");
    				printf("\n02 - Blusa laranja");
    				printf("\n03 - Brinco dourado");
    				printf("\n04 - Colar prata");
    				printf("\n05 - Sapato preto");
    				printf("\n06 - Tênis branco");
    				printf("\n07 - Bolsa marrom");
    				printf("\n08 - Mochila verde");
    				printf("\nDigite o código do produto vendido: ");
    				scanf("%d", &codigo_produto);
    
    				//Tratar erro do codigo produto
    				while (codigo_produto > 8 || codigo_produto < 1)
    				{
    					printf("Código inválido.\n");
    					printf("Digite um código válido: ");
    					scanf("%d", &codigo_produto);
    				}
    				
    				printf("Digite a quantidade do produto: ");
    				scanf("%d", &quantidade_produto);
    
    				//Tratar erro quantidade
    				while(quantidade_produto < 1)
    				{
    					printf("Quantidade inválida.\n");
    					printf("Digite uma quantidade válida: ");
    					scanf("%d", &quantidade_produto);
    					
    				}
    
    				// Contabilizar mês da venda
    				switch(mes_venda)
    				{
    					case 1:
    						jan += quantidade_produto;
    					break;
    					case 2:
    						fev += quantidade_produto;
    					break;
    					case 3:
    						mar += quantidade_produto;
    					break;
    					case 4:
    						abr += quantidade_produto;
    					break;
    					case 5:
    						maio += quantidade_produto;
    					break;
    					case 6:
    						jun += quantidade_produto;
    					break;
    					case 7:
    						jul += quantidade_produto;
    					break;
    					case 8:
    						ago += quantidade_produto;
    					break;
    					case 9:
    						set += quantidade_produto;
    					break;
    					case 10:
    						out += quantidade_produto;
    					break;
    					case 11:
    						nov += quantidade_produto;
    					break;
    					case 12:
    						dez += quantidade_produto;
    					break;
    				}
    
    				system("clear");
    				
    				printf("Digite o valor da venda: ");
    				scanf("%f", &valor_venda);
    
    				//Tratar erro venda
    				while(valor_venda < 0)
    				{
    					printf("Valor inválido.\n");
    					printf("Digite um valor válido: ");
    					scanf("%f", &valor_venda);
    				}
    
    				system("clear");
    
    				printf("1 - Masculino\n");
    				printf("2 - Feminino\n");
    				printf("3 - Outro\n");
    				printf("Digite o código do gênero do cliente: ");
    				scanf("%d", &genero_cliente);
    
    				//Tratar erro gênero
    				while(genero_cliente != 1 && genero_cliente != 2 && genero_cliente != 3)
    				{
    					printf("Código inválido.\n");
    					printf("Digite um código válido: ");
    					scanf("%d", &genero_cliente);
    				}
    
    				system("clear");
    
    				printf("Digite o Estado do cliente: ");
    				scanf("%s", estado_cliente);
    
    				system("clear");
    				
    				printf("Digite a Cidade do cliente: ");
    				scanf("%s",cidade_cliente);
    
    				system("clear");
    				
    				printf("Digite a idade do cliente: ");
    				scanf("%d", &idade_cliente);
    
    				//Tratar erro idade
    				while(idade_cliente < 18 || idade_cliente > 130)
    				{
    					printf("Idade inválida.\n");
    					printf("Digite uma idade válida: ");
    					scanf("%d", &idade_cliente);
    				}
    
    				// Coloca o código da categoria e contabiliza com a idade do cliente
    				switch(codigo_produto)
    				{
    					case 1:
    					case 2:
    						codigo_categoria = 1; // Roupas
    						if (idade_cliente >= 18 && idade_cliente <= 24)
    						{
    							produto_18_24_categoria1 += quantidade_produto;
    						}
    						else if (idade_cliente >= 25 && idade_cliente <= 34)
    						{
    							produto_25_34_categoria1 += quantidade_produto;
    						}
    						else if (idade_cliente >= 35 && idade_cliente <= 44)
    						{
    							produto_35_44_categoria1 += quantidade_produto;
    						}
    						else if (idade_cliente >= 45 && idade_cliente <= 54)
    						{
    							produto_45_54_categoria1 += quantidade_produto;
    						}
    						else if (idade_cliente >= 55 && idade_cliente <= 64)
    						{
    							produto_55_64_categoria1 += quantidade_produto;
    						}
    						else
    						{
    							produto_65_categoria1 += quantidade_produto;
    						}
    					break;
    					case 3:
    					case 4:
    						codigo_categoria = 2; // Acessórios
    						if(idade_cliente >= 18 && idade_cliente <= 24)
    						{
    							produto_18_24_categoria2 += quantidade_produto;
    						}
    						else if(idade_cliente >= 25 && idade_cliente <= 34)
    						{
    							produto_25_34_categoria2 += quantidade_produto;
    						}
    						else if(idade_cliente >= 35 && idade_cliente <= 44)
    						{
    							produto_35_44_categoria2 += quantidade_produto;
    						}
    						else if(idade_cliente >= 45 && idade_cliente <= 54)
    						{
    							produto_45_54_categoria2 += quantidade_produto;
    						}
    						else if(idade_cliente >= 55 && idade_cliente <= 64)
    						{
    							produto_55_64_categoria2 += quantidade_produto;
    						}
    						else
    						{
    							produto_65_categoria2 += quantidade_produto;
    						}
    					break;
    					case 5:
    					case 6:
    						codigo_categoria = 3; // Sapatos
    						if(idade_cliente >= 18 && idade_cliente <= 24)
    						{
    							produto_18_24_categoria3 += quantidade_produto;
    						}
    						else if(idade_cliente >= 25 && idade_cliente <= 34)
    						{
    							produto_25_34_categoria3 += quantidade_produto;
    						}
    						else if(idade_cliente >= 35 && idade_cliente <= 44)
    						{
    							produto_35_44_categoria3 += quantidade_produto;
    						}
    						else if(idade_cliente >= 45 && idade_cliente <= 54)
    						{
    							produto_45_54_categoria3 += quantidade_produto;
    						}
    						else if(idade_cliente >= 55 && idade_cliente <= 64)
    						{
    							produto_55_64_categoria3 += quantidade_produto;
    						}
    						else
    						{
    							produto_65_categoria3 += quantidade_produto;
    						}
    					break;
    					case 7:
    					case 8:
    						codigo_categoria = 4; // Bolsas e mochilas
    						if(idade_cliente >= 18 && idade_cliente <= 24)
    						{
    							produto_18_24_categoria4 += quantidade_produto;
    						}
    						else if(idade_cliente >= 25 && idade_cliente <= 34)
    						{
    							produto_25_34_categoria4 += quantidade_produto;
    						}
    						else if(idade_cliente >= 35 && idade_cliente <= 44)
    						{
    							produto_35_44_categoria4 += quantidade_produto;
    						}
    						else if(idade_cliente >= 45 && idade_cliente <= 54)
    						{
    							produto_45_54_categoria4 += quantidade_produto;
    						}
    						else if(idade_cliente >= 55 && idade_cliente <= 64)
    						{
    							produto_55_64_categoria4 += quantidade_produto;
    						}
    						else
    						{
    							produto_65_categoria4 += quantidade_produto;
    						}
    					break;
    					default:
    						codigo_categoria = 5; // BUG
    					break;
    				}
    
    				//Contabilizar gênero de acordo com a categoria
    				switch(genero_cliente)
    				{
    					case 1:
    						switch(codigo_categoria)
    						{
    							case 1:
    								categoria1_masculino += 1;
    							break;
    							case 2:
    								categoria2_masculino += 1;
    							break;
    							case 3:
    								categoria3_masculino += 1;
    							break;
    							case 4:
    								categoria4_masculino += 1;
    							break;
    						}
    					break;
    					case 2:
    						switch(codigo_categoria)
    						{
    							case 1:
    								categoria1_feminino += 1;
    							break;
    							case 2:
    								categoria2_feminino += 1;
    							break;
    							case 3:
    								categoria3_feminino += 1;
    							break;
    							case 4:
    								categoria4_feminino += 1;
    							break;
    						}
    					break;
    					case 3:
    						switch(codigo_categoria)
    						{
    							case 1:
    								categoria1_outro += 1;
    							break;
    							case 2:
    								categoria2_outro += 1;
    							break;
    							case 3:
    								categoria3_outro += 1;
    							break;
    							case 4:
    								categoria4_outro += 1;
    							break;
    						}
    					break;
    				}
    				
    
    				//Vendas no inicio do mês 
    				if (dia_venda <=15) 
    				{
    					switch (codigo_categoria) 
    					{
    						case 1:
    							inicio_mes_categoria1 += quantidade_produto;
    						break;
    						case 2:
    							inicio_mes_categoria2 += quantidade_produto;
    						break;
    						case 3:
    							inicio_mes_categoria3 += quantidade_produto;
    						break;
    						case 4:
    							inicio_mes_categoria4 += quantidade_produto;
    						break;
    					}
    				}
    				//Vendas no final do mês
    				else
    				{
    					switch (codigo_categoria) 
    					{
    						case 1:
    							fim_mes_categoria1 += quantidade_produto;
    						break;
    						case 2:
    							fim_mes_categoria2 += quantidade_produto;
    						break;
    						case 3:
    							fim_mes_categoria3 += quantidade_produto;
    						break;
    						case 4:
    							fim_mes_categoria4 += quantidade_produto;
    						break;
    					}
    				}
    
    				system("clear");
    
    				// Venda foi inserida
    				venda_inserida = true;
    				
    				printf("Deseja inserir mais uma venda? Digite 1 para SIM ou qualquer outro número para NÃO: ");
    				scanf("%d", &continuar);
    			}
    			while (continuar == 1);
    	
    			break;	
            
    		case 2:
    			system("clear");
    		
    			if(venda_inserida)
    			{
    				// Contabilizar para 18 - 24 anos
    				if(produto_18_24_categoria1 >= produto_18_24_categoria2 && produto_18_24_categoria1 >= produto_18_24_categoria3 && produto_18_24_categoria1 >= produto_18_24_categoria4)
    				{
    					strcpy(produto_mais_vendido_18_24, "Roupas");
    					quantidade_maxima_18_24 = produto_18_24_categoria1;
    				}
    				else if(produto_18_24_categoria2 >= produto_18_24_categoria1 && produto_18_24_categoria2 >= produto_18_24_categoria3 && produto_18_24_categoria2 >= produto_18_24_categoria4)
    				{
    					strcpy(produto_mais_vendido_18_24, "Acessórios");
    					quantidade_maxima_18_24 = produto_18_24_categoria2;
    				}
    				else if(produto_18_24_categoria3 >= produto_18_24_categoria1 && produto_18_24_categoria3 >= produto_18_24_categoria2 && produto_18_24_categoria3 >= produto_18_24_categoria4)
    				{
    					strcpy(produto_mais_vendido_18_24, "Sapatos");
    					quantidade_maxima_18_24 = produto_18_24_categoria3;
    				}
    				else if(produto_18_24_categoria4 >= produto_18_24_categoria1 && produto_18_24_categoria4 >= produto_18_24_categoria2 && produto_18_24_categoria4 >= produto_18_24_categoria3)
    				{
    					strcpy(produto_mais_vendido_18_24, "Bolsas e mochilas");
    					quantidade_maxima_18_24 = produto_18_24_categoria3;
    				}
    				else
    				{
    					strcpy(produto_mais_vendido_18_24, "Bug");
    					quantidade_maxima_18_24 = 0;
    				}
    					
    				// Contabilizar para 25 - 34 anos
    				if(produto_25_34_categoria1 >= produto_25_34_categoria2 && produto_25_34_categoria1 >= produto_25_34_categoria3 && produto_25_34_categoria1 >= produto_25_34_categoria4)
    				{
    					strcpy(produto_mais_vendido_25_34, "Roupas");
    					quantidade_maxima_25_34 = produto_25_34_categoria1;
    				}
    				else if(produto_25_34_categoria2 >= produto_25_34_categoria1 && produto_25_34_categoria2 >= produto_25_34_categoria3 && produto_25_34_categoria2 >= produto_25_34_categoria4)
    				{
    					strcpy(produto_mais_vendido_25_34, "Acessórios");
    					quantidade_maxima_25_34 = produto_25_34_categoria2;
    				}
    				else if(produto_25_34_categoria3 >= produto_25_34_categoria1 && produto_25_34_categoria3 >= produto_25_34_categoria2 && produto_25_34_categoria3 >= produto_25_34_categoria4)
    				{
    					strcpy(produto_mais_vendido_25_34, "Sapatos");
    					quantidade_maxima_25_34 = produto_25_34_categoria3;
    				}
    				else if(produto_25_34_categoria4 >= produto_25_34_categoria1 && produto_25_34_categoria4 >= produto_25_34_categoria2 && produto_25_34_categoria4 >= produto_25_34_categoria3)
    				{
    					strcpy(produto_mais_vendido_25_34, "Bolsas e mochilas");
    					quantidade_maxima_25_34 = produto_25_34_categoria4;
    				}
    				else
    				{
    					strcpy(produto_mais_vendido_25_34, "Bug");
    					quantidade_maxima_25_34 = 0;
    				}
    
    				// Contabilizar para 35 - 44 anos
    				if(produto_35_44_categoria1 >= produto_35_44_categoria2 && produto_35_44_categoria1 >= produto_35_44_categoria3 && produto_35_44_categoria1 >= produto_35_44_categoria4)
    				{
    					strcpy(produto_mais_vendido_35_44, "Roupas");
    					quantidade_maxima_35_44 = produto_35_44_categoria1;
    				}
    				else if(produto_35_44_categoria2 >= produto_35_44_categoria1 && produto_35_44_categoria2 >= produto_35_44_categoria3 && produto_35_44_categoria2 >= produto_35_44_categoria4)
    				{
    					strcpy(produto_mais_vendido_35_44, "Acessórios");
    					quantidade_maxima_35_44 = produto_35_44_categoria2;
    				}
    				else if(produto_35_44_categoria3 >= produto_35_44_categoria1 && produto_35_44_categoria3 >= produto_35_44_categoria2 && produto_35_44_categoria3 >= produto_35_44_categoria4)
    				{
    					strcpy(produto_mais_vendido_35_44, "Sapatos");
    					quantidade_maxima_35_44 = produto_35_44_categoria3;
    				}
    				else if(produto_35_44_categoria4 >= produto_35_44_categoria1 && produto_35_44_categoria4 >= produto_35_44_categoria2 && produto_35_44_categoria4 >= produto_35_44_categoria3)
    				{
    					strcpy(produto_mais_vendido_35_44, "Bolsas e mochilas");
    					quantidade_maxima_35_44 = produto_35_44_categoria4;
    				}
    				else
    				{
    					strcpy(produto_mais_vendido_35_44, "Bug");
    					quantidade_maxima_35_44 = 0;
    				}
    
    				// Contabilizar para 45 - 54 anos
    				if(produto_45_54_categoria1 >= produto_45_54_categoria2 && produto_45_54_categoria1 >= produto_45_54_categoria3 && produto_45_54_categoria1 >= produto_45_54_categoria4)
    				{
    					strcpy(produto_mais_vendido_45_54, "Roupas");
    					quantidade_maxima_45_54 = produto_45_54_categoria1;
    				}
    				else if(produto_45_54_categoria2 >= produto_45_54_categoria1 && produto_45_54_categoria2 >= produto_45_54_categoria3 && produto_45_54_categoria2 >= produto_45_54_categoria4)
    				{
    					strcpy(produto_mais_vendido_45_54, "Acessórios");
    					quantidade_maxima_45_54 = produto_45_54_categoria2;
    				}
    				else if(produto_45_54_categoria3 >= produto_45_54_categoria1 && produto_45_54_categoria3 >= produto_45_54_categoria2 && produto_45_54_categoria3 >= produto_45_54_categoria4)
    				{
    					strcpy(produto_mais_vendido_45_54, "Sapatos");
    					quantidade_maxima_45_54 = produto_45_54_categoria3;
    				}
    				else if(produto_45_54_categoria4 >= produto_45_54_categoria1 && produto_45_54_categoria4 >= produto_45_54_categoria2 && produto_45_54_categoria4 >= produto_45_54_categoria3)
    				{
    					strcpy(produto_mais_vendido_45_54, "Bolsas e mochilas");
    					quantidade_maxima_45_54 = produto_45_54_categoria4;
    				}
    				else
    				{
    					strcpy(produto_mais_vendido_45_54, "Bug");
    					quantidade_maxima_45_54 = 0;
    				}
    
    				// Contabilizar para 55 - 64 anos
    				if(produto_55_64_categoria1 >= produto_55_64_categoria2 && produto_55_64_categoria1 >= produto_55_64_categoria3 && produto_55_64_categoria1 >= produto_55_64_categoria4)
    				{
    					strcpy(produto_mais_vendido_55_64, "Roupas");
    					quantidade_maxima_55_64 = produto_55_64_categoria1;
    				}
    				else if(produto_55_64_categoria2 >= produto_55_64_categoria1 && produto_55_64_categoria2 >= produto_55_64_categoria3 && produto_55_64_categoria2 >= produto_55_64_categoria4)
    				{
    					strcpy(produto_mais_vendido_55_64, "Acessórios");
    					quantidade_maxima_55_64 = produto_55_64_categoria2;
    				}
    				else if(produto_55_64_categoria3 >= produto_55_64_categoria1 && produto_55_64_categoria3 >= produto_55_64_categoria2 && produto_55_64_categoria3 >= produto_55_64_categoria4)
    				{
    					strcpy(produto_mais_vendido_55_64, "Sapatos");
    					quantidade_maxima_55_64 = produto_55_64_categoria3;
    				}
    				else if(produto_55_64_categoria4 >= produto_55_64_categoria1 && produto_55_64_categoria4 >= produto_55_64_categoria2 && produto_55_64_categoria4 >= produto_55_64_categoria3)
    				{
    					strcpy(produto_mais_vendido_55_64, "Bolsas e mochilas");
    					quantidade_maxima_55_64 = produto_55_64_categoria4;
    				}
    				else
    				{
    					strcpy(produto_mais_vendido_55_64, "Bug");
    					quantidade_maxima_55_64 = 0;
    				}
    
    				// Contabilizar para 65+ anos
    				if(produto_65_categoria1 >= produto_65_categoria2 && produto_65_categoria1 >= produto_65_categoria3 && produto_65_categoria1 >= produto_65_categoria4)
    				{
    					strcpy(produto_mais_vendido_65_mais, "Roupas");
    					quantidade_maxima_65_mais = produto_65_categoria1;
    				}
    				else if(produto_65_categoria2 >= produto_65_categoria1 && produto_65_categoria2 >= produto_65_categoria3 && produto_65_categoria2 >= produto_65_categoria4)
    				{
    					strcpy(produto_mais_vendido_65_mais, "Acessórios");
    					quantidade_maxima_65_mais = produto_65_categoria2;
    				}
    				else if(produto_65_categoria3 >= produto_65_categoria1 && produto_65_categoria3 >= produto_65_categoria2 && produto_65_categoria3 >= produto_65_categoria4)
    				{
    					strcpy(produto_mais_vendido_65_mais, "Sapatos");
    					quantidade_maxima_65_mais = produto_65_categoria3;
    				}
    				else if(produto_65_categoria4 >= produto_65_categoria1 && produto_65_categoria4 >= produto_65_categoria2 && produto_65_categoria4 >= produto_65_categoria3)
    				{
    					strcpy(produto_mais_vendido_65_mais, "Bolsas e mochilas");
    					quantidade_maxima_65_mais = produto_65_categoria4;
    				}
    				else
    				{
    					strcpy(produto_mais_vendido_65_mais, "Bug");
    					quantidade_maxima_65_mais = 0;
    				}
    
    			
    				printf("--------------------SEGMENTAÇÃO DE MERCADO--------------------\n");
    			    printf("A partir dos dados inseridos, temos as seguintes análises: \n\n");
    
    			    //Se não tiver nenhum dado de determinada idade, não deve abreak;cer.
    		    	if(produto_18_24_categoria1 != 0 || produto_18_24_categoria2 != 0 || produto_18_24_categoria3 != 0 || produto_18_24_categoria4 != 0)
    		    	{
    		    		printf("- A categoria mais vendida entre pessoas de 18 a 24 anos foi: %s ", produto_mais_vendido_18_24);
    	    			printf(" (%d unidade/s vendidas).\n", quantidade_maxima_18_24);
    		    	}
    
    		    	if(produto_25_34_categoria1 != 0 || produto_25_34_categoria2 != 0 || produto_25_34_categoria3 != 0 || produto_25_34_categoria4 != 0)
    		    	{
    		    		printf("- A categoria mais vendida entre pessoas de 25 a 34 anos foi: %s ", produto_mais_vendido_25_34);
    		    		printf(" (%d unidade/s vendidas).\n", quantidade_maxima_25_34);
    		    	}
    
    		    	if(produto_35_44_categoria1 != 0 || produto_35_44_categoria2 != 0 || produto_35_44_categoria3 != 0 || produto_35_44_categoria4 != 0)
    		    	{
    		    		printf("- A categoria mais vendida entre pessoas de 35 a 44 anos foi: %s ", produto_mais_vendido_35_44);
    		    		printf(" (%d unidade/s vendidas).\n", quantidade_maxima_35_44);
    		    	}
    
    		    	if(produto_45_54_categoria1 != 0 || produto_45_54_categoria2 != 0 || produto_45_54_categoria3 != 0 || produto_45_54_categoria4 != 0)
    		    	{
    		    		printf("- A categoria mais vendida entre pessoas de 45 a 54 anos foi: %s ", produto_mais_vendido_45_54);
    		    		printf(" (%d unidade/s vendidas).\n", quantidade_maxima_45_54);
    		    	}
    
    		    	if(produto_55_64_categoria1 != 0 || produto_55_64_categoria2 != 0 || produto_55_64_categoria3 != 0 || produto_55_64_categoria4 != 0)
    		    	{
    		    		printf("- A categoria mais vendida entre pessoas de 55 a 64 anos foi: %s ", produto_mais_vendido_55_64);
    		    		printf(" (%d unidade/s vendidas).\n", quantidade_maxima_55_64);
    		    	}
    
    		    	if(produto_65_categoria1 != 0 || produto_65_categoria2 != 0 || produto_65_categoria3 != 0 || produto_65_categoria4 != 0)
    		    	{
    		    		printf("- A categoria mais vendida entre pessoas de  65 anos ou mais foi: %s ", produto_mais_vendido_65_mais);
    		    		printf(" (%d unidade/s vendidas).\n", quantidade_maxima_65_mais);
    		    	}
    
    				printf("\nAs categorias mais vendidas por gênero foram: \n");
    				printf("- Masculino: ");
    				
    			    //Checagem de qual categoria vendeu mais produtos por gênero
    		    	if(categoria1_masculino >= categoria2_masculino && categoria1_masculino >= categoria3_masculino && categoria1_masculino >= categoria4_masculino && categoria1_masculino != 0)
    		    	{
    		    		printf("Roupas (%d venda/s).\n", categoria1_masculino);
    		    	}
    		    	else if(categoria2_masculino >= categoria1_masculino && categoria2_masculino >= categoria3_masculino && categoria2_masculino >= categoria4_masculino && categoria2_masculino != 0)
    		    	{
    		    		printf("Acessórios (%d venda/s).\n", categoria2_masculino);
    		    	}
    		    	else if(categoria3_masculino >= categoria1_masculino && categoria3_masculino >= categoria2_masculino && categoria3_masculino >= categoria4_masculino && categoria3_masculino != 0)
    		    	{
    		    		printf("Sapatos (%d venda/s).\n", categoria3_masculino);
    		    	}
    			    else if(categoria4_masculino >= categoria1_masculino && categoria4_masculino >= categoria2_masculino && categoria4_masculino >= categoria3_masculino && categoria4_masculino != 0)
    		    	{
    		    		printf("Bolsas e mochilas (%d venda/s).\n", categoria4_masculino);
    		    	}
    		    	else
    		    	{
    		    		printf("Não houveram vendas.\n");	
    		    	}
    
    			   	printf("- Feminino: ");
    		    	if(categoria1_feminino >= categoria2_feminino && categoria1_feminino >= categoria3_feminino && categoria1_feminino >= categoria4_feminino && categoria1_feminino != 0)
    		    	{
    		    		printf("Roupas (%d venda/s).\n", categoria1_feminino);
    		    	}
    		    	else if(categoria2_feminino >= categoria1_feminino && categoria2_feminino >= categoria3_feminino && categoria2_feminino >= categoria4_feminino && categoria2_feminino != 0)
    		    	{
    		    		printf("Acessórios (%d venda/s).\n", categoria2_feminino);
    		    	}
    		    	else if(categoria3_feminino >= categoria1_feminino && categoria3_feminino >= categoria2_feminino && categoria3_feminino >= categoria4_feminino && categoria3_feminino != 0)
    		    	{
    		    		printf("Sapatos (%d venda/s).\n", categoria3_feminino);
    		    	}
    			    else if(categoria4_feminino >= categoria1_feminino && categoria4_feminino >= categoria2_feminino && categoria4_feminino >= categoria3_feminino && categoria4_feminino != 0)
    		    	{
    		    		printf("Bolsas e mochilas (%d venda/s).\n", categoria4_feminino);
    		    	}
    		    	else
    		    	{
    		    		printf("Não houveram vendas.\n");	
    		    	}
    
    		    	printf("- Outro: ");
    		    	if(categoria1_outro >= categoria2_outro && categoria1_outro >= categoria3_outro && categoria1_outro >= categoria4_outro && categoria1_outro != 0)
    		    	{
    		    		printf("Roupas (%d venda/s).\n", categoria1_outro);
    		    	}
    		    	else if(categoria2_outro >= categoria1_outro && categoria2_outro >= categoria3_outro && categoria2_outro >= categoria4_outro && categoria2_outro != 0)
    		    	{
    		    		printf("Acessórios (%d venda/s).\n", categoria2_outro);
    		    	}
    		    	else if(categoria3_outro >= categoria1_outro && categoria3_outro >= categoria2_outro && categoria3_outro >= categoria4_outro && categoria3_outro != 0)
    		    	{
    		    		printf("Sapatos (%d venda/s).\n", categoria3_outro);
    		    	}
    			    else if(categoria4_outro >= categoria1_outro && categoria4_outro >= categoria2_outro && categoria4_outro >= categoria3_outro && categoria4_outro != 0)
    		    	{
    		    		printf("Bolsas e mochilas (%d venda/s).\n", categoria4_outro);
    		    	}
    		    	else
    		    	{
    		    		printf("Não houveram vendas.\n");	
    		    	}
    
    				printf("\nPressione 'Enter' para continuar: ");
    				getchar(); //Pegar lixo
    				scanf("%c", &comecar);
    			    
    			    printf("--------------------------------------------------------------\n");
    			}
    			else
    			{
    				printf("-----------------------AVISO----------------------\n");
    				printf("Por favor, insira os dados de pelo menos uma venda\n");
    				printf("--------------------------------------------------\n");
    				printf("Pressione 'Enter' para continuar: ");
    				getchar(); // pegar lixo
    				scanf("%c", &comecar);			    	
    			}
    		break;
            //Previsão de Vendas
    		case 3:
    			system("clear");
    		
    			//Verificar qual mês teve mais vendas
    			if(venda_inserida)
    			{
    				if(jan >= fev && jan >= mar && jan >= abr && jan >= maio && jan >= jun && jan >= jul && jan >= ago && jan >= set && jan >= out && jan >= nov && jan >= dez)
    				{
    					strcpy(mes_mais_vendas, "Janeiro.");
    				}
    				else if(fev >= jan && fev >= mar && fev >= abr && fev >= maio && fev >= jun && fev >= jul && fev >= ago && fev >= set && fev >= out && fev >= nov && fev >= dez)
    				{
    					strcpy(mes_mais_vendas,"Fevereiro.");
    				}
    				else if(mar >= jan && mar >= fev && mar >= abr && mar >= maio && mar >= jun && mar >= jul && mar >= ago && mar >= set && mar >= out && mar >= nov && mar >= dez)
    				{
    					strcpy(mes_mais_vendas, "Março.");
    				}
    				else if(abr >= jan && abr >= fev && abr >= mar && abr >= maio && abr >= jun && abr >= jul && abr >= ago && abr >= set && abr >= out && abr >= nov && abr >= dez)
    				{
    					strcpy(mes_mais_vendas, "Abril.");
    				}
    				else if(maio >= jan && maio >= fev && maio >= mar && maio >= abr && maio >= jun && maio >= jul && maio >= ago && maio >= set && maio >= out && maio >= nov && maio >= dez)
    				{
    					strcpy(mes_mais_vendas, "Maio.");
    				}
    				else if(jun >= jan && jun >= fev && jun >= mar && jun >= abr && jun >= maio && jun >= jul && jun >= ago && jun >= set && jun >= out && jun >= nov && jun >= dez)
    				{
    					strcpy(mes_mais_vendas, "Junho.");
    				}
    				else if(jul >= jan && jul >= fev && jul >= mar && jul >= abr && jul >= maio && jul >= jun && jul >= ago && jul >= set && jul >= out && jul >= nov && jul >= dez)
    				{
    					strcpy(mes_mais_vendas, "Julho.");
    				}
    				else if(ago >= jan && ago >= fev && ago >= mar && ago >= abr && ago >= maio && ago >= jun && ago >= jul && ago >= set && ago >= out && ago >= nov && ago >= dez)
    				{
    					strcpy(mes_mais_vendas, "Agosto.");
    				}
    				else if(set >= jan && set >= fev && set >= mar && set >= abr && set >= maio && set >= jun && set >= jul && set >= ago && set >= out && set >= nov && set >= dez)
    				{
    					strcpy(mes_mais_vendas, "Setembro.");
    				}
    				else if(out >= jan && out >= fev && out >= mar && out >= abr && out >= maio && out >= jun && out >= jul && out >= ago && out >= set && out >= nov && out >= dez)
    				{
    					strcpy(mes_mais_vendas, "Outubro.");
    				}
    				else if(nov >= jan && nov >= fev && nov >= mar && nov >= abr && nov >= maio && nov >= jun && nov >= jul && nov >= ago && nov >= set && nov >= out && nov >= dez)
    				{
    					strcpy(mes_mais_vendas, "Novembro.");
    				}
    				else if(dez >= jan && dez >= fev && dez >= mar && dez >= abr && dez >= maio && dez >= jun && dez >= jul && dez >= ago && dez >= set && dez >= out && dez >= nov)
    				{
    					strcpy(mes_mais_vendas, "Dezembro.");
    				}
    				else
    				{
    					strcpy(mes_mais_vendas, "Bug");
    				}
    
    				printf("--------------------PREVISÃO DE VENDAS--------------------\n");
    				printf("A partir dos dados inseridos, temos as seguintes análises: \n\n");
    				printf("- O mês com mais vendas foi: %s\n", mes_mais_vendas);
    				printf("Recomendamos tentar focar suas vendas mais nesse mês.\n\n");
    
    				printf("- Na primeira quinzena do mês, a categoria mais vendida foi: ");
    				
    				//Verificar qual produto foi mais vendido na primeira quinzena do mês
    				if (inicio_mes_categoria1 >= inicio_mes_categoria2 && inicio_mes_categoria1 >= inicio_mes_categoria3 && inicio_mes_categoria1 >= inicio_mes_categoria4 && inicio_mes_categoria1 != 0) 
    				{
    					printf("Roupas.\n");							
    				}
    				else if (inicio_mes_categoria2 >= inicio_mes_categoria1 && inicio_mes_categoria2 >= inicio_mes_categoria3 && inicio_mes_categoria2 >= inicio_mes_categoria4 && inicio_mes_categoria2 != 0)
    				{
    					printf("Acessorios.\n");	
    				}
    				else if (inicio_mes_categoria3 >= inicio_mes_categoria1 && inicio_mes_categoria3 >= inicio_mes_categoria2 && inicio_mes_categoria3 >= inicio_mes_categoria4 && inicio_mes_categoria3 != 0)
    				{
    					printf("Sapatos.\n");		
    				}
    				else if (inicio_mes_categoria4 >= inicio_mes_categoria1 && inicio_mes_categoria4 >= inicio_mes_categoria2 && inicio_mes_categoria4 >= inicio_mes_categoria3 && inicio_mes_categoria4 != 0)
    				{
    					printf("Bolsas && Mochilas.\n");								
    				}
    				else 
    				{
    					printf("Não houveram vendas na primeira quinzena de mês.\n");	
    				}
    				
    				printf("\n- Na última quinzena do mês, a categoria mais vendida foi: ");
    
    				//Verificar qual produto foi mais vendido na última quinzena do mês
    				if (fim_mes_categoria1 >= fim_mes_categoria2 && fim_mes_categoria1 >= fim_mes_categoria3 && fim_mes_categoria1 >= fim_mes_categoria4 && fim_mes_categoria1 != 0) 
    				{
    					printf("Roupas.\n");						
    				}
    				else if (fim_mes_categoria2 >= fim_mes_categoria1 && fim_mes_categoria2 >= fim_mes_categoria3 && fim_mes_categoria2 >= fim_mes_categoria4 && fim_mes_categoria2 != 0)
    				{
    					printf("Acessorios.\n");	
    				}
    				else if (fim_mes_categoria3 >= fim_mes_categoria1 && fim_mes_categoria3 >= fim_mes_categoria2 && fim_mes_categoria3 >= fim_mes_categoria4 && fim_mes_categoria3 != 0)
    				{
    					printf("Sapatos.\n");		
    				}
    				else if (fim_mes_categoria4 >= fim_mes_categoria1 && fim_mes_categoria4 >= fim_mes_categoria2 && fim_mes_categoria4 >= fim_mes_categoria3 && fim_mes_categoria4 != 0)
    				{
    					printf("Bolsas && Mochilas.\n");	
    					
    				}
    				else
    				{
    					printf("Não houveram vendas na última quinzena de mês.\n");		
    				}
    
    				printf("\nPressione 'Enter' para continuar: ");
    				getchar();
    				scanf("%c", &comecar);
    				printf("----------------------------------------------------------\n");							
    					
    			}
    			else
    			{
    				printf("-----------------------AVISO----------------------\n");
    				printf("Por favor, insira os dados de pelo menos uma venda\n");
    				printf("--------------------------------------------------\n");
    				printf("Pressione 'Enter' para continuar: ");
    				getchar();
    				scanf("%c", &comecar);	
    			}
    		break;
    		case 4:
    			system("clear");
    			printf("Volte sempre!");
    		break;
    		default:
    			printf("Código inválido!\n");
    			printf("Pressione 'Enter' para continuar: ");
 				getchar();
				scanf("%c", &comecar);
    		break;
        }
    } while (codigo_menu != 4);
    return 0;
}