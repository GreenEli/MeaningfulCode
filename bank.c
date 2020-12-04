#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define N 100
//用户性别与用户是否借书不良记录
struct jieshu
{
    char lei[12];
    int  sum;
};
//用户密码，姓名，身份证，电话，和性别，不良记录。
struct people
{
    char number[11];
    char mimi[10];
    char id[10];
    char phone[13];
    struct jieshu leilie;
};
//书籍名字，单价，库存数目，书籍被借数目
struct book
{
    char name[10];
    float price;
    int  number;
    int  jie;
};
//用户借书日期
struct date
{
    int year;
    int mon;
    int day;
};
//shigebankuai
struct shige
{
    char qian[20];
    char hou[20];
};
//用户借书记录，包括借书人密码，用户名字，书籍名称，借书日期。
struct jiesh
{
    char number[11];
    char mimi[10];
    char name[10];
    struct date riqi;
};
typedef struct jiesh jiestru;
typedef struct people peostru;
typedef struct book bostru;
typedef struct shige shistru;
int jianren(peostru s[],int i);//功能：减去图书馆用户。
void jingru(peostru s[],int i,bostru a[],int k,int d,jiestru b[]);//进入管理员系统
void tushu(bostru a[],int k);//显示图书信息。
void yonghu(peostru s[],int i);//显示用户信息。
void jingru1(peostru s[],int i,bostru a[],int k,char r[],char t[],int d,jiestru b[]);//进入用户系统。
int zenjia(peostru s[],int i);//增加图书馆用户。
int zenshu(bostru a[],int k);//增加图书馆书籍信息。
int jianshu(bostru a[],int k);//减去书籍信息。
void chajie(jiestru b[],int d);//显示借书记录给管理员。
int yjie(char r[],char t[],bostru a[],int k,int d,jiestru b[]);//用户进行借书。
int huan(jiestru b[],int d,char r[],char t[],bostru a[],int k);//用户进行还书。
void paixu(bostru a[],int k);//对书籍进行排序。
void xiumi(peostru s[],int i,char r[]);//用户进行密码修改。
void gech(char p[],int d);//不回显输入。
void w96(peostru s[],int i);//写用户信息到9_6.dat文件。
void paixuren(peostru s[],int i);//对用户进行排序。
void w97(bostru a[],int k);//写书籍信息到9_7.dat文件。
void w98(jiestru b[],int d);//写借书情况信息到9_8.dat文件。
int r96(peostru s[],int i);//读取9_6.dat文件到数组。
int r97(bostru a[],int j);//读取9_7.dat文件到数组。
int r98(jiestru b[],int j);//读取9_8.dat文件到数组。
void jisuan();
int add(int sum,int chance);
int sub(int sum,int chance);
int mult(int sum,int chance);
int chu(int sum,int chance);
int zong(int sum,int chance);
void wenyi();
void qushi();

int main()
{
	while(1>0){
    int flag=1,i=0,j=0,k,d;FILE *fp;shistru z[N];
    peostru s[N];bostru a[N];jiestru b[N];
    char r[11],t[10],u[11]="1526201012";
    i=r96(s,i);
    k=r97(a,j);
    d=r98(b,j);
    printf("现在你已进入登入界面，请输入登入号和密码\n");
    gech(r,11);
    scanf("%s",t);
    for(j=0;j<i&&flag==1;j++)
    {
        if(strcmp(s[j].number,r)==0&&strcmp(s[j].mimi,t)==0)
            flag=0;
    }
    j--;
    if(flag==0&&strcmp(s[j].number,u)==0)
    {
        printf("尊敬的银行管理员你好，欢迎进入银行借贷系统，请选择你需要的操作\n");
        jingru(s,i,a,k,d,b);
    }
    else  if(flag==0)
    {
        printf("尊敬的用户你好，欢迎进入银行借贷系统，请选择你需要的操作\n");
        jingru1(s,i,a,k,r,t,d,b);
    }
    else printf("没有此用户\n\n");
    }
    return 0;
}

