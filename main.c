/*==============================================================*/
                /*Título: Exemplo de Montador Assembly*/
                /*Data: 20/08/2024*/
/*==============================================================*/

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*Variáveis Globais*/
FILE  *  Arq;
FILE  *  Trad;
char     nome_arquivo[50+1]; /*Variável Char com Null terminator para indicar final da string*/
char line [50+1]; /*Buffer para armazenar cada linha lida*/
char save[10]; /* Buffer para o processamento da tradução, armazenando os endereços das instruções*/

/*Corpo do programa*/
int main()
{
	/*Capturar o nome do arquivo a ser traduzido*/
	printf ("\nDigite o nome do arquivo: "); scanf ("%s", nome_arquivo); fflush (stdin);
	printf ("\nEste foi o nome do arquivo digitado: %s\n", nome_arquivo); /*Linha para confirmar se capturou o nome correto*/
	
	/*A variável Arq vai apontar para abrir o Arquivo capturado e Read(ler)*/
	Arq = fopen (nome_arquivo , "r" );
	
	/*Condição se o arquivo não existir*/
	if ( Arq == NULL ) /* NULL = 0X000000000*/
	{
		printf ("\nIMPOSSIVEL ABRIR O ARQUIVO!");
		getch();
		exit (0); /*Fecha o programa*/
	}
	
    /*Gerar o arquivo convertido*/
	Trad = fopen ( "Traduzido.mem", "w" );
	if ( Trad == NULL )
	{
		printf ("\nIMPOSSIVEL CRIAR O ARQUIVO Traduzido.mem");
		getch();
		exit (0);
	}
	
	fprintf(Trad, "03 4E 44 52\n");
	
	/* LÊ o arquivo .ASM e transfere para o .mem */	
	while (fgets(line, sizeof(line), Arq) != NULL) /*Enquanto fgets ler uma linha do arquivo Arq e a armazenar no buffer line for diferente de NULL*/
	/*sizeof garante que a linha será lida até o tamanho da variável line (50+1)*/
	{
		printf ("%s", line); /*Mostra na tela do programa as strings por linha pegos em line*/
		if (strncmp(line, "NOP", 3) == 0) {
	            fprintf(Trad, "00 00 00 00\n");  /* NOP: 00 00 00 00 */
	        }
	        else if (strncmp(line, "STA", 3) == 0) {
	            sscanf(line, "STA %s", save);
	            fprintf(Trad, "10 00 %s 00\n", save);  /* STA: 10 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "LDA", 3) == 0) {
	            sscanf(line, "LDA %s", save);
	            fprintf(Trad, "20 00 %s 00\n", save);  /* LDA: 20 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "ADD", 3) == 0) {
	            sscanf(line, "ADD %s", save);
	            fprintf(Trad, "30 00 %s 00\n", save);  /* ADD: 30 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "OR", 2) == 0) {
	            sscanf(line, "OR %s", save);
	            fprintf(Trad, "40 00 %s 00\n", save);  /* OR: 40 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "AND", 3) == 0) {
	            sscanf(line, "AND %s", save);
	            fprintf(Trad, "50 00 %s 00\n", save);  /* AND: 50 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "NOT", 3) == 0) {
	            fprintf(Trad, "60 00 00 00\n");  /* NOT: 60 00 00 00 */
	        }
	        else if (strncmp(line, "JMP", 3) == 0) {
	            sscanf(line, "JMP %s", save);
	            fprintf(Trad, "80 00 %s 00\n", save);  /* JMP: 80 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "JN", 2) == 0) {
	            sscanf(line, "JN %s", save);
	            fprintf(Trad, "90 00 %s 00\n", save);  /* JN: 90 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "JZ", 2) == 0) {
	            sscanf(line, "JZ %s", save);
	            fprintf(Trad, "A0 00 %s 00\n", save);  /* JZ: A0 00 <endereço> 00 */
	        }
	        else if (strncmp(line, "HLT", 3) == 0) {
	            fprintf(Trad, "F0 00\n");  /* HLT: F0 00 00 00 */
	        }
	        else {
	            printf("Instrução não reconhecida: %s\n", line);
	        }
	   	  
	}
		
	fclose (Arq);
	fclose (Trad);
	
	system ("Notepad Traduzido.mem");
    return 0;
}
