/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <stdio.h>
#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  KANAL2WY;
	Channel*  KANAL3WE;
	int time,i,j;
	KANAL2WY   = (Channel *)  get_param (3);
	KANAL3WE   = (Channel *)  get_param (4);
	printf("Start\n");
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			time=ChanInInt(KANAL3WE);
			printf("Wolny-poziomy\t%d\t%d\n", i, time);
		}
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			time=ChanInInt(KANAL3WE);
			printf("Wolny-pionowy\t%d\t%d\n", i, time);
		}
	for(i=10;i<=100;i+=10)
		for(j=0;j<5;j++){
			time=ChanInInt(KANAL3WE);
			printf("Szybki-pionowy\t%d\t%d\n", i, time);
		}
	exit_terminate (0);
	return 0;
}