void jingru1(peostru s[],int i,bostru a[],int k,char r[],char t[],int d,jiestru b[])
{
    int x,o;
    do
    {
    printf("(0),查看借贷产品信息\n");printf("(1)退出系统\n");printf("(2)借贷产品\n");printf("(3)还贷\n");printf("(4)修改密码\n");printf("(5)逻辑游戏\n");
    printf("(6)文艺游戏\n");
    printf("你想选择[    ]\b\b\b");scanf("%d",&x);
        switch(x)
        {
        case 0:tushu(a,k);break;
        case 1:printf("再见\n");break;
        case 2:d=yjie(r,t,a,k,d,b);break;
        case 3:d=huan(b,d,r,t,a,k);break;
        case 4:xiumi(s,i,r);break;
        case 5:jisuan();break;
        case 6:wenyi();break;
        default :printf("无此选项");
        }o=x;printf("请按任意键继续【  】\b\b\b");getch(); system("cls");
        printf("尊敬的用户你好，欢迎进入银行借贷系统，请选择你需要的操作\n");
    }while(o!=1);
}

void jingru(peostru s[],int i,bostru a[],int k,int d,jiestru b[])
{
    int x,o;
    do
    {
    printf("(0),查看借贷产品信息\n");printf("(1)查看用户（贷款者）信息\n");printf("(2)增加用户（贷款者）\n");printf("(3)增加借贷产品\n");printf("(4)删除用户（贷款者）\n");printf("(5)退出系统\n");
    printf("(6)删除借贷产品\n");printf("(7)借贷情况查询\n");printf("(8)查看借贷趋势\n");printf("你想选择[   ]\b\b\b");scanf("%d",&x);
    switch(x)
    {
        case 0:tushu(a,k);break;
        case 1:yonghu(s,i);break;
        case 2:i=zenjia(s,i);break;
        case 3:k=zenshu(a,k);break;
        case 4:i=jianren(s,i);break;
        case 5:printf("再见\n");break;
        case 6:k=jianshu(a,k);break;
        case 7:chajie(b,d);break;
        case 8:qushi();
        default:printf("无此选项");
    }o=x;printf("请按任意键继续【  】\b\b");getch();system("cls");
     printf("尊敬的银行管理员你好，欢迎进入银行借贷系统，请选择你需要的操作\n");
    }while (o!=5);
}

int zenjia(peostru s[],int i)
{
    int j,h,k,flag=1;FILE *fp;
    peostru b;printf("请输入增加的用户信息");
    printf("用户账号[          ]\b\b\b\b\b\b\b\b\b\b\b");scanf("%s",b.number);printf("\n用户密码[          ]\b\b\b\b\b\b\b");
    scanf("%s",b.mimi);printf("\n用户id[           ]\b\b\b\b\b\b\b\b\b\b");scanf("%s",b.id);printf("\n用户电话[          ]\b\b\b\b\b\b\b\b\b");
    scanf("%s",b.phone);printf("\n性别[      ]\b\b\b\b");scanf("%s",b.leilie.lei);printf("\n不良记录次数[      ]\b\b\b\b");
    scanf("%d",&b.leilie.sum);
    for(j=0;j<i;j++)
    if(strcmp(s[j].number,b.number)==0)
        flag=0;
    if(flag!=0)
    {
    i++;s[i-1]=b;paixuren(s,i);w96(s,i);
    }else printf("密码已存在，请换一个尝试\n");
    yonghu(s,i);
    return i;
	}
	
int add(int sum,int chance)
{
    int a,b,c,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%100;
        b=rand()%100;
        c=a+b;
        do
        {
             printf("[%d]%d+%d=",i,a,b);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=c);
        if(answer==c)
            d=good(d);
        else
        {
            printf("正确结果是%d\n",c);
            d+=70;
        }
    }
    return d;
}

int sub(int sum,int chance)
{
    int a,b,c,h,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%100;
        b=rand()%100;
        if(a<b)
        {
           h=a;
           a=b;
           b=h;
        }
        c=a-b;
        do
        {
             printf("[%d]%d-%d=",i,a,b);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=c);
        if(answer==c)
            d=good(d);
         else
        {
            printf("正确结果是%d\n",c);
            d+=70;
        }
    }
    return d;
}

