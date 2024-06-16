#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
  	allegro_init();
 	install_keyboard();
  
 	set_color_depth(32);
 	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
 
	//Creación de BITMAP
 	BITMAP *buffer = create_bitmap(800, 600);
 	BITMAP *fondo = load_bmp("reino.bmp", NULL);
 	BITMAP *personaje  = load_bmp("pj.bmp",NULL);
 
  //Declaracion de variables de control y arreglos
 	int x = 8, y = 8, ax, ay, direc[4] = {0, 64, 128, 192}, anima[3] = {0, 42, 84}, i = 0, j = 0;
 	direc[i] = 0;
 	anima[j] = 0; 
 
  //Main while
 	while (!key[KEY_ESC]) 
 	{ 
		ax = x;
		ay = y;
    	clear_to_color(buffer, 0x000000);
		masked_blit(fondo, buffer, 0, 0, 0, 0, 800, 600);
    	masked_blit(personaje, buffer, anima[j], direc[i], x, y, 42, 64);
        
	  //Movimiento de personaje	   
    	if (key[KEY_W])
    	{
			y-=4;
				i = 3;
		}
		if (key[KEY_S])
		{
    		y+=4;
    		i = 0;
		}
    	if (key[KEY_A])
		{
    		x-=4;
    		i = 1;
		}	
    	if (key[KEY_D])
		{
    		x+=4;
    		i = 2;
		}
	
		//Entra si el personaje se ha movido de coordenadas
		if(ax != x || ay != y)
		{
			j++;
			if(j > 2) 
			j = 0;
		}
	
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
    	rest(60);
               
 	}  
   
 	destroy_bitmap(fondo);  
 	destroy_bitmap(personaje);
 	destroy_bitmap(buffer);
  
 	return 0;
}
END_OF_MAIN();
