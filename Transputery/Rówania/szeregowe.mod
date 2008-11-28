/*
Model szeregowy

architektura max szybkich proców:
1 5 6
2 - 7
3
4

Brak setup time i predkosci przesylu dla przesylu z 1 do 5 !!!
Przesy³anie najpierw do 5,6,7 a potem do 2,3,4

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
param a2 := a1*2;
param a3 := a2*2;
param a4 := a3*2;

param a5 := 6.4*2;
param a6 := a5*2;
param a7 := a6*2;


/* setup time'y */
/* szybki pionowy*/
param s1 := 10.4;

param c1 := 4.3;


/* wolny poziomy*/
param s2 := 10.98;

param c2 := 2.25;


/* wolny pionowy*/
param s3 := 10.91;

param c3 := 4.33;



/*brak dla szybki - wolny poziomy!!!!!!!!! czasowo zastapiony wolny poziomy*/

/* Objective function */
minimize obj: +T;


/* Constraints */
R1: T >= s2+(l5+l6+l7)*c2 + s1+(l2+l3+l4)*c1 + l1*a1;
R2: T >= s2+(l5+l6+l7)*c2 + s1+(l2+l3+l4)*c1 + s1+(l3+l4)*c1 + l2*a2;
R3: T >= s2+(l5+l6+l7)*c2 + s1+(l2+l3+l4)*c1 + s1+(l3+l4)*c1 + s1+(l4)*c1 + l3*a3;
R4: T >= s2+(l5+l6+l7)*c2 + s1+(l2+l3+l4)*c1 + s1+(l3+l4)*c1 + s1+(l4)*c1 + l4*a4;
R5: T >= s2+(l5+l6+l7)*c2 + s2+(l6+l7)*c2 + l5*a5;
R6: T >= s2+(l5+l6+l7)*c2 + s2+(l6+l7)*c2 + s3+(l7)*c3 + l6*a6;
R7: T >= s2+(l5+l6+l7)*c2 + s2+(l6+l7)*c2 + s3+(l7)*c3 + l7*a7;
R8: v = l1+l2+l3+l4+l5+l6+l7;