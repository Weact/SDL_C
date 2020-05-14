#include <stdio.h>
#include <stdlib.h>

int n = 10, p = 4;
long q = 2;
float x = 1.75;


int main()
{
    displayTypes();
    displayResult();

    return 0;
}

void displayTypes(){
    printf("INT(a[%d]): %d\nINT(p[%d]): %d\nLONG(q[%d]): %d\nFLOAT(b[%f]): %d\n\n", n, sizeof(int), p, sizeof(int), q, sizeof(long), x, sizeof(float));
}

void displayResult(){

    displayTitle(1); //PARTIE 1
    printf("A) Le resultat de cette expression est un INT: n(int) + q(long) = r(INT) --> %d octets -- r=%d\n", sizeof(n+q), n+q);
    printf("B) Le resultat de cette expression est un FLOAT (resultat convertit en float apres operation): n(int) + x(float) = r(FLOAT) --> %d octets -- r=%f\n", sizeof(n+x), n+x);
    printf("C) Le resultat de cette expression est un INT: [ n(int) %% p(int) ] + q(long) = r(INT) --> %d octets -- r=%d\n", sizeof(n%p+q), n%p+q);
    printf("D) Le resultat de cette expression est un INT(0,1): n(int) < p(int) = r(INT(0,1)) --> %d octets -- r=%d\n", sizeof(n<p), n<p); // n=1/p=2/n<p=1 ; n=2/p=1/n<p=0
    printf("E) Le resultat de cette expression est un INT(0,1): n(int) >= p(int) = r(INT(0,1)) --> %d octets -- r=%d\n", sizeof(n>=p), n>=p); // n=2 ou n=3/p=2/n>=p=1 ; n=1/p=2/n>=p=0
    printf("F) Le resultat de cette expression est un INT(0,1): n(int) > q(long) = r(INT(0,1)) --> %d octets -- r=%d\n", sizeof(n>q), n>q); // n=2/q=1/n>q=1 ; n=2/q=3/n>q=0
    printf("G) Le resultat de cette expression est un INT: q(long) + 3(int) * (n(int) > p(int))(int(0,1)) = r(INT) --> %d octets -- r=%d\n", sizeof(q+3*(n>p)), q+3*(n>p));
    printf("H) Le resultat de cette expression est un INT(0,1): q(long) && n(int) = r(INT(0,1)) --> %d octets -- r=%d\n", sizeof(q&&n), q&&n); // Si q = 1 et n = 1, q&&n = 1 ; Si un des deux = 0, q&&n = 0
    printf("I) Le resultat de cette expression est un INT(0,1): (q(long) - 2(int)) && (n(int) - 10(int)) = r(INT(0,1)) --> %d octets -- r=%d\n", sizeof((q-2)&&(n-10)), (q-2)&&(n-10)); //Si q-2 = 1 et n-10 = 1, alors 1, si l'un des deux = 0, alors 0
    printf("J) Le resultat de cette expression est un FLOAT: x(float) * (q(long) == 2(int))(int(0,1)) = r(FLOAT) --> %d octets -- r=%f\n", sizeof(x*(q==2)), x*(q==2)); // Si q==2, r=x, sinon r=0.000
    printf("K) Le resultat de cette expression est un FLOAT: x(float) * (q(long)=5) = r(FLOAT) --> %d octets -- r=%f\n", sizeof(x*(q=5)), x*(q=5)); // Dans cette expression, on multiplie X par Q, où Q est égal à 5.

    displayTitle(2); //PARTIE 2
    printf("A) L'expression: z = (a>b ? a : b) + (a <= b ? a : b) revient a faire:\n  >  z = a + b.  <  \nLes deux cas possibles etant:\n     i) z = a + b\n     ii) z = b + a.\nOn simplie a l'expression precedente.\n");

    displayTitle(3); //PARTIE 3
    printf("A) Pour n etant de type int, l'expression serait:\n >>> m = (n < 0 ? -1 : n==0 ? 0 : 1); <<< \n");
    testPartie3_Expression();

    displayTitle(4); //PARTIE 4
    printf("Le programme fournit les resultats suivants:\n");
    printf("int n = 10, int p = 5, int q = 10, int r\n");
    printf("A   |   (r = (n == (p = q)))            | n = 10 p = 10 q = 10 r = 1\n"); // Car n = 10, p = 10, donc n = p. R = 1.
    printf("B   |   (n = p = q = 5 ; n += p += q)   | n = 15 p = 10 q = 5\n"); // Etape 1 -> n=5, p=5, q=5. Etape 2 -> n=15, p=10, q=5
    printf("C   |   (q = n < p ? n++ : p++)         | n = 15 p = 11 q = 10\n"); // Dans notre cas où n>p.
    printf("D   |   (q = n > p ? n++ : p++)         | n = 16 p = 11 q = 15\n\n"); // Dans notre cas où n>p.

    printf("1) Le programme fournit les resultats suivants:\n");
    printf("int n = 543, int p = 5, float x = 34.5678\n");
    printf("A   |543 34.5678            |\n");
    printf("B   | 543    34.5678        |%%4d %%10f         |n,x\n");
    printf("C   |543 34.5678            |%%2d %%3f          |n,x\n");
    printf("D   |   34.567 3.456+001    |%%10.3f %%10.3e    |x,x\n");
    printf("E   |  543                  |%%*d              |p,n\n");
    printf("F   |    34.56780           |%%*.*f            |12,5,x\n");
    printf("================================================================================================================================================================================\n");
    printf("CONCLUSION  |   %%Xd     |   X etant un nombre      |   Place le curseur le plus a droite   |   Insere des espaces si vide en allant vers la gauche\n");
    printf("            |   %%Xf     |   X etant un nombre      |                   IDEM                |                           IDEM                       \n");
    printf("            |   %%X.Xf   |   X etant des nombres    |   Le deuxieme X defini X nombre apres la virgule, le premier se comporte comme precedemment.\n");
    printf("            |   %%X.Xe   |   X etant des nombres    |   Notation scientifique, le 2eme X definissant X nombre apres la virgule\n");
    printf("            |   %%*d     |   * etant un int         |   Permet de specifier la valeur. * etant un int passer en premier argument, avant la variable en elle-meme.\n");
    printf("            |   %%*.*f   |   * etant des int        |   Permet de specifier les valeurs. * etant des int passer en premier et deuxieme argument, avant la variable en elle-meme.\n");
    printf("================================================================================================================================================================================\n");

    printf("2) Les valeurs lues dans les variables n(int) et p(int) par l'instruction, sont:\n");
    printf("scanf('%%4d %%2d',&n,&p);\n");
    printf("Le premier %%4d (n, int) va retenir les 4 premiers chiffres entres, puis le %%2d va retenir les 2 prochains.\n");
    printf("C'est a dire que si l'on ecrit 123456789:\n");
    printf("On peut print n(int) ce qui affichera: '1234'. Et print p(int) qui affichera '56'.\n");
    printf("Si l'utilisateur entre 12345 6789, alors n(int) affichera: '1234' et p(int) affichera: '5'.\n");
    printf("Si l'utilisateur entre 1234 56789, n(int) affichera '1234' et p(int) affichera '56'.\n");
    printf("Voici un test, entrez vos nombres ci dessous:\n");
    testPartie4_2();

    printf("\n--> Lorsqu'on lui fournit les donnees suivantes:\n");
    printf("a) >>> 12^45@ = 12(n, int) et 6422476(p,int).\n");
    printf("b) >>> 123456@ = 1234(n,int) et 56(p,int).\n");
    printf("c) >>> 123456^7@ = 1234(n,int) et 56(p,int).\n");
    printf("d) >>> 1^458@ = 1(n,int) et 6422476(p,int).\n");
    printf("e) >>> ^^^4567^^8912@ = 1988807872(n,int) et 6422476(p,int).\n");

    displayTitle(5);
    printf("\n1)\n");
    testPartie5_1_forLoop();
    testPartie5_1_whileLoop();
    testPartie5_1_doWhileLoop();
    printf("\n2)\n");
    testPartie5_2_note();
    printf("\n3)\n");
    testPartie5_3_etoile();
    printf("\n4)\n");

}

