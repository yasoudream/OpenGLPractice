#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#define FRIEND_SINGLENTON(mgr) friend class Singleton<mgr>

#include <mutex>

template <class T>
class Singleton
{
public:
	static T* GetInstanceP()
	{
		if (ptr == nullptr)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			ptr.reset(new(std::nothrow) T());
		}
		return ptr.get();
	};
	virtual ~Singleton() {  };
protected:

	Singleton() {}
	static std::unique_ptr<T> ptr;
	static std::mutex m_mutex;
};

template<class T>
std::unique_ptr<T> Singleton<T>::ptr = nullptr;

template<class T>
std::mutex Singleton<T>::m_mutex;


#endif // !__SINGLETON_H__


