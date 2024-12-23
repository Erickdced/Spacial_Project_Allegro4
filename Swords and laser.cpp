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
  	int money;
  	int potion;
  	int xlog[8];
  	int ylog[8];
  	int midx;
  	int midy;
};
struct player player;
struct player npc1;
struct player enemy;
struct player atack;
struct player boss;

//act of player 
void playerValues ()
{
	player.hb[2] = player.hb[0] + 32; //Player x2 acctualization
	player.hb[3] = player.hb[1] + 32; //Player y2 actualization
	player.hp[1] = player.hb[0];	  //lifebar x1 & lifebox x1 
	player.hp[2] = player.hb[1] - 8;  //lifebar y1 & lifebox y1
	player.hp[3] = player.hp[1] + 32; //lifebox x2
	player.hp[4] = player.hp[2] + 4;  //lifebox y2 & lifebar y2
	player.midx = (player.hb[0] + player.hb[2]) / 2;
	player.midy = (player.hb[1] + player.hb[3]) / 2;
	
	
	//Weapon direction
	if(player.direc == 0) // key s, Down direction
	{
		player.whb[0] = player.hb[0] + 14;	//x1
		player.whb[2] = player.hb[0] + 18;	//x2
		player.whb[1] = player.hb[3] + 8;	//y1
		player.whb[3] = player.hb[3];		//y2
    }
    if(player.direc == 1) // key a, Right direction
    {
		player.whb[0] = player.hb[0] - 8;	//x1
		player.whb[2] = player.hb[0];   	//x2
		player.whb[1] = player.hb[1] + 14; 	//y1
		player.whb[3] = player.hb[1] + 18;	//y2
	}
	if(player.direc == 2) // key d, Left direction
	{
		player.whb[0] = player.hb[2] + 8;	//x1
		player.whb[2] = player.hb[2];   	//z2
		player.whb[1] = player.hb[1] + 14; 	//y1
		player.whb[3] = player.hb[1] + 18;	//y2
	}
	if(player.direc == 3) // key w, Up direction
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
	enemy.hb[2] = enemy.hb[0] + 32; //x2 actualization
	enemy.hb[3] = enemy.hb[1] + 32; //y2 actualization
	enemy.hp[1] = enemy.hb[0];		//enemy lifebar & lifebox x1
	enemy.hp[2] = enemy.hb[1] - 8;	//enemy lifebar & lifebox y1
	enemy.hp[3] = enemy.hp[1] + 32;	//enemy lifebox x2
	enemy.hp[4] = enemy.hp[2] + 4;  //enemy lifebar & lifebox y2
	//Weapon direction
	if(enemy.direc == 0) //Down follow
	{
		enemy.whb[0] = enemy.hb[0] + 14;	//x1
		enemy.whb[2] = enemy.hb[0] + 18;	//x2
		enemy.whb[1] = enemy.hb[3] + 8;		//y1
		enemy.whb[3] = enemy.hb[3];			//y2
    }
    if(enemy.direc == 1) //Right follow
    {
		enemy.whb[0] = enemy.hb[0] - 8;		//x1
		enemy.whb[2] = enemy.hb[0];   		//x2
		enemy.whb[1] = enemy.hb[1] + 14; 	//y1
		enemy.whb[3] = enemy.hb[1] + 18;	//y2
	}
	if(enemy.direc == 2) //Left follow
	{
		enemy.whb[0] = enemy.hb[2] + 8;		//x1
		enemy.whb[2] = enemy.hb[2];   		//z2
		enemy.whb[1] = enemy.hb[1] + 14; 	//y1
		enemy.whb[3] = enemy.hb[1] + 18;	//y2
	}
	if(enemy.direc == 3) //Up follow
	{
		enemy.whb[0] = enemy.hb[0] + 14;	//x1
		enemy.whb[2] = enemy.hb[0] + 18;	//x2
		enemy.whb[1] = enemy.hb[1] - 8;		//y1
		enemy.whb[3] = enemy.hb[1];			//y2
	}		
}
void bossValues ()
{
	boss.hb[2] = boss.hb[0] + 64; 	//x2 actualization
	boss.hb[3] = boss.hb[1] + 64; 	//y2 actualization
	boss.hp[1] = boss.hb[0];		//enemy lifebar & lifebox x1
	boss.hp[2] = boss.hb[1] - 8;	//enemy lifebar & lifebox y1
	boss.hp[3] = boss.hp[1] + 64;	//enemy lifebox x2
	boss.hp[4] = boss.hp[2] + 4; 	//enemy lifebar & lifebox y2
	//weapon direction
	if(boss.direc == 0) //down follow
	{
		boss.whb[0] = boss.hb[0] + 28;	//x1
		boss.whb[2] = boss.hb[0] + 36;	//x2
		boss.whb[1] = boss.hb[3] + 16;	//y1
		boss.whb[3] = boss.hb[3];		//y2
    }
    if(boss.direc == 1) //right follow
    {
		boss.whb[0] = boss.hb[0] - 16;	//x1
		boss.whb[2] = boss.hb[0];   	//x2
		boss.whb[1] = boss.hb[1] + 28; 	//y1
		boss.whb[3] = boss.hb[1] + 36;	//y2
	}
	if(boss.direc == 2) //left follow
	{
		boss.whb[0] = boss.hb[2] + 16;	//x1
		boss.whb[2] = boss.hb[2];   	//z2
		boss.whb[1] = boss.hb[1] + 28; 	//y1
		boss.whb[3] = boss.hb[1] + 36;	//y2
	}
	if(boss.direc == 3) //up follow
	{
		boss.whb[0] = boss.hb[0] + 28;	//x1
		boss.whb[2] = boss.hb[0] + 36;	//x2
		boss.whb[1] = boss.hb[1] - 16;	//y1
		boss.whb[3] = boss.hb[1];		//y2
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
//enemy loot
void enemyLoot ()
{
	player.money += (rand() % 4) + 1;
}
void bossDead ()
{
	boss.hb[0] = 0;
	boss.hb[1] = 0;
	boss.hb[2] = 0;
	boss.hb[3] = 0;
	boss.hp[1] = 0;
	boss.hp[2] = 0;
	boss.hp[3] = 0;
	boss.hp[4] = 0;
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
void boss_pursuit(int bj)
{
	if((player.hb[2] + 4) < boss.hb[0] &&  bj == 0)//facing right
	{
		boss.hb[0] = boss.hb[0] - 4; 
		bossValues();
		boss.direc = 1;
	}
	else if((player.hb[3] + 4) < boss.hb[1] && bj == 0) //facing  up
	{
		boss.hb[1] = boss.hb[1] - 4;
		bossValues();
		boss.direc = 3;
	}
	else if((player.hb[0] - 4) > boss.hb[2] && bj == 0) //facing left
	{
		boss.hb[0] = boss.hb[0] + 4;
		bossValues();
		boss.direc = 2;
	}
	else if((player.hb[1] - 4) > boss.hb[3] && bj == 0)//facing down
	{
		boss.hb[1] = boss.hb[1] + 4;
		bossValues();
		boss.direc = 0;
	}
	return;
}
void move() //actualization of player values for the blit of the correct frame of the animation
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
void enemyAttack(BITMAP *hitbox, BITMAP *ataque, BITMAP *buffer) //enemy following and his weapong hitbox 
{
	if(getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072)
	{
		if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 0))//facing down
		{
			rectfill(buffer, enemy.whb[0], enemy.whb[1] + 4, enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[0], enemy.hb[3], 32, 32);
			player.hb[1] += 32;
		}
		else if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 1))//facing right
		{
			rectfill(buffer, enemy.whb[0] - 4, enemy.whb[1], enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[0] - 40, enemy.hb[1], 32, 32);
			player.hb[0] -= 32;
		}
		else if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 2))//facing left
		{
			rectfill(buffer, enemy.whb[0] + 4, enemy.whb[1], enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[2], enemy.hb[1], 32, 32);
			player.hb[0] += 32;
		}
		else if((getpixel(hitbox, enemy.whb[0], enemy.whb[1]) == 0xff0072) && (enemy.direc == 3))//facing up
		{
			rectfill(buffer, enemy.whb[0], enemy.whb[1] - 4, enemy.whb[2], enemy.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, enemy.hb[0], enemy.hb[1] - 32, 32, 32);
			player.hb[1] -= 32;
		}
		player.hp[0] -= 1;
		playerValues();
		rest(100);
	}
	return;
}
void playerAttack(BITMAP *hitbox, BITMAP *ataque, BITMAP *buffer, int mapa) //Player weapon sistem and his range
{
	if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (key[KEY_P]))
	{
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 0))//facing down
		{
			rectfill(buffer, player.whb[0], player.whb[1] + 4, player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[0], player.hb[3], 32, 32);
			if (mapa == 7)
			{
				boss.hb[1] += 16;
			} 
			else
			{
				enemy.hb[1] += 32;
			}
		}
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 1))//facing right
		{
			rectfill(buffer, player.whb[0] - 4, player.whb[1], player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[0] - 40, player.hb[1], 32, 32);
			
			if (mapa == 7)
			{
				boss.hb[0] -= 16;
			}
			else
			{
				enemy.hb[0] -= 32;
			}
		}
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 2))//facing left
		{
			rectfill(buffer, player.whb[0] + 4, player.whb[1], player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[2], player.hb[1], 32, 32);
			if (mapa == 7)
			{
				boss.hb[0] += 16;
			}
			else
			{
				enemy.hb[0] += 32;
			}
		}
		if((getpixel(hitbox, player.whb[0], player.whb[1]) == 0x00FFFF) && (player.direc == 3))//facing up
		{
			rectfill(buffer, player.whb[0], player.whb[1] - 4, player.whb[2], player.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, player.hb[0], player.hb[1] - 32, 32, 32);
			if (mapa == 7)
			{
				boss.hb[1] -= 16;
			}
			else
			{
				enemy.hb[1] -= 32;
			}
		}
		enemy.hp[0] -= 4;
		if (mapa == 7)
		{
			boss.hp[0] -= 4;
		}
		enemyValues();
		bossValues();
		rest(50);
	}
	return;
}
void bossAttack(BITMAP *hitbox, BITMAP *ataque, BITMAP *buffer) //boss weapon hitbox and damage for the player
{
	if((getpixel(hitbox, boss.whb[0], boss.whb[1]) == 0xff0072))
	{
		if((getpixel(hitbox, boss.whb[0], boss.whb[1]) == 0xff0072) && (boss.direc == 0))//facing down
		{
			rectfill(buffer, boss.whb[0], boss.whb[1] + 4, boss.whb[2], boss.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, boss.hb[0], boss.hb[3], 32, 32);
			player.hb[1] += 16;
		}
		else if((getpixel(hitbox, boss.whb[0], boss.whb[1]) == 0xff0072) && (boss.direc == 1))//facing right
		{
			rectfill(buffer, boss.whb[0] - 4, boss.whb[1], boss.whb[2], boss.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, boss.hb[0], boss.hb[3], 32, 32);
			player.hb[0] -= 16;
		}
		else if((getpixel(hitbox, boss.whb[0], boss.whb[1]) == 0xff0072) && (boss.direc == 2))//facing left
		{
			rectfill(buffer, boss.whb[0] - 4, boss.whb[1], boss.whb[2], boss.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, boss.hb[0], boss.hb[3], 32, 32);
			player.hb[0] += 16;
		}
		else if((getpixel(hitbox, boss.whb[0], boss.whb[1]) == 0xff0072) && (boss.direc == 3))//facing up
		{
			rectfill(buffer, boss.whb[0], boss.whb[1] - 4,boss.whb[2], boss.whb[3], 0xD7D1D1);
			rest(30);
			masked_blit(ataque, buffer, 64, 0, boss.hb[0], boss.hb[3], 32, 32);
			player.hb[1] -= 16;
		}
		player.hp[0] -= 1;
		playerValues();
		rest(100);
	}
	return;
}

