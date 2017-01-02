#pragma once

#include <iostream>

namespace algorithmic
{
	template<typename T>
	class BoundedQueue
	{
	public:
		BoundedQueue(int max_size);
		~BoundedQueue();

		void Insert(T* item);
		T* Remove();
		T* Peek();

		bool IsEmpty() { return num_items_ == 0; }
		bool IsFull() { return num_items_ == max_size_; }

		void DisplayQueue();

	private:
		T** queue_array_;
		int front_;
		int rear_;
		int num_items_;
		int max_size_;
	};
	
	template<typename T>
	inline BoundedQueue<T>::BoundedQueue(int max_size)
	{
		max_size_ = max_size;
		num_items_ = 0;
		front_ = 0;
		rear_ = -1;
		queue_array_ = new T*[max_size_];
	}
	
	template<typename T>
	inline BoundedQueue<T>::~BoundedQueue()
	{
		delete[] queue_array_;
	}
	
	template<typename T>
	inline void BoundedQueue<T>::Insert(T* item)
	{
		if (!IsFull())
		{
			queue_array_[++rear_] = item;
			num_items_++;
		}
	}

	template<typename T>
	inline T* BoundedQueue<T>::Remove()
	{
		if (!IsEmpty())
		{
			auto removed_item = queue_array_[front_++];

			if (front_ == max_size_)
				front_ = 0;

			num_items_--;

			return removed_item;
		}
		else
		{
			return nullptr;
		}
	}
	
	template<typename T>
	inline T* BoundedQueue<T>::Peek()
	{
		if (!IsEmpty())
			return queue_array_[front_];
		else
			return nullptr;
	}

	template<typename T>
	inline void BoundedQueue<T>::DisplayQueue()
	{
		std::cout << "[ ";

		for (int i = 0; i < max_size_; i++)
		{
			if (queue_array_[i] != nullptr)
				std::cout << *(queue_array_[i]) << " ";
		}

		std::cout << "]" << std::endl;
	}
}