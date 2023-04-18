#include <stdio.h>

float calcularCelsiusParaFahrenheit(float tempC){
	int result;
	result = (9.0 / 5.0) * tempC + 32.0;	
	return result;	
}

float calcularFahrenheitParaCelsius(float tempF){
	int result;
	result = (tempF - 32) * 5.0 / 9.0;	
	return result;	  
}

float calcularCelsiusParaKelvin(float tempC){
  int result;
  result = tempC + 273.15;
  return result;
}

float calcularKelvinParaCelcius(float tempK){
  int result;
  result= tempK - 273.15;
  return result;

}

float calcularCelsiusParaReaumur(float tempC){
  int result;
  result = tempC * 4/5;
  return result;
}

float calcularReaumurParaCelsius(float tempR){
  int result;
  result = tempR * 5/4;
  return result;
}

float calcularKelvinparaRankine(float tempK){
  int result;
  result =  tempK * 1.8;
  return result;
}

float calcularRankineparaKelvin(float tempR){
  int result;
  result = tempR / 1.8;
  return result;
}



int main() {
   int opcoes;
   float temperatura;

   printf("---- Opcoes de Conversao ---- \n");
   printf("- 1 - Celsius para Fahrenheit\n");
   printf("- 2 - Fahrenheit para Celsius\n");
   printf("- 3 - Celsius para Kelvin\n");
   printf("- 4 - Kelvin para Celsius\n");
   printf("- 5 - Celsius para Reaumur\n");
   printf("- 6 - Reaumur para Celsius\n");
   printf("- 7 - Kelvin para Rankine\n");
   printf("- 8 - Rankine para Kelvin\n");
   scanf("%d", &opcoes); 
   printf("Digite a temperatura que deseja converter: ");
   scanf("%f", &temperatura); 


   switch (opcoes){
		case 1: 
	      	printf("O resultado de sua conversao e de: %f\n", calcularCelsiusParaFahrenheit(temperatura));
      	break;
    case 2: 
	      	printf("O resultado de sua conversao e de: %f\n", calcularFahrenheitParaCelsius(temperatura));
      	break;

    case 3:

          printf("O resultado de sua conversao e de: %f", calcularCelsiusParaKelvin(temperatura));
        break;
      
    case 4: 
          printf("O resultado de sua conversao e de: %f",  calcularKelvinParaCelcius(temperatura));
        break;

    case 5: 
          printf("O resultado de sua conversao e de: %f",  calcularCelsiusParaReaumur(temperatura));
        break;

    case 6: 
          printf("O resultado de sua conversao e de: %f",  calcularReaumurParaCelsius(temperatura));
        break;
    case 7: 
          printf("O resultado de sua conversao e de: %f",  calcularKelvinparaRankine(temperatura));
        break;
     case 8: 
          printf("O resultado de sua conversao e de: %f",  calcularRankineparaKelvin(temperatura));
        break;

          	default: printf("Opcao invalida.\n");

   }

   return 0;
}