/*Verification of your position in map*/
int position () 
{
	int posValue;
	if(player.midx < 0 || player.midx > 800 || player.midy < 0 || player.midy > 600)
	{
		posValue = 1;
	}
	else
	{
		posValue = 0;
	}
	return posValue;
}

/*************************************MAIN**********************************************/
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
	BITMAP *textos = create_bitmap(341, 91);
	BITMAP *dialogos = create_bitmap(341, 91);
	
//Fondos y choques
	BITMAP *fondo1 = load_bmp("Map001.bmp", NULL);//mapa 1
	BITMAP *fondo2 = load_bmp("Map002.bmp", NULL);//mapa 2
	BITMAP *fondo3 = load_bmp("Map003.bmp", NULL);//mapa 3
	BITMAP *fondo4 = load_bmp("Map004.bmp", NULL);//mapa 4
	BITMAP *fondo5 = load_bmp("Map005.bmp", NULL);//mapa 5
	BITMAP *fondo6 = load_bmp("Map006.bmp", NULL);//mapa 6
	BITMAP *fondo7 = load_bmp("Map007.bmp", NULL);//mapa 7
	
	BITMAP *choque1 = load_bmp("Choque001.bmp", NULL);// hitboxes mapa 1
	BITMAP *choque2 = load_bmp("Choque002.bmp", NULL);// hitboxes mapa 2
	BITMAP *choque3 = load_bmp("Choque003.bmp", NULL);// hitboxes mapa 3
	BITMAP *choque4 = load_bmp("Choque004.bmp", NULL);// hitboxes mapa 4
	BITMAP *choque5 = load_bmp("Choque005.bmp", NULL);// hitboxes mapa 5
	BITMAP *choque6 = load_bmp("Choque006.bmp", NULL);// hitboxes mapa 6
	BITMAP *choque7 = load_bmp("Choque007.bmp", NULL);// hitboxes mapa 7
	
	BITMAP *menu = load_bmp("Universe.bmp",NULL); //initial background
	BITMAP *instrucciones = load_bmp("Instrucciones.bmp", NULL); //player instructions
	BITMAP *creditos = load_bmp("Creditos.bmp", NULL); //credits of the creators
	BITMAP *muerte = load_bmp("Dead.bmp", NULL); //the fatal message
