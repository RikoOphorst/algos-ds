namespace algorithmic
{
	template<class T>
	class BoundedStack
	{
	public:
		BoundedStack(int maxSize);
		~BoundedStack();

		void Push(const T* item);
		void Push(T* item);
		T* Pop();
		T* Peek();

		bool IsEmpty() { return top_ == -1; }
		bool IsFull() { return top_ == max_size_ - 1; }
	private:
		int max_size_;
		int top_;
		T** stack_array_;
	};

	template<typename T>
	inline BoundedStack<T>::BoundedStack(int maxSize) :
		max_size_(maxSize),
		top_(-1)
	{
		stack_array_ = new T*[maxSize];
	}
	
	template<typename T>
	inline BoundedStack<T>::~BoundedStack()
	{
		delete[] stack_array_;
	}

	template<class T>
	inline void BoundedStack<T>::Push(const T* item)
	{
		if (!IsFull())
		{
			stack_array_[++top_] = item;
		}
	}

	template<class T>
	inline void BoundedStack<T>::Push(T* item)
	{
		if (!IsFull())
		{
			stack_array_[++top_] = item;
		}
	}

	template<class T>
	inline T* BoundedStack<T>::Pop()
	{
		if (!IsEmpty())
		{
			return stack_array_[top_--];
		}
		else
		{
			return nullptr;
		}
	}
	
	template<class T>
	inline T* BoundedStack<T>::Peek()
	{
		if (!IsEmpty())
			return stack_array_[top_];
		else
			return nullptr;
	}
}