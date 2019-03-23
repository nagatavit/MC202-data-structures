#ifndef DATA_H
#define DATA_H

typedef struct data
{
	int dia;
	int mes;
	int ano;
} Data;

/*
 * Cria uma nova data a partir de dia, mês e ano.
 */
Data criaData(int dia, int mes, int ano);

/*
 * Lê uma data do teclado no formato
 *   DD/MM/AA
 * Devolve um novo registro correspondente.
 */
Data leData();

/*
 * Compara duas datas.
 * Retorna um número inteiro que é:
 *    < 0 se data1 for anterior a data2
 *    = 0 se as datas forem iguais
 *    > 0 se data1 for posterior a data2
 */
int comparaData(Data data1, Data data2);

#endif
