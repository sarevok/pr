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
	int beta[12];
	int i;
	int time[13][4];
	int t0,t1;
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
	beta[1]=alfa[1]+alfa[2]+alfa[3];
	beta[2]=alfa[2]+alfa[3];
	beta[3]=alfa[3];
	beta[7]=alfa[7]+alfa[10]+alfa[11];
	beta[10]=alfa[10]+alfa[11];
	beta[11]=alfa[11];
	ChanOut(KANAL5WY, alfa, sizeof(int)*12);
	ChanInInt(KANAL6WE);
	t0=ProcTime();
	ChanOut(KANAL5WY, x+alfa[4]+beta[1], beta[7]*sizeof(int));
	t1=ProcTime();
	ChanInInt(KANAL1WE);
	ChanIn(KANAL6WE, time, sizeof(int)*13*4);
	time[12][0]=t0;
 	time[12][1]=t1;
	time[12][3]=t0;
	ChanOut(KANAL0WY, time, sizeof(int)*13*4);
	return 0;
}