int mult(int sum,int chance)
{
    int a,b,c,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%10;
        b=rand()%10;
        c=a*b;
        do
        {
             printf("[%d]%d*%d=",i,a,b);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=c);
        if(answer==c)
            d=good(d);
         else
        {
            printf("正确结果是%d\n",c);
            d+=70;
        }
    }
    return d;
}

int chu(int sum,int chance)
{
    int a,b,c,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%100+1;
        b=rand()%100;
        c=a*b;
        do
        {
             printf("[%d]%d/%d=",i,c,a);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=b);
        if(answer==b)
           d=good(d);
         else
        {
            printf("正确结果是%d\n",d);
            d+=70;
        }
    }
    return d;
}

int good(int d)
{
    int a;
    srand(time(0));
    a=rand()%30;
    switch(a)
    {
        case 0:printf("你这么牛逼啊！\n");break;
        case 1:printf("你开挂了吧！\n");break;
        case 2:printf("unbelieveble!\n");break;
        case 3:printf("你已经超神了!\n");break;
        case 4:printf("你这是要上天的节奏啊!\n");break;
        case 5:printf("碉堡了!\n");break;
        case 6:printf("可以的！\n");break;
        case 7:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 8:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 9:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 10:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 11:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 12:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 13:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 14:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 15:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 16:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 17:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 18:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 19:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 20:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 21:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 22:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 23:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 24:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        default :printf("谢谢参与！\n");
    }
    return d;
}

int zong(int sum,int chance)
{
    int a,b,c,h,e,f,g,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%1000+1;
        b=rand()%1000;
        c=rand()%1000;
        h=rand()%1000;
        e=rand()%1000;
        f=a*c;
        g=f/a*b+h-e;
        do
        {
             printf("[%d]%d/%d*%d+%d-%d=",i,f,a,b,h,e);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=g);
        if(answer==g)
            d=good(d);
        else
        {
            printf("正确结果是%d\n",g);
            d+=70;
        }
    }
    return d;
}

void tushu(bostru a[],int k)
{
    int j;
    printf("借贷产品  ");  printf("产品单价（万） ");  printf("产品数目 ");  printf("已借出数目\n");
    for(j=0;j<k;j++)
    {
        printf("%-12s",a[j].name);
        printf("%8.2f",a[j].price);
        printf("%8d",a[j].number);
        printf("%8d\n",a[j].jie);
    }
}

void yonghu(peostru s[],int i)
{
    int j;
    printf("   账号  ");printf("    密码  ");printf("    身份证  ");printf("      电话   ");printf("    性别  ");printf("   逾期记录\n");
    for(j=0;j<i;j++)
    {
        printf("%-12s",s[j].number);
        printf("%-12s",s[j].mimi);
        printf("%-12s",s[j].id);
        printf("%-12s",s[j].phone);
        printf("%-4s",s[j].leilie.lei);
        printf("%4d次不良记录\n",s[j].leilie.sum);
    }
}

int zenshu(bostru a[],int k)
{
    bostru c;int j,h;FILE *fp;
    printf("请输入增加的借贷产品信息");
    printf("产品名[         ]\b\b\b\b\b\b\b\b\b");scanf("%s",c.name);printf("\n产品单价（万）[          ]\b\b\b\b\b\b\b");
    scanf("%f",&c.price);printf("\n产品数目[          ]\b\b\b\b\b\b\b\b");scanf("%d",&c.number);printf("\n借出产品数目[          ]\b\b\b\b\b\b\b\b");
    scanf("%d",&c.jie);
    k++;a[k-1]=c;
    paixu(a,k);
    w97(a,k);
     tushu(a,k);
    return k;
}

int jianren(peostru s[],int i)
{
       FILE *fp;
       char r[11];int flag=1,j;
       printf("输入你想删除的用户账号[         ]\b\b\b\b\b\b\b\b");scanf("%s",r);
       for(j=0;j<i&&flag;j++)
       {
            if(strcmp(s[j].number,r)==0)
                flag=0;
       }
       if(flag==0)
       {
            j--;
           while(j<=i-2)
           {
                s[j]=s[j+1];
                j++;
           }
           i--;
           w96(s,i);
          yonghu(s,i);
        }
        else
            printf("没有这个用户");
        return i;
}

