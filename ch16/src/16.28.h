#pragma once
#include <functional>
#include <memory>

namespace ch16
{
	class Deleter {
	public:
		template <typename T>
		void operator()(T* p) const
		{
			delete p;
		}
	};

	// ****************************** shared_ptr begin! ******************************
	template <typename T>
	class shared_ptr {
	public:
		// Default constructor
		shared_ptr() :
			ptr(nullptr), ref_count(new std::size_t(1)), deleter(Deleter()) {}

		// Constructor that takes a raw pointer
		explicit shared_ptr(T* raw_ptr) :
			ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(Deleter()) {}

		// Constructor that takes a raw pointer and a Deleter
		template <typename D>
		shared_ptr(T* raw_ptr, D deleter) :
			ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(deleter) {}

		// Copy constructor
		shared_ptr(const shared_ptr& sp) :
			ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter)
		{
			++*ref_count;
		}

		// Move constructor
		shared_ptr(shared_ptr&& sp) noexcept :
			ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter)
		{
			sp.ptr = nullptr;
			sp.ref_count = nullptr;
		}

		// Destructor
		~shared_ptr()
		{
			free();
		}

		// Copy assignment
		shared_ptr& operator=(const shared_ptr& sp);

		// Move assignment
		shared_ptr& operator=(shared_ptr&& sp) noexcept;

		// Reset function that takes a new pointer
		void reset(T* new_ptr);

		// Reset function that takes a new pointer and a new Deleter
		template <typename D>
		void reset(T* new_ptr, D new_deleter);

		// Swap two pointer values and ownership
		void swap(shared_ptr& sp);

		// Get the stored pointer
		T* get() const
		{
			return ptr;
		}

		// Dereference the stored pointer
		T& operator*() const
		{
			return *get();
		}

		// Dereference the stored pointer
		T* operator->() const
		{
			return get();
		}

		// Returns the number of shared_ptr objects referring to the same managed object
		std::size_t use_count() const
		{
			return *ref_count;
		}

		// Checks whether this shared_ptr is unique
		bool unique() const
		{
			return *ref_count == 1;
		}

		// Operator conversion to bool
		operator bool() const
		{
			return ptr ? true : false;
		}

	private:
		T* ptr;
		std::size_t* ref_count;
		std::function<void(T*)> deleter;

		// Utility free function for destructor
		void free();
	};

	// Swap two pointer values and ownership (Nonmember function)
	template <typename T>
	void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs)
	{
		lhs.swap(rhs);
	}

	// Copy assignment
	template <typename T>
	shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& sp)
	{
		if (this != &sp) {
			free();
			ptr = sp.ptr;
			ref_count = sp.ref_count;
			deleter = sp.deleter;
			++*ref_count;
		}
		return *this;
	}

	// Move assignment
	template <typename T>
	shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T>&& sp) noexcept
	{
		swap(sp);
		sp.free();
		return *this;
	}

	// Reset function that takes a new pointer
	template <typename T>
	void shared_ptr<T>::reset(T* new_ptr)
	{
		if (ptr != new_ptr) {
			free();
			ptr = new_ptr;
			ref_count = new std::size_t(1);
		}
	}

	// Reset function that takes a new pointer and a new Deleter
	template <typename T>
	template <typename D>
	void shared_ptr<T>::reset(T* new_ptr, D new_deleter)
	{
		reset(new_ptr);
		deleter = new_deleter;
	}

	// Swap two pointer values and ownership
	template <typename T>
	void shared_ptr<T>::swap(shared_ptr<T>& sp)
	{
		if (this != &sp) {
			using std::swap;
			swap(ptr, sp.ptr);
			swap(ref_count, sp.ref_count);
			swap(deleter, sp.deleter);
		}
	}

	// Utility free function for destructor
	template <typename T>
	void shared_ptr<T>::free()
	{
		if (ptr && --*ref_count == 0) {
			deleter(ptr);
			delete ref_count;
		}
		else if (!ptr)
			delete ref_count;
		ref_count = nullptr;
		ptr = nullptr;
	}
	// ****************************** shared_ptr end! ******************************


	// ****************************** unique_ptr begin! ******************************
	template <typename T, typename D = Deleter>
	class unique_ptr {
	public:
		// Prevents copy constructor and copy assignment
		unique_ptr(const unique_ptr& up) = delete;
		unique_ptr& operator=(const unique_ptr& up) = delete;

		// Default constructor
		unique_ptr() :
			ptr(nullptr), deleter(D()) {}

		// Constructor that takes a raw pointer
		explicit unique_ptr(T* ptr) :
			ptr(ptr), deleter(D()) {}

		// Constructor that takes a raw and a Deleter
		unique_ptr(T* ptr, const D& deleter) :
			ptr(nullptr), deleter(deleter) {}

		// Move constructor
		unique_ptr(unique_ptr&& up) noexcept :
			ptr(up.ptr), deleter(up.deleter)
		{
			up.ptr = nullptr;
		}

		// Move assignment
		unique_ptr& operator=(unique_ptr&& up) noexcept;

		// Destructor
		~unique_ptr()
		{
			free();
		}

		// Releases the ownership of the managed object
		T* release();

		// Reset function that takes a new pointer
		void reset(T* new_ptr = nullptr);

		// Swap two pointer values and ownership
		void swap(unique_ptr& up);

		// Get the stored pointer
		T* get() const
		{
			return ptr;
		}

		// Get the stored deleter
		T* get_deleter() const
		{
			return deleter;
		}

		// Operator conversion to bool
		operator bool() const
		{
			return ptr ? true : false;
		}

		// Dereference the stored pointer
		T& operator*() const
		{
			return *get();
		}

		// Dereference the stored pointer
		T* operator->() const
		{
			return get();
		}
	private:
		T* ptr;
		D deleter;

		// Utility free function for destructor
		void free();
	};

	template <typename T, typename D>
	unique_ptr<T, D>& unique_ptr<T, D>::operator=(unique_ptr<T, D>&& up) noexcept
	{
		swap(up);
		up.free();
		return *this;
	}

	// Swap two pointer values and ownership (Nonmember function)
	template <typename T, typename D>
	void swap(unique_ptr<T, D>& lhs, unique_ptr<T, D>& rhs)
	{
		lhs.swap(rhs);
	}

	// Releases the ownership of the managed object
	template <typename T, typename D>
	T* unique_ptr<T, D>::release()
	{
		T* ret = ptr;
		ptr = nullptr;
		return ret;
	}

	// Reset function that takes a new pointer
	template <typename T, typename D>
	void unique_ptr<T, D>::reset(T* new_ptr /*= nullptr*/)
	{
		free();
		ptr = new_ptr;
	}

	// Swap two pointer values and ownership
	template <typename T, typename D>
	void unique_ptr<T, D>::swap(unique_ptr<T, D>& up)
	{
		if (this != &up) {
			using std::swap;
			swap(ptr, up.ptr);
			swap(deleter, up.deleter);
		}
	}

	// Utility free function for destructor
	template <typename T, typename D>
	void unique_ptr<T, D>::free()
	{
		deleter(ptr);
		ptr = nullptr;
	}
	// ****************************** unique_ptr end! ******************************
}
