/*Model szeregowy

architektura max szybkich ³¹cz:
5 6 7
1 
2 3 4

Przesy³anie najpierw do 5,6,7 a potem do 2,3,4*/

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

var t1 >= 0;
var t2 >= 0;
var t3 >= 0;
var t4 >= 0;
var t5 >= 0;
var t6 >= 0;
var t7 >= 0;


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
R1: t1 = s1+(l5+l6+l7)*c1 + s1+(l2+l3+l4)*c1 + l1*a1;
R2: t2 = s1+(l5+l6+l7)*c1 + s1+(l2+l3+l4)*c1 + s1+(l3+l4)*c2 + l2*a2;
R3: t3 = s1+(l5+l6+l7)*c1 + s1+(l2+l3+l4)*c1 + s1+(l3+l4)*c2 + s2+(l4)*c2 + l3*a3;
R4: t4 = s1+(l5+l6+l7)*c1 + s1+(l2+l3+l4)*c1 + s1+(l3+l4)*c2 + s2+(l4)*c2 + l4*a4;
R5: t5 = s1+(l5+l6+l7)*c1 + s1+(l6+l7)*c2 + l5*a5;
R6: t6 = s1+(l5+l6+l7)*c1 + s1+(l6+l7)*c2 + s2+(l7)*c2 + l6*a6;
R7: t7 = s1+(l5+l6+l7)*c1 + s1+(l6+l7)*c2 + s2+(l7)*c2 + l7*a7;
R8: v = l1+l2+l3+l4+l5+l6+l7;
R9: T >= t1;
R10: T >= t2;
R11: T >= t3;
R12: T >= t4;
R13: T >= t5;
R14: T >= t6;
R15: T >= t7;
