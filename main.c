/*==============================================================*/
                /*Tï¿½tulo: Exemplo de Montador Assembly*/
                /*Data: 20/08/2024*/
/*==============================================================*/

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*Variï¿½veis Globais*/
FILE  *  Arq;
FILE  *  Trad;
char     nome_arquivo[50+1]; /*Variï¿½vel Char com Null terminator para indicar final da string*/
char line [50+1]; /*Buffer para armazenar cada linha lida*/
char save[10]; /* Buffer para o processamento da traduï¿½ï¿½o, armazenando os endereï¿½os das instruï¿½ï¿½es*/

/*Protï¿½tipos de funï¿½ï¿½es*/
unsigned char hex_to_byte(const char *hex);

/*Construï¿½ï¿½o das funï¿½ï¿½es*/
unsigned char hex_to_byte(const char *hex) {
    unsigned int value;
    sscanf(hex, "%2x", &value);
    return (unsigned char)value;
}

/*Corpo do programa*/
int main()
{
	/*Capturar o nome do arquivo a ser traduzido*/
	printf ("\nDigite o nome do arquivo: "); scanf ("%s", nome_arquivo); fflush (stdin);
	printf ("\nEste foi o nome do arquivo digitado: %s\n", nome_arquivo); /*Linha para confirmar se capturou o nome correto*/
	
	/*A variï¿½vel Arq vai apontar para abrir o Arquivo capturado e Read(ler)*/
	Arq = fopen (nome_arquivo , "r" );
	
	/*Condiï¿½ï¿½o se o arquivo nï¿½o existir*/
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
	
	fputc(0x03, Trad);
    fputc(0x4E, Trad);
    fputc(0x44, Trad);
    fputc(0x52, Trad);
	
	/* Lï¿½ o arquivo .ASM e transfere para o .mem */	
	while (fgets(line, sizeof(line), Arq) != NULL) /*Enquanto fgets ler uma linha do arquivo Arq e a armazenar no buffer line for diferente de NULL*/
	/*sizeof garante que a linha serï¿½ lida atï¿½ o tamanho da variï¿½vel line (50+1)*/
	{
		printf ("%s", line); /*Mostra na tela do programa as strings por linha pegos em line*/
		if (strncmp(line, "NOP", 3) == 0) {
	            fputc(0x00, Trad); fputc(0x00, Trad); fputc(0x00, Trad); fputc(0x00, Trad);  /* NOP: 00 00 00 00 */
	        }
	    else if (strncmp(line, "STA", 3) == 0) {
            sscanf(line, "STA %s", save);
            fputc(0x10, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* STA: 10 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "LDA", 3) == 0) {
            sscanf(line, "LDA %s", save);
            fputc(0x20, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* LDA: 20 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "ADD", 3) == 0) {
            sscanf(line, "ADD %s", save);
            fputc(0x30, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* ADD: 30 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "OR", 2) == 0) {
            sscanf(line, "OR %s", save);
            fputc(0x40, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* OR: 40 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "AND", 3) == 0) {
            sscanf(line, "AND %s", save);
            fputc(0x50, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* AND: 50 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "NOT", 3) == 0) {
            fputc(0x60, Trad); fputc(0x00, Trad); fputc(0x00, Trad); fputc(0x00, Trad);  /* NOT: 60 00 00 00 */
        }
        else if (strncmp(line, "JMP", 3) == 0) {
            sscanf(line, "JMP %s", save);
            fputc(0x80, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* JMP: 80 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "JN", 2) == 0) {
            sscanf(line, "JN %s", save);
            fputc(0x90, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* JN: 90 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "JZ", 2) == 0) {
            sscanf(line, "JZ %s", save);
            fputc(0xA0, Trad); fputc(0x00, Trad); fputc(hex_to_byte(save), Trad); fputc(0x00, Trad);  /* JZ: A0 00 <endereï¿½o> 00 */
        }
        else if (strncmp(line, "HLT", 3) == 0) {
            fputc(0xF0, Trad); fputc(0x00, Trad); fputc(0x00, Trad); fputc(0x00, Trad);  /* HLT: F0 00 00 00 */
        }
        else {
            printf("Instruï¿½ï¿½o nï¿½o reconhecida: %s\n", line);
        }
	   	  
	}
		
	fclose (Arq);
	fclose (Trad);

    system("start WNeander"); //Caminho do .exe do Neander

    return 0;
}
