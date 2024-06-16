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
  	int atack[3];
  	int menu[4];
};
struct player player;
struct player npc1;
struct player enemy;
struct player atack;
//act of player 
void playerValues ()
{
	player.hb[2] = player.hb[0] + 32; //player x2
	player.hb[3] = player.hb[1] + 32; //player y2
	player.hp[1] = player.hb[0];	  //lifebar x1 & lifebox x1 
	player.hp[2] = player.hb[1] - 8;  //lifebar y1 & lifebox y1
	player.hp[3] = player.hp[1] + 32; //lifebox x2
	player.hp[4] = player.hp[2] + 4;  //lifebox y2 & lifebar y2
	//weapon direction
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
	enemy.hp[4] = enemy.hp[2] + 4;  //enemy lifebar & lifebox y2
	//weapon direction
	if(enemy.direc == 0) // key s
	{
		enemy.whb[0] = enemy.hb[0] + 14;	//x1
		enemy.whb[2] = enemy.hb[0] + 18;	//x2
		enemy.whb[1] = enemy.hb[3] + 8;		//y1
		enemy.whb[3] = enemy.hb[3];			//y2
    }
    if(enemy.direc == 1) // key a
    {
		enemy.whb[0] = enemy.hb[0] - 8;		//x1
		enemy.whb[2] = enemy.hb[0];   		//x2
		enemy.whb[1] = enemy.hb[1] + 14; 	//y1
		enemy.whb[3] = enemy.hb[1] + 18;	//y2
	}
	if(enemy.direc == 2) // key d
	{
		enemy.whb[0] = enemy.hb[2] + 8;		//x1
		enemy.whb[2] = enemy.hb[2];   		//z2
		enemy.whb[1] = enemy.hb[1] + 14; 	//y1
		enemy.whb[3] = enemy.hb[1] + 18;	//y2
	}
	if(enemy.direc == 3) // key w
	{
		enemy.whb[0] = enemy.hb[0] + 14;	//x1
		enemy.whb[2] = enemy.hb[0] + 18;	//x2
		enemy.whb[1] = enemy.hb[1] - 8;		//y1
		enemy.whb[3] = enemy.hb[1];			//y2
	}		
}
void npcValues()
{
	npc1.hb[2] = npc1.hb[0] + 32; //x2
	npc1.hb[3] = npc1.hb[1] + 32; //y2
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
void enemy_pursuit(int j)
{
	if((player.hb[2] + 4) < enemy.hb[0] &&  j == 0)//facing right
	{
		enemy.hb[0] = enemy.hb[0] - 4; 
		enemyValues();
		enemy.direc = 1;
	}
	else if((player.hb[3] + 4) < enemy.hb[1] && j == 0) //facing  up
	{
		enemy.hb[1] = enemy.hb[1] - 4;
		enemyValues();
		enemy.direc = 3;
	}
	else if((player.hb[0] - 4) > enemy.hb[2] && j == 0) //facing left
	{
		enemy.hb[0] = enemy.hb[0] + 4;
		enemyValues();
		enemy.direc = 2;
	}
	else if((player.hb[1] - 4) > enemy.hb[3] && j == 0)//facing down
	{
		enemy.hb[1] = enemy.hb[1] + 4;
		enemyValues();
		enemy.direc = 0;
	}
	return;
}
void move()
{
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
		return;
}
void enemyAttack(BITMAP *hitbox, BITMAP *ataque, BITMAP *buffer)
{
	if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (key[KEY_P]))
	{
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 0))//s
		{
			rectfill(buffer, player.whb[0], player.whb[1] + 4, player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[0], player.hb[3], 32, 32);
			enemy.hb[1] += 32;
		}
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 1))//a
		{
			rectfill(buffer, player.whb[0] - 4, player.whb[1], player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[0] - 40, player.hb[1], 32, 32);
			enemy.hb[0] -= 32;
		}
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 2))//d
		{
			rectfill(buffer, player.whb[0] + 4, player.whb[1], player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[2], player.hb[1], 32, 32);
			enemy.hb[0] += 32;
		}
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 3))//w
		{
			rectfill(buffer, player.whb[0], player.whb[1] - 4, player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[0], player.hb[1] - 32, 32, 32);
			enemy.hb[1] -= 32;
		}
		enemy.hp[0] -= 4;
		enemyValues();
		rest(50);
	}
	return;
}
void playerAttack(BITMAP *hitbox, BITMAP *ataque, BITMAP *buffer)
{
	if(getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072)
	{
		if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 0))//s
		{
			rectfill(buffer, enemy.whb[0], enemy.whb[1] + 4, enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[0], enemy.hb[3], 32, 32);
			player.hb[1] += 32;
		}
		else if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 1))//a
		{
			rectfill(buffer, enemy.whb[0] - 4, enemy.whb[1], enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[0] - 40, enemy.hb[1], 32, 32);
			player.hb[0] -= 32;
		}
		else if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 2))//d
		{
			rectfill(buffer, enemy.whb[0] + 4, enemy.whb[1], enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[2], enemy.hb[1], 32, 32);
			player.hb[0] += 32;
		}
		else if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 3))//w
		{
			rectfill(buffer, enemy.whb[0], enemy.whb[1] - 4, enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[0], enemy.hb[1] - 32, 32, 32);
			player.hb[1] -= 32;
		}
		player.hp[0] -= 2;
		playerValues();
		rest(100);
	}
	return;
}
//*************************************MAIN**********************************************
int main() 
{	
	allegro_init();
	
	//Pre-settings
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	//BMP declaration 
	BITMAP *buffer = create_bitmap(800, 600);
	BITMAP *hitbox = create_bitmap(800, 600);
	BITMAP *textos = create_bitmap(200, 200);
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
	BITMAP *menu = load_bmp("Universe.bmp",NULL);
	BITMAP *instrucciones = load_bmp("Instrucciones.bmp", NULL);
	BITMAP *creditos = load_bmp("Creditos.bmp", NULL);
	BITMAP *muerte = load_bmp("Dead.bmp", NULL);
	//Player & Enemy
 	BITMAP *personaje  = load_bmp("Francis.bmp",NULL);//Fracis pancho
 	BITMAP *aldeano = load_bmp("Viejito.bmp", NULL);
 	BITMAP *lidia = load_bmp("lidia.bmp", NULL);
 	BITMAP *capitan = load_bmp("roderick.bmp", NULL);
 	BITMAP *martha = load_bmp("Martha.bmp", NULL);
 	BITMAP *enemigo = load_bmp("Villano001.bmp", NULL); //Enemiga Rosa
 	BITMAP *ataque = load_bmp("Hit.bmp", NULL);
 	BITMAP *arma = load_bmp("Arma.bmp", NULL);
 	
	//Variable declarations
	clear_to_color(buffer, 0x000000);
	int ax, ay, ex, ey, k = 0, h = 0, i = 0, j = 0, aip = 0, talk = 0;
	
	for(i >= 0; i < 4; i++)
	{
		player.visdir[i] = 32*i;
		if(i != 3)
		{
			player.anima[i] = 32*i;
		}
	}
	i=0;
	for(i >= 0; i < 4; i++)
	{
		enemy.visdir[i] = 32*i; 
		if(i != 3)
		{
			enemy.anima[i] = 32*i;
		}
	}
	player.visdir[0] = 0;
	player.anima[k] = 0;
	enemy.visdir[0] = 0;
	enemy.anima[h] = 0;
	player.direc = 0;
	enemy.direc = 0;
	player.hp[0] = 32;
	player.hb[0] = 290;
	player.hb[1] = 550;
	enemy.hp[0] = 32;
	enemy.hb[0] = 128;
	enemy.hb[1]= 256;
	npc1.hb[0] = 468;
	npc1.hb[1] = 272;
	j = 0;
	int mapa = 1;
	
	playerValues();
	enemyValues();
	npcValues();
	
	//First print
	rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909); // life bar
	rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff); // life bord
	rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
	rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
	rectfill(hitbox, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072); // player hitbox
	rectfill(hitbox, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF); //player-weapon hitbox
	rectfill(hitbox, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
	rectfill(hitbox, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF); //enemy-weapon hitbox
	rectfill(hitbox, npc1.hb[0], npc1.hb[1], npc1.hb[2], npc1.hb[3], 0xFF6A00); //npc hitbox
	
	blit(buffer, screen, 0, 0, 0, 0, 800, 600);
//**************************************MENU*********************************************
	while(!key[KEY_F])
	{
		masked_blit(menu, buffer, 0, 0, 0, 0, 800, 600);
		if(key[KEY_M])
		{
			masked_blit(instrucciones, buffer, 0, 0, 0, 0, 800, 600);
			readkey();
			if(key[KEY_S])
			{
				masked_blit(menu, buffer, 0, 0, 0, 0, 800, 600);
				readkey();	
			}
		}
		if(key[KEY_E])
		{
			masked_blit(creditos, buffer, 0, 0, 0, 0, 800, 600);
			readkey();
			if(key[KEY_S])
			{
				masked_blit(menu, buffer, 0, 0, 0, 0, 800, 600);
				readkey();	
			}
		}
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer);
	}
