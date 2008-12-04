/* --------------------------------------------------- *
 *   Szkielet pliku zrodlowego wygenrowany przez       *
 *                 TRANSPUTER STUDIO                   *
 * --------------------------------------------------- */

#include <process.h>
#include <channel.h>
#include <misc.h>

int main()
{
	Channel*  KANAL5WY;
	Channel*  KANAL6WE;
	int* x;
	int y[10000];
	int i,j, sp;
	int alfa;
	int* procNr;

	procNr     = (int *)      get_param (1);
	KANAL5WY   = (Channel *)  get_param (2);
	KANAL6WE   = (Channel *)  get_param (3);
	
	for(i=0;i<5000;i++)
		y[i]=0;
	sp=1;
	if(*procNr==18 ||*procNr==15)
		sp=2;
	else if(*procNr==19||*procNr==14)
		sp=4;
	else if(*procNr==20||*procNr==13)
		sp=8;
	alfa=ChanInInt(KANAL6WE);
	x = (int*)ChanInInt(KANAL6WE);
	for(j=0;j<sp;j++){
		for(i=0;i<alfa;i++)
			y[i]=(((4*x[i]+12)*x[i]+3)*x[i]+3)*x[i]+7;
	}
	ChanOutInt(KANAL5WY, 0);

	return 0;
}