//Dialogos
	BITMAP *M1D1 = load_bmp("M1D1.bmp", NULL); 
	BITMAP *M1D2 = load_bmp("M1D2.bmp", NULL);
	
	BITMAP *M2D1 = load_bmp("M2D1.bmp", NULL);
	BITMAP *M2D2 = load_bmp("M2D2.bmp", NULL);
	BITMAP *M2D3 = load_bmp("M2D3.bmp", NULL);
	BITMAP *M2D4 = load_bmp("M2D4.bmp", NULL);
	BITMAP *M2D5 = load_bmp("M2D5.bmp", NULL);
	BITMAP *M2D6 = load_bmp("M2D6.bmp", NULL);
	BITMAP *M2D7 = load_bmp("M2D7.bmp", NULL);
	BITMAP *M2D8 = load_bmp("M2D8.bmp", NULL);
	BITMAP *M2D9 = load_bmp("M2D9.bmp", NULL);
	BITMAP *M2D10 = load_bmp("M2D10.bmp", NULL);
	BITMAP *M2D11 = load_bmp("M2D11.bmp", NULL);
	BITMAP *M2D12 = load_bmp("M2D12.bmp", NULL);
	BITMAP *M2D13 = load_bmp("M2D13.bmp", NULL);
	
	BITMAP *M4D1 = load_bmp("M4D1.bmp", NULL);
	BITMAP *M4D2 = load_bmp("M4D2.bmp", NULL);
	BITMAP *M4D3 = load_bmp("M4D3.bmp", NULL);
	BITMAP *M4D4 = load_bmp("M4D4.bmp", NULL);
		
	BITMAP *dialogo = load_bmp("Dialogo.bmp", NULL);
