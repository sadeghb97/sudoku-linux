#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"
int checksudo(int [10][10]);
void printsudo(int [10][10],int);
int cms (int [10][10], int,int);
int finderror (int [10][10]);
int cmser (int[10][10],int,int);
void save(FILE *,int[10][10]);
void load(FILE *,int[10][10]);
int sumar(int[],int);
int tasaviar(char[],const char[]);
int main(){
	int sudo[10][10],i,j,choice,amar[26],pishraft,o,enter;
	char str[20];
	FILE *fp,*sv ,*st;
	sv=0; fp=0; st=0;
	menu:
	st=fopen("stat.bin","rb");
	fread (amar,sizeof(int),26,st);
	fclose(st); st=0;
	pishraft=sumar(amar,26);
	printf (BOLDRED "Be name khoda.\n" ANSI_COLOR_RESET);
	printf ("Salam. Be bazie sudoko khosh umadin.\n\n\n");
	printf (BOLDRED "Rahnamaye hengame bazi:\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "1: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "Baraye vared kardane adad dar jadval ebteda shomare satr,sepas shomare sotun va dar nahayat adade morede nazar ra vared konid.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "2: " ANSI_COLOR_RESET);
	printf ("Baraye hazfe yek khane adadi gheir az adade 1 ta 9 dar an gharar dahid.\n");
	printf (BOLDGREEN "3: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "Namayeshe jomle Error be in manist ke dar yek satr,sotun ya yek morabae kuchak yek adad do bar tekrar shode ast.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "4: " ANSI_COLOR_RESET);
	printf ("Agar adade 0 va sepas yek adade yek raghami vared konid tamame khane haei ke adade dovom dar an ast rangi mishavad.\n");
	printf (BOLDGREEN "5: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "Baraye save kardane bazi adade 10 ra vared konid.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "6: " ANSI_COLOR_RESET);
	printf ("Baraye load kardane akharin sudoko save shodeh adade 11 ra vared konid.\n");
	printf (BOLDGREEN "7: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "Baraye bazgasht be menuye asliye bazi va motaleeye rahnama adade 20 va baraye raftan be safhe entekhabe sudoko adade 30 ra vared konid.\n\n\n" ANSI_COLOR_RESET);
	
	printf (BOLDRED "Amare Bazi: \n" ANSI_COLOR_RESET);
	printf ("Shoma ta konun movafagh be hale %d sudoko az beine 25 sudoko shode id.\n",pishraft);
	printf (ANSI_COLOR_CYAN "Meghdare pishraft dar bazi:" BOLDCYAN " %d",pishraft*4);
	printf(ANSI_COLOR_RESET "");
	printf(BOLDCYAN "%\n" ANSI_COLOR_RESET);
	for(i=0; pishraft>i; i++) printf(BOLDGREEN "*" ANSI_COLOR_RESET);
	for(i=0; (25-pishraft)>i; i++) printf ("*");
	printf ("\n\n");
	
	printf("Baraye edame yek adad be delkhah vared konid. ");
	scanf("%d" ,&enter);
	entekhab:
	system ("clear");
	printf (BOLDRED "chenan ke amade bazi hastid shomare sudoko morede nazaretan ra vared konid.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "Nokte 1: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "Sudoko haye shomare 1-10 sade, shomare haye 11-15 motevaset, shomare haye 16-20 sakht va shomare haye 21-25 besiar sakht hastand.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "Nokte 2: " ANSI_COLOR_RESET);
	printf ("Ba vared kardane adade 0 akharin sudoko save shode load khahad shod.\n");
	printf (BOLDGREEN "Nokte 3: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN"Agar mikhahid bazi ra az ebteda shoru konid va hameye sudoko ha hal nashodeh shavand ebteda adade 100 va sepas ebarate " ANSI_COLOR_RESET);
	printf (BOLDMAGENTA "'delete' " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "ra vared konid.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "Nokte 4: " ANSI_COLOR_RESET);
	printf ("Baraye bargasht be menuye asliye bazi ebteda adade 100 va sepas ebarate ");
	printf (BOLDMAGENTA "'main' " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "ra vared konid.\n" ANSI_COLOR_RESET);
	printf (BOLDGREEN "Nokte 5: " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN"Baraye etela az in ke ta konun kodam sudoko ha ra hal va kodam sudoko hara hal nakarde id ebteda adade 100 va sepas ebarate " ANSI_COLOR_RESET);
	printf (BOLDMAGENTA "'stat' " ANSI_COLOR_RESET);
	printf (ANSI_COLOR_CYAN "ra vared konid.\n" ANSI_COLOR_RESET);
	scanf ("%d" ,& choice);
	while ((choice>25 || choice<0) && choice!=100){
		printf ("\nShoma bayad yek adad beine 0 ta 25 ya adade 100 ra entekhab konid. Dobare vared konid: \n");
		scanf ("%d" ,& choice);
	}
	switch (choice){
		case 0: fp = fopen("save.bin","rb");
		break;
		case 1: fp = fopen("sudo1.bin","rb");
		break;
		case 2: fp = fopen("sudo2.bin","rb");
		break;
		case 3: fp = fopen("sudo3.bin","rb"); 
		break;
		case 4: fp = fopen("sudo4.bin","rb");
		break;
		case 5: fp = fopen("sudo5.bin","rb");
		break;
		case 6: fp = fopen("sudo6.bin","rb");
		break;
		case 7: fp = fopen("sudo7.bin","rb");
		break;
		case 8: fp = fopen("sudo8.bin","rb");
		break;
		case 9: fp = fopen("sudo9.bin","rb"); 
		break;
		case 10: fp = fopen("sudo10.bin","rb");
		break;
		case 11: fp = fopen("sudo11.bin","rb");
		break;
		case 12: fp = fopen("sudo12.bin","rb");
		break;
		case 13: fp = fopen("sudo13.bin","rb");
		break;
		case 14: fp = fopen("sudo14.bin","rb");
		break;
		case 15: fp = fopen("sudo15.bin","rb"); 
		break;
		case 16: fp = fopen("sudo16.bin","rb");
		break;
		case 17: fp = fopen("sudo17.bin","rb");
		break;
		case 18: fp = fopen("sudo18.bin","rb");
		break;
		case 19: fp = fopen("sudo19.bin","rb");
		break;
		case 20: fp = fopen("sudo20.bin","rb");
		break;
		case 21: fp = fopen("sudo21.bin","rb"); 
		break;
		case 22: fp = fopen("sudo22.bin","rb");
		break;
		case 23: fp = fopen("sudo23.bin","rb");
		break;
		case 24: fp = fopen("sudo24.bin","rb");
		break;
		case 25: fp = fopen("sudo25.bin","rb");
		break;
		case 100:
		scanf("%s", str);
		if (tasaviar(str,"delete") == 1){
			for(i=0; 26>i; i++) amar[i] = 0;
			st=fopen("stat.bin","wb");
			fwrite(amar,sizeof(int),26,st);
			fclose(st); st=0;
			system ("clear");
			goto menu;
		}
		else if (tasaviar(str,"main") == 1){
			system ("clear");
			goto menu;
		}
		else if (tasaviar(str,"stat") == 1){
			system ("clear");
			o=1;
			printf(BOLDCYAN " --------------------------\n" ANSI_COLOR_RESET);
			for(i=0; 5>i; i++){
				printf(BOLDCYAN " |" ANSI_COLOR_RESET);
				for(j=0; 5>j; j++){
					if (amar[o]==0){
						if(o<10) printf (" 0%d ",o);
						else if(o>9) printf (" %d ",o);
					}
					else if (amar[o]==1){
						if(o<10){
							printf (BOLDYELLOW " 0%d ",o);
							printf (ANSI_COLOR_RESET "");
						}
						else if(o>9){
							printf (BOLDYELLOW " %d ",o);
							printf (ANSI_COLOR_RESET "");
						}
					}
					printf(BOLDCYAN "|" ANSI_COLOR_RESET);
					o++;
				}
				printf("\n");
				printf(BOLDCYAN " --------------------------\n" ANSI_COLOR_RESET);
			}
			printf(ANSI_COLOR_CYAN "\n Khane haei ke ba range" ANSI_COLOR_RESET);
			printf(ANSI_COLOR_YELLOW " zard" ANSI_COLOR_RESET);
			printf(ANSI_COLOR_CYAN " moshakhas shode hal shode and.\n" ANSI_COLOR_RESET);
			printf(" Baraye bargashtan be safhe entekhabe sudoko ha yek adad be delkhah vared konid.\n");
			scanf("%d" ,& enter);
			goto entekhab;
		}
		else goto entekhab;
		break;
	}
	system ("clear");
	fread(&sudo,sizeof(int),100,fp);
	fclose(fp); fp=0;
	printsudo(sudo,0);
	while (checksudo(sudo) != 1){
		if (finderror(sudo) ==0) printf (" ERROR!!!\n");
		printf (" Satr|Sotun|Adad: ");
		scanf ("%d" ,&i);
		if (i>0 && i<10){
			scanf ("%d" ,&j);
	    	scanf ("%d" ,& sudo[i][j]);
	    	system ("clear");
    		printsudo (sudo,sudo[i][j]);
		}
		else if(i==0){
			scanf ("%d" ,&j);
			system ("clear");
			printsudo (sudo,j);
		}
		else if(i==10){
			save(sv,sudo);
			system("clear");
			printsudo(sudo,0);
			printf (" Saved.\n");
		}
		else if(i==11){
			load(sv,sudo);
			system("clear");
			printsudo(sudo,0);
			printf (" Loaded.\n");
		}
		else if(i==20){
			system("clear");
			goto menu;
		}
		else if(i==30){
			system("clear");
			goto entekhab;
		}
	}
	if (checksudo(sudo)==1) printf (BOLDCYAN " Tabrik be shoma. Shoma movafagh shodid sudoko ra hal konid.\n\n" ANSI_COLOR_RESET);
	amar[sudo[0][0]]=1;
	st = fopen("stat.bin","wb");
	fwrite(amar,sizeof(int),26,st);
	fclose(st); st=0;
	printf (" Baraye Bargashtan be menuye asliye bazi adade 1, baraye raftan be safhe entekhabe sudoko adade 2 va baraye khoruj adade digari vared konid:\n");
	scanf("%d" ,& enter);
	if (enter==1){
		system ("clear");
		goto menu;
	}
	else if (enter==2){
		st=fopen("stat.bin","rb");
		fread (amar,sizeof(int),26,st);
		fclose(st); st=0;
		pishraft=sumar(amar,26);
		goto entekhab;
	}
	return 0;
}
void printsudo(int a[10][10],int c){
	int i,j;
	printf (BOLDYELLOW" -------------------------------------\n"ANSI_COLOR_RESET);
	for (i=1; 10>i; i++){
		printf (BOLDYELLOW" | "ANSI_COLOR_RESET);
		for (j=1; 10>j; j++){
			if (a[i][j] > 0 && a[i][j] < 10){
				if (a[i][j]!= c) printf ("%d " , a[i][j]);
				else printf (ANSI_COLOR_MAGENTA "%d ",a[i][j]);
			}
			else printf ("  ");
			if (j/3*3==j) printf (BOLDYELLOW"| "ANSI_COLOR_RESET);
			else printf (ANSI_COLOR_CYAN"| "ANSI_COLOR_RESET);
		}
		if (i/3*3==i) printf (BOLDYELLOW"\n -------------------------------------\n"ANSI_COLOR_RESET);
		else printf (ANSI_COLOR_CYAN"\n -------------------------------------\n"ANSI_COLOR_RESET);
	}
}
int cms (int a[10][10],int i,int j){
	int w,w2,check=1,c,t=0;
	for (c=1; 10>c && check ==1; c++){
		t = 0;
		for (w=i; i+3>w; w++){
			for (w2=j; j+3>w2; w2++){
				if(a[w][w2]== c) t++;
			}
		}
		if (t != 1) check =0;
	}
	return check;
}
int checksudo (int a[10][10]){
	int check=1,i,j,c,t=0;
	for(i=1; 10>i && check==1; i++){
		for (j=1; 10>j; j++){
			if (a[i][j] < 1 || a[i][j] > 9) check=0;
		}
	}
	for (i=1; 10>i && check ==1; i++){
		for (c=1; 10>c; c++){
			t=0;
			for (j=1; 10>j; j++){
				if (a[i][j] == c) t++;
			}
			if (t != 1) check =0;
		}
	}
	for (j=1; 10>j && check ==1; j++){
		for (c=1; 10>c; c++){
			t=0;
			for (i=1; 10>i; i++){
				if (a[i][j] == c) t++;
			}
			if (t != 1) check =0;
		}
	}
	if (check==1 && cms(a,1,1) == 0) check =0;
	if (check==1 && cms(a,1,4) == 0) check =0;
	if (check==1 && cms(a,1,7) == 0) check =0;
	if (check==1 && cms(a,4,1) == 0) check =0;
	if (check==1 && cms(a,4,4) == 0) check =0;
	if (check==1 && cms(a,4,7) == 0) check =0;
	if (check==1 && cms(a,7,1) == 0) check =0;
	if (check==1 && cms(a,7,4) == 0) check =0;
	if (check==1 && cms(a,7,7) == 0) check =0;
	return check;
}
int cmser (int a[10][10],int i,int j){
	int w,w2,check=1,c,t=0;
	for (c=1; 10>c && check ==1; c++){
		t = 0;
		for (w=i; i+3>w; w++){
			for (w2=j; j+3>w2; w2++){
				if(a[w][w2]== c) t++;
			}
		}
		if (t > 1) check =0;
	}
	return check;
}
int finderror (int a[10][10]){
	int check=1, c, i, j, t=0;
	for (i=1; 10>i && check ==1; i++){
		for (c=1; 10>c; c++){
			t=0;
			for (j=1; 10>j; j++){
				if (a[i][j] == c) t++;
			}
			if (t > 1) check =0;
		}
	}
	for (j=1; 10>j && check ==1; j++){
		for (c=1; 10>c; c++){
			t=0;
			for (i=1; 10>i; i++){
				if (a[i][j] == c) t++;
			}
			if (t > 1) check =0;
		}
	}
	if (check==1 && cmser(a,1,1) == 0) check =0;
	if (check==1 && cmser(a,1,4) == 0) check =0;
	if (check==1 && cmser(a,1,7) == 0) check =0;
	if (check==1 && cmser(a,4,1) == 0) check =0;
	if (check==1 && cmser(a,4,4) == 0) check =0;
	if (check==1 && cmser(a,4,7) == 0) check =0;
	if (check==1 && cmser(a,7,1) == 0) check =0;
	if (check==1 && cmser(a,7,4) == 0) check =0;
	if (check==1 && cmser(a,7,7) == 0) check =0;
	return check;
}
void save(FILE *f, int a[10][10]){
	f=fopen("save.bin","wb");
	fwrite(a,sizeof(int),100,f);
	fclose(f); f=0;
}
void load(FILE *f,int a[10][10]){
	printf ("1\n");
	f=fopen("save.bin","rb");
	fread(a,sizeof(int),100,f);
	printf ("2\n");
	fclose(f); f=0;
}
int sumar(int a[],int n){
	int i,sum=0;
	for(i=0; n>i; i++) sum=sum+a[i];
	return sum;
}
int tasaviar(char a[],const char b[]){
	int i,check;
	for(i=0,check=1; b[i]!=0 && a[i]!=0; i++){
		if(a[i] != b[i]) return 0;
	}
	if (a[i]!=0 || b[i]!=0) check=0;
	return check;
}
