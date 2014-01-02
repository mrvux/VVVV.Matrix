#pragma once

#include "DataTypes.h"

#include <omp.h>

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
	// used by C++ source code
#endif

__declspec(dllexport) void Identity(vmat::MatrixPointer* result);
__declspec(dllexport) void* Allocate(int size);
__declspec(dllexport) void* Reallocate(void* ptr,int size);
__declspec(dllexport) void Free(void* ptr);

//Translation operators
__declspec(dllexport) void TranslateCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd vectors, int totallength, bool threaded);
__declspec(dllexport) void TranslateVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded);


//Scale operators
__declspec(dllexport) void ScaleCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd vectors, int totallength, bool threaded);
__declspec(dllexport) void ScaleVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded);
__declspec(dllexport) void UniformScaleCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::DoublePointer scaling, int totallength, bool threaded);

//Rotation Operators
__declspec(dllexport) void RotateCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd vectors, int totallength, bool threaded);

__declspec(dllexport) void RotateVectorCyclic(vmat::MatrixPointer result, vmat::Vector3dPointer input, int totallength, bool threaded);
//__declspec(dllexport) void __cdecl RotateVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded);

__declspec(dllexport) void RotateQuaternionCyclic(vmat::MatrixPointer result, vmat::Vector4dPointer input, int totallength, bool threaded);
//__declspec(dllexport) void __cdecl RotateQuaternionCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector4dPointer input, int totallength, bool threaded);

//LookAt and LookTo
__declspec(dllexport) void LookAtCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd eye, vmat::Vector3SOAd target, vmat::Vector3SOAd up, int totallength, bool threaded);
//__declspec(dllexport) void __cdecl LookToCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd eye, vmat::Vector3SOAd eyedir, vmat::Vector3SOAd up, int totallength, bool threaded);

//Projections Matrices

//Other operators
__declspec(dllexport) void TransposeCyclic(vmat::MatrixPointer result, vmat::MatrixPointer input, bool threaded);
__declspec(dllexport) void InvertCyclic(vmat::MatrixPointer result, vmat::MatrixPointer input, bool threaded);

__declspec(dllexport) void GetMatrix(vmat::DoublePointer output, vmat::MatrixPointer input, bool threaded);

#ifdef __cplusplus
}
#endif