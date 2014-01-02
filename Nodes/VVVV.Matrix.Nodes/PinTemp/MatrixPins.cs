using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VVVV.Matrix.Nodes;
using VVVV.Matrix.Nodes.GetSet;
using VVVV.PluginInterfaces.V1;

namespace VVVV
{
    public class MatrixInput
    {
        private INodeIn nodein;

        public bool IsConnected { get { return this.nodein.IsConnected; } }

        public MatrixPointer Input
        {
            get 
            {  
                
                object o;
                this.nodein.GetUpstreamInterface(out o);
                MatrixHolder h = (MatrixHolder)o;
                return h.Ptr;
            }
        }

        public MatrixInput(IPluginHost host)
        {
            host.CreateNodeInput("Transform In", TSliceMode.Dynamic, TPinVisibility.True, out nodein);
            nodein.SetSubType2(typeof(MatrixHolder), new Guid[] { typeof(MatrixHolder).GUID }, "Hello");
            nodein.Order = 0;
        }

    }


    public class MatrixOutput
    {
        private INodeOut nodeout;
        private MatrixHolder mptr = new MatrixHolder();

        public void SetSliceCount(int count)
        {
            if (this.mptr.Ptr.DataLength != count)
            {
                if (count == 0)
                {
                    if (this.mptr.Ptr.DataPointer != IntPtr.Zero)
                    {
                        NativeMethods.Free(this.mptr.Ptr.DataPointer);
                        this.mptr.Ptr.DataPointer = IntPtr.Zero;
                    }
                }
                else
                {
                    if (this.mptr.Ptr.DataPointer != IntPtr.Zero)
                    {
                        this.mptr.Ptr.DataPointer = NativeMethods.Reallocate(this.mptr.Ptr.DataPointer,count * sizeof(float) * 16);
                    }
                    else
                    {
                        this.mptr.Ptr.DataPointer = NativeMethods.Allocate(count * sizeof(float) * 16);
                    }
                }
            }
            this.mptr.Ptr.DataLength = count;
        }

        public MatrixPointer Pointer
        {
            get
            {
                return mptr.Ptr;
            }
        }

        public MatrixOutput(IPluginHost host)
        {
            host.CreateNodeOutput("Transform Out", TSliceMode.Dynamic, TPinVisibility.True, out nodeout);
            nodeout.SetInterface(mptr);
            nodeout.SetSubType2(typeof(MatrixHolder), new Guid[] { typeof(MatrixHolder).GUID }, "Hello");
        }

    }


}
