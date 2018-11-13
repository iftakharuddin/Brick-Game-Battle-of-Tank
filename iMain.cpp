/*
	author: Iftakhar Uddin Bhuiyan and saifur rahman suhag

*/
# include "iGraphics.h"
# include "tankgame.h"
# include "mytank.h"
# include "enemytank.h"
# include "menu.h"

int bulletfrequency=40;

void iDraw()
{
	iClear();
	if(gameState==-1){
		menu();
	}
	else if(gameState==0){
		newgame();
	}
	else if(gameState==1){
		startplay();
	}
	else if(gameState==2){
		highscore();
	}
	else if(gameState==3){
		help();
	}
	else if(gameState==4){
		about();
	}
	else if(gameState==6){
		iSetColor(173, 173, 133);
		iFilledRectangle(0, 0, 800, 420);
		iSetColor(255, 0, 0);
		iText(330, 250, "LEVEL-2", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(gameState==7){
		gameover();
	}
	else if(gameState==8){
		
	}
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(gameState==-1){
			for(int i=0; i<6; i++){
				if(mx>=493   && mx<=493+180   && my>=50*(6-i)-10  && my<=50*(6-i)+20){
					red[i]=255;
					gameState=i;
					if(i==1){
						iResumeTimer(1);
						iResumeTimer(2);
						iResumeTimer(3);
						iResumeTimer(4);
						iResumeTimer(5);
					}

				}
				else red[i]=0;
				
			}
			/*if(mx>=493   && mx<=493+180   && my>=50*(6-1)-10  && my<=50*(6-1)+20){
				iResumeTimer(0);
				iResumeTimer(1);
				iResumeTimer(2);
				gameState=1;
			}
			*/
		}
		else if(gameState==0){
			if(mx>=20 && mx<=60 && my>=20 && my <=40) gameState=-1;
			else if(mx>=350 && mx<=450 && my>=150 && my<=180) {
				gameState=1;
				iResumeTimer(1);
				iResumeTimer(2);
				iResumeTimer(3);
				iResumeTimer(4);
				iResumeTimer(5);
				setnewgame();
				score=0; life=3;
			}
		}
		else if(gameState==1){
			if(mx>=623 && mx<=623+100 && my>=63 && my<=63+30){
				gameState=-1;
			}

		}
		else if(gameState==2){
			if(mx>=20 && mx<=60 && my>=20 && my <=40) gameState=-1;
		}
		else if(gameState==3){
			if(mx>=20 && mx<=60 && my>=20 && my <=40) gameState=-1;
		}
		else if(gameState==4){
			if(mx>=20 && mx<=60 && my>=20 && my <=40) gameState=-1;
		}
		else if(gameState==7){
			if(mx>=623 && mx<=623+100 && my>=63 && my<=63+30){
				gameState=-1;
			}
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}



/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(gameState==0){
		if(key == '\r')
		{
			strcpy(player[sss].name, str);
			/*
			FILE *fp;
			fp=fopen("Highscore.txt", "w");
			fputs(str2, fp);
			fclose(fp); 
			*/
			for(int i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
			gameState=1;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(5);
		}
		else if(key=='\b'){
			len--;
			str[len]='\0';
		}
		else
		{
			str[len] = key;
			len++;

		}
	}

	else if(gameState==1){
		if(key == 'q')
		{
			startshoot();
		}
		else if(key == 'p'){
			iPauseTimer(1);
			iPauseTimer(2);
			iPauseTimer(3);
			iPauseTimer(4);
			iPauseTimer(5);
			gameState=-1;
		}
		/*else if(key=='s'){
			if(s){
				PlaySound("music\\backgroundmusic", NULL, SND_LOOP | SND_SYNC);
				s=0;
			}
			else {
				PlaySound(0, 0, 0);
			}
		}
		*/
	}
	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP){
		if(u &&  mycollision()){
			if(y>=330) {
				y=330;
			}
			else {
				y+=30;
			}
		}
		else if(r){
			u=1; r=0;
		}
		else if(l){
			u=1; l=0;
		}
		else {
			u=1; d=0;
		}

	}
	else if(key == GLUT_KEY_DOWN){
		if(d &&  mycollision()) {
			if(y<=0){
				y=0;
			}
			else {
				y-=30;
			}
		}
		else if(r){
			d=1; r=0;
		}
		else if(l){
			d=1; l=0;
		}
		else {
			d=1; u=0;
		}
	}
	else if(key == GLUT_KEY_RIGHT){
		if(r &&  mycollision()){
			if(x>=510){
				x=510;
			}
			else {
				x+=30;
			}
		}
		else if(u){
			r=1; u=0;
		}
		else if(d){
			r=1; d=0;
		}
		else {
			r=1; l=0;
		}
	}
	else if(key == GLUT_KEY_LEFT){
		if(l &&  mycollision()){
			if(x<=0){
				x=0;			
			}
			else {
				x-=30;
			}
		}
		else if(u){
			l=1; u=0;
		}
		else if(d){
			l=1; d=0;
		}
		else {
			l=1; r=0;
		}
	}
}


void change(void)
{
	if(life==0){
		gameState=7;
		scoreset();
		life--;
	}
	if(score==25 && t<60){
		gameState=6;
		num=9;
		bulletfrequency=30;
		t++;
	}
	else if(t==60){
		gameState=1;
		t++;
	}

	
	mybulletflow();
	//attack();
	//printf("change--\n");
}
int t1=0;
void eshoot(void)
{
	t1+=1;
	if(t1==bulletfrequency){
		ebullet();
		t1=0;
	}
	int i;
	for(i=0; i<num; i++){
		if(enemy[i].show && enemy[i].bshow){
			if(enemy[i].u1){
				enemy[i].bY+=30;
				if(enemy[i].bY>400){
					enemy[i].bshow=0;
					enemy[i].u1=0;

				}
			}
			else if(enemy[i].d1){
				enemy[i].bY-=30;
				if(enemy[i].bY<0){
					enemy[i].bshow=0;
					enemy[i].d1=0;
				}
			}
			else if(enemy[i].r1){
				enemy[i].bX+=30;
				if(enemy[i].bX>600){
					enemy[i].bshow=0;
					enemy[i].r1=0;
				}
			}
			else if(enemy[i].l1){
				enemy[i].bX-=30;
				if(enemy[i].bX<0){
					enemy[i].bshow=0;
					enemy[i].l1=0;
				}
			}
		}
	}

	//printf("eshoot--\n");

}

void lifecounter()
{
	mylife();
	//printf("lifecounter--\n");
}

void enemysetting()
{
	autoSetenemy();
	//printf("enemysetting--\n");
}
void enemymovement()
{
		emove();
	//printf("enemymovement--\n");
}


int main()
{ 
	int i;
	for(i=0; i<num; i++){
		enemy[i].show=0;
	}
	//PlaySound("music\\backgroundmusic", NULL, SND_LOOP | SND_SYNC);
	//iSetTimer(1, setpause);
	i=iSetTimer(1900, enemysetting);
	//printf("enemysetting--%d\n", i);
	i=iSetTimer(20, lifecounter);
	//printf("lifecounter--%d\n", i);
	i=iSetTimer(25, change);
	//printf("change--%d\n", i);
	i=iSetTimer(50, eshoot);
	//printf("eshoot--%d\n", i);
	i=iSetTimer(2000, enemymovement);
	//printf("enemymovement--%d\n", i);

	iInitialize(800, 420, "Brick Game: Battle of Tank");
	return 0;
}	