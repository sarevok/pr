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
	Channel*  KANAL4WY;
	Channel*  KANAL5WE;
	Channel*  KANAL6WY;
	Channel*  KANAL7WE;
	int*      procNr;
	int i,j,t1,t2,tab[5000];
	KANAL2WY   = (Channel *)  get_param (1);
	KANAL3WE   = (Channel *)  get_param (2);
	KANAL4WY   = (Channel *)  get_param (3);
	KANAL5WE   = (Channel *)  get_param (4);
	KANAL6WY   = (Channel *)  get_param (5);
	KANAL7WE   = (Channel *)  get_param (6);
	procNr     = (int *)      get_param (7);
	for(i=0;i<5000;i++)
		tab[i]=i+1;
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			ChanIn(KANAL3WE, tab,1);
			t1=ProcTime();
			ChanOut(KANAL2WY, tab, i*4);
			ChanIn(KANAL3WE, tab, i*4);
			t2=ProcTime();
			ChanOutInt(KANAL6WY, (t2-t1)/2);
		}
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			ChanIn(KANAL5WE, tab,1);
			t1=ProcTime();
			ChanOut(KANAL4WY, tab, i*4);
			ChanIn(KANAL5WE, tab, i*4);
			t2=ProcTime();
			ChanOutInt(KANAL6WY, (t2-t1)/2);
		}
	return 0;
}