int jianshu(bostru a[],int k)
    {
        char r[10];int i,flag=1,j;
        FILE *fp;
        printf("请输入你要删减的借贷产品名称[           ]\b\b\b\b\b\b\b\b\b");
        scanf("%s",r);
        for(i=0;i<k&&flag;i++)
        {
            if(strcmp(a[i].name,r)==0)
                flag=0;
        }
        if(flag==0)
        {
            i--;
            for(j=i;j<k-1;j++)
            {
                a[j]=a[j+1];
            } k--;
            w97(a,k);
            tushu(a,k);
        }
        else
            printf("没有该产品\n");
            return k;

    }

void chajie(jiestru b[],int d)
{
    int j;
    printf("       账号     ");printf("    密码    ");printf("  产品名称   ");printf("    借贷日期   \n");
    for(j=0;j<d;j++)
    {
        printf("%12s",b[j].number);
        printf("%12s",b[j].mimi);
        printf("%12s",b[j].name);
        printf("    %d年",b[j].riqi.year);
        printf("%d月",b[j].riqi.mon);
        printf("%d日\n",b[j].riqi.day);
    }
}

int yjie(char r[],char t[],bostru a[],int k,int d,jiestru b[])
{
    int i,flag=1;jiestru g;time_t nowtime;
    char f[10];struct tm *m;FILE *fp;
    time(&nowtime);
    m=localtime(&nowtime);
    printf("请输入你想借的产品\n");
    scanf("%s",f);
    for(i=0;i<k&&flag;i++)
    {
        if(strcmp(a[i].name,f)==0)
            flag=0;
    }
    if(flag==0&&a[i-1].number>a[i-1].jie)
    {
        d++;a[i-1].jie++;w97(a,k);
       strcpy(g.number,r);strcpy(g.mimi,t);strcpy(g.name,f);
       g.riqi.year=m->tm_year+1900;
       g.riqi.mon=m->tm_mon+1;
       g.riqi.day=m->tm_mday;b[d-1]=g;
       fp=fopen("9_8.dat","ab");
       if(fp!=NULL)
       {
           fwrite(&g,sizeof(jiestru),1,fp);
           fclose(fp);
       }
       printf("输入成功\n");
    }
    else if(flag==0&&a[i-1].number==a[i-1].jie)
        printf("已经没有该种产品了\n");
    else printf("输入失败\n");return d;
}

int huan(jiestru b[],int d,char r[],char t[],bostru a[],int k)
{
    char n[10];int i,flag=1,j;FILE *fp;
    printf("请输入你借贷的产品，我们进行利息计算\n");scanf("%s",n);
    for(i=0;i<d&&flag;i++)
    {
        if(strcmp(b[i].number,r)==0&&strcmp(b[i].mimi,t)==0&&strcmp(b[i].name,n)==0)
            flag=0;
    }
    i--;
    if(flag==0)
    {
        for(j=i;j<d-1;j++)
        b[j]=b[j+1];d--;
        for(j=0;j<k;j++)
        {
            if(strcmp(a[j].name,n)==0)
            a[j].jie--;
        }w97(a,k);
    }
    else printf("  对不起，您的输入不匹配\n");
    if(flag==0)
        w98(b,d);
    else printf("输入不符合\n");
     chajie(b,d);return d;
}

void paixu(bostru a[],int k)
{
    int i;bostru d;
    while(k>1)
    {
        for(i=0;i<k-1;i++)
        if(strcmp(a[i].name,a[i+1].name)>0)
        {
            d=a[i];
            a[i]=a[i+1];
            a[i+1]=d;
        }k--;
    }
}

