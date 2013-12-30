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
    [PluginInfo(Name="ApplyTransform",Category="Transform")]
    public class ApplyTransformNode : IPluginEvaluate
    {
        [Input("Transform")]
        protected MatrixInput TransformIn;

        [Input("X UnTransformed")]
        protected FastValueInput XIn;

        [Input("Y UnTransformed")]
        protected FastValueInput YIn;

        [Input("Z UnTransformed")]
        protected FastValueInput ZIn;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        [Input("X Transformed")]
        protected ValueOutput XOut;

        [Input("Y Transformed")]
        protected ValueOutput YOut;

        [Input("Z Transformed")]
        protected ValueOutput ZOut;

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
