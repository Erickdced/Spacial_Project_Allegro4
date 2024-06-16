#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Main
int main() 
{	
	allegro_init();
	
	//Presettings
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	
	//Variable declarations
	BITMAP *buffer = create_bitmap(800, 600);
	clear_to_color(buffer, 0x000000);
	
	//First print
	blit(buffer, screen, 0, 0, 0, 0, 800, 600);
	//Main while      
    while(!key[KEY_ESC])
    {
		
		readkey();
    }
    //Close of program
	destroy_bitmap(buffer);
	return 0;
}
END_OF_MAIN();