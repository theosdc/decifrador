/******************************************************************************/
/* Theo Soares de Camargo - 206191 - LAB.6                                    */
/* EA876 - 1S2020 - 12 08 2020                                                */
/******************************************************************************/
#include <stdio.h>

/*============================================================================*/
/*= Definicoes                                                               =*/
/*============================================================================*/
#define TAM_BUFFER 60

/*============================================================================*/
/*= Variaveis globais                                                        =*/
/*============================================================================*/
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char senha[] = "SENHASECRETA";

/*============================================================================*/
/*= Funcoes                                                                  =*/
/*============================================================================*/
char mod(char a, char b) {
    /* Faz a operacao: 'a mod b' com sinal */

    if (a >= 0) {
	return(a%b);
    } else {			/* a mod b para a<0 */
	a = -a; 		/* |a| mod b */
	a%b;
	return(b-a);
    }
}
char decifrador(char c0, char k0) {
    /* Decifrador */
    /* M = (c - k) mod 26 */
    char c, k;
    if ( c0 >= 'A' && c0 <= 'Z') {
	c = c0 - 'A';		
	k = k0 - 'A';
	return(mod(c-k,26)+'A');
    } else {
	return(c0);
    }
}
/******************************************************************************/
/* Programa Principal                                                         */
/******************************************************************************/
int main() {
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  int i = 0;
  int j = 0;

  /* Passa os elementos para o decifrador */
  while( (i<TAM_BUFFER) && (buffer_entrada[i] !='\0') &&
	 (buffer_entrada[i] != '\n')) {

      buffer_saida[i] = decifrador(buffer_entrada[i], senha[j]);
      j++;
      i++;
      if(senha[j]=='\0') j=0;	/* Repeticao da senha */
  }
  buffer_saida[i]='\0';
  
  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
