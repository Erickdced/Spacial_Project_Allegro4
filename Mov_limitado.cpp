#include <allegro.h>
#include <stdio.h>
//Hitbox del perosnaje
struct player
{
	int hb[5];
};

struct player character;

//Actualización de valores de HB
void player_values(int x, int y)
{
	character.hb[1] = x + character.hb[0];
	character.hb[2] = y + character.hb[3];
}

int main() 
{
    allegro_init();
 	install_keyboard();
  
 	set_color_depth(32);
 	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
 
	//Creación de BITMAP´s
 	BITMAP *buffer = create_bitmap(800, 600);
	BITMAP *fondo = load_bmp("Map001.bmp", NULL);
 	BITMAP *personaje  = load_bmp("Francis.bmp",NULL);
 	BITMAP *choque = load_bmp("Choque001.bmp", NULL);
 
  	//Declaracion de variables de control y arreglos para movimiento
 	int x = 400, y = 500, ax, ay, direc[4] = {0, 32, 64, 96}, anima[3] = {0, 32, 64}, i = 0, j = 0;
 	character.hb[0] = 18;
 	character.hb[3] = 28;
 	direc[i] = 0;
 	anima[j] = 0; 
 
 
 	player_values(x, y);
 	
 	//Primera impresión - Color de .HB ROJO
 	rectfill(buffer, x, y, character.hb[1], character.hb[2], 0xFF0000);
 	blit(buffer, screen, 0, 0, 0, 0, 800, 600);
 
  	//Main while
 	while (!key[KEY_ESC])
 	{ 
		ax = x;
		ay = y;
    	clear_to_color(buffer, 0xaaaaaa);
    	rectfill(buffer, x, y, character.hb[1], character.hb[2], 0xFF00FF);
    	masked_blit(choque, buffer, 0, 0, 0, 0, 800, 600);
		masked_blit(fondo, buffer, 0, 0, 0, 0, 800, 600);
    	masked_blit(personaje, buffer, anima[j], direc[i], x, y, 28, 28);    	
        
	  	//Movimiento de personaje	   
    	if (key[KEY_UP])
    	{
			y-=4;
			i = 3;
			player_values(x, y);
		}
		if (key[KEY_DOWN])
		{
    		y+=4;
    		i = 0;
    		player_values(x, y);
		}
    	if (key[KEY_LEFT])
		{
    		x-=4;
    		i = 1;
			player_values(x, y);
		}	
    	if (key[KEY_RIGHT])
		{
    		x+=4;
    		i = 2;
    		player_values(x, y);
		}
	
		//Entra si el personaje se ha movido de coordenadas
		if(ax != x || ay != y)
		{
			j++;
			if(j > 2) 
				j = 0;
		}
		 //Compara el color del pixel a blanco
		if(getpixel(choque, character.hb[1], character.hb[2]) == 0xFFFFFF)
		{
			x = ax;
			y = ay;
		}	
		if(getpixel(choque, x, character.hb[2]) == 0xFFFFFF)
		{
			x = ax;
			y = ay;
		}	
		
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        
    	rest(40);
               
 	}  
 	
   	destroy_bitmap(choque);
 	destroy_bitmap(fondo);  
 	destroy_bitmap(personaje);
 	destroy_bitmap(buffer);
  
 	return 0;
}
END_OF_MAIN();