void xiumi(peostru s[],int i,char r[])
{
    char p[11],q[11];int j,d,flag=1;FILE *fp;
    printf("欢迎进入密码修改页面,请输入原密码【               】\b\b\b\b\b\b\b\b\b\b");
    gech(p,11);
    for(j=0;j<i&&flag;j++)
    {
        if(strcmp(s[j].number,r)==0)
        flag=0;
    }
    j--;d=j;
    if(strcmp(s[j].number,p)==0)
    {
        printf("\n验证通过,请输入你想的密码，有效数字10位\n");
        gech(p,11);flag=1;
        for(j=0;j<i&&flag;j++)
        if(strcmp(s[j].number,p)==0)
        flag=0;
        if(flag==1)
        {
        printf("\n请再次输入密码确定");
        gech(q,11);
        if(strcmp(p,q)==0)
        {
            strcpy(s[d].number,p);
            printf("\n输入成功，密码已更换\n");
            w96(s,i);
        }
        else printf("密码输入不一致\n");
        } else printf("密码已存在，请换一个密码\n");
    }
    else printf("密码验证失败\n");
}

void gech(char p[],int d)
{
    int j;
    for(j=0;j<10;j++)
    {
    p[j]=getch();printf("*");
    }
    p[d-1]='\0';
}

void w96(peostru s[],int i)
{
    FILE *fp;fp=fopen("9_6.dat","wb");
    if(fp!=NULL)
    {
    fwrite(s,sizeof(peostru),i,fp);
    fclose(fp);
    }
    else printf("文件打开失败\n");
}

void paixuren(peostru s[],int i)
{
    peostru v;int j;
    while(i>1)
    {
        for(j=0;j<i-1;j++)
        {
            if(strcmp(s[j].number,s[j+1].number)>0)
            {
                v=s[j];s[j]=s[j+1];s[j+1]=v;
            }
        }i--;
    }
}

void w97(bostru a[],int k)
{
    FILE *fp;fp=fopen("9_7.dat","wb");
    if(fp!=NULL)
    {
    fwrite(a,sizeof(bostru),k,fp);
    fclose(fp);
    }
    else printf("文件打开失败\n");
}

void w98(jiestru b[],int d)
{
    FILE *fp;
    fp=fopen("9_8.dat","wb");
        if(fp!=NULL)
        {
            fwrite(b,sizeof(jiestru),d,fp);
            fclose(fp);
        }
        else printf("文件打开失败\n");
}

int r96(peostru s[],int i)
{   int k;FILE *fp;
    fp=fopen("9_6.dat","rb");
    if(fp!=NULL)
    {
        while(1)
        {
            k=fread(s+i,sizeof(peostru),1,fp);
            if(k==1) i++;
            else break;
        }
        fclose(fp);
    }
    else printf("文件打开失败\n");
    return i;
}

int r97(bostru a[],int j)
{
    FILE *fp;int k;
    fp=fopen("9_7.dat","rb");
    if(fp!=NULL)
    {
       while(1)
       {
           k=fread(a+j,sizeof(bostru),1,fp);
           if(k==1) j++;
           else break;
       }
        fclose(fp);
    }
    else printf("文件打开失败\n");
    return j;
}

int r98(jiestru b[],int j)
{
    FILE *fp;int e;
    fp=fopen("9_8.dat","rb");
    if(fp!=NULL)
    {
        while(1)
        {
        e=fread(b+j,sizeof(jiestru),1,fp);
        if(e==1) j++;
        else break;
        }
        fclose(fp);
    }
    else printf("文件打开失败\n");
    return j;
}

