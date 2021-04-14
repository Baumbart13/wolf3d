#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//#include "../baumbartWolfHelp/baumbartWolf_beta.h" // NOTE: Only include this for BETA version of game

///////////////////////////////////////////////////////////////////////////
///
/// Function definitions
///
///////////////////////////////////////////////////////////////////////////

void CheckForEpisodes(void);
void Patch386(void);
void InitGame();
void DemoLoop();
void Quit(char *error);

/// CHECK FOR EPISODES
void CheckForEpisodes(void){

}

int main() {

#ifdef BETA
	//
	// THIS IS FOR BETA ONLY
	//
	time_t t = time(NULL);
	struct tm d = *localtime(&t);
	
	if(d.tm_year > YEAR || (d.tm_mon >= MONTH && d.tm_wday >= DAY)){
		printf("Sorry, BETA-TESTING is over. Thanks for your help.\n");
		exit(1);
	}
	
#endif
	
	CheckForEpisodes();
	
	Patch386();
	
	InitGame();
	
	DemoLoop();
	
	Quit("Demo Loop exited???");

}
