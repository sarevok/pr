/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  KANAL1WE;
	Channel*  KANAL0WY;
	Channel*  KANAL6WE;
	Channel*  KANAL5WY;
	int* procNr;
	int x[10000];
	int alfa[12];
	int gamma[13][6];
	int i;
	int time[13][6];
	int t0,t1,t2,t3,t4,t5;
	procNr     = (int *)      get_param (1);
	KANAL0WY   = (Channel *)  get_param (2);
	KANAL1WE   = (Channel *)  get_param (3);
	KANAL5WY   = (Channel *)  get_param (4);
	KANAL6WE   = (Channel *)  get_param (5);

	/*przygotowanie do przetwarzania*/
	for(i=0;i<10000;i++){
		x[i]=25;
	}
	ChanIn(KANAL1WE, alfa, sizeof(int)*12);
	/*alfa[1]=163; 
	alfa[2]=57;
	alfa[3]=26;
	alfa[4]=502;
	alfa[7]=161;
	alfa[10]=62;
	alfa[11]=29;*/
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
	ChanOut(KANAL5WY, alfa, sizeof(int)*12);
	ChanInInt(KANAL6WE);
	t0=ProcTime();
	ChanOut(KANAL5WY, &x[alfa[4]+gamma[4][0]+gamma[4][1]], gamma[12][0]*sizeof(int));
	t3=ProcTime();
	ChanOut(KANAL5WY, &x[alfa[4]+gamma[4][0]+gamma[4][1]+gamma[12][0]], gamma[12][1]*sizeof(int));
	t4=ProcTime();
	ChanInInt(KANAL1WE);
	ChanIn(KANAL6WE, time, sizeof(int)*13*6);
	time[12][0]=t0;
 	time[12][1]=t0;
	time[12][2]=t0;
	time[12][3]=t3;
	time[12][4]=t4;
	time[12][5]=t4;

	ChanOut(KANAL0WY, time, sizeof(int)*13*6);
	return 0;
}
