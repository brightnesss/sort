#include "sort.h"

void SelectSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end)
{
	for (std::vector<int>::iterator pos = begin;pos != end - 1;++pos)
	{
		std::vector<int>::iterator min = pos;
		for (std::vector<int>::iterator iter = pos + 1;iter != end;++iter)
		{
			if (*iter < *pos)
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
	for (std::vector<int>::iterator i = begin + 1;i != end;++i)
	{
		int val = *i;
		std::vector<int>::iterator j = i - 1;
		while (j != begin - 1 && *j > val)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = val;
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