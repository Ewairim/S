#include"shell.h"

/**
*interactive-returnstrueifshellisintermode
*@info:structaddress
*
*Return:1ifinteractivemode,0otherwise
*/
intinteractive(info_t*info)
{
return(isatty(STDIN_FILENO)&&info->readfd<=2);
}

/**
*is_delim-checksifcharisadelim
*@c:thechartocheck
*@delim:thedelimstring
*Return:1iftrue,0iffalse
*/
intis_delim(charc,char*delim)
{
while(*delim)
if(*delim++==c)
return(1);
return(0);
}

/**
*_isalpha-checksforalphabeticcharacter
*@c:Thecharactertoinput
*Return:1ifcisalphabetic,0otherwise
*/

int_isalpha(intc)
{
if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
return(1);
else
return(0);
}

/**
*_atoi-convertsastringtoaninteger
*@s:thestringtobeconverted
*Return:0ifnonumbersinstring,convertednumberotherwise
*/

int_atoi(char*s)
{
inti,sign=1,flag=0,output;
unsignedintresult=0;

for(i=0;s[i]!='\0'&&flag!=2;i++)
{
if(s[i]=='-')
sign*=-1;

if(s[i]>='0'&&s[i]<='9')
{
flag=1;
result*=10;
result+=(s[i]-'0');
}
elseif(flag==1)
flag=2;
}

if(sign==-1)
output=-result;
else
output=result;

return(output);
}
