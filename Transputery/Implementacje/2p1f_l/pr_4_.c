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
	int gamma[13][2];
	int i;
	int t0,t1,t2, t3, t4, t5;
	int time[13][6];
	
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
	alfa[1]=1588;/*5*/ 
	alfa[2]=598;/*6*/
	alfa[3]=159;/*7*/
	alfa[4]=4214;/*1*/
	alfa[7]=1588;/*2*/
	alfa[10]=584;/*3*/
	alfa[11]=269;/*4*/
	/*ile przesy³aæ do nastêpnego w pierwszej i drugiej paczce*/
	gamma[1][0]=alfa[2];
	gamma[2][0]=alfa[3];
	gamma[3][0]=0;
	gamma[4][0]=alfa[1];
	gamma[7][0]=alfa[10];
	gamma[10][0]=alfa[11];
	gamma[11][0]=0;
	gamma[12][0]=alfa[7];
	gamma[1][1]=alfa[3];
	gamma[2][1]=0;
	gamma[3][1]=0;
	gamma[4][1]=alfa[2]+alfa[3];
	gamma[7][1]=alfa[11];
	gamma[10][1]=0;
	gamma[11][1]=0;
	gamma[12][1]=alfa[10]+alfa[11];
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
	ChanOut(KANAL0WY, &x[alfa[4]], gamma[4][0]*sizeof(int));
	t3=ProcTime();
	ChanOut(KANAL0WY, &x[alfa[4]+gamma[4][0]], gamma[4][1]*sizeof(int));
	t4=ProcTime();
	/*synchronizacja po zakonczeniu obliczen*/
	ChanInInt(KANAL3WE);
	t5=ProcTime();
	/*komunikat do drugiego proc. komunikacyjnego, ¿e zakoñczono obliczenia i mo¿na dzia³aæ dalej*/
	ChanOutInt(KANAL4WY, 0);
	/*Zbieranie danych*/
	ChanIn(KANAL5WE, time, sizeof(int)*13*6);
	time[4][0]=t0;
	time[4][1]=t0;
	time[4][2]=t0;
	time[4][3]=t3;
	time[4][4]=t4;
	time[4][5]=t5;
	ChanOut(KANAL0WY, &time[4][0], sizeof(int)*9*6);
	return 0;
}
