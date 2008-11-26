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
	Channel*  KANAL6WY;
	Channel*  KANAL7WE;
	int*      procNr;

	KANAL0WY   = (Channel *)  get_param (1);
	KANAL1WE   = (Channel *)  get_param (2);
	KANAL6WY   = (Channel *)  get_param (3);
	KANAL7WE   = (Channel *)  get_param (4);
	procNr     = (int *)      get_param (5);

	return 0;
}
