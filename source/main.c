#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int main()
{
	// Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();

    u32 input;
	// Main loop
	while (aptMainLoop())
	{
		
		//HID Input
		hidScanInput();
		input = hidKeysDown();

		//Abort reboot if L is pressed
		if (input & KEY_L) break;
		else
		{
			//Reboot Code
			aptOpenSession();
			APT_HardwareResetAsync(NULL);
			aptCloseSession();
		}
	}

	// Exit services
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
