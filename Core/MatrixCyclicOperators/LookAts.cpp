
#include "stdafx.h"

#include "MatrixOperators.h"

using namespace DirectX;
using namespace vmat;

void LookAtCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd eye, vmat::Vector3SOAd target, vmat::Vector3SOAd up, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
	#pragma omp parallel if (threaded)
	{
		#pragma omp for
		for (int i = 0; i < totallength; i++)
		{		
			FXMVECTOR ve = XMVectorSet(eye.SliceX(i), eye.SliceY(i), eye.SliceZ(i), 0.0f);
			FXMVECTOR vt = XMVectorSet(target.SliceX(i), target.SliceY(i), target.SliceZ(i), 0.0f);
			FXMVECTOR vu = XMVectorSet(up.SliceX(i), up.SliceY(i), up.SliceZ(i), 0.0f);
			outptr[i] = XMMatrixMultiply(XMMatrixLookAtLH(ve,vt,vu), matrixin.GetSlice(i));
		}
	}
}

void LookToCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd eye, vmat::Vector3SOAd eyedir, vmat::Vector3SOAd up, int totallength, bool threaded)
{
	XMMATRIX* outptr = result.DataPointer;
#pragma omp parallel if (threaded)
	{
#pragma omp for
		for (int i = 0; i < totallength; i++)
		{
			FXMVECTOR ve = XMVectorSet(eye.SliceX(i), eye.SliceY(i), eye.SliceZ(i), 0.0f);
			FXMVECTOR vd = XMVectorSet(eyedir.SliceX(i), eyedir.SliceY(i), eyedir.SliceZ(i), 0.0f);
			FXMVECTOR vu = XMVectorSet(up.SliceX(i), up.SliceY(i), up.SliceZ(i), 0.0f);
			outptr[i] = XMMatrixMultiply(XMMatrixLookToLH(ve, vd, vu), matrixin.GetSlice(i));
		}
	}
}









