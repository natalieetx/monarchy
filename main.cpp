#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
    
    string name;
    bool isalive;
    int age, id, parentid;
    
};
bool operator<(const node& x, const node& y){
    
    return x.age<y.age;
    
}

vector<vector<node> > g_tree;
int numofrelatives;

//The data about queen's relatives shall be in the following format: relative's name, id, parent's id, age, whether they're alive
void addrelatives();
//When all alive, the oldest sibiling will be the successor. If not, the oldest of the sibilings that is alive.
//If all are dead, then we look for oldest alive child of the oldest sibiling; if all are dead,
//then for the oldest alive child of the second oldest sibiling... etc.
int successortothethrone();


int main(){
    
    
    cin>>numofrelatives;
    g_tree.assign(numofrelatives+1, vector<node> (0));
    
    addrelatives();
    cout<<successortothethrone();


    
}

void addrelatives(){
    
    for(int i=0; i<numofrelatives; i++){
        
        node x;
        cin>>x.name>>x.id>>x.parentid>>x.age>>x.isalive;
        g_tree[x.parentid].push_back(x);
        
    }
    
}

int successortothethrone(){
    
    sort(g_tree[0].begin(), g_tree[0].end());
    
    int currentparent=0;
    int currentsubstr=(int)g_tree[currentparent].size()-1;
    int successor=g_tree[currentparent][currentsubstr].id;
    
    queue<int> oldest;
    oldest.push(successor);
    
    while(!g_tree[currentparent][currentsubstr].isalive){
        
        successor=g_tree[currentparent][currentsubstr].id;
        oldest.push(successor);
        
        currentsubstr--;
        
        if(currentsubstr<0){
            
            currentparent=oldest.front();
            oldest.pop();
            currentsubstr=(int)g_tree[currentparent].size()-1;
            
        }
        
    }
    successor=g_tree[currentparent][currentsubstr].id;
    
    return successor;
}