//**********************************MAIN WHILE*******************************************     
    while(!key[KEY_ESC])
    {
		ax = player.hb[0];
		ay = player.hb[1];
		ex = enemy.hb[0];
		ey = enemy.hb[1];
		
		clear_to_color(buffer, 0xaaaaaa);
		rectfill(hitbox, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player
		rectfill(hitbox, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
		rectfill(hitbox, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
		rectfill(hitbox, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
		rectfill(hitbox, npc1.hb[0], npc1.hb[1], npc1.hb[2], npc1.hb[3], 0xFF6A00);	
//*********************MOVE**************************************************************
		move();
//**************************LIMITS*******************************************************
		/*if((getpixel(hitbox, player.hb[0] -5, player.hb[1] - 5) == 0x00FFFF) || (getpixel(hitbox, player.hb[2] - 5, player.hb[1] - 5) == 0x00FFFF) || (getpixel(hitbox, player.hb[0] - 5, player.hb[3] - 5) == 0x00FFFF) || (getpixel(hitbox, player.hb[2] - 5, player.hb[3] - 5) == 0x00FFFF))
		{
			player.hb[0] = ax;
			player.hb[1] = ay;s
		}*/
		if((getpixel(hitbox, player.hb[0], player.hb[3]) == 0xFF6A00) || (getpixel(hitbox, player.hb[2], player.hb[3]) == 0xFF6A00))
		{
			player.hb[0] = ax;
			player.hb[1] = ay;
		}
		if(mapa == 1)
		{
			if((getpixel(choque1, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque1, player.hb[2], player.hb[3])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
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
//*************************MASKED_BLIT & CHANGE OF MAP001********************************
		if(mapa == 1)
		{
			masked_blit(choque1, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo1, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(aldeano, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer);
			}
			//Interact
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O])&& (talk == 0))
			{
				textout_ex(textos, font, "o para", 24, 4, 0xffffff, 0x000000);
				textout_ex(textos, font, "interactuar", 0, 14, 0xffffff, 0x000000);
				blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 100, 25);
				if(key[KEY_O])
				{
					clear_bitmap(textos);
				}
			}
			//Dialogues
			while ((key[KEY_O]) && (getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (talk == 0))
			{
				readkey();
				clear_keybuf();
				if(key[KEY_O])
				{
					textout_ex(textos, font, "Oh, que dia", 0, 4, 0xffffff, 0x000000);
					textout_ex(textos, font, "tan tranquilo", 0, 14, 0xffffff, 0x000000);
					textout_ex(textos, font, "en nuestra aldea", 0, 24, 0xffffff, 0x000000);
					blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20,  128, 34);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						clear_bitmap(textos);
						textout_ex(textos, font, "¡Rrraaaargh!", 0, 4, 0xffffff, 0x000000);
						textout_ex(textos, font, "¡Vengo a sembrar", 0, 14, 0xffffff, 0x000000);
						textout_ex(textos, font, "el caos en este", 0, 24, 0xffffff, 0x000000);
						textout_ex(textos, font, "lugar pacifico!", 0, 32, 0xffffff, 0x000000);
						blit(textos, screen,  0, 0, enemy.hb[2] + 15, enemy.hb[1] - 20,  128, 44);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							clear_bitmap(textos);
							textout_ex(textos, font, "¡Detente ahi,", 0, 4, 0xffffff, 0x000000);
							textout_ex(textos, font, "monstruo!", 0, 14, 0xffffff, 0x000000);
							textout_ex(textos, font, "No permitire", 0, 24, 0xffffff, 0x000000);
							textout_ex(textos, font, "que hagas dano", 0, 32, 0xffffff, 0x000000);
							blit(textos, screen,  0, 0, player.hb[2] + 15, player.hb[1] - 20,  128, 44);
							readkey();
							clear_keybuf();
							if(!key[KEY_0])
							{
								talk = 1;
							}
						}
					}
				}
				clear_bitmap(textos);
			}
			//change of Map
			if(getpixel(choque1, player.hb[0], player.hb[1]) == 0x00FFFF)
			{
				mapa = 2;
				player.hb[0] = 420;
				player.hb[1] = 560;
				npc1.hb[0] = 413;
				npc1.hb[1] = 492;
				if(talk == 0)
				{
					talk = 2;
					enemy.hp[0] = 0;
				}
				if(talk == 1)
				{
					talk = 0;
					j = 0;
					enemy.hp[0] = 32;
					enemy.hb[0] = 272;
					enemy.hb[1]= 15;
				}
			}
		}
//*************************MASKED_BLIT & CHANGE OF MAP002********************************
		if(mapa == 2)
		{
			masked_blit(choque2, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo2, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(lidia, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer);
			}
			//************Interact I*****************************************************
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == 0))
			{
				textout_ex(textos, font, "o para", 24, 4, 0xffffff, 0x000000);
				textout_ex(textos, font, "interactuar", 0, 14, 0xffffff, 0x000000);
				blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 100, 25);
				if(key[KEY_O])
				{
					clear_bitmap(textos);
				}
			}
			//************Dialogues I***************************************************
			while ((key[KEY_O]) && (getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (talk == 0))
			{
				readkey();
				clear_keybuf();
				if(key[KEY_O])
				{
					textout_ex(textos, font, "¿Como se supone", 0, 4, 0xffffff, 0x000000);
					textout_ex(textos, font, "que llegue al", 0, 14, 0xffffff, 0x000000);
					textout_ex(textos, font, "castillo?", 0, 24, 0xffffff, 0x000000);
					blit(textos, screen,  0, 0, player.hb[2] + 15, player.hb[1] - 20,  128, 34);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						clear_bitmap(textos);
						textout_ex(textos, font, "Yo puedo llevarte,", 0, 4, 0xffffff, 0x000000);
						textout_ex(textos, font, "pero te pedire", 0, 14, 0xffffff, 0x000000);
						textout_ex(textos, font, "algo a cambio", 0, 24, 0xffffff, 0x000000);
						blit(textos, screen,  0, 0, npc1.hb[2] + 15,npc1.hb[1] - 20,  136, 34);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							clear_bitmap(textos);
							textout_ex(textos, font, "en verdad tengo", 0, 4, 0xffffff, 0x000000);
							textout_ex(textos, font, "que ir a ayudar,", 0, 14, 0xffffff, 0x000000);
							textout_ex(textos, font, "asi que dime", 0, 24, 0xffffff, 0x000000);
							textout_ex(textos, font, "¿Que necesitas?", 0, 32, 0xffffff, 0x000000);
							blit(textos, screen,  0, 0, player.hb[2] + 15, player.hb[1] - 20,  130, 44);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								clear_bitmap(textos);
								textout_ex(textos, font, "Ve a la aldea", 0, 4, 0xffffff, 0x000000);
								textout_ex(textos, font, "del NORTE y ", 0, 14, 0xffffff, 0x000000);
								textout_ex(textos, font, "derrota a los", 0, 24, 0xffffff, 0x000000);
								textout_ex(textos, font, "invasores", 0, 32, 0xffffff, 0x000000);
								blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20,  130, 44);
								readkey();
								clear_keybuf();
								if(!key[KEY_0])
								{
									talk = 1;
								}
							}
							
						}
					}
				}
				clear_bitmap(textos);
			}
			//************Interact II****************************************************
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == -1))
			{
				textout_ex(textos, font, "o para", 24, 4, 0xffffff, 0x000000);
				textout_ex(textos, font, "interactuar", 0, 14, 0xffffff, 0x000000);
				blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 100, 25);
				if(key[KEY_O])
				{
					clear_bitmap(textos);
				}
			}
			//************Dialogues II***************************************************
			while ((key[KEY_O]) && (getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (talk == -1))
			{
				readkey();
				clear_keybuf();
				if(key[KEY_O])
				{
					textout_ex(textos, font, "Listo, ahora", 0, 4, 0xffffff, 0x000000);
					textout_ex(textos, font, "¿Como llego", 0, 14, 0xffffff, 0x000000);
					textout_ex(textos, font, "al castillo?", 0, 24, 0xffffff, 0x000000);
					blit(textos, screen,  0, 0, player.hb[2] + 15, player.hb[1] - 20,  98, 34);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						clear_bitmap(textos);
						textout_ex(textos, font, "Antes tienes que", 0, 4, 0xffffff, 0x000000);
						textout_ex(textos, font, "salvar al capitan,", 0, 14, 0xffffff, 0x000000);
						textout_ex(textos, font, "esta en problemas", 0, 24, 0xffffff, 0x000000);
						blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20,  146, 34);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							clear_bitmap(textos);
							textout_ex(textos, font, "El lleva mucho", 0, 4, 0xffffff, 0x000000);
							textout_ex(textos, font, "peleando en el", 0, 14, 0xffffff, 0x000000);
							textout_ex(textos, font, "SURESTE, corre", 0, 24, 0xffffff, 0x000000);
							blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20,  146, 34);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								clear_bitmap(textos);
								textout_ex(textos, font, "Lo hare,", 0, 4, 0xffffff, 0x000000);
								textout_ex(textos, font, "espero que", 0, 14, 0xffffff, 0x000000);
								textout_ex(textos, font, "no sea muy", 0, 24, 0xffffff, 0x000000);
								textout_ex(textos, font, "tarde", 0, 32, 0xffffff, 0x000000);
								blit(textos, screen,  0, 0, player.hb[2] + 15, player.hb[1] - 20,  98, 44);
								readkey();
								clear_keybuf();
								if(!key[KEY_0])
								{
									talk = 1;
								}
							}
							
						}
					}
				}
				clear_bitmap(textos);
			}
			//************Interact III****************************************************
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == 4))
			{
				textout_ex(textos, font, "o para", 24, 4, 0xffffff, 0x000000);
				textout_ex(textos, font, "interactuar", 0, 14, 0xffffff, 0x000000);
				blit(textos, screen,  0, 0, npc1.hb[0], npc1.hb[1] - 40, 100, 25);
				if(key[KEY_O])
				{
					clear_bitmap(textos);
				}
			}
			//************Dialogues III***************************************************
			while ((key[KEY_O]) && (getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (talk == 4))
			{
				readkey();
				clear_keybuf();
				if(key[KEY_O])
				{
					textout_ex(textos, font, "¿Como esta el", 0, 4, 0xffffff, 0x000000);
					textout_ex(textos, font, "Capitan?", 0, 14, 0xffffff, 0x000000);
					blit(textos, screen,  0, 0, npc1.hb[0], npc1.hb[1] - 40,  106, 34);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						clear_bitmap(textos);
						textout_ex(textos, font, "Bien, pero ya no", 0, 4, 0xffffff, 0x000000);
						textout_ex(textos, font, "le quedan fuerzas,", 0, 14, 0xffffff, 0x000000);
						textout_ex(textos, font, "tengo que irme.", 0, 24, 0xffffff, 0x000000);
						blit(textos, screen,  0, 0, player.hb[0], player.hb[3] + 10,  146, 34);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							clear_bitmap(textos);
							textout_ex(textos, font, "El reino esta al", 0, 4, 0xffffff, 0x000000);
							textout_ex(textos, font, "ESTE, no puedo", 0, 14, 0xffffff, 0x000000);
							textout_ex(textos, font, "acompañarte", 0, 24, 0xffffff, 0x000000);
							blit(textos, screen,  0, 0, npc1.hb[0], npc1.hb[1] - 40,  146, 34);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								clear_bitmap(textos);
								textout_ex(textos, font, "Te deseso", 0, 4, 0xffffff, 0x000000);
								textout_ex(textos, font, " suerte ", 0, 14, 0xffffff, 0x000000);
								blit(textos, screen,  0, 0, npc1.hb[0], npc1.hb[1] - 40,  146, 34);
								readkey();
								clear_keybuf();
								if(!key[KEY_0])
								{
									talk = 1;
								}
							}
							
						}
					}
				}
				clear_bitmap(textos);
			}
			//Change of map
			if ((getpixel(choque2, player.hb[2], player.hb[3]) == 0x00FFFF)) //Back to MAP001
			{
				player.hb[0] = 400;
				player.hb[1] = 20;
				mapa = 1;
				npc1.hb[0] = 468;
				npc1.hb[1] = 272;
				if(talk == 2)
				{
					talk = 0;
					j = 0;  
					enemy.hp[0] = 32;
					enemy.hb[0] = 128;
					enemy.hb[1]= 256;
				}
			}
			else if ((getpixel(choque2, player.hb[0], player.hb[1]) == 0x00FF00) && (talk != 2))//Go to MAP003
			{
				mapa = 3;
				player.hb[0] = 330;
				player.hb[1] = 550;
				npc1.hb[0] = 264;
				npc1.hb[1] = 141;
				if(player.hp[0] < 20)
				{
					player.hp[0] = 30;
				}
				if(talk == 1)
				{
					talk = 0;
					j = 0;
					enemy.hp[0] = 32;
					enemy.hb[0] = 321;
					enemy.hb[1] = 167;
				}
			}
			else if ((getpixel(choque2, player.hb[2], player.hb[3]) == 0xFF00FF) && (talk != 2))//Go to MAP004
			{
				mapa = 4;
				player.hb[0] = 25;
				player.hb[1] = 100;
				if(talk == 1)
				{
					talk = 0;
					j = 0;
					enemy.hp[0] = 32;
					enemy.hb[0] = 511;
					enemy.hb[1] = 382;
					npc1.hb[0] = 338;
					npc1.hb[1] = 378;
				}
			}
			else if ((getpixel(choque2, player.hb[2], player.hb[3]) == 0xFF0000) && (talk != 2))//Go to MAP005
			{
				mapa = 5;
				player.hb[0] = 14;
				player.hb[1] = 411;
				if(talk == 1)
				{
					talk = 1;
					j = 0;
					enemy.hp[0] = 32;
					enemy.hb[0] = 549;
					enemy.hb[1] = 96;
				}
			}
		}
