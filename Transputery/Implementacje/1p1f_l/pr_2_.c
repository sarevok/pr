/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  KANAL2WY;
	Channel*  KANAL3WE;
	Channel*  KANAL6WY;
	Channel*  KANAL7WE;
	int*      procNr;
	Channel*  KANAL1WE;
	Channel*  KANAL0WY;
	int x[10000];
	int i;
	int alfa[12];
	int beta[12];
	int time[13][4];
	int ts, t0, t1, t2;
	
	procNr     = (int *)      get_param (1);
	KANAL0WY   = (Channel *)  get_param (2);
	KANAL1WE   = (Channel *)  get_param (3);
	KANAL2WY   = (Channel *)  get_param (4);
	KANAL3WE   = (Channel *)  get_param (5);	
	KANAL6WY   = (Channel *)  get_param (6);
	KANAL7WE   = (Channel *)  get_param (7);
	
	/*przygotowanie do przetwarzania*/
	for(i=0;i<5000;i++){
		x[i]=0;
	}
	ChanIn(KANAL7WE, alfa, sizeof(int)*12);
	ChanOutInt(KANAL0WY, alfa[*procNr]);
	
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
	ChanOut(KANAL2WY, alfa, sizeof(int)*12);
	/*synchronizacja*/
	
	ChanInInt(KANAL3WE);
	ts=ProcTime();
	ChanOutInt(KANAL6WY, 0);

	/*Odbieranie danych do obliczen*/
	ChanIn(KANAL7WE, x, beta[*procNr]*sizeof(int));
	ChanOutInt(KANAL0WY, (int)x);	
	t0=ProcTime();	

	/*przekazywanie danych*/
	ChanOut(KANAL2WY, x+alfa[*procNr], (beta[*procNr]-alfa[*procNr])*sizeof(int));
	t1=ProcTime();
	/*synchronizacja po zakoñczeniu obliczeñ*/
	ChanInInt(KANAL1WE);
	t2=ProcTime();
	ChanIn(KANAL3WE, time, sizeof(int)*13*4);
	time[*procNr][0]=t0;
	time[*procNr][1]=t1;
	time[*procNr][2]=t2;
	time[*procNr][3]=ts;	
	ChanOut(KANAL6WY, time, sizeof(int)*13*4);
	return 0;
}
