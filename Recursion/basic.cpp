c
void greet(int a){
    if(a==0) return;
    cout<<"Ram"<<endl;
    greet(a-1);
}

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;
    greet(n);
    return 0;
}