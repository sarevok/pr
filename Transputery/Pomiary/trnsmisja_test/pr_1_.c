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
	int time, i,j;
	KANAL2WY   = (Channel *)  get_param (1);
	KANAL3WE   = (Channel *)  get_param (2);
	KANAL4WY   = (Channel *)  get_param (3);
	KANAL5WE   = (Channel *)  get_param (4);
	KANAL6WY   = (Channel *)  get_param (5);
	KANAL7WE   = (Channel *)  get_param (6);
	procNr     = (int *)      get_param (7);
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			time=ChanInInt(KANAL3WE);
			ChanOutInt(KANAL6WY, time);
		}
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			time=ChanInInt(KANAL3WE);
			ChanOutInt(KANAL6WY, time);
		}
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			time=ChanInInt(KANAL5WE);
			ChanOutInt(KANAL6WY, time);
		}
	return 0;
}
