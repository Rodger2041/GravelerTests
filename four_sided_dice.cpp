#include<bits/stdc++.h>

using namespace std;

const int m1=1e9+7;

void genprimes(vector<int> &primes){
    vector<int> ip(1e9,0);
    int prev=0;
    long long loops=0;
    for(int i=2;i<1e9;i++){
        if(!ip[i]){
            if(i>=1e8) primes.push_back(i);
            for(int j=2*i;j<1e9;j+=i){
                ip[j]=1;
                loops++;
            }
        }
        if(10*loops/3220220432>prev){
            prev++;
            cout<<prev*10<<"%\n";
            cout.flush();
        }
    }
    return;
}
vector<int> rolls;
inline void roll(long long x){
    while(x>4){
        rolls.push_back(x%4);
        x/=4;
    }
    return;
}
inline void next(int next,long long & val){
    val=((val+next)*next);     // generate psuedorandom numbers using primes
    roll(val);
    val%=m1;
    return;        
}
signed main(){
    // first generate a list of prime numbers between 1e8 and 1e9
    // using seive for this method 
    vector<int> primes;
    cout<<"Generating Primes... please wait"<<'\n';
    cout.flush();
    genprimes(primes);
    // no of primes=45086079
    long long random_seed;
    cout<<"Input random seed (less than 9 digits): ";
    cout.flush();
    cin>>random_seed;
    int index=((74078113+random_seed)*87563527)%primes.size(); //generate a random index from the seed
    int epochs=1e9;
    double time=clock();
    int mx=0,cur;
    long long val=0;
    cout<<"Starting Simulation\n";
    cout.flush();
    for(int i=0;i<epochs;i++){
        cur=0;
        for(int j=0;j<231;j++){
            while(rolls.empty()){
                next(primes[index],val);      // update psuedorandom number
                index=(i+(random_seed+index+primes[index])*(primes[index]))%primes.size();
            }
            if(!rolls.back()){       //check output of dice
                cur++;
            }
            rolls.pop_back();
        }
        if(!(i%10000000)){
            cout<<(i/10000000)<<"%\n";
            cout.flush();
        }
        mx=max(mx,cur);
    }
    cout<<"Time taken "<<(clock()-time)/CLOCKS_PER_SEC<<'\n';
    cout<<mx<<'\n';
    return 0;
}
