#pragma once

#include <DirectXMath.h>

namespace vmat
{
	template <typename T>
	struct PointerTemplate
	{
		T* DataPointer;
		int ElementCount;
		inline T* GetSlicePointer(int slice) { return &DataPointer[slice % ElementCount]; }
		inline T GetSlice(int slice) { return DataPointer[slice % ElementCount]; }
	};



	template <typename T>
	struct Vector2SOA
	{
		T* x;
		T* y;
		int xcount;
		int ycount;

		inline T SliceX(int slice) { return x[slice % xcount]; }
		inline T SliceY(int slice) { return y[slice % ycount]; }
	};

	template <typename T>
	struct Vector3SOA
	{
		T* x;
		T* y;
		T* z;
		int xcount;
		int ycount;
		int zcount;

		inline T SliceX(int slice) { return x[slice % xcount]; }
		inline T SliceY(int slice) { return y[slice % ycount]; }
		inline T SliceZ(int slice) { return z[slice % zcount]; }
	};

	template <typename T>
	struct Vector4SOA
	{
		T* x;
		T* y;
		T* z;
		T* w;
		int xcount;
		int ycount;
		int zcount;
		int wcount;

		inline T SliceX(int slice) { return x[slice % xcount]; }
		inline T SliceY(int slice) { return y[slice % ycount]; }
		inline T SliceZ(int slice) { return z[slice % zcount]; }
		inline T SliceW(int slice) { return z[slice % wcount]; }
	};


#define DoublePointer PointerTemplate<double>
#define MatrixPointer PointerTemplate<DirectX::XMMATRIX>
#define Vector2SOAd Vector2SOA<double>
#define Vector3SOAd Vector3SOA<double>
#define Vector4SOAd Vector4SOA<double>
}

