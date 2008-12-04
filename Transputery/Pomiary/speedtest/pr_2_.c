/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>


int main()
{
	Channel*  KANAL0WY;
	Channel*  KANAL1WE;
	Channel*  KANAL4WY;
	Channel*  KANAL5WE;
	Channel*  KANAL6WY;
	Channel*  KANAL7WE;
	int*      procNr;
	int i, j,z, time, time2;
	int liczba[10000];
	int x[10000];
	KANAL0WY   = (Channel *)  get_param (1);
	KANAL1WE   = (Channel *)  get_param (2);
	KANAL4WY   = (Channel *)  get_param (3);
	KANAL5WE   = (Channel *)  get_param (4);
	KANAL6WY   = (Channel *)  get_param (5);
	KANAL7WE   = (Channel *)  get_param (6);
	procNr     = (int *)      get_param (7);

	ChanOutInt(KANAL0WY, (int)liczba);
		
	for(i=10;i<100;i+=10)
		for(j=0;j<20;j++){
			ChanInInt(KANAL1WE);
			time=ProcTime();
			ChanInInt(KANAL1WE);
			time2=ProcTime();
			ChanOutInt(KANAL6WY, time2-time);
		}
		
	for(i=200;i<=5000;i+=200)
		for(j=0;j<20;j++){
			ChanInInt(KANAL1WE);
			time=ProcTime();
			ChanInInt(KANAL1WE);
			time2=ProcTime();
			ChanOutInt(KANAL6WY, time2-time);
		}
			
	return 0;
}
