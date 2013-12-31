#pragma once

#include "DataTypes.h"

#include <omp.h>

__declspec(dllexport) void __cdecl Identity(vmat::MatrixPointer result);

__declspec(dllexport) void __cdecl TranslateCyclic(vmat::MatrixPointer result, vmat::Vector3SOAd vectors, int totallength, bool threaded);
__declspec(dllexport) void __cdecl TranslateCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd vectors, int totallength, bool threaded);

__declspec(dllexport) void __cdecl TranslateVectorCyclic(vmat::MatrixPointer result, vmat::Vector3dPointer input, int totallength, bool threaded);
__declspec(dllexport) void __cdecl TranslateVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded);

__declspec(dllexport) void __cdecl ScaleCyclic(vmat::MatrixPointer result, vmat::Vector3SOAd vectors, int totallength, bool threaded);
__declspec(dllexport) void __cdecl ScaleCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3SOAd vectors, int totallength, bool threaded);

__declspec(dllexport) void __cdecl ScaleVectorCyclic(vmat::MatrixPointer result, vmat::Vector3dPointer input, int totallength, bool threaded);
__declspec(dllexport) void __cdecl ScaleVectorCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::Vector3dPointer input, int totallength, bool threaded);

__declspec(dllexport) void __cdecl UniformScaleCyclic(vmat::MatrixPointer result, vmat::DoublePointer scaling, int totallength, bool threaded);
__declspec(dllexport) void __cdecl UniformScaleCyclic(vmat::MatrixPointer result, vmat::MatrixPointer matrixin, vmat::DoublePointer scaling, int totallength, bool threaded);

__declspec(dllexport) void __cdecl TransposeCyclic(vmat::MatrixPointer result, vmat::MatrixPointer input, bool threaded);
__declspec(dllexport) void __cdecl InvertCyclic(vmat::MatrixPointer result, vmat::MatrixPointer input, bool threaded);

