/*
 * start.c
 *
 *  Created on: 23 апр. 2020 г.
 *      Author: Joerdan Newue
 */

#include <stdio.h>                                      //vkluchenie bibliotek
#include <malloc.h>                                    //vkluchenie bibliotek
#include <stdlib.h>                                   //vkluchenie bibliotek
int main(void) {                                     //nachalo programmi
    char viebor,z;                                        // ponadobitsia dlya povtornieh raschetov
    do{                                        //tcikl DO WHILE
        float a,b,c,*A,*B,*C;                               // peremenniee i yacheyka otveta
        float d=1;
        int tip,i,n;                                       // i -schetchik dlya stepeni i fact;  n razmer vectora   ukazatel' na masssiv
        printf ("Nachalo rabotie programmie. calc mozhet: +, -, *, /, ^, !   \n");
        printf ("viebor standartnogo calc- '1' , vectornogo- '2'\n");
        printf ("vvedite tip calculyatora\n");
        scanf ("%d", &tip);
        if (tip==1)
        {printf ("vash viebor eto: standart\n");
            printf ("a=");                                                   // chtenie i zapic'
            scanf ("%f", &a);                                              //peremennieh
            printf ("b=");                                                 //  v stroki;
            scanf ("%f", &b);                                            //schitivanie a, b, z.
            printf ("vieberite deyystviye");                                               //smotri etot block
            scanf (" %c", &z);
            switch (z) {              // block zapici deystviy nizhe perebranie vse vozmozhniee dly moego calculyztora
                case '+':                    //0 means "+"
                    c=a+b;
                    break;
                case '-':                    //0 means "-"
                    c=a-b;
                    break;
                case '*':                    //0 means "*"
                    c=a*b;
                    break;
                case '/':                    //0 means "/"
                    if (b==0) puts("b=0 nedopustimaya operatcia"); else c=a/b;
                    break;
                case '^':                    //0 means "^"
                    c=1;
                    for (i=0; i < b; i++){        //stepen'
                        c=a*c;}
                    break;
                case '!':                    //0 means "!"
                    c=a;
                    for (i=0; i < a; i++){        //fact
                        a=a-1;c=c*a;}
                    break;
                default:
                    printf ("Vvedite poriadkoviy nomer deystvia!\n");}        // esli ne vveden nomer znaka deystvia  a kakiye-to drugie simvolie
        }
        else if (tip==2)
        {printf ("vash viebor eto: vector\n");
            {
                printf("razmer vectorov: ");
                scanf("%d", &n);                                                    // viedelenie pamyaty
                A =malloc(n*sizeof(int));
                B =malloc(n*sizeof(int));
                printf("vvedite 1-st vector");
                for (i=0; i<n; i++) scanf("%f", &A[i]);
                printf("vvedite 2-nd vector");
                for (i=0; i<n; i++) scanf("%f", &B[i]);
                printf ("vieberite deyystviye");
                scanf (" %c", &z);
                switch (z) {
                    case '+':
                        printf("slozheniye vectorov\n");
                        for (i=0; i<n; i++){ printf("%f\n",A[i]+B[i]);}
                        break;
                    case '-':
                        printf("viechetaniye vectorov\n");
                        for (i=0; i<n; i++){ printf("%f\n",A[i]-B[i]);}
                        break;
                    case '*':
                        printf("skalyarnoye proisvedenie\n");
                        for (i=0; i<n; i++) d=A[i]*B[i]+d;
                        printf("%f\n", d);
                        break;
                default:
                    printf ("Vvedite poriadkoviy nomer deystvia!\n");} }}       // esli ne vveden nomer znaka deystvia  a kakiye-to drugie simvolie
                    free(A); free(B);
            if (tip==1)
                printf ("Calculator standartnij poschital. otvet: %f", c);                                  // vidacha otveta
            else
                printf("vectornieye raschetie viepolnenie");
            fflush(stdin);            //reshenie vipolnit' programmu zanovo
            printf("\n Zhelaete vipolnit' raschetie snova? ('y'-esli hochesh' povtorit')\n");
            viebor=getchar();
        }while(viebor=='y'||viebor=='Y');
        if(viebor !='y'||viebor !='Y')
            scanf ("%c", &viebor);
        printf("Programma zavershena\n");                           //konetc
    }