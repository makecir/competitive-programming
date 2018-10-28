string alrep(string str,string b,string a){
    int itr=0;
    while(str.find(b,itr)!=string::npos){
        itr=str.find(b,itr);
        str.replace(itr,b.size(),a);
        itr+=a.size();
    }
    return str;
}

int gcd(int x, int y)
{
    int r;
    while((r=x%y)!=0)
    {
        x=y;
        y=r;
    }
    return y;
}