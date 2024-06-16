#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct player
{
  	int hp[5];
  	int hb[4];
};
struct damage
{
	int hb[4];
};
struct player prueba;
struct damage armap;
//Main
void playerValues ()
{
	prueba.hb[2] = prueba.hb[0] + 32;
	prueba.hb[3] = prueba.hb[1] + 32;
	
	prueba.hp[1] = prueba.hb[0];
	prueba.hp[2] = prueba.hb[1] - 8;
	prueba.hp[3] = prueba.hp[1] + 32;
	prueba.hp[4] = prueba.hp[2] + 4;
}
void playerDead ()
{
	prueba.hb[0] = 0;
	prueba.hb[1] = 0;
	prueba.hb[2] = 0;
	prueba.hb[3] = 0;
	
	prueba.hp[1] = 0;
	prueba.hp[2] = 0;
	prueba.hp[3] = 0;
	prueba.hp[4] = 0;
}
void weaponValues ()
{
	armap.hb[1] = 120;
	armap.hb[2] = armap.hb[0] + 20;
	armap.hb[3] = armap.hb[1] + 4;
}
int main() 
{	
	allegro_init();
	
	//Pre-settings
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 320, 0, 0);
	
	//Variable declarations
	BITMAP *buffer = create_bitmap(640, 320);
	clear_to_color(buffer, 0x000000);
	int i;
	//size ratio 
	prueba.hp[0] = 32;
	//y ratio
	prueba.hb[0] = 32;
	//x ratio
	prueba.hb[1] = 32;
	
	armap.hb[0] = 200;
	
	playerValues();
	weaponValues();
	
	//First print
	//life bar (RED)
	rectfill(buffer, prueba.hp[1], prueba.hp[2], prueba.hp[1] + prueba.hp[0], prueba.hp[4], 0xb70909);
	//life bar cover (WHITE)
	rect(buffer, prueba.hp[1], prueba.hp[2], prueba.hp[3], prueba.hp[4], 0xffffff);
	//Character (PINK)
	rectfill(buffer, prueba.hb[0], prueba.hb[1], prueba.hb[2], prueba.hb[3], 0xff0072);
	//Weapon (GREEN)
	rectfill(buffer, armap.hb[0], armap.hb[1], armap.hb[2], armap.hb[3], 0x00ff00);
	blit(buffer, screen, 0, 0, 0, 0, 640, 320);
	
	//Main while      
    while(!key[KEY_ESC])
    {
		if(key[KEY_W])
		{
			prueba.hb[1] = prueba.hb[1] - 4;
			playerValues();
		}
		if(key[KEY_A])
		{
			prueba.hb[0] = prueba.hb[0] - 4;
			playerValues();
		}
		if(key[KEY_S])
		{
			prueba.hb[1] = prueba.hb[1] + 4;
			playerValues();
		}
		if(key[KEY_D])
		{
			prueba.hb[0] = prueba.hb[0] + 4;
			playerValues();
		}
		
		//damage interaction
		if(prueba.hp[0] > 0 && prueba.hb[2] >= armap.hb[0] && prueba.hb[1] <= armap.hb[1] && prueba.hb[3] >= armap.hb[3] && prueba.hb[0] <= armap.hb[2])
		{
			prueba.hp[0] = prueba.hp[0] - 4;
			prueba.hb[0] = prueba.hb[0] - 12;
			playerValues();
		}
		//Dead of the character
		if(prueba.hp[0] == 0)
		{
			playerDead();
		}
		
		//hb
		rectfill(buffer, prueba.hp[1], prueba.hp[2], prueba.hp[1] + prueba.hp[0], prueba.hp[4], 0xb70909);
		rect(buffer, prueba.hp[1], prueba.hp[2], prueba.hp[3], prueba.hp[4], 0xffffff);
		rectfill(buffer, prueba.hb[0], prueba.hb[1], prueba.hb[2], prueba.hb[3], 0xff0072);
		rectfill(buffer, armap.hb[0], armap.hb[1], armap.hb[2], armap.hb[3], 0x00ff00);
		
		//Main print
		if(key[KEY_W] || key[KEY_S] || key[KEY_A] || key[KEY_D])
		{
			blit(buffer, screen, 0, 0, 0, 0, 640, 320);
		}
		
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer);
    }
    //Close of program
	destroy_bitmap(buffer);
	return 0;
}
END_OF_MAIN();
