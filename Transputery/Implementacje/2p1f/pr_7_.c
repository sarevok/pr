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
	Channel*  KANAL0WY;
	Channel*  KANAL1WE;
	int* procNr;
	int x[10000];
	int i;
	int alfa[12];
	int gamma[13][2];
	int time[13][6];
	int t0,t1,t2,t3,t4,t5;

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
	ChanOutInt(KANAL0WY, alfa[7]);
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
	ChanOut(KANAL2WY, alfa, sizeof(int)*12);
	/*synchronizacja*/
	ChanInInt(KANAL3WE);
	t0=ProcTime();
	ChanOutInt(KANAL6WY, 0);
	/*odbieranie danych do obliczen*/
	ChanIn(KANAL7WE, x, alfa[7]*sizeof(int));
	ChanOutInt(KANAL0WY, (int)x);
	t1=ProcTime();
	/*przekazywanie danych*/
	ChanIn(KANAL7WE, &x[alfa[7]], (gamma[7][0]+gamma[7][1])*sizeof(int));
	t2=ProcTime();
	ChanOut(KANAL2WY, &x[alfa[7]], gamma[7][0]*sizeof(int));
	t3=ProcTime();
	ChanOut(KANAL2WY, &x[alfa[7]+gamma[7][0]], gamma[7][1]*sizeof(int));
	t4=ProcTime();
	/*synchronizacja po zakonczeniu obliczen*/
	ChanInInt(KANAL1WE);
	t5=ProcTime();
	ChanIn(KANAL3WE, time, sizeof(int)*13*6);
	time[*procNr][0]=t0;
	time[*procNr][1]=t1;
	time[*procNr][2]=t2;
	time[*procNr][3]=t3;	
	time[*procNr][4]=t4;	
	time[*procNr][5]=t5;	
	ChanOut(KANAL6WY, time, sizeof(int)*13*6);
	return 0;
}
