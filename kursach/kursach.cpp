 
#include <iostream>
#include <vector>

 
class node {
public:
    int key;
    node* p; //указатель на пердыдущий элемент
    int getKey()
    {
        return key;
    }

};
 
class Stack: public node {
 
    private:
		
        int max_lenght = 30;
        node* head; //указатель верхнего элемента
 
    public:
 
        Stack()//Конструктор по умолчанию
		{ 
            head = NULL;
        }
		Stack(int length)
        {
            head = NULL;
            max_lenght = length;
        }

		void _max_lenght_(int length)
        {
            max_lenght = length;
        }
 
        ~Stack() { //Деструктор, он же remove
            while (head != NULL) {
                node* temporal = head->p;
                delete head;
                head = temporal;
            }
        }

    auto stackToVector(std::vector<int> vct)
	{
        	node* temporal = head;
	        while (temporal != NULL) {
	            vct.push_back(temporal->key);
	            temporal = temporal->p;
	        }
            return vct;
	}

    int lenght()
    {
        node* tempStart = head;
        int i = 0;
        while (head != NULL) {
            node* temporal = head->p;
            i += 1;
            head = temporal;
        }
        head = tempStart;
        return i;
    }
 
    void push(int data) { //Функция добавления элемента в стек
        if (lenght() + 2 <= max_lenght) {
            node* temoral = new node;// выделние динамической памяти под новый элемент
            temoral->key = data;
            temoral->p = head;
            head = temoral;
        } else std::cout << "Stack is over! Can`t input " << data << "\n";
    }
 
    void pop() { //Функция удаления элемента из вершины стека
        if (head == NULL) {
	        std::cout << "Empty stack, deliting is imposible\n";
        } else {
            node* temporal = head;
            std::cout <<"delited: " << temporal->key << std::endl;
            head = head->p;
            delete temporal;
        }
    }
 
    int sum() { //Функция поиска суммы элементов стека
        node* temporal = head;
        int sum = 0;
        while (temporal != NULL) {
            sum += temporal->key;
            temporal = temporal->p;
        }
        return sum;
    }
 
    void print() { //Функция вывода списка на экран
        bool flag = false;
        node* temporal = head;
        std::cout << "Now the stack is:\n";
        while (temporal != NULL) {
	        std::cout << temporal->key << " ";
            temporal = temporal->p;
            flag = true;
        }
        if (!flag) {
	        std::cout << "The stack is empty!\n";
        }
        std::cout << "\n";
    }
};
 
int main() {
    Stack st;
    st._max_lenght_(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.print();
    st.pop();
    st.pop();
    st.print();
    std::cout << "Found sum of stack elements: " << st.sum() << "\n";
    return 0;
}