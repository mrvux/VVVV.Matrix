// MatrixCyclicOperators.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void InvertCyclic(vmat::MatrixPointer result, vmat::MatrixPointer input, bool threaded)
{
	result.SetSliceCount(input.ElementCount);

	XMMATRIX* inptr = input.DataPointer;
	XMMATRIX* outptr = result.DataPointer;
	int t = input.ElementCount;

	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < t; i++)
		{
			outptr[i] = XMMatrixInverse(nullptr, inptr[i]);
		}
	}
}

void TransposeCyclic(vmat::MatrixPointer result, vmat::MatrixPointer input, bool threaded)
{
	result.SetSliceCount(input.ElementCount);

	XMMATRIX* inptr = input.DataPointer;
	XMMATRIX* outptr = result.DataPointer;
	int t = input.ElementCount;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < t; i++)
		{
			outptr[i] = XMMatrixTranspose(inptr[i]);
		}
	}
}


