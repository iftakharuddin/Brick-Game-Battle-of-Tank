
void mybulletshow()
{
	for(int j=0; j<bullet; j++){
		if(q[j]==1){
            iRectangle(bx[j], by[j], 30, 30);
            iFilledRectangle(bx[j]+5, by[j]+5, 20, 20);
        }
	}
}


void mybulletflow()
{
	for(int j=0; j<bullet; j++){
		if(u1[j] && q[j]){
			by[j]+=30;
			if(by[j]>400){
				q[j]=0;
				u1[j]=0;
			}
		}
		else if(d1[j] && q[j]){
			by[j]-=30;
			if(by[j]<0){
				q[j]=0;
				d1[j]=0;
			}
		}
		else if(r1[j] && q[j]){
			bx[j]+=30;
			if(bx[j]>570){
				q[j]=0;
				r1[j]=0;
			}
		}
		else if(l1[j] && q[j]){
			bx[j]-=30;
			if(bx[j]<0){
				q[j]=0;
				l1[j]=0;
			}
		}
	}
}

void mylife()
{
	int i;
	for(i=0; i<num; i++){
		if(enemy[i].bshow){
			if(u && ((enemy[i].bX>=x && enemy[i].bX<=x+60 && enemy[i].bY>=y && enemy[i].bY<=y+30)||(enemy[i].bX==x+30 && enemy[i].bY==y+60))){
				life--;
				enemy[i].bshow=0;
				enemy[i].u1=0;
				enemy[i].d1=0;
				enemy[i].r1=0;
				enemy[i].l1=0;
				enemy[i].bX=-60;
				enemy[i].bY=-60;
			}
			else if(d &&  ((enemy[i].bX>=x && enemy[i].bX<=x+60 && enemy[i].bY>=y+30 && enemy[i].bY<=y+60)||(enemy[i].bX==x+30 && enemy[i].bY==y))){
				life--;
				enemy[i].bshow=0;
				enemy[i].u1=0;
				enemy[i].d1=0;
				enemy[i].r1=0;
				enemy[i].l1=0;
				enemy[i].bX=-60;
				enemy[i].bY=-60;
			}
			else if(r && ((enemy[i].bX>=x && enemy[i].bX<=x+30 && enemy[i].bY>=y && enemy[i].bY<=y+60)||(enemy[i].bX==x+60 && enemy[i].bY==y+30))){
				life--;
				enemy[i].bshow=0;
				enemy[i].u1=0;
				enemy[i].d1=0;
				enemy[i].r1=0;
				enemy[i].l1=0;
				enemy[i].bX=-60;
				enemy[i].bY=-60;
			}
			else if(l && ((enemy[i].bX>=x+30 && enemy[i].bX<=x+60 && enemy[i].bY>=y && enemy[i].bY<=y+60)||(enemy[i].bX==x && enemy[i].bY==y+30))){
				life--;
				enemy[i].bshow=0;
				enemy[i].u1=0;
				enemy[i].d1=0;
				enemy[i].r1=0;
				enemy[i].l1=0;
				enemy[i].bX=-60;
				enemy[i].bY=-60;
			}
		}
	}
}

