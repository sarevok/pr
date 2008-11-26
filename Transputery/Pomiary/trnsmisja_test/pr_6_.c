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

	KANAL0WY   = (Channel *)  get_param (1);
	KANAL1WE   = (Channel *)  get_param (2);
	KANAL4WY   = (Channel *)  get_param (3);
	KANAL5WE   = (Channel *)  get_param (4);
	KANAL6WY   = (Channel *)  get_param (5);
	KANAL7WE   = (Channel *)  get_param (6);
	procNr     = (int *)      get_param (7);

	return 0;
}
