// MatrixCyclicOperators.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void TranslateCyclic(MatrixPointer result, Vector3SOAd vectors, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			outptr[i] = XMMatrixTranslation(vectors.SliceX(i), vectors.SliceY(i), vectors.SliceZ(i));
		}
	}
}

void TranslateCyclic(MatrixPointer result, MatrixPointer matrixin, Vector3SOAd vectors, int totallength, bool threaded)
{
	if (matrixin.DataPointer == 0)
	{
		TranslateCyclic(result, vectors, totallength, threaded);
		return;
	}

	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			outptr[i] = XMMatrixMultiply(XMMatrixTranslation(vectors.SliceX(i), vectors.SliceY(i), vectors.SliceZ(i)), matrixin.GetSlice(i));
		}
	}
}

void TranslateVectorCyclic(vmat::MatrixPointer result, vmat::Vector3dPointer input, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
	if (input.IsComplete())
	{
		Vector3d* data = (Vector3d*)input.DataPointer;
#pragma omp parallel if (threaded)
		{
#pragma omp for
			for (int i = 0; i < totallength; i++)
			{
				Vector3d d = data[i];
				outptr[i] = XMMatrixTranslation(d.x, d.y, d.z);
			}
		}
	}
	else
	{
		//TODO: We can make that faster since there's no transform input involved, process thread -1 at full speed, then last element with mod
		double* d = input.DataPointer;
		int l = input.DataLength;
#pragma omp parallel if (threaded)
		{
#pragma omp for
			for (int i = 0; i < totallength; i++)
			{
				outptr[i] = XMMatrixTranslation(d[i * 3 % l], d[(i * 3 + 1) % l], d[(i * 3 + 2) % l]);
			}
		}
	}
}

void TranslateVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
	if (input.IsComplete())
	{
		Vector3d* data = (Vector3d*)input.DataPointer;
		int vcount = input.VectorCount();
#pragma omp parallel if (threaded)
		{
#pragma omp for
			for (int i = 0; i < totallength; i++)
			{
				Vector3d d = data[i%vcount];
				outptr[i] = XMMatrixMultiply(XMMatrixTranslation(d.x, d.y, d.z), matrixin.GetSlice(i));
			}
		}
	}
	else
	{
		double* d = input.DataPointer;
		int l = input.DataLength;
#pragma omp parallel if (threaded)
		{
#pragma omp for
			for (int i = 0; i < totallength; i++)
			{
				outptr[i] = XMMatrixMultiply(XMMatrixTranslation(d[i * 3 % l], d[(i * 3 + 1) % l], d[(i * 3 + 2) % l]), matrixin.GetSlice(i));
			}
		}
	}
}


