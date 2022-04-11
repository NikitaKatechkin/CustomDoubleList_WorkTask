#pragma once

#include <iostream>
#include "CustomDoubleList.h"

template <typename T>
class CustomDoubleRingedListV2 final : public CustomDoubleList<T>
{
public:
	CustomDoubleRingedListV2();
	CustomDoubleRingedListV2(std::initializer_list<T> l_init_list);

	~CustomDoubleRingedListV2() = default;

	void PushFront(const T& l_value);
	void PushBack(const T& l_value);

	void PopFront();
	void PopBack();

	friend bool operator==(const CustomDoubleRingedListV2<T>& left_operand, const CustomDoubleRingedListV2<T>& right_operand)
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
};

template<typename T>
CustomDoubleRingedListV2<T>::CustomDoubleRingedListV2() :
	CustomDoubleList<T>()
{

}

template<typename T>
CustomDoubleRingedListV2<T>::CustomDoubleRingedListV2(std::initializer_list<T> l_init_list)
{
	for (auto iter : l_init_list)
	{
		PushBack(iter);
	}
}

template<typename T>
void CustomDoubleRingedListV2<T>::PushFront(const T& l_value)
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
void CustomDoubleRingedListV2<T>::PushBack(const T& l_value)
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
void CustomDoubleRingedListV2<T>::PopFront()
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
void CustomDoubleRingedListV2<T>::PopBack()
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
	m_tail_node->m_next_node = m_head_node;

	m_head_node->m_prev_node = m_tail_node;
}