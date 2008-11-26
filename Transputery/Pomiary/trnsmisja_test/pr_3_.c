/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  KANAL4WY;
	Channel*  KANAL5WE;
	Channel*  KANAL6WY;
	Channel*  KANAL7WE;
	int*      procNr;
	int i,j,tab[5000];
	KANAL4WY   = (Channel *)  get_param (1);
	KANAL5WE   = (Channel *)  get_param (2);
	KANAL6WY   = (Channel *)  get_param (3);
	KANAL7WE   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			ChanOut(KANAL6WY, tab,1);
			ChanIn(KANAL7WE, tab, i*4);
			ChanOut(KANAL6WY, tab, i*4);
		}
	return 0;
}