void jisuan()
{
    int sum,chance,select,d,x,y;
    time_t r,s;
    r=time(0);
    printf("\n");
    printf("学生算术游戏1.0版\n");
    printf("\n");
    printf("         **研发人员，拥有自主知识产权，侵权必究**\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&人物时间算术指标 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("&    7/15,22题刘强958s，11题刘娜480s，刘智1400s(不具代表性)【5】           &\n");
    printf("&    7/16,12道题目刘智用时不详，刘娜用时780s,徐志辉用时690s【5】           &\n");
    printf("&    7/17,13道题目，刘智用时782s，刘娜用时850S,20题刘强1053s【5】          &\n");
    printf("&    7/17，14题刘智1030 刘娜1400 【5】贝贝1400 刘强 750或 180&【1】        &\n");
    printf("&    7/19，15题刘智970 刘娜968 【5】贝贝171s 25题刘强1100s   &【1】        &\n");
    printf("&    7/23,18题【5】刘娜750s,刘智974s30题【5】1466s 10题 【2】奥比700s      &\n");
    printf("&    7/24,19题【5】刘强759s刘娜918s刘智1027s                               &\n");
    printf("&    7/25,20题【5】刘强881s刘智1300s刘娜1700s                              &\n");
    printf("&    7/26,21题【5】刘强702s刘智1117s刘娜1118S                              &\n");
    printf("&    7/28,11题,[+5],刘智2157s，刘娜2302s                                   &\n");
    printf("&    7/29,12题，【+5】，刘强1403s ,刘娜1888s,刘智1960s                     &\n");
    printf("&    7/30.12刘娜1376s,刘强1383s刘智 1833s\n                                &\n");
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    printf("你想设置多少答题量\n");
        scanf("%d",&sum);
    printf("你想设置多少次答题机会\n");
        scanf("%d",&chance);
    printf("[1]加法\n");
    printf("[2]减法\n");
    printf("[3]乘法\n");
    printf("[4]除法\n");
    printf("[5]综合法\n");
    scanf("%d",&select);
        switch(select)
    {
        case 1:d=add(sum,chance);break;
        case 2:d=sub(sum,chance);break;
        case 3:d=mult(sum,chance);break;
        case 4:d=chu(sum,chance);break;
        case 5:d=zong(sum,chance);break;
    }
    s=time(0);
    printf("你的用时为%d秒,现在你要加上奖励或惩罚的时间了！\n",s-r);
    printf("这个时间为：");
    scanf("%d",&x);
    while(x!=s-r+d-100000)
        {
        printf("啊呀，对不起，你答错了！\n");
        scanf("%d",&x);
        }
        y=time(0);
    printf("算上计时这个的时间，你的综合用时总和为%d秒\n",y-r+d-100000);
}

int add1(int sum,int chance)
{
    int a,b,c,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%100;
        b=rand()%100;
        c=a+b;
        do
        {
             printf("[%d]%d+%d=",i,a,b);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=c);
        if(answer==c)
            d=good(d);
        else
        {
            printf("正确结果是%d\n",c);
            d+=70;
        }
    }
    return d;
}

int sub1(int sum,int chance)
{
    int a,b,c,h,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%100;
        b=rand()%100;
        if(a<b)
        {
           h=a;
           a=b;
           b=h;
        }
        c=a-b;
        do
        {
             printf("[%d]%d-%d=",i,a,b);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=c);
        if(answer==c)
            d=good(d);
         else
        {
            printf("正确结果是%d\n",c);
            d+=70;
        }
    }
    return d;
}

int mult1(int sum,int chance)
{
    int a,b,c,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%10;
        b=rand()%10;
        c=a*b;
        do
        {
             printf("[%d]%d*%d=",i,a,b);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=c);
        if(answer==c)
            d=good(d);
         else
        {
            printf("正确结果是%d\n",c);
            d+=70;
        }
    }
    return d;
}

int chu1(int sum,int chance)
{
    int a,b,c,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%100+1;
        b=rand()%100;
        c=a*b;
        do
        {
             printf("[%d]%d/%d=",i,c,a);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=b);
        if(answer==b)
           d=good(d);
         else
        {
            printf("正确结果是%d\n",d);
            d+=70;
        }
    }
    return d;
}

int good1(int d)
{
    int a;
    srand(time(0));
    a=rand()%30;
    switch(a)
    {
        case 0:printf("你这么牛逼啊！\n");break;
        case 1:printf("你开挂了吧！\n");break;
        case 2:printf("unbelieveble!\n");break;
        case 3:printf("你已经超神了!\n");break;
        case 4:printf("你这是要上天的节奏啊!\n");break;
        case 5:printf("碉堡了!\n");break;
        case 6:printf("可以的！\n");break;
        case 7:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 8:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 9:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 10:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 11:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 12:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 13:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 14:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 15:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 16:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 17:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 18:printf("恭喜，减去%d秒\n",a);d-=a;break;
        case 19:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 20:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 21:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 22:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 23:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        case 24:printf("倒霉，加上%d秒\n",a/2);d+=a/2;break;
        default :printf("谢谢参与！\n");
    }
    return d;
}

