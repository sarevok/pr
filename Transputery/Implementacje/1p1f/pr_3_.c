/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
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
	int ts;
	procNr     = (int *)      get_param (1);
	KANAL0WY   = (Channel *)  get_param (2);
	KANAL1WE   = (Channel *)  get_param (3);	
	KANAL6WY   = (Channel *)  get_param (4);
	KANAL7WE   = (Channel *)  get_param (5);
	
	/*przygotowanie do przetwarzania*/
	for(i=0;i<5000;i++){
		x[i]=0;
	}
	ChanIn(KANAL7WE, alfa, sizeof(int)*12);
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
	/*synchronizacja*/
	ChanOutInt(KANAL0WY, alfa[*procNr]);
	ts=ProcTime();
	ChanOutInt(KANAL6WY, 0);

	/*odbieranie danych do obliczen*/
	ChanIn(KANAL7WE,x, beta[*procNr]*sizeof(int));
	ChanOutInt(KANAL0WY, (int)x);
	time[*procNr][0]=ProcTime();
	ChanInInt(KANAL1WE);
	time[*procNr][2]=ProcTime();
	time[*procNr][3]=ts;
	ChanOut(KANAL6WY, time, sizeof(int)*13*4);
	return 0;
}
