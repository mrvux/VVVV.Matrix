#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void RotateCyclic(MatrixPointer result, Vector3SOAd vectors, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
#pragma omp parallel if (threaded)
	{
#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			outptr[i] = XMMatrixRotationRollPitchYaw(vectors.SliceZ(i), vectors.SliceX(i), vectors.SliceY(i));
		}
	}
}

void RotateCyclic(MatrixPointer result, MatrixPointer matrixin, Vector3SOAd vectors, int totallength, bool threaded)
{
	if (matrixin.DataPointer == 0)
	{
		RotateCyclic(result, vectors, totallength, threaded);
		return;
	}

	XMMATRIX* outptr = result.DataPointer;
#pragma omp parallel if (threaded)
	{
#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			outptr[i] = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(vectors.SliceZ(i), vectors.SliceX(i), vectors.SliceY(i)), matrixin.GetSlice(i));
		}
	}
}

void RotateVectorCyclic(vmat::MatrixPointer result, vmat::Vector3dPointer input, int totallength, bool threaded)
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
				outptr[i] = XMMatrixRotationRollPitchYaw(d.z, d.x, d.y);
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
				outptr[i] = XMMatrixRotationRollPitchYaw(d[(i * 3+2) % l], d[(i * 3) % l], d[(i * 3 + 1) % l]);
			}
		}
	}
}

void RotateVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded)
{
	if (matrixin.DataPointer == 0)
	{
		RotateVectorCyclic(result, input, totallength, threaded);
		return;
	}

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
				outptr[i] = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(d.z, d.x, d.y), matrixin.GetSlice(i));
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
				outptr[i] = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(d[(i * 3 + 2) % l], d[(i * 3) % l], d[(i * 3 + 1) % l]), matrixin.GetSlice(i));
			}
		}
	}
}

void RotateQuaternionCyclic(vmat::MatrixPointer result, vmat::Vector4dPointer input, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
	if (input.IsComplete())
	{
		Vector4d* data = (Vector4d*)input.DataPointer;
#pragma omp parallel if (threaded)
		{
#pragma omp for
			for (int i = 0; i < totallength; i++)
			{
				Vector4d d = data[i];
				XMVECTOR quat = XMVectorSet(d.x, d.y, d.z, d.w);
				outptr[i] = XMMatrixRotationQuaternion(quat);
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
				XMVECTOR quat = XMVectorSet(d[(i * 3) % l], d[(i * 3 + 1) % l], d[(i * 3 + 2) % l], d[(i * 3 + 3) % l]);
				outptr[i] = XMMatrixRotationQuaternion(quat);
			}
		}
	}
}

void RotateQuaternionCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector4dPointer input, int totallength, bool threaded)
{
	if (matrixin.DataPointer == 0)
	{
		RotateQuaternionCyclic(result, input, totallength, threaded);
		return;
	}

	XMMATRIX* outptr = result.DataPointer;
	if (input.IsComplete())
	{
		Vector4d* data = (Vector4d*)input.DataPointer;
		int vcount = input.VectorCount();
		#pragma omp parallel if (threaded)
		{
			#pragma omp for
			for (int i = 0; i < totallength; i++)
			{
				Vector4d d = data[i];
				XMVECTOR quat = XMVectorSet(d.x, d.y, d.z, d.w);
				outptr[i] = XMMatrixMultiply(XMMatrixRotationQuaternion(quat), matrixin.GetSlice(i));
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
				XMVECTOR quat = XMVectorSet(d[(i * 3) % l], d[(i * 3 + 1) % l], d[(i * 3 + 2) % l], d[(i * 3 + 3) % l]);
				outptr[i] = XMMatrixMultiply(XMMatrixRotationQuaternion(quat), matrixin.GetSlice(i));
			}
		}
	}
}



