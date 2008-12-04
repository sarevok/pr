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
	int*      procNr;
	int i,j,z, time, time2;
	int* liczba;
	int x[10000];
	KANAL2WY   = (Channel *)  get_param (1);
	KANAL3WE   = (Channel *)  get_param (2);
	procNr     = (int *)      get_param (3);
	
	liczba=(int*)ChanInInt(KANAL3WE);
	for(i=0;i<5000;i++)
		liczba[i]=25;
		
	for(i=10;i<100;i+=10)
		for(j=0;j<20;j++){
			for(z=0;z<5000;z++)
				x[z]=0;
			z=0;
			ChanOutInt(KANAL2WY, 0);
			for(;z<i;z+=1)
				x[z]=(((4*liczba[z]+12)*liczba[z]+3)*liczba[z]+3)*liczba[z]+7;
			ChanOutInt(KANAL2WY, 0);
		}
		
	for(i=200;i<=5000;i+=200)
		for(j=0;j<20;j++){
			for(z=0;z<5000;z++)
				x[z]=0;
			z=0;
			ChanOutInt(KANAL2WY, 0);
			for(;z<i;z+=1)
				x[z]=(((4*liczba[z]+12)*liczba[z]+3)*liczba[z]+3)*liczba[z]+7;
			ChanOutInt(KANAL2WY, 0);
		}

	return 0;
}
