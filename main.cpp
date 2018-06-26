#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    
    //string parent, name;
    int age, parentid, id;
    
};

bool operator<(const node& x, const node& y){
    
    return x.age<y.age;
    
};
//vector<string, vector<node> > g_tree(int N);


int main(){
    
    //node queen;
    //g_tree[0] - queen
    //queen.id - 0
    
    cout<<"Type in the number of queen's relatives to input:"<<endl;
    int n;
    cin>>n;
    vector<int, vector<node> > g_tree(n);
    
    cout<<"Type in the data about queen's relatives in the following format:"<<endl<<"parent's id"<<endl<<"id"<<endl<<"age"<<endl;
    //let's assume that no two sibilings are the same age
    for(int i=0; i<n; i++){
        
        node x;
        cin>>x.parentid>>x.id>>x.age;
        g_tree[x.parentid].push_back(x);
        
    }
    int current=0;
    
    cout<<"Type in 0 to end the programme, 1 to find the next successor:"<<endl;
    int y;
    cin>>y;
    while(y){
        
        sort(g_tree[current], g_tree[current]+g_tree[current].size);
        cout<<"The next successor is the relative with id "<<g_tree[current][g_tree[current].size-1].id<<endl;
        current=g_tree[current][g_tree[current].size-1].id;
        
        cout<<"Type in 0 to end the programme, 1 to find the next successor:"<<endl;
        cin>>y;
        
    }
    
    return 0;

    
}
