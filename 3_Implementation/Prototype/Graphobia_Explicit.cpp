#include<conio.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<ctype.h>
#include<graphics.h>
#include<process.h>

#define e 2.71828
#define pi 3.14159
#define size 30

float Lx=-10,Ux=10,Ly=-10,Uy=10,prsn=10;
char fn1[2*size],fn2[2*size],fn3[size];
float num[25];


class Stack
{
  private:
    char stack1[size];
    float stack2[size];
    int top;
  public:
    void push(char);   //for stack1
    void push(float);  //for stack2
    char pop();        //for stack1
    float pop(int&);   //for stack2
    char getTop();
    void update();
}s;

enum error
{
  NONE,
  BRACE,
  NUMBER,
  FUNCTION,
  OPERATOR,
  OTHER
}err=NONE;


void Screen();
void Menu();
void Graph();
void Settings();
void Help();
void Credits();
void Input();
void Output();
void codeExp1();
void codeExp2();
char codeFn(char[]);
float DecodeFn1(char&,float);
float DecodeFn2(char&,float,float);
float getY(float,int&);
void braceChk(char[]);
int precdnce(char);
void ErrManager();


void main()
{
  Screen();
  char ch;
  textcolor(GREEN);
  do
  {
    clrscr();
    cout<<"\n\n\n\t\t\t\t  MENU\n";
    for(int i=0;i<80;i++)
      cout<<"_";
    cout<<"\n\n\t\t\t\t1.Graph"
	<<"\n\n\t\t\t\t2.Settings"
	<<"\n\n\t\t\t\t3.Help"
	<<"\n\n\t\t\t\t4.Credits"
	<<"\n\n\t\t\t\t5.Exit\n";
    for(i=0;i<80;i++)
      cout<<"_";
    cout<<"\n\n\t\t\tEnter your choice : ";
    cin>>ch;
    switch(ch)
    {
      case '1':
	Graph();
	break;
      case '2':
	Settings();
	break;
      case '3':
	Help();
	break;
      case '4':
	Credits();
	break;
    }
  }while(ch!='5');
  Screen();
}


void Graph()
{
  Input();
  codeExp1();
  braceChk(fn2);
  if(err)
    ErrManager();
  else
  {
    codeExp2();
    Output();
  }
}


void Settings()
{
  char ch;
  float a,b;
  do
  {
    clrscr();
    cout<<"\n\n\n\t\t\t\t  SETTINGS\n";
    for(int i=0;i<80;i++)
      cout<<"_";
    cout<<"\n\n\t\t\t\t1.Alter Domain"
	<<"\n\n\t\t\t\t2.Alter Range"
	<<"\n\n\t\t\t\t3.Alter Precision"
	<<"\n\n\t\t\t\t4.Back to Menu\n";
    for(i=0;i<80;i++)
      cout<<"_";
    cout<<"\n\n\t\t\tEnter your choice : ";
    cin>>ch;
    clrscr();
    cout<<"\n\n\n\t\t\t";
    switch(ch)
    {
      case '1':
	cout<<"Current Domain : ["<<Lx<<","<<Ux<<"]";
	cout<<"\n\n\t\t\tEnter New lower limit : ";
	cin>>a;
	cout<<"\n\t\t\tEnter New upper limit : ";
	cin>>b;
	cout<<"\n\t\t\t";
	if(a>=b)
	  cout<<"Illegal Domain";
	else
	{
	  Lx=a;
	  Ux=b;
	  cout<<"Domain changed successfully";
	  cout<<"\n\n\t\t\tNew Domain : ["<<Lx<<","<<Ux<<"]";
	}
	getch();
	break;
      case '2':
	cout<<"Current Range : ["<<Ly<<","<<Uy<<"]";
	cout<<"\n\n\t\t\tEnter New lower limit : ";
	cin>>a;
	cout<<"\n\t\t\tEnter New upper limit : ";
	cin>>b;
	cout<<"\n\t\t\t";
	if(a>=b)
	  cout<<"Illegal Range";
	else
	{
	  Ly=a;
	  Uy=b;
	  cout<<"Range changed successfully";
	  cout<<"\n\n\t\t\tNew Range : ["<<Ly<<","<<Uy<<"]";
	}
	getch();
	break;
      case '3':
	cout<<"Current Precision : "<<prsn;
	cout<<"\n\n\t\t\t"
	    <<"Enter New Precision : ";
	cin>>a;
	cout<<"\n\t\t\t";
	if(a<=0)
	  cout<<"Illegal Precision";
	else
	{
	  prsn=a;
	  cout<<"Precision changed successfully";
	  cout<<"\n\n\t\t\tNew Precision : "<<prsn;
	}
	getch();
	break;
    }
  }while(ch!='4');
}


