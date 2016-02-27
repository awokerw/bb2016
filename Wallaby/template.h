//#define CREATE
#define LINK

#include <stdio.h>

#ifdef CREATE
	#include "./createDrive.h"
#endif

#ifdef LINK
	#include "./drive.h"
#endif
