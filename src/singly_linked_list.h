#pragma once

namespace algorithmic
{
	template<typename T>
	class SinglyLinkedList
	{
	private:
		struct Node
		{
			T& data;
			Node* next;
		};

	public:
		SinglyLinkedList();
		~SinglyLinkedList();

		void InsertFront(T& data);

	private:
		Node* front;
		Node* last;
	};

	template<typename T>
	inline SinglyLinkedList<T>::SinglyLinkedList()
	{
	}

	template<typename T>
	inline SinglyLinkedList<T>::~SinglyLinkedList()
	{
	}

	template<typename T>
	inline void SinglyLinkedList<T>::InsertFront(T& data)
	{
		Node* node = new Node();
		node->data = data;
	}
}