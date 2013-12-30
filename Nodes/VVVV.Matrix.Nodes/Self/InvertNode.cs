using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VVVV.DataTypes;
using VVVV.Hosting.IO.Pointers;
using VVVV.PluginInterfaces.V2;

namespace VVVV.Nodes
{
    [PluginInfo(Name = "Inverse", Category = "Matrix")]
    public class InvertNode : IPluginEvaluate
    {
        [Input("Transform In")]
        protected MatrixInput TransformIn;

        [Input("Source")]
        protected MatrixInput Source;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        [Input("Transform Out")]
        protected MatrixOutput TransformOut;

        public void Evaluate(int SpreadMax)
        {

        }
    }
}
