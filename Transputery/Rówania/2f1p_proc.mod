/*
Model 2f1p

architektura max szybkich proców:
5 6 7
1
2
3 4

Wasik method :P
*/


/* Variable definitions */
/* alfy */
var l1, integer >= 0;
var l21, integer >= 0;
var l22, integer >= 0;
var l31, integer >= 0;
var l32, integer >= 0;
var l41, integer >= 0;
var l42, integer >= 0;

var l51, integer >= 0;
var l52, integer >= 0;
var l61, integer >= 0;
var l62, integer >= 0;
var l71, integer >= 0;
var l72, integer >= 0;

var T >=0;

/*obliczenia begin*/
var ob1 >= 0;
var ob21 >= 0;
var ob22 >= 0;
var ob31 >= 0;
var ob32 >= 0;
var ob41 >= 0;
var ob42 >= 0;
var ob51 >= 0;
var ob52 >= 0;
var ob61 >= 0;
var ob62 >= 0;
var ob71 >= 0;
var ob72 >= 0;

/*obliczenia end*/
var oe1 >= 0;
var oe21 >= 0;
var oe22 >= 0;
var oe31 >= 0;
var oe32 >= 0;
var oe41 >= 0;
var oe42 >= 0;
var oe51 >= 0;
var oe52 >= 0;
var oe61 >= 0;
var oe62 >= 0;
var oe71 >= 0;
var oe72 >= 0;

/*komunikacja begin*/
var kb11g >= 0;
var kb12g >= 0;
var kb11d >= 0;
var kb12d >= 0;
var kb21 >= 0;
var kb22 >= 0;
var kb31 >= 0;
var kb32 >= 0;
var kb41 >= 0;
var kb42 >= 0;
var kb51 >= 0;
var kb52 >= 0;
var kb61 >= 0;
var kb62 >= 0;

/*komunikacja end*/
var ke11g >= 0;
var ke12g >= 0;
var ke11d >= 0;
var ke12d >= 0;
var ke21 >= 0;
var ke22 >= 0;
var ke31 >= 0;
var ke32 >= 0;
var ke41 >= 0;
var ke42 >= 0;
var ke51 >= 0;
var ke52 >= 0;
var ke61 >= 0;
var ke62 >= 0;


/* Parameters definitions */
/* liczba zadañ */
param v := 1000;


/* czas przetwarzania jednostki danych */
param a1 := 6.09;
param a2 := 6.09*2;
param a3 := 6.09*4;
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
minimize obj: T;


/* Constraints */

r1: T >= oe1;
r2: T >= oe22;
r3: T >= oe32;
r4: T >= oe42;
r5: T >= oe52;
r6: T >= oe62;
r7: T >= oe72; 


r8: kb21 >= ke11d;
r9: kb22 >= ke12d;
r10: kb31 >= ke21;
r11: kb32 >= ke22;
r12: kb41 >= ke31;
r13: kb42 >= ke32;
r14: kb51 >= ke11g;
r15: kb52 >= ke12g;
r16: kb61 >= ke51;
r17: kb62 >= ke52;


r18: v = l1 + l21 + l22 + l31 + l32 + l41 + l42 + l51 + l52 + l61 + l62 + l71 + l72;

r19: ke11g = kb11g + s1+(l51+l61+l71)*c1;
r20: ke12g = kb12g + s1+(l52+l62+l72)*c1;
r21: ke11d = kb11d + s1+(l21+l31+l41)*c1;
r22: ke12d = kb12d + s1+(l22+l32+l42)*c1;
r23: ke21 = kb21 + s1+(l31+l41)*c1;
r24: ke22 = kb22 + s1+(l32+l42)*c1;
r25: ke31 = kb31 + s1+(l41)*c2;
r26: ke32 = kb32 + s1+(l42)*c2;
r27: ke51 = kb51 + s1+(l61+l71)*c2;
r28: ke52 = kb52 + s1+(l62+l72)*c2;
r29: ke61 = kb61 + s2+(l71)*c2;
r30: ke62 = kb62 + s2+(l72)*c2;

r31: kb12g >= ke11g;
r32: kb12d >= ke11d;
r33: kb22 >= ke21;
r34: kb32 >= ke31;
r35: kb42 >= ke41;
r36: kb52 >= ke51;
r37: kb62 >= ke61;

r38: ob22 >= oe21;
r39: ob32 >= oe31;
r40: ob42 >= oe41;
r41: ob52 >= oe51;
r42: ob62 >= oe61;
r43: ob72 >= oe71;



r44: ob21 >= ke11d;
r45: ob22 >= ke12d;
r46: ob31 >= ke21;
r47: ob32 >= ke22;
r48: ob41 >= ke31;
r49: ob42 >= ke32;
r50: ob51 >= ke11g;
r51: ob52 >= ke12g;
r52: ob61 >= ke51;
r53: ob62 >= ke52;
r54: ob71 >= ke61;
r55: ob72 >= ke62;

r56: oe1 = ob1 + a1*l1;
r57: oe21 = ob21 + a2*l21;
r58: oe22 = ob22 + a2*l22;
r59: oe31 = ob31 + a3*l31;
r60: oe32 = ob32 + a3*l32;
r61: oe41 = ob41 + a4*l41;
r62: oe42 = ob42 + a4*l42;
r63: oe51 = ob51 + a5*l51;
r64: oe52 = ob52 + a5*l52;
r65: oe61 = ob61 + a6*l61;
r66: oe62 = ob62 + a6*l62;
r67: oe71 = ob71 + a7*l71;
r68: oe72 = ob72 + a7*l72;