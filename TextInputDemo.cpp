/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

char str[100], str2[100];
int len;
int mode;

void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}


void iDraw()
{
	//place your drawing codes here

	iClear();

	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(55, 260, str);
	}

	iText(10, 10, "Click to activate the box, enter to finish.");
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}

/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0)
		{
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1)
	{
		if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}

	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
	str[0]= 0;
	iInitialize(400, 400, "TextInputDemo");
	return 0;
}
