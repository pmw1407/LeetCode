#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result = -1;
    	int n = gas.size();
        for(int i = 0; i < n; i++){
            int fuel = 0;
        	if(gas[i] >= cost[i]){
        		fuel = fuel + gas[i] - cost[i];
        		int temp = 0;
        		while(true){
        			if(temp == n - 1){
        				return i;
        			}
        			temp++;
        			if(i + temp < n){
        				if(cost[temp + i] > fuel + gas[temp + i]){
        					break;
        				}
        				else{
        					fuel = fuel + gas[temp + i] - cost[temp + i];
        				}
        			}
        			else{
        				if(cost[temp + i - n] > fuel + gas[temp + i - n]){
        					break;
        				}
        				else{
        					fuel = fuel + gas[temp + i - n] - cost[temp + i - n];
        				}
        			}
        		}
        	}

        }

        return result;
    }
};

int main(void){
	vector<int> gas;
	vector<int> cost;
	
	gas.push_back(1);
	gas.push_back(2);
	gas.push_back(3);
	gas.push_back(4);
	gas.push_back(5);
	cost.push_back(3);
	cost.push_back(4);
	cost.push_back(5);
	cost.push_back(1);
	cost.push_back(2);
	
	
	Solution sol;

	cout << sol.canCompleteCircuit(gas, cost) << endl;
}
