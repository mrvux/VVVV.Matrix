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
    [PluginInfo(Name = "Transform", Category = "2d", Version="Vector")]
    public class Transform2dVectorNode : IPluginEvaluate
    {
        [Input("Transform In")]
        protected MatrixInput TransformIn;

        [Input("Translate XY")]
        protected FastValueInput Position;

        [Input("Scale XY", DefaultValues= new double[] {1,1})]
        protected FastValueInput Scale;

        [Input("Rotate")]
        protected FastValueInput Rotate;

        [Input("Center XY")]
        protected FastValueInput Center;

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
