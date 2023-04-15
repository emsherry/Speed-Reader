#include<iostream>
using namespace std;


class strings{
    char *arr;
    int size=50;
    int strsize;

    public:
    strings()
    {
        strsize=0;
        arr=new char[size];
        arr='\0';
    }
    strings(char a[])
    {
        arr=new char[size];
        arr=a;
        for(int i=0;arr[i]!='\0';i++){
            strsize++;
        }  
    }
    strings(int s){
        size=s+1;
        strsize=s;
    }
    ~strings(){
        delete []arr;
    } 

    int arrsize(){return size;}

    int stringsize(){
        for(int i=0;arr[i]!='\0';i++){
            strsize++;
        }
        return strsize;
    }

    strings operator +(strings const& b){
        strings temp((strsize+b.strsize));
        int i=0,j=0;
        while(arr[i]!='\0'){
            temp.arr[i]=temp.arr[i]+arr[i];
            i++;
        }
        while(b.arr[j]!='\0'){
            temp.arr[i]=temp.arr[i]+b.arr[j];
            i++;
            j++;
        }
        temp.arr[i]='\0';
        return temp;        
    }

    strings operator +=(strings const& b){
        strings temp((strsize+b.strsize));
        int i=0,j=0;
        while(arr[i]!='\0'){
            temp.arr[i]+=arr[i];
            i++;
        }
        while(b.arr[j]!='\0'){
            temp.arr[i]+=b.arr[j];
            i++;
            j++;
        }
        temp.arr[i]='\0';
        return temp;        
    }

    char operator [](int index)
    {

        if (index >= size) {
            cout << "Array index out of bound";
            return '\0';
        }
        else
            return arr[index];
    }

    bool operator ==(strings const& b)
    {
        bool check=false;
        for(int i=0;arr[i]!='\0' && b.arr[i]!='\0';i++){
            if(arr[i]==b.arr[i])
                check=true;
            else
                return false;
        }
        return check;
    }

    bool operator !=(strings const& b)
    {
        for(int i=0;arr[i]!='\0' && b.arr[i]!='\0';i++){
            if(arr[i]!=b.arr[i])
                return true;
        }
        return false;
    }

    bool operator >(strings const& b)
    {
        int i=0;
        while(arr[i]!='\0' && b.arr[i]!='\0'){
            if(arr[i]>b.arr[i]){
                return true;
            }
            i++;
        }
        return false;
    }

    bool operator <(strings const& b){
        int i=0;
        while(arr[i]!='\0' && b.arr[i]!='\0'){
            if(arr[i]<b.arr[i]){
                return true;
            }
            i++;
        }
        return false;
    }

    strings operator ()(int x,int y){
        if(x<0||y<0||x>size||y>size){
            cout<<"Array index out of bound"<<endl;
            return NULL;
        }
        if(y>=x){
            strings temp(y-x+1);
            for(int i=0;x<=y;x++,i++){
                temp.arr[i]=arr[x];
            }
            return temp;
        }
        if(y<x){
            strings temp(x-y+1);
            for(int i=0;y<=x;y++,i++){
                temp.arr[i]=arr[y];
            }
            return temp;
        }
    }

    friend ostream &operator<<( ostream &output, const strings &b ) { 
        output<<"string is: ";
        for(int i=0;i<b.strsize;i++){
            output<<b.arr[i];
        }
        return output;
    }

    friend istream &operator>>( istream &input, strings &b ) { 
        input >> b.arr; 
        return input; 
    }

    void operator =(strings const& b){
        
        int i=0;
        while(b.arr[i]!='\0'){
            arr[i]=b.arr[i];
            i++;
        }
        arr[i]='\0';      
    }

    strings operator <<(int index){
        if(index<0){
            cout<<"Array index out of bound"<<endl;
            return NULL;
        }
        strings temp(index+1);
        int i;
        for(i=0;i<index||arr[i]!='\0';i++){
            temp.arr[i]=arr[i];
        }
        temp.arr[i]='\0';
        int j=0;
        while(arr[i]!='\0'){
            arr[j]=arr[i];
            j++;
            i++;
        }
        arr[j]='\0';
        return temp;
    }