//*************************MASKED_BLIT & CHANGE OF MAP003********************************
		if(mapa == 3)
		{
			masked_blit(choque3, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo3, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
			masked_blit(martha, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}	
			if ((talk == 0) && (enemy.hp[0] > 0) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer);
				textout_ex(textos, font, "ALGUIEN SALVEMEEE", 0, 4, 0xffffff, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 138, 18);
			}
			if(enemy.hp[0] <= 0)
			{
				talk = 1;
				textout_ex(textos, font, "  GRACIAAAS  ", 0, 4, 0xffffff, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 104, 18);
			}
			if(player.hp[0] <= 0)
			{
				talk = 1;
				textout_ex(textos, font, "   OH NOOOO  ", 0, 4, 0xffffff, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 104, 18);
			}
			//cambio de mapa
			if(getpixel(choque3, player.hb[0], player.hb[3]) == 0x00FF00)
			{
				talk = -1;
				mapa = 2;
				player.hb[0] = 320;
				player.hb[1] = 10;
				npc1.hb[0] = 413;
				npc1.hb[1] = 492;
				clear_bitmap(textos);
			}
		}
//*************************MASKED_BLIT & CHANGE OF MAP004********************************
		if (mapa == 4)
		{
			masked_blit(choque4, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo4, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
			masked_blit(capitan, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}
			if (talk == 0)
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer);
				textout_ex(textos, font, "¡cof!, ¡cof!…", 0, 4, 0xffffff, 0x000000);
				textout_ex(textos, font, "¡Los derrotare!", 0, 14, 0xffffff, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 122, 25);
			}
			//************Interact I*****************************************************
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == 0))
			{
				clear_bitmap(textos);
				textout_ex(textos, font, "o para", 24, 4, 0xffffff, 0x000000);
				textout_ex(textos, font, "interactuar", 0, 14, 0xffffff, 0x000000);
				blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 122, 25);
				if(key[KEY_O])
				{
					clear_bitmap(textos);
				}
			}
			//************Dialogues I****************************************************
			while ((key[KEY_O]) && (getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (talk == 0))
			{
				readkey();
				clear_keybuf();
				if(key[KEY_O])
				{
					textout_ex(textos, font, "Gracias muchacho,", 0, 4, 0xffffff, 0x000000);
					textout_ex(textos, font, "¿Cual es tu nombre?", 0, 14, 0xffffff, 0x000000);
					textout_ex(textos, font, "No eres de aqui", 0, 24, 0xffffff, 0x000000);
					blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 152, 34);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						clear_bitmap(textos);
						textout_ex(textos, font, "Mi nombre es Isaac", 0, 4, 0xffffff, 0x000000);
						textout_ex(textos, font, "soy un viajero,", 0, 14, 0xffffff, 0x000000);
						textout_ex(textos, font, "busco a la reina", 0, 24, 0xffffff, 0x000000);
						blit(textos, screen,  0, 0, player.hb[0], player.hb[3] + 15,  146, 34);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							clear_bitmap(textos);
							textout_ex(textos, font, "Ella debe estar", 0, 4, 0xffffff, 0x000000);
							textout_ex(textos, font, "en problemas", 0, 14, 0xffffff, 0x000000);
							textout_ex(textos, font, "ve en mi lugar", 0, 24, 0xffffff, 0x000000);
							blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 152, 34);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								clear_bitmap(textos);
								textout_ex(textos, font, "Estare bien pero", 0, 4, 0xffffff, 0x000000);
								textout_ex(textos, font, "date prisa ¡cof!", 0, 14, 0xffffff, 0x000000);
								textout_ex(textos, font, "no se de donde", 0, 24, 0xffffff, 0x000000);
								textout_ex(textos, font, "salieron, pero", 0, 32, 0xffffff, 0x000000);
								textout_ex(textos, font, "son peligrosos", 0, 40, 0xffffff, 0x000000);
								blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20,  152, 52);
								readkey();
								clear_keybuf();
								if(!key[KEY_0])
								{
									talk = 1;
								}
							}
							
						}
					}
				}
				clear_bitmap(textos);
			}
			//cambio de mapa
			if(getpixel(choque4, player.hb[0], player.hb[1]) == 0xFF00FF)
			{
				mapa = 2;
				player.hb[0] = 626;
				player.hb[1] = 555;
				npc1.hb[0] = 413;
				npc1.hb[1] = 492;
				if(player.hp[0] < 20)
				{
					player.hp[0] = 30;
				}
				if(talk == 1)
				{
					talk = 4;
				}
			}
		}
