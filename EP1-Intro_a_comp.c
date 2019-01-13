#include <stdio.h>
#include <stdlib.h>
/********************************************************************/
/**                                                                                 **/
/**   Lucas Penna Saraiva         N�mero USP 9770566   **/
/**   Exerc�cio-Programa 01                                           **/
/**   Professor: Alair                                                      **/
/**   Turma: 03                                                              **/
/**                                                                                **/
/********************************************************************/

int main()
{   int n100, /* nX s�o as vari�veis que armazenam o n�mero de notas x */
        n50,
        n10,
        n5,
        n1,
        nop, /* nop � a vari�vel que armazena o n�mero de opera��es desejadas pelo usu�rio*/
        op, /* op � a vari�vel que armazena as opera��es saque = 0 e dep�sito = 1 */
        cont, /*cont � a vari�vel que armazena o contador de opera��es dentro do la�o*/
        saq, /*saq � a vari�vel que armazena o valor do saque desejado*/
        dep100, /*depX � a vari�vel que armazena o numero de notas de cada valor que se quer depositar */
        dep50,
        dep10,
        dep5,
        dep1,
        n100saq, /* nXsaq s�o as vari�veis que armazenam o n�mero de notas sacadas */
        n50saq,
        n10saq,
        n5saq,
        n1saq,
        n100i, /* variaveis que armazenam o valor inicial das notas */
        n50i,
        n10i,
        n5i,
        n1i;

    printf("\nDigite a quantidade inicial de notas de 100, 50, 10, 5 e 1 reais: ");
    scanf("%d", &n100);
    scanf("%d", &n50);
    scanf("%d", &n10);
    scanf("%d", &n5);
    scanf("%d", &n1);

    printf("\nBem vindo ao Banco Adelmo! ");
    printf("\n* * * * * * * * * * * * * * * * * * *");
    printf("\nQuantas operacoes deseja realizar?");
    scanf("%d", &nop);

    for (cont=0; cont<nop; cont++) {

            printf("\nQual operacao deseja efetuar? (0=saque, 1=deposito)");
            scanf("\n%d", &op);

            /* inicializadores das vari�veis */

            n100saq = 0;
            n50saq = 0;
            n10saq = 0;
            n5saq = 0;
            n1saq = 0;
            n100i = n100;
            n50i = n50;
            n10i = n10;
            n5i = n5;
            n1i = n1;

        if(op == 0) {

                    printf("\nQuantos reais deseja sacar? ");
                    scanf("%d", &saq);

                    /*Aqui come�a um s�rie de la�os que alterar�o as vari�veis saq, n�mero de notas sacadas e n�mero de notas dispon�veis! */
                    /*Para executar os la�os, existem condi��es iniciais que devem ser obedecidas. Caso as condi��es n�o s�o atendidas,
                    o programa tentar� executar o la�o seguinte e assim sucessivamente. */

                        while((saq>=100)&&(n100>0)){
                            saq = saq - 100;
                            n100--;
                            n100saq++;}

                        while((saq>=50)&&(n50>0)){
                            saq = saq - 50;
                            n50--;
                            n50saq++;}

                        while((saq>=10)&&(n10>0)){
                            saq = saq - 10;
                            n10--;
                            n10saq++;}

                        while((saq>=5)&&(n5>0)){
                            saq = saq - 5;
                            n5--;
                            n5saq++;}

                        while((saq>=1)&&(n1>0)){
                            saq = saq - 1;
                            n1--;
                            n1saq++;}

                     /*Note que ao final dos la�os, se a vari�vel "saq" for igual a zero, significa que houve notas o suficiente para se executar o saque,
                     sendo essa uma condi��o essencial para sinalizar que o saque foi realizado com sucesso */

                            if(saq != 0){
                                n100 = n100i; /*note que aqui as vari�veis que armazenam o n�mero de notas retornam ao seu valor inicial caso a vari�vel saq != 0*/
                                n50 = n50i;
                                n10 = n10i;
                                n5 = n5i;
                                n1 = n1i;
                                printf("Saque nao efetuado!");}

                            else {
                                printf("\nSaque efetuado: %d %d %d %d %d", n100saq, n50saq, n10saq, n5saq, n1saq);
                                printf("\nNotas disponiveis: %d %d %d %d %d", n100, n50, n10, n5, n1);} /*note que aqui as vari�veis que armazenam o n�mero de notas tem seu valor alterado, visto que o saque deu certo)*/
        }

        if(op == 1) {

                    printf("\nDigite a quantidade de notas de 100, 50, 10, 5 e 1 sendo depositadas: ");
                    scanf("\n%d", &dep100);
                    scanf("\n%d", &dep50);
                    scanf("\n%d", &dep10);
                    scanf("\n%d", &dep5);
                    scanf("\n%d", &dep1);

                    n100 = n100 + dep100;
                    n50 = n50 + dep50;
                    n10 = n10 + dep10;
                    n5 = n5 + dep5;
                    n1 = n1 + dep1;

                    printf("\nDeposito efetuado! \nNotas disponiveis: %d %d %d %d %d", n100, n50, n10, n5, n1);}
    }
    printf("O Banco Adelmo agradece a sua visita e deseja reve-lo em breve!");
    return 0;
    }
