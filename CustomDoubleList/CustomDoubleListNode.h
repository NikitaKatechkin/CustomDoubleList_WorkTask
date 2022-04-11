#pragma once
#include <memory>

template <typename T>
struct CustomDoubleListNode
{
	T m_value;

	std::shared_ptr<CustomDoubleListNode<T>> m_prev_node;
	std::shared_ptr<CustomDoubleListNode<T>> m_next_node;

	CustomDoubleListNode(const T& l_value);
	CustomDoubleListNode();
};

template<typename T>
CustomDoubleListNode<T>::CustomDoubleListNode(const T& l_value) :
	m_value(l_value), m_prev_node(nullptr), m_next_node(nullptr)
{
	
}

template<typename T>
CustomDoubleListNode<T>::CustomDoubleListNode()
{
	m_value = T();

	m_prev_node = nullptr;
	m_next_node = nullptr;
}
