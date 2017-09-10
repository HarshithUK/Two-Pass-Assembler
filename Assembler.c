//Group Assignment of C : Conversion of Assembly Language to its Hexadecimal Equivalent
//SECTION : K - Computer Science - B-Tech
//By
//1.NAME : Udupi Katte Harshith
//SRN : 01FB14ECS268
//2.NAME : Abhimanyu A.
//SRN : 01FB14ECS005
//3.NAME : Akshay J.S
//SRN : 01FB14ECS020
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int c=0;
struct foo//The Symbol Table to store the constants and labels
{
    char a;
    int val;
    int address;
    char str[5];
}foo[5];
void display(FILE *fp)//To display the contents of the file
{
    char ch;
    while(!feof(fp))
    {
		ch = fgetc(fp);
		printf("%c", ch);
	}
}
int binary1(char z)//for the conversion of hexadecimal no. to binary no.
{
    switch(z)
    {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 10;
        case '3' : return 11;
        case '4' : return 100;
        case '5' : return 101;
        case '6' : return 110;
        case '7' : return 111;
        case '8' : return 1000;
        case '9' : return 1001;
        case 'A' : return 1010;
        case 'B' : return 1011;
        case 'C' : return 1100;
        case 'D' : return 1101;
        case 'E' : return 1110;
        case 'F' : return 1111;
        default : return -1;
    }
}
char hexadecimal(int n)//for the conversion of binary no. to hexadecimal no.
{
    if(n==0) return '0';
    else if(n==1) return '1';
    else if(n==10) return '2';
    else if(n==11) return '3';
    else if(n==100) return '4';
    else if(n==101) return '5';
    else if(n==110) return '6';
    else if(n==111) return '7';
    else if(n==1000) return '8';
    else if(n==1001) return '9';
    else if(n==1010) return 'A';
    else if(n==1011) return 'B';
    else if(n==1100) return 'C';
    else if(n==1101) return 'D';
    else if(n==1110) return 'E';
    else if(n==1111) return 'F';
}
int toint(char z)//for conversion of number character to number integer
{
    switch(z)
    {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        default : return -1;
    }
}
char toch(int n)
{
    switch(n)
    {
        case 0 : return '0';
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
        default : return 'Z';
    }
}
void hextobin(FILE *f,int n)//for the conversion of hexadecimal no. to binary no.
{
    int d,e=-1;
    int t,h,g,l;
    char z;
    t=n;
    while(t!=0)
    {
        t/=10;
        ++e;
    }
    t=n;
    g=0;
    if(e==0)
    {
        printf("\n%.12d",g);
        fprintf(f,"%.12d",g);
    }
    else if(e==1)
    {
        printf("\n%.8d",g);
        fprintf(f,"%.8d",g);
    }
    else if(e==2)
    {
        printf("\n%.4d",g);
        fprintf(f,"%.4d",g);
    }
    while(t!=0)
    {
        l=e;
        h=1;
        while(l!=0)
        {
            h*=10;
            --l;
        }
        d=t/h;
        z=toch(d);
        g=binary1(z);
        printf("%.4d",g);
        fprintf(f,"%.4d",g);
        t%=h;
        --e;
        if(t==0)
        {
            g=0;
            if(e==0)
            {
                printf("%.4d",g);
                fprintf(f,"%.4d",g);
            }
            else if(e==1)
            {
                printf("%.8d",g);
                fprintf(f,"%.8d",g);
            }
        }
    }
}
long int opcode(char ch[])//the symbol table of a given mnemonic to return its opcode
{
    if(ch[0]=='N'&&ch[1]=='E'&&ch[2]=='G')
        return 0;
    else if(ch[0]=='A'&&ch[1]=='N'&&ch[2]=='D')
        return 1;
    else if(ch[0]=='X'&&ch[1]=='O'&&ch[2]=='R')
        return 10;
    else if(ch[0]=='O'&&ch[1]=='R')
        return 11;
    else if(ch[0]=='L'&&ch[1]=='S'&&ch[2]=='R')
        return 100;
    else if(ch[0]=='L'&&ch[1]=='S'&&ch[2]=='L')
        return 101;
    else if(ch[0]=='H'&&ch[1]=='L'&&ch[2]=='T')
        return 1010;
    else if(ch[0]=='M'&&ch[1]=='O'&&ch[2]=='V')
        return 1101;
    else if(ch[0]=='J'&&ch[1]=='M'&&ch[2]=='P')
        return 1111;
    else if(ch[0]=='A'&&ch[1]=='D'&&ch[2]=='D')
        return 10000;
    else if(ch[0]=='S'&&ch[1]=='U'&&ch[2]=='B')
        return 10001;
    else return -1;
}
long int dec_to_bin(int t)//For the conversion of decimal number to its binary equivalent number
{
    int n,e,i=0,j,p=0;
    int a[10];
    long int o=0,k=1;
    n=t;
    while(n!=0)
    {
        e=n%2;
        a[i]=e;
        n/=2;
        ++i;
    }
    p=i-1;
    while(p!=0)
    {
        k*=10;
        p--;
    }
    for(j=i-1;j>=0;--j)
    {
        o+=(a[j]*k);
        k/=10;
    }
    return o;
}
void TwoPassAssembly(char ch[],int *a)//The first pass to store the constants and labels
{
    int i=0,j,l,d=0,e=0;
    int k=0,t[4];
    char s[4],h;
    while(ch[i]!='\0')
    {
        if(ch[i]==' '&&ch[i-1]!=':'&&ch[i+1]=='D')
        {
            if(ch[i+2]=='C')
            {
                for(j=0;ch[i+4+j]!='\0';++j)
                {
                    s[j]=ch[i+4+j];
                    t[j]=toint(s[j]);
                }
                j--;
                if(t[j]==-1)
                {
                    j--;
                }
                while(j!=-1)
                {
                    l=d;
                    k=1;
                    while(l!=0)
                    {
                        k*=10;
                        --l;
                    }
                    e+=(t[j]*k);
                    --j;
                    d++;
                }
                h=ch[i-1];
                foo[c].a=h;
                foo[c].val=e;
                foo[c].address=*a;
                ++c;
            }
            else if(ch[i+2]=='S')
            {
                for(j=0;ch[i+4+j]!='\0';++j)
                {
                    s[j]=ch[i+4+j];
                    t[j]=toint(s[j]);
                }
                j--;
                while(j!=-1)
                {
                    l=d;
                    k=1;
                    while(l!=0)
                    {
                        k*=10;
                        --l;
                    }
                    e+=(t[j]*k);
                    j--;
                    d++;
                }
                h=ch[i-1];
                foo[c].a=h;
                foo[c].val=0;
                foo[c].address=*a;
                ++c;
                d=0;
                if(e!=-1)
                {
                    *a+=2;
                    --e;
                }
            }
        }
        else if(ch[i]==':')
        {
            for(j=0;j<i;++j)
            {
                s[j]=ch[j];
            }
            strcpy(foo[c].str,s);
            foo[c].address=*a;
            c++;
        }
        else if(ch[i]=='&'||ch[i]=='#')
        {
            *a+=2;
        }
        ++i;
    }
}
void convert(char ch[],FILE *f,int c)//the main conversion process - the Second Pass
{
    f = fopen("temp.txt","a");
    int i=0,j;
    int d,e,l=0,t,x;
    char p,q,z;
    int a[5];
    char s[5];
    long int o=0;
    while(ch[i]!='\0')
    {
        if(ch[i]==' '&&i>=3&&ch[i-1]!='C'&&ch[i-1]!='S'&&i<=5)
        {
            for(j=0;j<i;++j)
            {
                s[j]=ch[j];
            }
            o=opcode(s);
            if(o==-1)
            {
                printf("Invalid !");
                exit(0);
            }
            d=o%100;
            e=o/100;
            printf("\n%.4d",e);
            printf("%.2d ",d);
            fprintf(f,"%.4d",e);
            fprintf(f,"%.2d",d);
        }
        else if(ch[i]=='R')
        {
            if(ch[i-1]==' '||ch[i-1]==',')
            {
                e=0;
                d=toint(ch[i+1]);
                z=toch(d);
                d=binary1(z);
                printf("%.3d",d);
                printf("%.2d ",e);
                fprintf(f,"%.3d",d);
                fprintf(f,"%.2d",e);
            }
            else if(ch[i-1]=='*')
            {
                e=1;
                d=toint(ch[i+1]);
                z=toch(d);
                d=binary1(z);
                printf("%.3d",d);
                printf("%.2d ",e);
                fprintf(f,"%.3d",d);
                fprintf(f,"%.2d",e);
            }
        }
        else if(ch[i]=='#')
        {
            e=10;
            printf("%.5d",e);
            fprintf(f,"%.5d",e);
            j=0;
            i++;
            while(ch[i]!='\n')
            {
                a[j]=toint(ch[i]);
                j++;
                i++;
            }
            --j;
            d=0;
            e=0;
            while(j!=-1)
            {
                l=d;
                t=1;
                while(l!=0)
                {
                    t*=10;
                    --l;
                }
                e+=(a[j]*t);
                j--;
                d++;
            }
            hextobin(f,e);
        }
        else if(ch[i]=='&'&&ch[i-1]==',')
        {
            e=10;
            printf("%.5d",e);
            fprintf(f,"%.5d",e);
            for(j=0;j<c;++j)
            {
                if(foo[j].a==ch[i+1])
                {
                        t=foo[j].address;
                        if(t==0)
                        {
                            printf("\n%.16d",t);
                            fprintf(f,"%.16d",t);
                        }
                        else
                        {
                            x=t;
                            while(t!=0)
                            {
                                 t/=16;
                                 ++l;
                            }
                            o=dec_to_bin(x);
                            if(l==1)
                            {
                                printf("\n%.12d",t);
                                fprintf(f,"%.12d",t);
                                printf("%.4ld",o);
                                fprintf(f,"%.4ld",o);
                            }
                            else if(l==2)
                            {
                                printf("\n%.8d",t);
                                fprintf(f,"%.8d",t);
                                printf("%.8ld",o);
                                fprintf(f,"%.8ld",o);
                            }
                            else if(l==3)
                            {
                                printf("\n%.4d",t);
                                fprintf(f,"%.4d",t);
                                printf("%.12ld",o);
                                fprintf(f,"%.12ld",o);
                            }
                        }
                }
            }
        }
        else if(ch[i]=='D'&&ch[i-1]==' ')
        {
            if(ch[i+1]=='C')
            {
                for(j=0;j<c;++j)
                {
                    if(foo[j].a==ch[i-2])
                    {
                        t=foo[j].val;
                        hextobin(f,t);
                    }
                }
            }
            else if(ch[i+1]=='S')
            {
                for(j=0;j<c;++j)
                {
                    if(foo[j].a==ch[i-2])
                    {
                        p=ch[i+3];
                        t=toint(p);
                        d=0;
                        while(t!=0)
                        {
                            printf("\n%.16d",d);
                            fprintf(f,"%.16d",d);
                            --t;
                        }
                    }
                }
            }
        }
        else if(ch[i-1]==' '&&ch[i-2]==':')
        {
            j=0;
            while(ch[i+j+1]!='R')
            {
                s[j]=ch[i+j];
                j++;
            }
            o=opcode(s);
            if(o==-1)
            {
                printf("Invalid !");
                exit(0);
            }
            d=o%100;
            e=o/100;
            printf("\n%.4d",e);
            printf("%.2d ",d);
            fprintf(f,"%.4d",e);
            fprintf(f,"%.2d",d);
        }
        if(ch[i-3]=='J'&&ch[i-2]=='M'&&ch[i-1]=='P')
        {
            t=0;
            e=0;
            printf("%.10d",e);
            fprintf(f,"%.10d",e);
            for(j=0;ch[i+j+1]!='\0';++j)
            {
                s[j]=ch[i+j+1];
                ++t;
            }
            for(l=0;l<c;++l)
            {
                if(foo[l].a=='\0')
                {
                    for(j=0;j<t;++j)
                    {
                        if(foo[l].str[j]==s[j])
                        {
                            ++e;
                        }
                        if(e==t-1&&x!=1)
                        {
                            d=foo[l].address;
                            o=dec_to_bin(d);
                            printf("\n%.16d",o);
                            fprintf(f,"%.16d",o);
                            x=1;
                        }
                    }
                }
            }
        }
        ++i;
        if(ch[i]=='\0')
        {
            for(j=0;j<i;++j)
            {
                s[j]=ch[j];
            }
            o=opcode(s);
            if(s[0]=='H'&&s[1]=='L'&&s[2]=='T')
            {
                d=o%100;
                e=o/100;
                printf("\n%.4d",e);
                printf("%.2d ",d);
                fprintf(f,"%.4d",e);
                fprintf(f,"%.2d",d);
                e=0;
                printf("%.10d",e);
                fprintf(f,"%.10d",e);
            }
        }
    }
    fclose(f);
}
void bintohex(FILE *f)//To convert the binary number to its hexadecimal equivalent
{
    int num[500],i=0,t=0,k=1;
    int r=0,l,g,h;
    char j;
    f = fopen("temp.txt","r");
    while((j = fgetc(f))!=EOF)
    {
        num[i]=toint(j);
        ++i;
    }
    printf("\n");
    for(l=1;l<=i;++l)
    {
        if(l%4==0)
        {
            t=0;
            k=1;
            g=3;
            while(g!=-1&&k!=10000)
            {
                h=g+r;
                t+=(num[h]*k);
                k*=10;
                --g;
            }
            r+=4;
            j=hexadecimal(t);
            printf("%c",j);
            if(l%16==0&&l!=0)
            {
                printf("\n");
            }
        }
    }
}
int main()
{
	FILE *  fp = fopen("file.txt", "r");
	FILE *f = fopen("temp.txt","w");
	char ch[100],file[10];
	int pc=0,i;
	int *a=&pc;
	printf("Enter the file name :");
	gets(file);
	fp = fopen(file,"r");
	printf("\nThe contents of the file you have entered is:\n");
	display(fp);
	rewind(fp);
	printf("\n\nThe binary equivalent of its machine language code is:\n");
	while((fgets(ch,20,fp))!=NULL)
    {
        TwoPassAssembly(ch,a);
        pc+=2;
    }
    rewind(fp);
    while((fgets(ch,20,fp))!=NULL)
    {
        convert(ch,f,c);
    }
    printf("\n\nThe hexadecimal equivalent of its machine language code is:\n");
    bintohex(f);
	fclose(fp);
	fclose(f);
	return 0;
}
