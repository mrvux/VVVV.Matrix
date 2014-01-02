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
    [PluginInfo(Name = "Rotate", Category = "Matrix", Version="Vector")]
    public unsafe class RotateVectorNode : IPluginEvaluate
    {

        [Input("XYZ")]
        protected FastValueInput trin;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        private MatrixInput input;
        private MatrixOutput output;

        [ImportingConstructor()]
        public RotateVectorNode(IPluginHost host)
        {
            this.input = new MatrixInput(host);
            this.output = new MatrixOutput(host);
        }

        public void Evaluate(int SpreadMax)
        {
            MatrixPointer min;
            int incnt = 1;
            if (this.input.IsConnected)
            {
                min = this.input.Input;
                incnt = this.input.Input.DataLength;
            }
            else
            {
                min = MatrixPointer.Zero;
            }

            DoublePointer dptr;
            dptr.DataPointer = trin.Data;
            dptr.DataLength = trin.Length;

            incnt = Math.Max(incnt, trin.GetSliceCount(3));

            this.output.SetSliceCount(incnt);
            MatrixPointer ptr = this.output.Pointer;
            NativeMethods.RotateVectorCyclic(ptr, min, dptr, incnt, this.Threaded[0]);
        }
    }
}