void Help()
{
  char ch;
  do
  {
    clrscr();
    cout<<"\n\n\n\t\t\t\t     HELP\n";
    for(int i=0;i<80;i++)
      cout<<"_";
    cout<<"\n\n\t\t\t\t1.Basic Operators"
	<<"\n\n\t\t\t\t2.Legal Functions"
	<<"\n\n\t\t\t\t3.Instructions"
	<<"\n\n\t\t\t\t4.Back to Menu\n";
    for(i=0;i<80;i++)
      cout<<"_";
    cout<<"\n\n\t\t\tEnter your choice : ";
    cin>>ch;
    clrscr();
    switch(ch)
    {
      case '1':
	cout<<"\n\n\n\t\t\t\tBASIC OPERATORS\n";
	for(i=0;i<80;i++)
	  cout<<"_";
	cout<<"\n\n\t\t\t+  .................  Addition"
	    <<"\n\n\t\t\t-  ..............  Subtraction"
	    <<"\n\n\t\t\t*  ...........  Multiplication"
	    <<"\n\n\t\t\t\\  .................  Division"
	    <<"\n\n\t\t\t^  .................  Exponent";
	getch();
	break;
      case '2':
	cout<<"\n\t\t\t\t LEGAL FUNCTIONS\n";
	for(i=0;i<80;i++)
	  cout<<"_";
	cout<<"\n\n\tsin.................Sine"<<"\t\tasin.............Arc Sine"
	    <<"\n\ttan..............Tangent"<<"\t\tatan..........Arc Tangent"
	    <<"\n\tsec...............Secant"<<"\t\tasec...........Arc Secant"
	    <<"\n\tcosec...........Cosecant"<<"\t\tacosec.......Arc Cosecant"
	    <<"\n\tcos...............Cosine"<<"\t\tacos...........Arc Cosine"
	    <<"\n\tcot............Cotangent"<<"\t\tacot........Arc Cotangent\n"
	    <<"\n\n\tsinh.....Hyperbolic Sine"<<"\t\t[]....Greatest Integer Fn"
	    <<"\n\tcosh...Hyperbolic Cosine"<<"\t\t{}.....Fractional Part Fn"
	    <<"\n\ttanh..Hyperbolic Tangent"<<"\t\tsgn.............Signum Fn\n"
	    <<"\n\n\tlog.....Common Logarithm"<<"\t\tmod...............Modulus"
	    <<"\n\tln......Natural Logarithm";
	getch();
	break;
      case '3':
	cout<<"\n\n\n\t   INSTRUCTIONS\n";
	for(i=0;i<80;i++)
	  cout<<"_";
	cout<<"\n\n\t1.The function should be uni varient"
	    <<"\n\n\t2.The independent variable should be x"
	    <<"\n\n\t3.Predefined Functions should contain parenthesis '()'"
	    <<"\n\n\t4.Errors due to domain exceeding may occur"
	    <<"\n\n\t5.Adjust domain,range,precision to get appropriate graph"
	    <<"\n\n\t6.Mathematical constants 'e' and 'pi' are pre defined" ;
	getch();
	break;
    }
 }while(ch!='4');
}


void Credits()
{
  const int R=200,r=200/3,N=400,n=200;
  float X,Y,x,y;
  clrscr();
  int gdriver=DETECT,gmode,i;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
  if(graphresult()!=grOk)
    goto Z;
  X=getmaxx()/2;
  Y=getmaxy()/2;
  setcolor(RED);
  for(i=0;i<N;i++)
  {
    x=X+2*R*cos(i*2*pi/N);
    y=Y+2*R*sin(i*2*pi/N);
    circle(x,y,R);
  }
  for(i=0;i<n;i++)
  {
    x=X+2*r*cos(i*2*pi/n);
    y=Y+2*r*sin(i*2*pi/n);
    circle(x,y,r);
  }
  settextstyle(9,HORIZ_DIR,4);
  outtextxy(X-55,Y-35,"G");
  delay(300);
  outtextxy(X-15,Y-35,"T");
  delay(300);
  outtextxy(X+25,Y-35,"G");
  delay(300);
  Z:
  getch();
  closegraph();
}


