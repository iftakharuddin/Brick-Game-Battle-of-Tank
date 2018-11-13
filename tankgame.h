//# define num 5
# define bullet 2


void autoSetenemy();
int reAffairPosition(int x, int y);
void enemyShow();
void emove();
int ecollision(int i);
void attack();
void ebullet();
int collisionWithme(int i);
void mybulletshow();
void mybulletflow();
void gameover();
void drawTextBox();
void menu();
void newgame();
void rearrange();
void myTankshow();
void scoreboard();

int sss=0, level=1, movement=30, num=6;
int x=0, y=0;
int u=1, d=0, l=0, r=0;
int u1[bullet]={0}, d1[bullet]={0}, l1[bullet]={0}, r1[bullet]={0};
int bx[bullet]={0}, by[bullet]={0};
int q[bullet]={0}, t=0, score=0, life=3, s=1;
int bulletfrequency=40;

void setnewgame()
{
    x=0; y=0;
    u=1; d=0; l=0; r=0;
    u1[0]=0; d1[0]=0; l1[0]=0; r1[0]=0;
    u1[1]=0; d1[1]=0; l1[1]=0; r1[1]=0;
    bx[0]=0; by[0]=0;
    bx[1]=0; by[1]=0;
    q[0]=0; q[1]=0; t=0; score=0; life=3;
}

int red[6]={0};
int gameState=-1, len=0;
char button[][20]={"NEW GAME", "RESUME", "HIGH SCORE", "HELP", "ABOUT", "EXIT"};
char str[20];


struct record{
	char name[20];
	int point;
};
struct etank{
	int x, y;
	int show;
	int u, d, l, r;
	int u1, d1, l1, r1;
	int bshow, bX, bY;
};


struct etank enemy[9];
struct record player[6];


void drawTextBox()
{
	iSetColor(255, 255, 255);
	iRectangle(280, 200, 250, 30);
	iSetColor(0, 0, 0);
	iFilledRectangle(280, 200, 250, 30);
}


void startplay()
{
	iSetColor(173, 173, 133);
	iFilledRectangle(0, 0, 800, 420);
	iSetColor(102, 105, 344);
	iLine(600, 0, 600, 420);

	iSetColor(0, 0, 0);
	for(int i=30; i<=600; i+=30){
		iLine(i, 0, i, 420);
	}
	for(int i=30; i<=390; i+=30){
		iLine(0, i, 600, i);
	}

	iSetColor(255, 0, 0);
	myTankshow();
	/*my bullet show */
	mybulletshow();
	iSetColor(62, 62, 40);

    enemyShow();
    attack();

	scoreboard();
	iText(630, 70, "PAUSE", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(623, 63, 100, 30);

}




