/*Model 1f2p

architektura max szybkich ³¹cz:
5 6 7
1 
2 3 4

zak³adam czas obliczeñ d³u¿szy ni¿ czas przesylu danych
*/

/* Variable definitions */
/* alfy */
var l1, integer >= 0;
var l2, integer >= 0;
var l3, integer >= 0;
var l4, integer >= 0;
var l5, integer >= 0;
var l6, integer >= 0;
var l7, integer >= 0;
var T >=0;


/* Parameters definitions */
/* liczba zadañ */
param v := 1000;


/* czas przetwarzania jednostki danych */
param a1 := 6.09;
param a2 := 6.09*2;
param a3 := 6.4*4;
param a4 := 6.4*8;

param a5 := 6.09*2;
param a6 := 6.4*4;
param a7 := 6.4*8;


/* setup time'y */

/* szybki */
param s1 := 10.4;

/*wolny*/
param s2 := 10.94;


/* przesy³anie*/

/*pionowo*/
param c1 := 4.3;

/*poziomo*/
param c2 := 2.25;


/* Objective function */
minimize obj: +T;


/* Constraints */
R1: T >= l1*a1;
R2: T >= s1+(l2)*c1 + l2*a2;
R3: T >= s1+(l2)*c1 + s1+(l3+l4)*c1 + s1+(l3)*c2 + l3*a3;
R4: T >= s1+(l2)*c1 + s1+(l3+l4)*c1 + s1+(l3)*c2 + s1+(l4)*c2 + s2+(l4)*c2 + l4*a4;
R5: T >= s1+(l5)*c1 + l5*a5;
R6: T >= s1+(l5)*c1 + s1+(l6+l7)*c1 + s1+(l6)*c2 + l6*a6;
R7: T >= s1+(l5)*c1 + s1+(l6+l7)*c1 + s1+(l6)*c2 + s1*(l7)*c2 + s2*(l7)*c2 + l7*a7;
R8: v = l1+l2+l3+l4+l5+l6+l7;