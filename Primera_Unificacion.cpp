#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//player
struct player
{
  	int hp[5];
  	int hb[4];
  	int direc;
  	int whb[4];
  	int visdir[4];
  	int anima[3];
};
struct player player;
struct player enemy;
//act of player 
void playerValues ()
{
	player.hb[2] = player.hb[0] + 32; //player x2
	player.hb[3] = player.hb[1] + 32; //player y2
	player.hp[1] = player.hb[0];	  //lifebar x1 & lifebox x1 
	player.hp[2] = player.hb[1] - 8;  //lifebar y1 & lifebox y1
	player.hp[3] = player.hp[1] + 32; //lifebox x2
	player.hp[4] = player.hp[2] + 4;  //lifebox y2 & lifebar y2
	
	if(player.direc == 0) // key s
	{
		player.whb[0] = player.hb[0] + 14;	//x1
		player.whb[2] = player.hb[0] + 18;	//x2
		player.whb[1] = player.hb[3] + 8;	//y1
		player.whb[3] = player.hb[3];		//y2
		
    }
    if(player.direc == 1) // key a
    {
		player.whb[0] = player.hb[0] - 8;	//x1
		player.whb[2] = player.hb[0];   	//x2
		player.whb[1] = player.hb[1] + 14; 	//y1
		player.whb[3] = player.hb[1] + 18;	//y2
	}
	if(player.direc == 2) // key d
	{
		player.whb[0] = player.hb[2] + 8;	//x1
		player.whb[2] = player.hb[2];   	//z2
		player.whb[1] = player.hb[1] + 14; 	//y1
		player.whb[3] = player.hb[1] + 18;	//y2
	}
	if(player.direc == 3) // key w
	{
		player.whb[0] = player.hb[0] + 14;	//x1
		player.whb[2] = player.hb[0] + 18;	//x2
		player.whb[1] = player.hb[1] - 8;	//y1
		player.whb[3] = player.hb[1];		//y2
	}	
}
//act of enemy
void enemyValues ()
{
	enemy.hb[2] = enemy.hb[0] + 32; //x2
	enemy.hb[3] = enemy.hb[1] + 32; //y2
	enemy.hp[1] = enemy.hb[0];		//enemy lifebar & lifebox x1
	enemy.hp[2] = enemy.hb[1] - 8;	//enemy lifebar & lifebox y1
	enemy.hp[3] = enemy.hp[1] + 32;	//enemy lifebox x2
	enemy.hp[4] = enemy.hp[2] + 4; //enemy lifebar & lifebox y2
}
//dead of player
void playerDead ()
{
	player.hb[0] = 0;
	player.hb[1] = 0;
	player.hb[2] = 0;
	player.hb[3] = 0;
	player.hp[1] = 0;
	player.hp[2] = 0;
	player.hp[3] = 0;
	player.hp[4] = 0;
}
//dead of enemy
void enemyDead ()
{
	enemy.hb[0] = 0;
	enemy.hb[1] = 0;
	enemy.hb[2] = 0;
	enemy.hb[3] = 0;
	enemy.hp[1] = 0;
	enemy.hp[2] = 0;
	enemy.hp[3] = 0;
	enemy.hp[4] = 0;
}
//main
int main() 
{	
	allegro_init();
	
	//Pre-settings
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	
	//BMP declaration 
	BITMAP *buffer = create_bitmap(800, 600);
	BITMAP *fondo = load_bmp("Map001.bmp", NULL);//mapa
 	BITMAP *personaje  = load_bmp("Francis.bmp",NULL);//Fracis pancho
 	BITMAP *choque = load_bmp("Choque001.bmp", NULL);// hitboxes mapa
 	BITMAP *enemigo = load_bmp("Villana001.bmp", NULL); //Enemiga Rosa
 	
	//Variable declarations
	clear_to_color(buffer, 0x000000);
	int ax, ay, k = 0, i = 1, j = 0, aip = 0;
	
	for(i >= 0; i < 4; i++)
	{
		player.visdir[i] = 32*i; 
		if(i != 3)
		{
			player.anima[i] = 32*i;
		}
	}
	player.visdir[0] = 0;
	player.anima[k] = 0;
	player.direc = 0;
	player.hp[0] = 32;
	player.hb[0] = 400;
	player.hb[1] = 300;
	enemy.hp[0] = 32;
	enemy.hb[0] = 128;
	enemy.hb[1]= 256;
	i = 1;
	
	playerValues();
	enemyValues();
	
	//First print
	rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909); // life bar
	rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff); // life bord
	rectfill(buffer, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072); // player hitbox

	
	rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
	rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
	rectfill(buffer, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00f072); // enemy hitbox
	
	blit(buffer, screen, 0, 0, 0, 0, 800, 600);
	
	//Main while      
    while(!key[KEY_ESC])
    {
		ax = player.hb[0];
		ay = player.hb[1];
		
		clear_to_color(buffer, 0xaaaaaa);
    	//rectfill(buffer, x, y, player.hb[2], player.hb[3], 0xFF00FF);
    	masked_blit(choque, buffer, 0, 0, 0, 0, 800, 600);
		//masked_blit(fondo, buffer, 0, 0, 0, 0, 800, 600);
        //move
		if(key[KEY_W] && player.hb[1] > 4)
		{
			player.hb[1] = player.hb[1] - 4;
			player.direc = 3;
			playerValues();
		}
		else if(key[KEY_A] && player.hb[0] > 4)
		{
			player.hb[0] = player.hb[0] - 4;
			player.direc = 1;
			playerValues();
		}
		else if(key[KEY_S] && player.hb[3] < 600)
		{
			player.hb[1] = player.hb[1] + 4;
			player.direc = 0;
			playerValues();
		}
		else if(key[KEY_D] && player.hb[2] < 800)
		{
			player.hb[0] = player.hb[0] + 4;
			player.direc = 2;
			playerValues();
		}
		//attack
		else if(key[KEY_P] && aip == 1 && enemy.hp[0] > 0)
		{
			enemy.hp[0] -= 4;
			enemyValues();
		}
		//enemy dead
		else if (enemy.hp[0] == 0)
		{
			enemyDead();
		}
		//dead of character
		else if(player.hp[0] == 0)
		{
			playerDead();
		}
		//enemy pursuit
		else if((player.hb[2] + 4) < enemy.hb[0] && i == 1 && j == 0)
		{
			enemy.hb[0] = enemy.hb[0] - 4; //facing right
			enemy.direc = 2;
			enemyValues();
		}
		else if((player.hb[3] + 4) < enemy.hb[1] && i == -1 && j == 0) //facing  up
		{
			enemy.hb[1] = enemy.hb[1] - 4;
			enemy.direc = 3;
			enemyValues();
		}
		else if((player.hb[0] - 4) > enemy.hb[2] && i == 1 && j == 0) //facing left
		{
			enemy.hb[0] = enemy.hb[0] + 4;
			enemy.direc = 1;
			enemyValues();
		}
		else if((player.hb[1] - 4) > enemy.hb[3] && i == -1 && j == 0)//facing down
		{
			enemy.hb[1] = enemy.hb[1] + 4;
			enemy.direc = 0;
			enemyValues();
		}
		//print of hitboxes
		rectfill(buffer, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player*/
		rectfill(buffer, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00f072); // enemy hitbox
		
		//move update
		i = i * -1;
		if(player.hb[3] == 0 && player.hb[4] == 0)
		{
			j = 1;
			textout_centre_ex(buffer, font, "game over", 320, 160, 0xffffff, 0x000000);
		}
		else if(enemy.hb[0] == 0 && enemy.hb[1] == 0)
		{
			j = 1;
		}
		else if(ax != player.hb[0] || ay != player.hb[1])
		{
			k++;
			if(k > 2)
			{ 
				k = 0;
			}
		}
		
		else if(getpixel(choque, player.hb[2], player.hb[3]) == 0xFFFFFF)
		{
			player.hb[0] = ax;
			player.hb[1] = ay;
		}
		else if(getpixel(choque, player.hb[0], player.hb[3]) == 0xFFFFFF)
		{
			player.hb[0] = ax;
			player.hb[1] = ay;
		}
		else if(getpixel(buffer, player.whb[0], player.whb[1]) == 0x00f072)
		{
			if(key[KEY_P])
			{
				enemy.hp[0] -= 4;
			}
		}
		else if(getpixel(buffer, player.whb[0], player.whb[3]) == 0x00f072)
		{
			if(key[KEY_P])
			{
				enemy.hp[0] -= 4;
			}
		}
		
		//masked blit of background
		masked_blit(fondo, buffer, 0, 0, 0, 0, 800, 600); 
		//life bar
		rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909);//player lifebar (hp)
		rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff);//player lifebar (box)
				
		rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
		rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
		
		//masked blit of player
    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
    	masked_blit(enemigo, buffer, enemy.anima[k], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
    	
		//re-blit of all
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer);
    }
    //Close of program
    destroy_bitmap(choque);
    destroy_bitmap(fondo);
    destroy_bitmap(buffer);
	destroy_bitmap(buffer);
	return 0;
}
END_OF_MAIN();