//Player & Enemy
 	BITMAP *personaje  = load_bmp("Francis.bmp",NULL);//Fracis pancho
 	BITMAP *aldeano = load_bmp("Viejito.bmp", NULL);
 	BITMAP *lidia = load_bmp("Random1.bmp", NULL);
 	BITMAP *capitan = load_bmp("roderick.bmp", NULL);
 	BITMAP *enemigo = load_bmp("Villano001.bmp", NULL); //Enemiga Rosa
 	BITMAP *jefe = load_bmp("Boss.bmp", NULL);
 	BITMAP *ataque = load_bmp("Hit.bmp", NULL);
 	BITMAP *arma = load_bmp("Arma.bmp", NULL);
 	
//HUD elements 
 	BITMAP *icons = load_bmp("Icons.bmp", NULL);
 	BITMAP *pjicon = load_bmp("PJicon.bmp", NULL);
 	BITMAP *numbers = load_bmp("Numbers.bmp", NULL);
 	
//initial coords
 	player.xlog[0] = 364;
 	player.ylog[0] = 536;
 	player.xlog[1] = 400;
 	player.ylog[1] = 300;
 	player.xlog[2] = 330;
 	player.ylog[2] = 550;
	player.xlog[3] = 510;
 	player.ylog[3] = 382;
	player.xlog[4] = 14;
 	player.ylog[4] = 411;
	player.xlog[5] = 12;
 	player.ylog[5] = 310;	
 	player.xlog[6] = 374;
	player.ylog[6] = 535;
//Variable declarations
	clear_to_color(buffer, 0x000000);
	int ax, ay, ex, ey, bx, by, k = 0, h = 0, eh = 0, i = 0, j = 0, bj = 0, aip = 0, talk = 0;
	
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
	i=0;
	for(i >= 0; i < 4; i++)
	{
		boss.visdir[i] = 64*i; 
		if(i != 3)
		{
			boss.anima[i] = 64*i;
		}
	}
	
	player.visdir[0] = 0;
	player.anima[k] = 0;
	enemy.visdir[0] = 0;
	enemy.anima[h] = 0;
	boss.visdir[0] = 0;
	boss.anima[eh] = 0;
	player.direc = 0;
	enemy.direc = 0;
	boss.direc = 0;
	player.hp[0] = 32;
	player.hb[0] = 364;
	player.hb[1] = 536;
	enemy.hp[0] = 32;
	enemy.hb[0] = 128;
	enemy.hb[1]= 256;
	boss.hp[0] = 0;
	boss.hb[0] = 383;
	boss.hb[1]= 253;
	npc1.hb[0] = 468;
	npc1.hb[1] = 272;
	
	j = 0;
	int mapa = 1;
	int letter = 8;
	int posValue = 0;
	
	playerValues();
	enemyValues();
	npcValues();
	
