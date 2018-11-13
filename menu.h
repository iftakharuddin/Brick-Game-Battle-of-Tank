void menu()
{
	iSetColor(107, 107, 71);
	iFilledRectangle(0, 0, 800, 420);
	iShowBMP(150, 310, "name.bmp");
	iSetColor(0, 0, 0);
	iFilledCircle(250, 175, 140);
	iSetColor(107, 107, 71);
	iFilledCircle(250, 175, 127);

	int x=250-90, y=175-80, a=60;
	iSetColor(0, 0, 0);
	iRectangle(x, y, a, a);
    iFilledRectangle(x+5, y+5, a-10, a-10);
	iRectangle(x, y+a,a,a);
	iFilledRectangle(x+5,y+a+5, a-10, a-10);
	iRectangle(x+a, y+a, a, a);
    iFilledRectangle(x+a+5, y+a+5, a-10, a-10);
    iRectangle(x+2*a, y+a, a, a);
    iFilledRectangle(x+2*a+5, y+a+5, a-10, a-10);
	iRectangle(x+2*a, y, a, a);
    iFilledRectangle(x+2*a+5, y+5, a-10, a-10);
	iRectangle(x+a,y+2*a, a, a);
    iFilledRectangle(x+a+5,y+2*a+5, a-10, a-10);

	for(int i=0; i<6; i++){
		iSetColor(red[i], 0, 0);
		iText(500, 50*(6-i)-3, button[i], GLUT_BITMAP_TIMES_ROMAN_24);
		iRectangle(493, 50*(6-i)-10, 180, 30);
	}
}
void newgame()
{
	iSetColor(107, 107, 71);
	iFilledRectangle(0, 0, 800, 420);
	iSetColor(0, 0, 0);
	iText(330, 250, "Enter Player Name:", GLUT_BITMAP_HELVETICA_18);
	drawTextBox();
	iSetColor(255, 255, 255);
	iText(288, 206, str, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(20, 20, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0, 0);
	iText(358, 156, "START", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(350, 150, 100, 30);
}
void gameover()
{
	iSetColor(173, 173, 133);
	iFilledRectangle(0, 0, 800, 420);
	iSetColor(0, 0, 0);
	iText(330, 250, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(630, 70, "MENU", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(623, 63, 100, 30);
	//iText(630, 30, "EXIT", GLUT_BITMAP_TIMES_ROMAN_24);
	//iRectangle(623, 23, 100, 30);
}


void scoreboard()
{
	char scorestr[20];
	sprintf_s(scorestr, "Score: %d", score);
	iText(650, 350, scorestr, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0, 0);
	for(int i=0; i<life; i++){
		iRectangle(685, 100+i*30, 30, 30);
		iFilledRectangle(690, 105+i*30, 20, 20);
	}

}
void about()
{
	FILE *fp;
	int i=0, j=400;
	char c[100];
	iSetColor(107, 107, 71);
	iFilledRectangle(0, 0, 800, 420);
	iSetColor(255, 255, 255);
	fp=fopen("about.txt", "r");
	fgets(c, 30, fp);
	while(!feof(fp)){
		iText(30, j, c, GLUT_BITMAP_TIMES_ROMAN_24);
		fgets(c, 30, fp);
		j-=30;
	}
	fclose(fp);
	iText(20, 20, "Back", GLUT_BITMAP_TIMES_ROMAN_24);
}
void help()
{
	FILE *fp;
	int i=0, j=400;
	char c[100];
	iSetColor(107, 107, 71);
	iFilledRectangle(0, 0, 800, 420);
	iSetColor(255, 255, 255);
	fp=fopen("help.txt", "r");
	fgets(c, 30, fp);
	while(!feof(fp)){
		iText(30, j, c, GLUT_BITMAP_TIMES_ROMAN_24);
		fgets(c, 30, fp);
		j-=30;
	}
	fclose(fp);
	iText(20, 20, "Back", GLUT_BITMAP_TIMES_ROMAN_24);

}

void highscore()
{
	FILE *fp1;
	int i=0, j=370;
	char c[30];
	iSetColor(107, 107, 71);
	iFilledRectangle(0, 0, 800, 420);
	iSetColor(255, 255, 255);
	iText(100, 400, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	fp1=fopen("highscore.txt", "r");
	fgets(c, 30, fp1);
	while(!feof(fp1)){
		iText(30, j, c, GLUT_BITMAP_HELVETICA_18);
		fgets(c, 30, fp1);
		j-=30;
	}
	fclose(fp1);
	iText(20, 20, "Back", GLUT_BITMAP_TIMES_ROMAN_24);

}
void scoreset()
{
	player[sss++].point=score;
	rearrange();
	FILE *fp;
	fp=fopen("highscore.txt", "w");
	for(int j=0; j<5; j++){
		fprintf(fp, "%d. %s-%d\n", j+1, player[j].name, player[j].point);
    }
	fclose(fp);
}

void rearrange()
{
    int i, j, k, high, f;
    char s[20];
    for(i=0; i<5; i++){
        high=player[i].point;
        f=0;
		//printf("sss: %d\n", player[i].point);
        for(j=i+1; j<6; j++){
            if(high<player[j].point){
                high=player[j].point;
                k=j;
                f=1;
            }
        }
        if(f==1){
            strcpy(s, player[i].name);
            strcpy(player[i].name, player[k].name);
            strcpy(player[k].name, s);
            high=player[i].point;
            player[i].point=player[k].point;
            player[k].point=high;
        }
    }
}

