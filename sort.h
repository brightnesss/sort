#pragma once

#include <iostream>
#include <vector>

void SelectSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);

void InsertSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);

void BubbleSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);

std::vector<int>::iterator HoarePartition(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);
void QuickSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);

void HeapBottomUp(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);
void HeapSort(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);