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
    [PluginInfo(Name = "GetMatrix", Category = "Matrix")]
    public unsafe class GetMatrixNode : IPluginEvaluate
    {
        protected INodeIn TransformIn;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        [Output("Matrix Out")]
        protected ValueOutput ValueOut;

        [ImportingConstructor()]
        public GetMatrixNode(IPluginHost host)
        {
            host.CreateNodeInput("Transform In", TSliceMode.Dynamic, TPinVisibility.True, out TransformIn);
            TransformIn.SetSubType2(typeof(MatrixHolder), new Guid[] { typeof(MatrixHolder).GUID }, "Hello");
            
        }

        public void Evaluate(int SpreadMax)
        {
            if (TransformIn.IsConnected == false) { return; }

            object o;
            TransformIn.GetUpstreamInterface(out o);
            MatrixHolder mp = (MatrixHolder)o;

            this.ValueOut.Length = mp.Ptr.DataLength * 16;

            DoublePointer dptr = new DoublePointer();
            dptr.DataPointer = this.ValueOut.Data;
            dptr.DataLength = this.ValueOut.Length;

            NativeMethods.GetMatrix(dptr, mp.Ptr, false);
        }
    }
}
