#include <stdio.h>

/*fun��o seno usando s�rie de taylor*/

double seno(double x)
{
    int c1, /*contador do la�o principal*/
        c2, /*contador da fatorial*/
        c3, /*contador expoente*/
        c4; /*contador expoente mudan�a sinal*/

    double sp,
            t, /*termo da sequencia*/
            pot, /*armazena a potencia*/
            fat; /*armazena fatorial*/

    /*inicializadores*/

    c1 = 3;
    sp = x;
    c4 = 2;
    t = x;

        while(t>=0.00000001 || t<=-0.00000001){

                /*calcular fatorial*/

                fat = 1.0;
                c2 = 1;
                while (c2 <= c1){
                    fat = c2 * fat;
                    c2++;}

               /*calcular expoente*/

               pot = 1.0;
               c3 = 1;
               while(c3 <= c1){
                    pot = pot * x;
                    c3++;}

               /*tarefas do la�o principal*/

               t = (pot/fat);

               if(c4%2 == 0){
               sp = sp - t;}

               if(c4%2 != 0){
               sp = sp + t; }

               c1 = c1 + 2;
               c4 = c4 + 1;}

    return sp;
}

    /*fun��o m�dulo (absoluto) */

    double fabs(double x){

        if(x>=0)
            x = x;
        else
            x = -x;

    return x;
}
    /*fun��o floor*/

    double floor(double x){

        int i;

        i = 0;

    while(i < x)
        {
            i++;
        }

    i--;
    return i;
}

int main()
{
    int x, /*valor de entrada fornecido pelo usu�rio*/
        c1, /*contador 1*/
        c2, /*contador 2*/
        c3,  /*contador 3*/
        krta, /*carta sorteada*/
        vit, /*armazena numero de vitorias jogador*/
        ncj, /*numero de c1artas jogador*/
        ncb; /*numero de cartas banca*/

    double cxa, /*armazena caixa*/
           teto, /*armazena o teto*/
           ptoj, /*armazena a quantidade de pontos do jogador*/
           ptob, /*armazena a qtd. de pontos da banca*/
           rifa; /*armazena a rifa*/

    scanf("%d", &x);

    /*inicializadores dos la�os da caixa*/
    c1 = 0;

    c2 = 0;

    cxa = x;

    /*os dois seguintes la�os servem p/ transformar o num de entrada (x) para a caixa (cxa)*/

    while(x > 0){

        x = x / 10;

        c1++;}

    while(c2<c1){

        c2++;

        cxa = cxa / 10;
    }

    /*la�o principal da simula��o*/

    for(teto = 0.5; teto<=7.5; teto = teto + 0.5){

        vit = 0;

        /*vez do jogador*/

        ptoj = 0.0;
        ncj = 0;

        while(ptoj<teto)
        {
            rifa = ( 9821.0 * fabs(seno(cxa)) ) + 0.211327;

            cxa = rifa - floor( rifa );

            krta = floor( cxa*10 + 1 );

            if (krta == 8 || krta == 9 || krta == 10)

                ptoj = ptoj + 0.5;

            else

                ptoj = ptoj + krta;

            ncj++; /*numero de cartas do jogador*/
        }

        /*vez da banca*/

        ptob = 0.0;
        ncb = 0;

        while((ptob<teto) && (ptoj<teto)){ /*fazer condicao de que a banca so pega carta se o jogador nao tiver estourado + se a banca ultrapassar
                            o valor do jogador ja ganha + se empatar o valor (mesmo que nao seja 7.5), se a banca tiver feito com
                            cartas ela j� ganha e para de pedir cartas*/

            rifa = ( 9821.0 * fabs(seno(cxa)) ) + 0.211327;

            cxa = rifa - floor( rifa );

            krta = floor( cxa * 10 + 1 );

            if (krta == 8 || krta == 9 || krta == 10)

                ptob = ptob + 0.5;

            else

                ptob = ptob + krta;

        ncb++; /*numero de cartas da banca*/
        }

        /*fim dos la�o dos jogo*/

        /*contador de vit�rias do jogador*/

        if (ptoj<teto){

            if (ptoj>ptob) /*em caso de vit�ria*/

                vit++;

            if(ptoj == ptob)/*em caso de empate*/{

            if(ncj<ncb)

                vit++;}
        }

        printf("\n %g %d", teto, vit);

        /*contador de asteriscos*/

        c3 = 0;

        while(c3<vit){

            c3++;

            printf(" *");
        }

}/*final do for (la�o principal)*/

 return 0;
}



