using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VVVV.Hosting.IO.Pointers;
using VVVV.Matrix.Nodes;
using VVVV.PluginInterfaces.V1;
using VVVV.PluginInterfaces.V2;

namespace VVVV.Nodes
{
    [PluginInfo(Name = "Scale", Category = "Matrix")]
    public unsafe class ScaleNode : IPluginEvaluate
    {
        /*[Input("Transform In")]
        protected MatrixInput TransformIn;*/

        [Input("X",DefaultValue=1)]
        protected FastValueInput X;

        [Input("Y", DefaultValue = 1)]
        protected FastValueInput Y;

        [Input("Z", DefaultValue = 1)]
        protected FastValueInput Z;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

       /* [Input("Transform Out")]
        protected MatrixOutput TransformOut;*/

        private MatrixInput input;
        private MatrixOutput output;

        [ImportingConstructor()]
        public ScaleNode(IPluginHost host)
        {
            this.input = new MatrixInput(host);
            this.output = new MatrixOutput(host);
        }

        public void Evaluate(int SpreadMax)
        {
            MatrixPointer min;
            if (this.input.IsConnected)
            {
                min = this.input.Input;
            }
            else
            {
                min = MatrixPointer.Zero;
            }

            Vector3SOAPointer soa = new Vector3SOAPointer();
            soa.x = new IntPtr(X.Data);
            soa.xcount = X.Length;
            soa.y = new IntPtr(Y.Data);
            soa.ycount = Y.Length;
            soa.z = new IntPtr(Z.Data);
            soa.zcount = Z.Length;

            this.output.SetSliceCount(SpreadMax);
            MatrixPointer ptr = this.output.Pointer;
            NativeMethods.ScaleCyclic(ptr, min, soa, SpreadMax, this.Threaded[0]);
        }
    }
}