void Screen()
{
  int X,Y;
  float x;
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
  if(graphresult()!=grOk)
    goto Z;
  X=getmaxx();
  Y=getmaxy();
 /* for(x=0;x<5*pi;x+=0.01)
  {
    putpixel(50*x,50*sin(x)+Y/2,GREEN);
  }*/
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  settextstyle(10, HORIZ_DIR, 7);
  setcolor(RED);
  outtextxy(X/2,Y/2-50,"GRAPHOBIA");
  setfillstyle(LTSLASH_FILL,RED);
  floodfill(0,0,RED);
  floodfill(125,200,RED);
  floodfill(400,200,RED);
  floodfill(275,200,RED);
  floodfill(200,210,RED);
  floodfill(450,200,RED);
  floodfill(450,220,RED);
  floodfill(550,210,RED);
  delay(2000);
  Z:
  closegraph();
}

void Input()
{
  err=NONE;
  clrscr();
  cout<<"\n\n\n\t\t\tEnter your function : "
      <<"\n\n\n\t\t\tf(x) = ";
  int i=0;
  while(1)
  {
    char c=1;
    c=getche();
    if(c==8)
    {
      if(i>0)
      {
	i-=1;
	cout<<" \b";
      }
      else
	cout<<" ";
    }
    else if(c==13)
    {
      fn1[i]='\0';
      break;
    }
    else if(!isspace(c))
      fn1[i++]=c;
  }
}


void codeExp1()
{
  int i,j,k,l,r;
  char c,str[10];
  num[0]=0;
  for(i=j=k=l=r=0; ;i++)
  {
    if(fn1[i]=='.')
      r=-1;
    else if(isdigit(fn1[i]))
    {
      if(r<0)
	num[k]+=(fn1[i]-48)*pow10(r--);
      else if(++r)
	num[k]=num[k]*10+fn1[i]-48;
    }
    else
    {
      if(r==-1)
      {
	err=NUMBER;
	goto Z;
      }
      else if(r)
      {
	fn2[j++]=48+k;
	num[++k]=0;
	r=0;
      }
    }

    if(fn1[i]=='x'||fn1[i]=='X')
    {
      if(l||r)
      {
	err=OTHER;
	goto Z;
      }
      fn2[j++]='x';
      continue;
    }

    if(isalpha(fn1[i]))
      str[l++]=fn1[i];
    else if(l)
    {
      str[l]='\0';
      l=0;
      c=codeFn(str);
      if(c=='X')
      {
	err=FUNCTION;
	goto Z;
      }
      else if(isupper(c))
	fn2[j++]=c;
      else
      {
	fn2[j++]=48+k;
	num[k++]=(c=='p')?pi:e;
      }
    }

    if(!isalnum(fn1[i]))
    {
      switch(fn1[i])
      {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
	  fn2[j++]=fn1[i];
	  break;
	case '[':
	  fn2[j++]='U';
	  fn2[j++]='(';
	  break;
	case '{':
	  fn2[j++]='V';
	  fn2[j++]='(';
	  break;
	case '}':
	case ']':
	  fn2[j++]=')';
	  break;
	case '.':
	case '\0':
	  break;
	default:
	  err=OPERATOR;
	  goto Z;
      }
    }
    if(fn1[i]=='\0')
      break;
  }
  Z:
  fn2[j]='\0';
}


void codeExp2()
{
  char ele,popd;
  int pre;
  s.update();
  for(int i=0,j=0; fn2[i]!='\0'; i++)
  {
    if(isdigit(fn2[i])||fn2[i]=='x')
      fn3[j++]=fn2[i];
    else if(fn2[i]=='(')
      s.push(fn2[i]);
    else if(fn2[i]==')')
      while((popd=s.pop())!='(')
	fn3[j++]=popd;
    else
    {
      pre=precdnce(fn2[i]);
      ele=s.getTop();
      if(pre>precdnce(ele))
      {
	if(fn2[i]=='-')
	{
	  if(i==0)
	    s.push('~');  //negation or unary minus
	  else if(!isdigit(fn2[i-1])&&fn2[i-1]!='x')
	    s.push('~');  //negation or unary minus
	  else
	    s.push('-');  //binary minus
	}
	else if(fn2[i]=='+')
	{
	  if(i==0);
	  else if(!isdigit(fn2[i-1])&&fn2[i-1]!='x');
	  else
	    s.push('+');  //binary plus
	}
	else
	  s.push(fn2[i]);
      }
      else
      {
	while(pre<=precdnce(ele))
	{
	  if(ele=='!') //stack empty
	    break;
	  popd=s.pop();
	  ele=s.getTop();
	  fn3[j++]=popd;
	}
	if(fn2[i]=='-')
	{
	  if(i==0)
	    s.push('~');  //negation or unary minus
	  else if(!isdigit(fn2[i-1])&&fn2[i-1]!='x')
	    s.push('~');  //negation or unary minus
	  else
	    s.push('-');  //binary minus
	}
	else if(fn2[i]=='+')
	{
	  if(i==0);
	  else if(!isdigit(fn2[i-1])&&fn2[i-1]!='x');
	  else
	    s.push('+');  //binary minus
	}
	else
	  s.push(fn2[i]);
      }
    }
  }
  while((popd=s.pop())!='!')
    fn3[j++]=popd;
  fn3[j]='\0';
}


