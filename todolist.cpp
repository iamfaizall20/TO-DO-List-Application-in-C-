#include <iostream>
#include <vector>
#include <string>
using namespace std;

	//Structure for Task Class
	struct Task{
		string taskDescription;
		bool isdone = true;
	};
	//Function to Display Menu
	void displayMenu(){
		
		cout<<"---- TO DO List Menu ----\n";
		cout<<"1.Add a Task\n";
		cout<<"2.Mark Task as Done\n";
		cout<<"3.View all Tasks\n";
		cout<<"4.Delete a Task\n";
		cout<<"5.Clear all Tasks\n";
		cout<<"6.Exit\n";
		cout<<"\nEnter your Choice :";
	}
	
	//Function to add a task
	void addTask(vector<Task> &tasks){
		Task newTask;
		cout<<"\nEnter a Task: ";
		cin.ignore();
		getline(cin,newTask.taskDescription);
		newTask.isdone = false;
		tasks.push_back(newTask);
		cout<<"\nTask Added Successfully!\n";
	}
	//Function to view tasks;
	void viewTasks(vector<Task> &tasks){
		if(!tasks.empty()){
			for(int i=0;i<tasks.size();i++){
				cout<<"\n"<<i+1 <<". " <<tasks[i].taskDescription <<" ["<< 
					(tasks[i].isdone ? "Done" : "Pending")<<"].\n";
			}
		}
		else{
			cout<<"\nNo Tasks Available\n";
		}
	}
	//Function to Mark Task as Done
	void marktask(vector<Task> &tasks){
		int taskNum = 0;
		if(tasks.empty()){
			cout<<"\nNo Tasks Available\n";
			return;
		}
		viewTasks(tasks);
		cout<<"\nEnter Task Number To Marks as Done: ";
		cin>>taskNum;
		
		if(taskNum>0 && taskNum <= tasks.size()){
			tasks[taskNum-1].isdone = true;
			cout<<"\nTask No."<<taskNum<<" Marked Done Successfully.\n";	
		}
		else{
			cout<<"\nInvalid Task No.\n";
			}
		}
		//Function to delete any task;
		void deleteTask(vector<Task> &tasks){
			if(tasks.empty()){
				cout<<"\nNo Tasks Available.\n";
				return;
			}
		int taskNum = 0;
		viewTasks(tasks);
		cout<<"\nEnter Task No. to Delete: ";
		cin>>taskNum;
		
		if(taskNum>0 && taskNum <= tasks.size()){
			tasks.erase(tasks.begin() + (taskNum-1));
			cout<<"\nTask No. "<<taskNum<<" deleted Successfully\n";	
		}
		else{
			cout<<"\nInvalid Task Number\n";
		}	
	}	
	//Function to clear all Tasks
	void clearAllTasks(vector<Task> &tasks){
		if(tasks.empty()){
			cout<<"\nNo Tasks Available.\n";
		}
		else{
			tasks.clear();
			cout<<"\nAll Tasks Cleared Successfully.\n";
		}
	}	
int main(){
	vector<Task> tasks;
	
	int choice = 0;
	
	while(choice!=6){
		
		displayMenu();
		cin>>choice;
		
		switch(choice){
			case 1:
				addTask(tasks);
				break;
			case 2:
				marktask(tasks);
				break;
			case 3:
				viewTasks(tasks);
				break;
			case 4:
				deleteTask(tasks);
				break;
			case 5:
				clearAllTasks(tasks);
				break;
			case 6:
				break;
			default:
				cout<<"\nInvalid Choice.Please try again.\n";
		}
		cout<<endl;
	}
}
