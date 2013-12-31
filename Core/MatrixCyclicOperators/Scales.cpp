#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void ScaleCyclic(MatrixPointer result, Vector3SOAd vectors, int totallength, bool threaded)
{
	result.SetSliceCount(totallength);
	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			outptr[i] = XMMatrixScaling(vectors.SliceX(i), vectors.SliceY(i), vectors.SliceZ(i));
		}
	}
}

void ScaleCyclic(MatrixPointer result, MatrixPointer matrixin, Vector3SOAd vectors, int totallength, bool threaded)
{
	result.SetSliceCount(totallength);
	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			outptr[i] = XMMatrixMultiply(XMMatrixScaling(vectors.SliceX(i), vectors.SliceY(i), vectors.SliceZ(i)), matrixin.GetSlice(i));
		}
	}
}

void UniformScaleCyclic(MatrixPointer result, DoublePointer scale, int totallength, bool threaded)
{
	result.SetSliceCount(totallength);
	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			float s = scale.DataPointer[i];
			outptr[i] = XMMatrixScaling(s, s, s);
		}
	}
}

void UniformScaleCyclic(MatrixPointer result, MatrixPointer matrixin, DoublePointer scale, int totallength, bool threaded)
{
	result.SetSliceCount(totallength);
	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			float s = scale.GetSlice(i);
			outptr[i] = XMMatrixMultiply(XMMatrixScaling(s, s, s), matrixin.GetSlice(i));
		}
	}
}



