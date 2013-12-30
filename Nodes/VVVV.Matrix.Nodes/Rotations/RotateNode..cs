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
    [PluginInfo(Name="Rotate",Category="Transform")]
    public class RotateNode : IPluginEvaluate
    {
        [Input("Transform In")]
        protected MatrixInput TransformIn;

        [Input("X", DefaultValue=1)]
        protected FastValueInput X;

        [Input("Y", DefaultValue = 1)]
        protected FastValueInput Y;

        [Input("Z", DefaultValue = 1)]
        protected FastValueInput Z;

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
