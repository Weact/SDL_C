# DOCUMENT REPONSE ISSUE DE L'OUPUT CONSOLE

INT(a[10]): 4
INT(p[4]): 4
LONG(q[2]): 4
FLOAT(b[1.750000]): 4

====================================================== [1] ======================================================

A) Le resultat de cette expression est un INT: n(int) + q(long) = r(INT) --> 4 octets -- r=12
B) Le resultat de cette expression est un FLOAT (resultat convertit en float apres operation): n(int) + x(float) = r(FLOAT) --> 4 octets -- r=11.750000
C) Le resultat de cette expression est un INT: [ n(int) % p(int) ] + q(long) = r(INT) --> 4 octets -- r=4
D) Le resultat de cette expression est un INT(0,1): n(int) < p(int) = r(INT(0,1)) --> 4 octets -- r=0
E) Le resultat de cette expression est un INT(0,1): n(int) >= p(int) = r(INT(0,1)) --> 4 octets -- r=1
F) Le resultat de cette expression est un INT(0,1): n(int) > q(long) = r(INT(0,1)) --> 4 octets -- r=1
G) Le resultat de cette expression est un INT: q(long) + 3(int) * (n(int) > p(int))(int(0,1)) = r(INT) --> 4 octets -- r=5
H) Le resultat de cette expression est un INT(0,1): q(long) && n(int) = r(INT(0,1)) --> 4 octets -- r=1
I) Le resultat de cette expression est un INT(0,1): (q(long) - 2(int)) && (n(int) - 10(int)) = r(INT(0,1)) --> 4 octets -- r=0
J) Le resultat de cette expression est un FLOAT: x(float) * (q(long) == 2(int))(int(0,1)) = r(FLOAT) --> 4 octets -- r=1.750000
K) Le resultat de cette expression est un FLOAT: x(float) * (q(long)=5) = r(FLOAT) --> 4 octets -- r=8.750000

====================================================== [2] ======================================================

A) L'expression: z = (a>b ? a : b) + (a <= b ? a : b) revient a faire:
  >  z = a + b.  <
Les deux cas possibles etant:
     i) z = a + b
     ii) z = b + a.
On simplie a l'expression precedente.

====================================================== [3] ======================================================

A) Pour n etant de type int, l'expression serait:
 >>> m = (n < 0 ? -1 : n==0 ? 0 : 1); <<<

=== TEST ===
N EST POSITIF (N = 5): M = 1
N EST NUL (N = 0): M = 0
N EST NUL (N = -5): M = -1
=== FINTEST ===

====================================================== [4] ======================================================

Le programme fournit les resultats suivants:
int n = 10, int p = 5, int q = 10, int r
A   |   (r = (n == (p = q)))            | n = 10 p = 10 q = 10 r = 1
B   |   (n = p = q = 5 ; n += p += q)   | n = 15 p = 10 q = 5
C   |   (q = n < p ? n++ : p++)         | n = 15 p = 11 q = 10
D   |   (q = n > p ? n++ : p++)         | n = 16 p = 11 q = 15

1) Le programme fournit les resultats suivants:
int n = 543, int p = 5, float x = 34.5678
A   |543 34.5678            |
B   | 543    34.5678        |%4d %10f         |n,x
C   |543 34.5678            |%2d %3f          |n,x
D   |   34.567 3.456+001    |%10.3f %10.3e    |x,x
E   |  543                  |%*d              |p,n
F   |    34.56780           |%*.*f            |12,5,x
================================================================================================================================================================================
CONCLUSION  |   %Xd     |   X etant un nombre      |   Place le curseur le plus a droite   |   Insere des espaces si vide en allant vers la gauche
            |   %Xf     |   X etant un nombre      |                   IDEM                |                           IDEM
            |   %X.Xf   |   X etant des nombres    |   Le deuxieme X defini X nombre apres la virgule, le premier se comporte comme precedemment.
            |   %X.Xe   |   X etant des nombres    |   Notation scientifique, le 2eme X definissant X nombre apres la virgule
            |   %*d     |   * etant un int         |   Permet de specifier la valeur. * etant un int passer en premier argument, avant la variable en elle-meme.
            |   %*.*f   |   * etant des int        |   Permet de specifier les valeurs. * etant des int passer en premier et deuxieme argument, avant la variable en elle-meme.
================================================================================================================================================================================
2) Les valeurs lues dans les variables n(int) et p(int) par l'instruction, sont:
scanf('%4d %2d',&n,&p);
Le premier %4d (n, int) va retenir les 4 premiers chiffres entres, puis le %2d va retenir les 2 prochains.
C'est a dire que si l'on ecrit 123456789:
On peut print n(int) ce qui affichera: '1234'. Et print p(int) qui affichera '56'.
Si l'utilisateur entre 12345 6789, alors n(int) affichera: '1234' et p(int) affichera: '5'.
Si l'utilisateur entre 1234 56789, n(int) affichera '1234' et p(int) affichera '56'.
Voici un test, entrez vos nombres ci dessous:

=====================TEST PARTIE 4_2============================
>>> Vos valeurs: 123456789

Votre resultat:
   >>>1234(n, int)
   >>>56(p, int)
!!! ATTENTION !!! Apres ces entrees, ou avant la prochaine, nous devons flush (fflush(stdin)).
Sinon, l'entree precedente va etre retenue a cause du %4d et %2d.
====================FINTEST PARTIE 4_2============================


--> Lorsqu'on lui fournit les donnees suivantes:
a) >>> 12^45@ = 12(n, int) et 6422476(p,int).
b) >>> 123456@ = 1234(n,int) et 56(p,int).
c) >>> 123456^7@ = 1234(n,int) et 56(p,int).
d) >>> 1^458@ = 1(n,int) et 6422476(p,int).
e) >>> ^^^4567^^8912@ = 1988807872(n,int) et 6422476(p,int).

====================================================== [5] ======================================================


1)
==== FOR LOOP ====
Donnez un entier: [0] >>> 1
Donnez un entier: [1] >>> 1
Donnez un entier: [2] >>> 1
Donnez un entier: [3] >>> 1
Somme: 4
==== FIN FOR LOOP ====

==== WHILE LOOP ====
Donnez un entier: [0] >>> 2
Donnez un entier: [1] >>> 2
Donnez un entier: [2] >>> 2
Donnez un entier: [3] >>> 2
Somme: 8
====FIN WHILE LOOP ====

==== DO WHILE LOOP ====
Donnez un entier: [0] >>> 3
Donnez un entier: [1] >>> 3
Donnez un entier: [2] >>> 3
Donnez un entier: [3] >>> 3
Somme: 12
==== FIN DO WHILE LOOP ====


2)
Note [1]: >>> 12
Note [2]: >>> 15.25
Note [3]: >>> 13.5
Note [4]: >>> 8.75
Note [5]: >>> -1

>>> La note que vous avez saisi vous a permi de quitter l'operation. Elle ne sera donc pas comptabilisee.
Moyenne: >> 12.38 <<

3)
Saisissez la valeur pour la HAUTEUR: >>> 10
*
**
***
****
*****
******
*******
********
*********
**********

4)

Process returned 0 (0x0)   execution time : 64.747 s
Press any key to continue.