int zong1(int sum,int chance)
{
    int a,b,c,h,e,f,g,i,answer,counter,d=100000;
    srand(time(0));
    for(i=1;i<=sum;i++)
    {
        counter=1;
        a=rand()%1000+1;
        b=rand()%1000;
        c=rand()%1000;
        h=rand()%1000;
        e=rand()%1000;
        f=a*c;
        g=f/a*b+h-e;
        do
        {
             printf("[%d]%d/%d*%d+%d-%d=",i,f,a,b,h,e);
             scanf("%d",&answer);
             counter++;
        }while(counter<=chance&&answer!=g);
        if(answer==g)
            d=good(d);
        else
        {
            printf("正确结果是%d\n",g);
            d+=70;
        }
    }
    return d;
}

void qushi()
{
printf(" ^\n");
printf("6|\n");
printf("5|\n");
printf("4|\n");
printf("3|\n");
printf("2|  \n");
printf("1|  *   *\n");
printf(" ---------------------------->(7月份借贷情况）\n");
printf(" 刘强 刘佳\n\n");
printf(" ^\n");
printf("6|\n");
printf("5|\n");
printf("4|\n");
printf("3|\n");
printf("2|  \n");
printf("1|  *   *    *    *\n");
printf(" ---------------------------->(8月份借贷情况）\n");
printf(" 刘智 刘娜 宁波 刘佳\n\n");
printf(" ^\n");
printf("6|\n");
printf("5|\n");
printf("4|\n");
printf("3|                 *\n");
printf("2|  *    *    *    *\n");
printf("1|  *    *    *    *\n");
printf(" ---------------------------->(9月份借贷情况）\n");
printf(" 宁波  小川  利川 刘异\n\n");
printf("  ^\n");
printf("11|\n");
printf("10|\n");
printf(" 9|                   *\n");
printf(" 8|                   *\n");
printf(" 7|                   *\n");
printf(" 6|                   *\n");
printf(" 5|                   *\n");
printf(" 4|         *         *\n");
printf(" 3|         *         *\n");
printf(" 2|  *      *         *\n");
printf(" 1|  *      *         *\n");
printf("  ---------------------------->(第四季度借贷情况）\n");
printf("    七月份  八月份  九月份\n");
}

void wenyi()
{
    int x,i=0,a,k;FILE *fp;
    shistru z[N];char d[20];
    fp=fopen("9_10.dat","rb");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            k=fread(z+i,sizeof(shistru),1,fp);
            if(k==1) i++;
        }
        fclose(fp);
    }
    printf("请输入你想做的题目数量\n");scanf("%d",&x);
    while(x)
    {
        srand(time(0));
        a=rand()%6;
        switch(a)
        {
            case 0:printf("\n%s\n",z[0].qian);scanf("%s",d);
            if(strcmp(z[0].hou,d)==0) printf("输入正确,进入下一题\n");
            else printf("%16s",z[0].hou);break;
            case 1:printf("\n%s\n",z[1].qian);scanf("%s",d);
            if(strcmp(z[1].hou,d)==0) printf("输入正确,进入下一题\n");
            else printf("%16s",z[1].hou);break;
            case 2:printf("\n%s\n",z[2].qian);scanf("%s",d);
            if(strcmp(z[2].hou,d)==0) printf("输入正确,进入下一题\n");
            else printf("%16s",z[2].hou);break;
            case 3:printf("\n%s\n",z[3].qian);scanf("%s",d);
            if(strcmp(z[3].hou,d)==0) printf("输入正确,进入下一题\n");
            else printf("%16s",z[3].hou);break;
            case 4:printf("\n%s\n",z[4].qian);scanf("%s",d);
            if(strcmp(z[4].hou,d)==0) printf("输入正确,进入下一题\n");
            else printf("%16s",z[4].hou);break;
            case 5:printf("\n%s\n",z[5].qian);scanf("%s",d);
            if(strcmp(z[5].hou,d)==0) printf("输入正确,进入下一题\n");
            else printf("%16s",z[5].hou);break;
        }
        x--;
    }
}
