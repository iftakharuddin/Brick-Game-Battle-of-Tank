
void autoSetenemy(){
	int i, x, y;
	for(i=0; i<num; i++){
		x=30*(rand()%17);
		y=30*(rand()%11);
		if((!enemy[i].show) && reAffairPosition(x, y)){
			enemy[i].show=1;
			enemy[i].x=x;
			enemy[i].y=y;
			if(rand()%2)
                enemy[i].u=1;
            else if(rand()%2)
                enemy[i].d=1;
            else if(rand()%2)
                enemy[i].l=1;
            else
                enemy[i].r=1;
		}
	}

}

int reAffairPosition(int x1, int y1)
{
	int i;
	for(i=0; i<num; i++){
		if(enemy[i].show){
			if(x1>=enemy[i].x-60 && x1<=enemy[i].x+60 && y1>=enemy[i].y-60 && y1<=enemy[i].y+60) return 0;
		}
	}
	if(x1>=x-60 && x1<=x+60 && y1>=y-60 && y1<=y+60) return 0;
	return 1;
}
void enemyShow()
{
    int i;
    for(i=0; i<num; i++){
        if(!enemy[i].show) continue;
        if(enemy[i].u){
            //iSetColor(102, 0, 102);
            iRectangle(enemy[i].x, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+65, 20, 20);
        }
        else if(enemy[i].d){
            //iSetColor(102, 0, 102);
            iRectangle(enemy[i].x+30, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+65, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+65, 20, 20);
        }
        else if(enemy[i].l){
            //iSetColor(102, 0, 102);
            iRectangle(enemy[i].x+30, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+65, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+65, 20, 20);
        }
        else {
            //iSetColor(102, 0, 102);
            iRectangle(enemy[i].x+30, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x, enemy[i].y, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+5, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x+60, enemy[i].y+30, 30, 30);
            iFilledRectangle(enemy[i].x+65, enemy[i].y+35, 20, 20);
            iRectangle(enemy[i].x, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+5, enemy[i].y+65, 20, 20);
            iRectangle(enemy[i].x+30, enemy[i].y+60, 30, 30);
            iFilledRectangle(enemy[i].x+35, enemy[i].y+65, 20, 20);
        }
		if(enemy[i].bshow){
			iRectangle(enemy[i].bX, enemy[i].bY, 30, 30);
			iFilledRectangle(enemy[i].bX+5, enemy[i].bY+5, 20, 20);
		}

    }
}
void emove()
{
	int i;
	for(i=0;i<num; i++){
		if(enemy[i].show){
			//if(rand()%2) continue;
			if(rand()%2){
				if(enemy[i].u && ecollision(i) && collisionWithme(i)){
					if(enemy[i].y>=330) {
						enemy[i].y=330;
					}
					else {
						enemy[i].y+=30;
					}
				}
				else if(enemy[i].r){
                    enemy[i].u=1; enemy[i].r=0;
				}
				else if(enemy[i].l){
					enemy[i].u=1; enemy[i].l=0;
				}
				else if(enemy[i].d){
					enemy[i].u=1; enemy[i].d=0;
				}
			}
			else if(rand()%2){
				if(enemy[i].d && ecollision(i) && collisionWithme(i)) {
					if(enemy[i].y<0){
						enemy[i].y=0;
					}
					else {
						enemy[i].y-=30;
					}
				}
				else if(enemy[i].r){
					enemy[i].d=1; enemy[i].r=0;
				}
				else if(enemy[i].l){
					enemy[i].d=1; enemy[i].l=0;
				}
				else if(enemy[i].u){
					enemy[i].d=1; enemy[i].u=0;
				}
			}
			else if(rand()%2){
				if(enemy[i].r && ecollision(i) && collisionWithme(i)){
					if(enemy[i].x>=510){
						enemy[i].x=510;
					}
					else {
						enemy[i].x+=30;
					}
				}
				else if(enemy[i].u){
					enemy[i].r=1; enemy[i].u=0;
				}
				else if(enemy[i].d){
					enemy[i].r=1;enemy[i].d=0;
				}
				else if(enemy[i].l){
					enemy[i].r=1; enemy[i].l=0;
				}
			}
			else if(rand()%2){
				if(enemy[i].l && ecollision(i) && collisionWithme(i)){
					if(enemy[i].x<=0){
						enemy[i].x=0;
					}
					else {
						enemy[i].x-=30;

					}
				}
				else if(enemy[i].u){
					enemy[i].l=1; enemy[i].u=0;
				}
				else if(enemy[i].d){
					enemy[i].l=1; enemy[i].d=0;
				}
				else if(enemy[i].r){
					enemy[i].l=1; enemy[i].r=0;
				}
			}
		}
	}
}

int ecollision(int i)
{
	int j, x, y;
	if(enemy[i].u) {
		x=enemy[i].x;
		y=enemy[i].y+90;
		for(j=0; j<num; j++){
			if(enemy[j].x>=x-60 && enemy[j].x<=x+60 && enemy[j].y==y){
				return 0;
			}
		}
	}
	else if(enemy[i].d){
		x=enemy[i].x;
		y=enemy[i].y-90;
		for(j=0; j<num; j++){
			if(enemy[j].x>=x-60 && enemy[j].x<=x+60 && enemy[j].y==y){
				return 0;
			}
		}
	}
	else if(enemy[i].l){
		x=enemy[i].x-90;
		y=enemy[i].y;
		for(j=0; j<num; j++){
			if(enemy[j].y>=y-60 && enemy[j].y<=y+60 && enemy[j].x==x){
				return 0;
			}
		}
	}
	else {
		x=enemy[i].x+90;
		y=enemy[i].y;
		for(j=0; j<num; j++){
			if(enemy[j].y>=y-60 && enemy[j].y<=y+60 && enemy[j].x==x){
				return 0;
			}
		}
	}
	return 1;
}


void ebullet()
{
	int i;
	for(i=0; i<num; i++){
		if(enemy[i].show && rand()%2){
			enemy[i].bshow=1;
			if(enemy[i].u){
				enemy[i].u1=enemy[i].u;
				enemy[i].bX=enemy[i].x+30;
				enemy[i].bY=enemy[i].y+60;
			}
			else if(enemy[i].d){
				enemy[i].d1=enemy[i].d;
				enemy[i].bX=enemy[i].x+30;
				enemy[i].bY=enemy[i].y;
			}
			else if(enemy[i].l){
				enemy[i].l1=enemy[i].l;
				enemy[i].bX=enemy[i].x;
				enemy[i].bY=enemy[i].y+30;
			}
			else {
				enemy[i].r1=enemy[i].r;
				enemy[i].bX=enemy[i].x+60;
				enemy[i].bY=enemy[i].y+30;
			}

		}

	}
}

int collisionWithme(int i){
	int x1, y1;
	if(enemy[i].u) {
		x1=enemy[i].x;
		y1=enemy[i].y+90;
		if(x>=x1-60 && x<=x1+60 && y==y1)
			return 0;
	}
	else if(enemy[i].d){
		x1=enemy[i].x;
		y1=enemy[i].y-90;
		if(x>=x1-60 && x<=x1+60 &&y==y1)
			return 0;
	}
	else if(enemy[i].l){
		x1=enemy[i].x-90;
		y1=enemy[i].y;
		if(y>=y1-60 && y<=y1+60 && x==x1)
			return 0;
	}
	else {
		x1=enemy[i].x+90;
		y1=enemy[i].y;
		if(y>=y1-60 &&y<=y1+60 && x==x1)
			return 0;
	}
	return 1;

}

