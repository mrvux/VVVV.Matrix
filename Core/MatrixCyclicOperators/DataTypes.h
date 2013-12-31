#pragma once

#include <DirectXMath.h>
#include <malloc.h>

namespace vmat
{
	struct Vector2d
	{
		double x;
		double y;
	};

	struct Vector3d
	{
		double x;
		double y;
		double z;
	};

	struct Vector4d
	{
		double x;
		double y;
		double z;
		double w;
	};

	template <typename T>
	struct PointerTemplate
	{
		T* DataPointer;
		int ElementCount;
		inline T* GetSlicePointer(int slice) { return &DataPointer[slice % ElementCount]; }
		inline T GetSlice(int slice) { return DataPointer[slice % ElementCount]; }
	};

	template <typename T, int A>
	struct WriteablePointerTemplate
	{
		T* DataPointer = nullptr;
		int ElementCount = 0;

		~WriteablePointerTemplate()
		{
			if (DataPointer)
			{
				_aligned_free(DataPointer);
			}
		}

		inline void SetSliceCount(int count)
		{
			if (ElementCount != count)
			{
				if (ElementCount == 0)
				{
					_aligned_free(DataPointer);
					DataPointer = 0;
				}
				else
				{
					if (DataPointer)
					{
						DataPointer = _aligned_realloc(DataPointer, sizeof(T)* count, A);
					}
					else
					{
						DataPointer = _aligned_malloc(sizeof(T)* count, A);
					}
				}

				ElementCount = count;
			}
		}

		inline T* GetSlicePointer(int slice) { return &DataPointer[slice % ElementCount]; }
		inline T GetSlice(int slice) { return DataPointer[slice % ElementCount]; }
	};

	template <typename T, int I>
	struct VectorTemplate
	{
		double* DataPointer;
		int DataLength;
		inline bool IsComplete() { return DataLength % I == 0; }
		inline int VectorCount() { return IsComplete() ? DataLength / I : (DataLength / I) + 1; }
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

	typedef PointerTemplate<double> DoublePointer;
	typedef WriteablePointerTemplate<DirectX::XMMATRIX,16> MatrixPointer;

	typedef VectorTemplate<Vector2d, 2> Vector2dPointer;
	typedef VectorTemplate<Vector3d, 3> Vector3dPointer;
	typedef VectorTemplate<Vector4d, 4> Vector4dPointer;

	typedef Vector2SOA<double> Vector2SOAd;
	typedef Vector3SOA<double> Vector3SOAd;
	typedef Vector4SOA<double> Vector4SOAd;

}

