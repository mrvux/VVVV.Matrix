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
    [PluginInfo(Name="Ortho",Category="Transform")]
    public class OrthoNode : IPluginEvaluate
    {
        [Input("Transform In")]
        protected MatrixInput TransformIn;

        [Input("Near Plane", DefaultValue=-100)]
        protected FastValueInput Near;

        [Input("Far", DefaultValue = 100)]
        protected FastValueInput Far;

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
