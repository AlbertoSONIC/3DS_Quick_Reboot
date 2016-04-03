#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int main()
{
	// Initialize services
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
			APT_HardwareResetAsync();
			aptCloseSession();
		}
	}

	// Exit services
	gfxExit();
	return 0;
}