char codeFn(char str[])
{
  if(strlen(str)>6)
    return 'X';
  else
  {
    if(!strcmp(str,"e"))
      return 'e';
    else if(!strcmp(str,"pi"))
      return 'p';
    else if(!strcmp(str,"asin"))
      return 'A';
    else if(!strcmp(str,"acos"))
      return 'B';
    else if(!strcmp(str,"atan"))
      return 'C';
    else if(!strcmp(str,"acot"))
      return 'D';
    else if(!strcmp(str,"asec"))
      return 'E';
    else if(!strcmp(str,"acosec"))
      return 'F';
    else if(!strcmp(str,"sin"))
      return 'G';
    else if(!strcmp(str,"cos"))
      return 'H';
    else if(!strcmp(str,"tan"))
      return 'I';
    else if(!strcmp(str,"cot"))
      return 'J';
    else if(!strcmp(str,"sec"))
      return 'K';
    else if(!strcmp(str,"cosec"))
      return 'L';
    else if(!strcmp(str,"sinh"))
      return 'M';
    else if(!strcmp(str,"cosh"))
      return 'N';
    else if(!strcmp(str,"tanh"))
      return 'O';
    else if(!strcmp(str,"ln"))
      return 'P';
    else if(!strcmp(str,"log"))
      return 'Q';
    else if(!strcmp(str,"mod"))
      return 'R';
/*    else if(!strcmp(str,"min"))
      return 'S';                //must include comma operator for min,max
    else if(!strcmp(str,"max"))
      return 'T';           */
    else if(!strcmp(str,"sgn"))
      return 'W';
    else
      return 'X';      //dont use U,V,X &lowercase
  }
}

float DecodeFn1(char &fn,float x)  //puts fn='X'if x out of domain
{
  float y=0;
  switch(fn)
  {
    case 'A':   //arc sine
      if(x>=-1&&x<=1)
	y=asin(x);
      else
	fn='X';
      break;
    case 'B':  //arc cosine
      if(x>=-1&&x<=1)
	y=acos(x);
      else
	fn='X';
      break;
    case 'C':  //arc tangent
      y=atan(x);
      break;
    case 'D':  //arc cotangent
      y=pi/2-atan(x);
      break;
    case 'E':  //arc secant
      if(x<=-1||x>=1)
	y=acos(1/x);
      else
	fn='X';
      break;
    case 'F':  //arc cosecant
      if(x<=-1||x>=1)
	y=asin(1/x);
      else
	fn='X';
      break;
    case 'G':  //sine
      y=sin(x);
      break;
    case 'H':  //cosine
      y=cos(x);
      break;
    case 'I':  //tangent
      if(cos(x)!=0)
	y=tan(x);
      else
	fn='X';
      break;
    case 'J':  //cotangent
      if(tan(x)!=0)
	y=1/tan(x);
      else
	fn='X';
      break;
    case 'K':  //secant
      if(cos(x)!=0)
	y=1/cos(x);
      else
	fn='X';
      break;
    case 'L':  //cosecant
      if(sin(x)!=0)
	y=1/sin(x);
      else
	fn='X';
      break;
    case 'M':  //hyperbolic sine
      y=sinh(x);
      if(y==HUGE_VAL)
	fn='X';
      break;
    case 'N':  //hyperbolic cosine
      y=cosh(x);
      if(y==HUGE_VAL)
	fn='X';
      break;
    case 'O':  //hyperbolic tangent
      y=tanh(x);
      break;
    case 'P':  //natural logarithm
      if(x>0)
	y=log(x);
      else
	fn='X';
      break;
    case 'Q':  //common logarithm
      if(x>0)
	y=log10(x);
      else
	fn='X';
      break;
    case 'R':  //modulus
      if(x>0)
	y=x;
      else
	y=-x;
      break;
    //min,max cant b  calcultd in tis fn
    case 'U':  //greatest int fn
      y=floor(x);
      break;
    case 'V':  //fractional part fn
      y=x-floor(x);
      break;
    case 'W':  //signum fn
      if(x>0)
	y=1;
      else if(x<0)
	y=-1;
      else
	y=0;
      break;
    case '~':  //negation
      y=-x;
      break;
    default:
      fn='X';
  }
  return y;
}


