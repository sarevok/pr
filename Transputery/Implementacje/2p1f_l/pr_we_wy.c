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
	Channel*  KANAL2WE;
	Channel*  KANAL3WY;
	int time[13][6];
	int i;
	int procesy[13];
	int y;

	KANAL2WE   = (Channel *)  get_param (3);
	KANAL3WY   = (Channel *)  get_param (4);
	
	ChanIn(KANAL2WE, time, sizeof(int)*13*6);
	
	for(i=0;i<13;i++)
		procesy[i]=1;
	procesy[0]=0;
	procesy[5]=0;
	procesy[6]=0;
	procesy[8]=0;
	procesy[9]=0;	

	for(i=0;i<13;i++){
		if(!procesy[i]) continue;	
		printf("%d: %d\t%d\t%d\t%d\t%d\n", i, time[i][1]-time[i][0], time[i][2]-time[i][0],
			time[i][3]-time[i][0], time[i][4]-time[i][0], time[i][5]-time[i][0]);
	}

	exit_terminate (0);
	return 0;
}