void myTankshow()
{
	if(u){
        //iSetColor(102, 0, 102);
        iRectangle(x, y, 30, 30);
        iFilledRectangle(x+5, y+5, 20, 20);
        iRectangle(x, y+30, 30, 30);
        iFilledRectangle(x+5,y+35, 20, 20);
        iRectangle(x+30, y+30, 30, 30);
        iFilledRectangle(x+35, y+35, 20, 20);
        iRectangle(x+60, y+30, 30, 30);
        iFilledRectangle(x+65, y+35, 20, 20);
        iRectangle(x+60, y, 30, 30);
        iFilledRectangle(x+65, y+5, 20, 20);
        iRectangle(x+30,y+60, 30, 30);
        iFilledRectangle(x+35,y+65, 20, 20);
    }
    else if(d){
        //iSetColor(102, 0, 102);
        iRectangle(x+30,y, 30, 30);
        iFilledRectangle(x+35, y+5, 20, 20);
        iRectangle(x, y+30, 30, 30);
        iFilledRectangle(x+5, y+35, 20, 20);
        iRectangle(x+30, y+30, 30, 30);
        iFilledRectangle(x+35, y+35, 20, 20);
        iRectangle(x+60, y+30, 30, 30);
        iFilledRectangle(x+65,y+35, 20, 20);
        iRectangle(x, y+60, 30, 30);
        iFilledRectangle(x+5, y+65, 20, 20);
        iRectangle(x+60, y+60, 30, 30);
        iFilledRectangle(x+65,y+65, 20, 20);
    }
    else if(l){
        //iSetColor(102, 0, 102);
        iRectangle(x+30, y, 30, 30);
        iFilledRectangle(x+35, y+5, 20, 20);
        iRectangle(x, y+30, 30, 30);
        iFilledRectangle(x+5,y+35, 20, 20);
        iRectangle(x+30, y+30, 30, 30);
        iFilledRectangle(x+35, y+35, 20, 20);
        iRectangle(x+60, y, 30, 30);
        iFilledRectangle(x+65, y+5, 20, 20);
        iRectangle(x+30, y+60, 30, 30);
        iFilledRectangle(x+35, y+65, 20, 20);
        iRectangle(x+60, y+60, 30, 30);
        iFilledRectangle(x+65, y+65, 20, 20);
    }
    else {
        //iSetColor(102, 0, 102);
        iRectangle(x+30, y, 30, 30);
        iFilledRectangle(x+35, y+5, 20, 20);
        iRectangle(x, y, 30, 30);
        iFilledRectangle(x+5, y+5, 20, 20);
        iRectangle(x+30, y+30, 30, 30);
        iFilledRectangle(x+35, y+35, 20, 20);
        iRectangle(x+60, y+30, 30, 30);
        iFilledRectangle(x+65, y+35, 20, 20);
        iRectangle(x, y+60, 30, 30);
        iFilledRectangle(x+5, y+65, 20, 20);
        iRectangle(x+30, y+60, 30, 30);
        iFilledRectangle(x+35, y+65, 20, 20);
    }
}

int mycollision()
{
	int j, x1, y1;
	if(u) {
		x1=x;
		y1=y+90;
		for(j=0; j<num; j++){
			if(enemy[j].x>=x1-60 && enemy[j].x<=x1+60 && enemy[j].y==y1){
					return 0;
			}
		}
	}
	else if(d){
		x1=x;
		y1=y-90;
		for(j=0; j<num; j++){
			if(enemy[j].x>=x1-60 && enemy[j].x<=x1+60 && enemy[j].y==y1){
				return 0;
			}
		}
	}
	else if(l){
		x1=x-90;
		y1=y;
		for(j=0; j<num; j++){
			if(enemy[j].y>=y1-60 && enemy[j].y<=y1+60 && enemy[j].x==x1){
				return 0;
			}
		}
	}
	else {
		x1=x+90;
		y1=y;
		for(j=0; j<num; j++){
			if(enemy[j].y>=y1-60 && enemy[j].y<=y1+60 && enemy[j].x==x1){
				return 0;
			}
		}
	}
	return 1;

}
void attack()
{
    int i, j;
    for(i=0; i<num; i++){
		for(j=0;j<bullet; j++){
			if(bx[j]>=enemy[i].x && bx[j]<enemy[i].x+90 && by[j]>=enemy[i].y && by[j]<enemy[i].y+90){
				enemy[i].show=0;
				q[j]=0;
				u1[j]=0;
				d1[j]=0;
				r1[j]=0;
				l1[j]=0;
				bx[j]=600;
				by[j]=0;
				score+=5;
				enemy[i].x=-90;
				enemy[i].y=-90;
			}
		}
    }
}
void startshoot()
{
	//for(int j=0; j<bullet; j++){
	int j=0;
    if(q[j]==0){
        q[j]=1;
        if(u){
            bx[j]=x+30;
            by[j]=y+60;
            u1[j]=1;
        }
        else if(d){
            bx[j]=x+30;
            by[j]=y;
            d1[j]=1;
        }
        else if(l){
            bx[j]=x;
            by[j]=y+30;
            l1[j]=1;
        }
        else if(r){
            bx[j]=x+60;
            by[j]=y+30;
            r1[j]=1;
        }
    }
    else if(q[++j]==0){
        q[j]=1;
        if(u){
            bx[j]=x+30;
            by[j]=y+60;
            u1[j]=1;
        }
        else if(d){
            bx[j]=x+30;
            by[j]=y;
            d1[j]=1;
        }
        else if(l){
            bx[j]=x;
            by[j]=y+30;
            l1[j]=1;
        }
        else if(r){
            bx[j]=x+60;
            by[j]=y+30;
            r1[j]=1;
        }
    }

    if(q[0] || q[1]){
        PlaySound("music\\shoot1", NULL,  SND_ASYNC);
    }
}

