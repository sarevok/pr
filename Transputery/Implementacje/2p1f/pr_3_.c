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
	int gamma[13][2];
	int time[13][6];
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
	/*synchronizacja*/
	ChanOutInt(KANAL0WY, alfa[*procNr]);
	time[*procNr][0]=ProcTime();
	ChanOutInt(KANAL6WY, 0);

	/*odbieranie danych do obliczen*/
	ChanIn(KANAL7WE,x, alfa[*procNr]*sizeof(int));
	ChanOutInt(KANAL0WY, (int)x);
	time[*procNr][1]=ProcTime();
	ChanInInt(KANAL1WE);
	time[*procNr][5]=ProcTime();
	time[*procNr][2]=time[*procNr][1];
	time[*procNr][3]=time[*procNr][1];
	time[*procNr][4]=time[*procNr][1];
	ChanOut(KANAL6WY, time, sizeof(int)*13*6);
	return 0;
}
