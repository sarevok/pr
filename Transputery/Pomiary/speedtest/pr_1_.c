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
	int i,j,z, time, time2;
	int liczba[5000];
	int x[5000];
	KANAL2WY   = (Channel *)  get_param (1);
	KANAL3WE   = (Channel *)  get_param (2);
	KANAL4WY   = (Channel *)  get_param (3);
	KANAL5WE   = (Channel *)  get_param (4);
	KANAL6WY   = (Channel *)  get_param (5);
	KANAL7WE   = (Channel *)  get_param (6);
	procNr     = (int *)      get_param (7);
	
	for(i=0;i<5000;i++)
		liczba[i]=(i%100)+1;
		
	for(i=10;i<100;i+=10)
		for(j=0;j<20;j++){
			for(z=0;z<i;z++)
				x[z]=0;
			time=ProcTime();
			for(z=0;z<i;z+=1)
				x[z]=(((4*liczba[z]+12)*liczba[z]+3)*liczba[z]+3)*liczba[z]+7;
			time2=ProcTime();
			ChanOutInt(KANAL6WY, time2-time);
		}
		
	for(i=200;i<=5000;i+=200)
		for(j=0;j<20;j++){
			for(z=0;z<i;z++)
				x[z]=0;
			time=ProcTime();
			for(z=0;z<i;z+=1)
				x[z]=(((4*liczba[z]+12)*liczba[z]+3)*liczba[z]+3)*liczba[z]+7;
			time2=ProcTime();
			ChanOutInt(KANAL6WY, time2-time);
		}
	for(i=10;i<100;i+=10)
		for(j=0;j<20;j++){
			time=ChanInInt(KANAL3WE);
			ChanOutInt(KANAL6WY, time);
		}
	for(i=200;i<=5000;i+=200)
		for(j=0;j<20;j++){
			time=ChanInInt(KANAL3WE);
			ChanOutInt(KANAL6WY, time);
		}
	return 0;
}
