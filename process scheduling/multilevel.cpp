//multilevel with feedback
#include<bits/stdc++.h>
using namespace std;

int system_time = 0;
class Process{
public:
	int id, arrival_time, orig_arrival_time, burst_time, remaining_time, completion_time, turn_around_time, waiting_time, priority, level;
};
bool comparePriority(Process p1, Process p2){
	return p1.priority < p2.priority;
}
bool compareArrivalTime(Process p1, Process p2){
	return p1.arrival_time < p2.arrival_time;
}
bool compareRemainingTime(Process p1, Process p2){
	return p1.remaining_time < p2.remaining_time;
}
bool compareCompletionTime(Process p1, Process p2){
	return p1.completion_time < p2.completion_time;
}

void display(Process process[], int n){
	sort(process, process + n, compareCompletionTime);
	for(int i=0; i<n; i++){
		process[i].turn_around_time = process[i].completion_time - process[i].orig_arrival_time;
		process[i].waiting_time = process[i].turn_around_time - process[i].burst_time;
	}

	int no_of_completed = 0;

	cout << "Name\tArrivalTime\tBurstTime\tPriority\tCompletionTime\tTurnAroundTime\tWaitingTime" << endl;

	for(int i=0; i<n; i++){
		cout << process[i].id << "\t" << process[i].arrival_time << "\t\t" << process[i].burst_time
			<< "\t\t" << process[i].priority << "\t\t";

		if(process[i].completion_time != -1){
			no_of_completed++;
			cout << process[i].completion_time << "\t\t" << process[i].turn_around_time
			<< "\t\t" << process[i].waiting_time << endl;
		}
		else{
			cout << "Not Yet Completed" << endl;
		}
	}



	float avg_waiting_time = 0, avg_turn_around_time = 0;
	for(int i=0; i<n; i++){
		if(process[i].completion_time != -1){
			avg_waiting_time += process[i].waiting_time;
			avg_turn_around_time += process[i].turn_around_time;
		}
	}
	avg_waiting_time /= (float)(no_of_completed);
	avg_turn_around_time /=(float)(no_of_completed);

	cout << "Average Waiting Time: " << avg_waiting_time << endl;
	cout << "Average Turn Around Time: " << avg_turn_around_time << endl;

}
void intermediateDisplay(Process process[], int n, int system_time){

	cout << "system_time = " << system_time << endl;
	cout << "Name\tArrivalTime\tRemainingTime\tPriority" << endl;

	for(int i=0; i<n; i++){
		cout << process[i].id << "\t" << process[i].arrival_time << "\t\t" << process[i].remaining_time
		     << "\t\t" << process[i].priority << endl;
	}

}
void input(Process process[], int n){
	for(int i=0; i<n; i++){
		process[i].id = i;
		process[i].arrival_time = process[i].orig_arrival_time = rand() % 100;
		process[i].burst_time = process[i].remaining_time = rand() % 100 + 1;
		process[i].priority = rand() % 20;
		process[i].completion_time = -1;
		process[i].level = rand() % 3;
	}
}
bool processRemaining(Process process[], int n){
	for(int i=0; i<n; i++){
		if(process[i].completion_time == -1)
			return true;
	}
	return false;
}
void roundRobin(Process process[], int n, int time_slice, int levelTimeWindow){
	sort(process, process+n, compareArrivalTime);
	while(processRemaining(process, n)){
        bool executed = false;
		for(int i=0; i<n; i++){
			if(system_time > levelTimeWindow){
				return;
			}
			if(process[i].remaining_time > 0 && process[i].arrival_time <= system_time){
                executed = true;
				if(process[i].remaining_time <= time_slice){
                    system_time += process[i].remaining_time;
                    process[i].remaining_time = 0;
                    process[i].completion_time = system_time;
                }
                else{
                    system_time += time_slice;
                    process[i].remaining_time -= time_slice;
                }
            }
		}
        if(!executed){
            system_time++;
        }
	}
}
void prioritySchedule(Process process[], int n, int levelTimeWindow){
	sort(process, process + n, comparePriority);
	while(processRemaining(process, n)){
		bool executed = false;
		int exec_priority = INT_MAX;

		for(int i=0; i<n; i++){
			if(system_time > levelTimeWindow){
				return;
			}
			if(system_time >= process[i].arrival_time && process[i].completion_time == -1 && process[i].priority < exec_priority){
				executed = true;
				exec_priority = process[i].priority;
				system_time ++;
				process[i].remaining_time--;
				if(process[i].remaining_time == 0){
					process[i].completion_time = system_time;
				}
			}
		}
		if(executed == false){
			system_time++;
		}

	}
}
void srf(Process process[], int n, int levelTimeWindow){
	sort(process, process+n, compareRemainingTime);
	while(processRemaining(process, n)){
		int min_exec_time = INT_MAX;
		int exec_process = -1;
		bool executed = false;


		for(int i=0; i<n; i++){
			if(system_time > levelTimeWindow){
				return;
			}
			if(process[i].arrival_time <= system_time && process[i].remaining_time >0 && process[i].remaining_time < min_exec_time){

				executed = true;
				min_exec_time = process[i].remaining_time;
				exec_process = i;
			}
		}

		//checking remaining time of each process after a time interval of 1 time unit
		system_time++;
		if(executed == true){
			process[exec_process].remaining_time--;
			if(process[exec_process].remaining_time == 0){
				process[exec_process].completion_time = system_time;
			}
		}
		
	}
}
int addToNextLevel(Process current[], int currentCount, Process next[], int nextCount){
	for(int i=0; i<currentCount; i++){
		if(current[i].completion_time == -1){
			current[i].arrival_time = system_time;
			next[nextCount++] = current[i];
		}
	}
	return nextCount;
}
void segregate(Process process[], int n){
	int LEVELS = 3;
	int countOfLevel[LEVELS];
	memset(countOfLevel, 0, sizeof(countOfLevel));
	for(int i=0; i<n; i++){
		countOfLevel[process[i].level]++;
	}

	Process level[LEVELS][n];
	int index[3];
	memset(index, 0, sizeof(index));
	for(int i=0; i<n; i++){
		int x = process[i].level;
		level[x][index[x]++] = process[i];
	}
	int time_window = 200;

	cout << "\nLEVEL 0 - Round Robin Scheduling" << endl;
	roundRobin(level[0], countOfLevel[0], 10, time_window * 1);
	display(level[0], countOfLevel[0]);
	countOfLevel[1] = addToNextLevel(level[0], countOfLevel[0], level[1], countOfLevel[1]);

	cout << "\nLEVEL 1 - Priority Scheduling (Pre-emptive)" << endl;
	prioritySchedule(level[1], countOfLevel[1], time_window * 2);
	display(level[1], countOfLevel[1]);
	countOfLevel[2] = addToNextLevel(level[1], countOfLevel[1], level[2], countOfLevel[2]);

	cout << "\nLEVEL 2 - Shortest Remaining First" << endl;
	srf(level[2], countOfLevel[2], time_window * 3);
	display(level[2], countOfLevel[2]);
}
int main(){
	int n;
	cout << "Enter no of processes:";
	cin >> n;
	Process process[n];
	input(process, n);
	segregate(process, n);
	return 0;
}
