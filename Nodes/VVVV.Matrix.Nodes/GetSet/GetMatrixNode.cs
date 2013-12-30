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
    [PluginInfo(Name = "GetMatrix", Category = "Matrix")]
    public class GetMatrixNode : IPluginEvaluate
    {
        [Input("Transform")]
        protected MatrixInput TransformIn;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        [Input("Matrix Out")]
        protected ValueOutput ValueOut;

        public void Evaluate(int SpreadMax)
        {

        }
    }
}
