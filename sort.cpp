#include "sort.h"

void SelectSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	for (std::vector<int>::iterator pos = begin;pos != end - 1;++pos)
	{
		std::vector<int>::iterator min = pos;
		for (std::vector<int>::iterator iter = pos + 1;iter != end;++iter)
		{
			if (*iter < *min)
			{
				min = iter;
			}
			else continue;
		}
		std::swap(*min, *pos);
	}
}

void InsertSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	bool isBegin = false;
	for (std::vector<int>::iterator i = begin + 1;i != end;++i)
	{
		int val = *i;
		std::vector<int>::iterator j = i - 1;
		while (j >= begin && *j > val)
		{
			*(j + 1) = *j;
			if (j == begin) 
			{
				*j = val;
				isBegin = true;
				break;
			}
			else --j;
		} 
		if (!isBegin) *(j + 1) = val;
	}
}

void BubbleSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	bool noComplete;
	for (std::vector<int>::iterator i = begin;i != end - 1;++i)
	{
		noComplete = false;
		for (std::vector<int>::iterator j = begin;j != begin + (end - i - 1);++j)
		{
			if (*(j + 1) < *j)
			{
				std::swap(*j, *(j + 1));
				noComplete = true;
			}
		}
		if (!noComplete) break;
	}
}

std::vector<int>::iterator HoarePartition(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	std::vector<int>::iterator i, j;
	i = begin;
	j = end - 1;
	int val = *begin;
	while (true)
	{
		while ((i != end) && (*i <= val)) ++i;
		while ((j != begin) && (*j >= val)) --j;
		if (i < j)
		{
			std::swap(*i, *j);
			++i;
			--j;
		}
		else break;
	}
	std::swap(*begin, *j);
	return j;
}

void QuickSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	if (begin < end)
	{
		std::vector<int>::iterator s = HoarePartition(begin, end);
		QuickSort(begin, s);
		QuickSort(s + 1, end);
	}
}

void HeapBottomUp(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	std::vector<int>::difference_type num, temp, k;
	num = end - begin;
	temp = floor(num / 2) - 1;
	std::vector<int>::iterator pos;
	int val;
	for (std::vector<int>::iterator i = begin + temp;i >= begin;--i)
	{
		pos = i;
		k = i - begin;
		val = *pos;
		bool heap = false;
		while (!heap && (end - pos) > k + 1)
		{
			std::vector<int>::iterator j = pos + k + 1;
			if (j < end - 1)
			{
				if (*j < *(j + 1)) j = j + 1;
			}
			if (val >= *j) heap = true;
			else
			{
				*pos = *j;
				k = j - begin;
				pos = j;
			}
		}
		*pos = val;
		if (i == begin) break;
	}
}

void HeapSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	while ((begin + 1) != end)
	{
		HeapBottomUp(begin, end);
		std::swap(*begin, *(end - 1));
		--end;
	}
}