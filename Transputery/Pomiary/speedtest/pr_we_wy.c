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
	int i, j;
	int x;
	KANAL2WY   = (Channel *)  get_param (3);
	KANAL3WE   = (Channel *)  get_param (4);
	for(i=10;i<100;i+=10)
		for(j=0;j<20;j++){
			x=ChanInInt(KANAL3WE);
			printf("Szybszy\t%d\t%d\n", i, x);
		}
	for(i=200;i<=5000;i+=200)
		for(j=0;j<20;j++){
			x=ChanInInt(KANAL3WE);
			printf("Szybszy\t%d\t%d\n", i, x);
		}
	for(i=10;i<100;i+=10)
		for(j=0;j<20;j++){
			x=ChanInInt(KANAL3WE);
			printf("Wolniejszy\t%d\t%d\n", i, x);
		}
	for(i=200;i<=5000;i+=200)
		for(j=0;j<20;j++){
			x=ChanInInt(KANAL3WE);
			printf("Wolniejszy\t%d\t%d\n", i, x);
		}
	exit_terminate (0);
	return 0;
}
