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
    [PluginInfo(Name = "LookAt", Category = "Matrix", Version="Vector")]
    public class LookAtVectorNode : IPluginEvaluate
    {
        [Input("Transform In")]
        protected MatrixInput TransformIn;

        [Input("Position XYZ")]
        protected FastValueInput Position;

        [Input("Target XYZ")]
        protected FastValueInput Target;

        [Input("UpVector XYZ")]
        protected FastValueInput Up;

        [Input("Threaded", IsSingle = true)]
        protected ISpread<bool> Threaded;

        [Input("Transform Out")]
        protected MatrixOutput TransformOut;

        public void Evaluate(int SpreadMax)
        {
            if (this.TransformIn.IsConnected)
            {

            }
            else
            {

            }
        }
    }
}
