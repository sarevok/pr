/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	int*      procNr;
	Channel*  KANAL5WE;
	Channel*  KANAL0WY;
	Channel*  KANAL4WY;
	Channel*  KANAL1WE;
	Channel*  KANAL2WY;
	Channel*  KANAL3WE;
	int x[10000];
	int alfa[12];
	int beta[12];
	int i;
	int t0,t1,t2;
	int time[13][4];
	
	procNr     = (int *)      get_param (1);
	KANAL0WY   = (Channel *)  get_param (2);
	KANAL1WE   = (Channel *)  get_param (3);	
	KANAL2WY   = (Channel *)  get_param (4);
	KANAL3WE   = (Channel *)  get_param (5);
	KANAL4WY   = (Channel *)  get_param (6);
	KANAL5WE   = (Channel *)  get_param (7);
	

/*przygotowanie do przetwarzania*/
	for(i=0;i<10000;i++){
		x[i]=25;
	}
	alfa[1]=1419;/*5*/ 
	alfa[2]=611;/*6*/
	alfa[3]=293;/*7*/
	alfa[4]=4354;/*1*/
	alfa[7]=1419;/*2*/
	alfa[10]=611;/*3*/
	alfa[11]=293;/*4*/
	beta[1]=alfa[1]+alfa[2]+alfa[3];
	beta[2]=alfa[2]+alfa[3];
	beta[3]=alfa[3];
	beta[7]=alfa[7]+alfa[10]+alfa[11];
	beta[10]=alfa[10]+alfa[11];
	beta[11]=alfa[11];
	/*informacja o iloœci zadañ*/
	ChanOutInt(KANAL2WY, alfa[*procNr]);
	ChanOut(KANAL0WY, alfa, sizeof(int)*12);
	ChanOut(KANAL4WY, alfa, sizeof(int)*12);
	/*synchronizacja*/
	ChanInInt(KANAL1WE);
	/*zezwolenie na rozpoczecie obliczen*/
	ChanOutInt(KANAL2WY, (int)x);
	/*wysylanie*/
	t0=ProcTime();
	ChanOut(KANAL0WY, x+alfa[4], beta[1]*sizeof(int));
	t1=ProcTime();
	/*synchronizacja po zakonczeniu obliczen*/
	ChanInInt(KANAL3WE);
	t2=ProcTime();
	/*komunikat do drugiego proc. komunikacyjnego, ¿e zakoñczono obliczenia i mo¿na dzia³aæ dalej*/
	ChanOutInt(KANAL4WY, 0);
	/*Zbieranie danych*/
	ChanIn(KANAL5WE, time, sizeof(int)*13*4);
	time[4][0]=t0;
	time[4][1]=t1;
	time[4][2]=t2;
	time[4][3]=t0;
	ChanOut(KANAL0WY, &time[4][0], sizeof(int)*9*4);
	return 0;
}