//First print
	rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909); // life bar
	rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff); // life bord
	rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
	rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
	rectfill(hitbox, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072); // player hitbox
	rectfill(hitbox, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
	rectfill(hitbox, npc1.hb[0], npc1.hb[1], npc1.hb[2], npc1.hb[3], 0xFF6A00); //npc hitbox
	rectfill(hitbox, boss.hb[0], boss.hb[1], boss.hb[2], boss.hb[3], 0x00FFFF);// boss Hitbox
				rectfill(hitbox, boss.whb[0], boss.whb[1], boss.whb[2], boss.whb[3], 0x0026FF);//boss-weapon Hitbox
	rectfill(buffer, boss.hp[1], boss.hp[2], boss.hp[1] + boss.hp[0], boss.hp[4], 0xb70909); // life bar of enemy
	rect(buffer, boss.hp[1], boss.hp[2], boss.hp[3], boss.hp[4], 0xffffff); // life bord of enemy
	
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
		bx = boss.hb[0];
		by = boss.hb[1];
		
		clear_to_color(buffer, 0xaaaaaa);
		rectfill(hitbox, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072);//player
		rectfill(hitbox, enemy.hb[0], enemy.hb[1], enemy.hb[2], enemy.hb[3], 0x00FFFF); // enemy hitbox
		rectfill(hitbox, npc1.hb[0], npc1.hb[1], npc1.hb[2], npc1.hb[3], 0xFF6A00);	
		rectfill(hitbox, boss.hb[0], boss.hb[1], boss.hb[2], boss.hb[3], 0x00FFFF);// boss Hitbox
					rectfill(hitbox, boss.whb[0], boss.whb[1], boss.whb[2], boss.whb[3], 0x0026FF);//boss-weapon Hitbox
//*********************MOVE**************************************************************
		move();
		posValue = position();
//**************************LIMITS*******************************************************
		if((getpixel(hitbox, player.hb[0], player.hb[3]) == 0xFF6A00) || (getpixel(hitbox, player.hb[2], player.hb[3]) == 0xFF6A00) || (getpixel(hitbox, player.hb[2], player.hb[1]) == 0xFF6A00)|| (getpixel(hitbox, player.hb[0], player.hb[1]) == 0xFF6A00))
		{
			player.hb[0] = ax;
			player.hb[1] = ay;
		}
		if(mapa == 1)
			if((getpixel(choque1, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque1, player.hb[2], player.hb[3])== 0xFFFFFF) || (getpixel(choque1, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque1, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 1)
			if((getpixel(choque1, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[0];
				player.hb[1] = player.ylog[0];
			}
		if(mapa == 2)
			if((getpixel(choque2, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque2, player.hb[2], player.hb[3]) == 0xFFFFFF) || (getpixel(choque2, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque2, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 2)
			if((getpixel(choque2, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[1];
				player.hb[1] = player.ylog[1];
			}
		if(mapa == 3)
			if((getpixel(choque3, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque3, player.hb[2], player.hb[3]) == 0xFFFFFF) || (getpixel(choque3, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque3, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 3)
			if((getpixel(choque3, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[2];
				player.hb[1] = player.ylog[2];
			}
		if(mapa == 4)
		{
			if((getpixel(choque4, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque4, player.hb[2], player.hb[3]) == 0xFFFFFF) || (getpixel(choque4, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque4, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		}
		if(mapa == 4)
		{
			if((getpixel(choque4, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[3];
				player.hb[1] = player.ylog[3];
			}
		}
		if(mapa == 5)
			if((getpixel(choque5, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque5, player.hb[2], player.hb[3]) == 0xFFFFFF) || (getpixel(choque5, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque5, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 5)
			if((getpixel(choque5, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[4];
				player.hb[1] = player.ylog[4];
			}
		if(mapa == 6)
			if((getpixel(choque6, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque6, player.hb[2], player.hb[3]) == 0xFFFFFF) || (getpixel(choque6, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque6, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 6)
			if((getpixel(choque6, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[5];
				player.hb[1] = player.ylog[5];
			}
		if(mapa == 7)
			if((getpixel(choque7, player.hb[0], player.hb[3]) == 0xFFFFFF) || (getpixel(choque7, player.hb[2], player.hb[3]) == 0xFFFFFF) || (getpixel(choque7, player.hb[0], player.hb[1])== 0xFFFFFF) || (getpixel(choque7, player.hb[2], player.hb[1])== 0xFFFFFF))
			{
				player.hb[0] = ax;
				player.hb[1] = ay;
			}
		if(mapa == 7)
			if((getpixel(choque7, player.midx, player.midy) == 0xFFFFFF) || posValue == 1)
			{
				player.hb[0] = player.xlog[6];
				player.hb[1] = player.ylog[6];
			}
//*************************MASKED_BLIT & OF MAP001********************************
		if(mapa == 1)
		{
			masked_blit(choque1, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo1, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(aldeano, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if((enemy.hp[0] > 0)) // Idea: Make the enemy invisible until we talk with the NPC
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
				rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
				rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
			}
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
			}
			//Interact
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == 0))
			{
				textout_ex(textos, font, "O para", 24, 4, 0xFFFFFF, 0x000000);
				textout_ex(textos, font, " interactuar", 0, 14, 0xFFFFFF, 0x000000);
				blit(textos, screen,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 100, 25);
				if(key[KEY_O])
				{
					clear_bitmap(textos);
					clear_to_color(textos, 0xEFD3A6);
				}
			}
			//Dialogues
			while ((key[KEY_O]) && (getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (talk == 0))
			{
				readkey();
				clear_keybuf();
				if(key[KEY_O])
				{
					masked_blit(M1D1, buffer, 0, 0, 37, 480, 341, 91);
					blit(buffer, screen,  0, 0, 0, 0,  800, 600);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						masked_blit(M1D2, buffer, 0, 0, 37, 480, 341, 91);
						blit(buffer, screen,  0, 0, 0, 0, 800, 600);
						readkey();
						clear_keybuf();
						talk = 1;							
					}
				}
				clear_bitmap(textos);
			}
			//change of Map
			if (enemy.hp[0] == 0)
			{
				if((getpixel(choque1, player.hb[0], player.hb[1]) == 0x00FFFF) && talk == 1)
				{
					mapa = 2;
					player.hb[0] = 440;
					player.hb[1] = 560;
					npc1.hb[0] = 413;
					npc1.hb[1] = 492;
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
		}
//*************************MASKED_BLIT & CHANGE OF MAP002********************************
		if(mapa == 2)
		{
			masked_blit(choque2, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo2, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(lidia, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
				rectfill(hitbox, player.hb[0], player.hb[1], player.hb[2], player.hb[3], 0xff0072); // player hitbox
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
			}
			
			//************Interact I*****************************************************
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == 0))
			{
				textout_ex(textos, font, "O para", 24, 4, 0xFFFFFF, 0x000000);
				textout_ex(textos, font, " interactuar", 0, 14, 0xFFFFFF, 0x000000);
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
					masked_blit(M2D1, buffer, 0, 0, 37, 480, 341, 91);
					blit(buffer, screen,  0, 0, 0, 0,  800, 600);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						masked_blit(M2D2, buffer, 0, 0, 37, 480, 341, 91);
						blit(buffer, screen,  0, 0, 0, 0,  800, 600);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							masked_blit(M2D3, buffer, 0, 0, 37, 480, 341, 91);
							blit(buffer, screen,  0, 0, 0, 0,  800, 600);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								masked_blit(M2D4, buffer, 0, 0, 37, 480, 341, 91);
								blit(buffer, screen,  0, 0, 0, 0,  800, 600);
								readkey();
								clear_keybuf();
								if(!key[KEY_0])
								{
									masked_blit(M2D5, buffer, 0, 0, 37, 480, 341, 91);
									player.potion += 5;
									blit(buffer, screen,  0, 0, 0, 0,  800, 600);
									readkey();
									clear_keybuf();
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
				textout_ex(textos, font, "O para", 24, 4, 0xFFFFFF, 0x000000);
				textout_ex(textos, font, " interactuar", 0, 14, 0xFFFFFF, 0x000000);
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
					masked_blit(M2D6, buffer, 0, 0, 37, 480, 341, 91);
					blit(buffer, screen,  0, 0, 0, 0,  800, 600);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						masked_blit(M2D7, buffer, 0, 0, 37, 480, 341, 91);
						blit(buffer, screen,  0, 0, 0, 0,  800, 600);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							masked_blit(M2D8, buffer, 0, 0, 37, 480, 341, 91);
							blit(buffer, screen,  0, 0, 0, 0,  800, 600);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								masked_blit(M2D9, buffer, 0, 0, 37, 480, 341, 91);
								blit(buffer, screen,  0, 0, 0, 0,  800, 600);
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
				textout_ex(textos, font, "O para", 24, 4, 0xFFFFFF, 0x000000);
				textout_ex(textos, font, " interactuar", 0, 14, 0xFFFFFF, 0x000000);
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
					masked_blit(M2D10, buffer, 0, 0, 37, 480, 341, 91);
					blit(buffer, screen,  0, 0, 0, 0,  800, 600);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						masked_blit(M2D11, buffer, 0, 0, 37, 480, 341, 91);
						blit(buffer, screen,  0, 0, 0, 0,  800, 600);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							masked_blit(M2D12, buffer, 0, 0, 37, 480, 341, 91);
							blit(buffer, screen,  0, 0, 0, 0,  800, 600);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								masked_blit(M2D13, buffer, 0, 0, 37, 480, 341, 91);
								blit(buffer, screen,  0, 0, 0, 0,  800, 600);
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
			if (enemy.hp[0] == 0)
			{
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
					player.potion += 4;
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
					if(player.hp[0] < 20)
					{
						player.hp[0] = 30;
					}
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
					if(player.hp[0] < 20)
					{
						player.hp[0] = 30;
					}
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
		}
//*************************MASKED_BLIT & CHANGE OF MAP003********************************
		if(mapa == 3)
		{
			masked_blit(choque3, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo3, buffer, 0, 0, 0, 0, 800, 600);
			//masked blit of player1
			masked_blit(lidia, buffer, 0, 0, npc1.hb[0], npc1.hb[1], 32, 32);
			if(player.hp[0] > 0)
			{
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}	
			if ((talk == 0) && (enemy.hp[0] > 0) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
				textout_ex(textos, font, "ALGUIEN SALVEMEEE", 0, 4, 0xFFFFFF, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 138, 18);
			}
			if(enemy.hp[0] <= 0)
			{
				talk = 1;
				textout_ex(textos, font, "  GRACIAAAS  ", 0, 4, 0xFFFFFF, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 104, 18);
			}
			if(player.hp[0] <= 0)
			{
				talk = 1;
				textout_ex(textos, font, "   OH NOOOO  ", 0, 4, 0xFFFFFF, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 104, 18);
			}
			//cambio de mapa
			if (enemy.hp[0] == 0)
			{
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
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	    	{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			if (talk == 0 && enemy.hp[0] > 0)
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
				textout_ex(textos, font, "¡cof!, ¡cof!", 0, 4, 0xFFFFFF, 0x000000);
				textout_ex(textos, font, "¡Los derrotare!", 0, 14, 0xFFFFFF, 0x000000);
				masked_blit(textos, buffer,  0, 0, npc1.hb[2] + 15, npc1.hb[1] - 20, 122, 25);
			}
			if(enemy.hp[0] == 0)
		    {
				clear_bitmap(textos);
			}
			//************Interact I*****************************************************
			while ((getpixel(hitbox, player.whb[0], player.whb[1]) == 0xFF6A00) && (!key[KEY_O]) && (talk == 0) && enemy.hp[0] == 0)
			{
				clear_bitmap(textos);
				textout_ex(textos, font, "O para", 24, 4, 0xFFFFFF, 0x000000);
				textout_ex(textos, font, " interactuar", 0, 14, 0xFFFFFF, 0x000000);
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
					masked_blit(M4D1, buffer, 0, 0, 37, 480, 341, 91);
					blit(buffer, screen,  0, 0, 0, 0,  800, 600);
					readkey();
					clear_keybuf();
					if(key[KEY_O])
					{
						masked_blit(M4D2, buffer, 0, 0, 37, 480, 341, 91);
						blit(buffer, screen,  0, 0, 0, 0,  800, 600);
						readkey();
						clear_keybuf();
						if(key[KEY_O])
						{
							masked_blit(M4D3, buffer, 0, 0, 37, 480, 341, 91);
							blit(buffer, screen,  0, 0, 0, 0,  800, 600);
							readkey();
							clear_keybuf();
							if(key[KEY_O])
							{
								masked_blit(M4D4, buffer, 0, 0, 37, 480, 341, 91);
								blit(buffer, screen,  0, 0, 0, 0,  800, 600);
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
			if(enemy.hp[0] == 0)
			{
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
		}
//*************************MASKED_BLIT & CHANGE OF MAP005********************************
		if (mapa == 5)
		{
			masked_blit(choque5, buffer, 0, 0, 0, 0, 800, 600);
			masked_blit(fondo5, buffer, 0, 0, 0, 0, 800, 600);
//masked blit of player1
			if(player.hp[0] > 0)
			{
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}	    	
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
//cambio de mapa
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
			}
//cambio de mapa
			if (enemy.hp[0] == 0)
			{
				if(getpixel(choque5, player.hb[0], player.hb[3]) == 0x00FFFF)
				{
					mapa = 2;
					talk = 3;
					player.hb[0] = 748;
					player.hb[1] = 305;
					npc1.hb[0] = 413;
					npc1.hb[1] = 492;
					enemy.hp[0] = 0;
					player.hp[0] = 32;
				}
				else if (getpixel(choque5, player.hb[2], player.hb[3]) == 0x00FF00)
				{
					mapa = 6;
					player.hb[0] = 12;
					player.hb[1] = 310;
				}
				if(talk == 1)
				{
					talk = 1;
					j = 0;
					enemy.hp[0] = 0;
					enemy.hb[0] = 0;
					enemy.hb[1] = 0;
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
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(enemy.hp[0] > 0)
	   		{
				masked_blit(enemigo, buffer, enemy.anima[h], enemy.visdir[enemy.direc], enemy.hb[0], enemy.hb[1], 32, 32);   //Enemy
			}
			//cambio de mapa
			if((talk == 1) && (player.hp[0] > 0))
			{
				enemy_pursuit(j);
				enemyAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
			}
			//cambio de mapa
			if (enemy.hp[0] == 0)
			{
				if(getpixel(choque6, player.hb[0], player.hb[1]) == 0xFF00FF)
				{
					mapa = 7;
					player.hb[0] = 374;
					player.hb[1] = 535;
					player.potion += 2;
					if(talk == 1)
					{
						talk = 1;
						bj = 0;
						boss.hp[0] = 64;
						boss.hb[0] = 383;
						boss.hb[1] = 253;
					}
				}
				else if(getpixel(choque6, player.hb[0], player.hb[1]) == 0x00FF00)
				{
					mapa = 5;
					talk = 0;
					player.hb[0] = 760;
					player.hb[1] = 93;
					enemy.hp[0] = 0;
					boss.hp[0] = 64;
				}
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
	   			masked_blit(personaje, buffer, player.anima[k], player.visdir[player.direc], player.hb[0], player.hb[1], 32, 32);   //Player
			}
			if(boss.hp[0] != 0)
	    	{
				masked_blit(jefe, buffer, boss.anima[eh], boss.visdir[boss.direc], boss.hb[0], boss.hb[1], 64, 64);   //Enemy
			}
			if((talk == 1) && (player.hp[0] > 0))
			{
				boss_pursuit(bj);
				bossAttack(hitbox, ataque, buffer);
				playerAttack(hitbox, ataque, buffer, mapa);
			}
			//cambio de mapa
			if(enemy.hp[0] == 0)
			{
				if(getpixel(choque7, player.hb[2], player.hb[3]) == 0xFF0000)
				{
					mapa = 6;
					talk = 3;
					player.hb[0] = 466;
					player.hb[1] = 36;
					enemy.hp[0] = 0;
				}
			}
		}
/****************************HUD IMPRESSION*********************************************/
/*The number changes with your inventory*/
		masked_blit(pjicon, buffer, 0, 0, 10, 14, 60, 60); //Icon of Character
		masked_blit(icons, buffer, 0, 0, 84, 41, 32, 32); //Potion icon
		
		if(player.potion > 0)
		{
			masked_blit(numbers, buffer, player.potion * 24, 0, 122, 41, 24, 30); //Potion number 	{	
		}
		if(player.potion == 0)
		{
			masked_blit(numbers, buffer, 0, 0, 122, 41, 24, 30); //Potion number 
		}
	
		masked_blit(icons, buffer, 32, 0, 156, 41, 32, 32); //Gold icon
		
		
		if(player.money < 10)
		{			
			masked_blit(numbers, buffer, 0 * 24, 0, 194, 41, 24, 30); //Gold number
			masked_blit(numbers, buffer, player.money * 24, 0, 218, 41, 24, 30); //Gold number
		}
		if(player.money >= 10)
		{
			masked_blit(numbers, buffer, (player.money / 10) * 24, 0, 194, 41, 24, 30); //Gold number
			masked_blit(numbers, buffer, (player.money % 10) * 24, 0, 218, 41, 24, 30); //Gold number
		}
//****************************LIFE BAR***************************************************
		npcValues();
		enemyValues();
		playerValues();
		
/*Large life bar.*/
		if (player.hp[0] > 0)
		{
		rectfill(buffer, 70, 18, ((player.hp[0] * 8) + 68), 30, 0xb70909); //player lifebar (hp)
		rect(buffer, 70, 18, 324, 30, 0xffffff); //player lifebar (box)
		}
		
		rectfill(buffer, player.hp[1], player.hp[2], player.hp[1] + player.hp[0], player.hp[4], 0xb70909);//player lifebar (hp)
		rect(buffer, player.hp[1], player.hp[2], player.hp[3], player.hp[4], 0xffffff);//player lifebar (box)
		rectfill(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[1] + enemy.hp[0], enemy.hp[4], 0xb70909); // life bar of enemy
		rect(buffer, enemy.hp[1], enemy.hp[2], enemy.hp[3], enemy.hp[4], 0xffffff); // life bord of enemy
		rectfill(buffer, boss.hp[1], boss.hp[2], boss.hp[1] + boss.hp[0], boss.hp[4], 0xb70909); // life bar of boss
		rect(buffer, boss.hp[1], boss.hp[2], boss.hp[3], boss.hp[4], 0xffffff); // life bord of boss
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
		else if(boss.hb[0] == 0 && boss.hb[1] == 0)
		{
			bj = 1;
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
		if(bx != boss.hb[0] || by != boss.hb[1])
		{
			eh++;
			if(eh > 2)
			{ 
				eh = 0;
			}
		}
//******************Healing
		if (key[KEY_I] && player.potion > 0)
		{
			clear_keybuf();
			readkey();	
			if (player.hp[0] + 8 <= 32)
			{
				player.hp[0] += 8; 
				player.potion -= 1;
			}
			if (player.hp[0] + 8 > 32)
			{
				player.hp[0] = 32;
				player.potion -= 1;
			}
			rest(20);
		}
//******************enemy dead
		if (enemy.hp[0] == 0)
		{
			if(enemy.hb[0] != 0 && enemy.hb[1] != 0)
			{
				player.money += (rand() %	4) + 1;
			}
			enemyDead(); 
			
		}
/******************enemy dead*/
		if (boss.hp[0] == 0)
		{
			bossDead();
		}
/******************dead of character*/
		if(player.hp[0] == 0)
		{
			playerDead();
			masked_blit(muerte, buffer, 0, 0, 0, 200, 800, 200);
		}
/****************************MAIN BLIT**************************************************/
		blit(buffer, screen, 0, 0, 0, 0, 800, 600);
		clear_keybuf();
    	keypressed();
    	rest(40);
    	clear_bitmap(buffer);
    	clear_bitmap(hitbox);
    }
    //Close of program
    destroy_bitmap(buffer);
 	destroy_bitmap(hitbox);
 	destroy_bitmap(textos);
	destroy_bitmap(dialogos );
	destroy_bitmap(fondo1);
	destroy_bitmap(fondo2);
	destroy_bitmap(fondo3);
 	destroy_bitmap(fondo4);
 	destroy_bitmap(fondo5);
 	destroy_bitmap(fondo6);
 	destroy_bitmap(fondo7 );
 	destroy_bitmap(choque1);
 	destroy_bitmap(choque2);
 	destroy_bitmap(choque3);
 	destroy_bitmap(choque4);
 	destroy_bitmap(choque5);
 	destroy_bitmap(choque6);
 	destroy_bitmap(choque7);
 	destroy_bitmap(menu);
 	destroy_bitmap(instrucciones );
 	destroy_bitmap(creditos);
 	destroy_bitmap(muerte);
 	destroy_bitmap(M1D1);
 	destroy_bitmap(M1D2);
 	destroy_bitmap(M2D1);
 	destroy_bitmap(M2D2);
 	destroy_bitmap(M2D3);
 	destroy_bitmap(M2D4);
 	destroy_bitmap(M2D5);
 	destroy_bitmap(M2D6);
 	destroy_bitmap(M2D7);
 	destroy_bitmap(M2D8);
 	destroy_bitmap(M2D9);
 	destroy_bitmap(M2D10);
 	destroy_bitmap(M2D11);
 	destroy_bitmap(M2D12);
 	destroy_bitmap(M2D13);
 	destroy_bitmap(M4D1);
 	destroy_bitmap(M4D2);
 	destroy_bitmap(M4D3);
 	destroy_bitmap(M4D4);
 	destroy_bitmap(dialogo);
  	destroy_bitmap(personaje);
  	destroy_bitmap(aldeano);
  	destroy_bitmap(lidia);
  	destroy_bitmap(capitan);
  	destroy_bitmap(enemigo);
  	destroy_bitmap(jefe);
  	destroy_bitmap(ataque);
  	destroy_bitmap(arma);
  	destroy_bitmap(icons);
  	destroy_bitmap(pjicon);
  	destroy_bitmap(numbers);
	return 0;
}
END_OF_MAIN();
