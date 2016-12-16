//Author: Katie Long
//Class: CS315
//Problem: UVA 469

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

const int MAX_COL = 20;
const int MAX_ROW = 20;
bool visited[MAX_ROW];
const int adjacencyMatrix[MAX_ROW][MAX_COL] =  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				    		{0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
						{0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0},
						{0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
						{0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1},
						{0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0},
						{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0},
						{0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0},
						{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1},
						{0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
						{0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0}};




//THIS WAS FOUND AT https://github.com/luisfcofv/competitive-programming-book/blob/master/ch4/ch4_02_UVa469.java
//This can also be done by using offsets in a 2D array traversal for loop
int drow[8] = {0, 0, -1,-1, -1, 1, 1, 1};
int dcol[8] = {-1, 1, -1, 0, 1, -1, 0, 1};


int inprogress[MAX_ROW][MAX_COL] = {{0}};

bool allZeroes(){

	for(int r = 0; r < MAX_ROW; r++){
		if(visited[r] == false)
			return false;
	}

	return true;

}

int main(){

	memcpy(inprogress, adjacencyMatrix, MAX_ROW*MAX_COL);
	memset(visited, false, MAX_ROW);
	int connections[MAX_ROW] = {0};
	int biggestConnection=0, nodeNumber =0;
	vector<int> dominatingSet;

        for(int r = 0; r < MAX_ROW; r++){
		for( int c = 0; c < MAX_COL; c++){
			if(adjacencyMatrix[r][c] == 1)
				connections[r] += 1;
		}
	}
	int round = 0;
	while(round < 9){
		for(int node = 0; node < MAX_ROW; node ++){
			if(connections[node] >= biggestConnection && connections[node] != 0 && connections[node] != -1){
				nodeNumber = node;
				biggestConnection = connections[node];
			}
			//cout << connections[node] << endl;
		}

		for(int row = 0; row < MAX_ROW; row ++){
			if(inprogress[row][nodeNumber] == 1){
				visited[row] = true;
			}
			inprogress[row][nodeNumber] = 0;
			

		}
		for(int col = 0; col < MAX_COL; col ++){
			inprogress[nodeNumber][col] = 0;	
		}


	//	cout << "node: " << nodeNumber << endl;
	//	cout << "num conn: " << biggestConnection<<endl;
		round += 1;
		bzero(connections, MAX_ROW);
  		for(int r = 0; r < MAX_ROW; r++){
			for( int c = 0; c < MAX_COL; c++){
				if(inprogress[r][c] == 1 && connections[r] != -1)
					connections[r] += 1;
			}
		}

		dominatingSet.push_back(nodeNumber);
		connections[nodeNumber] = -1;
		nodeNumber = -1;
		biggestConnection = -1;
	}

//	for(int i = 0; i < MAX_ROW; i ++)
//		cout << i << ": " << connections[i] << endl;
	
	cout << "DOMINATING SET!" << endl;
	for(int k = 0; k < dominatingSet.size(); k ++)
		cout << dominatingSet[k] << endl;

	return 0; 
}
