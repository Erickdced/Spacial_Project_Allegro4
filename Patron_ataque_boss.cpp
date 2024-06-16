#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************************************************************************************************************************************************************
																		STRUCTURES
*************************************************************************************************************************************************************/
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
/***************************************************************************************************************************************************************
																		FUNCTIONS
***************************************************************************************************************************************************************/
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
	enemy.hb[2] = enemy.hb[0] + 64; //x2
	enemy.hb[3] = enemy.hb[1] + 64; //y2
	enemy.hp[1] = enemy.hb[0];		//enemy lifebar & lifebox x1
	enemy.hp[2] = enemy.hb[1] - 8;	//enemy lifebar & lifebox y1
	enemy.hp[3] = enemy.hp[1] + 64;	//enemy lifebox x2
	enemy.hp[4] = enemy.hp[2] + 4; //enemy lifebar & lifebox y2
	if(enemy.direc == 0) // key s
	{
		enemy.whb[0] = enemy.hb[0] + 14;//x1
		enemy.whb[2] = enemy.hb[0] + 18;//x2
		enemy.whb[1] = enemy.hb[3] + 8;	//y1
		enemy.whb[3] = enemy.hb[3];		//y2
		
    }
    if(enemy.direc == 1) // key a
    {
		enemy.whb[0] = enemy.hb[0] - 8;	//x1
		enemy.whb[2] = enemy.hb[0];   	//x2
		enemy.whb[1] = enemy.hb[1] + 14; //y1
		enemy.whb[3] = enemy.hb[1] + 18;//y2
	}
	if(enemy.direc == 2) // key d
	{
		enemy.whb[0] = enemy.hb[2] + 8;	//x1
		enemy.whb[2] = enemy.hb[2];   	//z2
		enemy.whb[1] = enemy.hb[1] + 14; //y1
		enemy.whb[3] = enemy.hb[1] + 18;//y2
	}
	if(enemy.direc == 3) // key w
	{
		enemy.whb[0] = enemy.hb[0] + 14; //x1
		enemy.whb[2] = enemy.hb[0] + 18; //x2
		enemy.whb[1] = enemy.hb[1] - 8;	//y1
		enemy.whb[3] = enemy.hb[1];		//y2
	}	
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
//attack start
int attackStart ()
{
	if(player.whb[1] <= enemy.hb[3] && player.whb[2] >= enemy.hb[2] && player.whb[0] <= enemy.hb[0]) //comprobation of w
	{
		return 1;
	}
	else if(player.whb[1] <= enemy.hb[1] && player.whb[2] >= enemy.hb[2] && player.whb[0] <= enemy.hb[0]) //comprobation of s
	{
		return 3;
	}
	else if(player.whb[0] <= enemy.hb[2] && player.whb[1] >= enemy.hb[1] && player.whb[3] <= enemy.hb[3]) //comprobation of a
	{
		return 2;
	}
	else if(player.whb[0] >= enemy.hb[0] && player.whb[1] >= enemy.hb[1] && player.whb[3] <= enemy.hb[3]) // comprobation of d
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

/***************************************************************************************************************************************************************
																	MAIN PROGRAM
***************************************************************************************************************************************************************/
int main() 
{	
	allegro_init();
	
	//Pre-settings
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	
	//BMP declaration 
	BITMAP *buffer1 = create_bitmap(800, 600);
	BITMAP *buffer2 = create_bitmap(800, 600);
	BITMAP *fondo = load_bmp("Map001.bmp", NULL);//mapa
 	BITMAP *personaje  = load_bmp("Francis.bmp",NULL);//Fracis pancho
 	BITMAP *choque = load_bmp("Choque001.bmp", NULL);// hitboxes mapa
 	BITMAP *enemigo = load_bmp("Villana001", NULL); //Enemiga Rosa
 	
	//Variable declarations
	clear_to_color(buffer1, 0x000000);
	int ax, ay, k = 0, i = 1, j = 0, attfase = 0, attset = 0, attdir = 0, l = 0;
	
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
	enemy.hp[0] = 64;
	enemy.hb[0] = 128;
	enemy.hb[1]= 256;
	i = 1;
	srand(time(NULL));
	
	playerValues();
	enemyValues();
	
	//First print
	rectfill(buffer1, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909); // life bar
	rect(buffer1, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff); // life bord
	rectfill(buffer1, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072); // player hitbox

	
	rectfill(buffer1, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
	rect(buffer1, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
	rectfill(buffer1, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00f072); // enemy hitbox
	
	blit(buffer1, screen, 0, 0, 0, 0, 800, 600);
	
	/********************************************************************************************************************************************************
																		MAIN WHILE
	********************************************************************************************************************************************************/    
    while(!key[KEY_ESC])
    {
		ax = player.hb[0];
		ay = player.hb[1];
		//clear buffer
		clear_to_color(buffer1, 0xaaaaaa);
    	//rectfill(buffer1, x, y, player.hb[2], player.hb[3], 0xFF00FF);
    	masked_blit(choque, buffer1, 0, 0, 0, 0, 800, 600);
	//masked_blit(fondo, buffer1, 0, 0, 0, 0, 800, 600);
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
		else if((player.hb[2] + 4) < enemy.hb[0] && i == 1 && j == 0) //facing right
		{
			if (attfase == 0)
			{
				enemy.hb[0] = enemy.hb[0] - 4; 
			}
			enemy.direc = 2;
			enemyValues();
		}
		else if((player.hb[3] + 4) < enemy.hb[1] && i == -1 && j == 0) //facing  up
		{
			if(attfase == 0)
			{
				enemy.hb[1] = enemy.hb[1] - 4;
			}
			enemy.direc = 3;
			enemyValues();
		}
		else if((player.hb[0] - 4) > enemy.hb[2] && i == 1 && j == 0) //facing left
		{
		
			if(attfase == 0)
			{
				enemy.hb[0] = enemy.hb[0] + 4;
			}
			enemy.direc = 1;
			enemyValues();
		}
		else if((player.hb[1] - 4) > enemy.hb[3] && i == -1 && j == 0 && attfase == 0)//facing down
		{
			if(attfase == 0)
			{
				enemy.hb[1] = enemy.hb[1] + 4;
			}
			enemy.direc = 0;
			enemyValues();
		}
		//print of hitboxes
		rectfill(buffer1, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player
		rectfill(buffer1, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00f072); // enemy hitbox
		
		//move update
		i = i * -1;
		if(player.hb[3] == 0 && player.hb[4] == 0)
		{
			j = 1;
			textout_centre_ex(buffer1, font, "game over", 320, 160, 0xffffff, 0x000000);
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
		//attack
		else if(getpixel(buffer1, player.whb[0], player.whb[1]) == 0x00f072)
		{
			if(key[KEY_P] && i == -1)
			{
				enemy.hp[0] -= 2;
			}
		}
		else if(getpixel(buffer1, player.whb[0], player.whb[3]) == 0x00f072)
		{
			if(key[KEY_P] && i == -1)
			{
				enemy.hp[0] -= 2;
			}
		}
		/*******************************************************************************************************************************************************
																		ENEMY ATTACK
		*******************************************************************************************************************************************************/
		//attack init
		attset = attackStart();
		if(attset == 1 && attfase == 0) //UP
		{
			attfase++;
			attdir = 1;
		}
		if(attset == 2 && attfase == 0) //LEFT
		{
			attfase++;
			attdir = 2;
		}
		if(attset == 3 && attfase == 0) //DOWN
		{
			attfase++;
			attdir = 3;
		}
		if(attset == 4 && attfase == 0) //RIGHT
		{
			attfase++;
			attdir = 4;
		}
		//enemy attack UP
		if(attdir == 1 && attfase == 1)
		{
			enemy.hb[1] -= 12;
			enemyValues();
			attfase ++ ;
		}
		else if(attdir == 1 && attfase > 1 && attfase < 5)
		{
			attfase ++ ;
		}
		else if(attdir == 1 && attfase == 5)
		{
			if(getpixel(buffer1, enemy.whb[0], enemy.whb[1]) ==  0xff0072)
			{
				player.hp[0] -= 2;
				playerValues();
			}	
			else if(getpixel(buffer1, enemy.whb[0], enemy.whb[3]) ==  0xff0072)		
			{
				player.hp[0] -= 2;
				playerValues();
			}
			attfase++;
		}
		else if(attdir == 1 && attfase == 6)
		{
			enemy.hb[1]+= 8;
			enemyValues();
			attfase++;
		}
		else if(attdir == 1 && attfase > 6 && attfase < 10)
		{
			attfase++;
		}
		//enemy attack LEFT
		if(attdir == 2 && attfase == 1)
		{
			enemy.hb[0] -= 12;
			enemyValues();
			attfase ++ ;
		}
		else if(attdir == 2 && attfase > 1 && attfase < 5)
		{
			attfase ++ ;
		}
		else if(attdir == 2 && attfase == 5)
		{
			if(getpixel(buffer1, enemy.whb[0], enemy.whb[1]) ==  0xff0072)
			{
				player.hp[0] -= 2;
				playerValues();
			}	
			else if(getpixel(buffer1, enemy.whb[0], enemy.whb[3]) ==  0xff0072)		
			{
				player.hp[0] -= 2;
				playerValues();
			}
			attfase++;
		}
		else if(attdir == 2 && attfase == 6)
		{
			enemy.hb[0]+= 8;
			enemyValues();
			attfase++;
		}
		else if(attdir == 2 && attfase > 6 && attfase < 10)
		{
			attfase++;
		}
		
		//enemy attack DOWN
		if(attdir == 3 && attfase == 1)
		{
			enemy.hb[1] += 12;
			enemyValues();
			attfase ++ ;
		}
		else if(attdir == 3 && attfase > 1 && attfase < 5)
		{
			attfase ++ ;
		}
		else if(attdir == 3 && attfase == 5)
		{
			if(getpixel(buffer1, enemy.whb[0], enemy.whb[1]) ==  0xff0072)
			{
				player.hp[0] -= 2;
				playerValues();
			}	
			else if(getpixel(buffer1, enemy.whb[0], enemy.whb[3]) ==  0xff0072)		
			{
				player.hp[0] -= 2;
				playerValues();
			}
			attfase++;
		}
		else if(attdir == 3 && attfase == 6)
		{
			enemy.hb[0]-= 8;
			enemyValues();
			attfase++;
		}
		else if(attdir == 3 && attfase > 6 && attfase < 10)
		{
			attfase++;
		}
		
		//enemy attack RIGHT
		if(attdir == 4 && attfase == 1)
		{
			enemy.hb[0] += 12;
			enemyValues();
			attfase ++ ;
		}
		else if(attdir == 4 && attfase > 1 && attfase < 5)
		{
			attfase ++ ;
		}
		else if(attdir == 4 && attfase == 5)
		{
			if(getpixel(buffer1, enemy.whb[0], enemy.whb[1]) ==  0xff0072)
			{
				player.hp[0] -= 2;
				playerValues();
			}	
			else if(getpixel(buffer1, enemy.whb[0], enemy.whb[3]) ==  0xff0072)		
			{
				player.hp[0] -= 2;
				playerValues();
			}
			attfase++;
		}
		else if(attdir == 4 && attfase == 6)
		{
			enemy.hb[0] -= 8;
			enemyValues();
			attfase++;
		}
		else if(attdir == 4 && attfase > 6 && attfase < 10)
		{
			attfase++;
		}
		// att dir change
		if (attfase == 10)
		{
			l = rand() % 2;
			if (l == 1 && attdir < 4)
			{
				attdir++;
			}
			else if (l == 1 && attdir == 4)
			{
				attdir = 1;
			}
			else if (l == 0 && attdir > 1)
			{
				attdir--;
			}
			else if (l == 0 && attdir == 1)
			{
				attdir = 4;
			}
			attfase = 1;
		}
		//enemy attack 
		//masked blit of background
	//masked_blit(fondo, buffer1, 0, 0, 0, 0, 800, 600); 
		//life bar
		rectfill(buffer1, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909);//player lifebar (hp)
		rect(buffer1, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff);//player lifebar (box)
				
		rectfill(buffer1, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
		rect(buffer1, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
		
		//masked blit of player
    	masked_blit(personaje, buffer1, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
	//masked_blit(enemigo, buffer1, enemy.anima[k], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
    	
		//re-blit of all
		blit(buffer1, screen, 0, 0, 0, 0, 800, 600);
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer1);
    }
    //Close of program
    destroy_bitmap(choque);
    destroy_bitmap(fondo);
    destroy_bitmap(buffer1);
	destroy_bitmap(buffer2);
	destroy_bitmap(personaje);
	destroy_bitmap(enemigo); 
	return 0;
}
END_OF_MAIN();

