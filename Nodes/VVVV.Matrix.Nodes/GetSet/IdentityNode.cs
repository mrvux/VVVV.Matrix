using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VVVV.Hosting.IO.Pointers;
using VVVV.Matrix.Nodes;
using VVVV.Matrix.Nodes.GetSet;
using VVVV.PluginInterfaces.V1;
using VVVV.PluginInterfaces.V2;

namespace VVVV.Nodes
{
    [PluginInfo(Name = "Identity", Category = "Matrix")]
    public unsafe class IdentityNode : IPluginEvaluate
    {
        protected INodeOut TransformOut;
        protected MatrixHolder mptr = new MatrixHolder();

        

        [ImportingConstructor()]
        public IdentityNode(IPluginHost host)
        {
            host.CreateNodeOutput("Transform In", TSliceMode.Dynamic, TPinVisibility.True, out TransformOut);
            TransformOut.SetInterface(mptr);
            TransformOut.SetSubType2(typeof(MatrixHolder), new Guid[] { typeof(MatrixHolder).GUID }, "Hello");
        }

        public void Evaluate(int SpreadMax)
        {
            /*IntPtr ptr = NativeMethods.LoadLibrary(@"E:\repositories\vvvv\VVVV.Matrix\Debug\MatrixCyclicOperators.dll");
            IntPtr ptrf = NativeMethods.GetProcAddress(ptr, "Identity");

            ptrf = NativeMethods.GetProcAddress(ptr, "GetMatrix");
            ptrf = NativeMethods.GetProcAddress(ptr, "TranslateCyclic");*/

            //NativeMethods.Identity(ref this.mptr.Ptr);
            /*fixed (MatrixPointer* ptr2 = &this.mptr.Ptr)
            {
                NativeMethods.Identity(ptr2);
            }*/
           
        }
    }
}
