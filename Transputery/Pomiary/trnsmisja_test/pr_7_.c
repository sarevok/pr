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
	Channel*  KANAL2WY;
	Channel*  KANAL3WE;
	int*      procNr;
	int i,j,tab[5000];
	KANAL0WY   = (Channel *)  get_param (1);
	KANAL1WE   = (Channel *)  get_param (2);
	KANAL2WY   = (Channel *)  get_param (3);
	KANAL3WE   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			ChanOut(KANAL0WY, tab,1);
			ChanIn(KANAL1WE, tab, i*4);
			ChanOut(KANAL0WY, tab, i*4);
		}
	return 0;
}
