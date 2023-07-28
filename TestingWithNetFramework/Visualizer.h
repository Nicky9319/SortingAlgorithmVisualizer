#pragma once
#include<raylib.h>
#include<ctime>
#include<cstdlib>

#include "Pillar.h"
//#include<iostream>

int winWidth()
{
	return 1200;
}
int winHeigth()
{
	return 600;
}
int minPillarHeight()
{
	return 50;
}
int getPillarWidth() {
	return 5;
}


void drawPillars(Pillar* pillars, int totalPillers)
{
	int startingX = 40;
	int pillarGap = 0;
	int minPillarHeight = 100;

	for (int itr = 0; itr < totalPillers; itr++) {
		int posX = startingX + (getPillarWidth() + 1) * itr;
		int posY = GetScreenHeight() - (pillars[itr].getHeight());
		int width = getPillarWidth();
		int height = pillars[itr].getHeight();

		DrawRectangle(posX, posY, width, height, WHITE);
	}

}
void RenderScreen(Pillar* pillars, int totalPillars)
{
	
	BeginDrawing();

	drawPillars(pillars, totalPillars);

	ClearBackground(BLACK);
	DrawFPS(GetScreenWidth() - 100, 10);
	EndDrawing();
}




void swapPillars(Pillar* pillars, int low, int high)
{
	Pillar swapVar = pillars[low];
	pillars[low] = pillars[high];
	pillars[high] = swapVar;
}
void shufflePillars(Pillar* pillars, int totalPillers)
{
	int arbNumber = 200;
	for (int cnt = 0; cnt < 200; cnt++)
	{
		int low = rand() % 200;
		int high = rand() % 200;

		swapPillars(pillars, low, high);
	}
}



int quicksort_Partition(Pillar* pillars, int totalPillars , int smaller, int higher)
{
	int low = smaller;
	int high = higher;

	int pivot = pillars[low].getNumber();
	while (low < high)
	{
		do
		{
			low++;
		} while (pillars[low].getNumber() <= pivot);
		do
		{
			high--;
		} while (pillars[high].getNumber() > pivot);

		if (low < high)
		{
			swapPillars(pillars, low, high);
			RenderScreen(pillars, totalPillars);
		}
	}

	swapPillars(pillars, high, smaller);
	RenderScreen(pillars, totalPillars);

	return high;
}
void mergesort_Merge(Pillar* pillars, int totalPillars, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	Pillar* newPillars = new Pillar[high + 1];

	for (int itr = 0; itr <= high; itr++)
	{
		Pillar pill = pillars[low];
		newPillars[itr] = pill;
	}

	while (i <= mid && j <= high)
	{
		if (pillars[i].getNumber() < pillars[j].getNumber())
		{
			newPillars[k] = pillars[i];
			i++;
			k++;
		}
		else
		{
			newPillars[k] = pillars[j];
			j++;
			k++;
		}
	}

	for (; i <= mid; i++)
	{
		newPillars[k++] = pillars[i];
	}
	for (; j <= high; j++)
	{
		newPillars[k++] = pillars[j];
	}

	for (i = low; i <= high; i++) {
		pillars[i] = newPillars[i];
	}
}

void BubbleSort(Pillar* pillars , int totalPillars) 
{
	for (int counter = 0; counter < totalPillars - 1; counter++)
	{
		for (int index = 0; index <= totalPillars - 2 - counter; index++)
		{
			if (pillars[index].getNumber() > pillars[index + 1].getNumber())
			{
				swapPillars(pillars, index, index + 1);

				RenderScreen(pillars, totalPillars);
			}
		}
	}
}
void InsertionSort(Pillar* pillars, int totalPillars)
{
	for (int counter = 1; counter <= totalPillars - 1; counter++)
	{
		int index = counter;
		while (index != 0)
		{
			if (pillars[index].getNumber() > pillars[index - 1].getNumber())
			{
				break;
			}
			
			swapPillars(pillars, index, index - 1);
			RenderScreen(pillars, totalPillars);
			index--;
		}
	}
}
void SelectionSort(Pillar* pillars, int totalPillars)
{
	for (int counter = 0; counter <= totalPillars - 2; counter++)
	{
		int lowValueIndex = counter;
		for (int index = counter + 1; index <= totalPillars - 1; index++)
		{
			if (pillars[index].getNumber() < pillars[lowValueIndex].getNumber())
			{
				lowValueIndex = index;
				RenderScreen(pillars, totalPillars);
			}
		}

		swapPillars(pillars, counter, lowValueIndex);
		RenderScreen(pillars, totalPillars);
	}
}
void QuickSort(Pillar* pillars, int totalPillars , int low , int high)
{
	if (low < high)
	{
		int pivot = quicksort_Partition(pillars , totalPillars , low , high);
		RenderScreen(pillars, totalPillars);

		QuickSort(pillars , totalPillars , low, pivot);
		RenderScreen(pillars, totalPillars);

		QuickSort(pillars , totalPillars , pivot + 1, high);
		RenderScreen(pillars, totalPillars);
	}
}
void MergeSort(Pillar* pillars, int totalPillars , int low , int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		MergeSort(pillars, totalPillars, low, mid);
		RenderScreen(pillars, totalPillars);

		MergeSort(pillars, totalPillars, mid + 1, high);
		RenderScreen(pillars, totalPillars);

		mergesort_Merge(pillars, totalPillars, low, mid, high);
		RenderScreen(pillars, totalPillars);
	}
}




void InitializePillars(Pillar * pillars , int totalPillars)
{
	for (int itr = 0; itr < totalPillars; itr++)
	{
		pillars[itr].setNumber(itr + 1);
		pillars[itr].setWidth(getPillarWidth());
		pillars[itr].setHeight(100 + itr);
	}
}

void StartVisualizer(int SortingAlgo, int totalPillars = 200)
{

	Pillar* pillars = new Pillar[totalPillars];
	InitializePillars(pillars, totalPillars);
	shufflePillars(pillars, totalPillars);

	InitWindow(1250, 800, "Sorting Visualizer");
	SetWindowState(FLAG_VSYNC_HINT);

	if (SortingAlgo == 0) { BubbleSort(pillars, totalPillars);}
	if (SortingAlgo == 1) { InsertionSort(pillars, totalPillars); }
	if (SortingAlgo == 2) { SelectionSort(pillars, totalPillars); }
	if (SortingAlgo == 3) { QuickSort(pillars, totalPillars , 0 , totalPillars); }
	if (SortingAlgo == 4) { MergeSort(pillars, totalPillars , 0 , totalPillars - 1); }

	while(!WindowShouldClose())
		RenderScreen(pillars , totalPillars);

	CloseWindow();
}


