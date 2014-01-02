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
    [PluginInfo(Name = "Scale", Category = "Matrix", Version="Vector")]
    public unsafe class ScaleVectorNode : IPluginEvaluate
    {

        [Input("XYZ", DefaultValue=1)]
        protected FastValueInput trin;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        private MatrixInput input;
        private MatrixOutput output;

        [ImportingConstructor()]
        public ScaleVectorNode(IPluginHost host)
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

            DoublePointer dptr;
            dptr.DataPointer = trin.Data;
            dptr.DataLength = trin.Length;



            this.output.SetSliceCount(SpreadMax);
            MatrixPointer ptr = this.output.Pointer;
            NativeMethods.ScaleVectorCyclic(ptr, min, dptr, SpreadMax, this.Threaded[0]);
        }
    }
}