void displayTitle(int n){
    printf("\n====================================================== [%d] ======================================================\n\n", n);
}

void testPartie3_Expression(){
    printf("\n=== TEST ===\n");

    int n = 5;
    int m = (n < 0 ? -1 : (n==0 ? 0 : 1));
    printf("N EST POSITIF (N = %d): M = %d\n",n,m);

    n = 0;
    m = (n < 0 ? -1 : (n==0 ? 0 : 1));
    printf("N EST NUL (N = %d): M = %d\n",n,m);

    n = -5;
    m = (n < 0 ? -1 : (n==0 ? 0 : 1));
    printf("N EST NUL (N = %d): M = %d\n",n,m);
    printf("=== FINTEST ===\n");
}

void testPartie4_2(){
    int n, p;
    printf("\n=====================TEST PARTIE 4_2============================\n");
    printf(">>> Vos valeurs: ");
    scanf("%4d %2d",&n,&p);
    printf("\nVotre resultat:\n   >>>%d(n, int)\n   >>>%d(p, int)\n",n,p);
    printf("!!! ATTENTION !!! Apres ces entrees, ou avant la prochaine, nous devons flush (fflush(stdin)).\n");
    printf("Sinon, l'entree precedente va etre retenue a cause du %%4d et %%2d.\n");
    printf("====================FINTEST PARTIE 4_2============================\n\n");
}

