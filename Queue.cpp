#include<iostream>
#include<string>
using namespace std;
struct etype 
{
	string name;
	int age;
};
const int ML = 7;
struct CQueue
{
	int front,rear; //indecies
	etype elements[ML];
};
int Addone(int index)//returned function with (index+1)
{
	//return (index+1)%ML;

	//return (index % (ML-1)) +1; // look like i++ 

	if (index == ML-1)
		return 0;
	else
		return ++index;	
}
bool Empty(CQueue q)
{
	if(Addone(q.rear)==q.front)
		return true;
	else
		return false;
}
void Enqueue (CQueue &q,etype x)
{
	if(Addone(Addone(q.rear))==q.front)//full CQueue
		cout<<"invalid enqueue "<<endl;
	else
	{
		q.rear=Addone(q.rear);//move the rear one step == q.rear++
		q.elements[q.rear]=x;
		//which equvilant
		/*q.elements[Addone(q.rear)]=x;
		q.rear=Addone(q.rear);*/
	}
}
void disp(CQueue q)
{
	if(Empty(q))
		cout<<"invalid display since empty queue"<<endl;
	else
	{
		for(int i=q.front; ;i=Addone(i))
		{
			cout<<"element information : "<<endl;
			cout<<"name : "<<q.elements[i].name<<" and age : "<<q.elements[i].age <<endl;
			//stop at last element after displaying it 
			if(i==q.rear)
				break;
		}
	}
}
void Dequeue(CQueue &q)
{
	if(Empty(q))
		cout<<"invalid dequeue "<<endl;
	else
		q.front=Addone(q.front);
}
void input(CQueue &q)
{
	cout<<"enter number of elements : ";
	int s;
	cin>>s;
	if(s<ML)
	{
		for(int i=1;i<=s;i++)
		{
			etype temp;
			cout<<"enter element "<<i<<" :\n ";
			cout<<"name : ";
			cin>>temp.name;
			cout<<"age : ";
			cin>>temp.age;
			Enqueue (q,temp);
		}
	}
	else
	{
		cout<<"invalide size of Queue . "<<endl;
	}
	
}
int sizeQ(CQueue q)
{
	int s=0;
	if(Empty(q))
		return s;
	else
	{
		for(int i=q.front; ;i=Addone(i))
		{
			s++;
			//stop at last element after displaying it 
			if(i==q.rear)
				break;
		}
		return s;
	}
}
void merge(CQueue &q,CQueue &q1,CQueue &q2)
{
	int n1,n2;
	n1=sizeQ(q1);
	n2=sizeQ(q2);
	if((n1+n2)<=ML-1)
	{
		cout<<"valid merging : \n";
		for(int i=1;i<=n1+n2;)
		{
			if(!Empty(q1))
			{
				Enqueue(q,q1.elements[q1.front]);
				Dequeue(q1);
				i++;
			}
			if(!Empty(q2))
			{
				Enqueue(q,q2.elements[q2.front]);
				Dequeue(q2);
				i++;
			}
		}
	}
	else
	{
		cout<<"invalid merging : \n";
	}
}
void split(CQueue &q,CQueue &q1,CQueue &q2)
{
	if(Empty(q))
	{
		cout<<"invalid spliting \n";
	}
	else
	{
		//traversing the original q element  by element
		for(int i=q.front;;i=Addone(i))
		{
			if((i%2)==0)
			{
				Enqueue(q2,q.elements[i]);
			}
			else
			{
				Enqueue(q1,q.elements[i]);
			}
			if (i==q.rear)
				break;
		}
	}
}
void main()
{
	CQueue q;
	//intialization of CQ attribute
	q.front=0;
	q.rear=ML-1;
	/*etype x;
	x.name="godzila";
	x.age=19;
	Enqueue(q,x);
	etype y;
	y.name="roro";
	y.age=18;
	Enqueue(q,y);
	disp(q);
	cout<<"---------------------------------"<<endl;
	etype z;
	z.name="virus";
	z.age=21;
	Enqueue(q,z);
	cout<<"---------------------------------"<<endl;
	Dequeue(q);
	disp(q);
	cout<<"---------------------------------"<<endl;
	//Dequeue(q);
	//disp(q);
	Enqueue(q,z);
	disp(q);
	*/
	//input(q);
	//disp(q);
	/*CQueue q1,q2;
	//intialization of q1
	q1.front=0;
	q1.rear=ML-1;
	//intialization of q1
	q2.front=0;
	q2.rear=ML-1;
	cout<<"enter Q1 elements : "<<endl;
	input(q1);
	cout<<"-----------------------------------\n";
	cout<<"enter Q2 elements : "<<endl;
	input(q2);
	cout<<"-----------------------------------\n";
	merge(q,q1,q2);
	cout<<"the elements after merging...... \n";
	disp(q);*/
	input(q);
	CQueue q1,q2;
	//intialization of q1
	q1.front=0;
	q1.rear=ML-1;
	//intialization of q1
	q2.front=0;
	q2.rear=ML-1;
	split(q,q1,q2);
	cout<<"elements of Q1 : "<<endl;
	disp(q1);
	cout<<"elements of Q2 : "<<endl;
	disp(q2);
	system("pause");
}