float DecodeFn2(char &fn,float x1,float x2)
{
  float y=0;
  switch(fn)
  {
    case '+':
      y=x1+x2;
      break;
    case '-':
      y=x1-x2;
      break;
    case '*':
      y=x1*x2;
      break;
    case '/':
      if(x2!=0)
	y=x1/x2;
      else
	fn='X';
      break;
    case '^':
      if((x1==0&&x2==0)||(x1<0&&(x2-floor(x2))!=0))
	fn='X';
      else
	y=pow(x1,x2);
      break;
    default:
      fn='X';
  }
  return y;
}


void Output()
{
  int gdriver = DETECT, gmode, errorcode;
  int X,Y;
  float x,dy,dx;
  errorcode = graphresult();
  initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
  if (errorcode != grOk)
  {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);    /* terminate with an error code */
  }
  X = getmaxx();
  Y = getmaxy();
  dx=(Ux-Lx)/X;
  dy=(Uy-Ly)/Y;
  setcolor(GREEN);
  if(Lx*Ux<0)
    line(-Lx/dx,0,-Lx/dx,Y);
  if(Ly*Uy<0)
    line(0,Uy/dy,X,Uy/dy);
  for(x=Lx; x<=Ux; x+=dx/prsn)
  {
    int flag=1;
    int y=getY(x,flag);
    if(flag&&y<=Uy&&y>=Ly)
      putpixel((x-Lx)/dx,(Uy-y)/dy,RED);
  }
  getch();
  closegraph();
}


float getY(float x,int &flag)
{
  float popd1,popd2;
  char temp;
  float y=0;
  int flag1=1;
  s.update();
  for(int i=0; fn3[i]!='\0'; i++)
  {
    if(isdigit(fn3[i]))
      s.push(num[fn3[i]-48]);
    else if(fn3[i]=='x')
      s.push(x);
    else if(isalpha(fn3[i])||fn3[i]=='~')
    {
      popd1=s.pop(flag1);
      temp=fn3[i];
      y=DecodeFn1(temp,popd1);
      if(temp=='X')
	break;
      s.push(y);
    }
    else
    {
      popd1=s.pop(flag1);
      popd2=s.pop(flag1);
      temp=fn3[i];
      y=DecodeFn2(temp,popd2,popd1);
      if(temp=='X')
	break;
      s.push(y);
    }
  }
  y=s.pop(flag1);
  if(temp=='X')
    flag=0;
  return y;
}


void braceChk(char str[])
{
  int Lt=0,Rt=0;
  for(int i=0; str[i]!='\0'; i++)
  {
    if(str[i]=='(')
      Lt++;
    else if(str[i]==')')
      Rt++;
  }
  if(Rt!=Lt)
    err=BRACE;
}


int precdnce(char oper)
{
  if(oper=='~')
    return 7;
  else if(isalpha(oper))
    return 6;
  else
    switch(oper)
    {
      case '^':
	return 5;
      case '/':
	return 4;
      case '*':
	return 3;
      case '+':
	return 2;
      case '-':
	return 1;
      default:
	return 0;
    }
}


void ErrManager()
{
  switch(err)
  {
    case 1:
      cout<<"\n\n\t\t\tError:Unbalanced braces.";
      break;
    case 2:
      cout<<"\n\n\t\t\tError:Numerical problem.";
      break;
    case 3:
      cout<<"\n\n\t\t\tError:Illegal functions.";
      break;
    case 4:
      cout<<"\n\n\t\t\tError:Illegal operators.";
      break;
    default:
      cout<<"\n\n\t\t\tError:Invalid Entry.";
  }
  getch();
}


void Stack::push(char ele)
{
  if(top!=size-1)
  {
    top++;
    stack1[top]=ele;
  }
}


char Stack::pop()
{
  if(top!=-1)
  {
    char ret=stack1[top];
    top--;
    return ret;
  }
  else
    return '!';
}


void Stack::push(float ele)
{
  if(top!=size-1)
  {
    top++;
    stack2[top]=ele;
  }
}


float Stack::pop(int &flag)
{
  float ret=0;
  if(top!=-1)
  {
    ret=stack2[top];
    top--;
  }
  else
    flag=0;
  return ret;
}


char Stack::getTop()
{
  if(top!=-1)
    return stack1[top];
  else
    return '!';
}


void Stack::update()
{
  top=-1;
}

