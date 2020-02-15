#include <iostream>

using namespace std;

int pow1(int x, int y) {
    if (y<=0) { return 1; }
    return x * pow1(x,y-1);
}

int powmod1(int x, int y, int m) {
    return  pow1(x,y) % m;
}


int powmod2(int x, int y, int m){
    // code here
    if(y<=0){return 1;}
    return (powmod2(x,y-1,m)*x) % m;
}

int powmod3(int x, int y, int m){
    // code here
    if(y<=0){return 1;}
    if(y%2==0){
         return (powmod3(x,y/2,m)*powmod3(x,y/2,m)) % m;
    }
   else{
     return (powmod3(x,(y-1)/2,m)*powmod3(x,(y-1)/2,m)*x) % m;
   }
}

int powmod2loop(int x, int y, int m) {
    int ans = 1 % m;
    for ( int i=0; i<y; i++ ) {
        ans = ( ans * x ) % m ;
    }
    return ans;
}


int powmod3loop(int x, int y, int m){
    // code here
    int p=1;
    if(y>=2){
            for(int i=1;i<=y;i++){
        p=p*2;
            }
    }
    //cout <<p<<endl;
    int ans=1%m;
    while(p>0){
        //ans=((ans*ans)-ans)%m;
        //ans=(ans-ans%m)*(ans-ans%m);
        //ans=(ans*ans)-(ans*ans)%m;
         if(y>=p){
            y=y-p;
            ans = ( ans * x ) % m ;
        }
        p=p/2;
  }
  return ans;
}


/*
 * returns 1 if either of the inputs x,y is negative or if m <= 0
 * otherwise returns 0 and the correct answer powmod(x,y,n) in ans by using the method of powmod3loop
 */
int powmod3cbr(int x, int y, int m, int& ans) {
    // code here
     if(x<0){return 1;}
     if(y<0){return 1;}
     if(m<=0){return 1;}

     else{
     ans=powmod1(x,y,m);
     return   0;

     }
}

void test1(){
     int x = 0;
    int y = 0;
    int m = 0;
    cout << "Enter x y and m separated by spaces: ";
    cin >> x;
    cin >> y;
    cin >> m;
    cout << "x==" << x << " ";
    cout << "y==" << y << " ";
    cout << "m==" << m << " ";
    cout << " \n";
    int p = powmod1(x,y,m);
    cout << "powmod1(x,y,m)==" << p << endl;
}
void test2(){
     int x = 0;
    int y = 0;
    int m = 0;
    cout << "Enter x y and m separated by spaces: ";
    cin >> x;
    cin >> y;
    cin >> m;
    cout << "x==" << x << " ";
    cout << "y==" << y << " ";
    cout << "m==" << m << " ";
    cout << " \n";
    int p = powmod2(x,y,m);
    cout << "powmod2(x,y,m)==" << p << endl;
}

void test3(){
     int x = 0;
    int y = 0;
    int m = 0;
    cout << "Enter x y and m separated by spaces: ";
    cin >> x;
    cin >> y;
    cin >> m;
    cout << "x==" << x << " ";
    cout << "y==" << y << " ";
    cout << "m==" << m << " ";
    cout << " \n";
    int p = powmod3(x,y,m);
    cout << "powmod3(x,y,m)==" << p << endl;
}
void test4(){
     int x = 0;
    int y = 0;
    int m = 0;
    cout << "Enter x y and m separated by spaces: ";
    cin >> x;
    cin >> y;
    cin >> m;
    cout << "x==" << x << " ";
    cout << "y==" << y << " ";
    cout << "m==" << m << " ";
    cout << " \n";
    int p = powmod2loop(x,y,m);
    cout << "powmod2loop(x,y,m)==" << p << endl;
}

void test5(){
     int x = 0;
    int y = 0;
    int m = 0;
    cout << "Enter x y and m separated by spaces: ";
    cin >> x;
    cin >> y;
    cin >> m;
    cout << "x==" << x << " ";
    cout << "y==" << y << " ";
    cout << "m==" << m << " ";
    cout << " \n";
    int p = powmod3loop(x,y,m);
    cout << "powmod3loop(x,y,m)==" << p << endl;
}
void test6(){
     int x = 0;
    int y = 0;
    int m = 0;
    cout << "Enter x y and m separated by spaces: ";
    cin >> x;
    cin >> y;
    cin >> m;
    cout << "x==" << x << " ";
    cout << "y==" << y << " ";
    cout << "m==" << m << " ";
     cout << " \n";
    int p;
    if (powmod3cbr(x,y,m,p) != 0) {
        cout << "an error occurred" << endl;
    } else {
        cout << "powmod(x,y,m)==" << p << endl;
    }
}

int main()
{
   //test1();
   //test2();
  // test3();
  // test4();
  // test5();
   test6();
    return 0;
}
