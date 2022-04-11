#pragma once

#include "CustomDoubleListNode.h"

template <typename T>
class CustomDoubleRingedList
{
public:
	CustomDoubleRingedList() = default;
	~CustomDoubleRingedList() = default;

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
private:
	unsigned int m_size = 0;

	std::shared_ptr<CustomDoubleListNode<T>> m_head_node = nullptr;
	std::shared_ptr<CustomDoubleListNode<T>> m_tail_node = nullptr;
};

template<typename T>
void CustomDoubleRingedList<T>::PushFront(const T& l_value)
{
	m_size++;
	auto new_node = std::make_shared<CustomDoubleListNode<T>>(l_value);

	if (m_size == 1)
	{
		m_head_node = new_node;
		m_tail_node = new_node;

		m_head_node->m_next_node = m_tail_node;
		m_head_node->m_prev_node = m_tail_node;

		m_tail_node->m_next_node = m_head_node;
		m_tail_node->m_prev_node = m_head_node;

		return;
	}

	new_node->m_next_node = m_head_node;
	new_node->m_prev_node = m_tail_node;
	m_head_node->m_prev_node = new_node;

	m_head_node = new_node;
}

template<typename T>
void CustomDoubleRingedList<T>::PushBack(const T& l_value)
{
	m_size++;
	auto new_node = std::make_shared<CustomDoubleListNode<T>>(l_value);

	if (m_size == 1)
	{
		m_head_node = new_node;
		m_tail_node = new_node;

		m_head_node->m_next_node = m_tail_node;
		m_head_node->m_prev_node = m_tail_node;

		m_tail_node->m_next_node = m_head_node;
		m_tail_node->m_prev_node = m_head_node;

		return;
	}

	m_tail_node->m_next_node = new_node;
	new_node->m_prev_node = m_tail_node;
	new_node->m_next_node = m_head_node;


	m_tail_node = new_node;
}

template<typename T>
void CustomDoubleRingedList<T>::PopFront()
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
	m_head_node->m_prev_node = m_tail_node;

	m_tail_node->m_next_node = m_head_node;
}

template<typename T>
void CustomDoubleRingedList<T>::PopBack()
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

	m_tail_node = m_tail_node->m_prev_node;
	m_tail_node->m_next_node = m_head_node;

	m_head_node->m_prev_node = m_tail_node;
}

template<typename T>
T CustomDoubleRingedList<T>::Front()
{
	if (m_size < 1)
	{
		throw std::exception("Trying to access front element of an empty list");
	}

	return m_head_node->m_value;
}

template<typename T>
T CustomDoubleRingedList<T>::Back()
{
	if (m_size < 1)
	{
		throw std::exception("Trying to access back element of an empty list");
	}

	return m_tail_node->m_value;
}

template<typename T>
void CustomDoubleRingedList<T>::Insert(const unsigned int l_index, const T& l_value)
{
	if (l_index < 0 || l_index > m_size)
	{
		throw std::exception("Insertion index out of bounds exception");
	}

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

	auto before_insertion_node = m_head_node;
	for (unsigned int index = 0; index < (l_index - 1); index++)
	{
		before_insertion_node = before_insertion_node->m_next_node;
	}

	auto new_node = std::make_shared<CustomDoubleListNode<T>>(l_value);
	new_node->m_next_node = before_insertion_node->m_next_node;
	new_node->m_prev_node = before_insertion_node;

	before_insertion_node->m_next_node->m_prev_node = new_node;
	before_insertion_node->m_next_node = new_node;

	m_size++;
}

template<typename T>
void CustomDoubleRingedList<T>::Remove(const unsigned int l_index)
{
	if (l_index < 0 || l_index >= m_size)
	{
		throw std::exception("Insertion index out of bounds exception");
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
void CustomDoubleRingedList<T>::Clear()
{
	while (m_size > 0)
	{
		PopFront();
	}
}

template<typename T>
unsigned int CustomDoubleRingedList<T>::GetSize()
{
	return m_size;
}
