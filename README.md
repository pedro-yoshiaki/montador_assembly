# ⚙️Montador para a Arquitetura Neander
Este projeto é um montador (assembler) desenvolvido em linguagem C. Ele traduz código escrito em Assembly para a arquitetura didática Neander em seu correspondente código de máquina, gerando um arquivo binário que pode ser executado pelo emulador WNeander.

![image](https://github.com/user-attachments/assets/36ba9e4f-9b29-4252-9e52-da6bd36d8d02)

## 🎯 Objetivo
O objetivo principal é automatizar o processo de programação para o Neander. Em vez de escrever programas diretamente em Linguagem de Máquina, este montador permite que o desenvolvedor escreva em Assembly (em um editor de texto) e realize a tradução para um arquivo de memória (.mem) de forma automática.

## ✨ Funcionalidades Principais
Tradução de Assembly: Converte mnemônicos de Assembly (como LDA, ADD, HLT) para seus respectivos opcodes hexadecimais.
Geração de Arquivo de Memória: Produz um arquivo de saída binário (.mem) compatível com o emulador Neander.
Formatação Automática: Insere o cabeçalho 03 4E 44 52 exigido pelo Neander no início do arquivo binário  e formata cada instrução e operando em sequências de bytes, conforme especificado.
Manipulação de Arquivos: Lê um arquivo de entrada .asm e cria um arquivo de saída .mem.

## 🛠️ Tecnologias Utilizadas
Linguagem: C;
Bibliotecas C Padrão: stdio.h, stdlib.h, string.h;
Compilador: O código foi desenvolvido e testado utilizando o Dev-C++ 5.11.

## 🚀 Como Executar o Projeto
Para compilar e executar o montador, siga os passos abaixo:

### 1. Prepare o ambiente:
Certifique-se de ter um compilador C instalado (como GCC ou o MingW, que acompanha o Dev-C++).
Tenha o emulador WNeander.exe no mesmo diretório do projeto para que ele possa ser aberto automaticamente.

### 2. Crie um arquivo de código Assembly:
Crie um arquivo de texto com a extensão .asm (por exemplo, prog1.asm).
Escreva as instruções do Neander, uma por linha. Exemplo:

LDA 80
ADD 81
STA 82
HLT

### 3. Compile o montador:
Abra um terminal ou prompt de comando e execute o seguinte comando para compilar o main.c:
gcc main.c -o montador.exe

### 4. Execute o montador:
Execute o programa compilado:
./montador.exe
O programa solicitará o nome do arquivo de entrada. Digite o nome do seu arquivo Assembly (ex: prog1.asm) e pressione Enter.

### 5. Verifique a saída:
O programa criará um arquivo chamado Traduzido.mem.
Ele também tentará iniciar o emulador WNeander automaticamente, onde você poderá carregar o arquivo .mem gerado e testar seu programa.

## 🧠 Conclusões e Aprendizados
Desenvolver este montador proporcionou uma compreensão prática e aprofundada sobre os processos de compilação e a relação entre software e hardware. Os principais aprendizados foram:

Arquitetura de Computadores: Entendimento de como instruções de baixo nível são estruturadas, codificadas em opcodes e processadas por uma UCP (Unidade Central de Processamento).
Manipulação de Arquivos em C: Prática com leitura (fopen, fgets) e escrita de arquivos em modo binário (fputc), um conhecimento essencial para qualquer aplicação que lida com dados.
Conversão de Tipos de Dados: Implementação de funções para converter dados entre diferentes formatos, como a transformação de uma string hexadecimal em um valor unsigned char para a gravação no arquivo binário.
Este projeto foi um excelente exercício para solidificar conceitos fundamentais da ciência da computação de uma maneira prática e aplicada.