void testPartie5_1_forLoop(){
    int i = 0, n = 0, som = 0;
    printf("==== FOR LOOP ====\n");
    for(i; i<4 ; i++)
    {
        fflush(stdin);
        printf("Donnez un entier: [%d] >>> ", i);
        scanf("%d",&n);
        som += n;
    }
    printf("Somme: %d\n",som);
    printf("==== FIN FOR LOOP ====\n\n");
}
void testPartie5_1_whileLoop(){
    int i = 0, n = 0, som = 0;
    printf("==== WHILE LOOP ====\n");
    while(i<4){
        fflush(stdin);
        printf("Donnez un entier: [%d] >>> ", i);
        scanf("%d",&n);
        som+=n;
        i++;
    }
    printf("Somme: %d\n",som);
    printf("====FIN WHILE LOOP ====\n\n");
}
void testPartie5_1_doWhileLoop(){
    int i = 0, n = 0, som = 0;
    printf("==== DO WHILE LOOP ====\n");
    do{
        fflush(stdin);
        printf("Donnez un entier: [%d] >>> ", i);
        scanf("%d",&n);
        som+=n;
        i++;
    }while(i<4);
    printf("Somme: %d\n",som);
    printf("==== FIN DO WHILE LOOP ====\n\n");
}

void testPartie5_2_note(){
    double note = 0.0;
    double total = 0.0;
    double moyenne = 0.0;
    double i = 0.0;

    while(note>=0)
    {
        fflush(stdin);
        printf("Note [%.0lf]: >>> ", i+1);
        scanf("%lf",&note);
        if(note>=0){
            total+=note;
            i++;
        }else{
            printf("\n>>> La note que vous avez saisi vous a permi de quitter l'operation. Elle ne sera donc pas comptabilisee.\n");
        }
    }

    moyenne = total / i;
    printf("Moyenne: >> %.2lf <<\n", moyenne);
}

void testPartie5_3_etoile()
{
    int height, limit = 1;
    printf("Saisissez la valeur pour la HAUTEUR: >>> ");
    scanf("%d", &height);
    for(int i=0 ; i<height ; i++){
        for(int j=0 ; j<limit ; j++){
            printf("*");
        }
        limit++;
        printf("\n");
    }
}
