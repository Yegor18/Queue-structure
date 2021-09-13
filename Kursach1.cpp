#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int SIZE; //Размер массива
int *a;//массив
class Queue {
	public :
   	int count;//Указатель на начало-Счетчик 
    void pop();//функция добавления
    void show();//вывод массива
   	  
	Queue() {//конструктор
 		a = new int[SIZE];//выделение динамической памяти для массива
  		count =0 ;
  	}
		
	bool isempty(){ //Пуст ли массив?	
		if (SIZE == 0) return 0;
		else return 1;
	};
	
	int value(){ //Вывод значения на выходе
		return a[0]; 
	};
	
	void getQueueSize(){ //Вывод размера очереди
  		cout<<"Кол-во элементов в массиве:"<<SIZE<<endl;
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
	void push ( int num ){  //Помещение элемента в очередь
  	if (count == SIZE) 
  		cout <<"Очередь полна" <<endl ;
  	else
	{
	  	a[count]=num;
 		count++;
	}
}
// Функция "просеивания" через кучу - формирование кучи
void proseivanie(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // если мы в последнем ряду, 
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void Sortirovka(int *numbers, int array_size) 
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    proseivanie(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    proseivanie(numbers, 0, i - 1);
  }
}

};

void Queue::show() {//Вывод массива
  for(int i=0; i<count;i++)
    cout<<" "<<a[i];
    cout<<endl;
}

void RandomnoeZapolnenie(Queue &q,  int n){
	for (int i=0; i<n; i++)
	{
	q.push(-100+rand()%200);}
}



void Queue::pop(){// Извлечение элемента из очереди
  if ( count==0) {
    cout << "очередь пуста" <<endl ;
    return ;
  }
  for (int i=0; i<count ; i++) //смещение элементов
		a[i]=a[i+1]; 
		count--;
}
  

void menu(){
	cout << "0 - Заполнение массива" << endl;
	cout << "1 - Добавление элемента в массив" << endl;
	cout << "2 - Удаление элемента" << endl;
	cout << "3 - Значение (value)" << endl;
	cout << "4 - Сортировка" << endl;
	cout << "5 - Set" << endl;
	cout << "6 - Get"<<endl;
	cout << "7 - Выход" << endl;
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
			cout << "Выход" << endl;
		}
		while (h<0 and h>6);
			
		switch (h){
			case 0:
				cout << "Введи размер массива" << endl;
				cin >> SIZE;
				if (q.isempty() == 0){
					cout << "Очередь пуста" << endl;
					system("pause");
				}
				else
				RandomnoeZapolnenie(q, SIZE);
				system("CLS");
				q.show();
				break;
			case 1:
				int el;
				cout << "Введи элемент" << endl;
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
				cout << "Значение элемента - " <<q.value();
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
				cout<<"Введи номер позиции"<<endl;
				cin>>numb;
				cout<<"Введи элемент"<<endl;
				cin>>elem;
				q.set(numb,elem);
				system("CLS");
				q.show();
				break;
				
			case 6:
				int number;
				cout<<"Введи номер позиции"<<endl;
				cin>>number;
				system("CLS");
				cout<<"Элемент в этой позиции: ";
			 	cout<<	q.get(number)<<endl;
				q.show();
				break;
			
		}
	}


	return 1;
  
  cout<<endl;
  return 0;
}
