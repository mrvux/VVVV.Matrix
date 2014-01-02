using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using VVVV.Hosting.IO.Pointers;

namespace VVVV.Matrix.Nodes
{
    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct DoublePointer
    {
        public double* DataPointer;
        public int DataLength;
    }

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct MatrixPointer
    {
        public IntPtr DataPointer;
        public int DataLength;

        public static MatrixPointer Zero
        {
            get { return new MatrixPointer() { DataLength = 0, DataPointer = IntPtr.Zero }; }
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct Vector2SOAPointer
    {
        public IntPtr x;
        public IntPtr y;
        public int xcount;
        public int ycount;
    }

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct Vector3SOAPointer
    {
        public IntPtr x;
        public IntPtr y;
        public IntPtr z;
        public int xcount;
        public int ycount;
        public int zcount;
    }

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct Vector4SOAPointer
    {
        public IntPtr x;
        public IntPtr y;
        public IntPtr z;
        public IntPtr w;
        public int xcount;
        public int ycount;
        public int zcount;
        public int wcount;
    }


    public unsafe static class NativeMethods
    {
        public static int GetSliceCount(this FastValueInput input, int vectorsize)
        {
            return input.Length % vectorsize == 0 ? input.Length / vectorsize : input.Length / vectorsize + 1;
        }

        [DllImport("MatrixCyclicOperators")]
        public static extern void Identity (MatrixPointer output);

        [DllImport("MatrixCyclicOperators")]
        public static extern IntPtr Allocate(int size);

        [DllImport("MatrixCyclicOperators")]
        public static extern IntPtr Reallocate(IntPtr ptr, int size);

        [DllImport("MatrixCyclicOperators")]
        public static extern void Free(IntPtr ptr);

        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void TranslateCyclic(MatrixPointer result,MatrixPointer matrixin, Vector3SOAPointer vectors, int totallength, bool threaded);

        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void ScaleCyclic(MatrixPointer result, MatrixPointer matrixin, Vector3SOAPointer vectors, int totallength, bool threaded);

        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void RotateCyclic(MatrixPointer result, MatrixPointer matrixin, Vector3SOAPointer vectors, int totallength, bool threaded);

        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void TranslateVectorCyclic(MatrixPointer result,MatrixPointer matrixin, DoublePointer data, int totallength, bool threaded);

        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void ScaleVectorCyclic(MatrixPointer result, MatrixPointer matrixin, DoublePointer data, int totallength, bool threaded);

        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void RotateVectorCyclic(MatrixPointer result, MatrixPointer matrixin, DoublePointer data, int totallength, bool threaded);


        [DllImport("MatrixCyclicOperators.dll")]
        public static extern void GetMatrix(DoublePointer output, MatrixPointer input, bool threaded);
    }
}
