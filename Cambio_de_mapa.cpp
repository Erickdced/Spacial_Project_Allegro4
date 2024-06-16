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
	//Fondos y choques
	BITMAP *fondo1 = load_bmp("Map001.bmp", NULL);//mapa
	BITMAP *fondo2 = load_bmp("Map002.bmp", NULL);//mapa
	BITMAP *fondo3 = load_bmp("Map003.bmp", NULL);//mapa
	BITMAP *fondo4 = load_bmp("Map004.bmp", NULL);//mapa
	BITMAP *fondo5 = load_bmp("Map005.bmp", NULL);//mapa
	BITMAP *fondo6 = load_bmp("Map006.bmp", NULL);//mapa
	BITMAP *fondo7 = load_bmp("Map007.bmp", NULL);//mapa
	BITMAP *choque1 = load_bmp("Choque001.bmp", NULL);// hitboxes mapa
	BITMAP *choque2 = load_bmp("Choque002.bmp", NULL);// hitboxes mapa
	BITMAP *choque3 = load_bmp("Choque003.bmp", NULL);// hitboxes mapa
	BITMAP *choque4 = load_bmp("Choque004.bmp", NULL);// hitboxes mapa
	BITMAP *choque5 = load_bmp("Choque005.bmp", NULL);// hitboxes mapa
	BITMAP *choque6 = load_bmp("Choque006.bmp", NULL);// hitboxes mapa
	BITMAP *choque7 = load_bmp("Choque007.bmp", NULL);// hitboxes mapa

	//Player & Enemy
 	BITMAP *personaje  = load_bmp("Francis.bmp",NULL);//Fracis pancho
 	BITMAP *enemigo = load_bmp("Villano001.bmp", NULL); //Enemiga Rosa
 	
	//Variable declarations
	clear_to_color(buffer, 0x000000);
	int ax, ay, ex, ey, k = 0, ek = 0, i = 1, j = 0, aip = 0;
	
	for(i >= 0; i < 4; i++)
	{
		player.visdir[i] = 32*i; 
		if(i != 3)
		{
			player.anima[i] = 32*i;
		}
	}
	for(j >= 0; j < 4; j++)
	{
		enemy.visdir[j] = 32*j; 
		if(j != 3)
		{
			enemy.anima[j] = 32*j;
		}
	}
	player.visdir[0] = 0;
	player.anima[k] = 0;
	enemy.visdir[0] = 0;
	enemy.anima[ek] = 0;
	player.direc = 0;
	enemy.direc = 0;
	player.hp[0] = 32;
	player.hb[0] = 290;
	player.hb[1] = 550;
	enemy.hp[0] = 32;
	enemy.hb[0] = 128;
	enemy.hb[1]= 256;
	i = 1;
	j = 0;
	int mapa = 1;
	
	playerValues();
	enemyValues();
	
	//First print
	rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909); // life bar
	rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff); // life bord
	rectfill(buffer, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072); // player hitbox	
	rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
	rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
	rectfill(buffer, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
	rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	
	blit(buffer, screen, 0, 0, 0, 0, 800, 600);
	
	//Main while      
    while(!key[KEY_ESC])
    {
		ax = player.hb[0];
		ay = player.hb[1];
		ex = enemy.hb[0];
		ey = enemy.hb[1];
		
		clear_to_color(buffer, 0xaaaaaa);
		rectfill(buffer, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player
		rectfill(buffer, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
		//rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);	
//*********************MOVE************************************************************
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
//********************ATTACK***********************************************************
		else if((getpixel(buffer, player.whb[0], player.whb[1]) == 0x00FFFF) && (key[KEY_P]))
		{
			enemy.hp[0] -= 4;
			enemyValues();
		}
//******************enemy dead
		if (enemy.hp[0] == 0)
		{
			enemyDead();
		}
//******************dead of character
		else if(player.hp[0] == 0)
		{
			playerDead();
		}
//******************enemy pursuit
		else if((player.hb[2] + 4) < enemy.hb[0] && i == 1 && j == 0)
		{
			enemy.hb[0] = enemy.hb[0] - 4; //facing right
			enemy.direc = 1;
			enemy.visdir[enemy.direc] = 32;
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
			enemy.direc = 2;
			enemyValues();
		}
		else if((player.hb[1] - 4) > enemy.hb[3] && i == -1 && j == 0)//facing down
		{
			enemy.hb[1] = enemy.hb[1] + 4;
			enemy.direc = 0;
			enemyValues();
		}
//********************MOVE UPDATE******************************************************
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
		if(ax != player.hb[0] || ay != player.hb[1])
		{
			k++;
			if(k > 2)
			{ 
				k = 0;
			}
		}
		if(ex != enemy.hb[0] || ey != enemy.hb[1])
		{
			ek++;
			if(ek > 2)
			{ 
				ek = 0;
			}
		}
//**************************LIMITS*******************************************************
		if(mapa == 1)
			if((getpixel(choque1, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque1, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 2)
			if((getpixel(choque2, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque2, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 3)
			if((getpixel(choque3, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque3, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 4)
			if((getpixel(choque4, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque4, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 5)
			if((getpixel(choque5, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque5, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 6)
			if((getpixel(choque6, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque6, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 7)
			if((getpixel(choque7, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque7, player.hb[2], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 1)
			if((mapa == 7) && (getpixel(choque7, player.hb[0], player.hb[3]) == 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
//*************************MASKED_BLIT & CHANGE OF MAP001**************************************
		if(mapa == 1)
		{
			masked_blit(choque1, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo1, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	   		masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			if(enemy.hp[0] != 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			
			//cambio de mapa
			if(getpixel(choque1, player.hb[0], player.hb[1]) == 0x00FFFF)
			{
				mapa = 2;
	 			player.hb[0] = 420;
				player.hb[1] = 560;
			}
		}
	//*************************MASKED_BLIT & CHANGE OF MAP002**************************************
		if(mapa == 2)
		{
			masked_blit(choque2, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo2, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player2
	    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
	    	if(enemy.hp[0] != 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			//cambio de mapa
			if (getpixel(choque2, player.hb[2], player.hb[3]) == 0x00FFFF)
			{
				player.hb[0] = 400;
				player.hb[1] = 20;
				mapa = 1;
			}
			else if (getpixel(choque2, player.hb[0], player.hb[1]) == 0x00FF00)
			{
				mapa = 3;
				player.hb[0] = 330;
				player.hb[1] = 550;
			}
			else if (getpixel(choque2, player.hb[2], player.hb[3]) == 0xFF00FF)
			{
				mapa = 4;
				player.hb[0] = 25;
				player.hb[1] = 100;
			}
			else if (getpixel(choque2, player.hb[2], player.hb[3]) == 0xFF0000)
			{
				mapa = 5;
				player.hb[0] = 14;
				player.hb[1] = 411;
			}
		}
	//*************************MASKED_BLIT & CHANGE OF MAP003**************************************
		if(mapa == 3)
		{
			masked_blit(choque3, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo3, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
	    	if(enemy.hp[0] != 0)
	    	{
				masked_blit(personaje, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}	
			//cambio de mapa
			if(getpixel(choque3, player.hb[0], player.hb[3]) == 0x00FF00)
			{
				mapa = 2;
				player.hb[0] = 320;
				player.hb[1] = 10;
			}
		}
	//*************************MASKED_BLIT & CHANGE OF MAP004**************************************
		if (mapa == 4)
		{
			masked_blit(choque4, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo4, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
	    	if(enemy.hp[0] != 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			//cambio de mapa
			if(getpixel(choque4, player.hb[0], player.hb[1]) == 0xFF00FF)
			{
				mapa = 2;
				player.hb[0] = 626;
				player.hb[1] = 555;
			}
		}
	//*************************MASKED_BLIT & CHANGE OF MAP005**************************************
		if (mapa == 5)
		{
			masked_blit(choque5, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo5, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
	    	if(enemy.hp[0] != 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			//cambio de mapa
			if(getpixel(choque5, player.hb[0], player.hb[3]) == 0x00FFFF)
			{
				mapa = 2;
				player.hb[0] = 748;
				player.hb[1] = 305;
			}
			else if (getpixel(choque5, player.hb[2], player.hb[3]) == 0x00FF00)
			{
				mapa = 6;
				player.hb[0] = 12;
				player.hb[1] = 310;
			}
		}
			//*************************MASKED_BLIT & CHANGE OF MAP001**************************************
		if(mapa == 6)
		{
			masked_blit(choque6, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo6, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			if(enemy.hp[0] != 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			//cambio de mapa
			if(getpixel(choque6, player.hb[0], player.hb[1]) == 0xFF00FF)
			{
				mapa = 7;
				player.hb[0] = 374;
				player.hb[1] = 535;
			}
			else if(getpixel(choque6, player.hb[0], player.hb[1]) == 0x00FF00)
			{
				mapa = 5;
				player.hb[0] = 760;
				player.hb[1] = 93;
			}
		}
			//*************************MASKED_BLIT & CHANGE OF MAP007**************************************
		if(mapa == 7)
		{
			masked_blit(choque7, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo7, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	    	masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			if(enemy.hp[0] != 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[ek], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			//cambio de mapa
			if(getpixel(choque7, player.hb[2], player.hb[3]) == 0xFF0000)
			{
				mapa = 6;
				player.hb[0] = 466;
				player.hb[1] = 36;
			}
		}
//****************************LIFE BAR**************************************************
		rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909);//player lifebar (hp)
		rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff);//player lifebar (box)
		rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
		rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
		
//****************************MAIN BLIT*************************************************
		/*rectfill(buffer, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player
		rectfill(buffer, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox*/
		rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer);
    }
    //Close of program
    destroy_bitmap(choque1);
    destroy_bitmap(fondo1);
    destroy_bitmap(buffer);
	return 0;
}
END_OF_MAIN();
