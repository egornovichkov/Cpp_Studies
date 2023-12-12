#pragma once

template <typename T>
class StupidSmartPointer
{
public:
    StupidSmartPointer();

    StupidSmartPointer(T*);

    void release();

    void reset(T*);

    T* get();

    operator bool();

    T& operator*();

    template <typename... Types>
    void emplace(Types&&...);

	 ~StupidSmartPointer() noexcept;
private:
    T* m_data;
};

#include "StupidSmartPointer.ipp"