    strings operator >>(int index){
        if(index<0){
            cout<<"Array index out of bound"<<endl;
            return NULL;
        }
        strings temp(index+1);
        int i, j=0;
        for(i=strsize-1;i>(strsize-index-1);i--)
        {
            temp.arr[j]=arr[i];
        }
        temp.arr[j]='\0';
        int k=0;
        while(i!=0){
            arr[k]=arr[i];
            k++;
            i--;
        }
        arr[k]='\0';
        return temp;
    }
};

int main()
{

    int s1=0,s2=0;
    cout<<"Enter the size of  string 1: ";
    cin>>s1;

    strings a(s1);
    strings a("ABCDEFG");
    
    cout<<"Enter the size of  string 2 (greater than 50): ";
    cin>>s2;

    strings b(s2);
    strings b("1234567");


    //string size function
    cout<<"The size of the first string is: "<<a.stringsize()<<endl;
    cout<<"The size of the second string is: "<<b.stringsize()<<endl<<endl;

    //char arr size function
    cout<<"The size of the first character array is: "<<a.arrsize()<<endl;
    cout<<"The size of the second character array is: "<<b.arrsize()<<endl<<endl;

    //+ operator
    cout<<"+ operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    cout<<"The resultant string after concatenation is: "<<a+b<<endl<<endl;

    //+= operator
    cout<<"+= operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    cout<<"The resultant string after concatenation is: "<<(a+=b)<<endl<<endl;

    //[] operator
    cout<<"[] operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    char D=a[1];
    cout<<"The character at index 1 of string a is: "<<D<<endl;
    b[4]=D;
    cout<<"After changing string b is: "<<b<<endl<<endl;

    //== operator
    cout<<"== operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    if(a==b){
        cout<<"The strings are equal"<<endl;
    }
    else{
        cout<<"The strings are not equal"<<endl<<endl;
    }

    //!= operator
    cout<<"!= operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    if(a!=b){
        cout<<"The strings are not equal"<<endl;
    }
    else{
        cout<<"The strings are equal"<<endl<<endl;
    }

    //> operator
    cout<<"> operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    if(a>b){
        cout<<"string a is greater than b"<<endl;
    }
    else{
        cout<<"string a is not greater than b"<<endl<<endl;
    }

    //< operator
    cout<<"< operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    if(a<b){
        cout<<"string a is less than b"<<endl;
    }
    else{
        cout<<"string a is not less than b"<<endl<<endl;
    }

    // () operator
    cout<<"() operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    {
    strings c;
    c=a(0,3);
    cout<<"String a has the following characters in index 0 to 3: "<<c<<endl;
    c=b(2,5);
    cout<<"String b has the following characters in index 2 to 5: "<<c<<endl<<endl;
    }

    // << output operator
    cout<<"<< output operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl<<endl;

    // >> input operator
    cout<<">> input operator: "<<endl;
    cout<<"Enter the first string: ";
    cin>>a;
    cout<<"Enter the second string: ";
    cin>>b;
    cout<<endl<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl<<endl;

    // = operator
    cout<<"= operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    a=b;
    cout<<"string a after assigning b to a is: "<<a<<endl<<endl;

    // << left shift operator
    cout<<"<< left shift operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    {
        strings c;
        c=a<<1;
        cout<<"String C is: "<<c<<endl;
        cout<<"string a after left shit by 1 is: "<<a<<endl;
        c=b<<3;
        cout<<"String C is: "<<c<<endl;
        cout<<"string b after left shit by 3 is: "<<b<<endl<<endl;
    }

    // >> right shift operator
    cout<<"<< right shift operator: "<<endl;
    cout<<"The first string is : "<<a<<endl;
    cout<<"The second string is: "<<b<<endl;
    {
        strings c;
        c=a>>1;
        cout<<"String C is: "<<c<<endl;
        cout<<"string a after right shit by 1 is: "<<a<<endl;
        c=b>>3;
        cout<<"String C is: "<<c<<endl;
        cout<<"string b after right shit by 3 is: "<<b<<endl<<endl;
    }  
    

    return 0;
}