// MatrixCyclicOperators.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void Identity(vmat::MatrixPointer result)
{
	result.SetSliceCount(1);
	result.DataPointer[0] = XMMatrixIdentity();
}

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

void GetMatrix(vmat::DoublePointer output, vmat::MatrixPointer input, bool threaded)
{
	XMMATRIX* inptr = input.DataPointer;
	double* outptr = output.DataPointer;
	int t = input.ElementCount;
	#pragma omp parallel if (threaded)
	{
	#pragma omp for
		for (int i = 0; i < t; i++)
		{
			float* m = (float*)&inptr[i];
			outptr[i * 16] = m[0];
			outptr[i * 16 + 1] = m[1];
			outptr[i * 16 + 2] = m[2];
			outptr[i * 16 + 3] = m[3]; 

			outptr[i * 16+4] = m[4];
			outptr[i * 16 + 5] = m[5];
			outptr[i * 16 + 6] = m[6];
			outptr[i * 16 + 7] = m[7];

			outptr[i * 16+8] = m[8];
			outptr[i * 16 + 9] = m[9];
			outptr[i * 16 + 10] = m[10];
			outptr[i * 16 + 11] = m[11];

			outptr[i * 16+12] = m[0];
			outptr[i * 16 + 13] = m[1];
			outptr[i * 16 + 14] = m[2];
			outptr[i * 16 + 15] = m[3];
		}
	}
}
