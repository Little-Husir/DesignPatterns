#include "singleton.h"

////饿汉式-懒汉式的区别
/// 懒汉式单例：懒汉式单例在需要时才创建实例，延迟实例化。实现方法如下所示
/// 优点：线程安全，保证了实例的唯一性。只有在需要时才创建实例，节省内存。
/// 缺点：实现稍微复杂，要考虑多线程的使用，使用了双重检查锁定。

/// 饿汉式单例：饿汉式单例在类加载时就创建了单例实例。其实现方式如下所示
/// 优点：实现简单，类加载时即完成实例化，避免了线程同步问题。由于实例在类加载时即创建，保证了线程安全。
/// 缺点：即使单例实例未被使用，也会在类加载时创建，可能会浪费内存。

/// 总结：
///    饿汉式单例适合实例初始化较快且占用资源较少的情况，优点是实现简单且线程安全
/// 但缺点是类加载时即创建实例，可能浪费内存。

///    懒汉式单例适合实例初始化较慢或占用资源较多的情况，优点是只有在需要时才创建实例，节省内存
/// 但缺点是基本懒汉式在多线程环境下不安全，需要使用更复杂的线程安全机制如双重检查锁定来保证线程安全。


//// 单例 - 懒汉式
//Singleton *Singleton::m_pSingleton = NULL;

//Singleton *Singleton::GetInstance()
//{
//    if (m_pSingleton == NULL)
//        m_pSingleton = new Singleton();

//    return m_pSingleton;
//}

//// 单例 - 饿汉式
//Singleton *Singleton::m_pSingleton = new Singleton();

//Singleton *Singleton::GetInstance()
//{
//    return m_pSingleton;
//}


//// 单例 - 懒汉式（双检锁 DCL 机制）
/// 双检锁-对于m_pSingleton存在的情况，GetInstance直接返回这没有问题，当m_pSingleton为null并且
/// 同时有两个线程调用GetInstance方法时，他们将都可以通过第一重m_pSingleton == NULL的判断，然后由于lock机制
/// 这两个线程只有一个进入，另一个在外排队等候，必须要其中的一个进入并出来后，另一个才能进入。而此时如果没有第二重的
/// m_pSingleton是否为null的判断，则第一个线程创建了实例，而第二个线程还是可以继续再创建新的实例，这就没有达到单例的目的

//Singleton *Singleton::m_pSingleton = NULL;
//mutex Singleton::m_mutex;
//
//Singleton *Singleton::GetInstance()
//{
//    if (m_pSingleton == NULL) {
//        std::lock_guard<std::mutex> lock(m_mutex);  // 加锁
//        if (m_pSingleton == NULL) {
//            m_pSingleton = new Singleton();
//        }
//    }
//    return m_pSingleton;
//}


// 单例 - 懒汉式（双检锁 DCL 机制）
Singleton *Singleton::m_pSingleton = NULL;

Singleton *Singleton::GetInstance()
{
    if (m_pSingleton == NULL)
        m_pSingleton = new Singleton();

    return m_pSingleton;
}
