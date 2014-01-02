#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void ScaleCyclic(MatrixPointer result, Vector3SOAd vectors, int totallength, bool threaded)
{
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

void ScaleVectorCyclic(vmat::MatrixPointer result, vmat::Vector3dPointer input, int totallength, bool threaded)
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
				outptr[i] = XMMatrixScaling(d.x, d.y, d.z);
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
				outptr[i] = XMMatrixScaling(d[i * 3 % l], d[(i * 3 + 1) % l], d[(i * 3 + 2) % l]);
			}
		}
	}
}

void ScaleVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded)
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
				outptr[i] = XMMatrixMultiply(XMMatrixScaling(d.x, d.y, d.z), matrixin.GetSlice(i));
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
				outptr[i] = XMMatrixMultiply(XMMatrixScaling(d[i * 3 % l], d[(i * 3 + 1) % l], d[(i * 3 + 2) % l]), matrixin.GetSlice(i));
			}
		}
	}
}


void UniformScaleCyclic(MatrixPointer result, DoublePointer scale, int totallength, bool threaded)
{
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



