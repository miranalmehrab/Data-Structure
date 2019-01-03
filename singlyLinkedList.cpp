#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int data;
	node *next;
};


node* createNode(int data)
{
	node *temp = new node[1];
	temp[0].data = data;
	temp[0].next = NULL;
	return temp;
}

node *head = NULL;
node *tail = NULL;
void insertIntoList(node*temp)
{
	if(head==NULL && tail==NULL)
	{
		head = temp;
		tail = temp;
		temp->next = NULL;
	}
	else
	{
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}
}


void traverseForward()
{
	node *current = head;
	while(current != NULL)
	{
		cout<<current->data<<" ";
		current = current->next;
	}
	cout <<endl;
}

void searchDataInList(int data)
{
	node *current = head;
	while(current != NULL)
	{
		if(data == current->data)
		{
			cout <<"Data found."<<endl;
			return;
		}
		current = current->next;
	}
	cout <<"Data not found."<<endl;
}

void deleteDataFromList(int data)
{
	node *temp = head;
	node *tempPrevious = temp;
	bool dirtyBit = false;

	while(temp!=NULL)
	{
		dirtyBit = false;
	 	if(data == temp->data)
	 	{
	 		if(temp == head)
	 		{
	 			head = head->next;
	 			cout <<"Item deleted."<<endl;
	 		}
	 		else if(temp == tail)
	 		{
	 			tail = tempPrevious;
	 			tail->next = NULL;
	 			cout <<"Item deleted."<<endl;
	 		}
	 		else
	 		{
	 			tempPrevious->next = temp->next;		
	 			dirtyBit = true;
	 			cout <<"Item deleted."<<endl;
	 		}
	 	}
	 	if(!dirtyBit)tempPrevious = temp;
	 	temp = temp->next;
	}
}


void insertAfter(int key,int data)
{
	node *current = head;
	while(current != NULL)
	{
		if(key == current->data)
		{
			if(current==head)
			{
				node *temp = createNode(data);
				temp->next = current->next;	
				current->next = temp;
				cout <<"inserted: "<<data<<endl;
			}
			else if(current == tail)
			{
				node *temp = createNode(data);
				current->next = temp;
				temp->next = NULL;
				tail = temp;
				cout <<"inserted: "<<data<<endl;
			}
			else
			{
				node *temp = createNode(data);
				temp->next = current->next;
				current->next = temp;	
				cout <<"inserted: "<<data<<endl;
			}
		}
		
		current = current->next;
	}
}


void readFromFile()
{
	string fileName="bubble.txt";
	//cout <<"Enter your file name : ";
	//cin >> fileName;

	ifstream iFile;
	iFile.open(fileName.c_str());
	if(!iFile.is_open())
	{
		cout<<"Couldn't open file."<<endl;
		return;
	}

	int data;
	node *temp = NULL;
	while(!iFile.eof())
	{
		iFile >> data;
		temp = createNode(data);
		insertIntoList(temp);
	}
}

int main()
{

	readFromFile();
	traverseForward();
	searchDataInList(10);
	deleteDataFromList(10);
	searchDataInList(10);
	insertAfter(80,10);
	insertAfter(80,5);
	traverseForward();
	deleteDataFromList(80);
	traverseForward();

	return 0;
}