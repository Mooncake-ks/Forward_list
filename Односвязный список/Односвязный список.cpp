#include <iostream>


template<typename T>
class List
{
public:

	List();
	~List();

	void push_from(const T& data);
	void push_back(const T& data);
	void pop_front();

	void insert(const T& data,const int& index);
	void remove(const T& data);

	void clear();
	T& operator[](const int& index);
	int get_size() const{ return m_size; }
	
private:

	struct Node   
	{
		T m_data;
		Node* m_next{nullptr};
		Node(const T& data, Node* next = nullptr);
	};                                  
	
	Node* m_head;
	int m_size;
};

template<typename T>
void print_list( List<T>& ls);

int main()
{
	List<int> a;
	
	a.push_back(56);
	a.push_back(4);
	a.push_back(611);
	a.push_back(5);
	a.push_back(12);

	print_list(a);
	a.pop_front();
	std::cout << a[1] << std::endl;
	a.remove(12);
	print_list(a);
	
	
    return 0;
}

template<typename T>
List<T>::Node::Node(const T& data, Node* next):m_data{data},m_next{next}{}

template<typename T>
List<T>::List() : m_size{ 0 }, m_head{nullptr} {}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_from(const T& data)
{
	m_head = new Node(data, m_head);
	m_size++;
}

template<typename T>
void List<T>::push_back(const T& data)
{
	if (!m_head)
	{
		m_head = new Node(data);
	}
	else
	{
		Node* p = m_head;
		while (p->m_next) p = p->m_next;
		p->m_next = new Node(data);
	}
	m_size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node* p = m_head;
	m_head = m_head->m_next;
	delete p;
	m_size--;
}



template<typename T>
void List<T>::insert(const T& data, const int& index)
{
	if (index==0)
	{
		push_from(data);
	}
	else
	{
		Node* p = m_head;
		for (int i {0}; i < index-1; ++i)
		{
			p = p->m_next;
		}
		Node* new_node = new Node(data,p->m_next);
		p->m_next = new_node;
		m_size++;
	}
}

template<typename T>
void List<T>::remove(const T& data)
{
	Node* p = m_head;
	Node* p_next = p->m_next;
	while (p_next && p_next->m_data != data)
	{
		p_next = p_next->m_next;
		p = p->m_next;
	}
	if (!p_next)
	{
		std::cout << "This element cloes not exist" << std::endl;
	}
	p->m_next = p_next->m_next;
	delete p_next;
	m_size--;
}

template<typename T>
void List<T>::clear()
{
	while (m_size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int& index)
{
	Node* p = m_head;
	int i{ 0 };

	while (p)
	{
		if (i==index)
		{
			return p->m_data;
		}
		p = p->m_next;
		i++;
	}
}



template<typename T>
void print_list( List<T>& ls)
{
	for (int i{ 0 }; i < ls.get_size(); ++i)
	{
		std::cout << "Data " << i+1  << " :" << ls[i] << std::endl;
	}
}
