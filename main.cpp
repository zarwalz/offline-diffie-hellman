//Zineb Zarwal
//Project #3

#include <iostream>
#include <string>
using namespace std;


bool Prime(int num);
bool Range(int num, int a, int b);
long long int power(int a,int b,int mod);

struct user
{
    int s;
    long long int publicKey;
    long long int privateKey;
};

int main() {
    
    user A;
    user B;
    int n;
    int g;
    
    do {
    cout << "Enter the first public prime number (Bewtween 4000 and 10000)" << endl;
    cin >> n;
    }while (!Prime(n) || !Range(n, 4000, 10000));
    
    
    
    do {
    cout << "Enter the second public prime number (Bewtween 4000 and the FIRST NUMBER)" << endl;
    cin >> g;
    }while (!Prime(g) || !Range(g, 4000, n));
    
    
    do {
    cout << "User A: Enter your secret number ((Bewtween 40 and 100)" << endl;
    cin >> A.s;
    } while (!Range(A.s, 40, 100));
    
    do {
        cout << "User B: Enter your secret number ((Bewtween 40 and 100)" << endl;
        cin >> B.s;
    } while (!Range(B.s, 40, 100));
    
    //Calculating User A's public Key
    A.publicKey = power(g, A.s, n);
    cout << "User A Public Key: " << A.publicKey << endl;
    
    //Calculating User A's public Key
    B.publicKey = power(g, B.s, n);
    cout << "User B Public Key: " << B.publicKey << endl;
    
    //Calculating User A's private Key
    A.privateKey = power(B.publicKey, A.s, n);
    cout << "User A Private Key: " << A.privateKey << endl;
   
    //Calculating User A's private Key
    B.privateKey = power(A.publicKey, B.s, n);
    cout << "User B Private Key: " << B.privateKey << endl;
    
    if (A.privateKey == B.privateKey) {
        cout << "User A & User B Shared Private Key's are equal" << endl;
    }
    else cout << "User A & User B Shared Private Key are inconsistent" << endl;
    
    return 0;
}


bool Prime(int num) {
    
    for(int i = 2; i <= num / 2; ++i)
        {
        if(num % i == 0)
            {
            cout << "Error! " << num << " is not a prime number!" << endl;
            return false;
            break;
            }
        }
    return true;
}

bool Range(int num, int a, int b) {
    
    if ( num < a || num > b)
        {
            cout << "Error! " << num << " is not in range!" << endl;
            return false;
        }
    return true;
}

long long int power(int a,int b,int mod)
{
    long long int z;
    if(b==1)
        return a;
    z = power(a,b/2,mod);
    if(b%2==0)
        return (z*z)%mod;
    else
        return (((z*z)%mod)*z)%mod;
}


