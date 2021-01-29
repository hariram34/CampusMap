#include <iostream>
#include <fstream>
#include <stdexcept>
#include<string.h>
#include<limits.h>
#include<cstdlib>
#define maxints 52
#define edges 52
using namespace std;
void printpath(int parent[], int j)
{

    //cout<<"enter\n";
	if (parent[j] == - 1)
		return;

	printpath(parent, parent[j]);
	cout<<j;
}
int print(int dist[], int n,int p[])
{
    printf("Distance :\n");
    int source =0;
    for (int i = 0; i < maxints; i++){
        cout<<source<<"->"<<i<<" "<<dist[i]<<"\t\t"<<source<<"\n";
        cout<<"path\n";
		printpath(p, i);
    }
}
int minDistance(int dist[], bool marked[])
{

    int min = INT_MAX; //variable to store value of the min
    int minimum,s; //variable to store index

    for (s = 0; s < maxints; s++)
            if (marked[s] == false && dist[s] <= min) //check if marked and if the distance is less than current path distance
                min = dist[s];
                minimum = s;

    return minimum; //return the index
}

void dijkstra(int map[maxints][maxints], int src)
{
    int dist[maxints],path[maxints],i; //array to store the shortest path
    bool mark[maxints]; //to mark true if its already included in path
// Initializing all distances to infinite value and marked value to be false
    for (i = 0; i < maxints; i++)
            path[i] = -1;
            dist[i] = INT_MAX;
            mark[i] = false;
     //source
    dist[src] = 0;
    // Find shortest path for all vertices
    for (int count = 0; count < maxints - 1; count++) {
        int v = 0;
        int u = minDistance(dist, mark); //choosing each unvisited vertex
        mark[u] = true; // Mark the visited vertex as true
        for (v = 0; v < maxints; v++)// Update distance value
            if (!mark[v] && map[u][v]&& dist[u] + map[u][v] < dist[v])
                path[v] = u;
                dist[v] = dist[u] + map[u][v];
    }
 for (int v = 0; v < maxints; v++)// Update distance value
     {

       cout<<path[v]<<" ";
    }
    // print
    cout<<"test\n";
    print(dist, maxints,path);
}


int main() {
ifstream inf,nf;
int count = 0,count1=0,w=0,row=0,col=0;
string x,v1,v2;
string list[maxints];
int mat[52][52]={};
inf.open("list.txt");
nf.open("graph_data.txt");
if (inf.fail())
{
    cerr << "Error: Could not open input file\n";
    exit(1);
}
if (nf.fail())
{
    cerr << "Error: Could not open input file\n";
    exit(1);
}
//activate the exception handling of inf stream
//inf.exceptions(std::ifstream::failbit | std::ifstream::badbit);
while (count < maxints) { //keep reading until reading maxints or
             //until a reading failure is caught.
    inf>>x;
    list[count++]=x;
}
////cout<<"done"<<endl;
while(!nf.eof()){
        nf>>v1;
        nf>>v2;
        nf>>w;
        int i=0,j=0;
    for(int i = 0; i<52; i++){
        if(v1==list[i]){
            //cout<<"1"
            row = i;
            //break;
        }}
    for(int j = 0;j<52;j++){
        if(v2==list[j]){
            //cout<<"2";
            col = j;
            //break;
        }
        }
    //cout<<list[row]<<" "<<list[col]<<" "<<w<<endl;
    mat[row][col]=w;
    mat[col][row]=w;
    //count1++;
}
dijkstra(mat, 0);
//cout<<row<<" "<<col<<endl;
    //for(int i = 0; i < count; i++)
    //{cout << list[i] << endl;}
    for(int i=0;i<maxints;i++){
        for(int j=0;j<maxints;j++){
            //cout<<mat[i][j]<<" ";
        }
        //cout<<endl;
    }
    inf.close();
    nf.close();
     //Close the file at the end of your program.
    return 0;
}