//*************************MASKED_BLIT & CHANGE OF MAP005********************************
		if (mapa == 5)
		{
			masked_blit(choque5, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo5, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
			if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}	    	
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}
			//cambio de mapa
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer);
			}
			//cambio de mapa
			if(getpixel(choque5, player.hb[0], player.hb[3]) == 0x00FFFF)
			{
				mapa = 2;
				talk = 3;
				player.hb[0] = 748;
				player.hb[1] = 305;
				npc1.hb[0] = 413;
				npc1.hb[1] = 492;
				enemy.hp[0] = 0;
			}
			else if (getpixel(choque5, player.hb[2], player.hb[3]) == 0x00FF00)
			{
				mapa = 6;
				player.hb[0] = 12;
				player.hb[1] = 310;
				if(player.hp[0] < 20)
				{
					player.hp[0] = 30;
				}
				if(talk == 1)
				{
					talk = 1;
					j = 0;
					enemy.hp[0] = 32;
					enemy.hb[0] = 383;
					enemy.hb[1] = 253;
				}
			}
		}
//*************************MASKED_BLIT & CHANGE OF MAP006********************************
		if(mapa == 6)
		{
			masked_blit(choque6, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo6, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
			if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}
			//cambio de mapa
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer);
			}
			//cambio de mapa
			if(getpixel(choque6, player.hb[0], player.hb[1]) == 0xFF00FF)
			{
				mapa = 7;
				player.hb[0] = 374;
				player.hb[1] = 535;
				player.hp[0] = 32;
				if(talk == 1)
				{
					talk = 1;
					j = 0;
					enemy.hp[0] = 32;
					enemy.hb[0] = 383;
					enemy.hb[1] = 253;
				}
			}
			else if(getpixel(choque6, player.hb[0], player.hb[1]) == 0x00FF00)
			{
				mapa = 5;
				talk = 0;
				player.hb[0] = 760;
				player.hb[1] = 93;
				enemy.hp[0] = 0;
			}
		}
