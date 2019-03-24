#include <stdio.h>
#include "data.h"

#define DATA_ANTERIOR -1
#define DATA_POSTERIOR 1
#define DATA_IGUAL 0

Data criaData(int dia, int mes, int ano){
  Data novaData;

  novaData.dia = dia;
  novaData.mes = mes;
  novaData.ano = ano;

  return (novaData);
}

Data leData(){
  Data dataLida;

  scanf("%d%*c%d%*c%d", &dataLida.dia, &dataLida.mes, &dataLida.ano);

  return (dataLida);
}

int comparaData(Data data1, Data data2){

  // Compara anos
  if (data1.ano < data2.ano){
    return (DATA_ANTERIOR);
  } else if (data1.ano > data2.ano) {
    return (DATA_POSTERIOR);
  } else {

    // Compara meses
    if (data1.mes < data2.mes){
      return (DATA_ANTERIOR);
    } else if (data1.mes > data2.mes){
      return (DATA_POSTERIOR);
    } else {

      // Compara dias
      if (data1.dia < data2.dia){
        return (DATA_ANTERIOR);
      } else if (data1.dia > data2.dia){
        return (DATA_POSTERIOR);
      } else {
        return (DATA_IGUAL);
      }
    }
  }
}
