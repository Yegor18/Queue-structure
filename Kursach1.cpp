#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int SIZE; //������ �������
int *a;//������
class Queue {
	public :
   	int count;//��������� �� ������-������� 
    void pop();//������� ����������
    void show();//����� �������
   	  
	Queue() {//�����������
 		a = new int[SIZE];//��������� ������������ ������ ��� �������
  		count =0 ;
  	}
		
	bool isempty(){ //���� �� ������?	
		if (SIZE == 0) return 0;
		else return 1;
	};
	
	int value(){ //����� �������� �� ������
		return a[0]; 
	};
	
	void getQueueSize(){ //����� ������� �������
  		cout<<"���-�� ��������� � �������:"<<SIZE<<endl;
	};
	
	int get(int n){	
    	int val;
		int val_pos;	
		if (n != 1)  
		{	
			for (int i = 0; i != count; )
			{
				val = value();	
				pop();
				push (val); 
				i++;
				if (i == n - 1) 	
				{
					val_pos = value();	
				}
			}
		}
		else {
			val_pos = value();	
		}
		return val_pos;	
	}

	void set (int pos, int val){
		int valu;
		if (pos==1)	 {
			a[0] = val;	
		}
		else{
			for (int i = 0; i != count; )
			{
				valu = value(); 
				pop();	
				push (valu);
				i++;
				if (i == (pos - 1))	
				{
					a[0] = val;
				}
			}
		}
	}
	void push ( int num ){  //��������� �������� � �������
  	if (count == SIZE) 
  		cout <<"������� �����" <<endl ;
  	else
	{
	  	a[count]=num;
 		count++;
	}
}
// ������� "�����������" ����� ���� - ������������ ����
void proseivanie(int *numbers, int root, int bottom)
{
  int maxChild; // ������ ������������� �������
  int done = 0; // ���� ����, ��� ���� ������������
  // ���� �� ����� �� ���������� ����
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // ���� �� � ��������� ����, 
      maxChild = root * 2;    // ���������� ����� �������
    // ����� ���������� ������� ������� �� ����
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // ���� ������� ������� ������ ������������� �������
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // ������ �� �������
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // �����
      done = 1; // �������� ������������
  }
}
// ������� ���������� �� ����
void Sortirovka(int *numbers, int array_size) 
{
  // ��������� ������ ��� ��������
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    proseivanie(numbers, i, array_size - 1);
  // ���������� ����� �������� ��������� ��������
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    proseivanie(numbers, 0, i - 1);
  }
}

};

void Queue::show() {//����� �������
  for(int i=0; i<count;i++)
    cout<<" "<<a[i];
    cout<<endl;
}

void RandomnoeZapolnenie(Queue &q,  int n){
	for (int i=0; i<n; i++)
	{
	q.push(-100+rand()%200);}
}



void Queue::pop(){// ���������� �������� �� �������
  if ( count==0) {
    cout << "������� �����" <<endl ;
    return ;
  }
  for (int i=0; i<count ; i++) //�������� ���������
		a[i]=a[i+1]; 
		count--;
}
  

void menu(){
	cout << "0 - ���������� �������" << endl;
	cout << "1 - ���������� �������� � ������" << endl;
	cout << "2 - �������� ��������" << endl;
	cout << "3 - �������� (value)" << endl;
	cout << "4 - ����������" << endl;
	cout << "5 - Set" << endl;
	cout << "6 - Get"<<endl;
	cout << "7 - �����" << endl;
}


int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
  Queue q;
  int h=0;
  	
	while (h!=7){
		menu();
		
		do{
		cin >> h;
		if (h<-1 or h>6)
			cout << "�����" << endl;
		}
		while (h<0 and h>6);
			
		switch (h){
			case 0:
				cout << "����� ������ �������" << endl;
				cin >> SIZE;
				if (q.isempty() == 0){
					cout << "������� �����" << endl;
					system("pause");
				}
				else
				RandomnoeZapolnenie(q, SIZE);
				system("CLS");
				q.show();
				break;
			case 1:
				int el;
				cout << "����� �������" << endl;
				cin >> el;
				SIZE++;
				q.push(el);
				system("CLS");
				q.getQueueSize();
				q.show();
				break;
			case 2:
				q.pop();
				SIZE--;
				system("CLS");
				q.getQueueSize();
				q.show();
				break;
			case 3:
				cout << endl;
				cout << "�������� �������� - " <<q.value();
				cout << endl;
				system("pause");
				system("CLS");
				q.show();
				break;
			case 4:
				q.Sortirovka(a,SIZE);
				system("CLS");
				q.getQueueSize();
				q.show();
				break;
			case 5:
				int numb,elem;
				cout<<"����� ����� �������"<<endl;
				cin>>numb;
				cout<<"����� �������"<<endl;
				cin>>elem;
				q.set(numb,elem);
				system("CLS");
				q.show();
				break;
				
			case 6:
				int number;
				cout<<"����� ����� �������"<<endl;
				cin>>number;
				system("CLS");
				cout<<"������� � ���� �������: ";
			 	cout<<	q.get(number)<<endl;
				q.show();
				break;
			
		}
	}


	return 1;
  
  cout<<endl;
  return 0;
}