//*************************MASKED_BLIT & CHANGE OF MAP007********************************
		if(mapa == 7)
		{
			masked_blit(choque7, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo7, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
	    	if(player.hp[0] > 0)
			{
				rectfill(buffer, player.whb[0], player.whb[1], player.whb[2], player.whb[3], 0x0026FF);
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] != 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.whb[0], enemy.whb[1], enemy.whb[2], enemy.whb[3], 0x0026FF);
			}
			//cambio de mapa
			if(getpixel(choque7, player.hb[2], player.hb[3]) == 0xFF0000)
			{
				mapa = 6;
				talk = 3;
				player.hb[0] = 466;
				player.hb[1] = 36;
				enemy.hp[0] = 0;
			}
		}
//****************************LIFE BAR***************************************************
		npcValues();
		enemyValues();
		playerValues();
		rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909);//player lifebar (hp)
		rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff);//player lifebar (box)
		rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
		rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
		rectfill(buffer, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player
		rectfill(buffer, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
		rectfill(buffer, npc1.hb[0], npc1.hb[1], npc1.hb[2], npc1.hb[3], 0xFF6A00);
//********************MOVE UPDATE********************************************************
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
			h++;
			if(h > 2)
			{ 
				h = 0;
			}
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
			masked_blit(muerte, buffer, 0, 0, 0, 200, 800, 200);
		}
//****************************MAIN BLIT**************************************************
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer);
    	clear_bitmap(hitbox);
    }
    //Close of program
    destroy_bitmap(choque1);
    destroy_bitmap(fondo1);
    destroy_bitmap(buffer);
	return 0;
}
END_OF_MAIN();
