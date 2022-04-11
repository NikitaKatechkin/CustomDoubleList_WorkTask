#pragma once

#include <iostream>
#include "CustomDoubleListNode.h"


template <typename T>
class CustomDoubleList
{
using ListNode = CustomDoubleListNode<T>;

public:
	CustomDoubleList() = default;
	CustomDoubleList(std::initializer_list<T> l_init_list);

	virtual ~CustomDoubleList() = default;

	void PushFront(const T& l_value);
	void PushBack(const T& l_value);

	void PopFront();
	void PopBack();

	T Front();
	T Back();

	void Insert(const unsigned int l_index, const T& l_value);
	void Remove(const unsigned int l_index);
	void Clear();
	
	unsigned int GetSize();

	friend bool operator==(const CustomDoubleList<T>& left_operand, const CustomDoubleList<T>& right_operand)
	{
		if (left_operand.m_size != right_operand.m_size)
		{
			return false;
		}

		auto left_element = left_operand.m_head_node;
		auto right_element = right_operand.m_head_node;

		for (unsigned int counter = 0; counter < left_operand.m_size; counter++)
		{
			if (left_element->m_value != right_element->m_value)
			{
				return false;
			}

			left_element = left_element->m_next_node;
			right_element = right_element->m_next_node;
		}

		return true;
	}
protected:
	unsigned int m_size = 0;

	std::shared_ptr<ListNode> m_head_node = nullptr;
	std::shared_ptr<ListNode> m_tail_node = nullptr;
};

template<typename T>
CustomDoubleList<T>::CustomDoubleList(std::initializer_list<T> l_init_list)
{
	for (auto iter : l_init_list)
	{
		PushBack(iter);
	}
}

template<typename T>
void CustomDoubleList<T>::PushFront(const T& l_value)
{
	m_size++;
	auto new_node = std::make_shared<ListNode>(l_value);

	if (m_size == 1)
	{
		m_head_node = new_node;
		m_tail_node = new_node;

		return;
	}

	new_node->m_next_node = m_head_node;
	m_head_node->m_prev_node = new_node;

	m_head_node = new_node;
}

template<typename T>
void CustomDoubleList<T>::PushBack(const T& l_value)
{
	m_size++;
	auto new_node = std::make_shared<ListNode>(l_value);

	if (m_size == 1)
	{
		m_head_node = new_node;
		m_tail_node = new_node;

		return;
	}

	m_tail_node->m_next_node = new_node;
	new_node->m_prev_node = m_tail_node;

	m_tail_node = new_node;
}

template<typename T>
void CustomDoubleList<T>::PopFront()
{
	if (m_size < 1)
	{
		throw std::exception("Trying to pop front element of an empty list");
	}

	m_size--;

	if (m_size == 0)
	{
		m_head_node = nullptr;
		m_tail_node = nullptr;

		return;
	}

	m_head_node = m_head_node->m_next_node;
	m_head_node->m_prev_node = nullptr;
}

template<typename T>
void CustomDoubleList<T>::PopBack()
{
	if (m_size < 1)
	{
		throw std::exception("Trying to pop back element of an empty list");
	}

	m_size--;

	if (m_size == 0)
	{
		m_head_node = nullptr;
		m_tail_node = nullptr;

		return;
	}

	m_tail_node = m_tail_node->m_prev_node;
	m_tail_node->m_next_node = nullptr;
}

template<typename T>
T CustomDoubleList<T>::Front()
{
	if (m_size < 1)
	{
		throw std::exception("Trying to access front element of an empty list");
	}

	return m_head_node->m_value;
}

template<typename T>
T CustomDoubleList<T>::Back()
{
	if (m_size < 1)
	{
		throw std::exception("Trying to access back element of an empty list");
	}

	return m_tail_node->m_value;
}

template<typename T>
void CustomDoubleList<T>::Insert(const unsigned int l_index, const T& l_value)
{
	if (l_index < 0 || l_index > m_size)
	{
		throw std::exception("Insertion index out of bounds exception");
	}

	//std::cout << "here" << std::endl;

	if (l_index == 0)
	{
		PushFront(l_value);
		return;
	}
	else if (l_index == m_size)
	{
		PushBack(l_value);
		return;
	}

	//std::cout << "here" << std::endl;
	
	auto before_insertion_node = m_head_node;
	for (unsigned int index = 0; index < (l_index - 1); index++)
	{
		before_insertion_node = before_insertion_node->m_next_node;
	}

	auto new_node = std::make_shared<ListNode>(l_value);
	new_node->m_next_node = before_insertion_node->m_next_node;
	new_node->m_prev_node = before_insertion_node;

	before_insertion_node->m_next_node->m_prev_node = new_node;
	before_insertion_node->m_next_node = new_node;

	//std::cout << "Before value: " << new_node->m_prev_node->m_value << std::endl;
	//std::cout << "After value: " << new_node->m_next_node->m_value << std::endl;
	//std::cout << "here" << std::endl;

	m_size++;
}

template<typename T>
void CustomDoubleList<T>::Remove(const unsigned int l_index)
{
	if (l_index < 0 || l_index >= m_size)
	{
		throw std::exception("Removing index out of bounds exception");
	}

	if (l_index == 0)
	{
		PopFront();
		return;
	}
	else if (l_index == (m_size - 1))
	{
		PopBack();
		return;
	}

	auto before_insertion_node = m_head_node;
	for (unsigned int index = 0; index < (l_index - 1); index++)
	{
		before_insertion_node = before_insertion_node->m_next_node;
	}

	before_insertion_node->m_next_node = before_insertion_node->m_next_node->m_next_node;
	before_insertion_node->m_next_node->m_prev_node = before_insertion_node;

	m_size--;
}

template<typename T>
void CustomDoubleList<T>::Clear()
{
	while (m_size > 0)
	{
		PopFront();
	}
}

template<typename T>
unsigned int CustomDoubleList<T>::GetSize()
{
	return m_size;
}
